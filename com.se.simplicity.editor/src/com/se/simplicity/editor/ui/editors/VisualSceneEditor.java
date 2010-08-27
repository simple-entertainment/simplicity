/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.ui.editors;

import javax.media.opengl.GLContext;
import javax.media.opengl.GLDrawableFactory;

import org.apache.commons.logging.LogFactory;
import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.swt.SWT;
import org.eclipse.swt.opengl.GLCanvas;
import org.eclipse.swt.opengl.GLData;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Display;
import org.eclipse.ui.IEditorInput;
import org.eclipse.ui.IEditorSite;
import org.eclipse.ui.IFileEditorInput;
import org.eclipse.ui.PartInitException;
import org.eclipse.ui.part.EditorPart;

import com.se.simplicity.editor.internal.SceneManager;
import com.se.simplicity.jogl.JOGLComponent;
import com.se.simplicity.jogl.viewport.SimpleJOGLViewport;
import com.se.simplicity.vector.SimpleTranslationVectorf4;

public class VisualSceneEditor extends EditorPart
{
    private GLCanvas view;

    private SimpleJOGLViewport model;

    @Override
    public void createPartControl(final Composite parent)
    {
        GLData data = new GLData();
        data.doubleBuffer = true;
        view = new GLCanvas(parent, SWT.NONE, data);

        view.setCurrent();
        GLContext glContext = GLDrawableFactory.getFactory().createExternalGLContext();
        ((JOGLComponent) model).setGL(glContext.getGL());

        view.addControlListener(new VisualSceneControlListener(model, view));
        view.addMouseListener(new VisualSceneMouseListener(model, view));

        Display display = view.getShell().getDisplay();
        display.asyncExec(new VisualSceneDisplayer(display, model, view, glContext));

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
    public void doSave(final IProgressMonitor monitor)
    {
    // TODO Auto-generated method stub

    }

    @Override
    public void doSaveAs()
    {
    // TODO Auto-generated method stub

    }

    @Override
    public void init(final IEditorSite site, final IEditorInput input) throws PartInitException
    {
        setSite(site);
        setInput(input);
        setPartName(input.getName());

        IFileEditorInput fileInput = (IFileEditorInput) input;
        String filePath = fileInput.getFile().getFullPath().toString();

        try
        {
            SceneManager.getSceneManager().addSceneDefinition(fileInput);
        }
        catch (Exception e)
        {
            LogFactory.getLog(getClass()).error("Failed to load scene from file '" + filePath + "'.", e);
            throw new PartInitException("Failed to load scene from file '" + filePath + "'.", e);
        }

        model = (SimpleJOGLViewport) SceneManager.getSceneManager().getViewportToScene(filePath);

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
    public boolean isDirty()
    {
        // TODO Auto-generated method stub
        return false;
    }

    @Override
    public boolean isSaveAsAllowed()
    {
        // TODO Auto-generated method stub
        return false;
    }

    @Override
    public void setFocus()
    {
    // TODO Auto-generated method stub

    }

    public void update()
    {
    // SceneFactory.updateFromSource(scene, source);
    }
}
