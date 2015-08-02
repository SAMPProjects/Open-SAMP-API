#pragma once
#include "RenderBase.hpp"

namespace Game
{
	namespace Rendering
	{
		class Image : public RenderBase
		{
		public:
			static void DrawSprite(LPD3DXSPRITE SpriteInterface, LPDIRECT3DTEXTURE9 TextureInterface, int PosX, int PosY, int Rotation, int Align);

			Image(Renderer *renderer, const std::string& file_path, float x, float y, float rotation, int align, bool bShow);

			void setFilePath(const std::string & path);
			void setRotation(float rotation);
			void setAlign(int align);
			void setShown(bool show);
			bool updateImage(const std::string& file_path, float x, float y, float rotation, int align, bool bShow);

		protected:
			virtual void draw(IDirect3DDevice9 *pDevice) sealed;
			virtual void reset(IDirect3DDevice9 *pDevice) sealed;

			virtual void show() sealed;
			virtual void hide() sealed;

			virtual void releaseResourcesForDeletion(IDirect3DDevice9 *pDevice) sealed;
			virtual bool canBeDeleted() sealed;

			virtual bool loadResource(IDirect3DDevice9 *pDevice) override sealed;
			virtual void firstDrawAfterReset(IDirect3DDevice9 *pDevice) override sealed;

		private:
			std::string m_filePath;

			float m_rotation;
			int m_align;
			bool m_bShow;

			LPDIRECT3DTEXTURE9 m_pTexture;
			LPD3DXSPRITE m_pSprite;
		};
	}
}
