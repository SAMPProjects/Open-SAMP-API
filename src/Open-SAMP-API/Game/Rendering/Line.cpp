#include "Line.hpp"

Game::Rendering::Line::Line(Renderer *renderer, int x1,int y1,int x2,int y2,int width,D3DCOLOR color, bool bShow)
	: RenderBase(renderer), m_Line(NULL)
{
	setPos(x1,y1,x2,y2);
	setWidth(width);
	setColor(color);
	setShown(bShow);
}

void Game::Rendering::Line::setPos(int x1,int y1,int x2,int y2)
{
	m_X1 = x1, m_X2 = x2;
	m_Y1 = y1, m_Y2 = y2;
}

void Game::Rendering::Line::setWidth(int width)
{
	m_Width = width;
}

void Game::Rendering::Line::setColor(D3DCOLOR color)
{
	m_Color = color;
}

void Game::Rendering::Line::setShown(bool show)
{
	m_bShow = show;
}

void Game::Rendering::Line::draw(IDirect3DDevice9 *pDevice)
{
	if(!m_bShow || m_Line == NULL)
		return;

	D3DXVECTOR2	LinePos[2];

	m_Line->SetAntialias(TRUE);
	m_Line->SetWidth((FLOAT)m_Width);

	m_Line->Begin();

	LinePos[0].x = (float)calculatedXPos(m_X1);
	LinePos[0].y = (float)calculatedYPos(m_Y1);
	LinePos[1].x = (float)calculatedXPos(m_X2);
	LinePos[1].y = (float)calculatedYPos(m_Y2);

	m_Line->Draw(LinePos,2,m_Color);
	m_Line->End();	
}

void Game::Rendering::Line::reset(IDirect3DDevice9 *pDevice)
{
	if(m_Line)
	{
		m_Line->OnLostDevice();
		m_Line->OnResetDevice();
	}
}

void Game::Rendering::Line::show()
{
	setShown(true);
}

void Game::Rendering::Line::hide()
{
	setShown(false);
}

void Game::Rendering::Line::releaseResourcesForDeletion(IDirect3DDevice9 *pDevice)
{
	if(m_Line)
	{
		m_Line->Release();
		m_Line = NULL;
	}
}

bool Game::Rendering::Line::canBeDeleted()
{
	return (m_Line == NULL) ? true : false;
}

bool Game::Rendering::Line::loadResource(IDirect3DDevice9 *pDevice)
{
	if(m_Line)
	{
		m_Line->Release();
		m_Line = NULL;
	}

	D3DXCreateLine(pDevice,&m_Line);

	return m_Line != NULL;
}

void Game::Rendering::Line::firstDrawAfterReset(IDirect3DDevice9 *pDevice)
{

}