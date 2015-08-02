#pragma once
#include "Client.hpp"

namespace Client
{
	namespace RenderFunctions
	{
		EXPORT int TextCreate(const char *Font, float FontSize, bool bBold, bool bItalic, float x, float y, unsigned int color, const char *text, bool bShadow, bool bShow);
		EXPORT int TextDestroy(int ID);
		EXPORT int TextSetShadow(int id, bool b);
		EXPORT int TextSetShown(int id, bool b);
		EXPORT int TextSetColor(int id, unsigned int color);
		EXPORT int TextSetString(int id, const char *str);
		EXPORT int TextUpdate(int id, const char *Font, float FontSize, bool bBold, bool bItalic);

		EXPORT int BoxCreate(float x, float y, float w, float h, unsigned int dwColor, bool bShow);
		EXPORT int BoxDestroy(int id);
		EXPORT int BoxSetShown(int id, bool bShown);
		EXPORT int BoxSetBorder(int id, float height, bool bShown);
		EXPORT int BoxSetBorderColor(int id, unsigned int dwColor);
		EXPORT int BoxSetColor(int id, unsigned int dwColor);
		EXPORT int BoxSetHeight(int id, float height);
		EXPORT int BoxSetWidth(int id, float width);

		EXPORT int LineCreate(float x1, float y1, float x2, float y2, float width, unsigned int color, bool bShow);
		EXPORT int LineDestroy(int id);
		EXPORT int LineSetShown(int id, bool bShown);
		EXPORT int LineSetColor(int id, unsigned int color);
		EXPORT int LineSetWidth(int id, float width);
		EXPORT int LineSetPos(int id, float x1, float y1, float x2, float y2);

		EXPORT int ImageCreate(const char *path, float x, float y, float rotation, int align, bool bShow);
		EXPORT int ImageDestroy(int id);
		EXPORT int ImageSetShown(int id, bool bShown);
		EXPORT int ImageSetAlign(int id, int align);
		EXPORT int ImageSetRotation(int id, float rotation);

		EXPORT int DestroyAllVisual();
		EXPORT int ShowAllVisual();
		EXPORT int HideAllVisual();

		EXPORT int GetFrameRate();
		EXPORT int GetScreenSpecs(int& width, int& height);

		EXPORT int SetCalculationRatio(float width, float height);
		EXPORT int SetOverlayPriority(int id, int priority);
		EXPORT int SetOverlayCalculationEnabled(int id, bool enabled);
		EXPORT int SetOverlay2DPosition(int id, float x, float y);
		EXPORT int SetOverlay3DPosition(int id, float x, float y, float z);
	}
}
