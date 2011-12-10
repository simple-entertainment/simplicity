/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <GL/glew.h>

#include <simplicity/model/ModelConstants.h>
#include <simplicity/model/shape/Shape.h>
#include <simplicity/scene/model/ModelNode.h>

#include "SimpleOpenGLPicker.h"

using namespace boost;
using namespace simplicity::model_constants;

namespace simplicity
{
  namespace opengl
  {
    SimpleOpenGLPicker::SimpleOpenGLPicker() :
      fDrawingMode(Renderer::FACES), fSelectBufferCapacity(DEFAULT_SELECT_BUFFER_CAPACITY)
    {
    }

    SimpleOpenGLPicker::~SimpleOpenGLPicker()
    {
    }

    PickEvent
    SimpleOpenGLPicker::createPickEvent(const Scene& scene, const int numberOfHits) const
    {
      PickEvent event;
      int bufferIndex = 0;

      for (int hitIndex = 0; hitIndex < numberOfHits; hitIndex++)
      {
        Hit hit;
        unsigned int numberOfNames = fSelectBuffer[bufferIndex++];
        hit.minimumDistance = fSelectBuffer[bufferIndex++];
        hit.maximumDistance = fSelectBuffer[bufferIndex++];

        hit.node = scene.getNode(fSelectBuffer[bufferIndex]);

        shared_ptr<Model> model(dynamic_pointer_cast<ModelNode> (hit.node)->getModel());
        if (dynamic_cast<VertexGroup*> (model.get()))
        {
          if (numberOfNames > 1)
          {
            hit.primitive = getSubsetVG(dynamic_cast<VertexGroup&> (*model), fSelectBuffer[bufferIndex + 1]);
          }
        }
        else if (dynamic_cast<Shape*> (model.get()))
        {
          hit.primitive = model;
        }

        bufferIndex += numberOfNames;
        event.addHit(hit);
      }

      return (event);
    }

    void
    SimpleOpenGLPicker::dispose()
    {
      delete[] fSelectBuffer;
    }

    Renderer::DrawingMode
    SimpleOpenGLPicker::getDrawingMode() const
    {
      return (fDrawingMode);
    }

    shared_ptr<RenderingEngine>
    SimpleOpenGLPicker::getRenderingEngine() const
    {
      return fRenderingEngine;
    }

    unsigned int*
    SimpleOpenGLPicker::getSelectBuffer() const
    {
      return (fSelectBuffer);
    }

    int
    SimpleOpenGLPicker::getSelectBufferCapacity() const
    {
      return (fSelectBufferCapacity);
    }

    shared_ptr<VertexGroup>
    SimpleOpenGLPicker::getSubsetVG(VertexGroup& vertexGroup, const int index) const
    {
      shared_ptr<VertexGroup> subsetVertexGroup;

      if (fDrawingMode == Renderer::EDGES)
      {
        subsetVertexGroup = vertexGroup.createEdgeSubsetVG(index);
      }
      else if (fDrawingMode == Renderer::FACES)
      {
        subsetVertexGroup = vertexGroup.createFaceSubsetVG(index);
      }
      else if (fDrawingMode == Renderer::VERTICES)
      {
        subsetVertexGroup = vertexGroup.createVertexSubsetVG(index);
      }

      return (subsetVertexGroup);
    }

    void
    SimpleOpenGLPicker::init()
    {
      fSelectBuffer = new unsigned int[fSelectBufferCapacity];
      glSelectBuffer(fSelectBufferCapacity, fSelectBuffer);
    }

    PickEvent
    SimpleOpenGLPicker::pickScene(Scene& scene, const Camera& camera, const Pick pick)
    {
      shared_ptr<Scene> originalScene(fRenderingEngine->getScene());
      shared_ptr<Camera> originalCamera(fRenderingEngine->getCamera());

      fRenderingEngine->setScene(scene.getThisShared());
      fRenderingEngine->setCamera(camera.getPickCamera(pick));

      glRenderMode(GL_SELECT);

      fRenderingEngine->advance(shared_ptr<EngineInput>());

      int numberOfHits = glRenderMode(GL_RENDER);

      fRenderingEngine->setScene(originalScene);
      fRenderingEngine->setCamera(originalCamera);

      return (createPickEvent(scene, numberOfHits));
    }

    void
    SimpleOpenGLPicker::setDrawingMode(const Renderer::DrawingMode mode)
    {
      fDrawingMode = mode;
    }

    void
    SimpleOpenGLPicker::setRenderingEngine(shared_ptr<RenderingEngine> renderingEngine)
    {
      fRenderingEngine = renderingEngine;
    }

    void
    SimpleOpenGLPicker::setSelectBufferCapacity(const int selectBufferCapacity)
    {
      fSelectBufferCapacity = selectBufferCapacity;
    }
  }
}
