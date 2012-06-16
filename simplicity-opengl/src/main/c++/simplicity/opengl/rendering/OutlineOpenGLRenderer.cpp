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

#include "OutlineOpenGLRenderer.h"

using namespace std;

namespace simplicity
{
	namespace opengl
	{
		const float OutlineOpenGLRenderer::DEFAULT_OUTLINE_WIDTH = 3.0f;

		OutlineOpenGLRenderer::OutlineOpenGLRenderer() :
			monoColour(new MonoColourOpenGLRenderer), alwaysStencil(new AlwaysStencilOpenGLRenderer(monoColour)), notEqualStencil(
				new NotEqualStencilOpenGLRenderer(monoColour)), outlineWidth(DEFAULT_OUTLINE_WIDTH)
		{

		}

		OutlineOpenGLRenderer::~OutlineOpenGLRenderer()
		{
		}

		void OutlineOpenGLRenderer::dispose()
		{
		}

		Renderer::DrawingMode OutlineOpenGLRenderer::getDrawingMode() const
		{
			return monoColour->getDrawingMode();
		}

		const ColourVector<>& OutlineOpenGLRenderer::getOutlineColour() const
		{
			return monoColour->getColour();
		}

		float OutlineOpenGLRenderer::getOutlineWidth() const
		{
			return outlineWidth;
		}

		void OutlineOpenGLRenderer::init()
		{
		}

		void OutlineOpenGLRenderer::renderModel(const Model& model)
		{
			unsigned char lightingEnabledParams;
			glGetBooleanv(GL_LIGHTING, &lightingEnabledParams);
			unsigned char cullFaceEnabledParams;
			glGetBooleanv(GL_CULL_FACE, &cullFaceEnabledParams);

			// Prepare for setting the stencil.
			glDrawBuffer(GL_NONE);
			if (cullFaceEnabledParams)
			{
				glDisable(GL_CULL_FACE);
			}

			alwaysStencil->init();
			alwaysStencil->renderModel(model);
			alwaysStencil->dispose();

			// Restore rendering environment settings.
			glDrawBuffer(GL_BACK);

			// Prepare for rendering the outline.

			if (lightingEnabledParams)
			{
				glDisable(GL_LIGHTING);
			}

			// If outlines need to be drawn for the edges or faces, draw them.
			if (getDrawingMode() != VERTICES)
			{
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
				glLineWidth(outlineWidth);

				notEqualStencil->init();
				notEqualStencil->renderModel(model);
				notEqualStencil->dispose();

				glLineWidth(1.0f);
			}

			// Draw outlines for the vertices (if edges or faces are being drawn this just gives nice rounded corners).
			glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
			glPointSize(outlineWidth);

			notEqualStencil->init();
			notEqualStencil->renderModel(model);
			notEqualStencil->dispose();

			glPointSize(1.0f);

			// Restore rendering environment settings.
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			if (lightingEnabledParams)
			{
				glEnable(GL_LIGHTING);
			}
			if (cullFaceEnabledParams)
			{
				glEnable(GL_CULL_FACE);
			}
		}

		void OutlineOpenGLRenderer::setDrawingMode(const DrawingMode mode)
		{
			this->monoColour->setDrawingMode(mode);
		}

		void OutlineOpenGLRenderer::setOutlineColour(unique_ptr<ColourVector<> > outlineColour)
		{
			this->monoColour->setColour(move(outlineColour));
		}

		void OutlineOpenGLRenderer::setOutlineWidth(const float outlineWidth)
		{
			this->outlineWidth = outlineWidth;
		}
	}
}
