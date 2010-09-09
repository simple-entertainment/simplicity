/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.jogl.model.shape;

import com.se.simplicity.model.shape.Sphere;

/**
 * <p>
 * A {@link com.se.simplicity.model.shape.Sphere Sphere} implemented by the OpenGL Utilities.
 * </p>
 * 
 * @author Gary Buyn
 */
public class GLUSphere extends Sphere implements GLUShape
{
    /**
     * <p>
     * The default number of slices this <code>GLUSphere</code> is comprised of.
     * </p>
     */
    private static final int DEFALUT_SLICES = 10;

    /**
     * <p>
     * The default number of stacks this <code>GLUSphere</code> is comprised of.
     * </p>
     */
    private static final int DEFALUT_STACKS = 10;

    /**
     * <p>
     * The serialisation version of this class.
     * </p>
     */
    private static final long serialVersionUID = 1L;

    /**
     * <p>
     * The number of slices this <code>GLUSphere</code> is comprised of.
     * </p>
     */
    private int fSlices;

    /**
     * <p>
     * The number of stacks this <code>GLUSphere</code> is comprised of.
     * </p>
     */
    private int fStacks;

    /**
     * <p>
     * Creates an instance of <code>GLUSphere</code>.
     * </p>
     */
    public GLUSphere()
    {
        fSlices = DEFALUT_SLICES;
        fStacks = DEFALUT_STACKS;
    }

    @Override
    public int getSlices()
    {
        return (fSlices);
    }

    @Override
    public int getStacks()
    {
        return (fStacks);
    }

    @Override
    public void setSlices(final int slices)
    {
        fSlices = slices;
    }

    @Override
    public void setStacks(final int stacks)
    {
        fStacks = stacks;
    }
}
