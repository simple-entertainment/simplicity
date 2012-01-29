/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <simplicity/MockComponent.h>
#include <simplicity/rendering/MockCamera.h>
#include <simplicity/rendering/MockLight.h>
#include <simplicity/rendering/MockNamedRenderer.h>
#include <simplicity/rendering/MockRenderer.h>
#include <simplicity/scene/MockNode.h>
#include <simplicity/scene/MockScene.h>
#include <simplicity/SEInvalidOperationException.h>
#include <simplicity/testdoubles/NodeHierarchy.h>

#include "SimpleOpenGLRenderingEngineTest.h"

using namespace std;
using namespace testing;

namespace simplicity
{
  namespace opengl
  {
    /**
     * <p>
     * Unit test the method
     * {@link simplicity::opengl::SimpleOpenGLRenderingEngine#addEntities(std::vector<std::shared_ptr<Entity> >) addEntities(std::vector<std::shared_ptr<Entity> >)}.
     * </p>
     */
    TEST_F(SimpleOpenGLRenderingEngineTest, addEntities)
    {
      // Create dependencies.
      // //////////////////////////////////////////////////
      shared_ptr<MockScene> mockScene(new NiceMock<MockScene>);
      vector<shared_ptr<Entity> > entities;
      shared_ptr<Entity> entity0(new Entity);
      shared_ptr<Entity> entity1(new Entity);
      shared_ptr<Entity> entity2(new Entity);
      shared_ptr<Node> mockComponent0(new NiceMock<MockNode>);
      shared_ptr<Node> mockComponent1(new NiceMock<MockNode>);
      shared_ptr<Node> mockComponent2(new NiceMock<MockNode>);
      shared_ptr<Component> mockComponent3(new NiceMock<MockComponent>);

      // Dictate expected results.
      // //////////////////////////////////////////////////
      EXPECT_CALL(*mockScene, addNode(mockComponent0));
      EXPECT_CALL(*mockScene, addNode(mockComponent1));
      EXPECT_CALL(*mockScene, addNode(mockComponent2));

      // Initialise the test environment.
      // //////////////////////////////////////////////////
      fTestObject.setScene(mockScene);
      entities.push_back(entity0);
      entities.push_back(entity1);
      entities.push_back(entity2);
      entity1->addComponent(mockComponent0);
      entity2->addComponent(mockComponent1);
      entity2->addComponent(mockComponent2);
      entity2->addComponent(mockComponent3);

      // Perform test.
      // //////////////////////////////////////////////////
      fTestObject.addEntities(entities);
    }

    /**
     * <p>
     * Unit test the methods
     * {@link simplicity::opengl::SimpleOpenGLRenderingEngine#addRenderer(std::shared_ptr<Renderer>) addRenderer(std::shared_ptr<Renderer>)}
     * and {@link simplicity::opengl::SimpleOpenGLRenderingEngine#removeRenderer(const Renderer&) removeRenderer(const Renderer&)}.
     * </p>
     */
    TEST_F(SimpleOpenGLRenderingEngineTest, addRemoveRenderer)
    {
      // Create dependencies.
      // //////////////////////////////////////////////////
      shared_ptr<MockRenderer> mockRenderer(new NiceMock<MockRenderer>);
      shared_ptr<MockScene> mockScene(new NiceMock<MockScene>);
      NodeHierarchy nodes;
      nodes.setBasicNodeHierarchy();

      // Dictate correct behaviour.
      // //////////////////////////////////////////////////
      ON_CALL(*mockScene, getRoot()).WillByDefault(Return(nodes.node1));

      // Initialise the test environment.
      // //////////////////////////////////////////////////
      fTestObject.setScene(mockScene);

      // Perform test 1.
      // //////////////////////////////////////////////////
      fTestObject.addRenderer(mockRenderer);

      // Verify test 1 results.
      // //////////////////////////////////////////////////
      ASSERT_EQ(1u, fTestObject.getRenderers().size());
      ASSERT_FALSE(fTestObject.getRenderers().end() == find(fTestObject.getRenderers().begin(), fTestObject.getRenderers().end(), mockRenderer));
      ASSERT_EQ(nodes.node1, fTestObject.getRendererRoot(*mockRenderer));

      // Perform test 2.
      // //////////////////////////////////////////////////
      fTestObject.removeRenderer(*mockRenderer);

      // Verify test 2 results.
      // //////////////////////////////////////////////////
      ASSERT_EQ(0u, fTestObject.getRenderers().size());
      ASSERT_FALSE(fTestObject.getRendererRoot(*mockRenderer).get());
    }

