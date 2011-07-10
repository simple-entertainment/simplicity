/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <simplicity/model/VectorVG.h>
#include <simplicity/scenegraph/model/SimpleModelNode.h>

#include "NodeHierarchy.h"

namespace simplicity_test
{
  NodeHierarchy::NodeHierarchy()
  {
  }

  NodeHierarchy::~NodeHierarchy()
  {
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete node6;
    delete node7;
  }

  void
  NodeHierarchy::setBasicNodeHierarchy()
  {
    node1 = new SimpleNode();
    node2 = new SimpleNode();
    node3 = new SimpleModelNode();
    node4 = NULL;
    node5 = NULL;
    node6 = NULL;
    node7 = NULL;

    node1->setID(0);
    node1->addChild(node2);
      {
        node2->setID(1);
        node2->addChild(node3);
        node3->setID(2);
      }

    // A white triangle.
    VectorVG * vertexGroup = new VectorVG();
    float newColours[9] =
      { 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f };
    vertexGroup->setColours(vector<float> (newColours, newColours + 9));
    float newNormals[9] =
      { 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f };
    vertexGroup->setNormals(vector<float> (newNormals, newNormals + 9));
    float newVertices[9] =
      { -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f };
    vertexGroup->setVertices(vector<float> (newVertices, newVertices + 9));

    dynamic_cast<ModelNode *> (node3)->setModel(vertexGroup);
  }

  void
  NodeHierarchy::setStandardNodeHierarchy()
  {
    node1 = new SimpleNode();
    node2 = new SimpleNode();
    node3 = new SimpleModelNode();
    node4 = new SimpleNode();
    node5 = new SimpleNode();
    node6 = new SimpleNode();
    node7 = new SimpleNode();

    node1->setID(0);
    node1->addChild(node2);
      {
        node2->setID(1);
        node2->addChild(node3);
        node3->setID(2);
      }

    node1->addChild(node4);
      {
        node4->setID(3);
        node4->addChild(node5);
        node5->setID(4);
        node4->addChild(node6);
        node6->setID(5);
      }

    node1->addChild(node7);
    node7->setID(6);

    // A white triangle.
    VectorVG * vertexGroup = new VectorVG();
    float newColours[9] =
      { 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f };
    vertexGroup->setColours(vector<float> (newColours, newColours + 9));
    float newNormals[9] =
      { 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f };
    vertexGroup->setNormals(vector<float> (newNormals, newNormals + 9));
    float newVertices[9] =
      { -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f };
    vertexGroup->setVertices(vector<float> (newVertices, newVertices + 9));

    dynamic_cast<ModelNode *> (node3)->setModel(vertexGroup);
  }
}
