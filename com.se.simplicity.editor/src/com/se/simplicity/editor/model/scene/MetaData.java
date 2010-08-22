/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.model.scene;

import java.util.Enumeration;

/**
 * <p>
 * An object that contains meta data in the form of named attributes.
 * </p>
 * 
 * @author Gary Buyn
 */
public interface MetaData
{
    /**
     * <p>
     * Retrieves the meta data attribute contained in this object with the given name.
     * </p>
     * 
     * @param name The name of the meta data attribute to retrieve.
     * 
     * @return The meta data attribute contained in this object with the given name, or null if one does not exist.
     */
    Object getAttribute(String name);

    /**
     * <p>
     * Retrieves all the names of the meta data attributes contained in this object.
     * </p>
     * 
     * @return All the names of the meta data attributes contained in this object.
     */
    Enumeration<String> getAttributeNames();

    /**
     * <p>
     * Retrieves all the meta data attributes contained in this object.
     * </p>
     * 
     * @return All the meta data attributes contained in this object.
     */
    Enumeration<Object> getAttributes();

    /**
     * <p>
     * Adds the meta data attribute with the given name and value to the meta data attributes contained in this object.
     * </p>
     * 
     * @param name The name of the meta data attribute to add.
     * @param value The meta data attribute to add.
     */
    void setAttribute(String name, Object value);
}
