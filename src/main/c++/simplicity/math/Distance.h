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
#ifndef DISTANCE_H_
#define DISTANCE_H_

#include "../model/shape/Line.h"
#include "../model/shape/Point.h"

namespace simplicity
{
	namespace Distance
	{
		/**
		 * <p>
		 * Determines the distance between a line segment and a point.
		 * </p>
		 *
		 * @param lineSegment The line segment.
		 * @param point The point.
		 *
		 * @return The distance.
		 */
		SIMPLE_API float distanceBetween(const Line& lineSegment, const Point& point);

		/**
		 * <p>
		 * Determines the distance between a line segment and a point.
		 * </p>
		 *
		 * @param lineSegment The line segment.
		 * @param point The point.
		 *
		 * @return The distance.
		 */
		SIMPLE_API float distanceBetween(const Line& lineSegment, const Vector3& point);
	}
}

#endif /* DISTANCE_H_ */
