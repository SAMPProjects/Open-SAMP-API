#include <Utils/SafeBlock.hpp>

#include "Messagehandler.hpp"
#include "Game.hpp"
#include "SAMP.hpp"
#include "Rendering/Text.hpp"
#include "Rendering/Box.hpp"
#include "Rendering/Line.hpp"
#include "Rendering/Image.hpp"
#include "Rendering/Renderer.hpp"
#include "Rendering/RenderBase.hpp"

#define READ(X, Y) SERIALIZATION_READ(serializerIn, X, Y);
#define WRITE(X) serializerOut << X;

void Game::MessageHandler::TextCreate(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
{
	READ(std::string, Font); 
	READ(int, FontSize); 
	READ(bool, bBold);
	READ(bool, bItalic);
	READ(int, x); 
	READ(int, y);
	READ(unsigned int, color);
	READ(std::string, string);
	READ(bool, bShadow);
	READ(bool, bShow);

	WRITE(g_pRenderer.add(std::make_shared<Rendering::Text>(&g_pRenderer, Font, FontSize, bBold, bItalic, x, y, color, string, bShadow, bShow)));
}

void Game::MessageHandler::TextDestroy(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
{
	READ(int, id);
	WRITE(int(g_pRenderer.remove(id)));
}

void Game::MessageHandler::TextSetShadow(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
{
	READ(int, id); 
	READ(bool, bShadow);
	
	WRITE(int(Utils::SafeBlock::safeExecuteWithValidation([&](){ 
		g_pRenderer.getAs<Rendering::Text>(id)->setShadow(bShadow); 
	})));
}

void Game::MessageHandler::TextSetShown(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
{
	READ(int, id); 
	READ(bool, bShown);

	WRITE(int(Utils::SafeBlock::safeExecuteWithValidation([&](){
		g_pRenderer.getAs<Rendering::Text>(id)->setShown(bShown);
	})));
}

void Game::MessageHandler::TextSetColor(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
{
	READ(int, id); 
	READ(unsigned int, color);

	WRITE(int(Utils::SafeBlock::safeExecuteWithValidation([&](){
		g_pRenderer.getAs<Rendering::Text>(id)->setColor(color);
	})));
}

void Game::MessageHandler::TextSetPos(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
{
	READ(int, id); 
	READ(int, x); 
	READ(int, y);

	WRITE(int(Utils::SafeBlock::safeExecuteWithValidation([&](){
		g_pRenderer.getAs<Rendering::Text>(id)->setPos(x, y);
	})));
}

void Game::MessageHandler::TextSetString(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
{
	READ(int, id); 
	READ(std::string, str);

	WRITE(int(Utils::SafeBlock::safeExecuteWithValidation([&](){
		g_pRenderer.getAs<Rendering::Text>(id)->setText(str);
	})));
}

void Game::MessageHandler::TextUpdate(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
{
	READ(int, id); 
	READ(std::string, Font); 
	READ(int, FontSize); 
	READ(bool, bBold); 
	READ(bool, bItalic);

	WRITE(int(Utils::SafeBlock::safeExecuteWithValidation([&](){
		g_pRenderer.getAs<Rendering::Text>(id)->updateText(Font, FontSize, bBold, bItalic);
	})));
}

void Game::MessageHandler::BoxCreate(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
{
	READ(int, x); 
	READ(int, y); 
	READ(int, w); 
	READ(int, h); 
	READ(unsigned int, dwColor); 
	READ(bool, bShow);

	WRITE(g_pRenderer.add(std::make_shared<Rendering::Box>(&g_pRenderer, x, y, w, h, dwColor, bShow)));
}

void Game::MessageHandler::BoxDestroy(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
{
	READ(int, id);
	WRITE((int) g_pRenderer.remove(id));
}

void Game::MessageHandler::BoxSetShown(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
{
	READ(int, id); 
	READ(bool, bShown);

	WRITE(int(Utils::SafeBlock::safeExecuteWithValidation([&](){
		g_pRenderer.getAs<Rendering::Box>(id)->setShown(bShown);
	})));
}

void Game::MessageHandler::BoxSetBorder(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
{
	READ(int, id); 
	READ(int, height); 
	READ(bool, bShown);

	WRITE(int(Utils::SafeBlock::safeExecuteWithValidation([&](){
		g_pRenderer.getAs<Rendering::Box>(id)->setBorderWidth(height);
		g_pRenderer.getAs<Rendering::Box>(id)->setBorderShown(bShown);
	})));
}

void Game::MessageHandler::BoxSetBorderColor(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
{
	READ(int, id); 
	READ(unsigned int, dwColor);

	WRITE(int(Utils::SafeBlock::safeExecuteWithValidation([&](){
		g_pRenderer.getAs<Rendering::Box>(id)->setBorderColor(dwColor);
	})));
}

void Game::MessageHandler::BoxSetColor(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
{
	READ(int, id); 
	READ(unsigned int, dwColor);

	WRITE(int(Utils::SafeBlock::safeExecuteWithValidation([&](){
		g_pRenderer.getAs<Rendering::Box>(id)->setBoxColor(dwColor);
	})));
}

void Game::MessageHandler::BoxSetHeight(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
{
	READ(int, id); 
	READ(int, height);

	WRITE(int(Utils::SafeBlock::safeExecuteWithValidation([&](){
		g_pRenderer.getAs<Rendering::Box>(id)->setBoxHeight(height);
	})));
}

void Game::MessageHandler::BoxSetPos(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
{
	READ(int, id); 
	READ(int, x); 
	READ(int, y);

	WRITE(int(Utils::SafeBlock::safeExecuteWithValidation([&](){
		g_pRenderer.getAs<Rendering::Box>(id)->setPos(x, y);
	})));
}

void Game::MessageHandler::BoxSetWidth(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
{
	READ(int, id); 
	READ(int, width);

	WRITE(int(Utils::SafeBlock::safeExecuteWithValidation([&](){
		g_pRenderer.getAs<Rendering::Box>(id)->setBoxWidth(width);
	})));
}

void Game::MessageHandler::LineCreate(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
{
	READ(int, x1); 
	READ(int, y1); 
	READ(int, x2); 
	READ(int, y2); 
	READ(int, width); 
	READ(unsigned int, color);
	READ(bool, bShow);

	WRITE(g_pRenderer.add(std::make_shared<Rendering::Line>(&g_pRenderer, x1, y1, x2, y2, width, color, bShow)));
}

void Game::MessageHandler::LineDestroy(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
{
	READ(int, id);
	WRITE((int) g_pRenderer.remove(id));
}

void Game::MessageHandler::LineSetShown(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
{
	READ(int, id); 
	READ(bool, bShown);

	WRITE(int(Utils::SafeBlock::safeExecuteWithValidation([&](){
		g_pRenderer.getAs<Rendering::Line>(id)->setShown(bShown);
	})));
}

void Game::MessageHandler::LineSetColor(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
{
	READ(int, id); 
	READ(unsigned int, color);

	WRITE(int(Utils::SafeBlock::safeExecuteWithValidation([&](){
		g_pRenderer.getAs<Rendering::Line>(id)->setColor(color);
	})));
}

void Game::MessageHandler::LineSetWidth(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
{
	READ(int, id); 
	READ(int, width);

	WRITE(int(Utils::SafeBlock::safeExecuteWithValidation([&](){
		g_pRenderer.getAs<Rendering::Line>(id)->setWidth(width);
	})));
}

void Game::MessageHandler::LineSetPos(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
{
	READ(int, id); 
	READ(int, x1); 
	READ(int, y1); 
	READ(int, x2); 
	READ(int, y2);

	WRITE(int(Utils::SafeBlock::safeExecuteWithValidation([&](){
		g_pRenderer.getAs<Rendering::Line>(id)->setPos(x1, y1, x2, y2);
	})));
}

void Game::MessageHandler::ImageCreate(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
{
	READ(std::string, path); 
	READ(int, x); 
	READ(int, y); 
	READ(int, rotation); 
	READ(int, align); 
	READ(bool, show);
	
	WRITE(g_pRenderer.add(std::make_shared<Rendering::Image>(&g_pRenderer, path.c_str(), x, y, rotation, align, show)));
}

void Game::MessageHandler::ImageDestroy(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
{
	READ(int, id);
	WRITE((int) g_pRenderer.remove(id));
}

void Game::MessageHandler::ImageSetShown(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
{
	READ(int, id); 
	READ(bool, bShow);

	WRITE(int(Utils::SafeBlock::safeExecuteWithValidation([&](){
		g_pRenderer.getAs<Rendering::Image>(id)->setShown(bShow);
	})));
}

void Game::MessageHandler::ImageSetAlign(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
{
	READ(int, id); 
	READ(int, align);

	WRITE(int(Utils::SafeBlock::safeExecuteWithValidation([&](){
		g_pRenderer.getAs<Rendering::Image>(id)->setAlign(align);
	})));
}

void Game::MessageHandler::ImageSetPos(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
{
	READ(int, id); 
	READ(int, x); 
	READ(int, y);

	WRITE(int(Utils::SafeBlock::safeExecuteWithValidation([&](){
		g_pRenderer.getAs<Rendering::Image>(id)->setPos(x, y);
	})));
}

void Game::MessageHandler::ImageSetRotation(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
{
	READ(int, id); 
	READ(int, rotation);

	WRITE(int(Utils::SafeBlock::safeExecuteWithValidation([&](){
		g_pRenderer.getAs<Rendering::Image>(id)->setRotation(rotation);
	})));
}


void Game::MessageHandler::DestroyAllVisual(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
{
	g_pRenderer.destroyAll();
}

void Game::MessageHandler::ShowAllVisual(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
{
	g_pRenderer.showAll();
}

void Game::MessageHandler::HideAllVisual(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
{
	g_pRenderer.hideAll();
}

void Game::MessageHandler::GetFrameRate(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
{
	WRITE(g_pRenderer.frameRate());
}

void Game::MessageHandler::GetScreenSpecs(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
{
	WRITE(g_pRenderer.screenWidth()); 
	WRITE(g_pRenderer.screenHeight());
}

void Game::MessageHandler::SetCalculationRatio(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
{
	READ(int, width);
	READ(int, height);

	Rendering::RenderBase::xCalculator = width;
	Rendering::RenderBase::yCalculator = height;
}

void Game::MessageHandler::SetOverlayPriority(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
{
	READ(int, id);
	READ(int, priority);

	WRITE(int(Utils::SafeBlock::safeExecuteWithValidation([&](){
		g_pRenderer.get(id)->setPriority(priority);
	})));
}

void Game::MessageHandler::SendChat(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
{
	READ(std::string, message);

	WRITE(Game::SAMP::sendChat(message.c_str()));
}

void Game::MessageHandler::ShowGameText(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
{
	READ(std::string, message);
	READ(int, time);
	READ(int, style);

	WRITE(Game::SAMP::showGameText(message.c_str(), time, style));
}

void Game::MessageHandler::AddChatMessage(Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
{
	READ(std::string, message);

	WRITE(Game::SAMP::addChatMessage((std::string("{ffffff}• ") + message).c_str()));
}
