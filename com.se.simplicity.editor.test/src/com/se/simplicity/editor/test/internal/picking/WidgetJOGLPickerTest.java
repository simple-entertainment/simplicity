/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.test.internal.picking;

import static org.easymock.EasyMock.anyObject;
import static org.easymock.EasyMock.expect;
import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.replay;
import static org.junit.Assert.assertEquals;

import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.editor.internal.Widget;
import com.se.simplicity.editor.internal.picking.WidgetJOGLPicker;
import com.se.simplicity.jogl.test.mocks.MockGL;
import com.se.simplicity.model.VertexGroup;
import com.se.simplicity.model.shape.Shape;
import com.se.simplicity.picking.Pick;
import com.se.simplicity.picking.event.PickEvent;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.engine.RenderingEngine;
import com.se.simplicity.scene.Scene;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.SceneGraph;
import com.se.simplicity.scenegraph.model.ModelNode;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.jogl.rendering.WidgetJOGLPicker WidgetJOGLPicker}.
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
     * Unit test the method {@link com.se.simplicity.editor.internal.picking.WidgetJOGLPicker#pickScene(Scene, Camera, Pick) pickScene(Scene, Camera,
     * Pick)} with the special condition that the Widget is not hittable.
     */
    @Test
    public void pickSceneNotHittable()
    {
        // Create dependencies.
        Widget mockWidget = createMock(Widget.class);
        ModelNode mockNode = createMock(ModelNode.class);

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
        expect(mockWidget.isHittable()).andStubReturn(false);
        expect(mockWidget.getRootNode()).andStubReturn(mockNode);
        expect(mockNode.hasChildren()).andStubReturn(false);
        mockNode.setID(1);
        expect(mockNode.getID()).andStubReturn(1);
        mockNode.setParent((Node) anyObject());
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
        replay(mockWidget, mockNode, mockRenderingEngine, mockCamera, mockScene, mockSceneGraph, mockNode0, mockShape0, mockNode1, mockShape1);

        // Setup test environment.
        testObject.setGL(mockGl);
        testObject.setRenderingEngine(mockRenderingEngine);
        testObject.setWidget(mockWidget);
        testObject.init();
        testObject.getSelectBuffer().put(new int[] {3, -999, -999, 0, 0, 1, 3, -999, -999, 1, 0, 1});
        testObject.getSelectBuffer().rewind();

        // Perform test
        PickEvent pickEvent = testObject.pickScene(mockScene, mockCamera, null);

        // Verify test results.
        assertEquals(2, pickEvent.getHitCount());
        assertEquals(mockNode0, pickEvent.getHit(0).getNode());
        assertEquals(mockShape0, pickEvent.getHit(0).getPrimitive());
        assertEquals(mockNode1, pickEvent.getHit(1).getNode());
        assertEquals(mockShape1, pickEvent.getHit(1).getPrimitive());
    }

    /**
     * Unit test the method {@link com.se.simplicity.editor.internal.picking.WidgetJOGLPicker#pickScene(Scene, Camera, Pick) pickScene(Scene, Camera,
     * Pick)} with the special condition that the Widget's Model being picked is a Shape.
     */
    @Test
    public void pickSceneShape()
    {
        // Create dependencies.
        Widget mockWidget = createMock(Widget.class);
        ModelNode mockNode = createMock(ModelNode.class);
        Shape mockShape = createMock(Shape.class);

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
        expect(mockWidget.isHittable()).andStubReturn(true);
        expect(mockWidget.getRootNode()).andStubReturn(mockNode);
        expect(mockNode.hasChildren()).andStubReturn(false);
        mockNode.setID(1);
        expect(mockNode.getID()).andStubReturn(1);
        mockNode.setParent((Node) anyObject());
        expect(mockNode.getModel()).andStubReturn(mockShape);
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
        replay(mockWidget, mockNode, mockRenderingEngine, mockCamera, mockScene, mockSceneGraph, mockNode0, mockShape0, mockNode1, mockShape1);

        // Setup test environment.
        testObject.setGL(mockGl);
        testObject.setRenderingEngine(mockRenderingEngine);
        testObject.setWidget(mockWidget);
        testObject.init();
        testObject.getSelectBuffer().put(new int[] {3, -999, -999, 0, 0, 1, 3, -999, -999, 1, 0, 1});
        testObject.getSelectBuffer().rewind();

        // Perform test
        PickEvent pickEvent = testObject.pickScene(mockScene, mockCamera, null);

        // Verify test results.
        assertEquals(2, pickEvent.getHitCount());
        assertEquals(mockNode, pickEvent.getHit(0).getNode());
        assertEquals(mockShape, pickEvent.getHit(0).getPrimitive());
        assertEquals(mockNode, pickEvent.getHit(1).getNode());
        assertEquals(mockShape, pickEvent.getHit(1).getPrimitive());
    }

    /**
     * Unit test the method {@link com.se.simplicity.editor.internal.picking.WidgetJOGLPicker#pickScene(Scene, Camera, Pick) pickScene(Scene, Camera,
     * Pick)} with the special condition that the Widget's Model being picked is a VertexGroup.
     */
    @Test
    public void pickSceneVertexGroup()
    {
        // Create dependencies.
        Widget mockWidget = createMock(Widget.class);
        ModelNode mockNode = createMock(ModelNode.class);
        VertexGroup mockVertexGroup = createMock(VertexGroup.class);
        VertexGroup mockVertexGroupSubset = createMock(VertexGroup.class);

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
        expect(mockWidget.isHittable()).andStubReturn(true);
        expect(mockWidget.getRootNode()).andStubReturn(mockNode);
        expect(mockNode.hasChildren()).andStubReturn(false);
        mockNode.setID(1);
        expect(mockNode.getID()).andStubReturn(1);
        mockNode.setParent((Node) anyObject());
        expect(mockNode.getModel()).andStubReturn(mockVertexGroup);
        expect(mockVertexGroup.createFaceSubsetVG(0)).andStubReturn(mockVertexGroupSubset);
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
        replay(mockWidget, mockNode, mockVertexGroup, mockRenderingEngine, mockCamera, mockScene, mockSceneGraph, mockNode0, mockShape0, mockNode1,
                mockShape1);

        // Setup test environment.
        testObject.setGL(mockGl);
        testObject.setRenderingEngine(mockRenderingEngine);
        testObject.setWidget(mockWidget);
        testObject.init();
        testObject.getSelectBuffer().put(new int[] {4, -999, -999, 0, 0, 1, 0, 4, -999, -999, 1, 0, 1, 0});
        testObject.getSelectBuffer().rewind();

        // Perform test
        PickEvent pickEvent = testObject.pickScene(mockScene, mockCamera, null);

        // Verify test results.
        assertEquals(2, pickEvent.getHitCount());
        assertEquals(mockNode, pickEvent.getHit(0).getNode());
        assertEquals(mockVertexGroupSubset, pickEvent.getHit(0).getPrimitive());
        assertEquals(mockNode, pickEvent.getHit(1).getNode());
        assertEquals(mockVertexGroupSubset, pickEvent.getHit(1).getPrimitive());
    }
}
