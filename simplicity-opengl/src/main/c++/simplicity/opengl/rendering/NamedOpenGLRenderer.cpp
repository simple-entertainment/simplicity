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
#include <boost/math/constants/constants.hpp>

#include <GL/glew.h>
#include <GL/glut.h>

#include <simplicity/math/MathFactory.h>
#include <simplicity/model/ModelConstants.h>
#include <simplicity/SENotSupportedException.h>

#include "NamedOpenGLRenderer.h"

using namespace boost::math::constants;
using namespace std;
using namespace simplicity::model_constants;

namespace simplicity
{
	namespace opengl
	{
		NamedOpenGLRenderer::NamedOpenGLRenderer() :
			drawingMode(FACES)
		{
		}

		NamedOpenGLRenderer::~NamedOpenGLRenderer()
		{
		}

		void NamedOpenGLRenderer::dispose()
		{
			glPointSize(1.0f);
		}

		Renderer::DrawingMode NamedOpenGLRenderer::getDrawingMode() const
		{
			return (drawingMode);
		}

		int NamedOpenGLRenderer::getOpenGlDrawingMode(const DrawingMode drawingMode)
		{
			int openGlDrawingMode = -1;

			if (drawingMode == Renderer::VERTICES)
			{
				openGlDrawingMode = GL_POINTS;
			}
			else if (drawingMode == Renderer::EDGES)
			{
				openGlDrawingMode = GL_LINE_LOOP;
			}
			else if (drawingMode == Renderer::FACES)
			{
				openGlDrawingMode = GL_TRIANGLES;
			}

			return (openGlDrawingMode);
		}

		void NamedOpenGLRenderer::init()
		{
			glPointSize(2.0f);
		}

		void NamedOpenGLRenderer::renderModel(const GLUCapsule& capsule)
		{
			RGBAColourVector<>& color(capsule.getColour());
			glColor4f(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());

			gluCylinder(gluNewQuadric(), capsule.getRadius(), capsule.getRadius(), capsule.getLength(),
				capsule.getSlices(), capsule.getStacks());

			glPushMatrix();
			{
				gluSphere(gluNewQuadric(), capsule.getRadius(), capsule.getSlices(), capsule.getSlices());

				unique_ptr<TransformationMatrix<> > transformation(
					MathFactory::getInstance().createTransformationMatrix());
				transformation->getTranslation()->translateZ(capsule.getLength());

				glMultMatrixf(transformation->getData().data());

				gluSphere(gluNewQuadric(), capsule.getRadius(), capsule.getSlices(), capsule.getSlices());
			}
			glPopMatrix();
		}

		void NamedOpenGLRenderer::renderModel(const GLUCylinder& cylinder)
		{
			RGBAColourVector<>& color(cylinder.getColour());
			glColor4f(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());

			gluCylinder(gluNewQuadric(), cylinder.getRadius(), cylinder.getRadius(), cylinder.getLength(),
				cylinder.getSlices(), cylinder.getStacks());

			glPushMatrix();
			{
				unique_ptr<TransformationMatrix<> > transformation(
					MathFactory::getInstance().createTransformationMatrix());
				unique_ptr<TranslationVector<> > rotationAxis(MathFactory::getInstance().createTranslationVector());
				rotationAxis->setY(1.0f);
				transformation->rotate(pi<float>(), *rotationAxis);

				glMultMatrixf(transformation->getData().data());

				gluDisk(gluNewQuadric(), 0.0f, cylinder.getRadius(), cylinder.getSlices(), 1);
			}
			glPopMatrix();

			glPushMatrix();
			{
				unique_ptr<TransformationMatrix<> > transformation(
					MathFactory::getInstance().createTransformationMatrix());
				transformation->getTranslation()->translateZ(cylinder.getLength());

				glMultMatrixf(transformation->getData().data());

				gluDisk(gluNewQuadric(), 0.0f, cylinder.getRadius(), cylinder.getSlices(), 1);
			}
			glPopMatrix();
		}

		void NamedOpenGLRenderer::renderModel(const GLUSphere& sphere)
		{
			RGBAColourVector<>& color(sphere.getColour());
			glColor4f(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());

			gluSphere(gluNewQuadric(), sphere.getRadius(), sphere.getSlices(), sphere.getStacks());
		}

		void NamedOpenGLRenderer::renderModel(const GLUTorus& torus)
		{
			RGBAColourVector<>& color(torus.getColour());
			glColor4f(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());

			glutSolidTorus(torus.getInnerRadius(), torus.getOuterRadius(), torus.getSlices(), torus.getStacks());
		}

		void NamedOpenGLRenderer::renderModel(const IndexedVertexGroup& vertexGroup)
		{
			const vector<int>& indices = vertexGroup.getIndices();
			const vector<float>& colours = vertexGroup.getColours();
			const vector<float>& normals = vertexGroup.getNormals();
			const vector<float>& vertices = vertexGroup.getVertices();

			glBegin(getOpenGlDrawingMode(drawingMode));
			{
				for (unsigned int indicesIndex = 0; indicesIndex < indices.size(); indicesIndex++)
				{
					int vertexIndex = indices.at(indicesIndex) * ITEMS_IN_CNV;

					glColor3f(colours.at(vertexIndex), colours.at(vertexIndex + 1), colours.at(vertexIndex + 2));
					glNormal3f(normals.at(vertexIndex), normals.at(vertexIndex + 1), normals.at(vertexIndex + 2));
					glVertex3f(vertices.at(vertexIndex), vertices.at(vertexIndex + 1), vertices.at(vertexIndex + 2));
				}
			}
			glEnd();
		}

		void NamedOpenGLRenderer::renderModel(const Model& model)
		{
			renderModel(model, 0);
		}

