using System;
using System.Drawing;
using System.Runtime.InteropServices;

namespace SAMP_API
{
    class API
    {
        public const String PATH = "Open-SAMP-API.dll";

        // Client.hpp
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int Init();
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern void SetParam(string _szParamName, string _szParamValue);

        // GTAFunctions.hpp
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern bool IsMenuOpen();

        // PlayerFunctions.hpp
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetPlayerCPed();
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetPlayerHealth();
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetPlayerArmor();
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetPlayerMoney();
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int IsPlayerInAnyVehicle();
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int IsPlayerDriver();
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int IsPlayerPassenger();
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int IsPlayerInInterior();
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetPlayerX(out float posX);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetPlayerY(out float posY);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetPlayerZ(out float posZ);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetPlayerPosition(out float posX, out float posY, out float posZ);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int IsPlayerInRange2D(float posX, float posY, float radius);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int IsPlayerInRange3D(float posX, float posY, float posZ, float radius);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetCityName(out StringBuilder cityName, int max_len);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetZoneName(out StringBuilder zoneName, int max_len);

        // RenderFunctions.hpp
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int TextCreate(string Font, int FontSize, bool bBold, bool bItalic, int x, int y, int color, string text, bool bShadow, bool bShow);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int TextDestroy(int ID);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int TextSetShadow(int id, bool b);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int TextSetShown(int id, bool b);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int TextSetColor(int id, int color);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int TextSetPos(int id, int x, int y);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int TextSetString(int id, string str);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int TextUpdate(int id, string Font, int FontSize, bool bBold, bool bItalic);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int BoxCreate(int x, int y, int w, int h, int dwColor, bool bShow);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int BoxDestroy(int id);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int BoxSetShown(int id, bool bShown);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int BoxSetBorder(int id, int height, bool bShown);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int BoxSetBorderColor(int id, int dwColor);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int BoxSetColor(int id, int dwColor);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int BoxSetHeight(int id, int height);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int BoxSetPos(int id, int x, int y);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int BoxSetWidth(int id, int width);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int LineCreate(int x1, int y1, int x2, int y2, int width, int color, bool bShow);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int LineDestroy(int id);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int LineSetShown(int id, bool bShown);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int LineSetColor(int id, int color);
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

        // SAMPFunctions.hpp
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int SendChat(string msg);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int ShowGameText(string msg, int time, int style);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int AddChatMessage(string msg);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetPlayerNameByID(int id, out StringBuilder playername, int max_len);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetPlayerIDByName(string name);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int IsChatOpen();
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int IsDialogOpen();

        // VehicleFunctions.hpp
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetVehiclePointer();
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetVehicleSpeed(float factor);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern float GetVehicleHealth();
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetVehicleModelId();
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetVehicleModelName(out StringBuilder name, int len);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetVehicleModelNameById(int vehicleID, out StringBuilder name, int len);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetVehicleType();
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetVehicleFreeSeats(out int seatFL, out int seatFR, out int seatRL, out int seatRR);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetVehicleFirstColor();
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetVehicleSecondColor();
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetVehicleColor(out int color1, out int color2);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int IsVehicleSeatUsed(int seat);
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int IsVehicleLocked();
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int IsVehicleHornEnabled();
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int IsVehicleSirenEnabled();
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int IsVehicleAlternateSireneEnabled();
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int IsVehicleEngineEnabled();
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int IsVehicleLightEnabled();
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int IsVehicleCar();
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int IsVehiclePlane();
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int IsVehicleBoat();
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int IsVehicleTrain();
        [DllImport(PATH, CallingConvention = CallingConvention.Cdecl)]
        public static extern int IsVehicleBike();

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
            GetPlayerNameByID(id, out builder, builder.Capacity);

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
