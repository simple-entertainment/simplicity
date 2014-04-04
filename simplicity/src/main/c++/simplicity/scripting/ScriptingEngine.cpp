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
#include "ScriptingEngine.h"

using namespace std;

namespace simplicity
{
	ScriptingEngine::ScriptingEngine() :
		scriptsByEntity()
	{
	}

	void ScriptingEngine::advance()
	{
		for (pair<Entity*, vector<Script*>> entityScripts : scriptsByEntity)
		{
			for (Script* script : entityScripts.second)
			{
				script->execute(*entityScripts.first);
			}
		}
	}

	void ScriptingEngine::onAddEntity(Entity& entity)
	{
		scriptsByEntity[&entity] = entity.getComponents<Script>();

		for (Script* script : scriptsByEntity[&entity])
		{
			script->onAddEntity(entity);
		}
	}

	void ScriptingEngine::onCloseScene(Scene& scene)
	{
		for (pair<Entity*, vector<Script*>> entityScripts : scriptsByEntity)
		{
			for (Script* script : entityScripts.second)
			{
				script->onCloseScene(scene, *entityScripts.first);
			}
		}
	}

	void ScriptingEngine::onOpenScene(Scene& scene)
	{
		for (pair<Entity*, vector<Script*>> entityScripts : scriptsByEntity)
		{
			for (Script* script : entityScripts.second)
			{
				script->onOpenScene(scene, *entityScripts.first);
			}
		}
	}

	void ScriptingEngine::onPauseScene(Scene& scene)
	{
		for (pair<Entity*, vector<Script*>> entityScripts : scriptsByEntity)
		{
			for (Script* script : entityScripts.second)
			{
				script->onPauseScene(scene, *entityScripts.first);
			}
		}
	}

	void ScriptingEngine::onRemoveEntity(Entity& entity)
	{
		for (Script* script : scriptsByEntity[&entity])
		{
			script->onRemoveEntity(entity);
		}

		scriptsByEntity.erase(&entity);
	}

	void ScriptingEngine::onResumeScene(Scene& scene)
	{
		for (pair<Entity*, vector<Script*>> entityScripts : scriptsByEntity)
		{
			for (Script* script : entityScripts.second)
			{
				script->onResumeScene(scene, *entityScripts.first);
			}
		}
	}
}
