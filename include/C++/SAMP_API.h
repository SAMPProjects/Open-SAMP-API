#pragma once
#define IMPORT extern "C" __declspec(dllimport)

//! Creates a text with given parameters.
//! @param[in] Font Name of the font.
//! @param[in] FontSize Size of the font.
//! @param[in] bBold Should the font be bold?
//! @param[in] bItalic Should the font be italic?
//! @param[in] x Position X scaled on a resolution of 800 x 600.
//! @param[in] y Position Y scaled on a resolution of 800 x 600.
//! @param[in] color Color of the text (ARGB-Code).
//! @param[in] text Text of the overlay.
//! @param[in] bShadow Black shadow?
//! @param[in] bShow Should the overlay be drawed after the initialization?
//! @return Returns the text's id, return -1, if an error occured.
IMPORT int TextCreate(const char *Font, int FontSize, bool bBold, bool bItalic, int x, int y, unsigned int color, const char *text, bool bShadow, bool bShow);
//! Destroys a text.
//! @param[in] ID TextID which should be destroyed.
//! @return 1 if successfull, 0 if not.
//! @see TextCreate()
IMPORT int TextDestroy(int ID);
//! Activates / Deactivates the text's shadow.
//! @param[in] id Text's id.
//! @param[in] b true for activation, false for deactivation.
//! @return 1 if successfull, 0 if not.
//! @see TextCreate()
IMPORT int TextSetShadow(int id, bool b);
//! Activates / Deactivates the overlay.
//! @param[in] id Overlay-ID
//! @param[in] b true for activation, false for deactivation.
//! @return 1 if successfull, 0 if not.
//! @see TextCreate()
IMPORT int TextSetShown(int id, bool b);
//! Set the text's color.
//! @param[in] id Text's id.
//! @param[in] color New color (ARGB-code).
//! @return 1 if successfull, 0 if not.
//! @see TextCreate()
IMPORT int TextSetColor(int id, unsigned int color);
//! Give the text a new position.
//! @param[in] id Text's id.
//! @param[in] x Position X scaled on a resolution of 800 x 600.
//! @param[in] y Position Y scaled on a resolution of 800 x 600.
//! @return 1 if successfull, 0 if not.
//! @see TextCreate()
IMPORT int TextSetPos(int id, int x, int y);
//! Seta a new text.
//! @param[in] id Text's id.
//! @param[in] str New text as a string.
//! @return 1 if successfull, 0 if not.
//! @see TextCreate()
IMPORT int TextSetString(int id, const char *str);
//! Updates a text.
//! @param[in] id Text's id.
//! @param[in] Font New font as a string.
//! @param[in] FontSize Size of the font.
//! @param[in] bBold Should the text be bold?
//! @param[in] bItalic Should the text be italic?
//! @return 1 if successfull, 0 if not.
//! @see TextCreate()
IMPORT int TextUpdate(int id, const char *Font, int FontSize, bool bBold, bool bItalic);

//! Creates a box.
//! @param[in] x Position X scaled on a resolution of 800 x 600.
//! @param[in] y Position Y scaled on a resolution of 800 x 600.
//! @param[in] w Box's width scaled on a resolution of 800 x 600.
//! @param[in] h Box's height scaled on a resolution of 800 x 600.
//! @param[in] dwColor Color of the box (ARGB).
//! @param[in] bShow Should the box be drawed after the initialization?
//! @return Returns the box's id, return -1, if an error occured.
IMPORT int BoxCreate(int x, int y, int w, int h, unsigned int dwColor, bool bShow);
//! Destroys a box.
//! @param[in] id Box's id.
//! @return 1 if successfull, 0 if not.
//! @see BoxCreate()
IMPORT int BoxDestroy(int id);
//! Hides or shows a box.
//! @param[in] id ID of the box.
//! @param[in] bShown true, if the box should be displayed, otherwise false.
//! @return 1 if successfull, 0 if not.
//! @see BoxCreate()
IMPORT int BoxSetShown(int id, bool bShown);
//! Enables a border for the box or disables it.
//! @param[in] id Box's id.
//! @param[in] height Border's height.
//! @param[in] bShown true, if the border should be displayed, otherwise false.
//! @return 1 if successfull, 0 if not.
//! @see BoxCreate()
IMPORT int BoxSetBorder(int id, int height, bool bShown);
//! Set die border's color.
//! @param[in] id Box's id.
//! @param[in] dwColor Border's color (ARGB).
//! @return 1 if successfull, 0 if not.
//! @see BoxCreate()
IMPORT int BoxSetBorderColor(int id, unsigned int dwColor);
//! Set the box's color.
//! @param[in] id Box's id.
//! @param[in] dwColor Box'x color (ARGB).
//! @return 1 if successfull, 0 if not.
//! @see BoxCreate()
IMPORT int BoxSetColor(int id, unsigned int dwColor);
//! Set the box's height.
//! @param[in] id Box's id.
//! @param[in] height Box's height, scaled on a resolution of 800 x 600.
//! @return 1 if successfull, 0 if not.
//! @see BoxCreate()
IMPORT int BoxSetHeight(int id, int height);
//! Sets the position of the box.
//! @param[in] id Box's id.
//! @param[in] x Position-X, scaled on a resolution of 800 x 600.
//! @param[in] y Position-Y, scaled on a resolution of 800 x 600.
//! @return 1 if successfull, 0 if not.
//! @see BoxCreate()
IMPORT int BoxSetPos(int id, int x, int y);
//! Sets the box's width.
//! @param[in] id Box's id.
//! @param[in] width Box's width.
//! @return 1 if successfull, 0 if not.
//! @see BoxCreate()
IMPORT int BoxSetWidth(int id, int width);

