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
#include "../../math/SimpleTranslationVector.h"
#include "BezierPathInterpolator.h"

using namespace std;

namespace simplicity
{
	BezierPathInterpolator::BezierPathInterpolator(vector<std::shared_ptr<const Node> > path) :
		path(path)
	{
	}

	BezierPathInterpolator::~BezierPathInterpolator()
	{
	}

	unique_ptr<TranslationVector<> > BezierPathInterpolator::interpolate(const float time)
	{
		return interpolate(time, path.begin(), path.end());
	}

	unique_ptr<TranslationVector<> > BezierPathInterpolator::interpolate(const float time,
		const vector<std::shared_ptr<const Node> >::iterator& begin,
		const vector<std::shared_ptr<const Node> >::iterator& end)
	{
		if (begin + 1 == end)
		{
			return (*begin)->getTransformation().getTranslation();
		}

		unique_ptr<TranslationVector<> > p0 = interpolate(time, begin, end - 1);
		p0->scale(1 - time);

		unique_ptr<TranslationVector<> > p1 = interpolate(time, begin + 1, end);
		p1->scale(time);

		p0->add(*p1);

		return move(p0);
	}
}
