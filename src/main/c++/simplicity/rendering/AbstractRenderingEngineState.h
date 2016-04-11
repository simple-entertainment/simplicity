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
#ifndef ABSTRACTRENDERINGENGINESTATE_H
#define ABSTRACTRENDERINGENGINESTATE_H

#include <map>
#include <set>

#include "../scene/SceneState.h"
#include "../model/Model.h"

namespace simplicity
{
	class AbstractRenderingEngineState : public SceneState
	{
		public:
			AbstractRenderingEngineState();

			std::map<MeshBuffer*, std::set<Model*>>& getModelsByBuffer();

			void onAddComponent(Component& component) override;

			void onAddEntity(Entity& entity) override;

			void onRemoveComponent(Component& component) override;

			void onRemoveEntity(Entity& entity) override;

			void onTransformEntity(Entity& entity) override;

		private:
			std::map<MeshBuffer*, std::set<Model*>> modelsByBuffer;
	};
}

#endif /* ABSTRACTRENDERINGENGINESTATE_H */
