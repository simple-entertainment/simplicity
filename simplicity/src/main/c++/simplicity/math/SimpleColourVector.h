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
#ifndef SIMPLECOLOURVECTOR_H_
#define SIMPLECOLOURVECTOR_H_

#include "ColourVector.h"
#include "SimpleVector.h"

namespace simplicity
{
	/**
	 * <p>
	 * A 4 dimensional colour vector that stores its data in an array.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	template<typename Data = float>
	class SimpleColourVector : public SimpleVector<Data, 4>, public ColourVector<Data, 4>
	{
		public:
			/**
			 * <p>
			 * The number of cells in this vector.
			 * </p>
			 */
			static const unsigned int SIZE = 4;

			/**
			 * <p>
			 * Creates an instance of <code>SimpleColourVector</code>.
			 * </p>
			 *
			 * <p>
			 * The <code>SimpleColourVector</code> is initialised to <code>(0.0, 0.0, 0.0, 1.0)</code>.
			 * </p>
			 */
			SimpleColourVector();

			/**
			 * <p>
			 * Creates an instance of <code>SimpleColourVector</code>.
			 * </p>
			 *
			 * @param r The red element of this <code>SimpleColourVector</code>.
			 * @param g The green element of this <code>SimpleColourVector</code>.
			 * @param b The blue element of this <code>SimpleColourVector</code>.
			 * @param a The alpha element of this <code>SimpleColourVector</code>.
			 */
			SimpleColourVector(const Data r, const Data g, const Data b, const Data a);

			/**
			 * <p>
			 * Creates an instance of <code>SimpleColourVector</code>.
			 * </p>
			 *
			 * @param data An array containing the initial elements of this <code>SimpleColourVector</code>.
			 */
			SimpleColourVector(const std::array<Data, SIZE>& data);

			Data getAlpha() const;

			Data getBlue() const;

			Data getGreen() const;

			Data getRed() const;

			void setAlpha(const Data alpha);

			void setBlue(const Data blue);

			void setGreen(const Data green);

			void setRed(const Data red);
	};
}

#include "SimpleColourVector.tpp"

#endif /* SIMPLECOLOURVECTOR_H_ */
