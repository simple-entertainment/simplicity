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

#include "../BaseModel.h"
#include "Shape.h"

namespace simplicity
{
	/**
	 * <p>
	 * A cylindrical {@link simplicity::Model Model}.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class Cylinder : public BaseModel, public virtual Shape
	{
		public:
			/**
			 * <p>
			 * Creates an instance of <code>Cylinder</code>.
			 * </p>
			 */
			Cylinder();

			/**
			 * <p>
			 * Disposes of an instance of <code>Cylinder</code>.
			 * </p>
			 */
			~Cylinder();

			const TranslationVector<>& getCenter() const;

			RGBAColourVector<>& getColour() const;

			/**
			 * <p>
			 * Retrieves the length. The default is 1.0.
			 * </p>
			 *
			 * @return The length.
			 */
			float getLength() const;

			/**
			 * <p>
			 * Retrieves the radius. The default is 1.0.
			 * </p>
			 *
			 * @return The radius.
			 */
			float getRadius() const;

			void setColour(std::shared_ptr<RGBAColourVector<> > colour);

			/**
			 * <p>
			 * Sets the length. The default is 1.0.
			 * </p>
			 *
			 * @param length The length.
			 */
			void setLength(const float length);

			/**
			 * <p>
			 * Sets the radius. The default is 1.0.
			 * </p>
			 *
			 * @param radius The radius.
			 */
			void setRadius(const float radius);

		private:
			/**
			 * <p>
			 * The point at the center of this <code>Cylinder</code>.
			 * </p>
			 */
			std::shared_ptr<TranslationVector<> > center;

			/**
			 * <p>
			 * The colour to render this <code>Cylinder</code> as.
			 * </p>
			 */
			std::shared_ptr<RGBAColourVector<> > colour;

			/**
			 * <p>
			 * The length.
			 * </p>
			 */
			float length;

			/**
			 * <p>
			 * The radius.
			 * </p>
			 */
			float radius;
	};
}

#endif /* CYLINDER_H_ */
