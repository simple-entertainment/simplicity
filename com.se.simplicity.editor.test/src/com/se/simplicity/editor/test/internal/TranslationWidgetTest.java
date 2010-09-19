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

import com.se.simplicity.editor.internal.TranslationWidget;
import com.se.simplicity.editor.internal.selection.SceneSelection;
import com.se.simplicity.model.shape.Capsule;
import com.se.simplicity.model.shape.Shape;
import com.se.simplicity.model.shape.Sphere;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.model.ModelNode;
import com.se.simplicity.vector.SimpleRGBColourVectorf4;
import com.se.simplicity.vector.SimpleTransformationMatrixf44;
import com.se.simplicity.vector.TransformationMatrixf;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.editor.internal.TranslationWidget TranslationWidget}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class TranslationWidgetTest
{
    /**
     * An instance of the class being unit tested.
     */
    private TranslationWidget testObject;

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        testObject = new TranslationWidget();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.TranslationWidget#executeMove(int, int) executeMove(int, int)} with the special
     * condition that the currently selected widget node supports x axis translation only.
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
        assertEquals(0.2f, transformation.getXAxisTranslation(), 0.0001f);
        assertEquals(0.0f, transformation.getYAxisTranslation(), 0.0001f);
        assertEquals(0.0f, transformation.getZAxisTranslation(), 0.0001f);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.TranslationWidget#executeMove(int, int) executeMove(int, int)} with the special
     * condition that the currently selected widget node supports y axis translation only.
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
        assertEquals(0.0f, transformation.getXAxisTranslation(), 0.0001f);
        assertEquals(0.2f, transformation.getYAxisTranslation(), 0.0001f);
        assertEquals(0.0f, transformation.getZAxisTranslation(), 0.0001f);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.TranslationWidget#executeMove(int, int) executeMove(int, int)} with the special
     * condition that the currently selected widget node supports z axis translation only.
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
        assertEquals(0.0f, transformation.getXAxisTranslation(), 0.0001f);
        assertEquals(0.0f, transformation.getYAxisTranslation(), 0.0001f);
        assertEquals(0.2f, transformation.getZAxisTranslation(), 0.0001f);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.TranslationWidget#setSelection(SceneSelection) setSelection(SceneSelection)}.
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
     * Unit test the method {@link com.se.simplicity.editor.internal.TranslationWidget#setSelectedNodeComponent(ModelNode)
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
     * Unit test the method {@link com.se.simplicity.editor.internal.TranslationWidget#updateView(Camera) updateView(Camera)}.
     * </p>
     */
    @Test
    public void updateView()
    {
        // Create dependencies.
        Camera mockCamera = createMock(Camera.class);
        Node mockCameraNode = createMock(Node.class);
        SimpleTransformationMatrixf44 cameraTransformation = new SimpleTransformationMatrixf44();
        cameraTransformation.setXAxisTranslation(-10.0f);

        SceneSelection mockSelection = createMock(SceneSelection.class);
        Node mockSceneNode = createMock(Node.class);
        SimpleTransformationMatrixf44 sceneTransformation = new SimpleTransformationMatrixf44();
        sceneTransformation.setXAxisTranslation(10.0f);
        sceneTransformation.setZAxisRotation((float) Math.toRadians(10.0));

        // Dictate correct behaviour.
        expect(mockCamera.getNode()).andStubReturn(mockCameraNode);
        expect(mockCameraNode.getAbsoluteTransformation()).andStubReturn(cameraTransformation);
        expect(mockSelection.isEmpty()).andStubReturn(false);
        expect(mockSelection.getSceneComponent()).andStubReturn(mockSceneNode);
        expect(mockSceneNode.getAbsoluteTransformation()).andStubReturn(sceneTransformation);
        replay(mockCamera, mockCameraNode, mockSelection, mockSceneNode);

        // Initialise test environment.
        testObject.setSelection(mockSelection);

        // Perform test.
        testObject.updateView(mockCamera);

        // Verify test results.
        TransformationMatrixf testTransformation = testObject.getRootNode().getTransformation();
        assertEquals(0.0f, testTransformation.getXAxisRotation(), 0.0001f);
        assertEquals(0.0f, testTransformation.getYAxisRotation(), 0.0001f);
        assertEquals(Math.toRadians(10.0), testTransformation.getZAxisRotation(), 0.0001f);
        assertEquals(10.0f, testTransformation.getXAxisTranslation(), 0.0001f);
        assertEquals(0.0f, testTransformation.getYAxisTranslation(), 0.0001f);
        assertEquals(0.0f, testTransformation.getZAxisTranslation(), 0.0001f);

        ModelNode xCapsuleNode = (ModelNode) testObject.getRootNode().getChildren().get(0);
        assertEquals(2.0f, ((Capsule) xCapsuleNode.getModel()).getLength(), 0.0001f);
        assertEquals(0.2f, ((Capsule) xCapsuleNode.getModel()).getRadius(), 0.0001f);

        ModelNode yCapsuleNode = (ModelNode) testObject.getRootNode().getChildren().get(1);
        assertEquals(2.0f, ((Capsule) yCapsuleNode.getModel()).getLength(), 0.0001f);
        assertEquals(0.2f, ((Capsule) yCapsuleNode.getModel()).getRadius(), 0.0001f);

        ModelNode zCapsuleNode = (ModelNode) testObject.getRootNode().getChildren().get(2);
        assertEquals(2.0f, ((Capsule) zCapsuleNode.getModel()).getLength(), 0.0001f);
        assertEquals(0.2f, ((Capsule) zCapsuleNode.getModel()).getRadius(), 0.0001f);

        ModelNode freeSphereNode = (ModelNode) testObject.getRootNode().getChildren().get(3);
        assertEquals(0.4f, ((Sphere) freeSphereNode.getModel()).getRadius(), 0.0001f);
    }
}
