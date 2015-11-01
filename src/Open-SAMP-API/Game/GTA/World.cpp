#include "World.hpp"
#include <Utils/D3DX9/d3dx9.h>
#include <Game/Rendering/RenderBase.hpp>

void CalcScreenCoors(D3DXVECTOR3 *vecWorld, D3DXVECTOR3 *vecScreen)
{
	D3DXMATRIX m((float *)(0xB6FA2C));

	DWORD *dwLenX = (DWORD *)(0xC17044);
	DWORD *dwLenY = (DWORD *)(0xC17048);

	vecScreen->x = (vecWorld->z * m._31) + (vecWorld->y * m._21) + (vecWorld->x * m._11) + m._41;
	vecScreen->y = (vecWorld->z * m._32) + (vecWorld->y * m._22) + (vecWorld->x * m._12) + m._42;
	vecScreen->z = (vecWorld->z * m._33) + (vecWorld->y * m._23) + (vecWorld->x * m._13) + m._43;

	double fRecip = (double) 1.0 / vecScreen->z;
	vecScreen->x *= (float)(fRecip * (*dwLenX));
	vecScreen->y *= (float)(fRecip * (*dwLenY));
}

void CalcWorldCoors(D3DXVECTOR3 *vecScreen, D3DXVECTOR3 *vecWorld)
{
	D3DXMATRIX m((float *)(0xB6FA2C));

	D3DXMATRIX minv;
	memset(&minv, 0, sizeof(D3DXMATRIX));
	m._44 = 1.0f;
	D3DXMatrixInverse(&minv, NULL, &m);

	DWORD *dwLenX = (DWORD *)(0xC17044);
	DWORD *dwLenY = (DWORD *)(0xC17048);

	double fRecip = (double)1.0 / vecScreen->z;
	vecScreen->x /= (float)(fRecip * (*dwLenX));
	vecScreen->y /= (float)(fRecip * (*dwLenY));

	vecWorld->x = (vecScreen->z * minv._31) + (vecScreen->y * minv._21) + (vecScreen->x * minv._11) + minv._41;
	vecWorld->y = (vecScreen->z * minv._32) + (vecScreen->y * minv._22) + (vecScreen->x * minv._12) + minv._42;
	vecWorld->z = (vecScreen->z * minv._33) + (vecScreen->y * minv._23) + (vecScreen->x * minv._13) + minv._43;
}

bool Game::GTA::ScreenToWorld(float screenX, float screenY, float &worldX, float &worldY, float &worldZ)
{
	D3DXVECTOR3 vecScreen(screenX, screenY, 700.0f), vecWorld;

	CalcWorldCoors(&vecScreen, &vecWorld);

	worldX = vecWorld.x;
	worldY = vecWorld.y;
	worldZ = vecWorld.z;

	return true;
}

bool Game::GTA::WorldToScreen(float x, float y, float z, float &screenX, float &screenY)
{
	D3DXVECTOR3 vecScreen, vecWorld(x, y, z);

	CalcScreenCoors(&vecWorld, &vecScreen);

	screenX = vecScreen.x;
	screenY = vecScreen.y;

	if (vecScreen.z > 1.0f)
		return true;

	return false;
}

