/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <boost/smart_ptr.hpp>

#include "EntityTest.h"
#include "MockComponent.h"

using namespace boost;

namespace simplicity
{
  /**
   * <p>
   * Unit test the methods
   * {@link simplicity::Entity#addComponent(boost::shared_ptr<Component>) addComponent(boost::shared_ptr<Component>)} and
   * {@link simplicity::Entity#removeComponent(const Component&) removeComponent(const Component&)}.
   * </p>
   */
  TEST_F(EntityTest, addRemoveComponent)
  {
    // Create dependencies.
    // //////////////////////////////////////////////////
    shared_ptr<MockComponent> mockComponent(new MockComponent);

    // Perform test 1.
    // //////////////////////////////////////////////////
    fTestObject.addComponent(mockComponent);

    // Verify test 1 results.
    // //////////////////////////////////////////////////
    ASSERT_EQ(1, fTestObject.getComponents().size());
    ASSERT_FALSE(fTestObject.getComponents().end() == find(fTestObject.getComponents().begin(), fTestObject.getComponents().end(), mockComponent));

    // Perform test 2.
    // //////////////////////////////////////////////////
    fTestObject.removeComponent(*mockComponent);

    // Verify test 2 results.
    // //////////////////////////////////////////////////
    ASSERT_EQ(0, fTestObject.getComponents().size());
  }
}
