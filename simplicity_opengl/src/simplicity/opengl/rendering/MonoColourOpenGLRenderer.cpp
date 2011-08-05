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
#include <simplicity/vector/SimpleRGBAColourVector4.h>
#include <simplicity/vector/SimpleTransformationMatrix44.h>

#include "MonoColourOpenGLRenderer.h"

using namespace boost;
using namespace boost::math::constants;
using namespace simplicity::model_constants;

namespace simplicity
{
  namespace opengl
  {
    MonoColourOpenGLRenderer::MonoColourOpenGLRenderer() :
      fColour(shared_ptr<SimpleRGBAColourVector4<float> > (new SimpleRGBAColourVector4<float> )), fDrawingMode(FACES)
    {
    }

    MonoColourOpenGLRenderer::~MonoColourOpenGLRenderer()
    {
    }

    void
    MonoColourOpenGLRenderer::dispose()
    {
      glPointSize(1.0f);
    }

    shared_ptr<RGBAColourVector<float> >
    MonoColourOpenGLRenderer::getColour()
    {
      return (fColour);
    }

    Renderer::DrawingMode
    MonoColourOpenGLRenderer::getDrawingMode() const
    {
      return (fDrawingMode);
    }

    int
    MonoColourOpenGLRenderer::getOpenGlDrawingMode(const DrawingMode drawingMode)
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
    MonoColourOpenGLRenderer::init()
    {
      glPointSize(2.0f);
    }

    void
    MonoColourOpenGLRenderer::renderModel(const GLUCapsule& capsule)
    {
      glColor4f(fColour->getRed(), fColour->getGreen(), fColour->getBlue(), fColour->getAlpha());

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
    MonoColourOpenGLRenderer::renderModel(const GLUCylinder& cylinder)
    {
      glColor4f(fColour->getRed(), fColour->getGreen(), fColour->getBlue(), fColour->getAlpha());

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
    MonoColourOpenGLRenderer::renderModel(const GLUSphere& sphere)
    {
      glColor4f(fColour->getRed(), fColour->getGreen(), fColour->getBlue(), fColour->getAlpha());

      gluSphere(gluNewQuadric(), sphere.getRadius(), sphere.getSlices(), sphere.getStacks());
    }

    void
    MonoColourOpenGLRenderer::renderModel(const GLUTorus& torus)
    {
      glColor4f(fColour->getRed(), fColour->getGreen(), fColour->getBlue(), fColour->getAlpha());

      glutSolidTorus(torus.getInnerRadius(), torus.getOuterRadius(), torus.getSlices(), torus.getStacks());
    }

    void
    MonoColourOpenGLRenderer::renderModel(const IndexedVectorVG& vertexGroup)
    {
      const vector<int>& indices = vertexGroup.getIndices();
      const vector<float>& normals = vertexGroup.getNormals();
      const vector<float>& vertices = vertexGroup.getVertices();

      glBegin(getOpenGlDrawingMode(fDrawingMode));
      {
        for (unsigned int indicesIndex = 0; indicesIndex < indices.size(); indicesIndex++)
        {
          int vertexIndex = indices.at(indicesIndex) * ITEMS_IN_CNV;

          glColor3f(fColour->getRed(), fColour->getBlue(), fColour->getGreen());
          glNormal3f(normals.at(vertexIndex), normals.at(vertexIndex + 1), normals.at(vertexIndex + 2));
          glVertex3f(vertices.at(vertexIndex), vertices.at(vertexIndex + 1), vertices.at(vertexIndex + 2));
        }
      }
      glEnd();
    }

    void
    MonoColourOpenGLRenderer::renderModel(const Model& model)
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
    MonoColourOpenGLRenderer::renderModel(const VectorVG& vertexGroup)
    {
      const vector<float>& normals = vertexGroup.getNormals();
      const vector<float>& vertices = vertexGroup.getVertices();

      glBegin(getOpenGlDrawingMode(fDrawingMode));
      {
        for (unsigned int index = 0; index < vertices.size(); index += ITEMS_IN_CNV)
        {
          glColor3f(fColour->getRed(), fColour->getBlue(), fColour->getGreen());
          glNormal3f(normals.at(index), normals.at(index + 1), normals.at(index + 2));
          glVertex3f(vertices.at(index), vertices.at(index + 1), vertices.at(index + 2));
        }
      }
      glEnd();
    }

    void
    MonoColourOpenGLRenderer::setColour(shared_ptr<RGBAColourVector<float> > colour)
    {
      fColour = colour;
    }

    void
    MonoColourOpenGLRenderer::setDrawingMode(const DrawingMode mode)
    {
      fDrawingMode = mode;
    }
  }
}
