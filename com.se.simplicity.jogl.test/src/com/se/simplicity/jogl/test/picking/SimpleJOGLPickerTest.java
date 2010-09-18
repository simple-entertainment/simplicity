/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.jogl.test.picking;

import static org.easymock.EasyMock.expect;
import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.replay;
import static org.junit.Assert.assertEquals;

import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.jogl.picking.SimpleJOGLPicker;
import com.se.simplicity.jogl.test.mocks.MockGL;
import com.se.simplicity.model.VertexGroup;
import com.se.simplicity.model.shape.Shape;
import com.se.simplicity.picking.event.PickEvent;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.engine.RenderingEngine;
import com.se.simplicity.scene.Scene;
import com.se.simplicity.scenegraph.SceneGraph;
import com.se.simplicity.scenegraph.model.ModelNode;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.jogl.rendering.SimpleJOGLPicker SimpleJOGLPicker}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SimpleJOGLPickerTest
{
    /**
     * An instance of the class being unit tested.
     */
    private SimpleJOGLPicker testObject;

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        testObject = new SimpleJOGLPicker();
    }

    /**
     * Unit test the method {@link com.se.simplicity.jogl.picking.SimpleJOGLPicker.pickSceneGraph pickSceneGraph()} with the special condition that
     * the picked primitive is a <code>Shape</code>.
     */
    @Test
    public void pickSceneShape()
    {
        // Create dependencies.
        MockGL mockGl = new MockGL();
        mockGl.setReturnValue(2);

        RenderingEngine mockRenderingEngine = createMock(RenderingEngine.class);
        Camera mockCamera = createMock(Camera.class);

        Scene mockScene = createMock(Scene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        ModelNode mockNode0 = createMock(ModelNode.class);
        Shape mockShape0 = createMock(Shape.class);
        ModelNode mockNode1 = createMock(ModelNode.class);
        Shape mockShape1 = createMock(Shape.class);

        // Dictate correct behaviour.
        expect(mockRenderingEngine.getScene()).andStubReturn(null);
        expect(mockRenderingEngine.getCamera()).andStubReturn(null);
        mockRenderingEngine.setScene(mockScene);
        mockRenderingEngine.setCamera(null);
        mockRenderingEngine.advance();
        expect(mockCamera.getPickCamera(null)).andStubReturn(null);
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getNode(0)).andStubReturn(mockNode0);
        expect(mockNode0.getModel()).andStubReturn(mockShape0);
        expect(mockSceneGraph.getNode(1)).andStubReturn(mockNode1);
        expect(mockNode1.getModel()).andStubReturn(mockShape1);
        replay(mockRenderingEngine, mockCamera, mockScene, mockSceneGraph, mockNode0, mockShape0, mockNode1, mockShape1);

        // Setup test environment.
        testObject.setGL(mockGl);
        testObject.setRenderingEngine(mockRenderingEngine);
        testObject.init();
        testObject.getSelectBuffer().put(new int[] {1, -999, -999, 0, 1, -999, -999, 1});
        testObject.getSelectBuffer().rewind();

        // Perform test
        PickEvent pick = testObject.pickScene(mockScene, mockCamera, null);

        // Verify test results.
        assertEquals(2, pick.getHitCount());
        assertEquals(mockNode0, pick.getHit(0).getNode());
        assertEquals(mockShape0, pick.getHit(0).getPrimitive());
        assertEquals(mockNode1, pick.getHit(1).getNode());
        assertEquals(mockShape1, pick.getHit(1).getPrimitive());
    }

    /**
     * Unit test the method {@link com.se.simplicity.jogl.picking.SimpleJOGLPicker.pickSceneGraph pickSceneGraph()} with the special condition that
     * the picked primitive is a <code>VertexGroup</code>.
     */
    @Test
    public void pickSceneVertexGroup()
    {
        // Create dependencies.
        MockGL mockGl = new MockGL();
        mockGl.setReturnValue(2);

        RenderingEngine mockRenderingEngine = createMock(RenderingEngine.class);
        Camera mockCamera = createMock(Camera.class);

        Scene mockScene = createMock(Scene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        ModelNode mockNode0 = createMock(ModelNode.class);
        VertexGroup mockParentVertexGroup0 = createMock(VertexGroup.class);
        VertexGroup mockChildVertexGroup0 = createMock(VertexGroup.class);
        ModelNode mockNode1 = createMock(ModelNode.class);
        VertexGroup mockParentVertexGroup1 = createMock(VertexGroup.class);
        VertexGroup mockChildVertexGroup1 = createMock(VertexGroup.class);

        // Dictate correct behaviour.
        expect(mockRenderingEngine.getScene()).andStubReturn(null);
        expect(mockRenderingEngine.getCamera()).andStubReturn(null);
        mockRenderingEngine.setScene(mockScene);
        mockRenderingEngine.setCamera(null);
        mockRenderingEngine.advance();
        expect(mockCamera.getPickCamera(null)).andStubReturn(null);
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getNode(0)).andStubReturn(mockNode0);
        expect(mockNode0.getModel()).andStubReturn(mockParentVertexGroup0);
        expect(mockParentVertexGroup0.createFaceSubsetVG(20)).andStubReturn(mockChildVertexGroup0);
        expect(mockSceneGraph.getNode(1)).andStubReturn(mockNode1);
        expect(mockNode1.getModel()).andStubReturn(mockParentVertexGroup1);
        expect(mockParentVertexGroup1.createFaceSubsetVG(40)).andStubReturn(mockChildVertexGroup1);
        replay(mockRenderingEngine, mockCamera, mockScene, mockSceneGraph, mockNode0, mockParentVertexGroup0, mockNode1, mockParentVertexGroup1);

        // Initialise test environment.
        testObject.setGL(mockGl);
        testObject.setRenderingEngine(mockRenderingEngine);
        testObject.init();
        testObject.getSelectBuffer().put(new int[] {2, -999, -999, 0, 20, 2, -999, -999, 1, 40});
        testObject.getSelectBuffer().rewind();

        // Perform test
        PickEvent pick = testObject.pickScene(mockScene, mockCamera, null);

        // Verify test results.
        assertEquals(2, pick.getHitCount());
        assertEquals(mockNode0, pick.getHit(0).getNode());
        assertEquals(mockChildVertexGroup0, pick.getHit(0).getPrimitive());
        assertEquals(mockNode1, pick.getHit(1).getNode());
        assertEquals(mockChildVertexGroup1, pick.getHit(1).getPrimitive());
    }
}