    /**
     * <p>
     * Unit test the method
     * {@link simplicity::opengl::SimpleJOGLRenderingEngine#addRenderer(const int, shared_ptr<Renderer>) addRenderer(const int, shared_ptr<Renderer>)}.
     * </p>
     */
    TEST_F(SimpleOpenGLRenderingEngineTest, addRendererAtIndex)
    {
      // Create dependencies.
      // //////////////////////////////////////////////////
      shared_ptr<MockRenderer> mockRenderer1(new NiceMock<MockRenderer>);
      shared_ptr<MockRenderer> mockRenderer2(new NiceMock<MockRenderer>);
      shared_ptr<MockRenderer> mockRenderer3(new NiceMock<MockRenderer>);
      shared_ptr<MockScene> mockScene(new NiceMock<MockScene>);
      NodeHierarchy nodes;
      nodes.setBasicNodeHierarchy();

      // Dictate correct behaviour.
      // //////////////////////////////////////////////////
      ON_CALL(*mockScene, getRoot()).WillByDefault(Return(nodes.node1));

      // Initialise the test environment.
      // //////////////////////////////////////////////////
      fTestObject.setScene(mockScene);
      fTestObject.addRenderer(mockRenderer1);

      // Perform test.
      // //////////////////////////////////////////////////
      fTestObject.addRenderer(0, mockRenderer2);
      fTestObject.addRenderer(1, mockRenderer3);

      // Verify test results.
      // //////////////////////////////////////////////////
      ASSERT_EQ(mockRenderer2, fTestObject.getRenderers().at(0));
      ASSERT_EQ(mockRenderer3, fTestObject.getRenderers().at(1));
      ASSERT_EQ(mockRenderer1, fTestObject.getRenderers().at(2));
    }

    /**
     * <p>
     * Unit test the method
     * {@link simplicity::opengl::SimpleOpenGLRenderingEngine#advance(const EngineInput* const) advance(const EngineInput* const)} with the special
     * condition that the {@link simplicity::opengl::SimpleOpenGLRenderingEngine SimpleOpenGLRenderingEngine} being tested does not have a
     * {@link simplicity::Camera Camera} to view the {@link simplicity::SceneGraph SceneGraph} through.
     * </p>
     */
    TEST_F(SimpleOpenGLRenderingEngineTest, advanceNoCamera)
    {
      // Perform test - Verify test results.
      // //////////////////////////////////////////////////
      ASSERT_THROW(fTestObject.advance(shared_ptr<EngineInput>()), SEInvalidOperationException);
    }

    /**
     * <p>
     * Unit test the method
     * {@link simplicity::opengl::SimpleOpenGLRenderingEngine#advance(const EngineInput* const) advance(const EngineInput* const)} with the special
     * condition that the {@link simplicity::opengl::SimpleOpenGLRenderingEngine SimpleOpenGLRenderingEngine} being tested does not have a
     * {@link simplicity::Scene Scene} to render.
     * </p>
     */
    TEST_F(SimpleOpenGLRenderingEngineTest, advanceNoScene)
    {
      // Create dependencies.
      // //////////////////////////////////////////////////
      shared_ptr<MockCamera> mockCamera(new NiceMock<MockCamera>);

      // Initialise the test environment.
      // //////////////////////////////////////////////////
      fTestObject.setCamera(mockCamera);

      // Perform test - Verify test results.
      // //////////////////////////////////////////////////
      ASSERT_THROW(fTestObject.advance(shared_ptr<EngineInput>()), SEInvalidOperationException);
    }

    /**
     * <p>
     * Unit test the method
     * {@link simplicity::opengl::SimpleOpenGLRenderingEngine#advance(const EngineInput* const) advance(const EngineInput* const)}, specifically the
     * initialisation and disposal of dependencies.
     * </p>
     */
    TEST_F(SimpleOpenGLRenderingEngineTest, advanceRendererCameraLight)
    {
      // Create dependencies.
      // //////////////////////////////////////////////////
      shared_ptr<MockScene> mockScene(new NiceMock<MockScene>);
      NodeHierarchy nodes;
      nodes.setBasicNodeHierarchy();

      shared_ptr<MockRenderer> mockRenderer(new NiceMock<MockRenderer>);
      shared_ptr<MockCamera> mockCamera(new NiceMock<MockCamera>);
      shared_ptr<MockLight> mockLight(new NiceMock<MockLight>);
      vector<shared_ptr<Light> > lights;
      lights.push_back(mockLight);

      // Dictate correct behaviour.
      // //////////////////////////////////////////////////
      ON_CALL(*mockScene, getLights()).WillByDefault(Return(lights));
      ON_CALL(*mockScene, getRoot()).WillByDefault(Return(nodes.node1));

      // Dictate expected results.
      // //////////////////////////////////////////////////
      EXPECT_CALL(*mockRenderer, init());
      EXPECT_CALL(*mockCamera, init());
      EXPECT_CALL(*mockCamera, apply());
      EXPECT_CALL(*mockLight, apply());
      EXPECT_CALL(*mockRenderer, dispose());

      // Initialise the test environment.
      // //////////////////////////////////////////////////
      fTestObject.setCamera(mockCamera);
      fTestObject.setScene(mockScene);
      fTestObject.addRenderer(mockRenderer);

      // Perform test.
      // //////////////////////////////////////////////////
      fTestObject.advance(shared_ptr<EngineInput>());
    }

