/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SIMPLEVECTOR4TEST_H_
#define SIMPLEVECTOR4TEST_H_

#include <gtest/gtest.h>
using namespace testing;

#include <simplicity/vector/SimpleVector4.h>
using namespace simplicity;

namespace simplicity_test
{
  /**
   * <p>
   * Unit tests for the class {@link simplicity::SimpleVector4 SimpleVector4}.
   * </p>
   *
   * @author Gary Buyn
   */
  class SimpleVector4Test : public Test
  {
    protected:
      /**
       * An instance of the class being unit tested.
       */
      SimpleVector4<float> fTestObject;

      /**
       * <p>
       * Setup to perform before each unit test.
       * </p>
       */
      void
      SetUp()
      {
        array<float, 4> * data = &fTestObject.getData();

        data->at(0) = 1.0f;
        data->at(1) = 2.0f;
        data->at(2) = 3.0f;
        data->at(3) = 1.0f;
      }
  };
}

#endif /* SIMPLEVECTOR4TEST_H_ */
