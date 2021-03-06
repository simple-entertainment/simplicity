/*
 * Copyright © 2013 Simple Entertainment Limited
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
#ifndef PLANE_H_
#define PLANE_H_

#include "../../math/Vector.h"
#include "Shape.h"

namespace simplicity
{
	/**
	 * <p>
	 * A plane. Not the flying kind, the mathematical kind.
	 * </p>
	 */
	class SIMPLE_API Plane : public Shape
	{
		public:
			/**
			 * <p>
			 * An ID unique to the this model class.
			 * </p>
			 */
			static const unsigned int TYPE_ID = 1;

			/**
			 * @param normal The normal of the plane.
			 * @param positionOnPlane A position on the plane.
			 */
			Plane(const Vector3& normal, const Vector3& positionOnPlane);

			/**
			 * <p>
			 * Retrieves the normal of the plane.
			 * </p>
			 *
			 * @return The normal of the plane.
			 */
			const Vector3& getNormal() const;

			/**
			 * <p>
			 * Retrieves a position on the plane.
			 * </p>
			 *
			 * @return A position on the plane.
			 */
			const Vector3& getPositionOnPlane() const;

			unsigned short getTypeID() const override;

			/**
			 * <p>
			 * Sets the normal of the plane.
			 * </p>
			 *
			 * @param normal The normal of the plane.
			 */
			void setNormal(const Vector3& normal);

			/**
			 * <p>
			 * Sets a position on the plane.
			 * </p>
			 *
			 * @param positionOnPlane A position on the plane.
			 */
			void setPositionOnPlane(const Vector3& positionOnPlane);

		private:
			Vector3 normal;

			Vector3 positionOnPlane;
	};
}

#endif /* PLANE_H_ */
