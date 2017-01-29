#pragma once
#define IMPORT extern "C" __declspec(dllimport)

// Client.hpp
IMPORT int Init();
IMPORT void SetParam(char* _szParamName, char* _szParamValue);

// GTAFunctions.hpp
IMPORT int GetGTACommandLine(char* &line, int max_len);
IMPORT bool IsMenuOpen();
IMPORT bool ScreenToWorld(float x, float y, float &worldX, float &worldY, float &worldZ);
IMPORT bool WorldToScreen(float x, float y, float z, float &screenX, float &screenY);

// PlayerFunctions.hpp
IMPORT int GetPlayerCPed();
IMPORT int GetPlayerHealth();
IMPORT int GetPlayerArmor();
IMPORT int GetPlayerMoney();
IMPORT int GetPlayerSkinID();
IMPORT int GetPlayerInterior();
IMPORT int IsPlayerInAnyVehicle();
IMPORT int IsPlayerDriver();
IMPORT int IsPlayerPassenger();
IMPORT int IsPlayerInInterior();
IMPORT int GetPlayerX(float &posX);
IMPORT int GetPlayerY(float &posY);
IMPORT int GetPlayerZ(float &posZ);
IMPORT int GetPlayerPosition(float &posX, float &posY, float &posZ);
IMPORT int IsPlayerInRange2D(float posX, float posY, float radius);
IMPORT int IsPlayerInRange3D(float posX, float posY, float posZ, float radius);
IMPORT int GetCityName(char* &cityName, int max_len);
IMPORT int GetZoneName(char* &zoneName, int max_len);

// RenderFunctions.hpp
IMPORT int TextCreate(const char* Font, int FontSize, bool bBold, bool bItalic, int x, int y, unsigned int color, const char* text, bool bShadow, bool bShow);
IMPORT int TextDestroy(int ID);
IMPORT int TextSetShadow(int id, bool b);
IMPORT int TextSetShown(int id, bool b);
IMPORT int TextSetColor(int id, unsigned int color);
IMPORT int TextSetPos(int id, int x, int y);
IMPORT int TextSetString(int id, const char* str);
IMPORT int TextUpdate(int id, const char* Font, int FontSize, bool bBold, bool bItalic);
IMPORT int BoxCreate(int x, int y, int w, int h, unsigned int dwColor, bool bShow);
IMPORT int BoxDestroy(int id);
IMPORT int BoxSetShown(int id, bool bShown);
IMPORT int BoxSetBorder(int id, int height, bool bShown);
IMPORT int BoxSetBorderColor(int id, unsigned int dwColor);
IMPORT int BoxSetColor(int id, unsigned int dwColor);
IMPORT int BoxSetHeight(int id, int height);
IMPORT int BoxSetPos(int id, int x, int y);
IMPORT int BoxSetWidth(int id, int width);
IMPORT int LineCreate(int x1, int y1, int x2, int y2, int width, unsigned int color, bool bShow);
IMPORT int LineDestroy(int id);
IMPORT int LineSetShown(int id, bool bShown);
IMPORT int LineSetColor(int id, unsigned int color);
IMPORT int LineSetWidth(int id, int width);
IMPORT int LineSetPos(int id, int x1, int y1, int x2, int y2);
IMPORT int ImageCreate(const char* path, int x, int y, int rotation, int align, bool bShow);
IMPORT int ImageDestroy(int id);
IMPORT int ImageSetShown(int id, bool bShown);
IMPORT int ImageSetAlign(int id, int align);
IMPORT int ImageSetPos(int id, int x, int y);
IMPORT int ImageSetRotation(int id, int rotation);
IMPORT int DestroyAllVisual();
IMPORT int ShowAllVisual();
IMPORT int HideAllVisual();
IMPORT int GetFrameRate();
IMPORT int GetScreenSpecs(int &width, int &height);
IMPORT int SetCalculationRatio(int width, int height);
IMPORT int SetOverlayPriority(int id, int priority);
IMPORT int SetOverlayCalculationEnabled(int id, bool enabled);

// SAMPFunctions.hpp
IMPORT int GetServerIp(char* &ip, int max_len);
IMPORT int GetServerPort();
IMPORT int SendChat(const char* msg);
IMPORT int ShowGameText(const char* msg, int time, int style);
IMPORT int AddChatMessage(const char* msg);
IMPORT int ShowDialog(int id, int style, const char* caption, const char* text, const char* button, const char* button2);
IMPORT int GetPlayerNameByID(int id, char* &playername, int max_len);
IMPORT int GetPlayerIDByName(const char* name);
IMPORT int GetPlayerName(char* &playername, int max_len);
IMPORT int GetPlayerId();
IMPORT int IsChatOpen();
IMPORT int IsDialogOpen();

// VehicleFunctions.hpp
IMPORT unsigned int GetVehiclePointer();
IMPORT int GetVehicleSpeed(float factor);
IMPORT float GetVehicleHealth();
IMPORT int GetVehicleModelId();
IMPORT int GetVehicleModelName(char* &name, int max_len);
IMPORT int GetVehicleModelNameById(int vehicleID, char* &name, int max_len);
IMPORT int GetVehicleType();
IMPORT int GetVehicleFreeSeats(int &seatFL, int &seatFR, int &seatRL, int &seatRR);
IMPORT int GetVehicleFirstColor();
IMPORT int GetVehicleSecondColor();
IMPORT int GetVehicleColor(int &color1, int &color2);
IMPORT int IsVehicleSeatUsed(int seat);
IMPORT int IsVehicleLocked();
IMPORT int IsVehicleHornEnabled();
IMPORT int IsVehicleSirenEnabled();
IMPORT int IsVehicleAlternateSirenEnabled();
IMPORT int IsVehicleEngineEnabled();
IMPORT int IsVehicleLightEnabled();
IMPORT int IsVehicleCar();
IMPORT int IsVehiclePlane();
IMPORT int IsVehicleBoat();
IMPORT int IsVehicleTrain();
IMPORT int IsVehicleBike();

// WeaponFunctions.hpp
IMPORT int HasWeaponIDClip(int weaponID);
IMPORT int GetPlayerWeaponID();
IMPORT int GetPlayerWeaponType();
IMPORT int GetPlayerWeaponSlot();
IMPORT int GetPlayerWeaponName(int dwWeapSlot, char* &_szWeapName, int max_len);
IMPORT int GetPlayerWeaponClip(int dwWeapSlot);
IMPORT int GetPlayerWeaponTotalClip(int dwWeapSlot);
IMPORT int GetPlayerWeaponState();
IMPORT int GetPlayerWeaponAmmo(int weaponType);
IMPORT int GetPlayerWeaponAmmoInClip(int weaponType);
