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
#ifndef SIMPLERGBACOLOURVECTOR4_H_
#define SIMPLERGBACOLOURVECTOR4_H_

#include "RGBAColourVector.h"
#include "SimpleVector4.h"

namespace simplicity
{
	/**
	 * <p>
	 * A 4 dimensional RGBA colour vector that stores its data in an array.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	template<typename Data = float>
	class SimpleRGBAColourVector4 : public SimpleVector4<Data>, public RGBAColourVector<Data, SimpleVector4<>::SIZE>
	{
		public:
			/**
			 * <p>
			 * Creates an instance of <code>SimpleRGBAColourVector4</code>.
			 * </p>
			 *
			 * <p>
			 * The <code>SimpleRGBAColourVector4</code> is initialised to <code>(0.0, 0.0, 0.0, 1.0)</code>.
			 * </p>
			 */
			SimpleRGBAColourVector4();

			/**
			 * <p>
			 * Creates an instance of <code>SimpleRGBAColourVector4</code>.
			 * </p>
			 *
			 * @param r The red element of this <code>SimpleRGBAColourVector4</code>.
			 * @param g The green element of this <code>SimpleRGBAColourVector4</code>.
			 * @param b The blue element of this <code>SimpleRGBAColourVector4</code>.
			 * @param a The alpha element of this <code>SimpleRGBAColourVector4</code>.
			 */
			SimpleRGBAColourVector4(const Data r, const Data g, const Data b, const Data a);

			/**
			 * <p>
			 * Creates an instance of <code>SimpleRGBAColourVector4</code>.
			 * </p>
			 *
			 * @param data An array containing the initial elements of this <code>SimpleRGBAColourVector4</code>.
			 */
			SimpleRGBAColourVector4(const std::array<Data, SimpleVector4<>::SIZE>& data);

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

#include "SimpleRGBAColourVector4.tpp"

#endif /* SIMPLERGBACOLOURVECTOR4_H_ */
