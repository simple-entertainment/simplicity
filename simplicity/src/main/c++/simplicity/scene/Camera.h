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

#include "../graph/SimpleTree.h"
#include "../math/Matrix.h"
#include "../math/Vector.h"

namespace simplicity
{
	class Camera
	{
		public:
			virtual ~Camera()
			{
			}

			virtual float getFarClippingDistance() const = 0;

			virtual float getFrameHeight() const = 0;

			virtual float getFrameWidth() const = 0;

			virtual float getNearClippingDistance() const = 0;

			virtual SimpleTree* getNode() = 0;

			virtual Vector3 getTranslation() const = 0;

			virtual void lookAt(const Vector3& target, const Vector3& up) = 0;

			virtual void setFarClippingDistance(float farClippingDistance) = 0;

			virtual void setNearClippingDistance(float nearClippingDistance) = 0;

			virtual void setNode(SimpleTree* node) = 0;

			virtual void setOrthogonal(float width, float height) = 0;

			virtual void setPerspective(float yAxisFieldOfView, float aspectRatio) = 0;

			virtual void setTranslation(const Vector3& translation) = 0;
	};
}

#endif /* CAMERA_H_ */
