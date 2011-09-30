/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <algorithm>
#include <stdio.h>

#include <simplicity/common/shared_equals_raw.h>
#include <simplicity/scenegraph/SimpleTraversal.h>
#include <simplicity/vector/SimpleRGBAColourVector4.h>

#include "SimpleOpenGLRenderingEngine.h"

using namespace boost;
using namespace std;

namespace simplicity
{
  namespace opengl
  {
    log4cpp::Category& SimpleOpenGLRenderingEngine::fLogger = log4cpp::Category::getInstance(
        "simplicity::opengl::SimpleOpenGLRenderingEngine");

    SimpleOpenGLRenderingEngine::SimpleOpenGLRenderingEngine() :
      fClearingColour(new SimpleRGBAColourVector4<float> (0.0f, 0.0f, 0.0f, 1.0f)), fClearsBeforeRender(true),
          fInitialised(false), fViewportHeight(600), fViewportWidth(800)
    {
    }

    SimpleOpenGLRenderingEngine::~SimpleOpenGLRenderingEngine()
    {
    }

    void
    SimpleOpenGLRenderingEngine::addEntities(std::vector<boost::shared_ptr<Entity> > entities)
    {
      for (unsigned int index = 0; index < entities.size(); index++)
      {
        addEntity(entities.at(index));
      }
    }

    void
    SimpleOpenGLRenderingEngine::addEntity(boost::shared_ptr<Entity> entity)
    {
      for (unsigned int index = 0; index < entity->getComponents().size(); index++)
      {
        shared_ptr<Node> node(dynamic_pointer_cast<Node> (entity->getComponents().at(index)));

        if (node.get())
        {
          fScene->getSceneGraph()->addSubgraph(node);
        }
      }
    }

    void
    SimpleOpenGLRenderingEngine::addRenderer(const int index, shared_ptr<Renderer> renderer)
    {
      fRenderers.insert(fRenderers.begin() + index, renderer);

      if (fScene.get())
      {
        setRendererRoot(*renderer, fScene->getSceneGraph()->getRoot());
      }
    }

    void
    SimpleOpenGLRenderingEngine::addRenderer(shared_ptr<Renderer> renderer)
    {
      addRenderer(fRenderers.size(), renderer);
    }

    shared_ptr<EngineInput>
    SimpleOpenGLRenderingEngine::advance(const shared_ptr<EngineInput> input)
    {
      if (!fCamera.get())
      {
        fLogger.fatal("Just how do you expect me to render without a camera then?");
        throw SEInvalidOperationException();
      }

      fCamera->init();

      if (!fScene.get())
      {
        fLogger.fatal("Just what do you expect me to render then? I don't have a scene to play with.");
        throw SEInvalidOperationException();
      }

      if (!fInitialised)
      {
        init();
      }

      // Clear the buffers.
      if (fClearsBeforeRender)
      {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
      }

      for (unsigned int index = 0; index < fRenderers.size(); index++)
      {
        if (fRendererRoots.find(fRenderers.at(index))->second.get())
        {
          fRenderers.at(index)->init();
          renderScene(*fRenderers.at(index));
          fRenderers.at(index)->dispose();
        }
      }

      return (shared_ptr<EngineInput> ());
    }

    void
    SimpleOpenGLRenderingEngine::backtrack(const int backtracks)
    {
      for (int index = 0; index < backtracks; index++)
      {
        glPopMatrix();
      }
    }

    bool
    SimpleOpenGLRenderingEngine::clearsBeforeRender() const
    {
      return (fClearsBeforeRender);
    }

    void
    SimpleOpenGLRenderingEngine::destroy()
    {
      // Revert depth test settings.
      glDepthFunc(GL_LESS);
      glDisable(GL_DEPTH_TEST);

      // Revert face culling settings.
      glDisable(GL_CULL_FACE);

      // Revert client state settings.
      glDisableClientState(GL_VERTEX_ARRAY);

      // Revert clearing settings.
      glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    }

    shared_ptr<Camera>
    SimpleOpenGLRenderingEngine::getCamera() const
    {
      return (fCamera);
    }

    shared_ptr<RGBAColourVector<float> >
    SimpleOpenGLRenderingEngine::getClearingColour() const
    {
      return (fClearingColour);
    }

    shared_ptr<Node>
    SimpleOpenGLRenderingEngine::getRendererRoot(const Renderer& renderer) const
    {
      shared_ptr<Node> rendererRoot;

      shared_equals_raw<Renderer> sharedEqualsRaw(&renderer);
      shared_ptr<Renderer> sharedRenderer(*find_if(fRenderers.begin(), fRenderers.end(), sharedEqualsRaw));

      if (sharedRenderer != *fRenderers.end())
      {
        rendererRoot = fRendererRoots.find(sharedRenderer)->second;
      }

      return (rendererRoot);
    }

    vector<shared_ptr<Renderer> >
    SimpleOpenGLRenderingEngine::getRenderers() const
    {
      return (fRenderers);
    }

    shared_ptr<Scene>
    SimpleOpenGLRenderingEngine::getScene() const
    {
      return (fScene);
    }

    int
    SimpleOpenGLRenderingEngine::getViewportHeight() const
    {
      return (fViewportHeight);
    }

    int
    SimpleOpenGLRenderingEngine::getViewportWidth() const
    {
      return (fViewportWidth);
    }

