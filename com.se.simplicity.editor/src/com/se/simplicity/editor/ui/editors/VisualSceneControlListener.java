/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.ui.editors;

import java.awt.Dimension;
import java.util.ArrayList;
import java.util.List;

import org.eclipse.swt.events.ControlAdapter;
import org.eclipse.swt.events.ControlEvent;
import org.eclipse.swt.opengl.GLCanvas;

import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.engine.RenderingEngine;

/**
 * <p>
 * Listens for resize events on a 3D canvas and updates the <code>RenderingEngine</code>s and <code>Camera</code>s to reflect the change in size.
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
    private GLCanvas fCanvas;

    /**
     * <p>
     * Determines whether the current <code>Camera</code>'s aspect ratio should be synchronised with the <code>RenderingEngine</code>'s aspect ratio.
     * </p>
     */
    private boolean fCameraAspectRatioSyncronised;

    /**
     * <p>
     * The <code>RenderingEngine</code>s to update to reflect the change in viewport size.
     * </p>
     */
    private List<RenderingEngine> fRenderingEngines;

    /**
     * <p>
     * Creates an instance of <code>VisualSceneControlListener</code>.
     * </p>
     * 
     * @param canvas The 3D canvas whose size has changed.
     */
    public VisualSceneControlListener(final GLCanvas canvas)
    {
        fCanvas = canvas;

        fCameraAspectRatioSyncronised = false;
        fRenderingEngines = new ArrayList<RenderingEngine>();
    }

    /**
     * <p>
     * Adds the given <code>RenderingEngine</code> to the <code>RenderingEngine</code>s to be updated.
     * </p>
     * 
     * @param renderingEngine The <code>RenderingEngine</code> to be updated.
     */
    public void addRenderingEngine(final RenderingEngine renderingEngine)
    {
        fRenderingEngines.add(renderingEngine);
    }

    @Override
    public void controlResized(final ControlEvent event)
    {
        for (RenderingEngine renderingEngine : fRenderingEngines)
        {
            Dimension viewportSize = new Dimension();
            viewportSize.setSize(fCanvas.getBounds().width, fCanvas.getBounds().height);
            renderingEngine.setViewportSize(viewportSize);

            Camera camera = renderingEngine.getCamera();
            if (fCameraAspectRatioSyncronised && camera != null)
            {
                camera.setFrameAspectRatio((float) fCanvas.getBounds().height / (float) fCanvas.getBounds().width);
            }
        }
    }

    /**
     * <p>
     * Determines whether the current <code>Camera</code>'s aspect ratio should be synchronised with the <code>RenderingEngine</code>'s aspect ratio.
     * </p>
     * 
     * @return True if the current <code>Camera</code>'s aspect ratio should be synchronised with the <code>RenderingEngine</code>'s aspect ratio,
     * false otherwise.
     */
    public boolean isCameraAspectRatioSyncronised()
    {
        return (fCameraAspectRatioSyncronised);
    }

    /**
     * <p>
     * Determines whether the current <code>Camera</code>'s aspect ratio should be synchronised with the <code>RenderingEngine</code>'s aspect ratio.
     * </p>
     * 
     * @param cameraAspectRatioSyncronised Determines whether the current <code>Camera</code>'s aspect ratio should be synchronised with the
     * <code>RenderingEngine</code>'s aspect ratio.
     */
    public void setCameraAspectRatioSyncronised(final boolean cameraAspectRatioSyncronised)
    {
        fCameraAspectRatioSyncronised = cameraAspectRatioSyncronised;
    }
}
