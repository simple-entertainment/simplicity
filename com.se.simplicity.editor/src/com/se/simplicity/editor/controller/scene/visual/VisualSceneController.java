/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.controller.scene.visual;

import java.io.File;

import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Display;
import org.eclipse.ui.IEditorInput;
import org.eclipse.ui.IEditorSite;

import com.se.simplicity.editor.controller.EditorPartController;
import com.se.simplicity.editor.model.scene.SceneFactory;
import com.se.simplicity.editor.view.scene.visual.VisualSceneView;
import com.se.simplicity.jogl.JOGLComponent;
import com.se.simplicity.vector.SimpleTranslationVectorf4;
import com.se.simplicity.viewport.Viewport;

public class VisualSceneController implements EditorPartController
{
    private Viewport model;

    private VisualSceneView view;

    @Override
    public void init(Composite parent)
    {
        view.setParent(parent);

        // FOR TESTING PURPOSES ONLY // TODO remove
        // model.getPickingEngine().addPickListener(new PickAdapter()
        // {
        // public void scenePicked(PickEvent event)
        // {
        // for (int hitIndex = 0; hitIndex < event.getHitCount(); hitIndex++)
        // {
        // ModelNode node = (ModelNode) event.getHit(hitIndex)[event.getHit(hitIndex).length - 2];
        //
        // float[] colours = ((ArrayVG) node.getVertexGroup()).getColours();
        //
        // for (int index = 0; index < colours.length; index += 3)
        // {
        // colours[index] = Color.yellow.getRed();
        // colours[index + 1] = Color.yellow.getGreen();
        // colours[index + 2] = Color.yellow.getBlue();
        // }
        // }
        // }
        // });
    }

    @Override
    public void init(final IEditorSite site, final IEditorInput input)
    {
        ((JOGLComponent) model).setGL(view.getGLContext().getGL());

        view.addControlListener(new VisualSceneControlListener(model, view));
        view.addMouseListener(new VisualSceneMouseListener(model, view));

        try
        {
            model.getRenderingEngine().setScene(SceneFactory.loadFromSourceFile(new File("/home/simple/workspace/com.se.simplicity.editor/samples/triangle.xml")));//input.getName())));
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }

        // FOR TESTING PURPOSES ONLY // TODO remove
        model.getRenderingEngine().setCamera(model.getRenderingEngine().getScene().getCameras().get(0));

        Display display = view.getShell().getDisplay();
        display.asyncExec(new VisualSceneDisplayer(display, model, view));

        // FOR TESTING PURPOSES ONLY // TODO remove
        new Thread(new Runnable()
        {
            public void run()
            {
                while (true)
                {
                    model.getRenderingEngine().getScene().getSceneGraph().getNode(3).getTransformation().rotate((float) (1.0f * Math.PI / 180.0f),
                            new SimpleTranslationVectorf4(0.0f, 1.0f, 0.0f, 1.0f));
                    try
                    {
                        Thread.sleep(16);
                    }
                    catch (InterruptedException e)
                    {
                        e.printStackTrace();
                    }
                }
            }
        }).start();
    }

    @Override
    public void setFocus()
    {}

    @Override
    public void setModel(final Object newModel)
    {
        model = (Viewport) newModel;
    }

    @Override
    public void setView(final Object newView)
    {
        view = (VisualSceneView) newView;
    }

    @Override
    public void update()
    {}
}
