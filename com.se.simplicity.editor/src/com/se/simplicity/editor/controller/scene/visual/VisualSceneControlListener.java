/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.controller.scene.visual;

import org.eclipse.swt.events.ControlAdapter;
import org.eclipse.swt.events.ControlEvent;

import com.se.simplicity.editor.model.scene.MetaDataCamera;
import com.se.simplicity.editor.view.scene.visual.VisualSceneView;
import com.se.simplicity.jogl.rendering.SimpleJOGLCamera;
import com.se.simplicity.viewport.Viewport;

public class VisualSceneControlListener extends ControlAdapter
{
    private Viewport model;

    private VisualSceneView view;

    public VisualSceneControlListener(Viewport model, VisualSceneView view)
    {
        this.model = model;
        this.view = view;
    }

    public void controlResized(final ControlEvent event)
    {
        model.setSize(view.getBounds().width, view.getBounds().height);

        // TODO Specific to only one camera type!
        SimpleJOGLCamera camera = (SimpleJOGLCamera) ((MetaDataCamera) model.getRenderingEngine().getCamera()).getWrappedCamera();
        camera.setFrameAspectRatio((view.getBounds().height * 1.0f) / (view.getBounds().width * 1.0f));
        camera.setFrameWidth(view.getBounds().width / 1000.0f);
    }
}
