/*
 * Copyright © 2011 Simple Entertainment Limited
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
#ifndef SIMPLEOPENGLPICKINGENGINE_H_
#define SIMPLEOPENGLPICKINGENGINE_H_

#include <simplicity/engine/RunnableEngine.h>
#include <simplicity/picking/engine/PickingEngine.h>
#include <simplicity/rendering/engine/RenderingEngine.h>

namespace simplicity
{
	namespace opengl
	{
		/**
		 * <p>
		 * Manages the picking of a {@link simplicity::Scene Scene} in a OpenGL environment. This implementation uses
		 * only simple picking techniques and properties.
		 * </p>
		 *
		 * @author Gary Buyn
		 */
		class SimpleOpenGLPickingEngine : public RunnableEngine, public PickingEngine
		{
			public:
				/**
				 * <p>
				 * Creates an instance of <code>SimpleOpenGLPickingEngine</code>.
				 * </p>
				 */
				SimpleOpenGLPickingEngine();

				/**
				 * <p>
				 * Disposes of an instance of <code>SimpleOpenGLPickingEngine</code>.
				 * </p>
				 */
				virtual ~SimpleOpenGLPickingEngine();

				void addEntities(std::vector<boost::shared_ptr<Entity> > entities);

				void addEntity(boost::shared_ptr<Entity> entity);

				void addPickListener(boost::shared_ptr<PickListener> listener);

				boost::shared_ptr<EngineInput> advance(const boost::shared_ptr<EngineInput> input);

				void destroy();

				void firePickEvent(PickEvent event) const;

				boost::shared_ptr<Camera> getCamera() const;

				boost::shared_ptr<Picker> getPicker() const;

				std::vector<Pick> getPicks() const;

				/**
				 * <p>
				 * Retrieves the <code>RenderingEngine</code> who's <code>Scene</code> and <code>Camera</code> are used
				 * when picking.
				 * </p>
				 *
				 * @return The <code>RenderingEngine</code> who's <code>Scene</code> and <code>Camera</code> are used
				 * when picking.
				 */
				boost::shared_ptr<RenderingEngine> getRenderingEngine() const;

				boost::shared_ptr<Scene> getScene() const;

				void pick(const float x, const float y, const float width, const float height);

				void pick(const Pick pick);

				void pickViewport(const int viewportWidth, const int viewportHeight, const int x, const int y,
					const int width, const int height);

				void pickViewport(const int viewportWidth, const int viewportHeight, const Pick pick);

				void removePickListener(const PickListener& listener);

				void setCamera(boost::shared_ptr<Camera> camera);

				void setPicker(boost::shared_ptr<Picker> picker);

				/**
				 * <p>
				 * Sets the <code>RenderingEngine</code> who's <code>Scene</code> and <code>Camera</code> are used when
				 * picking. The ability to set a <code>RenderingEngine</code> is a convenience as in most cases picking
				 * will be associated with a particular rendered image. This <code>SimpleJOGLPickingEngine</code>
				 * synchronises the <code>Scene</code> and <code>Camera</code> from the <code>RenderingEngine</code>
				 * every time it advances if one is provided.
				 * </p>
				 *
				 * @param renderingEngine The <code>RenderingEngine</code> who's <code>Scene</code> and
				 * <code>Camera</code> are used when picking.
				 */
				void setRenderingEngine(boost::shared_ptr<RenderingEngine> renderingEngine);

				void setScene(boost::shared_ptr<Scene> scene);

			private:
				/**
				 * The viewpoint that will be adapted to create the picking viewpoint.
				 */
				boost::shared_ptr<Camera> camera;

				/**
				 * <p>
				 * The <code>PickListener</code>s to be invoked when a <code>Scene</code> is picked.
				 * </p>
				 */
				std::vector<boost::shared_ptr<PickListener> > listeners;

				/**
				 * <p>
				 * The <code>Picker</code> that picks the <code>Scene</code> for this
				 * <code>SimpleJOGLPickingEngine</code>.
				 * </p>
				 */
				boost::shared_ptr<Picker> picker;

				/**
				 * <p>
				 * The outstanding picks to be performed against a <code>Scene</code>.
				 * </p>
				 */
				std::vector<Pick> picks;

				/**
				 * <p>
				 * A <code>RenderingEngine</code> who's <code>Scene</code> and <code>Camera</code> are used when
				 * picking.
				 * </p>
				 */
				boost::shared_ptr<RenderingEngine> renderingEngine;

				/**
				 * The <code>Scene</code> to pick.
				 */
				boost::shared_ptr<Scene> scene;

				/**
				 * <p>
				 * Converts the coordinates of the given <code>Pick</code> from viewport coordinates to
				 * <code>Scene</code> coordinates.
				 * </p>
				 *
				 * @param viewportWidth The width of the viewport from which the original coordinates were retrieved.
				 * @param viewportHeight The height of the viewport from which the original coordinates were retrieved.
				 * @param pick The <code>Pick</code> to convert the coordinates of.
				 *
				 * @return A <code>Pick</code> with <code>Scene</code> coordinates.
				 */
				Pick convertPickCoordinatesFromViewportToSceneGraph(const float viewportWidth,
					const float viewportHeight, Pick pick) const;

				void onInit();

				void onReset();
		};
	}
}

#endif /* SIMPLEOPENGLPICKINGENGINE_H_ */
