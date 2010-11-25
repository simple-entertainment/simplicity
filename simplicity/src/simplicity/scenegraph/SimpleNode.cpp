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
#include "../vector/SimpleTransformationMatrixf44.h"

namespace simplicity
{
    SimpleNode::SimpleNode() :
        fBounds(0), fChildren(new vector<Node*> ()), fCollidable(true), fId(0), fModifiable(true), fParent(0), fTransformation(
                new SimpleTransformationMatrixf44()), fVisible(true)
    {
    }

    SimpleNode::~SimpleNode()
    {
        delete fBounds;
        delete fChildren;
        delete fTransformation;
    }

    void
    SimpleNode::addChild(Node* const child)
    {
        fChildren->push_back(child);
        child->setParent(this);
    }

    TransformationMatrixf*
    SimpleNode::getAbsoluteTransformation()
    {
        TransformationMatrixf* transformation = new SimpleTransformationMatrixf44();
        Node* currentNode = this;

        while (currentNode)
        {
            transformation->multiplyLeft(currentNode->getTransformation());

            currentNode = currentNode->getParent();
        }

        return (transformation);
    }

    BoundingVolume*
    SimpleNode::getBounds()
    {
        return (fBounds);
    }

    vector<Node*>*
    SimpleNode::getChildren()
    {
        return (fChildren);
    }

    int
    SimpleNode::getID()
    {
        return (fId);
    }

    Node*
    SimpleNode::getParent()
    {
        return (fParent);
    }

    TransformationMatrixf*
    SimpleNode::getTransformation()
    {
        return (fTransformation);
    }

    bool
    SimpleNode::hasChildren()
    {
        if (fChildren->size() == 0)
        {
            return (false);
        }

        return (true);
    }

    bool
    SimpleNode::isAncestor(Node* const ancestor)
    {
        Node* currentParent = fParent;

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
    SimpleNode::isCollidable()
    {
        return (fCollidable);
    }

    bool
    SimpleNode::isModifiable()
    {
        return (fModifiable);
    }

    bool
    SimpleNode::isSuccessor(Node* const successor)
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
    SimpleNode::isVisible()
    {
        return (fVisible);
    }

    void
    SimpleNode::removeChild(Node* const child)
    {
        vector<Node*>::iterator iterator = fChildren->begin();
        for (unsigned int index = 0; index < fChildren->size(); index++)
        {
            if (fChildren->at(index) == child)
            {
                fChildren->erase(iterator);
                child->setParent(NULL);
                break;
            }

            iterator++;
        }
    }

    void
    SimpleNode::setBounds(BoundingVolume* const bounds)
    {
        delete fBounds;

        fBounds = bounds;
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
    SimpleNode::setParent(Node* const parent)
    {
        fParent = parent;
    }

    void
    SimpleNode::setTransformation(TransformationMatrixf* const transformation)
    {
        delete fTransformation;

        fTransformation = transformation;
    }

    void
    SimpleNode::setVisible(const bool visible)
    {
        fVisible = visible;
    }
}
