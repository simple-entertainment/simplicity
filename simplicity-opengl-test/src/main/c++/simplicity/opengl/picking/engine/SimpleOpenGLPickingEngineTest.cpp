/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <simplicity/picking/event/MockPickListener.h>
#include <simplicity/picking/MockPicker.h>
#include <simplicity/rendering/engine/MockRenderingEngine.h>
#include <simplicity/rendering/MockCamera.h>
#include <simplicity/scene/MockScene.h>

#include "SimpleOpenGLPickingEngineTest.h"

using namespace boost;
using namespace testing;

namespace simplicity
{
  namespace opengl
  {
    /**
     * <p>
     * Unit test the method
     * {@link com.se.simplicity.jogl.rendering.SimpleJOGLPickingEngine#(const EngineInput* const) advance(const EngineInput* const)}.
     * </p>
     */
    TEST_F(SimpleOpenGLPickingEngineTest, advance)
    {
      // Create dependencies.
      // //////////////////////////////////////////////////
      shared_ptr<MockPicker> mockPicker(new NiceMock<MockPicker>);
      shared_ptr<MockScene> mockScene(new NiceMock<MockScene>);
      shared_ptr<MockCamera> mockCamera(new NiceMock<MockCamera>);

      // Initialise the test environment.
      // //////////////////////////////////////////////////
      fTestObject.setPicker(mockPicker);
      fTestObject.setScene(mockScene);
      fTestObject.setCamera(mockCamera);
      fTestObject.pick(5, 10, 15, 20);
      fTestObject.pick(10, 20, 30, 40);

      // Dictate expected results.
      // //////////////////////////////////////////////////
      EXPECT_CALL(*mockPicker, init());
      EXPECT_CALL(*mockPicker, pickScene(Ref(*mockScene), Ref(*mockCamera), _)).Times(2).WillRepeatedly(Return(PickEvent ()));
      EXPECT_CALL(*mockPicker, dispose());

      // Perform test.
      // //////////////////////////////////////////////////
      fTestObject.advance(shared_ptr<EngineInput>());
    }

    /**
     * <p>
     * Unit test the method {@link simplicity::opengl::SimpleOpenGLPickingEngine#(const EngineInput* const) advance(const EngineInput* const)} with
     * the special condition that the {@link simplicity::opengl::SimpleOpenGLPickingEngine SimpleOpenGLPickingEngine} being tested does not have any
     * outstanding picks to perform.
     * </p>
     */
    TEST_F(SimpleOpenGLPickingEngineTest, advanceNoPicks)
    {
      // Create dependencies.
      // //////////////////////////////////////////////////
      shared_ptr<MockPicker> mockPicker(new MockPicker);

      // Initialise the test environment.
      // //////////////////////////////////////////////////
      fTestObject.setPicker(mockPicker);

      // Perform test.
      // //////////////////////////////////////////////////
      fTestObject.advance(shared_ptr<EngineInput>());
    }

    /**
     * <p>
     * Unit test the method {@link simplicity::opengl::SimpleOpenGLPickingEngine#(const EngineInput* const) advance(const EngineInput* const)} with
     * the special condition that a <code>RenderingEngine</code> is specified.
     * </p>
     */
    TEST_F(SimpleOpenGLPickingEngineTest, advanceRenderer)
    {
      // Create dependencies.
      // //////////////////////////////////////////////////
      shared_ptr<MockPicker> mockPicker(new NiceMock<MockPicker>);
      shared_ptr<MockRenderingEngine> mockRenderingEngine(new NiceMock<MockRenderingEngine>);
      shared_ptr<MockScene> mockScene(new NiceMock<MockScene>);
      shared_ptr<MockCamera> mockCamera(new NiceMock<MockCamera>);

      // Dictate correct behaviour.
      // //////////////////////////////////////////////////
      ON_CALL(*mockRenderingEngine, getScene()).WillByDefault(Return(mockScene));
      ON_CALL(*mockRenderingEngine, getCamera()).WillByDefault(Return(mockCamera));

      // Initialise the test environment.
      // //////////////////////////////////////////////////
      fTestObject.setPicker(mockPicker);
      fTestObject.setRenderingEngine(mockRenderingEngine);
      fTestObject.pick(5, 10, 15, 20);
      fTestObject.pick(10, 20, 30, 40);

      // Dictate expected results.
      // //////////////////////////////////////////////////
      EXPECT_CALL(*mockPicker, init());
      EXPECT_CALL(*mockPicker, pickScene(Ref(*mockScene), Ref(*mockCamera), _)).Times(2).WillRepeatedly(Return(PickEvent ()));
      EXPECT_CALL(*mockPicker, dispose());

      // Perform test.
      // //////////////////////////////////////////////////
      fTestObject.advance(shared_ptr<EngineInput>());
    }

