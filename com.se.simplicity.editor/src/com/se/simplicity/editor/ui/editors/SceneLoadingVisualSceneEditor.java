/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.ui.editors;

import org.apache.log4j.Logger;
import org.eclipse.ui.IEditorInput;
import org.eclipse.ui.IFileEditorInput;
import org.eclipse.ui.PartInitException;

import com.se.simplicity.scene.Scene;
import com.se.simplicity.util.scene.SceneFactory;

/**
 * <p>
 * An eclipse editor that displays a <code>Scene</code> visually on a 3D canvas using the JOGL rendering environment.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SceneLoadingVisualSceneEditor extends VisualSceneEditor
{
    /**
     * <p>
     * Creates an instance of <code>VisualSceneEditor</code>.
     * </p>
     */
    public SceneLoadingVisualSceneEditor()
    {
        super();
    }

    @Override
    public Scene loadScene(final IEditorInput input) throws PartInitException
    {
        IFileEditorInput fileInput = (IFileEditorInput) input;
        String sceneName = fileInput.getFile().getFullPath().toString();

        Scene scene = null;
        try
        {
            scene = SceneFactory.loadFromSource(fileInput.getFile().getContents());
        }
        catch (Exception e)
        {
            Logger.getLogger(getClass()).error("Failed to load Scene from file '" + sceneName + "'.", e);
            throw new PartInitException("Failed to load Scene from file '" + sceneName + "'.", e);
        }

        return (scene);
    }
}
