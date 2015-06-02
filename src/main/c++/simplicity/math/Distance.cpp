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
#include "MathFunctions.h"
#include "Distance.h"

using namespace std;

namespace simplicity
{
	namespace Distance
	{
		/*
		 * The equation for the distance from a point to a line:
		 *     distance = ||(a - p) - ((a - p).n)n||
		 * Where:
		 *     a is any point on the line.
		 *     p is an arbitrary point.
		 *     n is a unit vector in the direction vector of the line.
		 * Reference:
		 *     http://en.wikipedia.org/wiki/Distance_from_a_point_to_a_line
		 */
		float distanceBetween(const Line& lineSegment, const Point& point)
		{
			return distanceBetween(lineSegment, point.getPoint());
		}

		float distanceBetween(const Line& lineSegment, const Vector3& point)
		{
			Vector3 n = lineSegment.getPointB() - lineSegment.getPointA();
			Vector3 aMinusP = lineSegment.getPointA() - point;

			// If the point is past either end of the line segment take the distance from the respective end.
			float lDotP = dotProduct(n, aMinusP);
			if (lDotP > 0.0f)
			{
				return aMinusP.getMagnitude();
			}
			else if (lDotP < -1.0f)
			{
				return (lineSegment.getPointB() - point).getMagnitude();
			}

			n.normalize();
			return (aMinusP - dotProduct(aMinusP, n) * n).getMagnitude();
		}
	}
}
