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
import com.se.simplicity.scenegraph.model.ModelNode;

/**
 * <p>
 * Listens for pick events on a 3D canvas and sets the picked {@link com.se.simplicity.scenegraph.Node Node} to be the currently selected
 * <code>Node</code> of the {@link com.se.simplicity.editor.internal.Widget Widget} currently being used to manipulate
 * {@link com.se.simplicity.model.Model Model}s.
 * </p>
 * 
 * @author Gary Buyn
 */
public class WidgetPickListener implements PickListener
{
    /**
     * <p>
     * The {@link com.se.simplicity.rendering.editor.internal.ContentProvider ContentProvider} containing the
     * {@link com.se.simplicity.editor.internal.Widget Widget}.
     * </p>
     */
    private ContentProvider fContentProvider;

    /**
     * <p>
     * Creates an instance of <code>WidgetPickListener</code>.
     * </p>
     * 
     * @param contentProvider The {@link com.se.simplicity.rendering.editor.internal.ContentProvider ContentProvider} containing the
     * {@link com.se.simplicity.editor.internal.Widget Widget}.
     */
    public WidgetPickListener(final ContentProvider contentProvider)
    {
        fContentProvider = contentProvider;
    }

    @Override
    public void scenePicked(final PickEvent event)
    {
        if (event.getHitCount() > 0)
        {
            fContentProvider.getCurrentWidget().setSelectedWidgetNode((ModelNode) event.getCloseHit().getNode());
        }
    }
}
