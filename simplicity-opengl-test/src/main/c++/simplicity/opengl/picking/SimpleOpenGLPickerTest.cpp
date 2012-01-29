/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <simplicity/model/MockVertexGroup.h>
#include <simplicity/model/shape/MockShape.h>
#include <simplicity/rendering/MockCamera.h>
#include <simplicity/rendering/MockRenderer.h>
#include <simplicity/scene/MockScene.h>
#include <simplicity/scene/model/MockModelNode.h>

#include "SimpleOpenGLPickerTest.h"

using namespace std;
using namespace testing;

namespace simplicity
{
  namespace opengl
  {
    /**
     * <p>
     * Unit test the method
     * {@link simplicity::SimpleJOGLPicker#createPickEvent(const Scene&, const int) createPickEvent(const Scene&, const int)}
     * with the special condition that the picked primitive is a <code>Shape</code>.
     * </p>
     */
    TEST_F(SimpleOpenGLPickerTest, createPickEventShape)
    {
      // Create dependencies.
      // //////////////////////////////////////////////////
      shared_ptr<MockScene> mockScene(new NiceMock<MockScene>);
      shared_ptr<MockModelNode> mockNode0(new NiceMock<MockModelNode>);
      shared_ptr<MockShape> mockShape0(new NiceMock<MockShape>);
      shared_ptr<MockModelNode> mockNode1(new NiceMock<MockModelNode>);
      shared_ptr<MockShape> mockShape1(new NiceMock<MockShape>);

      // Dictate correct behaviour.
      // //////////////////////////////////////////////////
      // Mock a scene graph that will be used to populate the pick event.
      ON_CALL(*mockScene, getNode(0)).WillByDefault(Return(mockNode0));
      ON_CALL(*mockNode0, getModel()).WillByDefault(Return(mockShape0));
      ON_CALL(*mockScene, getNode(1)).WillByDefault(Return(mockNode1));
      ON_CALL(*mockNode1, getModel()).WillByDefault(Return(mockShape1));

      // Initialise the test environment.
      // //////////////////////////////////////////////////
      fTestObject.init();
      // Fill in the select buffer.
      unsigned int* selectBuffer = fTestObject.getSelectBuffer();
      selectBuffer[0] = 1;
      selectBuffer[1] = -999;
      selectBuffer[2] = -999;
      selectBuffer[3] = 0;
      selectBuffer[4] = 1;
      selectBuffer[5] = -999;
      selectBuffer[6] = -999;
      selectBuffer[7] = 1;

      // Perform test
      // //////////////////////////////////////////////////
      PickEvent pickEvent = createPickEventPublic(*mockScene, 2);

      // Verify test results.
      // //////////////////////////////////////////////////
      ASSERT_EQ(2, pickEvent.getHitCount());
      ASSERT_EQ(mockNode0, pickEvent.getHit(0).node);
      ASSERT_EQ(mockShape0, pickEvent.getHit(0).primitive);
      ASSERT_EQ(mockNode1, pickEvent.getHit(1).node);
      ASSERT_EQ(mockShape1, pickEvent.getHit(1).primitive);
    }

    /**
     * Unit test the method
     * {@link simplicity::SimpleJOGLPicker#createPickEvent(const Scene&, const int) createPickEvent(const Scene&, const int)}
     * with the special condition that the picked primitive is a <code>VertexGroup</code>.
     */
    TEST_F(SimpleOpenGLPickerTest, createPickEventVertexGroup)
    {
      // Create dependencies.
      // //////////////////////////////////////////////////
      shared_ptr<MockScene> mockScene(new NiceMock<MockScene>);
      shared_ptr<MockModelNode> mockNode0(new NiceMock<MockModelNode>);
      shared_ptr<MockVertexGroup> mockParentVertexGroup0(new NiceMock<MockVertexGroup>);
      shared_ptr<MockVertexGroup> mockChildVertexGroup0(new NiceMock<MockVertexGroup>);
      shared_ptr<MockModelNode> mockNode1(new NiceMock<MockModelNode>);
      shared_ptr<MockVertexGroup> mockParentVertexGroup1(new NiceMock<MockVertexGroup>);
      shared_ptr<MockVertexGroup> mockChildVertexGroup1(new NiceMock<MockVertexGroup>);

      // Dictate correct behaviour.
      // //////////////////////////////////////////////////
      // Mock a scene graph that will be used to populate the pick event.
      ON_CALL(*mockScene, getNode(0)).WillByDefault(Return(mockNode0));
      ON_CALL(*mockNode0, getModel()).WillByDefault(Return(mockParentVertexGroup0));
      ON_CALL(*mockParentVertexGroup0, createFaceSubsetVG(20)).WillByDefault(Return(mockChildVertexGroup0));
      ON_CALL(*mockScene, getNode(1)).WillByDefault(Return(mockNode1));
      ON_CALL(*mockNode1, getModel()).WillByDefault(Return(mockParentVertexGroup1));
      ON_CALL(*mockParentVertexGroup1, createFaceSubsetVG(40)).WillByDefault(Return(mockChildVertexGroup1));

      // Initialise the test environment.
      // //////////////////////////////////////////////////
      fTestObject.init();
      // Fill in the select buffer.
      unsigned int* selectBuffer = fTestObject.getSelectBuffer();
      selectBuffer[0] = 2;
      selectBuffer[1] = -999;
      selectBuffer[2] = -999;
      selectBuffer[3] = 0;
      selectBuffer[4] = 20;
      selectBuffer[5] = 2;
      selectBuffer[6] = -999;
      selectBuffer[7] = -999;
      selectBuffer[8] = 1;
      selectBuffer[9] = 40;

      // Perform test
      // //////////////////////////////////////////////////
      PickEvent pickEvent = createPickEventPublic(*mockScene, 2);

      // Verify test results.
      // //////////////////////////////////////////////////
      ASSERT_EQ(2, pickEvent.getHitCount());
      ASSERT_EQ(mockNode0, pickEvent.getHit(0).node);
      ASSERT_EQ(mockChildVertexGroup0, pickEvent.getHit(0).primitive);
      ASSERT_EQ(mockNode1, pickEvent.getHit(1).node);
      ASSERT_EQ(mockChildVertexGroup1, pickEvent.getHit(1).primitive);
    }

