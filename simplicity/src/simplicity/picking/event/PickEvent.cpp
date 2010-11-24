/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include "PickEvent.h"

namespace simplicity
{
    PickEvent::PickEvent() :
        fHits(vector<Hit> ())
    {
    }

    PickEvent::~PickEvent()
    {
    }

    void
    PickEvent::addHit(const Hit hit)
    {
        fHits.push_back(hit);
    }

    optional<Hit>
    PickEvent::getCloseHit()
    {
        optional<Hit> closeHit;
        for (unsigned int index = 0; index < fHits.size(); index++)
        {
            if (!closeHit || fHits.at(index).getMinimumDistance() < closeHit->getMinimumDistance())
            {
                closeHit = optional<Hit> (fHits.at(index));
            }
        }

        return (closeHit);
    }

    Hit
    PickEvent::getHit(const int index)
    {
        return (fHits.at(index));
    }

    int
    PickEvent::getHitCount()
    {
        return (fHits.size());
    }
}
