/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.internal.picking;

import java.nio.IntBuffer;

import com.se.simplicity.jogl.picking.SimpleJOGLPicker;
import com.se.simplicity.picking.Hit;
import com.se.simplicity.picking.event.PickEvent;
import com.se.simplicity.scene.Scene;

/**
 * <p>
 * Picks from a JOGL rendering environment. This implementation ignores the name of the primitive picked and returns
 * {@link com.se.simplicity.picking.event.PickEvent PickEvent}s without primitive data.
 * </p>
 * 
 * @author Gary Buyn
 */
public class WidgetJOGLPicker extends SimpleJOGLPicker
{
    /**
     * <p>
     * Creates an instance of <code>WidgetJOGLPicker</code>.
     * </p>
     */
    public WidgetJOGLPicker()
    {
        super();
    }

    @Override
    protected PickEvent createPickEvent(final Scene scene, final int numberOfHits)
    {
        PickEvent event = new PickEvent();
        IntBuffer selectBuffer = getSelectBuffer();
        int bufferIndex = 0;

        for (int hitIndex = 0; hitIndex < numberOfHits; hitIndex++)
        {
            Hit hit = new Hit();
            int numberOfNames = selectBuffer.get(bufferIndex++);
            hit.setMinimumDistance(selectBuffer.get(bufferIndex++));
            hit.setMaximumDistance(selectBuffer.get(bufferIndex++));

            hit.setNode(scene.getSceneGraph().getNode(selectBuffer.get(bufferIndex)));

            bufferIndex += numberOfNames;
            event.addHit(hit);
        }

        return (event);
    }
}
