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
		height(600),
		lights(),
		modelsByBuffer(),
		pipeline(nullptr),
		width(800)
	{
	}

	void AbstractRenderingEngine::addLight(Entity& light)
	{
		lights.push_back(&light);
	}

	void AbstractRenderingEngine::advance()
	{
		if (!preAdvance())
		{
			return;
		}

		CameraProperties cameraProperties = getCameraProperties();

		set<Entity*> entities;
		if (cameraProperties.bounds != nullptr && graph != nullptr)
		{
			vector<Entity*> entityVector =
				graph->getEntitiesWithinBounds(*cameraProperties.bounds,
				cameraProperties.boundsPosition);

			entities.insert(entityVector.begin(), entityVector.end());
		}

		for (pair<MeshBuffer* const, set<Model*>>& bufferAndModels : modelsByBuffer)
		{
			Pipeline* pipeline = bufferAndModels.first->getPipeline();
			if (pipeline == nullptr)
			{
				pipeline = getDefaultPipeline();
			}

			applyPipeline(*pipeline, cameraProperties);

			render(entities, *bufferAndModels.first, *pipeline, bufferAndModels.second, false);
		}

		for (pair<MeshBuffer* const, set<Model*>>& bufferAndModels : modelsByBuffer)
		{
			Pipeline* pipeline = bufferAndModels.first->getPipeline();
			if (pipeline == nullptr)
			{
				pipeline = getDefaultPipeline();
			}

			applyPipeline(*pipeline, cameraProperties);

			render(entities, *bufferAndModels.first, *pipeline, bufferAndModels.second, true);
		}

		postAdvance();
	}

	void AbstractRenderingEngine::applyPipeline(Pipeline& pipeline, const CameraProperties& cameraProperties)
	{
		pipeline.apply();

		for (Entity* light : lights)
		{
			light->getComponent<Light>()->apply(pipeline, getPosition3(light->getTransform()));
		}

		pipeline.set("cameraPosition", cameraProperties.position);
		pipeline.set("cameraTransform", cameraProperties.transform);
	}

	Entity* AbstractRenderingEngine::getCamera() const
	{
		return camera;
	}

	AbstractRenderingEngine::CameraProperties AbstractRenderingEngine::getCameraProperties() const
	{
		CameraProperties properties;

		if (camera == nullptr)
		{
			properties.bounds = nullptr;
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

	Pipeline* AbstractRenderingEngine::getDefaultPipeline()
	{
		return pipeline.get();
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

	void AbstractRenderingEngine::render(const set<Entity*>& entities, const MeshBuffer& buffer, Pipeline& pipeline,
										 const set<Model*>& models, bool withTransparency)
	{
		vector<pair<Model*, Matrix44>> modelsAndTransforms;
		modelsAndTransforms.reserve(models.size());

		for (Model* model : models)
		{
			bool modelHasTransparency =
					model->getTexture() != nullptr && hasTransparency(model->getTexture()->getPixelFormat());
			if (withTransparency != modelHasTransparency)
			{
				continue;
			}

			for (Entity* entity : entitiesByModel[model])
			{
				if (entities.empty() || entities.find(entity) != entities.end())
				{
					modelsAndTransforms.push_back(pair<Model*, Matrix44>(model, entity->getTransform() *
																				model->getTransform()));
				}
			}
		}

		render(buffer, pipeline, modelsAndTransforms);
	}

	void AbstractRenderingEngine::setCamera(Entity* camera)
	{
		this->camera = camera;
	}

	void AbstractRenderingEngine::setDefaultPipeline(shared_ptr<Pipeline> pipeline)
	{
		this->pipeline = pipeline;
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