//! Creates a line.
//! @param[in] x1 Position X of the first point, scaled on a resolution of 800 x 600.
//! @param[in] y1 Position Y of the first point, scaled on a resolution of 800 x 600.
//! @param[in] x2 Position X of the second point, scaled on a resolution of 800 x 600.
//! @param[in] y2 Position Y of the second point, scaled on a resolution of 800 x 600.
//! @param[in] width Line's width.
//! @param[in] color Line's color (ARGB).
//! @param[in] bShow Should the line be drawed after initialization?
//! @return Returns the line's id, return -1, if an error occured.
IMPORT int LineCreate(int x1, int y1, int x2, int y2, int width, unsigned int color, bool bShow);
//! Destroys a line.
//! @param[in] id Line's id.
//! @return 1 if successfull, 0 if not.
IMPORT int LineDestroy(int id);
//! Hides or shows a line.
//! @param[in] id Line's id.
//! @param[in] bShown true, if the border should be displayed, otherwise false.
//! @return 1 if successfull, 0 if not.
//! @see LineCreate()
IMPORT int LineSetShown(int id, bool bShown);
//! Sets a line's color.
//! @param[in] id Line's id.
//! @param[in] color New color (ARGB).
//! @return 1 if successfull, 0 if not.
//! @see LineCreate()
IMPORT int LineSetColor(int id, unsigned int color);
//! Sets a line's width.
//! @param[in] id Line's id.
//! @param[in] width New width.
//! @return 1 if successfull, 0 if not.
//! @see LineCreate()
IMPORT int LineSetWidth(int id, int width);
//! Set the line's position
//! @param[in] id Line's id.
//! @param[in] x1 Position X of the first point, scaled on a resolution of 800 x 600.
//! @param[in] y1 Position Y of the first point, scaled on a resolution of 800 x 600.
//! @param[in] x2 Position X of the second point, scaled on a resolution of 800 x 600.
//! @param[in] y2 Position Y of the second point, scaled on a resolution of 800 x 600.
//! @return 1 if successfull, 0 if not.
//! @see LineCreate()
IMPORT int LineSetPos(int id, int x1, int y1, int x2, int y2);

//! Creates an image.
//! @param[in] path Relativ or absolut path to an image file.
//! @param[in] x Position X scaled on a resolution of 800 x 600
//! @param[in] y Position Y scaled on a resolution of 800 x 600
//! @param[in] rotation Image's rotation.
//! @param[in] align Image's alignment.
//! @param[in] bShow Should the image be drawed after initialization?
//! @return the id of the image otherwise -1 if an error occured
IMPORT int ImageCreate(const char *path, int x, int y, int rotation, int align, bool bShow);
//! Destroys an image.
//! @param[in] id Image's id.
//! @return 1 if successfull, 0 if not.
//! @see ImageCreate()
IMPORT int ImageDestroy(int id);
//! Hides or shows an image.
//! @param[in] id Image's id.
//! @param[in] bShown true, if the image should be drawed, otherwise false.
//! @return 1 if successfull, 0 if not.
//! @see ImageCreate()
IMPORT int ImageSetShown(int id, bool bShown);
//! Sets an image's alignment.
//! @param[in] id Image's id.
//! @param[in] align New alignment.
//! @return 1 if successfull, 0 if not.
//! @see ImageCreate()
IMPORT int ImageSetAlign(int id, int align);
//! Sets an image's position.
//! @param[in] id Image's id.
//! @param[in] x Position X scaled on a resolution of 800 x 600
//! @param[in] y Position Y scaled on a resolution of 800 x 600
//! @return 1 if successfull, 0 if not.
//! @see ImageCreate()
IMPORT int ImageSetPos(int id, int x, int y);
//! Sets an image's rotation.
//! @param[in] id Image's id.
//! @param[in] rotation New rotation.
//! @return 1 if successfull, 0 if not.
//! @see ImageCreate()
IMPORT int ImageSetRotation(int id, int rotation);

//! Destroys all overlays.
//! @return 1 if successfull, 0 if not.
IMPORT int DestroyAllVisual();
//! Shows all overlays.
//! @return 1 if successfull, 0 if not.
IMPORT int ShowAllVisual();
//! Hides all overlays.
//! @return 1 if successfull, 0 if not.
IMPORT int HideAllVisual();

//! Reads the game's framerate.
//! @return Returns the framerate, -1 if an error occured.
IMPORT int GetFrameRate();
//! Reads the game's resolution.
//! @param[out] width Width of the game.
//! @param[out] height Height of the game.
//! @return 1 if successfull, 0 if not.
IMPORT int GetScreenSpecs(int& width, int& height);

