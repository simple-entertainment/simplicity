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
#include "../Entity.h"
#include "../graph/Graph.h"
#include "../scene/Light.h"
#include "Renderer.h"

namespace simplicity
{
	class RenderingEngine : public Engine
	{
		public:
			virtual void addLight(Entity& light) = 0;

			virtual void addRenderer(std::unique_ptr<Renderer> renderer) = 0;

			virtual const Entity* getCamera() const = 0;

			virtual const Graph* getGraph() const = 0;

			virtual int getHeight() const = 0;

			virtual int getWidth() const = 0;

			virtual void removeRenderer(const Renderer& renderer) = 0;

			virtual void setCamera(Entity* camera) = 0;

			virtual void setGraph(Graph* graph) = 0;

			virtual void setHeight(int height) = 0;

			virtual void setRendererRoot(const Renderer& renderer, const Graph& root) = 0;

			virtual void setWidth(int width) = 0;
	};
}

#endif /* RENDERINGENGINE_H_ */
