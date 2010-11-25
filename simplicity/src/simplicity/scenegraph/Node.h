/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef NODE_H_
#define NODE_H_

#include <vector>
using namespace std;

#include "../model/BoundingVolume.h"
#include "../vector/TransformationMatrixf.h"

namespace simplicity
{
    /**
     * <p>
     * A component of a {@link simplicity::SceneGraph SceneGraph}.
     * </p>
     *
     * @author Gary Buyn
     */
    class Node
    {
        public:
            /**
             * <p>
             * Disposes of an instance of <code>Node</code> (included to allow polymorphic deletion).
             * </p>
             */
            virtual
            ~Node()
            {
            }

            /**
             * <p>
             * Adds a child to this <code>Node</code>.
             * </p>
             *
             * @param child The <code>Node</code> to add to this <code>Node</code>'s children.
             */
            virtual void
            addChild(Node* const child) = 0;

            /**
             * <p>
             * Retrieves this <code>Node</code>'s absolute position and orientation.
             * </p>
             *
             * <p>
             * The caller must assume ownership of the returned <code>TransformationMatrixf</code>.
             * </p>
             *
             * @return This <code>Node</code>'s absolute position and orientation.
             */
            virtual TransformationMatrixf*
            getAbsoluteTransformation() = 0;

            /**
             * <p>
             * Retrieves a volume containing all the {@link simplicity::Model Model}s within the subgraph of which this <code>Node</code> is the
             * root.
             * </p>
             *
             * @return A volume containing all the <code>Model</code>s within the subgraph of which this <code>Node</code> is the
             * root.
             */
            virtual BoundingVolume*
            getBounds() = 0;

            /**
             * <p>
             * Retrieves the <code>Node</code>s directly below this <code>Node</code> in a {@link simplicity::SceneGraph SceneGraph}.
             * </p>
             *
             * @return The <code>Node</code>s directly below this <code>Node</code> in a <code>SceneGraph</code>.
             */
            virtual vector<Node*>*
            getChildren() = 0;

            /**
             * <p>
             * Retrieves this <code>Node</code>'s unique identifier.
             * </p>
             *
             * @return This <code>Node</code>'s unique identifier.
             */
            virtual int
            getID() = 0;

            /**
             * <p>
             * Retrieves the <code>Node</code> directly above this <code>Node</code> in a {@link simplicity::SceneGraph SceneGraph}.
             * </p>
             *
             * @return The <code>Node</code> directly above this <code>Node</code> in a <code>SceneGraph</code>.
             */
            virtual Node*
            getParent() = 0;

            /**
             * <p>
             * Retrieves this <code>Node</code>'s relative position and orientation.
             * </p>
             *
             * @return This <code>Node</code>'s relative position and orientation.
             */
            virtual TransformationMatrixf*
            getTransformation() = 0;

            /**
             * <p>
             * Determines if children exist for this <code>Node</code>.
             * </p>
             *
             * @return True if children exist for this <code>Node</code>, false otherwise.
             */
            virtual bool
            hasChildren() = 0;

            /**
             * <p>
             * Determines if the given <code>Node</code> is an ancestor of this <code>Node</code>.
             * </p>
             *
             * @param ancestor The <code>Node</code> to check.
             * @return True if the given <code>Node</code> is an ancestor of this <code>Node</code>, false otherwise.
             */
            virtual bool
            isAncestor(Node* const ancestor) = 0;

            /**
             * <p>
             * Determines if this <code>Node</code> can collide with other <code>Node</code>s in the {@link simplicity::SceneGraph
             * SceneGraph} (determines if it should be included in collision detection).
             * </p>
             *
             * @return True if this <code>Node</code> can collide with other <code>Node</code>s in the <code>SceneGraph</code>, false otherwise.
             */
            virtual bool
            isCollidable() = 0;

            /**
             * <p>
             * Determines if this <code>Node</code> can be modified.
             * </p>
             *
             * @return True if this <code>Node</code> can be modified, false otherwise.
             */
            virtual bool
            isModifiable() = 0;

            /**
             * <p>
             * Determines if the given <code>Node</code> is a successor of this <code>Node</code>.
             * </p>
             *
             * @param successor The <code>Node</code> to check.
             * @return True if the given <code>Node</code> is a successor of this <code>Node</code>, false otherwise.
             */
            virtual bool
            isSuccessor(Node* const successor) = 0;

            /**
             * <p>
             * Determines if this <code>Node</code> is visible (determines if it should be rendered).
             * </p>
             *
             * @return True if this <code>Node</code> is visible, false otherwise.
             */
            virtual bool
            isVisible() = 0;

            /**
             * <p>
             * Removes a child from this <code>Node</code>.
             * </p>
             *
             * @param child The child to be removed.
             */
            virtual void
            removeChild(Node* const child) = 0;

            /**
             * <p>
             * Retrieves a volume containing all the {@link simplicity::Model Model}s within the subgraph of which this <code>Node</code> is the
             * root.
             * </p>
             *
             * <p>
             * This <code>Node</code> will assume ownership of the given <code>BoundingVolume</code> and the previously held <code>BoundingVolume</code> will be deleted.
             * </p>
             *
             * @param bounds A volume containing all the <code>Model</code>s within the subgraph of which this <code>Node</code> is
             * the root.
             */
            virtual void
            setBounds(BoundingVolume* const bounds) = 0;

            /**
             * <p>
             * Sets the collision mode.
             * </p>
             *
             * @param collidable Determines if this <code>Node</code> can collide with other <code>Node</code>s in the
             * {@link simplicity.scenegraph.SceneGraph SceneGraph} (determines if it should be included in collision detection).
             */
            virtual void
            setCollidable(const bool collidable) = 0;

            /**
             * <p>
             * Sets this <code>Node</code>'s unique identifier. This identifier should be managed by the {@link simplicity.scenegraph.SceneGraph
             * SceneGraph}.
             * </p>
             *
             * @param id This <code>Node</code>'s unique identifier.
             */
            virtual void
            setID(const int id) = 0;

            /**
             * <p>
             * Sets the modification mode.
             * </p>
             *
             * @param modifiable Determines if this <code>Node</code> can be modified.
             */
            virtual void
            setModifiable(const bool modifiable) = 0;

            /**
             * <p>
             * Sets the <code>Node</code> directly above this <code>Node</code> in a {@link simplicity.scenegraph.SceneGraph SceneGraph}.
             * </p>
             *
             * @param parent The <code>Node</code> directly above this <code>Node</code> in a {@link simplicity.scenegraph.SceneGraph SceneGraph}.
             */
            virtual void
            setParent(Node* const parent) = 0;

            /**
             * <p>
             * Sets this <code>Node</code>'s relative position and orientation.
             * </p>
             *
             * <p>
             * This <code>Node</code> will assume ownership of the given <code>TransformationMatrixf</code> and the previously held <code>TransformationMatrixf</code> will be deleted.
             * </p>
             *
             * @param transformation This <code>Node</code>'s relative position and orientation.
             */
            virtual void
            setTransformation(TransformationMatrixf* const transformation) = 0;

            /**
             * <p>
             * The visibility mode.
             * </p>
             *
             * @param visible Determines if this <code>Node</code> is visible (determines if it should be rendered).
             */
            virtual void
            setVisible(const bool visible) = 0;
    };
}

#endif /* NODE_H_ */
