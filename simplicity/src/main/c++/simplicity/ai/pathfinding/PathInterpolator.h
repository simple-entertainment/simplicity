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
#ifndef PATHINTERPOLATOR_H_
#define PATHINTERPOLATOR_H_

#include "../../vector/TranslationVector.h"

namespace simplicity
{
	/**
	 * <p>
	 * Interpolates a point on a given path.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class PathInterpolator
	{
		public:
			/**
			 * <p>
			 * Disposes of an instance of <code>PathInterpolator</code> (included to allow polymorphic deletion).
			 * </p>
			 */
			virtual ~PathInterpolator()
			{
			}

			/**
			 * <p>
			 * Interpolates the point on the path at the given time.
			 * </p>
			 *
			 * @param time The time at which to interpolate the point. Time is in the range [0, 1].
			 *
			 * @return The interpolated point.
			 */
			virtual boost::shared_ptr<TranslationVector<float> > interpolate(const float time) = 0;
	};
}

#endif /* PATHINTERPOLATOR_H_ */
