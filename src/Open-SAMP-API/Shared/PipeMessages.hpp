#pragma once

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

	// SAMP functions
	SendChat,
	ShowGameText,
	AddChatMessage
};