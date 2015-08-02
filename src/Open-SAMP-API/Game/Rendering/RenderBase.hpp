#pragma once
#include "Renderer.hpp"

namespace Game
{
	namespace Rendering
	{
		class RenderBase
		{
			friend class Renderer;
		public:
			static float xCalculator;
			static float yCalculator;

			RenderBase(Renderer *render);
			virtual ~RenderBase(void);

			void setPriority(int p);
			int priority();

			void setCalculationEnabled(bool enabled);
			bool isCalculationEnabled();

			void setPos2D(float x, float y);
			void setPos3D(float x, float y, float z);

			void physicalPosition2D(float x, float y, float& xOut, float& yOut);
			void physicalPosition3D(float x, float y, float z, float& xOut, float& yOut);

		protected:
			// Draw / Reset
			virtual void draw(IDirect3DDevice9 *pDevice) = 0;
			virtual void reset(IDirect3DDevice9 *pDevice) = 0;

			// Hiding and showing the element
			virtual void show() = 0;
			virtual void hide() = 0;

			// Resource management
			virtual void releaseResourcesForDeletion(IDirect3DDevice9 *pDevice) = 0;
			virtual bool canBeDeleted() = 0;
			virtual bool loadResource(IDirect3DDevice9 *pDevice) = 0;
			virtual void firstDrawAfterReset(IDirect3DDevice9 *pDevice) = 0;
			void changeResource();

			// Calculation for all resolutions
			float calculatedXPos(float x);
			float calculatedYPos(float y);

			// Returns the physical position of the element
			void overlayPosition(float& x, float& y) const;

			// The element's renderer
			Renderer *renderer();

		private:
			bool _hasToBeInitialised, _isMarkedForDeletion, _resourceChanged, _firstDrawAfterReset;

			int _priority = 0;

			float _xPosition = 0;
			float _yPosition = 0;
			float _zPosition = 0;
			bool _is3D = false;

			bool _calculationEnabled = true;

			Renderer *_renderer;
		};
	}
}


