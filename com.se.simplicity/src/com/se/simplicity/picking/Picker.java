/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.picking;

import com.se.simplicity.picking.event.PickEvent;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.scene.Scene;

/**
 * <p>
 * Picks {@link com.se.simplicity.scene.Scene Scene}s. The <code>Scene</code> is picked based on a {@link com.se.simplicity.rendering.Camera Camera}
 * and a {@link com.se.simplicity.picking.Pick Pick} that generally represents a subset of the <code>Camera</code>'s frame.
 * </p>
 * 
 * @author Gary Buyn
 */
public interface Picker
{
    /**
     * <p>
     * Picks a {@link com.se.simplicity.scene.Scene Scene} using the given {@link com.se.simplicity.picking.Pick Pick} and basing the
     * <code>Pick</code> on the given {@link com.se.simplicity.rendering.Camera Camera}.
     * </p>
     * 
     * @param scene The <code>Scene</code> to pick.
     * @param camera The <code>Camera</code> to base the pick on.
     * @param pick The <code>Pick</code> to apply to the <code>Scene</code>.
     * 
     * @return An event containing any picked components of the <code>Scene</code>.
     */
    PickEvent pickScene(Scene scene, Camera camera, Pick pick);
}
