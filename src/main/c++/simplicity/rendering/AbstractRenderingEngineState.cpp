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
#include <simplicity/model/Model.h>
#include "AbstractRenderingEngineState.h"

using namespace std;

namespace simplicity
{
	AbstractRenderingEngineState::AbstractRenderingEngineState() :
		modelsByBuffer()
	{
	}

	map<MeshBuffer*, set<Model*>>& AbstractRenderingEngineState::getModelsByBuffer()
	{
		return modelsByBuffer;
	}

	void AbstractRenderingEngineState::onAddComponent(Component& component)
	{
		Model* model = dynamic_cast<Model*>(&component);
		if (model != nullptr)
		{
			modelsByBuffer[model->getMesh()->getBuffer()].insert(model);
		}
	}

	void AbstractRenderingEngineState::onAddEntity(Entity& entity)
	{
		for (Component* component : entity.getComponents<Model>())
		{
			onAddComponent(*component);
		}
	}

	void AbstractRenderingEngineState::onRemoveComponent(Component& component)
	{
		Model* model = dynamic_cast<Model*>(&component);
		if (model != nullptr)
		{
			modelsByBuffer[model->getMesh()->getBuffer()].erase(model);
			if (modelsByBuffer[model->getMesh()->getBuffer()].size() == 0)
			{
				modelsByBuffer.erase(model->getMesh()->getBuffer());
			}
		}
	}

	void AbstractRenderingEngineState::onRemoveEntity(Entity& entity)
	{
		for (Component* component : entity.getComponents<Model>())
		{
			onRemoveComponent(*component);
		}
	}

	void AbstractRenderingEngineState::onTransformEntity(Entity& entity)
	{
	}
}
