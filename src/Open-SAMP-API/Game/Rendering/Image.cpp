#include "Image.hpp"
#include "dx_utils.hpp"

Game::Rendering::Image::Image(Renderer *renderer, const std::string& file_path, float x, float y, float rotation, int align, bool bShow) : RenderBase(renderer), m_pSprite(NULL), m_pTexture(NULL)
{
	setFilePath(file_path);
	setPos2D(x, y);
	setRotation(rotation);
	setAlign(align);
	setShown(bShow);
}

void Game::Rendering::Image::setFilePath(const std::string & path)
{
	m_filePath = path;
}

void Game::Rendering::Image::setRotation(float rotation)
{
	m_rotation = rotation;
}

void Game::Rendering::Image::setAlign(int align)
{
	m_align = align;
}

void Game::Rendering::Image::setShown(bool show)
{
	m_bShow = show;
}

bool Game::Rendering::Image::updateImage(const std::string& file_path, float x, float y, float rotation, int align, bool bShow)
{
	setFilePath(file_path);
	setPos2D(x, y);
	setRotation(rotation);
	setAlign(align);
	setShown(bShow);

	changeResource();

	return true;
}

void Game::Rendering::Image::draw(IDirect3DDevice9 *pDevice)
{
	if(!m_bShow)
		return;

	float x = 0, y = 0;
	overlayPosition(x, y);

	if(m_pTexture && m_pSprite)
		Drawing::DrawSprite(m_pSprite, m_pTexture, x, y, m_rotation, m_align);
}

void Game::Rendering::Image::reset(IDirect3DDevice9 *pDevice)
{
	if(m_pSprite)
	{
		m_pSprite->OnLostDevice();
		m_pSprite->OnResetDevice();
	}
}


void Game::Rendering::Image::show()
{
	setShown(true);
}

void Game::Rendering::Image::hide()
{
	setShown(false);
}

void Game::Rendering::Image::releaseResourcesForDeletion(IDirect3DDevice9 *pDevice)
{
	if(m_pSprite)
	{
		m_pSprite->Release();
		m_pSprite = NULL;
	}

	if(m_pTexture)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}
}

bool Game::Rendering::Image::canBeDeleted()
{
	return (m_pTexture == NULL && m_pSprite == NULL);
}

bool Game::Rendering::Image::loadResource(IDirect3DDevice9 *pDevice)
{
	if(m_pSprite)
	{
		m_pSprite->Release();
		m_pSprite = NULL;
	}

	if(m_pTexture)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}

	D3DXCreateTextureFromFileA(pDevice, m_filePath.c_str(), &m_pTexture);
	D3DXCreateSprite(pDevice, &m_pSprite);

	return (m_pTexture != NULL && m_pSprite != NULL);
}

void Game::Rendering::Image::firstDrawAfterReset(IDirect3DDevice9 *pDevice)
{

}