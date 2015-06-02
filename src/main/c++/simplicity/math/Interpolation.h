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
#ifndef INTERPOLATION_H_
#define INTERPOLATION_H_

#include <vector>

#include "../math/Vector.h"
#include "../model/Vertex.h"

namespace simplicity
{
	namespace Interpolation
	{
		/**
		 * <p>
		 * Interpolates a set of points at regular intervals on a bezier curve.
		 * </p>
		 *
		 * @param points The points that make up the bezier curve.
		 * @param interpolationCount The number of points to interpolate.
		 *
		 * @return The interpolated points.
		 */
		SIMPLE_API std::vector<Vector3> interpolateBezier(const std::vector<Vector3>& points, unsigned int interpolationCount);

		/**
		 * <p>
		 * Interpolates a point on a bezier curve.
		 * </p>
		 *
		 * @param begin The first point on the bezier curve.
		 * @param end The end point on the bezier curve (non-inclusive).
		 * @param time A value in the range [0-1] that denotes how far along the curve to interpolate.
		 *
		 * @return The interpolated point.
		 */
		SIMPLE_API Vector3 interpolateBezier(const std::vector<Vector3>::const_iterator& begin,
			const std::vector<Vector3>::const_iterator& end, float time);

		/**
		 * UNDER CONSTRUCTION
		 */
		Vertex interpolateLinear(const std::vector<Vertex>& vertices, const Vector3& position);
	}
}

#endif /* INTERPOLATION_H_ */
