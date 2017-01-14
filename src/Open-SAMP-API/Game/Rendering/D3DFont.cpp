//-----------------------------------------------------------------------------
// File: D3DFont.cpp
//
// Desc: Texture-based font class
//
// Copyright (c)  Microsoft Corporation. All rights reserved.
//-----------------------------------------------------------------------------
#define STRICT
#include <stdio.h>
#include <tchar.h>
#include <Utils/D3DX9/d3dx9.h>
#include "D3DFont.hpp"

#include <vector>

#define SAFE_RELEASE( p ) if( p ){ p->Release(); p = NULL; }


//-----------------------------------------------------------------------------
// Custom vertex types for rendering text
//-----------------------------------------------------------------------------
#define MAX_NUM_VERTICES 50*6

struct FONT2DVERTEX { D3DXVECTOR4 p;   DWORD color;     FLOAT tu, tv; };
struct FONT3DVERTEX { D3DXVECTOR3 p;   D3DXVECTOR3 n;   FLOAT tu, tv; };

#define D3DFVF_FONT2DVERTEX (D3DFVF_XYZRHW|D3DFVF_DIFFUSE|D3DFVF_TEX1)
#define D3DFVF_FONT3DVERTEX (D3DFVF_XYZ|D3DFVF_NORMAL|D3DFVF_TEX1)

inline FONT2DVERTEX InitFont2DVertex(const D3DXVECTOR4& p, D3DCOLOR color,
	FLOAT tu, FLOAT tv)
{
	FONT2DVERTEX v;   v.p = p;   v.color = color;   v.tu = tu;   v.tv = tv;
	return v;
}

inline FONT3DVERTEX InitFont3DVertex(const D3DXVECTOR3& p, const D3DXVECTOR3& n,
	FLOAT tu, FLOAT tv)
{
	FONT3DVERTEX v;   v.p = p;   v.n = n;   v.tu = tu;   v.tv = tv;
	return v;
}




//-----------------------------------------------------------------------------
// Name: CD3DFont()
// Desc: Font class constructor
//-----------------------------------------------------------------------------
CD3DFont::CD3DFont(const TCHAR* strFontName, DWORD dwHeight, DWORD dwFlags)
{
	_tcsncpy_s(m_strFontName, strFontName, sizeof(m_strFontName) / sizeof(TCHAR));
	m_strFontName[sizeof(m_strFontName) / sizeof(TCHAR) -1] = _T('\0');
	m_dwFontHeight = dwHeight;
	m_dwFontFlags = dwFlags;
	m_dwSpacing = 0;

	m_pd3dDevice = NULL;
	m_pTexture = NULL;
	m_pVB = NULL;

	m_pStateBlockSaved = NULL;
	m_pStateBlockDrawText = NULL;
}




//-----------------------------------------------------------------------------
// Name: ~CD3DFont()
// Desc: Font class destructor
//-----------------------------------------------------------------------------
CD3DFont::~CD3DFont()
{
	InvalidateDeviceObjects();
	DeleteDeviceObjects();
}




