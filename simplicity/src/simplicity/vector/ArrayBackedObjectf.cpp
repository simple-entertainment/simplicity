/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include "ArrayBackedObjectf.h"

namespace simplicity
{
    ArrayBackedObjectf::ArrayBackedObjectf() :
        fArray(0), fLength(0)
    {
    }

    ArrayBackedObjectf::~ArrayBackedObjectf()
    {
        delete[] fArray;
    }

    float*
    ArrayBackedObjectf::getArray()
    {
        return (fArray);
    }

    float*
    ArrayBackedObjectf::getArrayCopy()
    {
        float* arrayCopy = new float[fLength];

        for (int index = 0; index < fLength; index++)
        {
            arrayCopy[index] = fArray[index];
        }

        return (arrayCopy);
    }

    int
    ArrayBackedObjectf::getLength()
    {
        return (fLength);
    }

    bool
    ArrayBackedObjectf::operator==(ArrayBackedObjectf& rhs) const
    {
        if (fLength != rhs.getLength())
        {
            return (false);
        }

        for (int index = 0; index < fLength; index++)
        {
            if (fArray[index] != rhs.getArray()[index])
            {
                return (false);
            }
        }

        return (true);
    }

    void
    ArrayBackedObjectf::setArray(float* const array)
    {
        delete []fArray;

        fArray = array;
    }

    void
    ArrayBackedObjectf::setLength(const int length)
    {
        fLength = length;
    }
}
