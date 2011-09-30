/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.internal.properties;

import org.eclipse.jface.viewers.CellEditor;
import org.eclipse.jface.viewers.CheckboxCellEditor;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.ui.views.properties.PropertyDescriptor;

/**
 * <p>
 * Describes boolean properties.
 * </p>
 * 
 * @author Gary Buyn
 */
public class CheckBoxPropertyDescriptor extends PropertyDescriptor
{
    /**
     * <p>
     * Creates an instance of <code>CheckBoxPropertyDescriptor</code>.
     * </p>
     * 
     * @param id The property id.
     * @param displayName The name to display for the property.
     */
    public CheckBoxPropertyDescriptor(final Object id, final String displayName)
    {
        super(id, displayName);
    }

    @Override
    public CellEditor createPropertyEditor(final Composite parent)
    {
        CellEditor editor = new CheckboxCellEditor(parent);

        if (getValidator() != null)
        {
            editor.setValidator(getValidator());
        }

        return (editor);
    }

}
