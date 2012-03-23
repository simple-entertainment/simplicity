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
#ifndef PICKINGENGINE_H_
#define PICKINGENGINE_H_

#include "../../engine/Engine.h"
#include "../PickEvent.h"
#include "../Picker.h"
#include "../../rendering/Camera.h"

namespace simplicity
{
	/**
	 * <p>
	 * Manages the picking of a {@link simplicity::Scene Scene}. Each advance processes the outstanding
	 * {@link simplicity::Pick Pick}s, the results are fired to any {@link simplicity::PickListener PickListener}s in
	 * the form of a {@link simplicity::PickEvent PickEvent}.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class PickingEngine : public virtual Engine
	{
		public:
			/**
			 * <p>
			 * Performs the outstanding picks against a {@link simplicity::Scene Scene}.
			 * </p>
			 */
			virtual std::shared_ptr<EngineInput> advance(const std::shared_ptr<EngineInput> input) = 0;

			/**
			 * <p>
			 * Retrieves the viewpoint that will be adapted to create the picking viewpoint.
			 * </p>
			 *
			 * @return The viewpoint that will be adapted to create the picking viewpoint.
			 */
			virtual std::shared_ptr<Camera> getCamera() const = 0;

			/**
			 * <p>
			 * Retrieves the {@link simplicity::Picker Picker} that picks the {@link simplicity::Scene Scene} for this
			 * <code>PickingEngine</code>.
			 * </p>
			 *
			 * @return The <code>Picker</code> that picks the <code>Scene</code> for this <code>PickingEngine</code>.
			 */
			virtual std::shared_ptr<Picker> getPicker() const = 0;

			/**
			 * <p>
			 * Retrieves the outstanding picks to be performed against this <code>PickingEngine</code>'s
			 * {@link simplicity::Scene Scene}.
			 * </p>
			 *
			 * @return The outstanding picks to be performed against this <code>PickingEngine</code>'s
			 * <code>Scene</code>.
			 */
			virtual std::vector<Pick> getPicks() const = 0;

			/**
			 * <p>
			 * Retrieves the {@link simplicity::Scene Scene} to be picked.
			 * </p>
			 *
			 * @return The <code>Scene</code> to be picked.
			 */
			virtual std::shared_ptr<Scene> getScene() const = 0;

			/**
			 * <p>
			 * Registers a pick at the given location and area relative to this <code>PickingEngine</code>'s
			 * {@link simplicity::Camera Camera} in {@link simplicity::Scene Scene} coordinates.
			 * </p>
			 *
			 * @param x The position on the <code>x</code> axis to pick.
			 * @param y The position on the <code>y</code> axis to pick.
			 * @param width The width of the area to pick.
			 * @param height The height of the area to pick.
			 */
			virtual void pick(const float x, const float y, const float width, const float height) = 0;

			/**
			 * <p>
			 * Registers a pick at the given location and area relative to this <code>PickingEngine</code>'s
			 * {@link simplicity::Camera Camera} in {@link simplicity::Scene Scene} coordinates.
			 * </p>
			 *
			 * @param pick The position and area to pick.
			 */
			virtual void pick(const Pick pick) = 0;

			/**
			 * <p>
			 * Registers a pick at the given location of a viewport with the given dimensions.
			 * </p>
			 *
			 * @param viewportWidth The width of the viewport.
			 * @param viewportHeight The height of the viewport.
			 * @param x The position on the <code>x</code> axis of the viewport to pick.
			 * @param y The position on the <code>y</code> axis of the viewport to pick.
			 * @param width The width of the area on the viewport to pick.
			 * @param height The height of the area on the viewport to pick.
			 */
			virtual void pickViewport(const int viewportWidth, const int viewportHeight, const int x, const int y,
				const int width, const int height) = 0;

			/**
			 * <p>
			 * Registers a pick at the given location and area of a viewport.
			 * </p>
			 *
			 * @param viewportWidth The width of the viewport.
			 * @param viewportHeight The height of the viewport.
			 * @param pick The position and area of the viewport to pick.
			 */
			virtual void pickViewport(const int viewportWidth, const int viewportHeight, const Pick pick) = 0;

			/**
			 * <p>
			 * Sets the viewpoint that will be adapted to create the picking viewpoint.
			 * </p>
			 *
			 * @param camera The viewpoint that will be adapted to create the picking viewpoint. The
			 * {@link simplicity::Camera Camera} given will not be modified when creating the picking viewpoint.
			 */
			virtual void setCamera(std::shared_ptr<Camera> camera) = 0;

			/**
			 * <p>
			 * Sets the {@link simplicity::Picker Picker} that picks the {@link simplicity::Scene Scene} for this
			 * <code>PickingEngine</code>.
			 * </p>
			 *
			 * @param picker The {@link simplicity::Picker Picker} that picks the
			 * {@link simplicity::Scene Scene} for this <code>PickingEngine</code>.
			 */
			virtual void setPicker(std::shared_ptr<Picker> picker) = 0;

			/**
			 * <p>
			 * Sets the {@link simplicity::Scene Scene} to be picked.
			 * </p>
			 *
			 * @param scene The <code>Scene</code> to be picked.
			 */
			virtual void setScene(std::shared_ptr<Scene> scene) = 0;
	};
}

#endif /* PICKINGENGINE_H_ */
