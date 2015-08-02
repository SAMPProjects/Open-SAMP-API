#pragma once
#include "RenderBase.hpp"

namespace Game
{
	namespace Rendering
	{
		class Box : public RenderBase
		{
		public:
			Box(Renderer *renderer, float x, float y, float w, float h, D3DCOLOR color, bool show);

			void setBorderColor(D3DCOLOR dwColor);
			void setBoxColor(D3DCOLOR dwColor);
			void setBorderWidth(float width);
			void setBoxWidth(float width);
			void setBoxHeight(float height);
			void setBorderShown(bool b);
			void setShown(bool b);

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
			bool m_bShown, m_bBorderShown;
			D3DCOLOR m_dwBoxColor, m_borderColor;
			float m_borderWidth = 0.0, m_boxWidth = 0.0, m_boxHeight = 0.0;
		};
	}
}
