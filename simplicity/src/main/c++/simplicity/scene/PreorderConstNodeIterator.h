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
#ifndef PREORDERCONSTNODEITERATOR_H_
#define PREORDERCONSTNODEITERATOR_H_

#include "ConstNodeIterator.h"

namespace simplicity
{
	/**
	 * <p>
	 * A preorder iteration over an acyclic read-only read-only graph of {@link simplicity::Node Node}s.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class PreorderConstNodeIterator : public ConstNodeIterator
	{
		public:
			/**
			 * <p>
			 * Creates an instance of <code>PreorderConstNodeIterator</code>.
			 * </p>
			 *
			 * @param root The root {@link simplicity::Node Node} of the graph to iterate over.
			 */
			PreorderConstNodeIterator(const Node& root);

			/**
			 * <p>
			 * Disposes of an instance of <code>PreorderConstNodeIterator</code>.
			 * </p>
			 */
			virtual ~PreorderConstNodeIterator();

			/**
			 * <p>
			 * Retrieves the number of backtracks required to get to the next {@link simplicity::Node Node}.
			 * </p>
			 *
			 * <p>
			 * A backtrack is an upward movement in the graph being iterated. An additional backtrack is performed at
			 * the end of a iteration to move above back to the root. This ensures that the number of backtracks
			 * performed is equal to the number of downward movements performed including the initial downward movement
			 * to the root when {@link getNextNode()} is first called.
			 * </p>
			 *
			 * @return The number of backtracks required to get to the next <code>Node</code>.
			 */
			int getBacktracksToNextNode() const;

			const Node& getNextNode();

			bool hasMoreNodes() const;

		private:
			/**
			 * <p>
			 * The number of backtracks required to get to the next {@link simplicity::Node Node}.
			 * </p>
			 */
			int backtracksToNextNode;

			/**
			 * <p>
			 * The next {@link simplicity::Node Node} to retrieve from the iteration.
			 * </p>
			 */
			const Node* nextNode;

			/**
			 * <p>
			 * The root {@link simplicity::Node Node} of the graph to iterate over.
			 * </p>
			 */
			const Node& root;

			/**
			 * <p>
			 * Finds the next {@link simplicity::Node Node} in the iteration, updating the state variables
			 * appropriately.
			 * </p>
			 *
			 * @return The next <code>Node</code> in the iteration.
			 */
			const Node* findNextNode();
	};
}

#endif /* PREORDERCONSTNODEITERATOR_H_ */
