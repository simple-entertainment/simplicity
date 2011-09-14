/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include "SimpleNode.h"
#include "SimpleTraversal.h"
#include "../vector/SimpleTransformationMatrix44.h"

using namespace boost;
using namespace std;

namespace simplicity
{
  SimpleNode::SimpleNode() :
    fChildren(vector<shared_ptr<Node> > ()), fCollidable(true), fId(0), fModifiable(true),
        fTransformation(new SimpleTransformationMatrix44<float> ), fVisible(true)
  {
  }

  SimpleNode::~SimpleNode()
  {
  }

  void
  SimpleNode::addChild(shared_ptr<Node> child)
  {
    fChildren.push_back(child);
    child->setParent(getThisShared());
  }

  const TransformationMatrix<float>&
  SimpleNode::getAbsoluteTransformation() const
  {
    fAbsoluteTransformation.reset(new SimpleTransformationMatrix44<float> );
    Node* thisNode = (Node*) this;
    shared_ptr<Node> currentNode(thisNode->getThisShared());

    while (currentNode.get())
    {
      fAbsoluteTransformation->multiplyLeft(currentNode->getTransformation());

      currentNode = currentNode->getParent();
    }

    return (*fAbsoluteTransformation);
  }

  //  const BoundingVolume& TODO
  //  SimpleNode::getBounds() const
  //  {
  //    return (fBounds);
  //  }

  const vector<shared_ptr<Node> >&
  SimpleNode::getChildren() const
  {
    return (fChildren);
  }

  int
  SimpleNode::getID() const
  {
    return (fId);
  }

  shared_ptr<Node>
  SimpleNode::getParent() const
  {
    return (fParent);
  }

  TransformationMatrix<float>&
  SimpleNode::getTransformation() const
  {
    return (*fTransformation);
  }

  bool
  SimpleNode::hasChildren() const
  {
    bool children = false;

    if (!fChildren.empty())
    {
      children = true;
    }

    return (children);
  }

  bool
  SimpleNode::isAncestor(const Node& ancestor) const
  {
    shared_ptr<Node> currentParent(fParent);

    while (currentParent)
    {
      if (currentParent.get() == &ancestor)
      {
        return (true);
      }

      currentParent = currentParent->getParent();
    }

    return (false);
  }

  bool
  SimpleNode::isCollidable() const
  {
    return (fCollidable);
  }

  bool
  SimpleNode::isModifiable() const
  {
    return (fModifiable);
  }

  bool
  SimpleNode::isSuccessor(const Node& successor) const
  {
    SimpleTraversal traversal(*this);

    while (traversal.hasMoreNodes())
    {
      if (traversal.getNextNode().get() == &successor && &successor != this)
      {
        return (true);
      }
    }

    return (false);
  }

  bool
  SimpleNode::isVisible() const
  {
    return (fVisible);
  }

  void
  SimpleNode::removeChild(Node& child)
  {
    vector<shared_ptr<Node> >::iterator iterator = fChildren.begin();
    for (unsigned int index = 0; index < fChildren.size(); index++)
    {
      if (fChildren.at(index).get() == &child)
      {
        fChildren.erase(iterator);
        child.setParent(shared_ptr<Node> ());
        break;
      }

      iterator++;
    }
  }

  void
  SimpleNode::setCollidable(const bool collidable)
  {
    fCollidable = collidable;
  }

  void
  SimpleNode::setID(const int id)
  {
    fId = id;
  }

  void
  SimpleNode::setModifiable(const bool modifiable)
  {
    fModifiable = modifiable;
  }

  void
  SimpleNode::setParent(shared_ptr<Node> parent)
  {
    fParent = parent;
  }

  void
  SimpleNode::setTransformation(shared_ptr<TransformationMatrix<float> > transformation)
  {
    fTransformation = transformation;
  }

  void
  SimpleNode::setVisible(const bool visible)
  {
    fVisible = visible;
  }
}