    /**
     * Unit test the method
     * {@link simplicity::SimpleJOGLPicker#createPickEvent(const Scene&, const int) createPickEvent(const Scene&, const int)}
     * with the special condition that the picked primitive is a <code>VertexGroup</code> and only one name is in the select buffer.
     */
    TEST_F(SimpleOpenGLPickerTest, createPickEventVertexGroupOneName)
    {
      // Create dependencies.
      // //////////////////////////////////////////////////
      shared_ptr<MockScene> mockScene(new NiceMock<MockScene>);
      shared_ptr<MockModelNode> mockNode0(new NiceMock<MockModelNode>);
      shared_ptr<MockVertexGroup> mockParentVertexGroup0(new NiceMock<MockVertexGroup>);
      shared_ptr<MockVertexGroup> mockChildVertexGroup0(new NiceMock<MockVertexGroup>);
      shared_ptr<MockModelNode> mockNode1(new NiceMock<MockModelNode>);
      shared_ptr<MockVertexGroup> mockParentVertexGroup1(new NiceMock<MockVertexGroup>);
      shared_ptr<MockVertexGroup> mockChildVertexGroup1(new NiceMock<MockVertexGroup>);

      // Dictate correct behaviour.
      // //////////////////////////////////////////////////
      // Mock a scene graph that will be used to populate the pick event.
      ON_CALL(*mockScene, getNode(0)).WillByDefault(Return(mockNode0));
      ON_CALL(*mockNode0, getModel()).WillByDefault(Return(mockParentVertexGroup0));
      ON_CALL(*mockParentVertexGroup0, createFaceSubsetVG(20)).WillByDefault(Return(mockChildVertexGroup0));
      ON_CALL(*mockScene, getNode(1)).WillByDefault(Return(mockNode1));
      ON_CALL(*mockNode1, getModel()).WillByDefault(Return(mockParentVertexGroup1));
      ON_CALL(*mockParentVertexGroup1, createFaceSubsetVG(40)).WillByDefault(Return(mockChildVertexGroup1));

      // Initialise the test environment.
      // //////////////////////////////////////////////////
      fTestObject.init();
      // Fill in the select buffer.
      unsigned int* selectBuffer = fTestObject.getSelectBuffer();
      selectBuffer[0] = 1;
      selectBuffer[1] = -999;
      selectBuffer[2] = -999;
      selectBuffer[3] = 0;
      selectBuffer[4] = 1;
      selectBuffer[5] = -999;
      selectBuffer[6] = -999;
      selectBuffer[7] = 1;

      // Perform test
      // //////////////////////////////////////////////////
      PickEvent pickEvent = createPickEventPublic(*mockScene, 2);

      // Verify test results.
      // //////////////////////////////////////////////////
      ASSERT_EQ(2, pickEvent.getHitCount());
      ASSERT_EQ(mockNode0, pickEvent.getHit(0).node);
      ASSERT_EQ(shared_ptr<MockVertexGroup> (), pickEvent.getHit(0).primitive);
      ASSERT_EQ(mockNode1, pickEvent.getHit(1).node);
      ASSERT_EQ(shared_ptr<MockVertexGroup> (), pickEvent.getHit(1).primitive);
    }
  }
}
