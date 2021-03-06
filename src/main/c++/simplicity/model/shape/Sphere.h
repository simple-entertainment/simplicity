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
#ifndef SPHERE_H_
#define SPHERE_H_

#include "Shape.h"

namespace simplicity
{
	/**
	 * <p>
	 * A sphere.
	 * </p>
	 */
	class SIMPLE_API Sphere : public Shape
	{
		public:
			/**
			 * <p>
			 * An ID unique to the this model class.
			 * </p>
			 */
			static const unsigned int TYPE_ID = 9;

			/**
			 * @param radius The radius of this sphere.
			 */
			Sphere(float radius);

			/**
			 * <p>
			 * Retrieves the radius of this sphere.
			 * </p>
			 *
			 * @return The radius of this sphere.
			 */
			float getRadius() const;

			unsigned short getTypeID() const override;

			/**
			 * <p>
			 * Sets the radius of this sphere.
			 * </p>
			 *
			 * @param radius The radius of this sphere.
			 */
			void setRadius(const float radius);

		private:
			float radius;
	};
}

#endif /* SPHERE_H_ */
