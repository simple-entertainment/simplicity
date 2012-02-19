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
#ifndef NAMEDOPENGLRENDERER_H_
#define NAMEDOPENGLRENDERER_H_

#include <simplicity/model/IndexedVectorVG.h>
#include <simplicity/model/VectorVG.h>
#include <simplicity/rendering/NamedRenderer.h>

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
		 * This implementation names the <code>Model</code>s rendered as well as the primitives rendered (faces, edges
		 * or vertices). <code>Model</code>s are named using their hash codes unless a specific name is given. The
		 * naming of the primitives is specific to the <code>Model</code> implementation.
		 * </p>
		 *
		 * @author Gary Buyn
		 */
		class NamedOpenGLRenderer : public NamedRenderer
		{
			public:
				/**
				 * <p>
				 * Creates an instance of <code>NamedOpenGLRenderer</code>.
				 * </p>
				 */
				NamedOpenGLRenderer();

				/**
				 * <p>
				 * Disposes of an instance of <code>NamedOpenGLRenderer</code>.
				 * </p>
				 */
				~NamedOpenGLRenderer();

				void dispose();

				DrawingMode getDrawingMode() const;

				void init();

				void renderModel(const Model& model);

				void renderModel(const Model& model, const int name);

				void setDrawingMode(const DrawingMode mode);

			private:
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
				 * Renders an <code>IndexedArrayVG</code>.
				 * </p>
				 *
				 * @param vertexGroup The <code>IndexedArrayVG</code> to render.
				 */
				void renderModel(const IndexedVectorVG& vertexGroup);

				/**
				 * <p>
				 * Renders an <code>ArrayVG</code>.
				 * </p>
				 *
				 * @param vertexGroup The <code>ArrayVG</code> to render.
				 */
				void renderModel(const VectorVG& vertexGroup);

				/**
				 * <p>
				 * Renders the given <code>ArrayVG</code> naming the edges with consecutive integers beginning with
				 * zero. This means that the section of the <code>ArrayVG</code>'s arrays containing data for a
				 * particular edge can be found as follows:
				 * </p>
				 *
				 * <p>
				 * <code>int firstIndexOfEdgeSection = egdeName * 3;</code>
				 * </p>
				 *
				 * <p>
				 * The section containing a particular edge consists of six consecutive items of data beginning at
				 * <code>firstIndexOfEdgeSection</code> in each
				 * array.
				 * </p>
				 *
				 * @param vertexGroup The <code>ArrayVG</code> to render.
				 */
				void renderVectorVGEdges(const VectorVG& vertexGroup);

				/**
				 * <p>
				 * Renders the given <code>ArrayVG</code> naming the faces with consecutive integers beginning with
				 * zero. This means that the section of the <code>ArrayVG</code>'s arrays containing data for a
				 * particular face can be found as follows:
				 * </p>
				 *
				 * <p>
				 * <code>int firstIndexOfFaceSection = faceName * 9;</code>
				 * </p>
				 *
				 * <p>
				 * The section containing a particular face consists of nine consecutive items of data beginning at
				 * <code>firstIndexOfFaceSection</code> in each
				 * array.
				 * </p>
				 *
				 * @param vertexGroup The <code>ArrayVG</code> to render.
				 */
				void renderVectorVGFaces(const VectorVG& vertexGroup);

				/**
				 * <p>
				 * Renders the given <code>ArrayVG</code> naming the vertices with consecutive integers beginning with
				 * zero. This means that the section of the <code>ArrayVG</code>'s arrays containing data for a
				 * particular vertex can be found as follows:
				 * </p>
				 *
				 * <p>
				 * <code>int firstIndexOfVertexSection = vertexName * 3;</code>
				 * </p>
				 *
				 * <p>
				 * The section containing a particular vertex consists of three consecutive items of data beginning at
				 * <code>firstIndexOfVertexSection</code> in
				 * each array.
				 * </p>
				 *
				 * @param vertexGroup The <code>ArrayVG</code> to render.
				 */
				void renderVectorVGVertices(const VectorVG& vertexGroup);
		};
	}
}

#endif /* NAMEDOPENGLRENDERER_H_ */
