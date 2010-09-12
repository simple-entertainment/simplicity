/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.ui.editors.outline;

import org.eclipse.swt.widgets.Composite;
import org.eclipse.ui.views.contentoutline.ContentOutlinePage;

import com.se.simplicity.scene.Scene;

/**
 * <p>
 * Displays an outline of a {@link com.se.simplicity.scene.Scene Scene}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SceneOutlinePage extends ContentOutlinePage
{
    /**
     * <p>
     * The {@link com.se.simplicity.scene.Scene Scene} to display the outline of.
     * </p>
     */
    private Scene fScene;

    /**
     * <p>
     * Creates an instance of <code>SceneOutlinePage</code>.
     * </p>
     * 
     * @param scene The {@link com.se.simplicity.scene.Scene Scene} to display the outline of.
     */
    public SceneOutlinePage(final Scene scene)
    {
        fScene = scene;
    }

    @Override
    public void createControl(final Composite parent)
    {
        super.createControl(parent);

        getTreeViewer().setContentProvider(new SceneContentProvider());
        getTreeViewer().setLabelProvider(new SceneLabelProvider());
        getTreeViewer().setInput(fScene);
    }
}
