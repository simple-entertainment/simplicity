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
#ifndef TRANSFORMATIONMATRIX_H_
#define TRANSFORMATIONMATRIX_H_

#include <math.h>

#include "Matrix.h"
#include "TranslationVector.h"
#include "Vector.h"

namespace simplicity
{
	/**
	 * <p>
	 * A transformation matrix that stores its data in a array.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	template<typename Data = float, unsigned int Size = 16, unsigned int Height = 4>
	class TransformationMatrix : public virtual Matrix<Data, Size, Height>
	{
		public:
			/**
			 * <p>
			 * Retrieves the translation portion of this <code>TransformationMatrix</code>.
			 * </p>
			 *
			 * @return The translation portion of this <code>TransformationMatrix</code>.
			 */
			virtual std::unique_ptr<TranslationVector<> > getTranslation() const = 0;

			/**
			 * <p>
			 * Rotates this <code>TransformationMatrix</code> by the angle given about the axis given.
			 * </p>
			 *
			 * @param angle The angle to rotate this <code>TransformationMatrix</code>.
			 * @param axis The axis to rotate this <code>TransformationMatrix</code> about.
			 */
			virtual void rotate(const Data angle, const TranslationVector<Data, Height>& axis) = 0;

			/**
			 * <p>
			 * Sets the translation portion of this <code>TransformationMatrix</code>.
			 * </p>
			 *
			 * @param translation The translation portion of this <code>TransformationMatrix</code>.
			 */
			virtual void setTranslation(const TranslationVector<Data, Height>& translation) = 0;

			/**
			 * <p>
			 * Translates this <code>TransformationMatrix</code> by the translation given.
			 * </p>
			 *
			 * @param translation The translation to translate this <code>TransformationMatrix</code> by.
			 */
			virtual void translate(const TranslationVector<Data, Height>& translation) = 0;
	};
}

#endif /* TRANSFORMATIONMATRIX_H_ */
