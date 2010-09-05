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
     * Unit test the method {@link com.se.simplicity.jogl.picking.SimpleJOGLPicker.pickSceneGraph pickSceneGraph()}.
     */
    @Test
    public void pickScene()
    {
        // Create dependencies.
        MockGL mockGl = new MockGL();
        mockGl.setReturnValue(1);

        Camera mockCamera = createMock(Camera.class);
        RenderingEngine mockRenderingEngine = createMock(RenderingEngine.class);

        Scene mockScene = createMock(Scene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        ModelNode mockNode = createMock(ModelNode.class);
        VertexGroup mockParentVertexGroup = createMock(VertexGroup.class);
        VertexGroup mockChildVertexGroup = createMock(VertexGroup.class);

        // Dictate correct behaviour.
        expect(mockRenderingEngine.getScene()).andStubReturn(null);
        expect(mockRenderingEngine.getCamera()).andStubReturn(null);
        mockRenderingEngine.setScene(mockScene);
        expect(mockCamera.getPickCamera(null)).andStubReturn(null);
        mockRenderingEngine.setCamera(null);
        mockRenderingEngine.advance();
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getNode(0)).andStubReturn(mockNode);
        expect(mockNode.getModel()).andStubReturn(mockParentVertexGroup);
        expect(mockParentVertexGroup.createFaceSubsetVG(20)).andStubReturn(mockChildVertexGroup);
        replay(mockRenderingEngine, mockCamera, mockScene, mockSceneGraph, mockNode, mockParentVertexGroup);

        // Setup test environment.
        testObject.setGL(mockGl);
        testObject.setRenderingEngine(mockRenderingEngine);
        testObject.getSelectBuffer().put(new int[] {2, 0, 0, 0, 20});
        testObject.getSelectBuffer().rewind();

        // Perform test
        PickEvent pick = testObject.pickScene(mockScene, mockCamera, null);

        // Verify test results.
        assertEquals(1, pick.getHitCount());
        assertEquals(mockNode, pick.getHit(0).getNode());
        assertEquals(mockChildVertexGroup, pick.getHit(0).getPrimitive());
    }

    /**
     * Unit test the method {@link com.se.simplicity.jogl.picking.SimpleJOGLPicker.setGL setGL()}.
     */
    @Test
    public void setGL()
    {
        MockGL mockGl = new MockGL();

        testObject.setGL(mockGl);

        assertEquals(1, mockGl.getMethodCallCountIgnoreParams("glSelectBuffer"), 0);
    }

    /**
     * Unit test the method {@link com.se.simplicity.jogl.picking.SimpleJOGLPicker.setSelectBufferCapacity setSelectBufferCapacity()} with the special
     * condition that a GL has already been set.
     */
    @Test
    public void setSelectBufferCapacityGL()
    {
        MockGL mockGl = new MockGL();

        testObject.setGL(mockGl);

        mockGl.reset();

        testObject.setSelectBufferCapacity(10);

        assertEquals(1, mockGl.getMethodCallCountIgnoreParams("glSelectBuffer"), 0);
    }
}
