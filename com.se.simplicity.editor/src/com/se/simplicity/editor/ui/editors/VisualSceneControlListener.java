/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.ui.editors;

import org.eclipse.swt.events.ControlAdapter;
import org.eclipse.swt.events.ControlEvent;
import org.eclipse.swt.opengl.GLCanvas;

import com.se.simplicity.jogl.rendering.SimpleJOGLCamera;
import com.se.simplicity.util.metadata.rendering.MetaDataCamera;
import com.se.simplicity.viewport.Viewport;

/**
 * <p>
 * Listens for resize events on a 3D canvas and updates the <code>Viewport</code> and <code>Camera</code> to reflect the change in size.
 * </p>
 * 
 * @author Gary Buyn
 */
public class VisualSceneControlListener extends ControlAdapter
{
    /**
     * <p>
     * The 3D canvas whose size has changed.
     * </p>
     */
    private GLCanvas canvas;

    /**
     * <p>
     * Determines whether the current <code>Camera</code>'s aspect ratio should be synchronised with the <code>Viewport</code>'s aspect ratio.
     * </p>
     */
    private boolean cameraAspectRatioSyncronised;

    /**
     * <p>
     * The <code>Viewport</code> to update to reflect the change in size.
     * </p>
     */
    private Viewport viewport;

    /**
     * <p>
     * Creates an instance of <code>VisualSceneControlListener</code>.
     * </p>
     * 
     * @param newViewport The <code>Viewport</code> to update to reflect the change in size.
     * @param newCanvas The 3D canvas whose size has changed.
     */
    public VisualSceneControlListener(final Viewport newViewport, final GLCanvas newCanvas)
    {
        viewport = newViewport;
        canvas = newCanvas;

        cameraAspectRatioSyncronised = false;
    }

    @Override
    public void controlResized(final ControlEvent event)
    {
        viewport.setSize(canvas.getBounds().width, canvas.getBounds().height);

        if (cameraAspectRatioSyncronised)
        {
            // TODO Specific to only one camera type!
            SimpleJOGLCamera camera = (SimpleJOGLCamera) ((MetaDataCamera) viewport.getRenderingEngine().getCamera()).getWrappedCamera();
            camera.setFrameAspectRatio((canvas.getBounds().height * 1.0f) / (canvas.getBounds().width * 1.0f));
        }
    }

    /**
     * <p>
     * Determines whether the current <code>Camera</code>'s aspect ratio should be synchronised with the <code>Viewport</code>'s aspect ratio.
     * </p>
     * 
     * @return True if the current <code>Camera</code>'s aspect ratio should be synchronised with the <code>Viewport</code>'s aspect ratio, false
     * otherwise.
     */
    public boolean isCameraAspectRatioSyncronised()
    {
        return (cameraAspectRatioSyncronised);
    }

    /**
     * <p>
     * Determines whether the current <code>Camera</code>'s aspect ratio should be synchronised with the <code>Viewport</code>'s aspect ratio.
     * </p>
     * 
     * @param newCameraAspectRatioSyncronised Determines whether the current <code>Camera</code>'s aspect ratio should be synchronised with the
     * <code>Viewport</code>'s aspect ratio.
     */
    public void setCameraAspectRatioSyncronised(final boolean newCameraAspectRatioSyncronised)
    {
        cameraAspectRatioSyncronised = newCameraAspectRatioSyncronised;
    }
}
