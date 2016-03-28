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
#include <simplicity/model/Mesh.h>
#include "AbstractRenderingEngineState.h"

using namespace std;

namespace simplicity
{
	AbstractRenderingEngineState::AbstractRenderingEngineState() :
		meshesByBuffer()
	{
	}

	map<MeshBuffer*, set<Mesh*>>& AbstractRenderingEngineState::getMeshesByBuffer()
	{
		return meshesByBuffer;
	}

	void AbstractRenderingEngineState::onAddComponent(Component& component)
	{
		Mesh* mesh = dynamic_cast<Mesh*>(&component);
		if (mesh != nullptr)
		{
			meshesByBuffer[mesh->getBuffer()].insert(mesh);
		}
	}

	void AbstractRenderingEngineState::onAddEntity(Entity& entity)
	{
		for (Component* component : entity.getComponents<>(Category::RENDER))
		{
			onAddComponent(*component);
		}
	}

	void AbstractRenderingEngineState::onRemoveComponent(Component& component)
	{
		Mesh* mesh = dynamic_cast<Mesh*>(&component);
		if (mesh != nullptr)
		{
			meshesByBuffer[mesh->getBuffer()].erase(mesh);
			if (meshesByBuffer[mesh->getBuffer()].size() == 0)
			{
				meshesByBuffer.erase(mesh->getBuffer());
			}
		}
	}

	void AbstractRenderingEngineState::onRemoveEntity(Entity& entity)
	{
		for (Component* component : entity.getComponents<>(Category::RENDER))
		{
			onRemoveComponent(*component);
		}
	}

	void AbstractRenderingEngineState::onTransformEntity(Entity& entity)
	{
	}
}
