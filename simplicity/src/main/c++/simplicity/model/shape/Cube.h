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
#ifndef CUBE_H_
#define CUBE_H_

#include "Shape.h"

namespace simplicity
{
	/**
	 * <p>
	 * A cube.
	 * </p>
	 */
	class SIMPLE_API Cube : public Shape
	{
		public:
			/**
			 * <p>
			 * An ID unique to the this model class.
			 * </p>
			 */
			static const unsigned int TYPE_ID = 7;

			/**
			 * @param halfEdgeLength Half the length of all dimensions of the cube.
			 */
			Cube(float halfEdgeLength);

			/**
			 * <p>
			 * Retrieves half the length of all dimensions of the cube.
			 * </p>
			 *
			 * @return Half the length of all dimensions of the cube.
			 */
			float getHalfEdgeLength() const;

			unsigned short getTypeID() const;

			/**
			 * <p>
			 * Sets half the length of all dimensions of the cube.
			 * </p>
			 *
			 * @param halfEdgeLength Half the length of all dimensions of the cube.
			 */
			void setHalfEdgeLength(float halfEdgeLength);

		private:
			float halfEdgeLength;
	};
}

#endif /* CUBE_H_ */