    void
    SimpleOpenGLRenderingEngine::init()
    {
      RunnableEngine::init();

      // Ensure objects further from the viewpoint are not drawn over the top of closer objects. To assist multi pass rendering, objects at the
      // exact same distance can be rendered over (i.e. the object will be rendered using the result of the last Renderer executed).
      glDepthFunc(GL_LEQUAL);
      glEnable(GL_DEPTH_TEST);

      // Only render the front (counter-clockwise) side of a polygon.
      glEnable(GL_CULL_FACE);

      // Enable model data arrays.
      glEnableClientState(GL_VERTEX_ARRAY);

      // Set the colour buffer clearing colour.
      glClearColor(fClearingColour->getRed(), fClearingColour->getGreen(), fClearingColour->getBlue(),
          fClearingColour->getAlpha());

      // Initialise the viewport size.
      glViewport(0, 0, fViewportWidth, fViewportHeight);

      fInitialised = true;
    }

    void
    SimpleOpenGLRenderingEngine::removeRenderer(const Renderer& renderer)
    {
      shared_equals_raw<Renderer> sharedEqualsRaw(&renderer);
      vector<shared_ptr<Renderer> >::iterator sharedRenderer(find_if(fRenderers.begin(), fRenderers.end(), sharedEqualsRaw));

      fRenderers.erase(sharedRenderer);
      fRendererRoots.erase(*sharedRenderer);
    }

    void
    SimpleOpenGLRenderingEngine::renderScene(Renderer& renderer)
    {
      glPushMatrix();
      {
        fCamera->apply();

        for (unsigned int index = 0; index < fScene->getLights().size(); index++)
        {
          fScene->getLights().at(index)->apply();
        }

        shared_equals_raw<Renderer> sharedEqualsRaw(&renderer);
        shared_ptr<Renderer> sharedRenderer(*find_if(fRenderers.begin(), fRenderers.end(), sharedEqualsRaw));
        renderSceneGraph(renderer, *fRendererRoots.find(sharedRenderer)->second);
      }
      glPopMatrix();
    }

    void
    SimpleOpenGLRenderingEngine::renderSceneGraph(Renderer& renderer, const Node& root)
    {
      // For every node in the traversal of the scene.
      SimpleTraversal traversal(root);
      shared_ptr<Node> currentNode;

      while (traversal.hasMoreNodes())
      {
        // Remove transformations from the stack that do not apply to the next node.
        backtrack(traversal.getBacktracksToNextNode());

        // Apply the transformation of the current node.
        currentNode = traversal.getNextNode();

        glPushMatrix();
        glMultMatrixf(currentNode->getTransformation().getRawData());

        // Render the current node.
        ModelNode* modelNode = dynamic_cast<ModelNode*> (currentNode.get());
        if (modelNode)
        {
          NamedRenderer* namedRenderer = dynamic_cast<NamedRenderer*> (&renderer);
          if (namedRenderer)
          {
            namedRenderer->renderModel(*modelNode->getModel(), modelNode->getID());
          }
          else
          {
            renderer.renderModel(*modelNode->getModel());
          }
        }
      }

      // Remove all remaining transformations from the stack.
      backtrack(traversal.getBacktracksToNextNode());
    }

    void
    SimpleOpenGLRenderingEngine::reset()
    {
      init();
    }

    void
    SimpleOpenGLRenderingEngine::setCamera(shared_ptr<Camera> camera)
    {
      fCamera = camera;
    }

    void
    SimpleOpenGLRenderingEngine::setClearingColour(shared_ptr<RGBAColourVector<float> > clearingColour)
    {
      fClearingColour = clearingColour;

      fInitialised = false;
    }

    void
    SimpleOpenGLRenderingEngine::setClearsBeforeRender(const bool clearsBeforeRender)
    {
      fClearsBeforeRender = clearsBeforeRender;
    }

    void
    SimpleOpenGLRenderingEngine::setRendererRoot(const Renderer& renderer, shared_ptr<Node> root)
    {
      shared_equals_raw<Renderer> sharedEqualsRaw(&renderer);
      shared_ptr<Renderer> sharedRenderer(*find_if(fRenderers.begin(), fRenderers.end(), sharedEqualsRaw));
      fRendererRoots.erase(sharedRenderer);
      fRendererRoots.insert(pair<shared_ptr<Renderer> , shared_ptr<Node> > (sharedRenderer, root));
    }

    void
    SimpleOpenGLRenderingEngine::setScene(shared_ptr<Scene> scene)
    {
      if (!scene->getSceneGraph().get())
      {
        fLogger.fatal("I'm going to have to insist that you attach a scene graph to that scene first.");
        throw new SEInvalidOperationException();
      }

      fScene = scene;

      for (unsigned int index = 0; index < fRenderers.size(); index++)
      {
        if (fRendererRoots.find(fRenderers.at(index)) == fRendererRoots.end())
        {
          fRendererRoots.insert(
              pair<shared_ptr<Renderer> , shared_ptr<Node> > (fRenderers.at(index), fScene->getSceneGraph()->getRoot()));
        }
      }
    }

    void
    SimpleOpenGLRenderingEngine::setViewportHeight(const int viewportHeight)
    {
      fViewportHeight = viewportHeight;

      fInitialised = false;
    }

    void
    SimpleOpenGLRenderingEngine::setViewportWidth(const int viewportWidth)
    {
      fViewportWidth = viewportWidth;

      fInitialised = false;
    }
  }
}
