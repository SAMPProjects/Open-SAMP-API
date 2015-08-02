#include "Box.hpp"
#include "dx_utils.hpp"

Game::Rendering::Box::Box(Renderer *renderer, float x, float y, float w, float h, D3DCOLOR color, bool show) : RenderBase(renderer), m_bShown(false)
{
	setPos2D(x, y);
	setBoxWidth(w);
	setBoxHeight(h);
	setBoxColor(color);
	setShown(show);

	setBoxColor(color);
	setBorderWidth(0);
	setBorderShown(false);
}

void Game::Rendering::Box::setBorderColor(D3DCOLOR dwColor)
{
	m_borderColor = dwColor;
}

void Game::Rendering::Box::setBoxColor(D3DCOLOR dwColor)
{
	m_dwBoxColor = dwColor;
}

void Game::Rendering::Box::setBorderWidth(float width)
{
	m_borderWidth = width;
}

void Game::Rendering::Box::setBoxWidth(float width)
{
	m_boxWidth = width;
}

void Game::Rendering::Box::setBoxHeight(float height)
{
	m_boxHeight = height;
}

void Game::Rendering::Box::setBorderShown(bool b)
{
	m_bBorderShown = b;
}

void Game::Rendering::Box::setShown(bool b)
{
	m_bShown = b;
}

void Game::Rendering::Box::draw(IDirect3DDevice9 *pDevice)
{
	if(!m_bShown)
		return;

	float x = 0.0, y = 0.0;
	overlayPosition(x, y);

	float w = calculatedXPos(m_boxWidth);
	float h = calculatedYPos(m_boxHeight);

	Drawing::DrawBox(x, y, w, h, m_dwBoxColor, pDevice);

	if(m_bBorderShown)
		Drawing::DrawRectangular(x, y, w, h, m_borderWidth, m_borderColor, pDevice);
}

void Game::Rendering::Box::reset(IDirect3DDevice9 *pDevice)
{
	
}

void Game::Rendering::Box::show()
{
	setShown(true);
}

void Game::Rendering::Box::hide()
{
	setShown(false);
}

void Game::Rendering::Box::releaseResourcesForDeletion(IDirect3DDevice9 *pDevice)
{
	m_bShown = false;
	m_bBorderShown = false;
}

bool Game::Rendering::Box::canBeDeleted()
{
	return true;
}

bool Game::Rendering::Box::loadResource(IDirect3DDevice9 *pDevice)
{
	return true;
}

void Game::Rendering::Box::firstDrawAfterReset(IDirect3DDevice9 *pDevice)
{
	
}