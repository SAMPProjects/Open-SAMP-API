# coding: utf8
# Python 3

import re
import codecs
import os
import fnmatch

class Function:
    def __init__(self, name, arguments, retType, origin):
        self.name = name
        self.arguments = arguments
        self.retType = retType
        self.origin = origin

class Argument:
    def __init__(self, name, aType, isPtr):
        self.name = name
        self.aType = aType
        self.isPtr = isPtr

class Type:
    def __init__(self, typeName, isConst, isArray, isUnsigned):
        self.typeName = typeName
        self.isConst = isConst
        self.isArray = isArray
        self.isUnsigned = isUnsigned

functions = []

def parseDefinition(expression):
    expression = expression.strip()
    expression = re.sub(r'\t', " ", expression)
    (expression, isArray) = re.subn(r'\*', "", expression)
    (expression, isPtr) = re.subn(r'&', "", expression)
    (expression, isConst) = re.subn(r'^const ', "", expression)
    (expression, isUnsigned) = re.subn(r'^unsigned ', "", expression)
    parts = expression.split()
    name = parts.pop()
    typeName = " ".join(parts)
    return Argument(
        name,
        Type(
            typeName,
            bool(isConst),
            bool(isArray),
            bool(isUnsigned)
        ),
        bool(isPtr)
    )

def scan():
    os.chdir("src/Open-SAMP-API/Client")
    for filename in os.listdir("."):
        if filename in ["GTAStructs.hpp", "MemoryFunctions.hpp"] or not fnmatch.fnmatch(filename, "*.hpp"):
            continue
        with codecs.open(filename, encoding="utf-8-sig") as file:
            content = file.read()
        matches = re.findall(r'^\s*EXPORT (.+)\((.*)\);\s*$', content, flags=re.M)
        for match in matches:
            functionDefinition = parseDefinition(match[0])
            (name, retType) = (functionDefinition.name, functionDefinition.aType)
            arguments = match[1].split(",")
            if arguments[0] == "":
                arguments.pop(0)
            arguments = list(map(parseDefinition, arguments))
            function = Function(
                name,
                arguments,
                retType,
                filename
            )
            functions.append(function)

def gen_ahk():
    header = '''#NoEnv 

PATH_SAMP_API := PathCombine(A_ScriptDir, "..\..\\bin\Open-SAMP-API.dll")

hModule := DllCall("LoadLibrary", Str, PATH_SAMP_API)
if(hModule == -1 || hModule == 0)
{
	MsgBox, 48, Error, The dll-file couldn't be found!
	ExitApp
}
'''
    footer = '''
PathCombine(abs, rel) {
	VarSetCapacity(dest, (A_IsUnicode ? 2 : 1) * 260, 1) ; MAX_PATH
	DllCall("Shlwapi.dll\PathCombine", "UInt", &dest, "UInt", &abs, "UInt", &rel)
	Return, dest
}
'''
    output = header
    GetProcAddressTemplate = '{0}_func := DllCall("GetProcAddress", "UInt", hModule, "AStr", "{0}")\n'
    currentOrigin = ""
    for function in functions:
        if currentOrigin != function.origin:
            output += "\n;{0}\n".format(function.origin)
            currentOrigin = function.origin
        output += GetProcAddressTemplate.format(function.name)
    output += "\n"
    FunctionTemplate = '''{0}({1})
{{
	global {0}_func
	return DllCall({0}_func{2})
}}

'''
    FunctionTemplatePtr = '''{0}({1})
{{
	global {0}_func
	{3}
	res := DllCall({0}_func{2})
	; We need StrGet to convert the API answer (ANSI) to the charset AHK uses (ANSI or Unicode)
	{4}
	return res
}}

'''
    dataTypeMap = {
        "bool": "UChar",
        "char": "AStr",
        "float": "Float",
        "int": "Int"
    }
    for function in functions:
        hasStrPtr = False
        VarSetCapacity_opt = StrGet_opt = DllCallArguments = ""
        for argument in function.arguments:
            dataType = dataTypeMap[argument.aType.typeName]
            if argument.isPtr and argument.aType.typeName == "char" and argument.aType.isArray:
                hasStrPtr = True
                dataType = "Str" # Don't use AStr so we don't get AStrP later on (the P is added below)
                for innerArgument in function.arguments:
                    if innerArgument.name == "max_len":
                        maxVarLen = "max_len"
                if not maxVarLen:
                    maxVarLen = input("Maximum output length for " + function.name + " (variable name or value): ")
                    print("You may also add a param named max_len so we can make it work automatically")
                VarSetCapacity_opt += "\n\tVarSetCapacity({0}, {1} * (A_IsUnicode ? 2 : 1), 0)".format(argument.name, maxVarLen)
                StrGet_opt += "\n\t{0} := StrGet(&{0}, \"cp0\")".format(argument.name)
            
            if argument.aType.isUnsigned:
                dataType = "U" + dataType
            if argument.isPtr:
                dataType += "P"
            DllCallArguments += ', "{0}", {1}'.format(dataType, argument.name)
        if function.retType.typeName not in ["void", "bool", "int"]:
            DllCallArguments += ', "Cdecl {0}"'.format(function.retType.typeName)
        template = FunctionTemplatePtr if hasStrPtr else FunctionTemplate
        functionBody = template.format(
            function.name,
            ", ".join(map(lambda argument: ("ByRef " if argument.isPtr else "") + argument.name, function.arguments)),
            DllCallArguments,
            VarSetCapacity_opt.strip(),
            StrGet_opt.strip()
        )
        output += functionBody
    output += footer
    with codecs.open("AHK/SAMP_API.ahk", encoding="utf-8", mode="w") as file:
        file.write(output)

