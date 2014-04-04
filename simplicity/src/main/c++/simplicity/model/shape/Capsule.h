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
#ifndef CAPSULE_H_
#define CAPSULE_H_

#include "Shape.h"

namespace simplicity
{
	/**
	 * <p>
	 * A capsule.
	 * </p>
	 */
	class SIMPLE_API Capsule : public Shape
	{
		public:
			/**
			 * <p>
			 * An ID unique to the this model class.
			 * </p>
			 */
			static const unsigned int TYPE_ID = 6;

			/**
			 * @param length The length of the capsule.
			 * @param radius The radius of the capsule.
			 */
			Capsule(float length, float radius);

			/**
			 * <p>
			 * Retrieves the length of the capsule.
			 * </p>
			 *
			 * @return The length of the capsule.
			 */
			float getLength() const;

			/**
			 * <p>
			 * Retrieves the radius of the capsule.
			 * </p>
			 *
			 * @return The radius of the capsule.
			 */
			float getRadius() const;

			unsigned short getTypeID() const;

			/**
			 * <p>
			 * Sets the length of the capsule.
			 * </p>
			 *
			 * @param length The length of the capsule.
			 */
			void setLength(const float length);

			/**
			 * <p>
			 * Sets the radius of the capsule.
			 * </p>
			 *
			 * @param radius The radius of the capsule.
			 */
			void setRadius(const float radius);

		private:
			float length;

			float radius;
	};
}

#endif /* CAPSULE_H_ */
