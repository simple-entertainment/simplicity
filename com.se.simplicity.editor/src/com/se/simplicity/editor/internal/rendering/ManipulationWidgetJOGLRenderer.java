/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.internal.rendering;

import com.se.simplicity.editor.internal.Widget;
import com.se.simplicity.jogl.rendering.AdaptingJOGLRenderer;
import com.se.simplicity.model.Model;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.Renderer;

/**
 * <p>
 * Renders manipulation {@link com.se.simplicity.editor.internal.Widget Widget} in a JOGL environment.
 * </p>
 * 
 * @author Gary Buyn
 */
public class ManipulationWidgetJOGLRenderer extends AdaptingJOGLRenderer
{
    /**
     * <p>
     * The {@link com.se.simplicity.rendering.Camera Camera} the {@link com.se.simplicity.editor.internal.Widget Widget} is being viewed through.
     * </p>
     */
    private Camera fCamera;

    /**
     * <p>
     * The {@link com.se.simplicity.editor.internal.Widget Widget} that will be rendered.
     * </p>
     */
    private Widget fWidget;

    /**
     * <p>
     * Creates an instance of <code>ManipulationWidgetJOGLRenderer</code>.
     * </p>
     * 
     * @param renderer The wrapped {@link com.se.simplicity.rendering.Renderer Renderer} that will render the
     * {@link com.se.simplicity.editor.internal.Widget Widget}.
     */
    public ManipulationWidgetJOGLRenderer(final Renderer renderer)
    {
        super(renderer);

        fWidget = null;
    }

    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.rendering.Camera Camera} the {@link com.se.simplicity.editor.internal.Widget Widget} is being viewed
     * through.
     * </p>
     * 
     * @return The {@link com.se.simplicity.rendering.Camera Camera} the {@link com.se.simplicity.editor.internal.Widget Widget} is being viewed
     * through.
     */
    public Camera getCamera()
    {
        return (fCamera);
    }

    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.editor.internal.Widget Widget} that will be rendered.
     * </p>
     * 
     * @return The {@link com.se.simplicity.editor.internal.Widget Widget} that will be rendered.
     */
    public Widget getWidget()
    {
        return (fWidget);
    }

    @Override
    public void renderModel(final Model model)
    {
        fWidget.updateView(fCamera, null, model);

        super.renderModel(model);
    }

    /**
     * <p>
     * Sets the {@link com.se.simplicity.rendering.Camera Camera} the {@link com.se.simplicity.editor.internal.Widget Widget} is being viewed through.
     * </p>
     * 
     * @param camera The {@link com.se.simplicity.rendering.Camera Camera} the {@link com.se.simplicity.editor.internal.Widget Widget} is being viewed
     * through.
     */
    public void setCamera(final Camera camera)
    {
        fCamera = camera;
    }

    /**
     * <p>
     * Sets the {@link com.se.simplicity.editor.internal.Widget Widget} that will be rendered.
     * </p>
     * 
     * @param widget The {@link com.se.simplicity.editor.internal.Widget Widget} that will be rendered.
     */
    public void setWidget(final Widget widget)
    {
        fWidget = widget;
    }
}
