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

import com.se.simplicity.editor.internal.SceneManager;
import com.se.simplicity.editor.internal.TranslationWidget;
import com.se.simplicity.model.shape.Shape;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.model.ModelNode;
import com.se.simplicity.vector.SimpleRGBColourVectorf4;
import com.se.simplicity.vector.SimpleTransformationMatrixf44;

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

        SceneManager.getSceneManager().reset();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.TranslationWidget#executeMove(int, int) executeMove(int, int)}.
     * </p>
     */
    @Test
    public void executeMove()
    {
        // Create dependencies.
        Node mockNode = createMock(Node.class);
        SimpleTransformationMatrixf44 transformation = new SimpleTransformationMatrixf44();

        // Dictate correct behaviour.
        expect(mockNode.getTransformation()).andStubReturn(transformation);
        replay(mockNode);

        // Initialise test environment.
        testObject.setSelectedSceneComponent(mockNode);

        // Perform test.
        testObject.executeMove(10, 10);

        // Verify test results.
        assertEquals(0.1f, transformation.getXAxisTranslation(), 0.0001f);
        assertEquals(0.1f, transformation.getYAxisTranslation(), 0.0001f);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.TranslationWidget#setSelectedNodeComponent(ModelNode)
     * setSelectedNodeComponent(ModelNode)}.
     * </p>
     */
    @Test
    public void setSelectedNodeComponent()
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
}