//-----------------------------------------------------------------------------
// Name: InitDeviceObjects()
// Desc: Initializes device-dependent objects, including the vertex buffer used
//       for rendering text and the texture map which stores the font image.
//-----------------------------------------------------------------------------
HRESULT CD3DFont::InitDeviceObjects(LPDIRECT3DDEVICE9 pd3dDevice)
{
	HRESULT hr;

	// Keep a local copy of the device
	m_pd3dDevice = pd3dDevice;

	// Establish the font and texture size
	m_fTextScale = 1.0f; // Draw fonts into texture without scaling

	// Large fonts need larger textures
	/*if (m_dwFontHeight > 60)
		m_dwTexWidth = m_dwTexHeight = 2048;
	else if (m_dwFontHeight > 30)
		m_dwTexWidth = m_dwTexHeight = 1024;
	else if (m_dwFontHeight > 15)
		m_dwTexWidth = m_dwTexHeight = 512;
	else
		m_dwTexWidth = m_dwTexHeight = 256;*/

	// Dynamic size
	m_dwTexWidth = m_dwTexHeight = (m_dwFontHeight * 30);


	// If requested texture is too big, use a smaller texture and smaller font,
	// and scale up when rendering.
	D3DCAPS9 d3dCaps;
	m_pd3dDevice->GetDeviceCaps(&d3dCaps);

	if (m_dwTexWidth > d3dCaps.MaxTextureWidth)
	{
		m_fTextScale = (FLOAT) d3dCaps.MaxTextureWidth / (FLOAT) m_dwTexWidth;
		m_dwTexWidth = m_dwTexHeight = d3dCaps.MaxTextureWidth;
	}

	// Create a new texture for the font
	hr = m_pd3dDevice->CreateTexture(m_dwTexWidth, m_dwTexHeight, 1,
		0, D3DFMT_A4R4G4B4,
		D3DPOOL_MANAGED, &m_pTexture, NULL);
	if (FAILED(hr))
		return hr;

	// Prepare to create a bitmap
	DWORD*      pBitmapBits;
	BITMAPINFO bmi;
	ZeroMemory(&bmi.bmiHeader, sizeof(BITMAPINFOHEADER));
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmi.bmiHeader.biWidth = (int) m_dwTexWidth;
	bmi.bmiHeader.biHeight = -(int) m_dwTexHeight;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biCompression = BI_RGB;
	bmi.bmiHeader.biBitCount = 32;

	// Create a DC and a bitmap for the font
	HDC     hDC = CreateCompatibleDC(NULL);
	HBITMAP hbmBitmap = CreateDIBSection(hDC, &bmi, DIB_RGB_COLORS,
		(void**) &pBitmapBits, NULL, 0);
	SetMapMode(hDC, MM_TEXT);

	// Create a font.  By specifying ANTIALIASED_QUALITY, we might get an
	// antialiased font, but this is not guaranteed.
	INT nHeight = -MulDiv(m_dwFontHeight,
		(INT) (GetDeviceCaps(hDC, LOGPIXELSY) * m_fTextScale), 72);
	DWORD dwBold = (m_dwFontFlags&D3DFONT_BOLD) ? FW_BOLD : FW_NORMAL;
	DWORD dwItalic = (m_dwFontFlags&D3DFONT_ITALIC) ? TRUE : FALSE;
	HFONT hFont = CreateFont(nHeight, 0, 0, 0, dwBold, dwItalic,
		FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY,
		VARIABLE_PITCH, m_strFontName);
	if (NULL == hFont)
		return E_FAIL;

	SelectObject(hDC, hbmBitmap);
	SelectObject(hDC, hFont);

	// Set text properties
	SetTextColor(hDC, RGB(255, 255, 255));
	SetBkColor(hDC, 0x00000000);
	SetTextAlign(hDC, TA_TOP);

	// Loop through all printable character and output them to the bitmap..
	// Meanwhile, keep track of the corresponding tex coords for each character.
	DWORD x = 0;
	DWORD y = 0;
	WCHAR str[2] = { L'x', L'\0' };
	SIZE size;

	// Calculate the spacing between characters based on line height
	GetTextExtentPoint32(hDC, TEXT(" "), 1, &size);
	x = m_dwSpacing = (DWORD) ceil(size.cy * 0.3f);

	for (wchar_t c = 32; c < 255; c++)
	{
		str[0] = c;

		GetTextExtentPoint32W(hDC, str, 1, &size);


		if ((DWORD)(x + size.cx + m_dwSpacing) > m_dwTexWidth)
		{
			x = m_dwSpacing;
			y += size.cy + 1;
		}

		ExtTextOutW(hDC, x + 0, y + 0, ETO_OPAQUE, NULL, str, 1, NULL);

		m_fTexCoords[c - 32][0] = ((FLOAT)(x + 0 - m_dwSpacing)) / m_dwTexWidth;
		m_fTexCoords[c - 32][1] = ((FLOAT)(y + 0 + 0)) / m_dwTexHeight;
		m_fTexCoords[c - 32][2] = ((FLOAT)(x + size.cx + m_dwSpacing)) / m_dwTexWidth;
		m_fTexCoords[c - 32][3] = ((FLOAT)(y + size.cy + 0)) / m_dwTexHeight;

		x += size.cx + (2 * m_dwSpacing);
	}

	// Lock the surface and write the alpha values for the set pixels
	D3DLOCKED_RECT d3dlr;
	m_pTexture->LockRect(0, &d3dlr, 0, 0);
	BYTE* pDstRow = (BYTE*) d3dlr.pBits;
	WORD* pDst16;
	BYTE bAlpha; // 4-bit measure of pixel intensity

	for (y = 0; y < m_dwTexHeight; y++)
	{
		pDst16 = (WORD*) pDstRow;
		for (x = 0; x < m_dwTexWidth; x++)
		{
			bAlpha = (BYTE) ((pBitmapBits[m_dwTexWidth*y + x] & 0xff) >> 4);
			if (bAlpha > 0)
			{
				*pDst16++ = (WORD) ((bAlpha << 12) | 0x0fff);
			}
			else
			{
				*pDst16++ = 0x0000;
			}
		}
		pDstRow += d3dlr.Pitch;
	}

	// Done updating texture, so clean up used objects
	m_pTexture->UnlockRect(0);
	DeleteObject(hbmBitmap);
	DeleteDC(hDC);
	DeleteObject(hFont);

	return S_OK;
}




