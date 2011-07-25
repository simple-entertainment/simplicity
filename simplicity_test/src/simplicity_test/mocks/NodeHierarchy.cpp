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

using namespace boost;
using namespace simplicity;
using namespace std;

namespace simplicity_test
{
  void
  NodeHierarchy::setBasicNodeHierarchy()
  {
    node1.reset(new SimpleNode);
    node2.reset(new SimpleNode);
    node3.reset(new SimpleModelNode);

    node1->setID(0);
    node1->addChild(node2);
    {
      node2->setID(1);
      node2->addChild(node3);
      node3->setID(2);
    }

    // A white triangle.
    shared_ptr<VectorVG> vertexGroup(new VectorVG);
    float newColours[9] = { 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f };
    shared_ptr<vector<float> > coloursVector(new vector<float>(newColours, newColours + 9));
    vertexGroup->setColours(coloursVector);
    float newNormals[9] = { 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f };
    shared_ptr<vector<float> > normalsVector(new vector<float>(newNormals, newNormals + 9));
    vertexGroup->setNormals(normalsVector);
    float newVertices[9] = { -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f };
    shared_ptr<vector<float> > verticesVector(new vector<float>(newVertices, newVertices + 9));
    vertexGroup->setVertices(verticesVector);

    dynamic_pointer_cast<ModelNode> (node3)->setModel(vertexGroup);
  }

  void
  NodeHierarchy::setStandardNodeHierarchy()
  {
    node1.reset(new SimpleNode);
    node2.reset(new SimpleNode);
    node3.reset(new SimpleModelNode);
    node4.reset(new SimpleNode);
    node5.reset(new SimpleNode);
    node6.reset(new SimpleNode);
    node7.reset(new SimpleNode);

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
    shared_ptr<VectorVG> vertexGroup(new VectorVG);
    float newColours[9] = { 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f };
    shared_ptr<vector<float> > coloursVector(new vector<float>(newColours, newColours + 9));
    vertexGroup->setColours(coloursVector);
    float newNormals[9] = { 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f };
    shared_ptr<vector<float> > normalsVector(new vector<float>(newNormals, newNormals + 9));
    vertexGroup->setNormals(normalsVector);
    float newVertices[9] = { -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f };
    shared_ptr<vector<float> > verticesVector(new vector<float>(newVertices, newVertices + 9));
    vertexGroup->setVertices(verticesVector);

    dynamic_pointer_cast<ModelNode> (node3)->setModel(vertexGroup);
  }
}
