/*
 * Copyright © 2012 Simple Entertainment Limited
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
#ifndef RENDERINGENGINE_H_
#define RENDERINGENGINE_H_

#include <memory>

#include "../engine/Engine.h"
#include "../entity/Entity.h"
#include "../graph/Graph.h"
#include "Renderer.h"

namespace simplicity
{
	/**
	 * <p>
	 * An engine that renders a scene.
	 * </p>
	 */
	class SIMPLE_API RenderingEngine : public Engine
	{
		public:
			/**
			 * <p>
			 * Adds a light, allowing it to affect the rendering of the scene.
			 * </p>
			 *
			 * @param light An entity containg a light component.
			 */
			virtual void addLight(Entity& light) = 0;

			/**
			 * <p>
			 * Adss a renderer. Every renderer added acts as a rendering pass.
			 * </p>
			 *
			 * @param renderer The renderer.
			 */
			virtual void addRenderer(std::unique_ptr<Renderer> renderer) = 0;

			/**
			 * <p>
			 * Retrieves the camera through which the scene will be rendered.
			 * </p>
			 *
			 * @return The entity containing the camera component.
			 */
			virtual const Entity* getCamera() const = 0;

			/**
			 * <p>
			 * Retrieves the graph that will be searched to determine which models to render and in which order.
			 * </p>
			 *
			 * @return The graph.
			 */
			virtual const Graph* getGraph() const = 0;

			/**
			 * <p>
			 * Retrieves the height of the viewport.
			 * </p>
			 *
			 * @return The height of the viewport.
			 */
			virtual int getHeight() const = 0;

			/**
			 * <p>
			 * Retrieves the width of the viewport.
			 * </p>
			 *
			 * @return The width of the viewport.
			 */
			virtual int getWidth() const = 0;

			/**
			 * <p>
			 * Removes the specified renderer.
			 * </p>
			 *
			 * @param renderer The renderer.
			 *
			 * @return The removed renderer.
			 */
			virtual std::unique_ptr<Renderer> removeRenderer(Renderer* renderer) = 0;

			/**
			 * <p>
			 * Sets the camera through which the scene will be rendered.
			 * </p>
			 *
			 * @param camera The entity containing the camera component.
			 */
			virtual void setCamera(Entity* camera) = 0;

			/**
			 * <p>
			 * Sets the graph that will be searched to determine which models to render and in which order. Using the
			 * right graph for your scene can have a dramatic effect on performance. If no graph is specified, all the
			 * models in the scene will be sent to the GPU.
			 * </p>
			 *
			 * @return The graph.
			 */
			virtual void setGraph(Graph* graph) = 0;

			/**
			 * <p>
			 * Sets the height of the viewport.
			 * </p>
			 *
			 * @param height The height of the viewport.
			 */
			virtual void setHeight(int height) = 0;

			/**
			 * <p>
			 * Sets the graph that will be searched when rendering using a particular render. If this is not called for
			 * a particular renderer it will use the graph provided in setGraph(Graph*).
			 * </p>
			 *
			 * @param renderer
			 * @param root
			 */
			virtual void setRendererRoot(const Renderer& renderer, const Graph& root) = 0;

			/**
			 * <p>
			 * Sets the width of the viewport.
			 * </p>
			 *
			 * @param height The width of the viewport.
			 */
			virtual void setWidth(int width) = 0;
	};
}

#endif /* RENDERINGENGINE_H_ */
