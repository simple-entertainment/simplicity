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
	class Triangle : public Shape
	{
		public:
			Triangle(const Vector3& pointA, const Vector3& pointB, const Vector3& pointC);

			const Vector3& getPointA() const;

			const Vector3& getPointB() const;

			const Vector3& getPointC() const;

			void render(Renderer& renderer) const;

			void setPointA(const Vector3& pointA);

			void setPointB(const Vector3& pointB);

			void setPointC(const Vector3& pointC);

		private:
			Vector3 pointA;

			Vector3 pointB;

			Vector3 pointC;
	};
}

#endif /* TRIANGLE_H_ */

