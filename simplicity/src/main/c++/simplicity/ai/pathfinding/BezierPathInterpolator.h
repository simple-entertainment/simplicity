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
#ifndef BEZIERPATHINTERPOLATOR_H_
#define BEZIERPATHINTERPOLATOR_H_

#include "../../graph/Node.h"
#include "PathInterpolator.h"

namespace simplicity
{
	/**
	 * <p>
	 * Interpolates a point on a given path using the waypoints in the path as control points for Bezier curve.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class BezierPathInterpolator : public PathInterpolator
	{
		public:
			/**
			 * <p>
			 * Creates an instance of <code>BezierPathInterpolator</code>.
			 * </p>
			 *
			 * @param path The path to be interpolated.
			 */
			BezierPathInterpolator(std::vector<std::reference_wrapper<const Node> > path);

			/**
			 * <p>
			 * Disposes of an instance of <code>BezierPathInterpolator</code>.
			 * </p>
			 */
			virtual ~BezierPathInterpolator();

			std::unique_ptr<TranslationVector<> > interpolate(const float time);

		private:
			/**
			 * <p>
			 * The path to be interpolated.
			 * </p>
			 */
			std::vector<std::reference_wrapper<const Node> > path;

			/**
			 * <p>
			 * Interpolates the point on the given path at the given time.
			 * </p>
			 *
			 * @param time The time at which to interpolate the point. Time is in the range [0, 1].
			 * @param path The path to be interpolated.
			 *
			 * @return The interpolated point.
			 */
			std::unique_ptr<TranslationVector<> > interpolate(const float time,
				const std::vector<std::reference_wrapper<const Node> >::iterator& begin,
				const std::vector<std::reference_wrapper<const Node> >::iterator& end);
	};
}

#endif /* BEZIERPATHINTERPOLATOR_H_ */
