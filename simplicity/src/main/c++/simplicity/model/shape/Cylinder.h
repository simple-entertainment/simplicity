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
#ifndef CYLINDER_H_
#define CYLINDER_H_

#include "Shape.h"

namespace simplicity
{
	class Cylinder : public Shape
	{
		public:
			Cylinder(float length, float radius);

			float getLength() const;

			float getRadius() const;

			void render(Renderer& renderer) const;

			void setLength(const float length);

			void setRadius(const float radius);

		private:
			float length;

			float radius;
	};
}

#endif /* CYLINDER_H_ */
