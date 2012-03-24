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
#ifndef SIMPLETRANSFORMATIONMATRIX_H_
#define SIMPLETRANSFORMATIONMATRIX_H_

#include "SimpleMatrix.h"
#include "TransformationMatrix.h"

namespace simplicity
{
	/**
	 * <p>
	 * A 4x4 transformation matrix that stores its data in a array.
	 * </p>
	 *
	 * <p>
	 * This <code>SimpleTransformationMatrix</code> uses a 3D homogeneous coordinate system. It is of the following
	 * format:
	 * </p>
	 *
	 * <pre>
	 * --------------------
	 *  xx | yx | zx | tx |
	 * --------------------
	 *  xy | yy | zy | ty |
	 * --------------------
	 *  xz | yz | zz | tz |
	 * --------------------
	 *  xw | yw | zw | tw |
	 * --------------------
	 * </pre>
	 *
	 * <p>
	 * Where the first column is the x axis rotation, the second column is the y axis rotation, the third column is the
	 * z axis rotation and the fourth column is the translation.
	 * </p>
	 *
	 * <p>
	 * It is stored in column-major format. This means the first four indices of the array represent the first column of
	 * the <code>SimpleTransformationMatrix</code>, the second four represent the second column etc.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	template<typename Data = float>
	class SimpleTransformationMatrix : public SimpleMatrix<Data, 4, 4>, public TransformationMatrix<Data, 4, 4>
	{
		public:
			/**
			 * <p>
			 * The number of columns in this matrix.
			 * </p>
			 */
			static const unsigned int COLUMNS = 4;

			/**
			 * <p>
			 * The number of rows in this matrix.
			 * </p>
			 */
			static const unsigned int ROWS = 4;

			/**
			 * <p>
			 * The number of cells in this matrix.
			 * </p>
			 */
			static const unsigned int SIZE = 16;

			/**
			 * <p>
			 * Creates an instance of <code>SimpleTransformationMatrix</code>.
			 * </p>
			 */
			SimpleTransformationMatrix();

			/**
			 * <p>
			 * Creates an instance of <code>SimpleTransformationMatrix</code>.
			 * </p>
			 *
			 * @param data A array containing the initial elements for this <code>SimpleTransformationMatrix</code>.
			 */
			SimpleTransformationMatrix(const array<Data, SIZE>& data);

			std::unique_ptr<TranslationVector<> > getTranslation() const;

			void rotate(const Data angle, const TranslationVector<Data, ROWS>& axis);

			void setTranslation(const TranslationVector<Data, ROWS>& translation);

			void translate(const TranslationVector<Data, ROWS>& translation);
	};
}

#include "SimpleTransformationMatrix.tpp"

#endif /* SIMPLETRANSFORMATIONMATRIX_H_ */