//! Sets the calculation ratio of the overlay objects.
//! @param[in] width The calculation width.
//! @param[in] height The calculation height.
//! @return 1 if successfull, 0 if not.
IMPORT int SetCalculationRatio(int width, int height);

//! Sets the priority of an overlay object.
//! If the priority of an overlay object is higher than the priority of another object the object with the higher priority will be drawn in the foreground.
//! @param[in] id The id of the overlay object.
//! @param[in] priority The object's new priority.
//! @return 1 if successfull, 0 if not.
IMPORT int SetOverlayPriority(int id, int priority);

//! Send a command or chat message directly to the server.
//! @param[in] msg The message which should be sent.
//! @return 1 if successfull, 0 if not.
IMPORT int SendChat(const char *msg);
//! Draw a game text.
//! @param[in] msg The message which should be shown.
//! @param[in] time The time in milliseconds
//! @param[in] style The style which should be used.
//! //! @return 1 if successfull, 0 if not.
IMPORT int ShowGameText(const char *msg, int time, int style);
//! Adds a chat message to the chat window.
//! @param[in] msg The message which should be added.
//! @return 1 if successfull, 0 if not.
IMPORT int AddChatMessage(const char *msg);

//! Reads the health of the player.
//! @return -1 if an error occured, otherwise the health.
IMPORT int GetPlayerHealth();
//! Reads the armor of the player.
//! @return -1 if an error occured, otherwise the armor.
IMPORT int GetPlayerArmor();
//! Check if the player is in any vehicle.
//! @return 1 if the player is in any vehicle, 0 if not or an error occured.
IMPORT int IsPlayerInAnyVehicle();
//! Check if the player is in a interior.
//! @return 1 if the player is in a interior, 0 if not or an error occured.
IMPORT int IsPlayerInInterior();
//! Reads the X-axis of the player.
//! @param[in] posX Reference to be written.
//! @return 1 if successfull, 0 if not.
IMPORT int GetPlayerX(float &posX);
//! Reads the Y-axis of the player.
//! @param[in] posY Reference to be written.
//! @return 1 if successfull, 0 if not.
IMPORT int GetPlayerY(float &posY);
//! Reads the Z-axis of the player.
//! @param[in] posZ Reference to be written.
//! @return 1 if successfull, 0 if not.
IMPORT int GetPlayerZ(float &posZ);
//! Reads the X-, Y- and Z-axis of the player.
//! @param[in] posX Reference to be written the X-axis.
//! @param[in] posY Reference to be written the Y-axis.
//! @param[in] posZ Reference to be written the Z-axis.
//! @return 1 if successfull, 0 if not.
IMPORT int GetPlayerPosition(float &posX, float &posY, float &posZ);
//! Check if the player is in the radius of the given X- and Y-axis
//! @param[in] posX The X-axis of the point.
//! @param[in] posY The Y-axis of the point.
//! @param[in] radius The radius of the point.
//! @return 1 if the player is in the radius, 0 if not.
IMPORT int IsPlayerInRange2D(float posX, float posY, float radius);
//! Check if the player is in the radius of the given X-, Y- and Z-axis
//! @param[in] posX The X-axis of the point.
//! @param[in] posY The Y-axis of the point.
//! @param[in] posY The Z-axis of the point.
//! @param[in] radius The radius of the point.
//! @return 1 if the player is in the radius, 0 if not.
IMPORT int IsPlayerInRange3D(float posX, float posY, float posZ, float radius);

//! Reads the pointer of the current vehicle.
//! @return Returns the pointer of the current vehicle, 0 if an error occured or the player was not in a vehicle.
IMPORT unsigned int GetVehiclePointer();
//! Calculate the current vehicle speed.
//! @param[in] factor The factor of the speed.
//! @return -1 if an error occured, otherwise the speed.
IMPORT int GetVehicleSpeed(float factor);
//! Reads the vehicle health
//! @return -1.0 if an error occured, otherwise the health.
IMPORT float GetVehicleHealth();
//! Reads the type Id of the vehicle.
//! @return -1 if an error occured, otherwise the type Id.
IMPORT short GetVehicleTypeId();
//! Check if the current vehicle is a bike.
//! @return 1 if it is a bike, 0 if not or an error occured.
IMPORT int IsVehicleBike();

//! Routine to initialize the API, but it does not have to be explicitly called because it's initialized internally.
//! @return 1 if successfull, 0 if not.
IMPORT int  Init();
//! Sets API's parameters.\n
//! Possible Parameters for '_szParamName':\n
//! "use_window" The API uses the window name instead the process name. default 0.\n
//! "process" Name of the process, will be ignored, if 'use_window' is set to '1'.\n
//! "window" Name of the window.\n
//! \n
//! @param[in] _szParamName Key.
//! @param[in] _szParamValue Value.
//! This function MUST be called for the proper use of the API.
IMPORT void SetParam(const char *_szParamName, const char *_szParamValue);
