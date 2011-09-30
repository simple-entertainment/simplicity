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
import static org.junit.Assert.assertEquals;

import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.editor.internal.SelectionWidget;
import com.se.simplicity.model.ArrayVG;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.model.ModelNode;
import com.se.simplicity.vector.SimpleTransformationMatrixf44;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.editor.internal.SelectionWidget SelectionWidget}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SelectionWidgetTest
{
    /**
     * An instance of the class being unit tested.
     */
    private SelectionWidget testObject;

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        testObject = new SelectionWidget();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.SelectionWidget#init(Camera, boolean) init(Camera, boolean)} with the special
     * condition that the Widget is NOT being rendered for the selection.
     * </p>
     */
    @Test
    public void initNotSelected()
    {
        // Create dependencies.
        Camera mockCamera = createMock(Camera.class);
        Node mockCameraNode = createMock(Node.class);
        SimpleTransformationMatrixf44 cameraTransformation = new SimpleTransformationMatrixf44();
        cameraTransformation.setXAxisTranslation(-10.0f);
        cameraTransformation.setZAxisRotation((float) Math.toRadians(-10.0));

        // Dictate correct behaviour.
        expect(mockCamera.getNode()).andStubReturn(mockCameraNode);
        expect(mockCameraNode.getAbsoluteTransformation()).andReturn(cameraTransformation);
        replay(mockCamera, mockCameraNode);

        // Perform test.
        testObject.init(mockCamera, false);

        // Verify test results.
        ArrayVG selectionModel = (ArrayVG) ((ModelNode) testObject.getRootNode()).getModel();

        float[] vertices = selectionModel.getVertices();
        assertEquals(-0.15f, vertices[0], 0.0001f);
        assertEquals(0.07f, vertices[1], 0.0001f);
        assertEquals(0.0f, vertices[2], 0.0001f);

        float[] colours = selectionModel.getColours();
        assertEquals(0.0f, colours[0], 0.0001f);
        assertEquals(0.0f, colours[1], 0.0001f);
        assertEquals(0.0f, colours[2], 0.0001f);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.SelectionWidget#init(Camera, boolean) init(Camera, boolean)} with the special
     * condition that the Widget is being rendered for the selection.
     * </p>
     */
    @Test
    public void initSelected()
    {
        // Create dependencies.
        Camera mockCamera = createMock(Camera.class);
        Node mockCameraNode = createMock(Node.class);
        SimpleTransformationMatrixf44 cameraTransformation = new SimpleTransformationMatrixf44();
        cameraTransformation.setXAxisTranslation(-10.0f);
        cameraTransformation.setZAxisRotation((float) Math.toRadians(-10.0));

        // Dictate correct behaviour.
        expect(mockCamera.getNode()).andStubReturn(mockCameraNode);
        expect(mockCameraNode.getAbsoluteTransformation()).andReturn(cameraTransformation);
        replay(mockCamera, mockCameraNode);

        // Perform test.
        testObject.init(mockCamera, true);

        // Verify test results.
        ArrayVG selectionModel = (ArrayVG) ((ModelNode) testObject.getRootNode()).getModel();

        float[] vertices = selectionModel.getVertices();
        assertEquals(-0.15f, vertices[0], 0.0001f);
        assertEquals(0.07f, vertices[1], 0.0001f);
        assertEquals(0.0f, vertices[2], 0.0001f);

        float[] colours = selectionModel.getColours();
        assertEquals(0.0f, colours[0], 0.0001f);
        assertEquals(1.0f, colours[1], 0.0001f);
        assertEquals(1.0f, colours[2], 0.0001f);
    }
}
