/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include "Hit.h"

namespace simplicity
{
    Hit::Hit() :
        fMaximumDistance(0), fMinimumDistance(0), fNode(0), fPrimitive(0)
    {
    }

    Hit::~Hit()
    {
    }

    int
    Hit::getMaximumDistance()
    {
        return (fMaximumDistance);
    }

    int
    Hit::getMinimumDistance()
    {
        return (fMinimumDistance);
    }

    Node*
    Hit::getNode()
    {
        return (fNode);
    }

    Model*
    Hit::getPrimitive()
    {
        return (fPrimitive);
    }

    void
    Hit::setMaximumDistance(const int maximumDistance)
    {
        fMaximumDistance = maximumDistance;
    }

    void
    Hit::setMinimumDistance(const int minimumDistance)
    {
        fMinimumDistance = minimumDistance;
    }

    void
    Hit::setNode(Node* const node)
    {
        fNode = node;
    }

    void
    Hit::setPrimitive(Model* const primitive)
    {
        fPrimitive = primitive;
    }
}
