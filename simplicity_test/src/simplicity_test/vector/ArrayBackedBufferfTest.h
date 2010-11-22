/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef ARRAYBACKEDBUFFERFTEST_H_
#define ARRAYBACKEDBUFFERFTEST_H_

#include <gtest/gtest.h>
using namespace testing;

#include "../mocks/LengthSettableMockArrayBackedObjectf.h"

namespace simplicity_test
{
    /**
     * <p>
     * Unit tests for the class {@link simplicity::ArrayBackedBufferf ArrayBackedBufferf}.
     * </p>
     *
     * @author Gary Buyn
     */
    class ArrayBackedBufferfTest : public Test
    {
        public:
            // TODO Should this be done in the constructor or SetUp()?
            ArrayBackedBufferfTest() :
                fTestObject(5)
            {
            }

        protected:
            /**
             * An instance of the class being unit tested.
             */
            LengthSettableMockArrayBackedObjectf fTestObject;
    };

}

#endif /* ARRAYBACKEDBUFFERFTEST_H_ */
