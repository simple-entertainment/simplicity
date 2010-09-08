/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.internal;

import com.se.simplicity.picking.event.PickEvent;
import com.se.simplicity.picking.event.PickListener;

/**
 * <p>
 * Listens for pick events on a 3D canvas and sets the picked {@link com.se.simplicity.scenegraph.Node Node} to be the currently selected scene
 * component.
 * </p>
 * 
 * @author Gary Buyn
 */
public class ScenePickListener implements PickListener
{
    /**
     * <p>
     * The {@link com.se.simplicity.rendering.editor.internal.ContentProvider ContentProvider} to set the currently selected scene component for.
     * </p>
     */
    private ContentProvider fContentProvider;

    /**
     * <p>
     * Creates an instance of <code>ScenePickListener</code>.
     * </p>
     * 
     * @param contentProvider The {@link com.se.simplicity.rendering.editor.internal.ContentProvider ContentProvider} to set the currently selected
     * scene component for.
     */
    public ScenePickListener(final ContentProvider contentProvider)
    {
        fContentProvider = contentProvider;
    }

    @Override
    public void scenePicked(final PickEvent event)
    {
        if (event.getHitCount() > 0)
        {
            fContentProvider.setSelectedSceneComponent(event.getCloseHit().getNode());
        }
        else
        {
            fContentProvider.setSelectedSceneComponent(null);
        }
    }
}
