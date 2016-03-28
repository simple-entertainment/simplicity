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
#include "../Simplicity.h"
#include "ScriptingEngine.h"

using namespace std;

namespace simplicity
{
	ScriptingEngine::ScriptingEngine() :
		state()
	{
	}

	void ScriptingEngine::advance(Scene& scene)
	{
		ScriptingEngineState* state = this->state[&scene];

		for (Script* script = state->first(); script != nullptr; script = state->next())
		{
			script->execute();
		}
	}

	void ScriptingEngine::onBeforeOpenScene(Scene& scene)
	{
		unique_ptr<ScriptingEngineState> state(new ScriptingEngineState);

		this->state[&scene] = state.get();
		scene.addState(move(state));
	}

	void ScriptingEngine::onCloseScene(Scene& scene)
	{
		ScriptingEngineState* state = this->state[&scene];

		for (Script* script = state->first(); script != nullptr; script = state->next())
		{
			script->onCloseScene();
		}

		scene.removeState(*state);
	}

	void ScriptingEngine::onOpenScene(Scene& scene)
	{
		ScriptingEngineState* state = this->state[&scene];

		for (Script* script = state->first(); script != nullptr; script = state->next())
		{
			script->onOpenScene();
		}
	}

	void ScriptingEngine::onPauseScene(Scene& scene)
	{
		ScriptingEngineState* state = this->state[&scene];

		for (Script* script = state->first(); script != nullptr; script = state->next())
		{
			script->onPauseScene();
		}
	}

	void ScriptingEngine::onResumeScene(Scene& scene)
	{
		ScriptingEngineState* state = this->state[&scene];

		for (Script* script = state->first(); script != nullptr; script = state->next())
		{
			script->onResumeScene();
		}
	}
}
