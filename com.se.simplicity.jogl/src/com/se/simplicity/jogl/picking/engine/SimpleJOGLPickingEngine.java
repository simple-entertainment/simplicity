/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.jogl.picking.engine;

import java.awt.Dimension;
import java.util.ArrayList;
import java.util.List;

import javax.media.opengl.GL;

import org.apache.log4j.Logger;

import com.se.simplicity.jogl.JOGLComponent;
import com.se.simplicity.jogl.engine.JOGLEngine;
import com.se.simplicity.jogl.rendering.SimpleJOGLCamera;
import com.se.simplicity.picking.Pick;
import com.se.simplicity.picking.Picker;
import com.se.simplicity.picking.engine.PickingEngine;
import com.se.simplicity.picking.event.PickEvent;
import com.se.simplicity.picking.event.PickListener;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.engine.RenderingEngine;
import com.se.simplicity.scene.Scene;

/**
 * <p>
 * Manages the picking of a {@link com.se.simplicity.scene.Scene Scene} in a JOGL environment. This implementation uses only simple picking techniques
 * and properties.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SimpleJOGLPickingEngine extends JOGLEngine implements PickingEngine
{
    /**
     * <p>
     * The default preferred frequency (advancements per second) of this <code>SimpleJOGLPickingEngine</code>.
     * </p>
     */
    private static final int DEFAULT_PREFERRED_FREQUENCY = 24;

    /**
     * <p>
     * The number of milliseconds in a second.
     * </p>
     */
    private static final double MILLISECONDS_IN_A_SECOND = 1000.0;

    /**
     * The viewpoint that will be adapted to create the picking viewpoint.
     */
    private Camera fCamera;

    /**
     * <p>
     * The <code>PickListener</code>s to be invoked when a <code>Scene</code> is picked.
     * </p>
     */
    private List<PickListener> fListeners;

    /**
     * <p>
     * Logs messages associated with this class.
     * </p>
     */
    private Logger logger;

    /**
     * <p>
     * The <code>Picker</code> that picks the <code>Scene</code> for this <code>SimpleJOGLPickingEngine</code>.
     * </p>
     */
    private Picker fPicker;

    /**
     * <p>
     * The outstanding picks to be performed against a <code>Scene</code>.
     * </p>
     */
    private List<Pick> fPicks;

    /**
     * <p>
     * The preferred frequency (advancements per second) of this <code>SimpleJOGLPickingEngine</code>.
     * </p>
     */
    private int fPreferredFrequency;

    /**
     * <p>
     * A <code>RenderingEngine</code> who's <code>Scene</code> and <code>Camera</code> are used when picking.
     * </p>
     */
    private RenderingEngine fRenderingEngine;

    /**
     * The <code>Scene</code> to pick.
     */
    private Scene fScene;

    /**
     * <p>
     * Creates an instance of <code>JOGLPickingEngine</code>.
     * </p>
     */
    public SimpleJOGLPickingEngine()
    {
        fCamera = null;
        fListeners = new ArrayList<PickListener>();
        logger = Logger.getLogger(getClass().getName());
        fPicker = null;
        fPicks = new ArrayList<Pick>();
        fPreferredFrequency = DEFAULT_PREFERRED_FREQUENCY;
        fRenderingEngine = null;
        fScene = null;
    }

    @Override
    public void addPickListener(final PickListener listener)
    {
        fListeners.add(listener);
    }

    @Override
    public void advance()
    {
        if (fPicks.isEmpty())
        {
            return;
        }

        if (fRenderingEngine != null)
        {
            if (fRenderingEngine.getScene() != null)
            {
                fScene = fRenderingEngine.getScene();
            }

            if (fRenderingEngine.getCamera() != null)
            {
                fCamera = fRenderingEngine.getCamera();
            }
        }

        // For every pick.
        for (Pick pick : fPicks)
        {
            firePickEvent(fPicker.pickScene(fScene, fCamera, pick));
        }

        fPicks.clear();
    }

    /**
     * <p>
     * Converts the coordinates of the given <code>Pick</code> from viewport coordinates to <code>SceneGraph</code> coordinates.
     * </p>
     * 
     * @param viewportSize The size of the viewport from which the original coordinates were retrieved.
     * @param pick The <code>Pick</code> to convert the coordinates of.
     * 
     * @return A <code>Pick</code> with <code>SceneGraph</code> coordinates.
     */
    public Pick convertPickCoordinatesFromViewportToSceneGraph(final Dimension viewportSize, final Pick pick)
    {
        SimpleJOGLCamera simpleJoglCamera = (SimpleJOGLCamera) this.fCamera;

        pick.setHeight((float) pick.getHeight() / (float) viewportSize.height
                * (simpleJoglCamera.getFrameWidth() * simpleJoglCamera.getFrameAspectRatio()));
        pick.setWidth((float) pick.getWidth() / (float) viewportSize.width * simpleJoglCamera.getFrameWidth());
        pick.setX(((float) pick.getX() / (float) viewportSize.width * simpleJoglCamera.getFrameWidth()));
        pick.setY(((float) pick.getY() / (float) viewportSize.height * (simpleJoglCamera.getFrameWidth() * simpleJoglCamera.getFrameAspectRatio())));

        return (pick);
    }

    @Override
    public void destroy()
    {}

    @Override
    public void firePickEvent(final PickEvent event)
    {
        for (PickListener listener : fListeners)
        {
            listener.scenePicked(event);
        }
    }

    @Override
    public Camera getCamera()
    {
        return (fCamera);
    }

    @Override
    public Picker getPicker()
    {
        return (fPicker);
    }

    @Override
    public List<Pick> getPicks()
    {
        return (fPicks);
    }

    @Override
    public int getPreferredFrequency()
    {
        return (fPreferredFrequency);
    }

    /**
     * <p>
     * Retrieves the <code>RenderingEngine</code> who's <code>Scene</code> and <code>Camera</code> are used when picking.
     * </p>
     * 
     * @return The <code>RenderingEngine</code> who's <code>Scene</code> and <code>Camera</code> are used when picking.
     */
    public RenderingEngine getRenderingEngine()
    {
        return (fRenderingEngine);
    }

    @Override
    public Scene getScene()
    {
        return (fScene);
    }

    @Override
    public void init()
    {}

    @Override
    public void pick(final float x, final float y, final float width, final float height)
    {
        Pick pick = new Pick();
        pick.setX(x);
        pick.setY(y);
        pick.setWidth(width);
        pick.setHeight(height);

        pick(pick);
    }

    @Override
    public void pick(final Pick pick)
    {
        fPicks.add(pick);
    }

    @Override
    public void pickViewport(final Dimension viewportSize, final int x, final int y, final int width, final int height)
    {
        Pick pick = new Pick();
        pick.setX(x);
        pick.setY(y);
        pick.setWidth(width);
        pick.setHeight(height);

        pickViewport(viewportSize, pick);
    }

    @Override
    public void pickViewport(final Dimension viewportSize, final Pick pick)
    {
        fPicks.add(convertPickCoordinatesFromViewportToSceneGraph(viewportSize, pick));
    }

    @Override
    public void removePickListener(final PickListener listener)
    {
        fListeners.remove(listener);
    }

    @Override
    public void reset()
    {}

    @Override
    public void run()
    {
        init();

        while (!Thread.interrupted())
        {
            sleep();
            advance();
        }

        destroy();
    }

    @Override
    public void setCamera(final Camera camera)
    {
        fCamera = camera;
    }

    @Override
    public void setGL(final GL gl)
    {
        super.setGL(gl);

        if (fPicker != null)
        {
            ((JOGLComponent) fPicker).setGL(getGL());
        }
    }

    @Override
    public void setPicker(final Picker picker)
    {
        fPicker = picker;

        ((JOGLComponent) fPicker).setGL(getGL());
    }

    @Override
    public void setPreferredFrequency(final int preferredFrequency)
    {
        fPreferredFrequency = preferredFrequency;
    }

    /**
     * <p>
     * Sets the <code>RenderingEngine</code> who's <code>Scene</code> and <code>Camera</code> are used when picking. The ability to set a
     * <code>RenderingEngine</code> is a convenience as in most cases picking will be associated with a particular rendered image. This
     * <code>SimpleJOGLPickingEngine</code> synchronises the <code>Scene</code> and <code>Camera</code> from the <code>RenderingEngine</code> every
     * time it advances if one is provided.
     * </p>
     * 
     * @param renderingEngine The <code>RenderingEngine</code> who's <code>Scene</code> and <code>Camera</code> are used when picking.
     */
    public void setRenderingEngine(final RenderingEngine renderingEngine)
    {
        fRenderingEngine = renderingEngine;

        if (fRenderingEngine.getScene() != null)
        {
            fScene = fRenderingEngine.getScene();
        }

        if (fRenderingEngine.getCamera() != null)
        {
            fCamera = fRenderingEngine.getCamera();
        }
    }

    @Override
    public void setScene(final Scene scene)
    {
        fScene = scene;
    }

    /**
     * <p>
     * Causes this <code>SimpleJOGLPickingEngine</code> to sleep for the appropriate amount of time to allow for its preferred frequency.
     * </p>
     */
    protected void sleep()
    {
        try
        {
            Thread.sleep((long) MILLISECONDS_IN_A_SECOND / fPreferredFrequency);
        }
        catch (InterruptedException e)
        {
            Thread.currentThread().interrupt();

            logger.debug("The engine was interrupted while sleeping.");
        }
    }
}
