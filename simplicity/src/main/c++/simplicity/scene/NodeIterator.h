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
#ifndef NODEITERATOR_H_
#define NODEITERATOR_H_

#include "Node.h"

namespace simplicity
{
	/**
	 * <p>
	 * Iterates over a graph of {@link simplicity::Node Node}s.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class NodeIterator
	{
		public:
			/**
			 * <p>
			 * Disposes of an instance of <code>NodeIterator</code> (included to allow polymorphic deletion).
			 * </p>
			 */
			virtual ~NodeIterator()
			{
			}

			/**
			 * <p>
			 * Retrieves the next {@link simplicity::Node Node} in the iteration.
			 * </p>
			 *
			 * @return The next <code>Node</code> in the iteration or <code>null</code> if there are no more
			 * <code>Node</code>s to be retrieved by the iteration.
			 */
			virtual std::shared_ptr<Node> getNextNode() = 0;

			/**
			 * <p>
			 * Determines if there are more {@link simplicity::Node Node}s to be retrieved by the iteration.
			 * </p>
			 *
			 * @return True if a <code>Node</code> will be retrieved by the next call to {@link #getNextNode()}, false
			 * otherwise.
			 */
			virtual bool hasMoreNodes() const = 0;

			/**
			 * <p>
			 * Resets this <code>NodeIterator</code> so that the next {@link simplicity::Node Node} retrieved is the
			 * root <code>Node</code> of the graph.
			 * </p>
			 */
			virtual void reset() = 0;
	};
}

#endif /* NODEITERATOR_H_ */