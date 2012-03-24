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
#ifndef MONOCOLOUROPENGLRENDERER_H_
#define MONOCOLOUROPENGLRENDERER_H_

#include <simplicity/math/ColourVector.h>
#include <simplicity/model/IndexedVertexGroup.h>
#include <simplicity/model/VertexGroup.h>
#include <simplicity/rendering/Renderer.h>

#include "../model/OpenGLText.h"
#include "../model/shape/GLUCapsule.h"
#include "../model/shape/GLUCylinder.h"
#include "../model/shape/GLUSphere.h"
#include "../model/shape/GLUTorus.h"

namespace simplicity
{
	namespace opengl
	{
		/**
		 * <p>
		 * Renders a {@link simplicity::Model Model} using only one colour in an OpenGL environment.
		 * </p>
		 *
		 * @author Gary Buyn
		 */
		class MonoColourOpenGLRenderer : public Renderer
		{
			public:
				/**
				 * <p>
				 * Creates an instance of <code>MonoColourOpenGLRenderer</code>.
				 * </p>
				 */
				MonoColourOpenGLRenderer();

				/**
				 * <p>
				 * Disposes of an instance of <code>MonoColourOpenGLRenderer</code>.
				 * </p>
				 */
				virtual ~MonoColourOpenGLRenderer();

				void dispose();

				/**
				 * <p>
				 * Retrieves the colour to render the {@link simplicity::Model Model} in.
				 * </p>
				 *
				 * @return The colour to render the {@link simplicity::Model Model} in.
				 */
				const ColourVector<>& getColour() const;

				DrawingMode getDrawingMode() const;

				void init();

				void renderModel(const Model& model);

				/**
				 * <p>
				 * Sets the colour to render the {@link com.se.simplicity.model.Model Model} in.
				 * </p>
				 *
				 * @param renderColour The colour to render the {@link com.se.simplicity.model.Model Model} in.
				 */
				void setColour(std::unique_ptr<ColourVector<> > colour);

				void setDrawingMode(const DrawingMode mode);

			private:
				/**
				 * <p>
				 * Renders a <code>GLUCapsule</code>.
				 * </p>
				 *
				 * @param capsule The <code>GLUCapsule</code> to render.
				 */
				void renderModel(const GLUCapsule& capsule);

				/**
				 * <p>
				 * Renders a <code>GLUCylinder</code>.
				 * </p>
				 *
				 * @param cylinder The <code>GLUCylinder</code> to render.
				 */
				void renderModel(const GLUCylinder& cylinder);

				/**
				 * <p>
				 * Renders a <code>GLUSphere</code>.
				 * </p>
				 *
				 * @param sphere The <code>GLUSphere</code> to render.
				 */
				void renderModel(const GLUSphere& sphere);

				/**
				 * <p>
				 * Renders a <code>GLUTorus</code>.
				 * </p>
				 *
				 * @param torus The <code>GLUTorus</code> to render.
				 */
				void renderModel(const GLUTorus& torus);

				/**
				 * <p>
				 * Renders an <code>IndexedVertexGroup</code>.
				 * </p>
				 *
				 * @param vertexGroup The <code>IndexedVertexGroup</code> to render.
				 */
				void renderModel(const IndexedVertexGroup& vertexGroup);

				/**
				 * <p>
				 * Renders an <code>OpenGLText</code>.
				 * </p>
				 *
				 * @param vertexGroup The <code>OpenGLText</code> to render.
				 */
				void renderModel(const OpenGLText& text);

				/**
				 * <p>
				 * Renders an <code>VertexGroup</code>.
				 * </p>
				 *
				 * @param vertexGroup The <code>VertexGroup</code> to render.
				 */
				void renderModel(const VertexGroup& vertexGroup);

				/**
				 * <p>
				 * The colour to render the {@link com.se.simplicity.model.Model Model} in.
				 * </p>
				 */
				std::unique_ptr<ColourVector<> > colour;

				/**
				 * <p>
				 * The drawing mode used to render the {@link com.se.simplicity.model.Model Model}s.
				 * </p>
				 */
				DrawingMode drawingMode;

				/**
				 * <p>
				 * Retrieves the OpenGL drawing mode used to render the {@link simplicity::Model Model}.
				 * </p>
				 *
				 * @param drawingMode The <code>DrawingMode</code> to retrieve the OpenGL drawing mode for.
				 *
				 * @return The OpenGL drawing mode used to render the <code>Model</code>.
				 */
				int getOpenGlDrawingMode(const DrawingMode drawingMode);
		};
	}
}

#endif /* MONOCOLOUROPENGLRENDERER_H_ */
