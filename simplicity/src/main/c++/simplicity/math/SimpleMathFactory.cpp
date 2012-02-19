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
#include "SimpleMathFactory.h"
#include "SimpleRGBAColourVector4.h"
#include "SimpleTranslationVector4.h"
#include "SimpleTransformationMatrix44.h"

using namespace std;

namespace simplicity
{
	SimpleMathFactory::SimpleMathFactory()
	{
	}

	SimpleMathFactory::~SimpleMathFactory()
	{
	}

	unique_ptr<Matrix<> > SimpleMathFactory::createMatrix() const
	{
		return unique_ptr<Matrix<> >(new SimpleMatrix44<>);
	}

	unique_ptr<RGBAColourVector<> > SimpleMathFactory::createRGBAColourVector() const
	{
		return unique_ptr<RGBAColourVector<> >(new SimpleRGBAColourVector4<>);
	}

	unique_ptr<TransformationMatrix<> > SimpleMathFactory::createTransformationMatrix() const
	{
		return unique_ptr<TransformationMatrix<> >(new SimpleTransformationMatrix44<>);
	}

	unique_ptr<TranslationVector<> > SimpleMathFactory::createTranslationVector() const
	{
		return unique_ptr<TranslationVector<> >(new SimpleTranslationVector4<>);
	}

	unique_ptr<Vector<> > SimpleMathFactory::createVector() const
	{
		return unique_ptr<Vector<> >(new SimpleVector4<>);
	}
}
