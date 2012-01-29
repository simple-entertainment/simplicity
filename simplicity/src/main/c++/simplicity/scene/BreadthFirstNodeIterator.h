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
#ifndef BREADTHFIRSTNODEITERATOR_H_
#define BREADTHFIRSTNODEITERATOR_H_

#include <queue>

#include "NodeIterator.h"

namespace simplicity
{
	/**
	 * <p>
	 * A breadth first iteration over a graph (acyclic or cyclic) of {@link simplicity::Node Node}s.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class BreadthFirstNodeIterator : public NodeIterator
	{
		public:
			/**
			 * <p>
			 * Creates an instance of <code>BreadthFirstNodeIterator</code>.
			 * </p>
			 *
			 * @param root The root {@link simplicity::Node Node} of the graph to iterate over.
			 */
			BreadthFirstNodeIterator(const Node& root);

			/**
			 * <p>
			 * Disposes of an instance of <code>BreadthFirstNodeIterator</code>.
			 * </p>
			 */
			virtual ~BreadthFirstNodeIterator();

			std::shared_ptr<Node> getNextNode();

			bool hasMoreNodes() const;

			void reset();

		private:
			/**
			 * <p>
			 * The {@link simplicity::Node Node}s that have already been visited by the iteration.
			 * </p>
			 */
			std::vector<std::shared_ptr<Node> > queuedNodes;

			/**
			 * <p>
			 * The root {@link simplicity::Node Node} of the graph to iterate over.
			 * </p>
			 */
			const Node& root;

			/**
			 * <p>
			 * The {@link simplicity::Node Node}s who are still to be visited.
			 * </p>
			 */
			std::queue<std::shared_ptr<Node> > unvisitedNodes;
	};
}

#endif /* BREADTHFIRSTNODEITERATOR_H_ */
