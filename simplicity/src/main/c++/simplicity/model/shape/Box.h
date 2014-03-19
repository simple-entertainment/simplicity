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
#ifndef BOX_H_
#define BOX_H_

#include "Shape.h"

namespace simplicity
{
	/**
	 * <p>
	 * A box! Not like those boxes in box2d nooo... this is a bonified 3D box.
	 * </p>
	 */
	class Box : public Shape
	{
		public:
			/**
			 * @param halfXLength Half the length on the x axis.
			 * @param halfYLength Half the length on the y axis.
			 * @param halfZLength Half the length on the z axis.
			 */
			Box(float halfXLength, float halfYLength, float halfZLength);

			/**
			 * <p>
			 * Retrieves half the length on the x axis.
			 * </p>
			 *
			 * @return Half the length on the x axis.
			 */
			float getHalfXLength() const;

			/**
			 * <p>
			 * Retrieves half the length on the y axis.
			 * </p>
			 *
			 * @return Half the length on the y axis.
			 */
			float getHalfYLength() const;

			/**
			 * <p>
			 * Retrieves half the length on the z axis.
			 * </p>
			 *
			 * @return Half the length on the z axis.
			 */
			float getHalfZLength() const;

			void render(Renderer& renderer) const;

			/**
			 * <p>
			 * Sets half the length on the x axis.
			 * </p>
			 *
			 * @param halfXLength Half the length on the x axis.
			 */
			void setHalfXLength(float halfXLength);

			/**
			 * <p>
			 * Sets half the length on the y axis.
			 * </p>
			 *
			 * @param halfYLength Half the length on the y axis.
			 */
			void setHalfYLength(float halfYLength);

			/**
			 * <p>
			 * Sets half the length on the z axis.
			 * </p>
			 *
			 * @param halfZLength Half the length on the z axis.
			 */
			void setHalfZLength(float halfZLength);

		private:
			float halfXLength;

			float halfYLength;

			float halfZLength;
	};
}

#endif /* BOX_H_ */

