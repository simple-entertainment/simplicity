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
#ifndef POINT_H_
#define POINT_H_

#include "../../math/Vector.h"
#include "Shape.h"

namespace simplicity
{
	/**
	 * <p>
	 * A lonesome point in space... just used as a container so that a point can be used polymorphically as a model.
	 * </p>
	 */
	class SIMPLE_API Point : public Shape
	{
		public:
			/**
			 * <p>
			 * An ID unique to the this model class.
			 * </p>
			 */
			static const unsigned int TYPE_ID = 2;

			/**
			 * @param point The point.
			 */
			Point(const Vector3& point);

			/**
			 * <p>
			 * Retrieves the point.
			 * </p>
			 *
			 * @return The point.
			 */
			const Vector3& getPoint() const;

			unsigned short getTypeID() const override;

			/**
			 * <p>
			 * Sets the point.
			 * </p>
			 *
			 * @param point The point.
			 */
			void setPoint(const Vector3& point);

		private:
			Vector3 point;
	};
}

#endif /* POINT_H_ */