//-----------------------------------------------------------------------------
// Name: RestoreDeviceObjects()
// Desc:
//-----------------------------------------------------------------------------
HRESULT CD3DFont::RestoreDeviceObjects()
{
	HRESULT hr;

	// Create vertex buffer for the letters
	int vertexSize = max(sizeof(FONT2DVERTEX), sizeof(FONT3DVERTEX));
	if (FAILED(hr = m_pd3dDevice->CreateVertexBuffer(MAX_NUM_VERTICES * vertexSize,
		D3DUSAGE_WRITEONLY | D3DUSAGE_DYNAMIC, 0,
		D3DPOOL_DEFAULT, &m_pVB, NULL)))
	{
		return hr;
	}

	// Create the state blocks for rendering text
	for (UINT which = 0; which < 2; which++)
	{
		m_pd3dDevice->BeginStateBlock();
		m_pd3dDevice->SetTexture(0, m_pTexture);

		if (D3DFONT_ZENABLE & m_dwFontFlags)
			m_pd3dDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
		else
			m_pd3dDevice->SetRenderState(D3DRS_ZENABLE, FALSE);

		m_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
		m_pd3dDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
		m_pd3dDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
		m_pd3dDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
		m_pd3dDevice->SetRenderState(D3DRS_ALPHAREF, 0x08);
		m_pd3dDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATEREQUAL);
		m_pd3dDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
		m_pd3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);
		m_pd3dDevice->SetRenderState(D3DRS_STENCILENABLE, FALSE);
		m_pd3dDevice->SetRenderState(D3DRS_CLIPPING, TRUE);
		m_pd3dDevice->SetRenderState(D3DRS_CLIPPLANEENABLE, FALSE);
		m_pd3dDevice->SetRenderState(D3DRS_VERTEXBLEND, D3DVBF_DISABLE);
		m_pd3dDevice->SetRenderState(D3DRS_INDEXEDVERTEXBLENDENABLE, FALSE);
		m_pd3dDevice->SetRenderState(D3DRS_FOGENABLE, FALSE);
		m_pd3dDevice->SetRenderState(D3DRS_COLORWRITEENABLE,
			D3DCOLORWRITEENABLE_RED | D3DCOLORWRITEENABLE_GREEN |
			D3DCOLORWRITEENABLE_BLUE | D3DCOLORWRITEENABLE_ALPHA);
		m_pd3dDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
		m_pd3dDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
		m_pd3dDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
		m_pd3dDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
		m_pd3dDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
		m_pd3dDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);
		m_pd3dDevice->SetTextureStageState(0, D3DTSS_TEXCOORDINDEX, 0);
		m_pd3dDevice->SetTextureStageState(0, D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_DISABLE);
		m_pd3dDevice->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_DISABLE);
		m_pd3dDevice->SetTextureStageState(1, D3DTSS_ALPHAOP, D3DTOP_DISABLE);
		m_pd3dDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_POINT);
		m_pd3dDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_POINT);
		m_pd3dDevice->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_NONE);

		if (which == 0)
			m_pd3dDevice->EndStateBlock(&m_pStateBlockSaved);
		else
			m_pd3dDevice->EndStateBlock(&m_pStateBlockDrawText);
	}

	return S_OK;
}