    /**
     * Unit test the method {@link simplicity::opengl::SimpleOpenGLPickingEngine#pick(const Pick) pick(const Pick)}.
     */
    TEST_F(SimpleOpenGLPickingEngineTest, pick)
    {
      // Create dependencies.
      // //////////////////////////////////////////////////
      Pick pick;
      pick.x = 10;
      pick.y = 20;
      pick.width = 30;
      pick.height = 40;

      // Perform test.
      // //////////////////////////////////////////////////
      fTestObject.pick(pick);

      // Verify test results.
      // //////////////////////////////////////////////////
      ASSERT_EQ(1, fTestObject.getPicks().size());
      pick = fTestObject.getPicks().at(0);
      ASSERT_EQ(pick.x, fTestObject.getPicks().at(0).x);
      ASSERT_EQ(pick.y, fTestObject.getPicks().at(0).y);
      ASSERT_EQ(pick.width, fTestObject.getPicks().at(0).width);
      ASSERT_EQ(pick.height, fTestObject.getPicks().at(0).height);
    }

    /**
     * Unit test the method
     * {@link simplicity::opengl::SimpleOpenGLPickingEngine#pickViewport(const int, const int, const Pick) pickViewport(const int, const int, const Pick)}.
     */
    TEST_F(SimpleOpenGLPickingEngineTest, pickViewport)
    {
      // Create dependencies.
      // //////////////////////////////////////////////////
      shared_ptr<MockCamera> mockCamera(new NiceMock<MockCamera>);
      Pick pick;
      pick.x = 100.0f;
      pick.y = 100.0f;
      pick.width = 2.0f;
      pick.height = 2.0f;

      // Dictate correct behaviour.
      // //////////////////////////////////////////////////
      ON_CALL(*mockCamera, getFrameWidth()).WillByDefault(Return(0.1f));
      ON_CALL(*mockCamera, getFrameAspectRatio()).WillByDefault(Return(0.75f));

      // Initialise the test environment.
      // //////////////////////////////////////////////////
      fTestObject.setCamera(mockCamera);

      // Perform test.
      // //////////////////////////////////////////////////
      fTestObject.pickViewport(200, 200, pick);

      // Verify test results.
      // //////////////////////////////////////////////////
      ASSERT_EQ(1, fTestObject.getPicks().size());
      pick = fTestObject.getPicks().at(0);
      ASSERT_EQ(0.05f, pick.x);
      ASSERT_EQ(0.05f * 0.75f, pick.y);
      ASSERT_EQ(0.1f / 100.0f, pick.width);
      ASSERT_EQ((0.1f * 0.75f) / 100.0f, pick.height);
    }

    /**
     * <p>
     * Unit test the method
     * {@link simplicity::opengl::SimpleJOGLPickingEngine#setRenderingEngine(shared_ptr<RenderingEngine>) setRenderingEngine(shared_ptr<RenderingEngine>)}.
     * </p>
     */
    TEST_F(SimpleOpenGLPickingEngineTest, setRenderingEngine)
    {
      // Create dependencies.
      // //////////////////////////////////////////////////
      shared_ptr<MockRenderingEngine> mockRenderingEngine(new NiceMock<MockRenderingEngine>);
      shared_ptr<MockScene> mockScene(new NiceMock<MockScene>);
      shared_ptr<MockCamera> mockCamera(new NiceMock<MockCamera>);

      // Dictate correct behaviour.
      // //////////////////////////////////////////////////
      ON_CALL(*mockRenderingEngine, getScene()).WillByDefault(Return(mockScene));
      ON_CALL(*mockRenderingEngine, getCamera()).WillByDefault(Return(mockCamera));

      // Perform test.
      // //////////////////////////////////////////////////
      fTestObject.setRenderingEngine(mockRenderingEngine);

      // Verify test results.
      // //////////////////////////////////////////////////
      ASSERT_EQ(mockScene, fTestObject.getScene());
      ASSERT_EQ(mockCamera, fTestObject.getCamera());
    }
  }
}
