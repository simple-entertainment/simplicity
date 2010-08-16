package com.se.simplicity.jogl.test.picking.engine;

import static org.easymock.EasyMock.expect;
import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.createNiceMock;
import static org.easymock.classextension.EasyMock.replay;
import static org.easymock.classextension.EasyMock.reset;
import static org.easymock.classextension.EasyMock.verify;
import static org.junit.Assert.assertEquals;

import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.jogl.picking.engine.SimpleJOGLPickingEngine;
import com.se.simplicity.picking.Pick;
import com.se.simplicity.picking.Picker;
import com.se.simplicity.picking.event.PickEvent;
import com.se.simplicity.picking.event.PickListener;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.engine.RenderingEngine;
import com.se.simplicity.scenegraph.SceneGraph;

/**
 * TODO Implement a set of tests
 * 
 * <p>
 * Unit tests for the class {@link com.se.simplicity.jogl.rendering.SimpleJOGLPickingEngine SimpleJOGLPickingEngine}.
 * </p>
 * 
 * @author simple
 */
public class SimpleJOGLPickingEngineTest
{
	/**
	 * An instance of the class being unit tested.
	 */
	private SimpleJOGLPickingEngine testObject;
	
	/**
	 * <p>
	 * Unit test the method {@link com.se.simplicity.jogl.rendering.SimpleJOGLPickingEngine.advance advance()}.
	 * </p>
	 */
	@Test
	public void advance()
	{
		Picker mockPicker = createNiceMock(Picker.class);

		testObject.setPicker(mockPicker);
		testObject.pick(5, 10, 15, 20);
		testObject.pick(10, 20, 30, 40);
		
		reset(mockPicker);
		expect(mockPicker.pickSceneGraph(null, null, testObject.getPicks().get(0)));
		expect(mockPicker.pickSceneGraph(null, null, testObject.getPicks().get(1)));
		replay(mockPicker);

		testObject.advance();
		
		verify(mockPicker);
	}
	
	/**
	 * <p>
	 * Unit test the method {@link com.se.simplicity.jogl.rendering.SimpleJOGLPickingEngine.advance advance()} with the special
	 * condition that the {@link com.se.simplicity.jogl.rendering.SimpleJOGLPickingEngine SimpleJOGLPickingEngine} being tested
	 * does not have any outstanding picks to perform.
	 * </p>
	 */
	@Test
	public void advanceNoPicks()
	{
		Picker mockPicker = createMock(Picker.class);

		testObject.setPicker(mockPicker);
		
		reset(mockPicker);
		expect(mockPicker.pickSceneGraph(null, null, null)).andReturn(null);
		replay(mockPicker);

		testObject.advance();
		
		verify(mockPicker);
	}
	
	/**
	 * <p>
	 * Unit test the method {@link com.se.simplicity.jogl.rendering.SimpleJOGLPickingEngine.advance advance()} with the special
	 * condition that the {@link com.se.simplicity.jogl.rendering.SimpleJOGLPickingEngine SimpleJOGLPickingEngine} being tested
	 * is related to a Rendering Engine.
	 * </p>
	 */
	@Test
	public void advanceRenderingEngine()
	{
		Picker mockPicker = createNiceMock(Picker.class);
		RenderingEngine mockRenderingEngine = createNiceMock(RenderingEngine.class);
		SceneGraph mockSceneGraph = createNiceMock(SceneGraph.class);
		Camera mockCamera = createNiceMock(Camera.class);

		testObject.setPicker(mockPicker);
		testObject.setRenderingEngine(mockRenderingEngine);
		testObject.pick(5, 10, 15, 20);
		testObject.pick(10, 20, 30, 40);
		
		reset(mockPicker, mockRenderingEngine);
		expect(mockRenderingEngine.getSceneGraph()).andReturn(mockSceneGraph);
		expect(mockRenderingEngine.getCamera()).andReturn(mockCamera);
		expect(mockPicker.pickSceneGraph(null, null, testObject.getPicks().get(0)));
		expect(mockPicker.pickSceneGraph(null, null, testObject.getPicks().get(1)));
		replay(mockPicker, mockRenderingEngine);

		testObject.advance();
		
		assertEquals(testObject.getSceneGraph(), mockSceneGraph);
		assertEquals(testObject.getCamera(), mockCamera);
		
		verify(mockPicker, mockRenderingEngine);
	}

	/**
	 * <p>
	 * Setup to perform before each unit test.
	 * </p>
	 */
	@Before
	public void before()
	{
		testObject = new SimpleJOGLPickingEngine();
	}

	/**
	 * Unit test the method {@link com.se.simplicity.jogl.picking.SimpleJOGLPickingEngine.firePickEvent firePickEvent()}.
	 */
	@Test
	public void firePickEvent()
	{
		PickListener mockPickListener1 = createMock(PickListener.class);
		PickListener mockPickListener2 = createMock(PickListener.class);
		PickEvent mockPickEvent = createMock(PickEvent.class);

		testObject.addPickListener(mockPickListener1);
		testObject.addPickListener(mockPickListener2);

		reset(mockPickListener1, mockPickListener2);
		mockPickListener1.scenePicked(mockPickEvent);
		mockPickListener2.scenePicked(mockPickEvent);
		replay(mockPickListener1, mockPickListener2);

		testObject.firePickEvent(mockPickEvent);

		verify(mockPickListener1, mockPickListener2);
	}

	/**
	 * Unit test the method {@link com.se.simplicity.jogl.picking.SimpleJOGLPickingEngine.pick pick()}.
	 */
	@Test
	public void pick()
	{
		testObject.pick(5, 10, 15, 20);

		assertEquals(1, testObject.getPicks().size(), 0);

		Pick pick = testObject.getPicks().get(0);
		assertEquals(5, pick.getX(), 0);
		assertEquals(10, pick.getY(), 0);
		assertEquals(15, pick.getWidth(), 0);
		assertEquals(20, pick.getHeight(), 0);
	}
}
