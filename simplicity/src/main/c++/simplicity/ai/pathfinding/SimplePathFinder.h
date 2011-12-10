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
#ifndef SIMPLEPATHFINDER_H_
#define SIMPLEPATHFINDER_H_

#include <map>

#include "../../scene/Node.h"
#include "PathFinder.h"

namespace simplicity
{
	/**
	 * <p>
	 * Performs a simple path-finding algorithm that does not take the weight of any connections into account (i.e. it
	 * assumes all connections to have an equal weight). The algorithm is loosly based on one found on Wikipedia:
	 * http://en.wikipedia.org/wiki/Pathfinding.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class SimplePathFinder : public PathFinder
	{
		public:
			/**
			 * <p>
			 * Creates an instance of <code>SimplePathFinder</code>.
			 * </p>
			 */
			SimplePathFinder(const Node& start, const Node& finish);

			/**
			 * <p>
			 * Disposes of an instance of <code>SimplePathFinder</code>.
			 * </p>
			 */
			virtual ~SimplePathFinder();

			std::vector<boost::shared_ptr<const Node> > findShortestPath();

			std::vector<boost::shared_ptr<const Node> > getOpenNodes();

			bool stepForward();

		private:
			/**
			 * <p>
			 * The distance that has been traversed from the start.
			 * </p>
			 */
			unsigned int distance;

			/**
			 * <p>
			 * The {@link simplicity::Node Node} at which the path is to end.
			 * </p>
			 */
			const Node& finish;

			/**
			 * <p>
			 * The distance of the traversed {@link simplicity::Node Node}s from the start.
			 * </p>
			 */
			std::map<boost::shared_ptr<const Node>, int> nodeDistances;

			/**
			 * <p>
			 * The {@link simplicity::Node Node}s that are 'open' after the last step that was performed.
			 * </p>
			 */
			std::vector<boost::shared_ptr<const Node> > openNodes;

			/**
			 * <p>
			 * The {@link simplicity::Node Node} at which the path is to begin.
			 * </p>
			 */
			const Node& start;

			/**
			 * <p>
			 * The {@link simplicity::Node Node}s that have already been traversed.
			 * </p>
			 */
			std::vector<boost::shared_ptr<const Node> > traversedNodes;

			/**
			 * <p>
			 * Generates the path from the data recorded during a successful search.
			 * </p>
			 *
			 * @return The path.
			 */
			std::vector<boost::shared_ptr<const Node> > generatePath();

			/**
			 * <p>
			 * Determines if the given {@link simplicity::Node Node} has already been traversed.
			 * </p>
			 *
			 * @param node The <code>Node</code> to check.
			 *
			 * @return True if the given <code>Node</code> has already been traversed, false otherwise.
			 */
			bool isTraversed(const Node& node);

			/**
			 * <p>
			 * Records the given {@link simplicity::Node Node} in the list of traversed {@link simplicity::Node Node}s.
			 * </p>
			 *
			 * @param node The <code>Node</code> to record.
			 */
			void markAsTraversed(const Node& node);
	};
}

#endif /* SIMPLEPATHFINDER_H_ */
