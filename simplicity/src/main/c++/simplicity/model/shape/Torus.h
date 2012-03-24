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

#include "../BaseModel.h"
#include "Shape.h"

namespace simplicity
{
	/**
	 * <p>
	 * A torus-shaped {@link simplicity::Model Model}.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class Torus : public BaseModel, public virtual Shape
	{
		public:
			/**
			 * <p>
			 * Creates an instance of <code>Torus</code>.
			 * </p>
			 */
			Torus();

			/**
			 * <p>
			 * Disposes of an instance of <code>Torus</code>.
			 * </p>
			 */
			virtual ~Torus();

			const TranslationVector<>& getCenter() const;

			ColourVector<>& getColour() const;

			/**
			 * <p>
			 * Retrieves the inner radius. The default is 1.0.
			 * </p>
			 *
			 * @return The inner radius.
			 */
			float getInnerRadius() const;

			/**
			 * <p>
			 * Retrieves the outer radius. The default is 2.0.
			 * </p>
			 *
			 * @return The outer radius.
			 */
			float getOuterRadius() const;

			void setColour(std::shared_ptr<ColourVector<> > colour);

			/**
			 * <p>
			 * Sets the inner radius. The default is 1.0.
			 * </p>
			 *
			 * @param innerRadius The inner radius.
			 */
			void setInnerRadius(const float innerRadius);

			/**
			 * <p>
			 * Sets the outer radius. The default is 2.0.
			 * </p>
			 *
			 * @param outerRadius The outer radius.
			 */
			void setOuterRadius(const float outerRadius);

		private:
			/**
			 * <p>
			 * The point at the center of this <code>Torus</code>.
			 * </p>
			 */
			std::shared_ptr<TranslationVector<> > center;

			/**
			 * <p>
			 * The colour to render this <code>Torus</code> as.
			 * </p>
			 */
			std::shared_ptr<ColourVector<> > colour;

			/**
			 * <p>
			 * The inner radius.
			 * </p>
			 */
			float innerRadius;

			/**
			 * <p>
			 * The outer radius.
			 * </p>
			 */
			float outerRadius;
	};
}

#endif /* TORUS_H_ */
