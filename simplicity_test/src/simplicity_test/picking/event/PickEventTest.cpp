/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include "PickEventTest.h"

namespace simplicity_test
{
    /**
     * <p>
     * Unit test the method {@link simplicity::PickEvent#getCloseHit() getCloseHit()}.
     * </p>
     */
    TEST_F(PickEventTest, getCloseHit)
    {
        // Create dependencies.
        // TODO not mocked!!
        Hit hit0;
        Hit hit1;

        // Dictate correct behaviour.
        hit0.setMinimumDistance(20);
        hit1.setMinimumDistance(10);

        // Initialise test environment.
        fTestObject.addHit(hit0);
        fTestObject.addHit(hit1);

        // Perform test.
        optional<Hit> hit = fTestObject.getCloseHit();

        // Verify test results.
        ASSERT_EQ(10, hit->getMinimumDistance());
    }
}
