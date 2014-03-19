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
#ifndef TORUS_H_
#define TORUS_H_

#include "Shape.h"

namespace simplicity
{
	/**
	 * <p>
	 * A torus.
	 * </p>
	 */
	class Torus : public Shape
	{
		public:
			/**
			 * @param innerRadius The radius of the inner edge of the torus.
			 * @param outerRadius The radius of the outer edge of the torus.
			 */
			Torus(float innerRadius, float outerRadius);

			/**
			 * <p>
			 * Retrieves the radius of the inner edge of the torus.
			 * </p>
			 *
			 * @return The radius of the inner edge of the torus.
			 */
			float getInnerRadius() const;

			/**
			 * <p>
			 * Retrieves the radius of the outer edge of the torus.
			 * </p>
			 *
			 * @return The radius of the outer edge of the torus.
			 */
			float getOuterRadius() const;

			void render(Renderer& renderer) const;

			/**
			 * <p>
			 * Sets the radius of the inner edge of the torus.
			 * </p>
			 *
			 * @param innerRadius The radius of the inner edge of the torus.
			 */
			void setInnerRadius(const float innerRadius);

			/**
			 * <p>
			 * Sets the radius of the outer edge of the torus.
			 * </p>
			 *
			 * @param outerRadius The radius of the outer edge of the torus.
			 */
			void setOuterRadius(const float outerRadius);

		private:
			float innerRadius;

			float outerRadius;
	};
}

#endif /* TORUS_H_ */
