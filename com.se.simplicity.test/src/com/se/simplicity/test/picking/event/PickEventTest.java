/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.test.picking.event;

import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.expect;
import static org.easymock.classextension.EasyMock.replay;

import static org.junit.Assert.assertEquals;

import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.picking.Hit;
import com.se.simplicity.picking.event.PickEvent;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.picking.event.PickEvent PickEvent}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class PickEventTest
{
    /**
     * An instance of the class being unit tested.
     */
    private PickEvent testObject;

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        testObject = new PickEvent();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.picking.event.PickEvent#getCloseHit() getCloseHit()}.
     * </p>
     */
    @Test
    public void getCloseHit()
    {
        // Create dependencies.
        Hit mockHit0 = createMock(Hit.class);
        Hit mockHit1 = createMock(Hit.class);

        // Dictate correct behaviour.
        expect(mockHit0.getMinimumDistance()).andStubReturn(20);
        expect(mockHit1.getMinimumDistance()).andStubReturn(10);
        replay(mockHit0, mockHit1);

        // Initialise test environment.
        testObject.addHit(mockHit0);
        testObject.addHit(mockHit1);

        // Perform test.
        Hit hit = testObject.getCloseHit();

        // Verify test results.
        assertEquals(mockHit1, hit);
    }
}
