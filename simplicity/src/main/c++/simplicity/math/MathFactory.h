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
#ifndef MATHFACTORY_H_
#define MATHFACTORY_H_

#include "ColourVector.h"
#include "TransformationMatrix.h"

namespace simplicity
{
	class MathFactory
	{
		public:
			static const MathFactory& getInstance();

			static void setInstance(std::unique_ptr<MathFactory> instance);

			virtual ~MathFactory();

			virtual std::unique_ptr<Matrix<> > createMatrix() const = 0;

			virtual std::unique_ptr<ColourVector<> > createColourVector() const = 0;

			virtual std::unique_ptr<TransformationMatrix<> > createTransformationMatrix() const = 0;

			virtual std::unique_ptr<TranslationVector<> > createTranslationVector() const = 0;

			virtual std::unique_ptr<Vector<> > createVector() const = 0;

		private:
			static std::unique_ptr<MathFactory> instance;
	};
}

#endif /* MATHFACTORY_H_ */
