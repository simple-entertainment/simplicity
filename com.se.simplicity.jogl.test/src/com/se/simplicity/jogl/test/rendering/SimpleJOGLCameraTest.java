package com.se.simplicity.jogl.test.rendering;

import static org.easymock.EasyMock.expect;
import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.replay;
import static org.easymock.classextension.EasyMock.reset;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNull;
import static org.junit.Assert.assertTrue;

import javax.media.opengl.GL;

import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.SEInvalidOperationException;
import com.se.simplicity.jogl.rendering.SimpleJOGLCamera;
import com.se.simplicity.jogl.test.mocks.MockGL;
import com.se.simplicity.picking.Pick;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.vector.SimpleTransformationMatrixf44;
import com.se.simplicity.vector.SimpleTranslationVectorf4;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.jogl.rendering.SimpleJOGLCamera SimpleJOGLCamera}.
 * </p>
 * 
 * @author simple
 */
public class SimpleJOGLCameraTest
{
    /**
     * An instance of the class being unit tested.
     */
    private SimpleJOGLCamera testObject;

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.rendering.SimpleJOGLCamera.apply apply()}.
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
        expect(mockNode.getTransformation()).andStubReturn(matrix);
        expect(mockNode.getParent()).andStubReturn(null);
        replay(mockNode);

        testObject.apply();

        assertEquals(1, mockGl.getMethodCallCountIgnoreParams("glMultMatrixf"), 0);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.rendering.SimpleJOGLCamera.apply apply()} with the special condition that the
     * {@link com.se.simplicity.jogl.rendering.SimpleJOGLCamera SimpleJOGLCamera} is not initialised.
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
        expect(mockNode.getTransformation()).andStubReturn(matrix);
        expect(mockNode.getParent()).andStubReturn(null);
        replay(mockNode);

        testObject.apply();

        assertEquals(2, mockGl.getMethodCallCountIgnoreParams("glMatrixMode"), 0);
        assertEquals(1, mockGl.getMethodCallCountIgnoreParams("glMultMatrixf"), 0);
    }

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public final void before()
    {
        testObject = new SimpleJOGLCamera();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.rendering.SimpleJOGLCamera.getPickCamera getPickCamera()}.
     * </p>
     */
    @Test
    public void getPickCamera()
    {
        Pick mockPick = createMock(Pick.class);

        expect(mockPick.getX()).andStubReturn(0.05f);
        expect(mockPick.getY()).andStubReturn(0.0375f);
        expect(mockPick.getWidth()).andStubReturn(0.001f);
        expect(mockPick.getHeight()).andStubReturn(0.00075f);
        replay(mockPick);

        SimpleJOGLCamera pickCamera = (SimpleJOGLCamera) testObject.getPickCamera(mockPick);

        assertEquals(testObject.getFarClippingDistance(), pickCamera.getFarClippingDistance(), 0.0f);
        assertEquals(testObject.getFrameAspectRatio(), pickCamera.getFrameAspectRatio(), 0.0f);
        assertEquals(0.001f, pickCamera.getFrameWidth(), 0.0f);
        assertEquals(0.0f, pickCamera.getFrameX(), 0.0f);
        assertEquals(0.0f, pickCamera.getFrameY(), 0.0f);
        assertEquals(pickCamera.getGL(), pickCamera.getGL());
        assertEquals(testObject.getNearClippingDistance(), pickCamera.getNearClippingDistance(), 0.0f);
        assertEquals(testObject.getNode(), pickCamera.getNode());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.rendering.SimpleJOGLCamera.getTransformation getTransformation()}.
     * </p>
     * 
     * @throws SEInvalidOperationException Thrown by the setup of a helper object.
     */
    @Test
    public void getTransformation() throws SEInvalidOperationException
    {
        Node mockNode1 = createMock(Node.class);
        Node mockNode2 = createMock(Node.class);
        SimpleTransformationMatrixf44 matrix1 = new SimpleTransformationMatrixf44();
        matrix1.translate(new SimpleTranslationVectorf4(0.0f, 10.0f, 0.0f, 1.0f));
        SimpleTransformationMatrixf44 matrix2 = new SimpleTransformationMatrixf44();
        matrix2.rotate((float) (90.0f * Math.PI / 180), new SimpleTranslationVectorf4(1.0f, 0.0f, 0.0f, 1.0f));

        testObject.setNode(mockNode1);

        reset(mockNode1, mockNode2);
        expect(mockNode1.getTransformation()).andStubReturn(matrix1);
        expect(mockNode1.getParent()).andStubReturn(mockNode2);
        expect(mockNode2.getTransformation()).andStubReturn(matrix2);
        expect(mockNode2.getParent()).andStubReturn(null);
        replay(mockNode1, mockNode2);

        SimpleTransformationMatrixf44 matrix3 = new SimpleTransformationMatrixf44();
        matrix3.multiplyRight(matrix1);
        matrix3.multiplyRight(matrix2);
        matrix3.invert();

        assertEquals(matrix3, testObject.getTransformation());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.rendering.SimpleJOGLCamera.getTransformation getTransformation()} with the special condition
     * that the {@link com.se.simplicity.jogl.rendering.SimpleJOGLCamera SimpleJOGLCamera} being tested does not have a <code>Node</code>.
     * </p>
     */
    @Test
    public void getTransformationNoNode()
    {
        assertNull(testObject.getTransformation());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.rendering.SimpleJOGLCamera.init init()}.
     * </p>
     */
    @Test
    public void init()
    {
        MockGL mockGl = new MockGL();

        testObject.setGL(mockGl);

        mockGl.reset();

        testObject.init();

        assertTrue(mockGl.methodCallOrderCheck(0, "glMatrixMode", new Object[] {GL.GL_PROJECTION}, 0, "glLoadIdentity", null));
        assertTrue(mockGl.methodCallOrderCheck(0, "glLoadIdentity", null, 0, "glFrustum", new Object[] {-0.05f, 0.05f, -0.0375f, 0.0375f, 0.1f, 1000.0f}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glFrustum", new Object[] {-0.05f, 0.05f, -0.0375f, 0.0375f, 0.1f, 1000.0f}, 0, "glMatrixMode", new Object[] {GL.GL_MODELVIEW}));
    }
}
