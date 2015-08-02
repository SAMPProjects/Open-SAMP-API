#pragma once

namespace Shared
{
	enum class PipeMessages : short
	{
		// Internal use
		Ping = 1,

		// Text functions
		TextCreate,
		TextDestroy,
		TextSetShadow,
		TextSetShown,
		TextSetColor,
		TextSetString,
		TextUpdate,

		// Box functions
		BoxCreate,
		BoxDestroy,
		BoxSetShown,
		BoxSetBorder,
		BoxSetBorderColor,
		BoxSetColor,
		BoxSetHeight,
		BoxSetWidth,

		// Line functions
		LineCreate,
		LineDestroy,
		LineSetShown,
		LineSetColor,
		LineSetWidth,
		LineSetPos,

		// Image functions
		ImageCreate,
		ImageDestroy,
		ImageSetShown,
		ImageSetAlign,
		ImageSetRotation,

		// Misc overlay functions
		DestroyAllVisual,
		ShowAllVisual,
		HideAllVisual,
		GetFrameRate,
		GetScreenSpecs,
		SetCalculationRatio,
		SetOverlayPriority,
		SetOverlayCalculationEnabled,
		SetOverlay2DPosition,
		SetOverlay3DPosition,

		// SAMP functions
		SendChat,
		ShowGameText,
		AddChatMessage,
		GetPlayerNameByID,
		IsChatOpen,
		IsDialogOpen,

		// Memory functions
		ReadMemory,

		// Misc GTA functions
		WorldToScreen
	};
}
