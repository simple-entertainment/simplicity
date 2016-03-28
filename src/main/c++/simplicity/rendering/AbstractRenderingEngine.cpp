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
		graph(nullptr),
		height(600),
		lights(),
		pipeline(nullptr),
		state(),
		width(800)
	{
	}

	void AbstractRenderingEngine::addLight(Entity& light)
	{
		lights.push_back(&light);
	}

	void AbstractRenderingEngine::advance(Scene& scene)
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

		list<RenderList> renderLists = buildRenderLists(scene, entities);

		for (RenderList& renderList : renderLists)
		{
			applyPipeline(*renderList.pipeline, cameraProperties);
			render(renderList);
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

	list<AbstractRenderingEngine::RenderList> AbstractRenderingEngine::buildRenderLists(Scene& scene,
																						const set<Entity*>& entities)
	{
		list<RenderList> renderLists;
		AbstractRenderingEngineState* state = this->state[&scene];

		for (pair<MeshBuffer*, set<Mesh*>> bufferAndMeshes : state->getMeshesByBuffer())
		{
			RenderList withoutTransparency;
			withoutTransparency.buffer = bufferAndMeshes.first;
			RenderList withTransparency;
			withTransparency.buffer = bufferAndMeshes.first;

			Pipeline* pipeline = bufferAndMeshes.first->getPipeline();
			if (pipeline == nullptr)
			{
				pipeline = getDefaultPipeline();
			}
			withoutTransparency.pipeline = pipeline;
			withTransparency.pipeline = pipeline;

			for (Mesh* mesh : bufferAndMeshes.second)
			{
				bool modelHasTransparency =
						mesh->getTexture() != nullptr &&
						hasTransparency(mesh->getTexture()->getPixelFormat());

				Entity* entity = mesh->getEntity();
				if (!entities.empty() && entities.find(entity) == entities.end())
				{
					continue;
				}

				if (modelHasTransparency)
				{
					withTransparency.list.emplace_back(pair<Model*, Matrix44>(mesh, entity->getTransform() *
																					mesh->getTransform()));
				}
				else
				{
					withoutTransparency.list.emplace_back(pair<Model*, Matrix44>(mesh, entity->getTransform() *
																					   mesh->getTransform()));
				}
			}

			// Render transparent models last.
			if (!withoutTransparency.list.empty())
			{
				renderLists.push_front(withoutTransparency);
			}
			if (!withTransparency.list.empty())
			{
				renderLists.push_back(withTransparency);
			}
		}

		return renderLists;
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

	const SceneGraph* AbstractRenderingEngine::getGraph() const
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

	void AbstractRenderingEngine::onBeforeOpenScene(Scene& scene)
	{
		unique_ptr<AbstractRenderingEngineState> state(new AbstractRenderingEngineState);

		this->state[&scene] = state.get();
		scene.addState(move(state));
	}

	void AbstractRenderingEngine::onCloseScene(Scene& scene)
	{
		scene.removeState(*this->state[&scene]);
	}

	void AbstractRenderingEngine::onPlay()
	{
		init();
	}

	void AbstractRenderingEngine::onStop()
	{
		dispose();
	}

	void AbstractRenderingEngine::setCamera(Entity* camera)
	{
		this->camera = camera;
	}

	void AbstractRenderingEngine::setDefaultPipeline(shared_ptr<Pipeline> pipeline)
	{
		this->pipeline = pipeline;
	}

	void AbstractRenderingEngine::setGraph(SceneGraph* graph)
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
