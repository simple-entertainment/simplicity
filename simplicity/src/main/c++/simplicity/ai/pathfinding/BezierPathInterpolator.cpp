/*
 * Copyright © 2011 Simple Entertainment Limited
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
#include "../../math/SimpleTranslationVector4.h"
#include "BezierPathInterpolator.h"

using namespace boost;
using namespace std;

namespace simplicity
{
	BezierPathInterpolator::BezierPathInterpolator(vector<shared_ptr<const Node> > path) :
		path(path)
	{
	}

	BezierPathInterpolator::~BezierPathInterpolator()
	{
	}

	shared_ptr<TranslationVector<float> > BezierPathInterpolator::interpolate(const float time)
	{
		shared_ptr<Vector<float> > b = interpolate(time, path.begin(), path.end());

		// TODO Remove the dependency on concrete class SimpleTranslationVector4.
		shared_ptr<TranslationVector<float> > bTranslation(new SimpleTranslationVector4<float>);
		bTranslation->setX(b->getRawData()[0]);
		bTranslation->setY(b->getRawData()[1]);
		bTranslation->setZ(b->getRawData()[2]);

		return bTranslation;
	}

	shared_ptr<Vector<float> > BezierPathInterpolator::interpolate(const float time,
		const vector<shared_ptr<const Node> >::iterator& begin, const vector<shared_ptr<const Node> >::iterator& end)
	{
		if (begin + 1 == end)
		{
			return (*begin)->getTransformation().getTranslation();
		}

		shared_ptr<Vector<float> > p0 = interpolate(time, begin, end - 1);
		p0->scale(1 - time);

		shared_ptr<Vector<float> > p1 = interpolate(time, begin + 1, end);
		p1->scale(time);

		p0->add(*p1);

		return p0;
	}
}
