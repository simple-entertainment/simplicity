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
#ifndef SCRIPTINGENGINESTATE_H
#define SCRIPTINGENGINESTATE_H

#include <map>
#include <set>

#include "../scene/SceneState.h"
#include "../scripting/Script.h"

namespace simplicity
{
	class ScriptingEngineState : public SceneState
	{
		public:
			ScriptingEngineState();

			Script* first();

			Script* next();

			void onAddComponent(Component& component) override;

			void onAddEntity(Entity& entity) override;

			void onRemoveComponent(Component& component) override;

			void onRemoveEntity(Entity& entity) override;

			void onTransformEntity(Entity& entity) override;

		private:
			std::map<Entity*, std::set<Script*>>::iterator entityIterator;

			std::map<Entity*, std::set<Script*>> scriptsByEntity;

			std::set<Script*>::iterator scriptIterator;
	};
}

#endif /* SCRIPTINGENGINESTATE_H */
