package com.se.simplicity.jogl.test.rendering.engine;

import static org.easymock.EasyMock.expect;
import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.createNiceMock;
import static org.easymock.classextension.EasyMock.replay;
import static org.easymock.classextension.EasyMock.reset;
import static org.easymock.classextension.EasyMock.verify;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import javax.media.opengl.GL;

import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.jogl.rendering.SimpleJOGLCamera;
import com.se.simplicity.jogl.rendering.SimpleJOGLLight;
import com.se.simplicity.jogl.rendering.SimpleJOGLRenderer;
import com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine;
import com.se.simplicity.jogl.test.mocks.MockGL;
import com.se.simplicity.rendering.DrawingMode;
import com.se.simplicity.scenegraph.SceneGraph;
import com.se.simplicity.test.mocks.NodeHierarchy;

/**
 * TODO repair tests
 * 
 * <p>
 * Unit tests for the class {@link com.se.simplicity.jogl.rendering.SimpleJOGLRenderingEngine SimpleJOGLRenderingEngine}.
 * </p>
 * 
 * @author simple
 */
public class SimpleJOGLRenderingEngineTest
{
	/**
	 * An instance of the class being unit tested.
	 */
	private SimpleJOGLRenderingEngine testObject;

	/**
	 * <p>
	 * Unit test the method {@link com.se.simplicity.jogl.rendering.SimpleJOGLRenderingEngine.addLight addLight()}.
	 * </p>
	 */
	@Test
	public void addLight()
	{
		SimpleJOGLLight mockLight = createMock(SimpleJOGLLight.class);
		
		mockLight.setGL(null);
		replay(mockLight);

		testObject.addLight(mockLight);

		assertTrue(testObject.getLights().contains(mockLight));

		verify(mockLight);
	}

	/**
	 * <p>
	 * Setup to perform before each unit test.
	 * </p>
	 */
	@Before
	public void before()
	{
		testObject = new SimpleJOGLRenderingEngine();
	}

	/**
	 * <p>
	 * Unit test the method {@link com.se.simplicity.jogl.rendering.SimpleJOGLRenderingEngine.display display()}, specifically the
	 * application of the <code>Camera</code> and <code>Lights</code>.
	 * </p>
	 */
	@Test
	public void displayApplyCameraLights()
	{
		MockGL mockGL = new MockGL();
		
		SimpleJOGLCamera mockCamera = createNiceMock(SimpleJOGLCamera.class);
		SimpleJOGLLight mockLight = createNiceMock(SimpleJOGLLight.class);
		
		testObject.setGL(mockGL);
		testObject.setCamera(mockCamera);
		testObject.addLight(mockLight);
		testObject.setSceneGraph(createMock(SceneGraph.class));

		reset(mockCamera, mockLight);
		mockCamera.apply();
		mockLight.apply();
		replay(mockCamera, mockLight);
		
		//testObject.display();
		
		verify(mockCamera, mockLight);
	}

	/**
	 * <p>
	 * Unit test the method {@link com.se.simplicity.jogl.rendering.SimpleJOGLRenderingEngine.display display()}, specifically clearing
	 * before rendering.
	 * </p>
	 */
	@Test
	public void displayClearing()
	{		
		MockGL mockGL = new MockGL();

		NodeHierarchy nodes = new NodeHierarchy();
		nodes.setBasicNodeHierarchy();

		SceneGraph mockSceneGraph = createMock(SceneGraph.class);

		testObject.setGL(mockGL);
		testObject.setCamera(createMock(SimpleJOGLCamera.class));
		testObject.addLight(createMock(SimpleJOGLLight.class));
		testObject.setSceneGraph(mockSceneGraph);

		// Test with clearing enabled.
		reset(mockSceneGraph);
		expect(mockSceneGraph.getRoot()).andReturn(nodes.node1);
		replay(mockSceneGraph);
		
		//testObject.display();

		assertEquals(1, mockGL.getMethodCallCountIgnoreParams("glClear"), 0);
		assertTrue(mockGL.getMethodCallCountIgnoreParams("glBegin") > 0);
		assertTrue(mockGL.methodCallOrderCheckIgnoreParams(0, "glClear", 0, "glBegin"));

		// Test with clearing disabled.
		testObject.setClearsBeforeRender(false);
		//mockGL.clearMethodCalls();
		
		reset(mockSceneGraph);
		expect(mockSceneGraph.getRoot()).andReturn(nodes.node1);
		replay(mockSceneGraph);
		
		//testObject.display();

		assertEquals(0, mockGL.getMethodCallCountIgnoreParams("glClear"), 0);
	}

	/**
	 * <p>
	 * Unit test the method {@link com.se.simplicity.jogl.rendering.SimpleJOGLRenderingEngine.display display()} with the special
	 * condition that the {@link com.se.simplicity.jogl.rendering.SimpleJOGLRenderingEngine SimpleJOGLRenderingEngine} being tested does not
	 * have a {@link com.se.simplicity.rendering.Camera Camera} to view the {@link com.se.simplicity.scenegraph.SceneGraph
	 * SceneGraph} through.
	 * </p>
	 */
	@Test(expected = IllegalStateException.class)
	public void displayNoCamera()
	{
		//testObject.display();
	}

