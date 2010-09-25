/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.test.internal;

import static org.easymock.EasyMock.expect;
import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.replay;
import static org.easymock.classextension.EasyMock.reset;
import static org.easymock.classextension.EasyMock.verify;
import static org.junit.Assert.assertEquals;

import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.editor.internal.RotationWidget;
import com.se.simplicity.editor.internal.selection.SceneSelection;
import com.se.simplicity.model.shape.Shape;
import com.se.simplicity.model.shape.Sphere;
import com.se.simplicity.model.shape.Torus;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.model.ModelNode;
import com.se.simplicity.vector.SimpleRGBColourVectorf4;
import com.se.simplicity.vector.SimpleTransformationMatrixf44;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.editor.internal.RotationWidget RotationWidget}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class RotationWidgetTest
{
    /**
     * An instance of the class being unit tested.
     */
    private RotationWidget testObject;

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        testObject = new RotationWidget();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.RotationWidget#executeMove(int, int) executeMove(int, int)} with the special
     * condition that the currently selected widget node supports x axis rotation only.
     * </p>
     */
    @Test
    public void executeMoveXAxis()
    {
        // Create dependencies.
        SceneSelection mockSelection = createMock(SceneSelection.class);
        Node mockNode = createMock(Node.class);
        SimpleTransformationMatrixf44 transformation = new SimpleTransformationMatrixf44();

        // Dictate correct behaviour.
        expect(mockSelection.isEmpty()).andStubReturn(false);
        expect(mockSelection.getSceneComponent()).andStubReturn(mockNode);
        expect(mockNode.getTransformation()).andStubReturn(transformation);
        replay(mockSelection, mockNode);

        // Initialise test environment.
        testObject.setSelection(mockSelection);
        testObject.setSelectedWidgetNode((ModelNode) testObject.getRootNode().getChildren().get(0));

        // Perform test.
        testObject.executeMove(10, -10);

        // Verify test results.
        assertEquals(Math.toRadians(-20.0f), transformation.getXAxisRotation(), 0.0001f);
        assertEquals(0.0f, transformation.getYAxisRotation(), 0.0001f);
        assertEquals(0.0f, transformation.getZAxisRotation(), 0.0001f);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.RotationWidget#executeMove(int, int) executeMove(int, int)} with the special
     * condition that the currently selected widget node supports y axis rotation only.
     * </p>
     */
    @Test
    public void executeMoveYAxis()
    {
        // Create dependencies.
        SceneSelection mockSelection = createMock(SceneSelection.class);
        Node mockNode = createMock(Node.class);
        SimpleTransformationMatrixf44 transformation = new SimpleTransformationMatrixf44();

        // Dictate correct behaviour.
        expect(mockSelection.isEmpty()).andStubReturn(false);
        expect(mockSelection.getSceneComponent()).andStubReturn(mockNode);
        expect(mockNode.getTransformation()).andStubReturn(transformation);
        replay(mockSelection, mockNode);

        // Initialise test environment.
        testObject.setSelection(mockSelection);
        testObject.setSelectedWidgetNode((ModelNode) testObject.getRootNode().getChildren().get(1));

        // Perform test.
        testObject.executeMove(10, -10);

        // Verify test results.
        assertEquals(0.0f, transformation.getXAxisRotation(), 0.0001f);
        assertEquals(Math.toRadians(20.0f), transformation.getYAxisRotation(), 0.0001f);
        assertEquals(0.0f, transformation.getZAxisRotation(), 0.0001f);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.RotationWidget#executeMove(int, int) executeMove(int, int)} with the special
     * condition that the currently selected widget node supports z axis rotation only.
     * </p>
     */
    @Test
    public void executeMoveZAxis()
    {
        // Create dependencies.
        SceneSelection mockSelection = createMock(SceneSelection.class);
        Node mockNode = createMock(Node.class);
        SimpleTransformationMatrixf44 transformation = new SimpleTransformationMatrixf44();

        // Dictate correct behaviour.
        expect(mockSelection.isEmpty()).andStubReturn(false);
        expect(mockSelection.getSceneComponent()).andStubReturn(mockNode);
        expect(mockNode.getTransformation()).andStubReturn(transformation);
        replay(mockSelection, mockNode);

        // Initialise test environment.
        testObject.setSelection(mockSelection);
        testObject.setSelectedWidgetNode((ModelNode) testObject.getRootNode().getChildren().get(2));

        // Perform test.
        testObject.executeMove(10, -10);

        // Verify test results.
        assertEquals(0.0f, transformation.getXAxisRotation(), 0.0001f);
        assertEquals(0.0f, transformation.getYAxisRotation(), 0.0001f);
        assertEquals(Math.toRadians(20.0f), transformation.getZAxisRotation(), 0.0001f);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.RotationWidget#setSelection(SceneSelection) setSelection(SceneSelection)}.
     * </p>
     */
    @Test
    public void setSelection()
    {
        // Create dependencies.
        ModelNode mockModelNode = createMock(ModelNode.class);
        Shape mockShape = createMock(Shape.class);
        SimpleRGBColourVectorf4 mockColour = createMock(SimpleRGBColourVectorf4.class);

        // Dictate correct behaviour.
        expect(mockModelNode.getModel()).andStubReturn(mockShape);
        expect(mockShape.getColour()).andStubReturn(mockColour);
        replay(mockModelNode, mockShape);

        // Dictate expected results.
        mockColour.setAlpha(1.0f);
        replay(mockColour);

        // Perform test.
        testObject.setSelectedWidgetNode(mockModelNode);

        // Verify test results.
        verify(mockColour);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.RotationWidget#setSelectedNodeComponent(ModelNode)
     * setSelectedNodeComponent(ModelNode)}, specifically the functionality that reverts the state of the previously selected widget node.
     * </p>
     */
    @Test
    public void setSelectedWidgetNodeRevert()
    {
        // Create dependencies.
        ModelNode mockModelNode = createMock(ModelNode.class);
        Shape mockShape = createMock(Shape.class);
        SimpleRGBColourVectorf4 mockColour = createMock(SimpleRGBColourVectorf4.class);

        // Dictate correct behaviour.
        expect(mockModelNode.getModel()).andStubReturn(mockShape);
        expect(mockShape.getColour()).andStubReturn(mockColour);
        mockColour.setAlpha(1.0f);
        replay(mockModelNode, mockShape, mockColour);

        // Initialise test environment.
        testObject.setSelectedWidgetNode(mockModelNode);

        // Dictate expected results.
        reset(mockColour);
        mockColour.setAlpha(0.5f);
        replay(mockColour);

        // Perform test.
        testObject.setSelectedWidgetNode(null);

        // Verify test results.
        verify(mockColour);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.RotationWidget#init(Camera, boolean) init(Camera, boolean)}.
     * </p>
     */
    @Test
    public void init()
    {
        // Create dependencies.
        Camera mockCamera = createMock(Camera.class);
        Node mockCameraNode = createMock(Node.class);
        SimpleTransformationMatrixf44 cameraTransformation = new SimpleTransformationMatrixf44();
        cameraTransformation.setXAxisTranslation(-10.0f);

        // Dictate correct behaviour.
        expect(mockCamera.getNode()).andStubReturn(mockCameraNode);
        expect(mockCameraNode.getAbsoluteTransformation()).andStubReturn(cameraTransformation);
        replay(mockCamera, mockCameraNode);

        // Perform test.
        testObject.init(mockCamera, true);

        // Verify test results.
        ModelNode xTorusNode = (ModelNode) testObject.getRootNode().getChildren().get(0);
        assertEquals(0.1f, ((Torus) xTorusNode.getModel()).getInnerRadius(), 0.0001f);
        assertEquals(1.0f, ((Torus) xTorusNode.getModel()).getOuterRadius(), 0.0001f);

        ModelNode yTorusNode = (ModelNode) testObject.getRootNode().getChildren().get(1);
        assertEquals(0.1f, ((Torus) yTorusNode.getModel()).getInnerRadius(), 0.0001f);
        assertEquals(1.0f, ((Torus) yTorusNode.getModel()).getOuterRadius(), 0.0001f);

        ModelNode zTorusNode = (ModelNode) testObject.getRootNode().getChildren().get(2);
        assertEquals(0.1f, ((Torus) zTorusNode.getModel()).getInnerRadius(), 0.0001f);
        assertEquals(1.0f, ((Torus) zTorusNode.getModel()).getOuterRadius(), 0.0001f);

        ModelNode freeSphereNode0 = (ModelNode) testObject.getRootNode().getChildren().get(3);
        assertEquals(0.2f, ((Sphere) freeSphereNode0.getModel()).getRadius(), 0.0001f);

        assertEquals(1.0f, freeSphereNode0.getTransformation().getXAxisTranslation(), 0.0001f);
        assertEquals(0.0f, freeSphereNode0.getTransformation().getYAxisTranslation(), 0.0001f);
        assertEquals(0.0f, freeSphereNode0.getTransformation().getZAxisTranslation(), 0.0001f);

        ModelNode freeSphereNode1 = (ModelNode) testObject.getRootNode().getChildren().get(4);
        assertEquals(-1.0f, freeSphereNode1.getTransformation().getXAxisTranslation(), 0.0001f);
        assertEquals(0.0f, freeSphereNode1.getTransformation().getYAxisTranslation(), 0.0001f);
        assertEquals(0.0f, freeSphereNode1.getTransformation().getZAxisTranslation(), 0.0001f);

        ModelNode freeSphereNode2 = (ModelNode) testObject.getRootNode().getChildren().get(5);
        assertEquals(0.0f, freeSphereNode2.getTransformation().getXAxisTranslation(), 0.0001f);
        assertEquals(1.0f, freeSphereNode2.getTransformation().getYAxisTranslation(), 0.0001f);
        assertEquals(0.0f, freeSphereNode2.getTransformation().getZAxisTranslation(), 0.0001f);

        ModelNode freeSphereNode3 = (ModelNode) testObject.getRootNode().getChildren().get(6);
        assertEquals(0.0f, freeSphereNode3.getTransformation().getXAxisTranslation(), 0.0001f);
        assertEquals(-1.0f, freeSphereNode3.getTransformation().getYAxisTranslation(), 0.0001f);
        assertEquals(0.0f, freeSphereNode3.getTransformation().getZAxisTranslation(), 0.0001f);

        ModelNode freeSphereNode4 = (ModelNode) testObject.getRootNode().getChildren().get(7);
        assertEquals(0.0f, freeSphereNode4.getTransformation().getXAxisTranslation(), 0.0001f);
        assertEquals(0.0f, freeSphereNode4.getTransformation().getYAxisTranslation(), 0.0001f);
        assertEquals(1.0f, freeSphereNode4.getTransformation().getZAxisTranslation(), 0.0001f);

        ModelNode freeSphereNode5 = (ModelNode) testObject.getRootNode().getChildren().get(8);
        assertEquals(0.0f, freeSphereNode5.getTransformation().getXAxisTranslation(), 0.0001f);
        assertEquals(0.0f, freeSphereNode5.getTransformation().getYAxisTranslation(), 0.0001f);
        assertEquals(-1.0f, freeSphereNode5.getTransformation().getZAxisTranslation(), 0.0001f);
    }
}
