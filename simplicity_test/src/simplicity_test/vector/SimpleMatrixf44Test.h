/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SIMPLEMATRIXF44TEST_H_
#define SIMPLEMATRIXF44TEST_H_

#include <gtest/gtest.h>
using namespace testing;

#include <simplicity/vector/SimpleMatrixf44.h>
using namespace simplicity;

namespace simplicity_test
{
    /**
     * <p>
     * Unit tests for the class {@link simplicity::SimpleMatrixf44 SimpleMatrixf44}.
     * </p>
     *
     * @author Gary Buyn
     */
    class SimpleMatrixf44Test : public Test
    {
        protected:
            SimpleMatrixf44 fTestObject;

            void
            SetUp()
            {
                float* array = fTestObject.getArray();

                array[0] = 1.0f;
                array[4] = 2.0f;
                array[8] = 3.0f;
                array[12] = 4.0f;
                array[1] = 2.0f;
                array[5] = 1.0f;
                array[9] = 4.0f;
                array[13] = 3.0f;
                array[2] = 3.0f;
                array[6] = 4.0f;
                array[10] = 1.0f;
                array[14] = 2.0f;
                array[3] = 0.0f;
                array[7] = 0.0f;
                array[11] = 0.0f;
                array[15] = 1.0f;
            }
    };
}

#endif /* SIMPLEMATRIXF44TEST_H_ */
