Open-SAMP-API
=============

An open source API for GTA SA:MP licensed under the terms of the LGPL 3.0. Dependencies are under their respective licenses.

Dependencies
------------
- [Boost C++ Libraries](http://www.boost.org/)

Documentation
------------
- [Doxygen Docs](http://www.samp-api.net/doc/)

Exported functions
-------------------
```
//SAMP functions
int SendChat(const char *msg);
int ShowGameText(const char *msg, int time, int style);
int AddChatMessage(const char *msg);

// Rendering functions
int TextCreate(char *Font, int FontSize, bool bBold, bool bItalic, int x, int y, unsigned int color, char *text, bool bShadow, bool bShow);
int TextDestroy(int ID);
int TextSetShadow(int id, bool b);
int TextSetShown(int id, bool b);
int TextSetColor(int id, unsigned int color);
int TextSetPos(int id, int x, int y);
int TextSetString(int id, char *str);
int TextUpdate(int id, char *Font, int FontSize, bool bBold, bool bItalic);

int BoxCreate(int x, int y, int w, int h, unsigned int dwColor, bool bShow);
int BoxDestroy(int id);
int BoxSetShown(int id, bool bShown);
int BoxSetBorder(int id, int height, bool bShown);
int BoxSetBorderColor(int id, unsigned int dwColor);
int BoxSetColor(int id, unsigned int dwColor);
int BoxSetHeight(int id, int height);
int BoxSetPos(int id, int x, int y);
int BoxSetWidth(int id, int width);

int LineCreate(int x1, int y1, int x2, int y2, int width, unsigned int color, bool bShow);
int LineDestroy(int id);
int LineSetShown(int id, bool bShown);
int LineSetColor(int id, unsigned int color);
int LineSetWidth(int id, int width);
int LineSetPos(int id, int x1, int y1, int x2, int y2);

int ImageCreate(char *path, int x, int y, int rotation, int align, bool bShow);
int ImageDestroy(int id);
int ImageSetShown(int id, bool bShown);
int ImageSetAlign(int id, int align);
int ImageSetPos(int id, int x, int y);
int ImageSetRotation(int id, int rotation);

int DestroyAllVisual();
int ShowAllVisual();
int HideAllVisual();

int GetFrameRate();
int GetScreenSpecs(int& width, int& height);

int SetCalculationRatio(int width, int height);
int SetOverlayPriority(int id, int priority);
```
