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
#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "Shape.h"

namespace simplicity
{
	/**
	 * <p>
	 * A triangle.
	 * </p>
	 */
	class Triangle : public Shape
	{
		public:
			/**
			 * @param pointA The position of the first corner of the triangle.
			 * @param pointB The position of the second corner of the triangle.
			 * @param pointC The position of the third corner of the triangle.
			 */
			Triangle(const Vector3& pointA, const Vector3& pointB, const Vector3& pointC);

			/**
			 * <p>
			 * Retrieves the position of the first corner of the triangle.
			 * </p>
			 *
			 * @return The position of the first corner of the triangle.
			 */
			const Vector3& getPointA() const;

			/**
			 * <p>
			 * Retrieves the position of the second corner of the triangle.
			 * </p>
			 *
			 * @return The position of the second corner of the triangle.
			 */
			const Vector3& getPointB() const;

			/**
			 * <p>
			 * Retrieves the position of the third corner of the triangle.
			 * </p>
			 *
			 * @return The position of the third corner of the triangle.
			 */
			const Vector3& getPointC() const;

			void render(Renderer& renderer) const;

			/**
			 * <p>
			 * Sets the position of the first corner of the triangle.
			 * </p>
			 *
			 * @param pointA The position of the first corner of the triangle.
			 */
			void setPointA(const Vector3& pointA);

			/**
			 * <p>
			 * Sets the position of the second corner of the triangle.
			 * </p>
			 *
			 * @param pointB The position of the second corner of the triangle.
			 */
			void setPointB(const Vector3& pointB);

			/**
			 * <p>
			 * Sets the position of the third corner of the triangle.
			 * </p>
			 *
			 * @param pointC The position of the third corner of the triangle.
			 */
			void setPointC(const Vector3& pointC);

		private:
			Vector3 pointA;

			Vector3 pointB;

			Vector3 pointC;
	};
}

#endif /* TRIANGLE_H_ */

