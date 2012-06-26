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
#ifndef PATHWALKER_H_
#define PATHWALKER_H_

#include "../../math/TranslationVector.h"

namespace simplicity
{
	/**
	 * <p>
	 * Walks along a given path in either direction.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class PathWalker
	{
		public:
			/**
			 * <p>
			 * Disposes of an instance of <code>PathWalker</code> (included to allow polymorphic deletion).
			 * </p>
			 */
			virtual ~PathWalker()
			{
			}

			/**
			 * <p>
			 * Gets the current location on the path that the walker has walked to.
			 * </p>
			 *
			 * @return The current location on the path that the walker has walked to.
			 */
			virtual const TranslationVector<>& getLocation() const = 0;

			/**
			 * <p>
			 * Walks one 'step' backward.
			 * </p>
			 *
			 * @param stepDistance The distance to 'step'.
			 */
			virtual void stepBackward(const float stepDistance) = 0;

			/**
			 * <p>
			 * Walks one 'step' forward.
			 * </p>
			 *
			 * @param stepDistance The distance to 'step'.
			 */
			virtual void stepForward(const float stepDistance) = 0;
	};
}

#endif /* PATHWALKER_H_ */