//-----------------------------------------------------------------------------
// Name: InvalidateDeviceObjects()
// Desc: Destroys all device-dependent objects
//-----------------------------------------------------------------------------
HRESULT CD3DFont::InvalidateDeviceObjects()
{
	SAFE_RELEASE(m_pVB);
	SAFE_RELEASE(m_pStateBlockSaved);
	SAFE_RELEASE(m_pStateBlockDrawText);

	return S_OK;
}




//-----------------------------------------------------------------------------
// Name: DeleteDeviceObjects()
// Desc: Destroys all device-dependent objects
//-----------------------------------------------------------------------------
HRESULT CD3DFont::DeleteDeviceObjects()
{
	SAFE_RELEASE(m_pTexture);
	m_pd3dDevice = NULL;

	return S_OK;
}




//-----------------------------------------------------------------------------
// Name: GetTextExtent()
// Desc: Get the dimensions of a text string
//-----------------------------------------------------------------------------
HRESULT CD3DFont::GetTextExtent(const WCHAR* strText, SIZE* pSize)
{
	if (NULL == strText || NULL == pSize)
		return E_FAIL;

	float rowWidth = 0.0f;
	float rowHeight = (m_fTexCoords[0][3] - m_fTexCoords[0][1]) * m_dwTexHeight;
	float width = 0.0f;
	float height = rowHeight;

	auto stringLength = lstrlenW(strText);

	for (int i = 0; i < stringLength; i++)
	{
		wchar_t c = strText[i];

		// TODO 
		if (c == L'{')
		{
			int endIndex = 0;
			bool valid = true;
			std::wstring numericString = L"";
			for (int j = i + 1; j < stringLength; j++)
			{
				wchar_t ch = strText[j];
				ch = towupper(ch);

				if (ch == '}')
				{
					endIndex = j;
					break;
				}

				bool numeric = (ch >= L'0' && ch <= L'9') || (ch >= L'A' && ch <= L'F');
				if (!numeric)
				{
					valid = false;
					break;
				}
				else
				{
					numericString += ch;
					if (numericString.size() > 8)
					{
						valid = false;
						break;
					}
				}
			}

			if (endIndex > 0 && valid)
			{
				i = endIndex;
				continue;
			}
		}

		if (c == '\n')
		{
			rowWidth = 0.0f;
			height += rowHeight;
		}

		if ((c - 32) < 0 || (c - 32) >= 256 - 32)
		{
			continue;
		}

		FLOAT tx1 = m_fTexCoords[c - 32][0];
		FLOAT tx2 = m_fTexCoords[c - 32][2];

		rowWidth += (tx2 - tx1) * m_dwTexWidth - 2 * m_dwSpacing;

		if (rowWidth > width)
			width = rowWidth;
	}

	pSize->cx = (int)width;
	pSize->cy = (int)height;

	return S_OK;
}




