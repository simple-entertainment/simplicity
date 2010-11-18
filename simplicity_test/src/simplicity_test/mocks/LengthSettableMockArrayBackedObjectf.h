/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef LENGTHSETTABLEMOCKARRAYBACKEDOBJECTF_H_
#define LENGTHSETTABLEMOCKARRAYBACKEDOBJECTF_H_

#include <simplicity/vector/ArrayBackedObjectf.h>
using namespace simplicity;

namespace simplicity_test
{
    /**
     * <p>
     * An object <code>ArrayBackedObjectf</code> whose length can be chosen upon construction.
     * </p>
     *
     * @author Gary Buyn
     */
    class LengthSettableMockArrayBackedObjectf : public simplicity::ArrayBackedObjectf
    {
        public:
            /**
             * <p>
             * Creates an instance of <code>LengthSettableMockArrayBackedObjectf</code>.
             * </p>
             *
             * @param length The length of the array that contains the data for this object.
             */
            LengthSettableMockArrayBackedObjectf(const int length);

            /**
             * <p>
             * Disposes an instance of <code>LengthSettableMockArrayBackedObjectf</code>.
             * </p>
             */
            virtual
            ~LengthSettableMockArrayBackedObjectf();
    };
}

#endif /* LENGTHSETTABLEMOCKARRAYBACKEDOBJECTF_H_ */
