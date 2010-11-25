/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SIMPLETRAVERSAL_H_
#define SIMPLETRAVERSAL_H_

#include "Traversal.h"

namespace simplicity
{
    /**
     * <p>
     * A simple traversal that traverses {@link simplicity::Node Node}s in a prefix order.
     * </p>
     *
     * @author Gary Buyn
     */
    class SimpleTraversal : public Traversal
    {
        public:
            /**
             * <p>
             * Creates an instance of <code>SimpleTraversal</code>.
             * </p>
             *
             * @param root The root {@link simplicity::Node Node} of the graph to traverse.
             */
            SimpleTraversal(Node* const root);

            /**
             * <p>
             * Disposes of an instance of <code>SimpleTraversal</code>.
             * </p>
             */
            virtual
            ~SimpleTraversal();

            Node*
            getNextNode();

            bool
            hasMoreNodes();

            void
            reset();

        private:
            /**
             * <p>
             * The number of backtracks required to get to the next {@link simplicity::Node Node}.
             * </p>
             */
            int fBacktracksToNextNode;

            /**
             * <p>
             * The next {@link simplicity::Node Node} to retrieve from this traversal.
             * </p>
             */
            Node* fNextNode;

            /**
             * <p>
             * The root {@link simplicity::Node Node} of the graph to traverse.
             * </p>
             */
            Node* fRoot;

            /**
             * <p>
             * Finds the next {@link simplicity::Node Node} in this traversal, updating the state variables appropriately.
             * </p>
             *
             * @return The next <code>Node</code> in this traversal,
             */
            Node*
            findNextNode();

            /**
             * <p>
             * Retrieves the number of backtracks required to get to the next {@link com.se.simplicity.scenegraph.Node Node}.
             * </p>
             *
             * <p>
             * A backtrack is an upward movement in the graph being traversed. An additional backtrack is performed at the end of a traversal to move above
             * back to the root. This ensures that the number of backtracks performed is equal to the number of downward movements performed including the
             * initial downward movement to the root when <code>getNextNode()</code> is first called.
             * </p>
             *
             * @return The number of backtracks required to get to the next <code>Node</code>.
             */
            int
            getBacktracksToNextNode();
    };
}

#endif /* SIMPLETRAVERSAL_H_ */
