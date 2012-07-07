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
#ifndef LINEARPATHWALKER_H_
#define LINEARPATHWALKER_H_

#include <map>

#include "../../scene/Node.h"
#include "PathWalker.h"

namespace simplicity
{
	/**
	 * <p>
	 * Walks along a given path in either direction.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class LinearPathWalker : public PathWalker
	{
		public:
			LinearPathWalker(std::vector<std::shared_ptr<const Node> > path);

			const TranslationVector<> & getLocation() const;

			bool isAtEnd() const;

			bool isAtStart() const;

			void stepBackward(const float stepDistance);

			void stepForward(const float stepDistance);

		private:

			float distance;

			mutable std::unique_ptr<TranslationVector<> > location;

			std::map<unsigned int, float> nodeDistances;

			std::vector<std::shared_ptr<const Node> > path;

			float totalDistance;

			std::unique_ptr<Vector<> > getSegment(const unsigned int segmentStartIndex) const;

			unsigned int getSegmentStartIndex() const;

			void initNodeDistances();

			void step(const float stepDistance);
	};
}

#endif /* LINEARPATHWALKER_H_ */
