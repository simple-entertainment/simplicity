/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.ui.views;

import org.eclipse.swt.SWT;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Text;
import org.eclipse.ui.part.ViewPart;

/**
 * <p>
 * An eclipse view that displays details for the currently active <code>Node</code> (if there is one).
 * </p>
 * 
 * @author Gary Buyn
 */
public class SceneComponentDetailView extends ViewPart
{
    @Override
    public void createPartControl(final Composite parent)
    {
        Text textX = new Text(parent, SWT.NONE);
        textX.setText("X");

        Text textY = new Text(parent, SWT.NONE);
        textY.setText("X");

        Text textZ = new Text(parent, SWT.NONE);
        textZ.setText("X");
    }

    @Override
    public void setFocus()
    {}
}
