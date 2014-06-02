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
#ifndef CAMERA_H_
#define CAMERA_H_

#include "../entity/Component.h"
#include "../math/Matrix.h"
#include "../math/Vector.h"

namespace simplicity
{
	/**
	 * <p>
	 * A viewpoint through which a scene can be rendered.
	 * </p>
	 */
	class SIMPLE_API Camera : public Component
	{
		public:
			Camera();

			/**
			 * <p>
			 * Retrieves the far clipping distance (the distance past which objects will not be rendered).
			 * </p>
			 *
			 * @return The far clipping distance.
			 */
			float getFarClippingDistance() const;

			/**
			 * <p>
			 * Retrieves the height of the camera frame.
			 * </p>
			 *
			 * @return The height of the camera frame.
			 */
			float getFrameHeight() const;

			/**
			 * <p>
			 * Retrieves the width of the camera frame.
			 * </p>
			 *
			 * @return The width of the camera frame.
			 */
			float getFrameWidth() const;

			/**
			 * <p>
			 * Retrieves the near clipping distance (the distance in front of which objects will not be rendered).
			 * </p>
			 *
			 * @return The near clipping distance.
			 */
			float getNearClippingDistance() const;

			/**
			 * <p>
			 * Retrieves the projection.
			 * </p>
			 *
			 * @return The projection.
			 */
			const Matrix44& getProjection() const;

			/**
			 * <p>
			 * Sets the far clipping distance (the distance past which objects will not be rendered).
			 * </p>
			 *
			 * @param farClippingDistance The far clipping distance.
			 */
			void setFarClippingDistance(float farClippingDistance);

			/**
			 * <p>
			 * Sets the near clipping distance (the distance in front of which objects will not be rendered).
			 * </p>
			 *
			 * @param nearClippingDistance The near clipping distance.
			 */
			void setNearClippingDistance(float nearClippingDistance);

			/**
			 * <p>
			 * Sets an orthogonal projection. Orthogonal projections work well with 2D games.
			 * </p>
			 *
			 * @param width The width of the camera frame.
			 * @param height The height of the camera frame.
			 */
			void setOrthogonal(float width, float height);

			/**
			 * <p>
			 * Sets a perspective projection. Perspective projections work well with 3D games.
			 * </p>
			 *
			 * @param yAxisFieldOfView The field of view on the Y axis.
			 * @param aspectRatio The aspect ratio.
			 */
			void setPerspective(float yAxisFieldOfView, float aspectRatio);

		private:
			float farClippingDistance;

			float frameHeight;

			float frameWidth;

			float nearClippingDistance;

			Matrix44 projection;
	};
}

#endif /* CAMERA_H_ */
