/*
 * Copyright © 2012 Simple Entertainment Limited
 *
 * This file is part of The Simplicity Engine.
 *
 * The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see
 * <http://www.gnu.org/licenses/>.
 */
#include <GL/glew.h>

#include <simplicity/math/MathFactory.h>

#include "CullFaceOpenGLRenderer.h"

using namespace std;

namespace simplicity
{
	namespace opengl
	{
		CullFaceOpenGLRenderer::CullFaceOpenGLRenderer() :
			backFaceColour(MathFactory::getInstance().createRGBAColourVector()), cullFace(), drawingMode(), frontFace(), frontFaceColour(
				MathFactory::getInstance().createRGBAColourVector()), renderer()
		{
			backFaceColour->setRed(1.0f);
			frontFaceColour->setGreen(1.0f);
		}

		CullFaceOpenGLRenderer::~CullFaceOpenGLRenderer()
		{
		}

		void CullFaceOpenGLRenderer::dispose()
		{
			if (!cullFace)
			{
				glDisable(GL_CULL_FACE);
			}

			if (frontFace == GL_CW)
			{
				glFrontFace(GL_CW);
			}
			else
			{
				glFrontFace(GL_CCW);
			}
		}

		const RGBAColourVector<>& CullFaceOpenGLRenderer::getBackFaceColour() const
		{
			return *backFaceColour;
		}

		Renderer::DrawingMode CullFaceOpenGLRenderer::getDrawingMode() const
		{
			return drawingMode;
		}

		const RGBAColourVector<>& CullFaceOpenGLRenderer::getFrontFaceColour() const
		{
			return *frontFaceColour;
		}

		void CullFaceOpenGLRenderer::init()
		{
			glGetBooleanv(GL_CULL_FACE, &cullFace);
			glEnable(GL_CULL_FACE);

			glGetIntegerv(GL_FRONT_FACE, &frontFace);
		}

		void CullFaceOpenGLRenderer::renderModel(const Model& model)
		{
			unique_ptr<RGBAColourVector<> > renderColour;

			// Prepare for rendering of the back sides.
			if (frontFace == GL_CW)
			{
				glFrontFace(GL_CCW);
			}
			else
			{
				glFrontFace(GL_CW);
			}

			renderColour = MathFactory::getInstance().createRGBAColourVector();
			renderColour->setData(backFaceColour->getData());
			renderer.setColour(move(renderColour));

			renderer.init();
			renderer.renderModel(model);

			// Prepare for rendering of the front sides.
			if (frontFace == GL_CW)
			{
				glFrontFace(GL_CW);
			}
			else
			{
				glFrontFace(GL_CCW);
			}

			renderColour = MathFactory::getInstance().createRGBAColourVector();
			renderColour->setData(frontFaceColour->getData());
			renderer.setColour(move(renderColour));

			renderer.init();
			renderer.renderModel(model);
		}

		void CullFaceOpenGLRenderer::setBackFaceColour(unique_ptr<RGBAColourVector<> > backFaceColour)
		{
			this->backFaceColour = move(backFaceColour);
		}

		void CullFaceOpenGLRenderer::setDrawingMode(const DrawingMode mode)
		{
			this->drawingMode = mode;
		}

		void CullFaceOpenGLRenderer::setFrontFaceColour(unique_ptr<RGBAColourVector<> > frontFaceColour)
		{
			this->frontFaceColour = move(frontFaceColour);
		}
	}
}
