/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.test.ui.editors.picking;

import static org.easymock.EasyMock.expect;
import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.replay;
import static org.junit.Assert.assertEquals;

import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.editor.internal.picking.WidgetJOGLPicker;
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
 * Unit tests for the class {@link com.se.simplicity.editor.internal.rendering.WidgetJOGLPicker WidgetJOGLPicker}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class WidgetJOGLPickerTest
{
    /**
     * An instance of the class being unit tested.
     */
    private WidgetJOGLPicker testObject;

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        testObject = new WidgetJOGLPicker();
    }

    /**
     * Unit test the method {@link com.se.simplicity.jogl.picking.WidgetJOGLPicker.pickSceneGraph pickSceneGraph()} with the special condition that
     * the picked primitive is a <code>Shape</code>.
     */
    @Test
    public void pickSceneShape()
    {
        // Create dependencies.
        MockGL mockGl = new MockGL();
        mockGl.setReturnValue(1);

        RenderingEngine mockRenderingEngine = createMock(RenderingEngine.class);
        Camera mockCamera = createMock(Camera.class);

        Scene mockScene = createMock(Scene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        ModelNode mockNode = createMock(ModelNode.class);
        Shape mockShape = createMock(Shape.class);

        // Dictate correct behaviour.
        expect(mockRenderingEngine.getScene()).andStubReturn(null);
        expect(mockRenderingEngine.getCamera()).andStubReturn(null);
        mockRenderingEngine.setScene(mockScene);
        mockRenderingEngine.setCamera(null);
        mockRenderingEngine.advance();
        expect(mockCamera.getPickCamera(null)).andStubReturn(null);
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getNode(0)).andStubReturn(mockNode);
        expect(mockNode.getModel()).andStubReturn(mockShape);
        replay(mockRenderingEngine, mockCamera, mockScene, mockSceneGraph, mockNode, mockShape);

        // Setup test environment.
        testObject.setGL(mockGl);
        testObject.setRenderingEngine(mockRenderingEngine);
        testObject.init();
        testObject.getSelectBuffer().put(new int[] {1, -999, -999, 0});
        testObject.getSelectBuffer().rewind();

        // Perform test
        PickEvent pick = testObject.pickScene(mockScene, mockCamera, null);

        // Verify test results.
        assertEquals(1, pick.getHitCount());
        assertEquals(mockNode, pick.getHit(0).getNode());
        assertEquals(null, pick.getHit(0).getPrimitive());
    }

    /**
     * Unit test the method {@link com.se.simplicity.jogl.picking.WidgetJOGLPicker.pickSceneGraph pickSceneGraph()} with the special condition that
     * the picked primitive is a <code>VertexGroup</code>.
     */
    @Test
    public void pickSceneVertexGroup()
    {
        // Create dependencies.
        MockGL mockGl = new MockGL();
        mockGl.setReturnValue(1);

        RenderingEngine mockRenderingEngine = createMock(RenderingEngine.class);
        Camera mockCamera = createMock(Camera.class);

        Scene mockScene = createMock(Scene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        ModelNode mockNode = createMock(ModelNode.class);
        VertexGroup mockParentVertexGroup = createMock(VertexGroup.class);
        VertexGroup mockChildVertexGroup = createMock(VertexGroup.class);

        // Dictate correct behaviour.
        expect(mockRenderingEngine.getScene()).andStubReturn(null);
        expect(mockRenderingEngine.getCamera()).andStubReturn(null);
        mockRenderingEngine.setScene(mockScene);
        mockRenderingEngine.setCamera(null);
        mockRenderingEngine.advance();
        expect(mockCamera.getPickCamera(null)).andStubReturn(null);
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getNode(0)).andStubReturn(mockNode);
        expect(mockNode.getModel()).andStubReturn(mockParentVertexGroup);
        expect(mockParentVertexGroup.createFaceSubsetVG(20)).andStubReturn(mockChildVertexGroup);
        replay(mockRenderingEngine, mockCamera, mockScene, mockSceneGraph, mockNode, mockParentVertexGroup);

        // Initialise test environment.
        testObject.setGL(mockGl);
        testObject.setRenderingEngine(mockRenderingEngine);
        testObject.init();
        testObject.getSelectBuffer().put(new int[] {2, -999, -999, 0, 20});
        testObject.getSelectBuffer().rewind();

        // Perform test
        PickEvent pick = testObject.pickScene(mockScene, mockCamera, null);

        // Verify test results.
        assertEquals(1, pick.getHitCount());
        assertEquals(mockNode, pick.getHit(0).getNode());
        assertEquals(null, pick.getHit(0).getPrimitive());
    }
}
