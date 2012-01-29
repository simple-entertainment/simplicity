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
#ifndef TRANSLATIONVECTOR_H_
#define TRANSLATIONVECTOR_H_

#include "Vector.h"

namespace simplicity
{
	/**
	 * <p>
	 * A 3D translation vector.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	template<typename Data = float, unsigned int Size = 4>
	class TranslationVector : public virtual Vector<Data, Size>
	{
		public:
			/**
			 * <p>
			 * Retrieves the w component of this <code>TranslationVector</code>.
			 * </p>
			 *
			 * @return The w component of this <code>TranslationVector</code>.
			 */
			virtual Data getW() const = 0;

			/**
			 * <p>
			 * Retrieves the x axis component of this <code>TranslationVector</code>.
			 * </p>
			 *
			 * @return The x axis component of this <code>TranslationVector</code>.
			 */
			virtual Data getX() const = 0;

			/**
			 * <p>
			 * Retrieves the y axis component of this <code>TranslationVector</code>.
			 * </p>
			 *
			 * @return The y axis component of this <code>TranslationVector</code>.
			 */
			virtual Data getY() const = 0;

			/**
			 * <p>
			 * Retrieves the z axis component of this <code>TranslationVector</code>.
			 * </p>
			 *
			 * @return The z axis component of this <code>TranslationVector</code>.
			 */
			virtual Data getZ() const = 0;

			/**
			 * <p>
			 * Sets the x axis component of this <code>TranslationVector</code>.
			 * </p>
			 *
			 * @param x The x axis component of this <code>TranslationVector</code>.
			 */
			virtual void setX(const Data x) = 0;

			/**
			 * <p>
			 * Sets the y axis component of this <code>TranslationVector</code>.
			 * </p>
			 *
			 * @param y The y axis component of this <code>TranslationVector</code>.
			 */
			virtual void setY(const Data y) = 0;

			/**
			 * <p>
			 * Sets the z axis component of this <code>TranslationVector</code>.
			 * </p>
			 *
			 * @param z The z axis component of this <code>TranslationVector</code>.
			 */
			virtual void setZ(const Data z) = 0;

			/**
			 * <p>
			 * Translates this <code>TranslationVector</code> by the given distance on the x axis.
			 * </p>
			 *
			 * @param x The distance to translate this <code>TranslationVector</code> on the x axis.
			 */
			virtual void translateX(const Data x) = 0;

			/**
			 * <p>
			 * Translates this <code>TranslationVector</code> by the given distance on the y axis.
			 * </p>
			 *
			 * @param y The distance to translate this <code>TranslationVector</code> on the y axis.
			 */
			virtual void translateY(const Data y) = 0;

			/**
			 * <p>
			 * Translates this <code>TranslationVector</code> by the given distance on the z axis.
			 * </p>
			 *
			 * @param z The distance to translate this <code>TranslationVector</code> on the z axis.
			 */
			virtual void translateZ(const Data z) = 0;
	};
}

#endif /* TRANSLATIONVECTOR_H_ */
