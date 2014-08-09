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

		std::set<Entity*> entities;
		if (cameraProperties.bounds != nullptr && graph != nullptr)
		{
			std::vector<Entity*> entityVector =
				graph->getEntitiesWithinBounds(*cameraProperties.bounds,
				cameraProperties.boundsPosition);

			entities.insert(entityVector.begin(), entityVector.end());
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

			for (pair<MeshBuffer* const, set<Model*>>& bufferAndModels : modelsByBuffer)
			{
				vector<pair<Model*, Matrix44>> modelsAndTransforms;
				modelsAndTransforms.reserve(bufferAndModels.second.size());

				for (Model* model : bufferAndModels.second)
				{
					for (Entity* entity : entitiesByModel[model])
					{
						if (entities.empty() || entities.find(entity) != entities.end())
						{
							modelsAndTransforms.push_back(pair<Model*, Matrix44>(model, entity->getTransform() *
									model->getTransform()));
						}
					}
				}

				renderer->render(*bufferAndModels.first, modelsAndTransforms);
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
		// TODO Support all model types?
		for (Mesh* mesh : entity.getComponents<Mesh>(Category::RENDER))
		{
			entitiesByModel[mesh].insert(&entity);
			modelsByBuffer[mesh->getBuffer()].insert(mesh);
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
