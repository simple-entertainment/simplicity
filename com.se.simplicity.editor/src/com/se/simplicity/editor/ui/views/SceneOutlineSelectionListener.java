/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.ui.views;

import java.util.Map;

import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.events.SelectionListener;
import org.eclipse.swt.widgets.TreeItem;

import com.se.simplicity.editor.internal.SceneManager;
import com.se.simplicity.scenegraph.Node;

/**
 * <p>
 * Listens for selection events on a tree outline of the contents of the <code>Scene</code> displayed in the active editor (if there is one) and
 * notifies the {@link com.se.simplicity.editor.internal.SceneManager SceneManager} of the change in active <code>Node</code>.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SceneOutlineSelectionListener implements SelectionListener
{
    /**
     * <p>
     * A map from <code>TreeItem</code> to <code>Scene</code> components. Used for notifications of changes in active <code>Node</code>.
     * </p>
     */
    private Map<TreeItem, Object> sceneComponents;

    /**
     * <p>
     * Creates an instance of <code>SceneOutlineSelectionListener</code>.
     * </p>
     * 
     * @param newSceneComponents A map from <code>TreeItem</code> to <code>Scene</code> components.
     */
    public SceneOutlineSelectionListener(final Map<TreeItem, Object> newSceneComponents)
    {
        sceneComponents = newSceneComponents;
    }

    @Override
    public void widgetDefaultSelected(final SelectionEvent e)
    {
        notify(e);
    }

    @Override
    public void widgetSelected(final SelectionEvent e)
    {
        notify(e);
    }

    /**
     * <p>
     * Responds to a <code>SelectionEvent</code> by notifying the {@link com.se.simplicity.editor.internal.SceneManager SceneManager} of the change in
     * active <code>Node</code>.
     * </p>
     * 
     * @param e The <code>SelectionEvent</code> to respond to.
     */
    protected void notify(final SelectionEvent e)
    {
        if (e.item instanceof TreeItem)
        {
            Object sceneComponent = sceneComponents.get((TreeItem) e.item);

            if (sceneComponent instanceof Node)
            {
                SceneManager.getSceneManager().setActiveNode(((Node) sceneComponent).getID());
            }
        }
    }

}