		void NamedOpenGLRenderer::renderModel(const Model& model, const int name)
		{
			glPushName(name);

			if (dynamic_cast<const GLUCapsule*>(&model))
			{
				renderModel(dynamic_cast<const GLUCapsule&>(model));
			}
			else if (dynamic_cast<const GLUCylinder*>(&model))
			{
				renderModel(dynamic_cast<const GLUCylinder&>(model));
			}
			else if (dynamic_cast<const GLUSphere*>(&model))
			{
				renderModel(dynamic_cast<const GLUSphere&>(model));
			}
			else if (dynamic_cast<const GLUTorus*>(&model))
			{
				renderModel(dynamic_cast<const GLUTorus&>(model));
			}
			else if (dynamic_cast<const IndexedVertexGroup*>(&model))
			{
				renderModel(dynamic_cast<const IndexedVertexGroup&>(model));
			}
			else if (dynamic_cast<const VertexGroup*>(&model))
			{
				renderModel(dynamic_cast<const VertexGroup&>(model));
			}
			else
			{
				glPopName();
				throw new SENotSupportedException;
			}

			glPopName();
		}

		void NamedOpenGLRenderer::renderModel(const VertexGroup& vertexGroup)
		{
			if (getDrawingMode() == EDGES)
			{
				renderModel(vertexGroup);
			}
			else if (getDrawingMode() == FACES)
			{
				renderModel(vertexGroup);
			}
			else if (getDrawingMode() == VERTICES)
			{
				renderModel(vertexGroup);
			}
		}

		void NamedOpenGLRenderer::renderVertexGroupEdges(const VertexGroup& vertexGroup)
		{
			const vector<float>& colours = vertexGroup.getColours();
			const vector<float>& normals = vertexGroup.getNormals();
			const vector<float>& vertices = vertexGroup.getVertices();

			for (unsigned int index = 0; index < vertices.size() / ITEMS_IN_CNV - 1; index++)
			{
				glPushName(index);
				glBegin(GL_LINE_LOOP);
				{
					glColor3f(colours.at(index * ITEMS_IN_CNV), colours.at(index * ITEMS_IN_CNV + 1),
						colours.at(index * ITEMS_IN_CNV + 2));
					glNormal3f(normals.at(index * ITEMS_IN_CNV), normals.at(index * ITEMS_IN_CNV + 1),
						normals.at(index * ITEMS_IN_CNV + 2));
					glVertex3f(vertices.at(index * ITEMS_IN_CNV), vertices.at(index * ITEMS_IN_CNV + 1),
						vertices.at(index * ITEMS_IN_CNV + 2));

					glColor3f(colours.at((index + 1) * ITEMS_IN_CNV), colours.at((index + 1) * ITEMS_IN_CNV + 1),
						colours.at((index + 1) * ITEMS_IN_CNV + 2));
					glNormal3f(normals.at((index + 1) * ITEMS_IN_CNV), normals.at((index + 1) * ITEMS_IN_CNV + 1),
						normals.at((index + 1) * ITEMS_IN_CNV + 2));
					glVertex3f(vertices.at((index + 1) * ITEMS_IN_CNV), vertices.at((index + 1) * ITEMS_IN_CNV + 1),
						vertices.at((index + 1) * ITEMS_IN_CNV + 2));
				}
				glEnd();
				glPopName();
			}
		}

		void NamedOpenGLRenderer::renderVertexGroupFaces(const VertexGroup& vertexGroup)
		{
			const vector<float>& colours = vertexGroup.getColours();
			const vector<float>& normals = vertexGroup.getNormals();
			const vector<float>& vertices = vertexGroup.getVertices();

			for (unsigned int faceIndex = 0; faceIndex < vertices.size() / CNV_ITEMS_IN_FACE; faceIndex++)
			{
				glPushName(faceIndex);
				glBegin(GL_TRIANGLES);
				{
					for (int vertexIndex = 0; vertexIndex < CNV_ITEMS_IN_FACE; vertexIndex += ITEMS_IN_CNV)
					{
						int vertex = faceIndex * CNV_ITEMS_IN_FACE + vertexIndex;

						glColor3f(colours.at(vertex), colours.at(vertex + 1), colours.at(vertex + 2));
						glNormal3f(normals.at(vertex), normals.at(vertex + 1), normals.at(vertex + 2));
						glVertex3f(vertices.at(vertex), vertices.at(vertex + 1), vertices.at(vertex + 2));
					}
				}
				glEnd();
				glPopName();
			}
		}

		void NamedOpenGLRenderer::renderVertexGroupVertices(const VertexGroup& vertexGroup)
		{
			const vector<float>& colours = vertexGroup.getColours();
			const vector<float>& normals = vertexGroup.getNormals();
			const vector<float>& vertices = vertexGroup.getVertices();

			for (unsigned int index = 0; index < vertices.size() / ITEMS_IN_CNV; index++)
			{
				glPushName(index);
				glBegin(GL_POINTS);
				{
					glColor3f(colours.at(index * ITEMS_IN_CNV), colours.at(index * ITEMS_IN_CNV + 1),
						colours.at(index * ITEMS_IN_CNV + 2));
					glNormal3f(normals.at(index * ITEMS_IN_CNV), normals.at(index * ITEMS_IN_CNV + 1),
						normals.at(index * ITEMS_IN_CNV + 2));
					glVertex3f(vertices.at(index * ITEMS_IN_CNV), vertices.at(index * ITEMS_IN_CNV + 1),
						vertices.at(index * ITEMS_IN_CNV + 2));
				}
				glEnd();
				glPopName();
			}
		}

		void NamedOpenGLRenderer::setDrawingMode(const DrawingMode mode)
		{
			drawingMode = mode;
		}
	}
}
