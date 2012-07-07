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
#include "../../math/SimpleVector.h"

#include "../../math/MathFactory.h"
#include "LinearPathWalker.h"

using namespace std;

namespace simplicity
{
	LinearPathWalker::LinearPathWalker(vector<shared_ptr<const Node> > path) :
		distance(0.0f), location(MathFactory::getInstance().createTranslationVector()), nodeDistances(), path(path), totalDistance()
	{
		initNodeDistances();
	}

	unique_ptr<Vector<> > LinearPathWalker::getSegment(const unsigned int segmentStartIndex) const
	{
		unique_ptr<Vector<> > segment = path.at(segmentStartIndex + 1)->getTransformation().getTranslation();
		segment->subtract(*path.at(segmentStartIndex)->getTransformation().getTranslation());

		return move(segment);
	}

	unsigned int LinearPathWalker::getSegmentStartIndex() const
	{
		unsigned int segmentEndIndex = 0;

		while (segmentEndIndex < path.size())
		{
			if (nodeDistances.find(segmentEndIndex)->second > distance)
			{
				return segmentEndIndex - 1;
			}

			segmentEndIndex++;
		}

		return path.size() - 2;
	}

	const TranslationVector<>& LinearPathWalker::getLocation() const
	{
		unsigned int segmentStartIndex = getSegmentStartIndex();
		unique_ptr<Vector<> > segment = getSegment(segmentStartIndex);
		float distanceIntoSegment = distance - nodeDistances.find(segmentStartIndex)->second;

		location = path.at(segmentStartIndex)->getTransformation().getTranslation();

		segment->scale(distanceIntoSegment / segment->getLength());
		location->add(*segment);

		return *location;
	}

	void LinearPathWalker::initNodeDistances()
	{
		shared_ptr<const Node> node;
		float nodeDistance = 0.0f;

		for (unsigned int index = 0; index < path.size(); index++)
		{
			node = path.at(index);
			nodeDistances.insert(pair<unsigned int, float>(index, nodeDistance));

			if (node != path.back())
			{
				nodeDistance += getSegment(index)->getLength();
			}
			else
			{
				totalDistance = nodeDistance;
			}
		}
	}

	bool LinearPathWalker::isAtEnd() const
	{
		return distance == totalDistance;
	}

	bool LinearPathWalker::isAtStart() const
	{
		return distance == 0.0f;
	}

	void LinearPathWalker::step(const float stepDistance)
	{
		distance += stepDistance;

		if (distance > totalDistance)
		{
			distance = totalDistance;
		}
		else if (distance < 0.0f)
		{
			distance = 0.0f;
		}
	}

	void LinearPathWalker::stepBackward(const float stepDistance)
	{
		step(stepDistance * -1);
	}

	void LinearPathWalker::stepForward(const float stepDistance)
	{
		step(stepDistance);
	}
}
