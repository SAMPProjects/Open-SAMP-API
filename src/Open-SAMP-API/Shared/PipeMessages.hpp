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
		TextSetPos,
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
		BoxSetPos,
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
		ImageSetPos,
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
