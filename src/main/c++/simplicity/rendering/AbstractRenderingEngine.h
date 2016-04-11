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
#ifndef ABSTRACTRENDERINGENGINE_H_
#define ABSTRACTRENDERINGENGINE_H_

#include <list>

#include "../model/MeshBuffer.h"
#include "../model/Model.h"
#include "../rendering/RenderingEngine.h"
#include "AbstractRenderingEngineState.h"

namespace simplicity
{
	/**
	 * <p>
	 * A rendering engine that performs a rendering API agnostic rendering algorithm. It needs to be extended to add
	 * rendering API specific commands.
	 * </p>
	 */
	class SIMPLE_API AbstractRenderingEngine : public RenderingEngine
	{
		public:
			AbstractRenderingEngine();

			void addLight(Entity& light) override;

			void advance(Scene& scene) override;

			Entity* getCamera() const override;

			Pipeline* getDefaultPipeline() override;

			const SceneGraph* getGraph() const override;

			int getHeight() const override;

			int getWidth() const override;

			void onBeforeOpenScene(Scene& scene) override;

			void onCloseScene(Scene& scene) override;

			void onPlay() override;

			void onStop() override;

			void setCamera(Entity* camera) override;

			void setDefaultPipeline(std::shared_ptr<Pipeline> pipeline) override;

			void setGraph(SceneGraph* graph) override;

			void setHeight(int height) override;

			void setWidth(int width) override;

		protected:
			struct RenderList
			{
				MeshBuffer* buffer;
				std::list<std::pair<Model*, Matrix44>> list;
				Pipeline* pipeline;
			};

		private:
			struct CameraProperties
			{
				Shape* bounds;
				Vector3 position;
				Matrix44 transform;
			};

			Entity* camera;

			SceneGraph* graph;

			int height;

			std::vector<Entity*> lights;

			std::shared_ptr<Pipeline> pipeline;

			std::map<Scene*, AbstractRenderingEngineState*> state;

			int width;

			void applyPipeline(Pipeline& pipeline, const CameraProperties& cameraProperties);

			std::list<RenderList> buildRenderLists(Scene& scene, const std::set<Entity*>& entities);

			virtual void dispose() = 0;

			CameraProperties getCameraProperties() const;

			virtual void init() = 0;

			virtual void postAdvance() = 0;

			virtual bool preAdvance() = 0;

			virtual void render(const RenderList& renderList) = 0;
	};
}

#endif /* ABSTRACTRENDERINGENGINE_H_ */
