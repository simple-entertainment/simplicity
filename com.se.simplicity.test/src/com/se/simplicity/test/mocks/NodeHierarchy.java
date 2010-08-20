/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.test.mocks;

import com.se.simplicity.model.ArrayVG;
import com.se.simplicity.scenegraph.SimpleNode;
import com.se.simplicity.scenegraph.model.SimpleModelNode;

/**
 * <p>
 * Standard reusable node hierarchies for test purposes.
 * </p>
 * 
 * @author Gary Buyn
 */
public class NodeHierarchy
{
    /**
     * <p>
     * The first node of the hierarchy.
     * </p>
     */
    public SimpleNode node1;

    /**
     * <p>
     * The second node of the hierarchy.
     * </p>
     */
    public SimpleNode node2;

    /**
     * <p>
     * The third node of the hierarchy.
     * </p>
     */
    public SimpleNode node3;

    /**
     * <p>
     * The fourth node of the hierarchy.
     * </p>
     */
    public SimpleNode node4;

    /**
     * <p>
     * The fifth node of the hierarchy.
     * </p>
     */
    public SimpleNode node5;

    /**
     * <p>
     * The sixth node of the hierarchy.
     * </p>
     */
    public SimpleNode node6;

    /**
     * <p>
     * The seventh node of the hierarchy.
     * </p>
     */
    public SimpleNode node7;

    /**
     * <p>
     * Builds a basic node hierarchy involving 3 nodes. The third node contains a white triangle. It is structured as follows:
     * </p>
     * 
     * <pre>
     * node1 - node2 - node3
     * </pre>
     */
    public void setBasicNodeHierarchy()
    {
        node1 = new SimpleNode();
        node2 = new SimpleNode();
        node3 = new SimpleModelNode();
        node4 = null;
        node5 = null;
        node6 = null;
        node7 = null;

        node1.setID(0);
        node1.addChild(node2);
        {
            node2.setID(1);
            node2.addChild(node3);
            node3.setID(2);
        }

        // A white triangle.
        ArrayVG vertexGroup = new ArrayVG();
        vertexGroup.setColours(new float[] {1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f});
        vertexGroup.setNormals(new float[] {0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f});
        vertexGroup.setVertices(new float[] {-1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f});

        ((SimpleModelNode) node3).setVertexGroup(vertexGroup);
    }

    /**
     * <p>
     * Builds a node hierarchy involving all 7 nodes. The third node contains a white triangle. It is structured as follows:
     * </p>
     * 
     * <pre>
     * node1 - node2 - node3 - node4 - node5 - node6 - node7
     * </pre>
     */
    public void setStandardNodeHierarchy()
    {
        node1 = new SimpleNode();
        node2 = new SimpleNode();
        node3 = new SimpleModelNode();
        node4 = new SimpleNode();
        node5 = new SimpleNode();
        node6 = new SimpleNode();
        node7 = new SimpleNode();

        node1.setID(0);
        node1.addChild(node2);
        {
            node2.setID(1);
            node2.addChild(node3);
            node3.setID(2);
        }

        node1.addChild(node4);
        {
            node4.setID(3);
            node4.addChild(node5);
            node5.setID(4);
            node4.addChild(node6);
            node6.setID(5);
        }

        node1.addChild(node7);
        node7.setID(6);

        // A white triangle.
        ArrayVG vertexGroup = new ArrayVG();
        vertexGroup.setColours(new float[] {1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f});
        vertexGroup.setNormals(new float[] {0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f});
        vertexGroup.setVertices(new float[] {-1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f});

        ((SimpleModelNode) node3).setVertexGroup(vertexGroup);
    }
}
