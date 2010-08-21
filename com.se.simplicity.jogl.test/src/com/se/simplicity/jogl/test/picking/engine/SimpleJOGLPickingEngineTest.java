/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.jogl.test.picking.engine;

import static org.easymock.EasyMock.expect;
import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.replay;
import static org.easymock.classextension.EasyMock.reset;
import static org.easymock.classextension.EasyMock.verify;
import static org.junit.Assert.assertEquals;

import org.junit.Before;
import org.junit.Ignore;
import org.junit.Test;

import com.se.simplicity.jogl.picking.engine.SimpleJOGLPickingEngine;
import com.se.simplicity.jogl.rendering.SimpleJOGLCamera;
import com.se.simplicity.picking.Pick;
import com.se.simplicity.picking.Picker;
import com.se.simplicity.picking.event.PickEvent;
import com.se.simplicity.picking.event.PickListener;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.engine.RenderingEngine;
import com.se.simplicity.viewport.Viewport;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.jogl.rendering.SimpleJOGLPickingEngine SimpleJOGLPickingEngine}.
 * </p>
 * 
 * @author Gary Buyn
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
        Picker mockPicker = createMock(Picker.class);
        RenderingEngine mockRenderingEngine = createMock(RenderingEngine.class);
        Camera mockCamera = createMock(Camera.class);

        testObject.setPicker(mockPicker);
        testObject.setRenderingEngine(mockRenderingEngine);
        testObject.pick(5, 10, 15, 20);
        testObject.pick(10, 20, 30, 40);

        reset(mockPicker);
        expect(mockRenderingEngine.getCamera()).andStubReturn(mockCamera);
        expect(mockPicker.pickScene(null, mockCamera, testObject.getPicks().get(0))).andReturn(null);
        expect(mockPicker.pickScene(null, mockCamera, testObject.getPicks().get(1))).andReturn(null);
        replay(mockPicker, mockRenderingEngine);

        testObject.advance();

        verify(mockPicker);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.rendering.SimpleJOGLPickingEngine.advance advance()} with the special condition that the
     * {@link com.se.simplicity.jogl.rendering.SimpleJOGLPickingEngine SimpleJOGLPickingEngine} being tested does not have any outstanding picks to
     * perform.
     * </p>
     */
    @Test
    public void advanceNoPicks()
    {
        Picker mockPicker = createMock(Picker.class);

        testObject.setPicker(mockPicker);

        reset(mockPicker);
        replay(mockPicker);

        testObject.advance();

        verify(mockPicker);
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
     * Unit test the method {@link com.se.simplicity.jogl.picking.SimpleJOGLPickingEngine.convertPickCoordinatesFromViewportToSceneGraph
     * convertPickCoordinatesFromViewportToSceneGraph()}.
     */
    @Test
    public void convertPickCoordinatesFromViewportToSceneGraph()
    {
        Pick mockPick = createMock(Pick.class);
        Viewport mockViewport = createMock(Viewport.class);
        SimpleJOGLCamera mockCamera = createMock(SimpleJOGLCamera.class);

        expect(mockPick.getX()).andStubReturn(100f);
        expect(mockPick.getY()).andStubReturn(100f);
        expect(mockPick.getWidth()).andStubReturn(2.0f);
        expect(mockPick.getHeight()).andStubReturn(2.0f);

        expect(mockViewport.getWidth()).andStubReturn(200);
        expect(mockViewport.getHeight()).andStubReturn(200);

        expect(mockCamera.getFrameWidth()).andStubReturn(0.1f);
        expect(mockCamera.getFrameAspectRatio()).andStubReturn(0.75f);

        mockPick.setX(0.05f);
        mockPick.setY(0.05f * 0.75f);
        mockPick.setWidth(0.1f / 100);
        mockPick.setHeight((0.1f * 0.75f) / 100);

        testObject.setCamera(mockCamera);

        replay(mockPick, mockViewport, mockCamera);

        testObject.convertPickCoordinatesFromViewportToSceneGraph(mockViewport, mockPick);

        verify(mockPick);
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

        Pick pick0 = testObject.getPicks().get(0);
        assertEquals(5, pick0.getX(), 0);
        assertEquals(10, pick0.getY(), 0);
        assertEquals(15, pick0.getWidth(), 0);
        assertEquals(20, pick0.getHeight(), 0);

        Pick mockPick = createMock(Pick.class);

        testObject.pick(mockPick);

        assertEquals(2, testObject.getPicks().size(), 0);
        assertEquals(mockPick, testObject.getPicks().get(1));
    }

    /**
     * Unit test the method {@link com.se.simplicity.jogl.picking.SimpleJOGLPickingEngine.pickViewport pickViewport()}.
     */
    @Test
    public void pickViewport()
    {
        Viewport mockViewport = createMock(Viewport.class);
        SimpleJOGLCamera mockCamera = createMock(SimpleJOGLCamera.class);

        expect(mockViewport.getHeight()).andStubReturn(200);
        expect(mockViewport.getWidth()).andStubReturn(200);

        expect(mockCamera.getFrameWidth()).andStubReturn(0.1f);
        expect(mockCamera.getFrameAspectRatio()).andStubReturn(0.75f);

        replay(mockViewport, mockCamera);

        testObject.setCamera(mockCamera);

        testObject.pickViewport(mockViewport, 100, 100, 2, 2);

        assertEquals(1, testObject.getPicks().size(), 0);

        Pick pick0 = testObject.getPicks().get(0);
        assertEquals(0.05f, pick0.getX(), 0);
        assertEquals(0.0375f, pick0.getY(), 0);
        assertEquals(0.001f, pick0.getWidth(), 0);
        assertEquals(0.00075f, pick0.getHeight(), 0);

        Pick pick = new Pick();
        pick.setX(50);
        pick.setY(150);
        pick.setWidth(2);
        pick.setHeight(2);

        testObject.pickViewport(mockViewport, pick);

        assertEquals(2, testObject.getPicks().size(), 0);

        Pick pick1 = testObject.getPicks().get(1);
        assertEquals(0.025f, pick1.getX(), 0);
        assertEquals(0.05625f, pick1.getY(), 0.0001f);
        assertEquals(0.001f, pick1.getWidth(), 0);
        assertEquals(0.00075f, pick1.getHeight(), 0);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.picking.engine.SimpleJOGLPickingEngine.run run()}.
     * </p>
     */
    @Test
    @Ignore("May need to use aspect to test")
    public void run()
    {}
}
