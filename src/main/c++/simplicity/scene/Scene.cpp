/*
 * Copyright © 2014 Simple Entertainment Limited
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
#include "../common/AddressEquals.h"
#include "../input/MouseButtonEvent.h"
#include "../messaging/Messages.h"
#include "../messaging/Subject.h"
#include "../Simplicity.h"
#include "../windowing/WindowEngine.h"
#include "Scene.h"

using namespace std;

namespace simplicity
{
	Scene::Scene() :
			entities(),
			isOpen(false),
			mouseCaptureEnabled(true),
			state(),
			windowEngine(nullptr)
	{
	}

	void Scene::addEntity(unique_ptr<Entity> entity)
	{
		entity->setScene(this);
		entities.push_back(move(entity));

		if (isOpen)
		{
			for (unique_ptr<SceneState>& singleState : state)
			{
				singleState->onAddEntity(*entities.back());
			}
		}
	}

	void Scene::addState(unique_ptr<SceneState> state)
	{
		this->state.push_back(move(state));
	}

	bool Scene::capturesMouse()
	{
		return mouseCaptureEnabled;
	}

	Entity* Scene::getEntity(const std::string& name)
	{
		for (unique_ptr<Entity>& entity : entities)
		{
			if (entity->getName() == name)
			{
				return entity.get();
			}
		}

		return nullptr;
	}

    vector<Entity*> Scene::getEntities(unsigned short category)
	{
    	vector<Entity*> rawEntities;

    	for (unsigned int index = 0; index < entities.size(); index++)
    	{
			if (category == Category::ALL_CATEGORIES || entities[index]->getCategory() == category)
    		{
    			rawEntities.push_back(entities[index].get());
    		}
    	}

    	return rawEntities;
	}

	void Scene::onAddComponent(Component& component)
	{
		for (unique_ptr<SceneState>& singleState : state)
		{
			singleState->onAddComponent(component);
		}
	}

	bool Scene::onMouseButton(const Message& message)
	{
		const MouseButtonEvent* event = static_cast<const MouseButtonEvent*>(message.body);
		if (event->button == Mouse::Button::LEFT && event->buttonState == Button::State::UP)
		{
			if (!windowEngine->isMouseCaptured())
			{
				windowEngine->captureMouse();
			}
		}

		return false;
	}

	void Scene::onRemoveComponent(Component& component)
	{
		for (unique_ptr<SceneState>& singleState : state)
		{
			singleState->onRemoveComponent(component);
		}
	}

	void Scene::onTransformEntity(Entity& entity)
	{
		for (unique_ptr<SceneState>& singleState : state)
		{
			singleState->onTransformEntity(entity);
		}
	}

	void Scene::open()
	{
		isOpen = true;

		for (unique_ptr<Entity>& entity : entities)
		{
			for (unique_ptr<SceneState>& singleState : state)
			{
				singleState->onAddEntity(*entity);
			}
		}
	}

	void Scene::pause()
	{
		if (mouseCaptureEnabled && windowEngine != nullptr)
		{
			windowEngine->releaseMouse();
			Messages::deregisterRecipient(Subject::MOUSE_BUTTON, bind(&Scene::onMouseButton, this, placeholders::_1));
		}
	}

	unique_ptr<Entity> Scene::removeEntity(Entity& entity)
	{
		unique_ptr<Entity> removedEntity;
		vector<unique_ptr<Entity>>::iterator result =
				find_if(entities.begin(), entities.end(), AddressEquals<Entity>(entity));

		if (result != entities.end())
		{
			for (unique_ptr<SceneState>& singleState : state)
			{
				singleState->onRemoveEntity(entity);
			}

			removedEntity = move(*result);
			removedEntity->setScene(nullptr);
			entities.erase(result);
		}

		return move(removedEntity);
	}

	unique_ptr<SceneState> Scene::removeState(SceneState& state)
	{
		unique_ptr<SceneState> removedState;
		vector<unique_ptr<SceneState>>::iterator result =
				find_if(this->state.begin(), this->state.end(), AddressEquals<SceneState>(state));

		if (result != this->state.end())
		{
			removedState = move(*result);
			this->state.erase(result);
		}

		return move(removedState);
	}

	void Scene::resume()
	{
		windowEngine = Simplicity::getEngine<WindowEngine>();
		if (mouseCaptureEnabled && windowEngine != nullptr)
		{
			windowEngine->captureMouse();
			Messages::registerRecipient(Subject::MOUSE_BUTTON, bind(&Scene::onMouseButton, this, placeholders::_1));
		}
	}

	void Scene::setCapturesMouse(bool capturesMouse)
	{
		mouseCaptureEnabled = capturesMouse;
	}
}
