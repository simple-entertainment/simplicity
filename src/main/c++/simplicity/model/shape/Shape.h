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
#ifndef SHAPE_H_
#define SHAPE_H_

#include "../../common/Defines.h"

namespace simplicity
{
	/**
	 * <p>
	 * A basic geometric shape that is not constructed from primitives like a mesh is. It has a level of detail which
	 * is a hint used by renderers etc. when they convert them to meshes.
	 * </p>
	 */
	class SIMPLE_API Shape
	{
		public:
			/**
			 * <p>
			 * User defined type IDs should start with this ID.
			 * </p>
			 *
			 * <p>
			 * For example:
			 * </p>
			 *
			 * <pre><code>
			 * static const unsigned short TYPE_ID = USER_ID_0;
			 * ...
			 * static const unsigned short TYPE_ID = USER_ID_0 + 1;
			 * </code></pre>
			 */
			static const unsigned short USER_TYPE_ID_0 = 128;

			Shape();

			/**
			 * <p>
			 * Allows polymorphism.
			 * </p>
			 */
			virtual ~Shape();

			/**
			 * <p>
			 * Retrieves the level of detail applied to this shape.
			 * </p>
			 *
			 * @return The level of detail applied to this shape.
			 */
			unsigned int getLevelOfDetail() const;

			/**
			 * <p>
			 * Retrieves an ID unique to the class this shape is an instance of. This is part of the ID member +
			 * static_cast pattern for faster 'dynamic' casting.
			 * </p>
			 *
			 * <p>
			 * Instead of this:
			 * </p>
			 *
			 * <pre>
			 * <code>
			 * Shape* shape = // some shape...
			 * Square* square = dynamic_cast<Square*>(shape);
			 * if (square != nullptr)
			 * {
			 *     // do stuff...
			 * }
			 * </code>
			 * </pre>
			 *
			 * <p>
			 * You can do this to avoid the expensive dynamic_cast operation:
			 * </p>
			 *
			 * <pre>
			 * <code>
			 * Shape* shape = // some shape...
			 * if (shape->getTypeID() == Square::TYPE_ID)
			 * {
			 *     Square* square = static_cast<Square*>(shape);
			 *     // do stuff...
			 * }
			 * </code>
			 * </pre>
			 *
			 * <p>
			 * Each shape implementation should provide a public static TYPE_ID member whose value is returned by this
			 * function.
			 * </p>
			 *
			 * @return An ID unique to the class this model is an instance of.
			 */
			virtual unsigned short getTypeID() const = 0;

			/**
			 * <p>
			 * Applies a level of detail to this shape.
			 * </p>
			 *
			 * @return The level of detail applied to this shape.
			 */
			void setLevelOfDetail(unsigned int levelOfDetail);

		private:
			unsigned int levelOfDetail;
	};
}

#endif /* SHAPE_H_ */
