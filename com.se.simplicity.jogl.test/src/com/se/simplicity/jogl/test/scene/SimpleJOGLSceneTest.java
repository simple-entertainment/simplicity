/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.jogl.test.scene;

import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.replay;
import static org.easymock.classextension.EasyMock.reset;
import static org.easymock.classextension.EasyMock.verify;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import java.util.ArrayList;

import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.jogl.rendering.SimpleJOGLCamera;
import com.se.simplicity.jogl.rendering.SimpleJOGLLight;
import com.se.simplicity.jogl.scene.SimpleJOGLScene;
import com.se.simplicity.jogl.test.mocks.MockGL;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.Light;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.jogl.scene.SimpleJOGLScene SimpleJOGLScene}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SimpleJOGLSceneTest
{
    /**
     * An instance of the class being unit tested.
     */
    private SimpleJOGLScene testObject;

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.scene.Scene.addCamera addCamera()}.
     * </p>
     */
    @Test
    public void addCamera()
    {
        SimpleJOGLCamera mockCamera = createMock(SimpleJOGLCamera.class);

        mockCamera.setGL(null);
        replay(mockCamera);

        testObject.addCamera(mockCamera);

        assertTrue(testObject.getCameras().contains(mockCamera));

        verify(mockCamera);
    }
    
    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.scene.Scene.addLight addLight()}.
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
        testObject = new SimpleJOGLScene();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.scene.Scene.setCameras setCameras()}.
     * </p>
     */
    @Test
    public void setCameras()
    {
        SimpleJOGLCamera mockCamera1 = createMock(SimpleJOGLCamera.class);
        SimpleJOGLCamera mockCamera2 = createMock(SimpleJOGLCamera.class);

        ArrayList<Camera> cameras = new ArrayList<Camera>();
        cameras.add(mockCamera1);
        cameras.add(mockCamera2);

        reset(mockCamera1, mockCamera2);
        mockCamera1.setGL(null);
        mockCamera2.setGL(null);
        replay(mockCamera1, mockCamera2);

        testObject.setCameras(cameras);

        assertEquals(cameras, testObject.getCameras());

        verify(mockCamera1, mockCamera2);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.scene.Scene.setCameras setCameras()}.
     * </p>
     */
    @Test
    public void setGL()
    {
        SimpleJOGLCamera mockCamera1 = createMock(SimpleJOGLCamera.class);
        SimpleJOGLCamera mockCamera2 = createMock(SimpleJOGLCamera.class);
        SimpleJOGLLight mockLight1 = createMock(SimpleJOGLLight.class);
        SimpleJOGLLight mockLight2 = createMock(SimpleJOGLLight.class);
        MockGL mockGl = new MockGL();

        ArrayList<Camera> cameras = new ArrayList<Camera>();
        cameras.add(mockCamera1);
        cameras.add(mockCamera2);
        ArrayList<Light> lights = new ArrayList<Light>();
        lights.add(mockLight1);
        lights.add(mockLight2);

        testObject.setCameras(cameras);
        testObject.setLights(lights);

        reset(mockCamera1, mockCamera2, mockLight1, mockLight2);
        mockCamera1.setGL(mockGl);
        mockCamera2.setGL(mockGl);
        mockLight1.setGL(mockGl);
        mockLight2.setGL(mockGl);
        replay(mockCamera1, mockCamera2, mockLight1, mockLight2);

        testObject.setGL(mockGl);

        verify(mockCamera1, mockCamera2, mockLight1, mockLight2);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.scene.Scene.setLights setLights()}.
     * </p>
     */
    @Test
    public void setLights()
    {
        SimpleJOGLLight mockLight1 = createMock(SimpleJOGLLight.class);
        SimpleJOGLLight mockLight2 = createMock(SimpleJOGLLight.class);

        ArrayList<Light> lights = new ArrayList<Light>();
        lights.add(mockLight1);
        lights.add(mockLight2);

        reset(mockLight1, mockLight2);
        mockLight1.setGL(null);
        mockLight2.setGL(null);
        replay(mockLight1, mockLight2);

        testObject.setLights(lights);

        assertEquals(lights, testObject.getLights());

        verify(mockLight1, mockLight2);
    }
}
