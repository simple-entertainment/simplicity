/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <boost/math/constants/constants.hpp>

#include <GL/glew.h>
#include <GL/glut.h>

#include <simplicity/model/ModelConstants.h>
#include <simplicity/SENotSupportedException.h>
#include <simplicity/vector/RGBAColourVector.h>
#include <simplicity/vector/SimpleTransformationMatrix44.h>

#include "SimpleOpenGLRenderer.h"

using namespace boost;
using namespace boost::math::constants;
using namespace simplicity::model_constants;

namespace simplicity
{
  namespace opengl
  {
    SimpleOpenGLRenderer::SimpleOpenGLRenderer() :
      fDrawingMode(FACES)
    {
    }

    SimpleOpenGLRenderer::~SimpleOpenGLRenderer()
    {
    }

    void
    SimpleOpenGLRenderer::dispose()
    {
      glPointSize(1.0f);
    }

    Renderer::DrawingMode
    SimpleOpenGLRenderer::getDrawingMode() const
    {
      return (fDrawingMode);
    }

    int
    SimpleOpenGLRenderer::getOpenGlDrawingMode(const DrawingMode drawingMode)
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

    void
    SimpleOpenGLRenderer::init()
    {
      glPointSize(2.0f);
    }

    void
    SimpleOpenGLRenderer::renderModel(const GLUCapsule& capsule)
    {
      RGBAColourVector<float>& color(capsule.getColour());
      glColor4f(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());

      gluCylinder(gluNewQuadric(), capsule.getRadius(), capsule.getRadius(), capsule.getLength(), capsule.getSlices(),
          capsule.getStacks());

      glPushMatrix();
      {
        gluSphere(gluNewQuadric(), capsule.getRadius(), capsule.getSlices(), capsule.getSlices());

        SimpleTransformationMatrix44<float> transformation;
        transformation.getTranslation()->translateZ(capsule.getLength());

        glMultMatrixf(transformation.getRawData());

        gluSphere(gluNewQuadric(), capsule.getRadius(), capsule.getSlices(), capsule.getSlices());
      }
      glPopMatrix();
    }

    void
    SimpleOpenGLRenderer::renderModel(const GLUCylinder& cylinder)
    {
      RGBAColourVector<float>& color(cylinder.getColour());
      glColor4f(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());

      gluCylinder(gluNewQuadric(), cylinder.getRadius(), cylinder.getRadius(), cylinder.getLength(), cylinder.getSlices(),
          cylinder .getStacks());

      glPushMatrix();
      {
        SimpleTransformationMatrix44<float> transformation;
        transformation.rotate(pi<float> (), SimpleTranslationVector4<float> (0.0f, 1.0f, 0.0f, 1.0f));

        glMultMatrixf(transformation.getRawData());

        gluDisk(gluNewQuadric(), 0.0f, cylinder.getRadius(), cylinder.getSlices(), 1);
      }
      glPopMatrix();

      glPushMatrix();
      {
        SimpleTransformationMatrix44<float> transformation;
        transformation.getTranslation()->translateZ(cylinder.getLength());

        glMultMatrixf(transformation.getRawData());

        gluDisk(gluNewQuadric(), 0.0f, cylinder.getRadius(), cylinder.getSlices(), 1);
      }
      glPopMatrix();
    }

    void
    SimpleOpenGLRenderer::renderModel(const GLUSphere& sphere)
    {
      RGBAColourVector<float>& color(sphere.getColour());
      glColor4f(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());

      gluSphere(gluNewQuadric(), sphere.getRadius(), sphere.getSlices(), sphere.getStacks());
    }

    void
    SimpleOpenGLRenderer::renderModel(const GLUTorus& torus)
    {
      RGBAColourVector<float>& color(torus.getColour());
      glColor4f(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());

      glutSolidTorus(torus.getInnerRadius(), torus.getOuterRadius(), torus.getSlices(), torus.getStacks());
    }

    void
    SimpleOpenGLRenderer::renderModel(const IndexedVectorVG& vertexGroup)
    {
      const vector<int>& indices = vertexGroup.getIndices();
      const vector<float>& colours = vertexGroup.getColours();
      const vector<float>& normals = vertexGroup.getNormals();
      const vector<float>& vertices = vertexGroup.getVertices();

      glBegin(getOpenGlDrawingMode(fDrawingMode));
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

    void
    SimpleOpenGLRenderer::renderModel(const Model& model)
    {
      if (dynamic_cast<const GLUCapsule*> (&model))
      {
        renderModel(dynamic_cast<const GLUCapsule&> (model));
      }
      else if (dynamic_cast<const GLUCylinder*> (&model))
      {
        renderModel(dynamic_cast<const GLUCylinder&> (model));
      }
      else if (dynamic_cast<const GLUSphere*> (&model))
      {
        renderModel(dynamic_cast<const GLUSphere&> (model));
      }
      else if (dynamic_cast<const GLUTorus*> (&model))
      {
        renderModel(dynamic_cast<const GLUTorus&> (model));
      }
      else if (dynamic_cast<const IndexedVectorVG*> (&model))
      {
        renderModel(dynamic_cast<const IndexedVectorVG&> (model));
      }
      else if (dynamic_cast<const VectorVG*> (&model))
      {
        renderModel(dynamic_cast<const VectorVG&> (model));
      }
      else
      {
        throw new SENotSupportedException;
      }
    }

    void
    SimpleOpenGLRenderer::renderModel(const VectorVG& vertexGroup)
    {
      const vector<float>& colours = vertexGroup.getColours();
      const vector<float>& normals = vertexGroup.getNormals();
      const vector<float>& vertices = vertexGroup.getVertices();

      glBegin(getOpenGlDrawingMode(fDrawingMode));
      {
        for (unsigned int index = 0; index < vertices.size(); index += ITEMS_IN_CNV)
        {
          glColor3f(colours.at(index), colours.at(index + 1), colours.at(index + 2));
          glNormal3f(normals.at(index), normals.at(index + 1), normals.at(index + 2));
          glVertex3f(vertices.at(index), vertices.at(index + 1), vertices.at(index + 2));
        }
      }
      glEnd();
    }

    void
    SimpleOpenGLRenderer::setDrawingMode(const DrawingMode mode)
    {
      fDrawingMode = mode;
    }
  }
}
