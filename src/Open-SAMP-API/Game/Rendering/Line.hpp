#pragma once
#include "RenderBase.hpp"

namespace Game
{
	namespace Rendering
	{
		class Line : public RenderBase
		{
		public:
			Line(Renderer *renderer, float x1, float y1, float x2, float y2, float width, D3DCOLOR color, bool bShow);

			void setPos(float x1, float y1, float x2, float y2);
			void setWidth(float width);
			void setColor(D3DCOLOR color);
			void setShown(bool show);

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
			float m_X2 = 0.0, m_Y2 = 0.0, m_Width;

			bool m_bShow;

			D3DCOLOR m_Color;

			LPD3DXLINE m_Line;
		};
	}
}
