using System;
using System.Drawing;
using System.Runtime.InteropServices;

namespace SAMP_API
{
    class API
    {
        public const String PATH = "Open-SAMP-API.dll";

        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int TextCreate(string font, int fontSize, bool bBold, bool bItalic, int x, int y, uint color, string text, bool bShadow, bool bShow);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int TextDestroy(int id);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int TextSetShadow(int id, bool b);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int TextSetShown(int id, bool b);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int TextSetColor(int id, uint color);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int TextSetPos(int id, int x, int y);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int TextSetString(int id, string str);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int TextUpdate(int id, string font, int fontSize, bool bBold, bool bItalic);

        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int BoxCreate(int x, int y, int w, int h, uint dwColor, bool bShow);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int BoxDestroy(int id);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int BoxSetShown(int id, bool bShown);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int BoxSetBorder(int id, int height, bool bShown);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int BoxSetBorderColor(int id, uint dwColor);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int BoxSetColor(int id, uint dwColor);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int BoxSetHeight(int id, int height);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int BoxSetPos(int id, int x, int y);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int BoxSetWidth(int id, int width);

        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int LineCreate(int x1, int y1, int x2, int y2, int width, uint color, bool bShow);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int LineDestroy(int id);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int LineSetShown(int id, bool bShown);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int LineSetColor(int id, uint color);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int LineSetWidth(int id, int width);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int LineSetPos(int id, int x1, int y1, int x2, int y2);

        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int ImageCreate(string path, int x, int y, int rotation, int align, bool bShow);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int ImageDestroy(int id);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int ImageSetShown(int id, bool bShown);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int ImageSetAlign(int id, int align);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int ImageSetPos(int id, int x, int y);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int ImageSetRotation(int id, int rotation);

        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int DestroyAllVisual();
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int ShowAllVisual();
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int HideAllVisual();

        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetFrameRate();
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetScreenSpecs(out int width, out int height);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int SetCalculationRatio(int width, int height);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int SetOverlayPriority(int id, int priority);

        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int SendChat(string msg);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int ShowGameText(string msg, int time, int style);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int AddChatMessage(string msg);

        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetPlayerHealth();
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetPlayerArmor();
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int IsPlayerInAnyVehicle();
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int IsPlayerInInterior();
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetPlayerX(ref float posX);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetPlayerY(ref float posY);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetPlayerZ(ref float posZ);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetPlayerPosition(ref float posX, ref float posY, ref float posZ);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int IsPlayerInRange2D(float posX, float posY, float radius);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int IsPlayerInRange3D(float posX, float posY, float posZ, float radius);

        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern uint GetVehiclePointer();
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetVehicleSpeed(float factor);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern float GetVehicleHealth();
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern short GetVehicleTypeId();
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int IsVehicleBike();

        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetPlayerIDByName(string name);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetPlayerNameByID(int id, ref string playerName, int maxLength);

        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int Init();
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern void SetParam(string _szParamName, string _szParamValue);

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