    /**
     * <p>
     * Unit test the method
     * {@link simplicity::opengl::SimpleJOGLRenderingEngine#renderSceneGraph(Renderer&, const Node&) renderSceneGraph(Renderer&, const Node&)}.
     * </p>
     */
    TEST_F(SimpleOpenGLRenderingEngineTest, renderSceneGraph)
    {
      // Create dependencies.
      // //////////////////////////////////////////////////
      shared_ptr<MockRenderer> mockRenderer(new NiceMock<MockRenderer>);
      NodeHierarchy nodes;
      nodes.setStandardNodeHierarchy();

      // Dictate expected results.
      // //////////////////////////////////////////////////
      EXPECT_CALL(*mockRenderer, renderModel(Ref(*dynamic_pointer_cast<ModelNode> (nodes.node3)->getModel())));

      // Perform test.
      // //////////////////////////////////////////////////
      fTestObject.renderSceneGraph(*mockRenderer, *nodes.node1);
    }

    /**
     * <p>
     * Unit test the method
     * {@link simplicity::opengl::SimpleOpenGLRenderingEngine#renderSceneGraph(Renderer&, const Node&) renderSceneGraph(Renderer&, const Node&)} with
     * the special condition that the {@link simplicity::opengl::SimpleOpenGLRenderingEngine} being tested uses a {@link simplicity::NamedRenderer}.
     * </p>
     */
    TEST_F(SimpleOpenGLRenderingEngineTest, renderSceneGraphNamed)
    {
      // Create dependencies.
      // //////////////////////////////////////////////////
      shared_ptr<MockNamedRenderer> mockNamedRenderer(new NiceMock<MockNamedRenderer>);
      NodeHierarchy nodes;
      nodes.setStandardNodeHierarchy();

      // Dictate expected results.
      // //////////////////////////////////////////////////
      EXPECT_CALL(*mockNamedRenderer, renderModel(Ref(*dynamic_pointer_cast<ModelNode> (nodes.node3)->getModel()), 2));

      // Perform test.
      // //////////////////////////////////////////////////
      fTestObject.renderSceneGraph(*mockNamedRenderer, *nodes.node1);
    }

    /**
     * <p>
     * Unit test the method {@link simplicity::opengl::SimpleOpenGLRenderingEngine#setScene(shared_ptr<Scene>) setScene(shared_ptr<Scene>)}.
     * </p>
     */
    TEST_F(SimpleOpenGLRenderingEngineTest, setScene)
    {
      // Create dependencies.
      // //////////////////////////////////////////////////
      shared_ptr<MockRenderer> mockRenderer1(new NiceMock<MockRenderer>);
      shared_ptr<MockRenderer> mockRenderer2(new NiceMock<MockRenderer>);
      shared_ptr<MockScene> mockScene(new NiceMock<MockScene>);
      NodeHierarchy nodes;
      nodes.setBasicNodeHierarchy();

      // Dictate correct behaviour.
      // //////////////////////////////////////////////////
      ON_CALL(*mockScene, getRoot()).WillByDefault(Return(nodes.node1));

      // Initialise the test environment.
      // //////////////////////////////////////////////////
      fTestObject.addRenderer(mockRenderer1);
      fTestObject.addRenderer(mockRenderer2);

      // Perform test.
      // //////////////////////////////////////////////////
      fTestObject.setScene(mockScene);

      // Verify test results.
      // //////////////////////////////////////////////////
      ASSERT_EQ(nodes.node1, fTestObject.getRendererRoot(*mockRenderer1));
      ASSERT_EQ(nodes.node1, fTestObject.getRendererRoot(*mockRenderer2));
    }
  }
}
