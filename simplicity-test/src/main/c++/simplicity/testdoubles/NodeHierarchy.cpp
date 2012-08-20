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
#include <simplicity/graph/SimpleNode.h>

#include "NodeHierarchy.h"

using namespace std;

namespace simplicity
{
	void NodeHierarchy::setBasicNodeHierarchy()
	{
		node1.setId(0);
		{
			node2.setId(1);
			node2.connectTo(node1);
			node1.addChild(node2);
			{
				node3.setId(2);
				node3.connectTo(node2);
				node2.addChild(node3);
			}
		}

		// A white triangle.
		float newColours[9] = {1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f};
		shared_ptr<vector<float> > coloursVector(new vector<float>(newColours, newColours + 9));
		model.setColours(coloursVector);
		float newNormals[9] = {0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f};
		shared_ptr<vector<float> > normalsVector(new vector<float>(newNormals, newNormals + 9));
		model.setNormals(normalsVector);
		float newVertices[9] = {-1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f};
		shared_ptr<vector<float> > verticesVector(new vector<float>(newVertices, newVertices + 9));
		model.setVertices(verticesVector);

		node3.setComponent(&model);
	}

	void NodeHierarchy::setStandardNodeHierarchy()
	{
		node1.setId(0);
		{
			node2.setId(1);
			node2.connectTo(node1);
			node1.addChild(node2);
			{
				node3.setId(2);
				node3.connectTo(node2);
				node2.addChild(node3);
			}
		}
		{
			node4.setId(3);
			node4.connectTo(node1);
			node1.addChild(node4);
			{
				node5.setId(4);
				node5.connectTo(node4);
				node4.addChild(node5);
				node6.setId(5);
				node6.connectTo(node4);
				node4.addChild(node6);
			}
		}
		{
			node7.setId(6);
			node7.connectTo(node1);
			node1.addChild(node7);
		}

		// A white triangle.
		float newColours[9] = {1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f};
		shared_ptr<vector<float> > coloursVector(new vector<float>(newColours, newColours + 9));
		model.setColours(coloursVector);
		float newNormals[9] = {0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f};
		shared_ptr<vector<float> > normalsVector(new vector<float>(newNormals, newNormals + 9));
		model.setNormals(normalsVector);
		float newVertices[9] = {-1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f};
		shared_ptr<vector<float> > verticesVector(new vector<float>(newVertices, newVertices + 9));
		model.setVertices(verticesVector);

		node3.setComponent(&model);
	}
}