def gen_cs():
    header = '''using System;
using System.Drawing;
using System.Runtime.InteropServices;

namespace SAMP_API
{
    class API
    {
        public const String PATH = "Open-SAMP-API.dll";
'''
    footer = '''
        /// <summary>
        /// Send a message/command to the server
        /// </summary>
        /// <param name="message">The message/command</param>
        /// <param name="args">Arguments for a command, e.g an ID</param>
        public static void SendChatEx(string message, params object[] args)
        {
            if (message.Length != 0)
            {
                if (args.Length > 0)
                    message += " " + string.Join(" ", args);
                SendChat(message);
            }
        }

        /// <summary>
        /// Add a new message in the SAMP chat (only local)
        /// </summary>
        /// <param name="text">The text to be written</param>
        /// <param name="color">A color in Hex</param>
        public static void AddChatMessageEx(string text, string color = "FFFFFF")
        {
            AddChatMessage("{" + color + "}" + text);
        }

        /// <summary>
        /// Add a new message in the SAMP chat (only local)
        /// </summary>
        /// <param name="text">The text to be written</param>
        /// <param name="color">A Color-Type</param>
        public static void AddChatMessageEx(string text, Color color)
        {
            AddChatMessage("{" + ColorToHexRGB(color) + "}" + text);
        }

        /// <summary>
        /// Add a new message in the SAMP chat (only local)
        /// </summary>
        /// <param name="prefix">The prefix to be written</param>
        /// <param name="prefixColor">A prefix color in Hex</param>
        /// <param name="text">The text to be written</param>
        /// <param name="color">A color in Hex</param>
        public static void AddChatMessageEx(string prefix, string prefixColor, string text, string color = "FFFFFF")
        {
            AddChatMessage("{" + prefixColor + "}" + prefix + " {" + color + "}" + text);
        }

        /// <summary>
        /// Add a new message in the SAMP chat (only local)
        /// </summary>
        /// <param name="prefix">The prefix to be written</param>
        /// <param name="prefixColor">A Color-Type</param>
        /// <param name="text">The text to be written</param>
        /// <param name="color">A Color-Type</param>
        public static void AddChatMessageEx(string prefix, Color prefixColor, string text, Color color)
        {
            AddChatMessage("{" + ColorToHexRGB(prefixColor) + "}" + prefix + " {" + ColorToHexRGB(color) + "}" + text);
        }

        public static string GetPlayerNameByIDEx(int id)
        {
            StringBuilder builder = new StringBuilder(32);
            GetPlayerNameByID(id, ref builder, builder.Capacity);

            return builder.ToString();
        }

        /// <summary>
        /// Convert a Color to Hex (RGB)
        /// </summary>
        /// <param name="color">Color convert to Hex</param>
        /// <returns></returns>
        public static String ColorToHexRGB(Color color)
        {
            return color.R.ToString("X2") + color.G.ToString("X2") + color.B.ToString("X2");
        }

        /// <summary>
        /// Convert a Color to Hex (ARGB)
        /// </summary>
        /// <param name="color">Color convert to Hex</param>
        /// <returns></returns>
        public static String ColorToHexARGB(Color color)
        {
            return color.A.ToString("X2") + color.R.ToString("X2") + color.G.ToString("X2") + color.B.ToString("X2");
        }
    }
}
'''
    output = header
    FunctionTemplate = '''        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern {0} {1}({2});
'''
    currentOrigin = ""
    for function in functions:
        if currentOrigin != function.origin:
            output += "\n        // {0}\n".format(function.origin)
            currentOrigin = function.origin
        paramList = []
        for argument in function.arguments:
            curParam = ""
            if argument.isPtr:
                curParam = "out "
            if argument.isPtr and argument.aType.typeName == "char":
                curParam = "ref StringBuilder "
            elif argument.aType.isArray and argument.aType.typeName == "char":
                curParam += "string "
            else:
                curParam += argument.aType.typeName + " "
            curParam += argument.name
            paramList.append(curParam)
        output += FunctionTemplate.format(
            function.retType.typeName,
            function.name,
            ", ".join(paramList)
        )
    output += footer
    with codecs.open("C#/SAMP_API.cs", encoding="utf-8", mode="w") as file:
        file.write(output)

def gen_cpp():
    header = '''#pragma once
#define IMPORT extern "C" __declspec(dllimport)
'''
    output = header
    FunctionTemplate = '''IMPORT {0} {1}({2});
'''
    currentOrigin = ""
    for function in functions:
        if currentOrigin != function.origin:
            output += "\n// {0}\n".format(function.origin)
            currentOrigin = function.origin
        paramList = []
        for argument in function.arguments:
            curParam = ""
            if argument.aType.isConst:
                curParam += "const "
            if argument.aType.isUnsigned:
                curParam += "unsigned "
            curParam += argument.aType.typeName
            if argument.aType.isArray:
                curParam += "*"
            curParam += " "
            if argument.isPtr:
                curParam += "&"
            curParam += argument.name
            paramList.append(curParam)
        retType = ""
        if function.retType.isConst:
            retType += "const "
        if function.retType.isUnsigned:
            retType += "unsigned "
        retType += function.retType.typeName
        output += FunctionTemplate.format(
            retType,
            function.name,
            ", ".join(paramList)
        )
    with codecs.open("C++/SAMP_API.h", encoding="utf-8", mode="w") as file:
        file.write(output)


if os.path.split(os.getcwd())[-1] == "include":
    os.chdir("..")
print("Parsing C++ header files...", end=" ")
scan()
print("Done.")
os.chdir("../../../include")
print("Generating AHK include...", end=" ")
gen_ahk()
print("Done.")
print("Generating C# include...", end=" ")
gen_cs()
print("Done.")
print("Generating C++ include...", end=" ")
gen_cpp()
print("Done.")
