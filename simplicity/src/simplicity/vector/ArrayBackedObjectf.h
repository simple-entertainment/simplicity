/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef ARRAYBACKEDOBJECTF_H_
#define ARRAYBACKEDOBJECTF_H_

namespace simplicity
{
    /**
     * <p>
     * An object which stores its data in a <code>float</code> array.
     * </p>
     *
     * @author Gary Buyn
     */
    class ArrayBackedObjectf
    {
        public:
            /**
             * <p>
             * Creates an instance of <code>ArrayBackedObjectf</code>.
             * </p>
             */
            ArrayBackedObjectf();

            /**
             * <p>
             * Disposes of an instance of <code>ArrayBackedObjectf</code>.
             * </p>
             */
            virtual
            ~ArrayBackedObjectf();

            /**
             * <p>
             * Retrieves the array that contains the data for this object.
             * </p>
             *
             * <p>
             * This <code>ArrayBackedObjectf</code> will retain ownership of the returned array.
             * </p>
             *
             * @return The array that contains the data for this object.
             */
            float*
            getArray();

            /**
             * <p>
             * Retrieves a copy of the array that contains the data for this object.
             * </p>
             *
             * <p>
             * The caller must assume ownership of the returned array.
             * </p>
             *
             * @return A copy of the array that contains the data for this object.
             */
            float*
            getArrayCopy();

            /**
             * <p>
             * Retrieves the length of the array that contains the data for this object.
             * </p>
             *
             * @return The length of the array that contains the data for this object.
             */
            int
            getLength();

            /**
             * <p>
             * Returns true if the argument has an array the same size with the same contents.
             * </p>
             *
             * @param other The object to compare this <code>ArrayBackedObjectf</code> to.
             *
             * @return True if this <code>ArrayBackedObjectf</code> is equal to the object given, false otherwise.
             */
            bool
            operator==(ArrayBackedObjectf& rhs) const;

            /**
             * <p>
             * Sets the array that contains the data for this object.
             * </p>
             *
             * <p>
             * This <code>ArrayBackedObjectf</code> will assume ownership of the given array and the previously held array will be deleted.
             * </p>
             *
             * @param array The array that contains the data for this object.
             */
            void
            setArray(float* const array);

        protected:
            /**
             * <p>
             * Sets the length of the array that contains the data for this object.
             * </p>
             *
             * @param length The length of the array that contains the data for this object.
             */
            void
            setLength(const int length);

        private:
            /**
             * <p>
             * The array that contains the data for this object.
             * </p>
             */
            float* fArray;

            /**
             * <p>
             * The length of the array that contains the data for this object.
             * </p>
             */
            int fLength;
    };
}

#endif /* ARRAYBACKEDOBJECTF_H_ */
