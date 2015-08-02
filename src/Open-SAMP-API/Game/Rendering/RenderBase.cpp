#include "RenderBase.hpp"
#include <Game/GTA/World.hpp>

float Game::Rendering::RenderBase::xCalculator = 800.0;
float Game::Rendering::RenderBase::yCalculator = 600.0;

Game::Rendering::RenderBase::RenderBase(Renderer *renderer)
	: _renderer(renderer), _isMarkedForDeletion(false), _resourceChanged(false), _hasToBeInitialised(true), _firstDrawAfterReset(false)
{
}

Game::Rendering::RenderBase::~RenderBase()
{
}

void Game::Rendering::RenderBase::setPriority(int p)
{
	_priority = p;
}

int Game::Rendering::RenderBase::priority()
{
	return _priority;
}

void Game::Rendering::RenderBase::setCalculationEnabled(bool enabled)
{
	_calculationEnabled = enabled;
}

bool Game::Rendering::RenderBase::isCalculationEnabled()
{
	return _calculationEnabled;
}

void Game::Rendering::RenderBase::setPos2D(float x, float y)
{
	_is3D = false;
	_xPosition = calculatedXPos(x);
	_yPosition = calculatedYPos(y);
}

void Game::Rendering::RenderBase::setPos3D(float x, float y, float z)
{
	_is3D = true;
	_xPosition = x;
	_yPosition = y;
	_zPosition = z;
}

void Game::Rendering::RenderBase::physicalPosition2D(float x, float y, float& xOut, float& yOut)
{
	xOut = calculatedXPos(x);
	yOut = calculatedYPos(y);
}

void Game::Rendering::RenderBase::physicalPosition3D(float x, float y, float z, float& xOut, float& yOut)
{
	if (GTA::WorldToScreen(x, y, z, xOut, yOut))
		return;

	xOut = yOut = 9999.0;
}

void Game::Rendering::RenderBase::changeResource()
{
	_resourceChanged = true;
}

float Game::Rendering::RenderBase::calculatedXPos(float x)
{
	return _calculationEnabled ? (x / xCalculator) * (float)_renderer->screenWidth() : x;
}

float Game::Rendering::RenderBase::calculatedYPos(float y)
{
	return _calculationEnabled ? (y / yCalculator) * (float)_renderer->screenHeight() : y;
}

void Game::Rendering::RenderBase::overlayPosition(float& x, float& y) const
{
	x = _xPosition, y = _yPosition;
	if (!_is3D)
		return;

	float screenX = 0.0, screenY = 0.0;
	if (!GTA::WorldToScreen(_xPosition, _yPosition, _zPosition, screenX, screenY))
		screenX = screenY = 99999.0;

	x = screenX, y = screenY;
}

Game::Rendering::Renderer *Game::Rendering::RenderBase::renderer()
{
	return _renderer;
}
