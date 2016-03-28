/*      _                 _ _      _ _
 *     (_)               | (_)    (_) |
 *  ___ _ _ __ ___  _ __ | |_  ___ _| |_ _   _
 * / __| | '_ ` _ \| '_ \| | |/ __| | __| | | |
 * \__ \ | | | | | | |_) | | | (__| | |_| |_| |
 * |___/_|_| |_| |_| .__/|_|_|\___|_|\__|\__, |
 *                 | |                    __/ |
 *                 |_|                   |___/
 *
 * This file is part of simplicity. See the LICENSE file for the full license governing this code.
 */
#include <algorithm>

#include "../common/AddressEquals.h"
#include "ScriptingEngineState.h"

using namespace std;

namespace simplicity
{
	ScriptingEngineState::ScriptingEngineState() :
			entityIterator(),
			scriptsByEntity(),
			scriptIterator()
	{
	}

	Script* ScriptingEngineState::first()
	{
		entityIterator = scriptsByEntity.begin();
		if (entityIterator == scriptsByEntity.end())
		{
			return nullptr;
		}

		scriptIterator = entityIterator->second.begin();

		return *scriptIterator;
	}

	Script* ScriptingEngineState::next()
	{
		scriptIterator++;
		if (scriptIterator == entityIterator->second.end())
		{
			entityIterator++;
			if (entityIterator == scriptsByEntity.end())
			{
				return nullptr;
			}

			scriptIterator = entityIterator->second.begin();
		}

		return *scriptIterator;
	}

	void ScriptingEngineState::onAddComponent(Component& component)
	{
		Script* script = dynamic_cast<Script*>(&component);
		if (script != nullptr)
		{
			scriptsByEntity[script->getEntity()].insert(script);
		}
	}

	void ScriptingEngineState::onAddEntity(Entity& entity)
	{
		for (Script* script : entity.getComponents<Script>())
		{
			scriptsByEntity[&entity].insert(script);

			script->onAddEntity();
		}
	}

	void ScriptingEngineState::onRemoveComponent(Component& component)
	{
		Script* script = dynamic_cast<Script*>(&component);
		if (script != nullptr)
		{
			if (scriptsByEntity[script->getEntity()].find(script) == scriptIterator)
			{
				// Move to the script before the one being removed to avoid iterator invalidation.
				// The next call to next() will result in returning the script after the one being removed.
				if (scriptIterator == scriptsByEntity[script->getEntity()].begin())
				{
					entityIterator--;
					scriptIterator = --entityIterator->second.end();
				}
				else
				{
					scriptIterator--;
				}
			}

			scriptsByEntity[script->getEntity()].erase(script);
			if (scriptsByEntity[script->getEntity()].size() == 0)
			{
				if (scriptsByEntity.find(script->getEntity()) == entityIterator)
				{
					// Move to the last script of the entity before the one being removed to avoid iterator invalidation.
					// The next call to next() will result in returning the first entity after the one being removed.
					entityIterator--;
					scriptIterator = --entityIterator->second.end();
				}

				scriptsByEntity.erase(script->getEntity());
			}
		}
	}

	void ScriptingEngineState::onRemoveEntity(Entity& entity)
	{
		for (Script* script : scriptsByEntity[&entity])
		{
			script->onRemoveEntity();
		}

		if (scriptsByEntity.find(&entity) == entityIterator)
		{
			// Move to the last script of the entity before the one being removed to avoid iterator invalidation.
			// The next call to next() will result in returning the first entity after the one being removed.
			entityIterator--;
			scriptIterator = --entityIterator->second.end();
		}

		scriptsByEntity.erase(&entity);
	}

	void ScriptingEngineState::onTransformEntity(Entity& entity)
	{
	}
}
