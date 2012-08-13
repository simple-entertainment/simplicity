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
#ifndef PATHFINDER_H_
#define PATHFINDER_H_

#include "../../scene/Node.h"

namespace simplicity
{
	/**
	 * <p>
	 * Finds a path between two {@link simplicity::Node Node}s in network of {@link simplicity::Node Node}s.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class PathFinder
	{
		public:
			/**
			 * <p>
			 * Disposes of an instance of <code>PathFinder</code> (included to allow polymorphic deletion).
			 * </p>
			 */
			virtual ~PathFinder()
			{
			}

			/**
			 * <p>
			 * Finds the shortest path between two {@link simplicity::Node Node}s connected via a network of
			 * {@link simplicity::Node Node}s.
			 * </p>
			 *
			 * @return The shortest path between two {@link simplicity::Node Node}s connected via a network of
			 * {@link simplicity::Node Node}s.
			 */
			virtual std::vector<std::reference_wrapper<const Node> > findShortestPath() = 0;

			/**
			 * <p>
			 * Retrieves the {@link simplicity::Node Node}s that are at 'open' after the last step that was performed.
			 * </p>
			 *
			 * @return The {@link simplicity::Node Node}s that are 'open' after the last step that was performed.
			 */
			virtual std::vector<std::reference_wrapper<const Node> > getOpenNodes() = 0;

			/**
			 * <p>
			 * Performs a step in the path-finding algorithm. After a series of these steps the path (if one exists)
			 * will be found.
			 * </p>
			 *
			 * @return True if the step found a path, false otherwise.
			 */
			virtual bool stepForward() = 0;
	};
}

#endif /* PATHFINDER_H_ */
