/*
 * Copyright © 2011 Simple Entertainment Limited
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

		void SimpleOpenGLPickingEngine::addEntities(std::vector<boost::shared_ptr<Entity> > entities)
		{
		}

		void SimpleOpenGLPickingEngine::addEntity(boost::shared_ptr<Entity> entity)
		{
		}

		void SimpleOpenGLPickingEngine::addPickListener(shared_ptr<PickListener> listener)
		{
			listeners.push_back(listener);
		}

		shared_ptr<EngineInput> SimpleOpenGLPickingEngine::advance(const shared_ptr<EngineInput> input)
		{
			if (picks.empty())
			{
				return (shared_ptr<EngineInput>());
			}

			if (renderingEngine.get())
			{
				if (renderingEngine->getScene().get())
				{
					scene = renderingEngine->getScene();
				}

				if (renderingEngine->getCamera().get())
				{
					camera = renderingEngine->getCamera();
				}
			}

			picker->init();

			// For every pick.
			for (unsigned int index = 0; index < picks.size(); index++)
			{
				firePickEvent(picker->pickScene(*scene, *camera, picks.at(index)));
			}

			picker->dispose();

			picks.clear();

			return shared_ptr<EngineInput>();
		}

		Pick SimpleOpenGLPickingEngine::convertPickCoordinatesFromViewportToSceneGraph(const float viewportWidth,
			const float viewportHeight, Pick pick) const
		{
			pick.height = pick.height / viewportHeight * (camera->getFrameWidth() * camera->getFrameAspectRatio());
			pick.width = pick.width / viewportWidth * camera->getFrameWidth();
			pick.x = pick.x / viewportWidth * camera->getFrameWidth();
			pick.y = pick.y / viewportHeight * (camera->getFrameWidth() * camera->getFrameAspectRatio());

			return pick;
		}

		void SimpleOpenGLPickingEngine::destroy()
		{
		}

		void SimpleOpenGLPickingEngine::firePickEvent(PickEvent event) const
		{
			for (unsigned int index = 0; index < listeners.size(); index++)
			{
				PickListener& listener = *listeners.at(index);
				listener(event);
			}
		}

		shared_ptr<Camera> SimpleOpenGLPickingEngine::getCamera() const
		{
			return camera;
		}

		shared_ptr<Picker> SimpleOpenGLPickingEngine::getPicker() const
		{
			return picker;
		}

		vector<Pick> SimpleOpenGLPickingEngine::getPicks() const
		{
			return picks;
		}

		shared_ptr<RenderingEngine> SimpleOpenGLPickingEngine::getRenderingEngine() const
		{
			return renderingEngine;
		}

		shared_ptr<Scene> SimpleOpenGLPickingEngine::getScene() const
		{
			return scene;
		}

		void SimpleOpenGLPickingEngine::onInit()
		{
		}

		void SimpleOpenGLPickingEngine::onReset()
		{
		}

		void SimpleOpenGLPickingEngine::pick(const float x, const float y, const float width, const float height)
		{
			Pick pick;
			pick.x = x;
			pick.y = y;
			pick.width = width;
			pick.height = height;

			SimpleOpenGLPickingEngine::pick(pick);
		}

		void SimpleOpenGLPickingEngine::pick(const Pick pick)
		{
			picks.push_back(pick);
		}

		void SimpleOpenGLPickingEngine::pickViewport(const int viewportWidth, const int viewportHeight, const int x,
			const int y, const int width, const int height)
		{
			Pick pick;
			pick.x = x;
			pick.y = y;
			pick.width = width;
			pick.height = height;

			pickViewport(viewportWidth, viewportHeight, pick);
		}

		void SimpleOpenGLPickingEngine::pickViewport(const int viewportWidth, const int viewportHeight, const Pick pick)
		{
			picks.push_back(convertPickCoordinatesFromViewportToSceneGraph(viewportWidth, viewportHeight, pick));
		}

		void SimpleOpenGLPickingEngine::removePickListener(const PickListener& listener)
		{
			shared_equals_raw<PickListener> sharedEqualsRaw(&listener);
			listeners.erase(find_if(listeners.begin(), listeners.end(), sharedEqualsRaw));
		}

		void SimpleOpenGLPickingEngine::setCamera(shared_ptr<Camera> camera)
		{
			this->camera = camera;
		}

		void SimpleOpenGLPickingEngine::setPicker(shared_ptr<Picker> picker)
		{
			this->picker = picker;
		}

		void SimpleOpenGLPickingEngine::setRenderingEngine(shared_ptr<RenderingEngine> renderingEngine)
		{
			this->renderingEngine = renderingEngine;

			if (renderingEngine->getScene().get())
			{
				scene = renderingEngine->getScene();
			}

			if (renderingEngine->getCamera().get())
			{
				camera = renderingEngine->getCamera();
			}
		}

		void SimpleOpenGLPickingEngine::setScene(shared_ptr<Scene> scene)
		{
			this->scene = scene;
		}
	}
}
