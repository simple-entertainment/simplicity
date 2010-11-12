/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SIMPLECOMPOSITEENGINETEST_H_
#define SIMPLECOMPOSITEENGINETEST_H_

#include <gtest/gtest.h>
using namespace testing;

#include <simplicity/engine/SimpleCompositeEngine.h>
using namespace simplicity;

namespace simplicity_test
{
    class SimpleCompositeEngineTest : public Test
    {
        protected:
            /**
             * An instance of the class being unit tested.
             */
            SimpleCompositeEngine fTestObject;
    };
}

#endif /* SIMPLECOMPOSITEENGINETEST_H_ */
