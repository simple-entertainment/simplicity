/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef NODEHIERARCHY_H_
#define NODEHIERARCHY_H_

#include <simplicity/scenegraph/Node.h>

namespace simplicity_test
{
  /**
   * <p>
   * Standard reusable node hierarchies for test purposes.
   * </p>
   *
   * @author Gary Buyn
   */
  struct NodeHierarchy
  {
      /**
       * <p>
       * The first node of the hierarchy.
       * </p>
       */
      boost::shared_ptr<simplicity::Node> node1;

      /**
       * <p>
       * The second node of the hierarchy.
       * </p>
       */
      boost::shared_ptr<simplicity::Node> node2;

      /**
       * <p>
       * The third node of the hierarchy.
       * </p>
       */
      boost::shared_ptr<simplicity::Node> node3;

      /**
       * <p>
       * The fourth node of the hierarchy.
       * </p>
       */
      boost::shared_ptr<simplicity::Node> node4;

      /**
       * <p>
       * The fifth node of the hierarchy.
       * </p>
       */
      boost::shared_ptr<simplicity::Node> node5;

      /**
       * <p>
       * The sixth node of the hierarchy.
       * </p>
       */
      boost::shared_ptr<simplicity::Node> node6;

      /**
       * <p>
       * The seventh node of the hierarchy.
       * </p>
       */
      boost::shared_ptr<simplicity::Node> node7;

      /**
       * <p>
       * Builds a basic node hierarchy involving 3 nodes. The third node contains a white triangle. It is structured as follows:
       * </p>
       *
       * <code>
       * <pre>
       * node1
       *   - node2
       *     - node3
       * </pre>
       * </code>
       */
      void
      setBasicNodeHierarchy();

      /**
       * <p>
       * Builds a node hierarchy involving all 7 nodes. The third node contains a white triangle. It is structured as follows:
       * </p>
       *
       * <code>
       * <pre>
       * node1
       *   - node2
       *     - node3
       *   - node4
       *     - node5
       *     - node6
       *   - node7
       * </pre>
       * </code>
       */
      void
      setStandardNodeHierarchy();
  };
}

#endif /* NODEHIERARCHY_H_ */
