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
#include <algorithm>

#include <simplicity/common/AddressEquals.h>
#include <simplicity/math/Intersection.h>
#include <simplicity/math/MathFunctions.h>
#include <simplicity/rendering/Camera.h>
#include <simplicity/rendering/Light.h>
#include <simplicity/Simplicity.h>

#include "AbstractRenderingEngine.h"

using namespace std;

namespace simplicity
{
	AbstractRenderingEngine::AbstractRenderingEngine() :
		camera(nullptr),
		entitiesByModel(),
		graph(nullptr),
		height(768),
		lights(),
		modelsByBuffer(),
		renderers(),
		width(1024)
	{
	}

	void AbstractRenderingEngine::addLight(Entity& light)
	{
		lights.push_back(&light);
	}

	void AbstractRenderingEngine::addRenderer(unique_ptr<Renderer> renderer)
	{
		renderers.push_back(move(renderer));
	}

	void AbstractRenderingEngine::advance()
	{
		if (!preAdvance())
		{
			return;
		}

		CameraProperties cameraProperties = getCameraProperties();

		// TODO This is currently ignored...
		std::vector<Entity*> entities;
		if (cameraProperties.bounds == nullptr || graph == nullptr)
		{
			entities = Simplicity::getScene()->getEntities();
		}
		else
		{
			entities =
				graph->getEntitiesWithinBounds(*cameraProperties.bounds,
				cameraProperties.boundsPosition);
		}

		for (unique_ptr<Renderer>& renderer : renderers)
		{
			renderer->init();

			renderer->getDefaultPipeline()->apply();
			renderer->getDefaultPipeline()->set("cameraPosition", cameraProperties.position);
			renderer->getDefaultPipeline()->set("cameraTransform", cameraProperties.transform);

			for (unsigned int index = 0; index < lights.size(); index++)
			{
				lights[index]->getComponent<Light>()->apply(*renderer->getDefaultPipeline(),
						getPosition3(lights[index]->getTransform()));
			}

			int bufferCount = modelsByBuffer.size();
			for (pair<MeshBuffer* const, set<Mesh*>>& bufferAndModels : modelsByBuffer)
			{
				bind(*bufferAndModels.first);

				int modelCount = bufferAndModels.second.size();
				for (Mesh* model : bufferAndModels.second)
				{
					int entityCount = entitiesByModel[model].size();
					for (Entity* entity : entitiesByModel[model])
					{
						renderer->getDefaultPipeline()->set("worldTransform", entity->getTransform() *
								model->getTransform());

						renderer->render(*model);
					}
				}
			}

			renderer->dispose();
		}

		postAdvance();
	}

	Entity* AbstractRenderingEngine::getCamera() const
	{
		return camera;
	}

	AbstractRenderingEngine::CameraProperties AbstractRenderingEngine::getCameraProperties() const
	{
		CameraProperties properties;
		properties.bounds = nullptr;

		if (camera == nullptr)
		{
			properties.position = Vector3(0.0f, 0.0f, 0.0f);
			properties.transform.setIdentity();
		}
		else
		{
			properties.bounds = camera->getComponent<Model>(Category::BOUNDS);
			if (properties.bounds != nullptr)
			{
				properties.boundsPosition = getPosition3(camera->getTransform() *
						properties.bounds->getTransform());
			}

			Camera* cameraComponent = camera->getComponent<Camera>();
			if (cameraComponent != nullptr)
			{
				Matrix44 view = camera->getTransform() * cameraComponent->getTransform();
				properties.position = getPosition3(view);
				view.invert();

				Matrix44 projection = cameraComponent->getProjection();

				properties.transform = projection * view;
			}
		}

		return properties;
	}

	const Graph* AbstractRenderingEngine::getGraph() const
	{
		return graph;
	}

	int AbstractRenderingEngine::getHeight() const
	{
		return height;
	}

	int AbstractRenderingEngine::getWidth() const
	{
		return width;
	}

	void AbstractRenderingEngine::onAddEntity(Entity& entity)
	{
		for (Mesh* model : entity.getComponents<Mesh>(Category::RENDER))
		{
			entitiesByModel[model].insert(&entity);
			modelsByBuffer[model->getBuffer()].insert(model);
		}
	}

	void AbstractRenderingEngine::onPlay()
	{
		init();
	}

	void AbstractRenderingEngine::onStop()
	{
		dispose();
	}

	unique_ptr<Renderer> AbstractRenderingEngine::removeRenderer(Renderer* renderer)
	{
		unique_ptr<Renderer> removedRenderer;

		vector<unique_ptr<Renderer>>::iterator result =
				find_if(renderers.begin(), renderers.end(), AddressEquals<Renderer>(*renderer));
		if (result != renderers.end())
		{
			removedRenderer = move(*result);
			renderers.erase(result);
			renderer = nullptr;
		}

		return move(removedRenderer);
	}

	void AbstractRenderingEngine::setCamera(Entity* camera)
	{
		this->camera = camera;
	}

	void AbstractRenderingEngine::setGraph(Graph* graph)
	{
		this->graph = graph;
	}

	void AbstractRenderingEngine::setHeight(int height)
	{
		this->height = height;
	}

	void AbstractRenderingEngine::setWidth(int width)
	{
		this->width = width;
	}
}
