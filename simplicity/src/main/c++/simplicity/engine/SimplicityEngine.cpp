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
#include <algorithm>

#include "../common/AddressEquals.h"
#include "../Events.h"
#include "../Messages.h"
#include "SimplicityEngine.h"
#include "EntityDoesNotExistException.h"

using namespace std;

namespace simplicity
{
	SimplicityEngine::SimplicityEngine() :
		engine(), entities(), newEntities(), scene()
	{
	}

	SimplicityEngine::~SimplicityEngine()
	{
	}

	void SimplicityEngine::addEntity(shared_ptr<Entity> entity)
	{
		newEntities.push_back(entity);

		Messages::send(ADD_ENTITY_EVENT, cref(*entity));
	}

	void SimplicityEngine::addEntity(shared_ptr<Entity> entity, shared_ptr<TreeNode> node)
	{
		addEntity(entity, node, scene->getTree().getRoot());
	}

	void SimplicityEngine::addEntity(shared_ptr<Entity> entity, shared_ptr<TreeNode> node, TreeNode& parent)
	{
		addEntity(entity);

		newNodes.insert(pair<shared_ptr<TreeNode>, reference_wrapper<TreeNode> >(node, parent));
		nodes.insert(pair<Entity*, reference_wrapper<TreeNode> >(entity.get(), *node));
	}

	shared_ptr<EngineInput> SimplicityEngine::advance(const shared_ptr<EngineInput> input)
	{
		for (shared_ptr<Entity> newEntity : newEntities)
		{
			entities.insert(pair<string, shared_ptr<Entity> >(newEntity->getName(), newEntity));
			engine->addEntity(newEntity);
		}
		newEntities.clear();

		for (pair<shared_ptr<TreeNode>, reference_wrapper<TreeNode> > newNode : newNodes)
		{
			scene->getTree().connect(newNode.second, scene->getTree().add(newNode.first));
		}
		newNodes.clear();

		return engine->advance(input);
	}

	void SimplicityEngine::destroy()
	{
		engine->destroy();
	}

	Engine* SimplicityEngine::getEngine() const
	{
		return engine.get();
	}

	Entity& SimplicityEngine::getEntity(const string name)
	{
		map<const string, shared_ptr<Entity> >::iterator entity = entities.find(name);

		if (entity == entities.end())
		{
			throw EntityDoesNotExistException();
		}

		return *entity->second;
	}

	Scene* SimplicityEngine::getScene() const
	{
		return scene.get();
	}

	void SimplicityEngine::onInit()
	{
		engine->init();
		setPreferredFrequency(engine->getPreferredFrequency());
	}

	void SimplicityEngine::onReset()
	{
		engine->reset();
		entities.clear();
		setPreferredFrequency(engine->getPreferredFrequency());
	}

	void SimplicityEngine::removeEntity(const Entity& entity)
	{
		Messages::send(REMOVE_ENTITY_EVENT, cref(entity));

		engine->removeEntity(entity);
		entities.erase(entity.getName());

		map<const Entity*, reference_wrapper<TreeNode> >::iterator node = nodes.find(&entity);
		if (node != nodes.end())
		{
			scene->getTree().remove(node->second.get());
			nodes.erase(node);
		}
	}

	void SimplicityEngine::removeEntity(const string& name)
	{
		removeEntity(*entities.find(name)->second);
	}

	void SimplicityEngine::setEngine(shared_ptr<Engine> engine)
	{
		this->engine = engine;
	}

	void SimplicityEngine::setScene(shared_ptr<Scene> scene)
	{
		this->scene = scene;
	}
}
