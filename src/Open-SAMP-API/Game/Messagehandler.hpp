#pragma once
#include <Utils/Serializer.hpp>
#include <Shared/PipeMessages.hpp>
#include <functional>

namespace Game
{
	namespace MessageHandler
	{
		void TextCreate(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);
		void TextDestroy(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);
		void TextSetShadow(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);
		void TextSetShown(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);
		void TextSetColor(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);
		void TextSetPos(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);
		void TextSetString(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);
		void TextUpdate(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);

		void BoxCreate(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);
		void BoxDestroy(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);
		void BoxSetShown(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);
		void BoxSetBorder(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);
		void BoxSetBorderColor(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);
		void BoxSetColor(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);
		void BoxSetHeight(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);
		void BoxSetPos(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);
		void BoxSetWidth(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);

		void LineCreate(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);
		void LineDestroy(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);
		void LineSetShown(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);
		void LineSetColor(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);
		void LineSetWidth(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);
		void LineSetPos(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);

		void ImageCreate(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);
		void ImageDestroy(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);
		void ImageSetShown(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);
		void ImageSetAlign(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);
		void ImageSetPos(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);
		void ImageSetRotation(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);

		void DestroyAllVisual(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);
		void ShowAllVisual(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);
		void HideAllVisual(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);

		void GetFrameRate(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);
		void GetScreenSpecs(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);

		void SetCalculationRatio(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);

		void SetOverlayPriority(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);
		void SetOverlayCalculationEnabled(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);

		void GetGTACommandLine(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);

		void SendChat(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);
		void ShowGameText(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);
		void AddChatMessage(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);
		void GetPlayerNameByID(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);
		void IsChatOpen(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);
		void IsDialogOpen(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);

		void ReadMemory(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);

		void ScreenToWorld(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);
		void WorldToScreen(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut);
	}
}
