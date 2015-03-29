#include "RenderBase.hpp"

int Game::Rendering::RenderBase::xCalculator = 800;
int Game::Rendering::RenderBase::yCalculator = 600;

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

void Game::Rendering::RenderBase::changeResource()
{
	_resourceChanged = true;
}

int Game::Rendering::RenderBase::calculatedXPos(int x)
{
	return (int)(((float)x / (float)xCalculator) * (float)_renderer->screenWidth());
}

int Game::Rendering::RenderBase::calculatedYPos(int y)
{
	return (int)(((float)y / (float)yCalculator) * (float)_renderer->screenHeight());
}

Game::Rendering::Renderer *Game::Rendering::RenderBase::renderer()
{
	return _renderer;
}


