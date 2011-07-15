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

namespace simplicity
{
  SimpleNode::SimpleNode() :
    fBounds(0), fChildren(vector<Node *> ()), fCollidable(true), fId(0), fModifiable(true), fParent(0),
        fTransformation(new SimpleTransformationMatrix44<float> ()), fVisible(true)
  {
  }

  SimpleNode::~SimpleNode()
  {
    delete fBounds;
    delete fTransformation;
  }

  void
  SimpleNode::addChild(Node * const child)
  {
    fChildren.push_back(child);
    child->setParent(this);
  }

  TransformationMatrix<float> *
  SimpleNode::getAbsoluteTransformation() const
  {
    TransformationMatrix<float> * transformation = new SimpleTransformationMatrix44<float> ();
    Node * currentNode = (Node *) this;

    while (currentNode)
      {
        transformation->multiplyLeft(currentNode->getTransformation());

        currentNode = currentNode->getParent();
      }

    return (transformation);
  }

  BoundingVolume *
  SimpleNode::getBounds() const
  {
    return (fBounds);
  }

  vector<Node *>
  SimpleNode::getChildren() const
  {
    return (fChildren);
  }

  int
  SimpleNode::getID() const
  {
    return (fId);
  }

  Node *
  SimpleNode::getParent() const
  {
    return (fParent);
  }

  TransformationMatrix<float> *
  SimpleNode::getTransformation() const
  {
    return (fTransformation);
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
  SimpleNode::isAncestor(Node const * const ancestor) const
  {
    Node * currentParent = fParent;

    while (currentParent)
      {
        if (currentParent == ancestor)
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
  SimpleNode::isSuccessor(Node const * const successor) const
  {
    SimpleTraversal traversal(this);

    while (traversal.hasMoreNodes())
      {
        if (traversal.getNextNode() == successor && successor != this)
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
  SimpleNode::removeChild(Node * const child)
  {
    vector<Node *>::iterator iterator = fChildren.begin();
    for (unsigned int index = 0; index < fChildren.size(); index++)
      {
        if (fChildren.at(index) == child)
          {
            fChildren.erase(iterator);
            child->setParent(NULL);
            break;
          }

        iterator++;
      }
  }

  void
  SimpleNode::setBounds(BoundingVolume * const bounds)
  {
    delete fBounds;

    fBounds = bounds;
  }

  void
  SimpleNode::setCollidable(bool const collidable)
  {
    fCollidable = collidable;
  }

  void
  SimpleNode::setID(int const id)
  {
    fId = id;
  }

  void
  SimpleNode::setModifiable(bool const modifiable)
  {
    fModifiable = modifiable;
  }

  void
  SimpleNode::setParent(Node * const parent)
  {
    fParent = parent;
  }

  void
  SimpleNode::setTransformation(TransformationMatrix<float> * const transformation)
  {
    delete fTransformation;

    fTransformation = transformation;
  }

  void
  SimpleNode::setVisible(bool const visible)
  {
    fVisible = visible;
  }
}
