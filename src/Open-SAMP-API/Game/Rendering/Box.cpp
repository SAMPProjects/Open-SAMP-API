#include "Box.hpp"
#include "dx_utils.hpp"

Game::Rendering::Box::Box(Renderer *renderer,  int x, int y, int w, int h, D3DCOLOR color, bool show)
	: RenderBase(renderer), m_bShown(false)
{
	setPos(x, y);
	setBoxWidth(w);
	setBoxHeight(h);
	setBoxColor(color);
	setShown(show);

	setBoxColor(color);
	setBorderWidth(0);
	setBorderShown(false);
}


void Game::Rendering::Box::setPos(int x,int y)
{
	m_iX = x, m_iY = y;
}

void Game::Rendering::Box::setBorderColor(D3DCOLOR dwColor)
{
	m_dwBorderColor = dwColor;
}

void Game::Rendering::Box::setBoxColor(D3DCOLOR dwColor)
{
	m_dwBoxColor = dwColor;
}

void Game::Rendering::Box::setBorderWidth(DWORD dwWidth)
{
	m_dwBorderWidth = dwWidth;
}

void Game::Rendering::Box::setBoxWidth(DWORD dwWidth)
{
	m_dwBoxWidth = dwWidth;
}

void Game::Rendering::Box::setBoxHeight(DWORD dwHeight)
{
	m_dwBoxHeight = dwHeight;
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

	float x = (float)calculatedXPos(m_iX);
	float y = (float)calculatedYPos(m_iY);
	float w = (float)calculatedXPos(m_dwBoxWidth);
	float h = (float)calculatedYPos(m_dwBoxHeight);

	Drawing::DrawBox(x, y, w, h, m_dwBoxColor, pDevice);

	if(m_bBorderShown)
		Drawing::DrawRectangular(x, y, w, h, (float)m_dwBorderWidth, m_dwBorderColor, pDevice);
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