	/**
	 * <p>
	 * Unit test the method {@link com.se.simplicity.jogl.rendering.SimpleJOGLRenderingEngine.display display()} with the special
	 * condition that the {@link com.se.simplicity.jogl.rendering.SimpleJOGLRenderingEngine SimpleJOGLRenderingEngine} being tested does not
	 * have a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} to render.
	 * </p>
	 */
	@Test(expected = IllegalStateException.class)
	public void displayNoSceneGraph()
	{
		testObject.setCamera(createMock(SimpleJOGLCamera.class));

		//testObject.display();
	}

	/**
	 * <p>
	 * Unit test the method {@link com.se.simplicity.jogl.rendering.SimpleJOGLRenderingEngine.display display()}, specifically the number
	 * of calls to <code>glPushMatrix</code>, <code>glPopMatrix</code> and <code>glMultMatrix</code>.
	 * </p>
	 */
	@Test
	public void displayPopPushMatrixMult()
	{
		MockGL mockGL = new MockGL();

		NodeHierarchy nodes = new NodeHierarchy();
		nodes.setStandardNodeHierarchy();

		SceneGraph mockSceneGraph = createMock(SceneGraph.class);

		testObject.setGL(mockGL);
		testObject.setCamera(createMock(SimpleJOGLCamera.class));
		testObject.addLight(createMock(SimpleJOGLLight.class));
		testObject.setSceneGraph(mockSceneGraph);
		
		reset(mockSceneGraph);
		expect(mockSceneGraph.getRoot()).andReturn(nodes.node1);
		replay(mockSceneGraph);

		//testObject.display();

		assertEquals(8, mockGL.getMethodCallCountIgnoreParams("glPushMatrix"), 0);
		assertEquals(8, mockGL.getMethodCallCountIgnoreParams("glPopMatrix"), 0);
		assertEquals(7, mockGL.getMethodCallCountIgnoreParams("glMultMatrixf"), 0);
	}
	
	/**
	 * <p>
	 * Unit test the method {@link com.se.simplicity.jogl.rendering.SimpleJOGLRenderingEngine.display display()}, specifically the ???.
	 * </p>
	 */
	@Test
	public void displayRenderArrayVG()
	{
		// TODO implement test
	}
	
	/**
	 * <p>
	 * Unit test the method {@link com.se.simplicity.jogl.rendering.SimpleJOGLRenderingEngine.display display()}, specifically the ???.
	 * </p>
	 */
	@Test
	public void displayRenderIndexedArrayVG()
	{
		// TODO implement test
	}

	/**
	 * <p>
	 * Unit test the method {@link com.se.simplicity.jogl.rendering.SimpleJOGLRenderingEngine.init init()}.
	 * </p>
	 */
	@Test
	public void init()
	{
		MockGL mockGL = new MockGL();

		SimpleJOGLCamera mockCamera = createMock(SimpleJOGLCamera.class);
		SimpleJOGLLight mockLight1 = createMock(SimpleJOGLLight.class);
		SimpleJOGLLight mockLight2 = createMock(SimpleJOGLLight.class);

		testObject.setGL(mockGL);
		testObject.setCamera(mockCamera);
		testObject.addLight(mockLight1);
		testObject.addLight(mockLight2);

		reset(mockCamera, mockLight1, mockLight2);
		mockCamera.setGL(mockGL);
		mockLight1.setGL(mockGL);
		mockLight2.setGL(mockGL);
		replay(mockCamera, mockLight1, mockLight2);

		testObject.init();

		verify(mockCamera, mockLight1, mockLight2);
	}

	/**
	 * <p>
	 * Unit test the method {@link com.se.simplicity.jogl.rendering.SimpleJOGLRenderingEngine.setCamera setCamera()}.
	 * </p>
	 */
	@Test
	public void setCamera()
	{
		SimpleJOGLCamera mockCamera = createMock(SimpleJOGLCamera.class);
		
		mockCamera.setGL(null);
		replay();

		testObject.setCamera(mockCamera);
		
		verify();
		assertEquals(mockCamera, testObject.getCamera());
	}

	/**
	 * <p>
	 * Unit test the method {@link com.se.simplicity.jogl.rendering.SimpleJOGLRenderingEngine.setDrawingMode setDrawingMode()}.
	 * </p>
	 */
	@Test
	public void setDrawingMode()
	{
		testObject.setGL(new MockGL());

		testObject.setDrawingMode(DrawingMode.EDGES);

		assertEquals(GL.GL_LINE_LOOP, testObject.getJOGLDrawingMode(), 0);

		testObject.setDrawingMode(DrawingMode.FACES);

		assertEquals(GL.GL_TRIANGLES, testObject.getJOGLDrawingMode(), 0);

		testObject.setDrawingMode(DrawingMode.VERTICES);

		assertEquals(GL.GL_POINTS, testObject.getJOGLDrawingMode(), 0);
	}
}
