/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef PICKEVENTTEST_H_
#define PICKEVENTTEST_H_

#include <gtest/gtest.h>
using namespace testing;

#include <simplicity/picking/event/PickEvent.h>
using namespace simplicity;

namespace simplicity_test
{
    /**
     * <p>
     * Unit tests for the class {@link simplicity::PickEvent PickEvent}.
     * </p>
     *
     * @author Gary Buyn
     */
    class PickEventTest : public Test
    {
        protected:
            PickEvent fTestObject;
    };
}

#endif /* PICKEVENTTEST_H_ */