//-----------------------------------------------------------------------------
// Name: DrawText()
// Desc: Draws 2D text. Note that sx and sy are in pixels
//-----------------------------------------------------------------------------
HRESULT CD3DFont::DrawText(FLOAT sx, FLOAT sy, DWORD dwColor,
	const WCHAR* strText, DWORD dwFlags)
{
	if (m_pd3dDevice == NULL || strText == NULL)
		return E_FAIL;

	// Setup renderstate
	m_pStateBlockSaved->Capture();
	m_pStateBlockDrawText->Apply();
	m_pd3dDevice->SetFVF(D3DFVF_FONT2DVERTEX);
	m_pd3dDevice->SetPixelShader(NULL);
	m_pd3dDevice->SetStreamSource(0, m_pVB, 0, sizeof(FONT2DVERTEX));

	if (dwFlags & D3DFONT_FILTERED)
	{
		m_pd3dDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
		m_pd3dDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
	}

	// Center the text block in the viewport
	if (dwFlags & D3DFONT_CENTERED_X)
	{
		SIZE size;
		GetTextExtent(strText, &size);
		sx -= (float)size.cx / 2.0f;
	}
	if (dwFlags & D3DFONT_CENTERED_Y)
	{
		SIZE size;
		GetTextExtent(strText, &size);
		sy -= (float)size.cy / 2.0f;
	}

	// Adjust for character spacing
	sx -= m_dwSpacing;
	float startX = sx;

	// Fill vertex buffer
	FONT2DVERTEX* vertices = NULL;
	int trianglesCount = 0;
	m_pVB->Lock(0, 0, (void**)&vertices, D3DLOCK_DISCARD);

	auto stringLength = lstrlenW(strText);
	DWORD customColor = dwColor;

	for (int i = 0; i < stringLength; i++)
	{
		wchar_t c = strText[i];

		if (c == L'{')
		{
			int endIndex = 0;
			bool valid = true;
			std::wstring numericString = L"";
			for (int j = i + 1; j < stringLength; j++)
			{
				wchar_t ch = strText[j];
				ch = towupper(ch);

				if (ch == '}')
				{
					endIndex = j;
					break;
				}

				bool numeric = (ch >= L'0' && ch <= L'9') || (ch >= L'A' && ch <= L'F');
				if (!numeric)
				{
					valid = false;
					break;
				}
				else
				{
					numericString += ch;
					if (numericString.size() > 8)
					{
						valid = false;
						break;
					}
				}
			}

			if (endIndex > 0 && valid)
			{
				swscanf_s(numericString.data(), L"%X", &customColor);
				customColor |= (dwColor >> 24) << 24;
				i = endIndex;
				continue;
			}
		}


		if (c == '\n')
		{
			sx = startX;
			sy += (m_fTexCoords[0][3] - m_fTexCoords[0][1]) * m_dwTexHeight;
		}

		if ((c - 32) < 0 || (c - 32) >= 256 - 32)
			continue;

		float tx1 = m_fTexCoords[c - 32][0];
		float ty1 = m_fTexCoords[c - 32][1];
		float tx2 = m_fTexCoords[c - 32][2];
		float ty2 = m_fTexCoords[c - 32][3];

		float w = (tx2 - tx1) * m_dwTexWidth / m_fTextScale;
		float h = (ty2 - ty1) * m_dwTexHeight / m_fTextScale;

		if (c != ' ')
		{
			if (dwFlags & D3DFONT_COLORTABLE)
				dwColor = customColor;

			if (dwFlags & D3DFONT_BORDER)
			{
				float _x = sx, _y = sy;
				float addy = 1.0f;
				float fHeight = h, fWidth = w;

				DWORD dwShadow = 0xFF000000;

				_x = sx - addy, _y = sy - addy;
				*vertices++ = InitFont2DVertex(D3DXVECTOR4(_x, _y + fHeight, 0.0f, 0.0f), dwShadow, tx1, ty2);
				*vertices++ = InitFont2DVertex(D3DXVECTOR4(_x, _y, 0.0f, 0.0f), dwShadow, tx1, ty1);
				*vertices++ = InitFont2DVertex(D3DXVECTOR4(_x + fWidth, _y + fHeight, 0.0f, 0.0f), dwShadow, tx2, ty2);
				*vertices++ = InitFont2DVertex(D3DXVECTOR4(_x + fWidth, _y, 0.0f, 0.0f), dwShadow, tx2, ty1);
				*vertices++ = InitFont2DVertex(D3DXVECTOR4(_x + fWidth, _y + fHeight, 0.0f, 0.0f), dwShadow, tx2, ty2);
				*vertices++ = InitFont2DVertex(D3DXVECTOR4(_x, _y, 0.0f, 0.0f), dwShadow, tx1, ty1);


				_x = sx + addy, _y = sy + addy;
				*vertices++ = InitFont2DVertex(D3DXVECTOR4(_x, _y + fHeight, 0.0f, 0.0f), dwShadow, tx1, ty2);
				*vertices++ = InitFont2DVertex(D3DXVECTOR4(_x, _y, 0.0f, 0.0f), dwShadow, tx1, ty1);
				*vertices++ = InitFont2DVertex(D3DXVECTOR4(_x + fWidth, _y + fHeight, 0.0f, 0.0f), dwShadow, tx2, ty2);
				*vertices++ = InitFont2DVertex(D3DXVECTOR4(_x + fWidth, _y, 0.0f, 0.0f), dwShadow, tx2, ty1);
				*vertices++ = InitFont2DVertex(D3DXVECTOR4(_x + fWidth, _y + fHeight, 0.0f, 0.0f), dwShadow, tx2, ty2);
				*vertices++ = InitFont2DVertex(D3DXVECTOR4(_x, _y, 0.0f, 0.0f), dwShadow, tx1, ty1);

				_x = sx - addy, _y = sy + addy;
				*vertices++ = InitFont2DVertex(D3DXVECTOR4(_x, _y + fHeight, 0.0f, 0.0f), dwShadow, tx1, ty2);
				*vertices++ = InitFont2DVertex(D3DXVECTOR4(_x, _y, 0.0f, 0.0f), dwShadow, tx1, ty1);
				*vertices++ = InitFont2DVertex(D3DXVECTOR4(_x + fWidth, _y + fHeight, 0.0f, 0.0f), dwShadow, tx2, ty2);
				*vertices++ = InitFont2DVertex(D3DXVECTOR4(_x + fWidth, _y, 0.0f, 0.0f), dwShadow, tx2, ty1);
				*vertices++ = InitFont2DVertex(D3DXVECTOR4(_x + fWidth, _y + fHeight, 0.0f, 0.0f), dwShadow, tx2, ty2);
				*vertices++ = InitFont2DVertex(D3DXVECTOR4(_x, _y, 0.0f, 0.0f), dwShadow, tx1, ty1);

				_x = sx + addy, _y = sy - addy;
				*vertices++ = InitFont2DVertex(D3DXVECTOR4(_x, _y + fHeight, 0.0f, 0.0f), dwShadow, tx1, ty2);
				*vertices++ = InitFont2DVertex(D3DXVECTOR4(_x, _y, 0.0f, 0.0f), dwShadow, tx1, ty1);
				*vertices++ = InitFont2DVertex(D3DXVECTOR4(_x + fWidth, _y + fHeight, 0.0f, 0.0f), dwShadow, tx2, ty2);
				*vertices++ = InitFont2DVertex(D3DXVECTOR4(_x + fWidth, _y, 0.0f, 0.0f), dwShadow, tx2, ty1);
				*vertices++ = InitFont2DVertex(D3DXVECTOR4(_x + fWidth, _y + fHeight, 0.0f, 0.0f), dwShadow, tx2, ty2);
				*vertices++ = InitFont2DVertex(D3DXVECTOR4(_x, _y, 0.0f, 0.0f), dwShadow, tx1, ty1);


				trianglesCount += 8;
			}

			*vertices++ = InitFont2DVertex(D3DXVECTOR4(sx + 0 - 0.5f, sy + h - 0.5f, 0.9f, 1.0f), dwColor, tx1, ty2);
			*vertices++ = InitFont2DVertex(D3DXVECTOR4(sx + 0 - 0.5f, sy + 0 - 0.5f, 0.9f, 1.0f), dwColor, tx1, ty1);
			*vertices++ = InitFont2DVertex(D3DXVECTOR4(sx + w - 0.5f, sy + h - 0.5f, 0.9f, 1.0f), dwColor, tx2, ty2);
			*vertices++ = InitFont2DVertex(D3DXVECTOR4(sx + w - 0.5f, sy + 0 - 0.5f, 0.9f, 1.0f), dwColor, tx2, ty1);
			*vertices++ = InitFont2DVertex(D3DXVECTOR4(sx + w - 0.5f, sy + h - 0.5f, 0.9f, 1.0f), dwColor, tx2, ty2);
			*vertices++ = InitFont2DVertex(D3DXVECTOR4(sx + 0 - 0.5f, sy + 0 - 0.5f, 0.9f, 1.0f), dwColor, tx1, ty1);
			trianglesCount += 2;

			if (trianglesCount * 3 > (MAX_NUM_VERTICES - 6))
			{
				// Unlock, render, and relock the vertex buffer
				m_pVB->Unlock();
				m_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, trianglesCount);
				vertices = NULL;
				m_pVB->Lock(0, 0, (void**)&vertices, D3DLOCK_DISCARD);
				trianglesCount = 0L;
			}
		}

		sx += w - (2 * m_dwSpacing);
	}

	// Unlock and render the vertex buffer
	m_pVB->Unlock();
	if (trianglesCount > 0)
		m_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, trianglesCount);

	// Restore the modified renderstates
	m_pStateBlockSaved->Apply();

	return S_OK;
}
