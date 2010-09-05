/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.jogl.test.rendering;

import static org.easymock.EasyMock.expect;
import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.replay;
import static org.easymock.classextension.EasyMock.reset;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNull;

import javax.media.opengl.GL;

import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.SEInvalidOperationException;
import com.se.simplicity.jogl.rendering.SimpleJOGLLight;
import com.se.simplicity.jogl.test.mocks.MockGL;
import com.se.simplicity.rendering.LightingMode;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.vector.SimpleTransformationMatrixf44;
import com.se.simplicity.vector.SimpleTranslationVectorf4;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.jogl.rendering.SimpleJOGLLight SimpleJOGLLight}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SimpleJOGLLightTest
{
    /**
     * An instance of the class being unit tested.
     */
    private SimpleJOGLLight testObject;

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.rendering.SimpleJOGLLight.apply apply()}.
     * </p>
     */
    @Test
    public void apply()
    {
        MockGL mockGl = new MockGL();
        Node mockNode = createMock(Node.class);
        SimpleTransformationMatrixf44 matrix = new SimpleTransformationMatrixf44();

        testObject.setGL(mockGl);
        testObject.setNode(mockNode);
        testObject.init();

        mockGl.reset();
        reset(mockNode);
        expect(mockNode.getAbsoluteTransformation()).andStubReturn(matrix);
        expect(mockNode.getParent()).andStubReturn(null);
        replay(mockNode);

        testObject.apply();

        assertEquals(4, mockGl.getMethodCallCountIgnoreParams("glLightfv"), 0);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.rendering.SimpleJOGLLight.apply apply()} with the special condition that the
     * {@link com.se.simplicity.jogl.rendering.SimpleJOGLCamera SimpleJOGLLight} is not initialised.
     * </p>
     */
    @Test
    public void applyNotInitialised()
    {
        MockGL mockGl = new MockGL();
        Node mockNode = createMock(Node.class);
        SimpleTransformationMatrixf44 matrix = new SimpleTransformationMatrixf44();

        testObject.setGL(mockGl);
        testObject.setNode(mockNode);

        mockGl.reset();
        reset(mockNode);
        expect(mockNode.getAbsoluteTransformation()).andStubReturn(matrix);
        expect(mockNode.getParent()).andStubReturn(null);
        replay(mockNode);

        testObject.apply();

        assertEquals(3, mockGl.getMethodCallCountIgnoreParams("glEnable"), 0);
        assertEquals(4, mockGl.getMethodCallCountIgnoreParams("glLightfv"), 0);
    }

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public final void before()
    {
        testObject = new SimpleJOGLLight();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.rendering.SimpleJOGLLight.getTransformation getTransformation()}.
     * </p>
     * 
     * @throws SEInvalidOperationException Thrown by the setup of a helper object.
     */
    @Test
    public void getTransformation() throws SEInvalidOperationException
    {
        Node mockNode = createMock(Node.class);
        SimpleTransformationMatrixf44 matrix = new SimpleTransformationMatrixf44();
        matrix.rotate((float) (90.0f * Math.PI / 180), new SimpleTranslationVectorf4(1.0f, 0.0f, 0.0f, 1.0f));

        testObject.setNode(mockNode);

        expect(mockNode.getAbsoluteTransformation()).andStubReturn(matrix);
        replay(mockNode);

        SimpleTransformationMatrixf44 invertedMatrix = new SimpleTransformationMatrixf44();
        invertedMatrix.multiplyRight(matrix);
        invertedMatrix.invert();

        assertEquals(invertedMatrix, testObject.getTransformation());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.rendering.SimpleJOGLLight.getTransformation getTransformation()} with the special condition
     * that the {@link com.se.simplicity.jogl.rendering.SimpleJOGLCamera SimpleJOGLLight} being tested does not have a <code>Node</code>.
     * </p>
     */
    @Test
    public void getTransformationNoNode()
    {
        assertNull(testObject.getTransformation());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.rendering.SimpleJOGLLight.init init()}.
     * </p>
     */
    @Test
    public void init()
    {
        MockGL mockGl = new MockGL();

        testObject.setGL(mockGl);

        mockGl.reset();

        testObject.init();

        assertEquals(1, mockGl.getMethodCallCount("glEnable", new Object[] {GL.GL_LIGHTING}), 0);
        assertEquals(1, mockGl.getMethodCallCount("glEnable", new Object[] {GL.GL_COLOR_MATERIAL}), 0);
        assertEquals(1, mockGl.getMethodCallCount("glEnable", new Object[] {GL.GL_LIGHT0}), 0);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.rendering.SimpleJOGLLight.init init()} with the special condition that the
     * {@link com.se.simplicity.jogl.rendering.SimpleJOGLLight SimpleJOGLLight} being tested is usng the solid lighting mode.
     * </p>
     */
    @Test
    public void initSolid()
    {
        MockGL mockGl = new MockGL();

        testObject.setGL(mockGl);
        testObject.setLightingMode(LightingMode.SOLID);

        mockGl.reset();

        testObject.init();

        assertEquals(1, mockGl.getMethodCallCount("glDisable", new Object[] {GL.GL_LIGHTING}), 0);
        assertEquals(1, mockGl.getMethodCallCount("glDisable", new Object[] {GL.GL_COLOR_MATERIAL}), 0);
        assertEquals(1, mockGl.getMethodCallCount("glDisable", new Object[] {GL.GL_LIGHT0}), 0);
    }
}
