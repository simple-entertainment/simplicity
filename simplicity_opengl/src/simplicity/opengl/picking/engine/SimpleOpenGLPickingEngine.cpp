/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <log4cpp/Category.hh>

#include <simplicity/common/shared_equals_raw.h>

#include "../../rendering/SimpleOpenGLCamera.h"
#include "SimpleOpenGLPickingEngine.h"

using namespace boost;
using namespace std;

namespace simplicity
{
  namespace opengl
  {
    SimpleOpenGLPickingEngine::SimpleOpenGLPickingEngine()
    {
    }

    SimpleOpenGLPickingEngine::~SimpleOpenGLPickingEngine()
    {
    }

    void
    SimpleOpenGLPickingEngine::addEntities(std::vector<boost::shared_ptr<Entity> > entities)
    {
    }

    void
    SimpleOpenGLPickingEngine::addEntity(boost::shared_ptr<Entity> entity)
    {
    }

    void
    SimpleOpenGLPickingEngine::addPickListener(shared_ptr<PickListener> listener)
    {
      fListeners.push_back(listener);
    }

    shared_ptr<EngineInput>
    SimpleOpenGLPickingEngine::advance(const shared_ptr<EngineInput> input)
    {
      if (fPicks.empty())
      {
        return (shared_ptr<EngineInput> ());
      }

      if (fRenderingEngine.get())
      {
        if (fRenderingEngine->getScene().get())
        {
          fScene = fRenderingEngine->getScene();
        }

        if (fRenderingEngine->getCamera().get())
        {
          fCamera = fRenderingEngine->getCamera();
        }
      }

      fPicker->init();

      // For every pick.
      for (unsigned int index = 0; index < fPicks.size(); index++)
      {
        firePickEvent(fPicker->pickScene(*fScene, *fCamera, fPicks.at(index)));
      }

      fPicker->dispose();

      fPicks.clear();

      return (shared_ptr<EngineInput> ());
    }

    Pick
    SimpleOpenGLPickingEngine::convertPickCoordinatesFromViewportToSceneGraph(const float viewportWidth,
        const float viewportHeight, Pick pick) const
    {
      pick.height = pick.height / viewportHeight * (fCamera->getFrameWidth() * fCamera->getFrameAspectRatio());
      pick.width = pick.width / viewportWidth * fCamera->getFrameWidth();
      pick.x = pick.x / viewportWidth * fCamera->getFrameWidth();
      pick.y = pick.y / viewportHeight * (fCamera->getFrameWidth() * fCamera->getFrameAspectRatio());

      return (pick);
    }

    void
    SimpleOpenGLPickingEngine::destroy()
    {
    }

    void
    SimpleOpenGLPickingEngine::firePickEvent(PickEvent event) const
    {
      for (unsigned int index = 0; index < fListeners.size(); index++)
      {
        PickListener& listener = *fListeners.at(index);
        listener(event);
      }
    }

    shared_ptr<Camera>
    SimpleOpenGLPickingEngine::getCamera() const
    {
      return (fCamera);
    }

    shared_ptr<Picker>
    SimpleOpenGLPickingEngine::getPicker() const
    {
      return (fPicker);
    }

    vector<Pick>
    SimpleOpenGLPickingEngine::getPicks() const
    {
      return (fPicks);
    }

    /**
     * <p>
     * Retrieves the <code>RenderingEngine</code> who's <code>Scene</code> and <code>Camera</code> are used when picking.
     * </p>
     *
     * @return The <code>RenderingEngine</code> who's <code>Scene</code> and <code>Camera</code> are used when picking.
     */
    shared_ptr<RenderingEngine>
    SimpleOpenGLPickingEngine::getRenderingEngine() const
    {
      return (fRenderingEngine);
    }

    shared_ptr<Scene>
    SimpleOpenGLPickingEngine::getScene() const
    {
      return (fScene);
    }

    void
    SimpleOpenGLPickingEngine::init()
    {
    }

    void
    SimpleOpenGLPickingEngine::pick(const float x, const float y, const float width, const float height)
    {
      Pick pick;
      pick.x = x;
      pick.y = y;
      pick.width = width;
      pick.height = height;

      SimpleOpenGLPickingEngine::pick(pick);
    }

    void
    SimpleOpenGLPickingEngine::pick(const Pick pick)
    {
      fPicks.push_back(pick);
    }

    void
    SimpleOpenGLPickingEngine::pickViewport(const int viewportWidth, const int viewportHeight, const int x, const int y,
        const int width, const int height)
    {
      Pick pick;
      pick.x = x;
      pick.y = y;
      pick.width = width;
      pick.height = height;

      pickViewport(viewportWidth, viewportHeight, pick);
    }

    void
    SimpleOpenGLPickingEngine::pickViewport(const int viewportWidth, const int viewportHeight, const Pick pick)
    {
      fPicks.push_back(convertPickCoordinatesFromViewportToSceneGraph(viewportWidth, viewportHeight, pick));
    }

    void
    SimpleOpenGLPickingEngine::removePickListener(const PickListener& listener)
    {
      shared_equals_raw<PickListener> sharedEqualsRaw(&listener);
      fListeners.erase(find_if(fListeners.begin(), fListeners.end(), sharedEqualsRaw));
    }

    void
    SimpleOpenGLPickingEngine::reset()
    {
    }

    void
    SimpleOpenGLPickingEngine::setCamera(shared_ptr<Camera> camera)
    {
      fCamera = camera;
    }

    void
    SimpleOpenGLPickingEngine::setPicker(shared_ptr<Picker> picker)
    {
      fPicker = picker;
    }

    /**
     * <p>
     * Sets the <code>RenderingEngine</code> who's <code>Scene</code> and <code>Camera</code> are used when picking. The ability to set a
     * <code>RenderingEngine</code> is a convenience as in most cases picking will be associated with a particular rendered image. This
     * <code>SimpleJOGLPickingEngine</code> synchronises the <code>Scene</code> and <code>Camera</code> from the <code>RenderingEngine</code> every
     * time it advances if one is provided.
     * </p>
     *
     * @param renderingEngine The <code>RenderingEngine</code> who's <code>Scene</code> and <code>Camera</code> are used when picking.
     */
    void
    SimpleOpenGLPickingEngine::setRenderingEngine(shared_ptr<RenderingEngine> renderingEngine)
    {
      fRenderingEngine = renderingEngine;

      if (fRenderingEngine->getScene().get())
      {
        fScene = fRenderingEngine->getScene();
      }

      if (fRenderingEngine->getCamera().get())
      {
        fCamera = fRenderingEngine->getCamera();
      }
    }

    void
    SimpleOpenGLPickingEngine::setScene(shared_ptr<Scene> scene)
    {
      fScene = scene;
    }
  }
}
