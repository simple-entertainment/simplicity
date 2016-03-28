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
#include "SceneGraph.h"

namespace simplicity
{
	void SceneGraph::onAddComponent(Component& component)
	{
	}

	void SceneGraph::onAddEntity(Entity& entity)
	{
		insert(entity);
	}

	void SceneGraph::onRemoveComponent(Component& component)
	{
	}

	void SceneGraph::onRemoveEntity(Entity& entity)
	{
		remove(entity);
	}

	void SceneGraph::onTransformEntity(Entity& entity)
	{
		update(entity);
	}
}
