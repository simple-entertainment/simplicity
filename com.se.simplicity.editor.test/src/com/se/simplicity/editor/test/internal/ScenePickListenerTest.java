/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.test.internal;

import static org.easymock.EasyMock.expect;
import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.replay;
import static org.easymock.classextension.EasyMock.verify;

import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.editor.internal.ContentProvider;
import com.se.simplicity.editor.internal.SceneManager;
import com.se.simplicity.editor.internal.ScenePickListener;
import com.se.simplicity.picking.Hit;
import com.se.simplicity.picking.event.PickEvent;
import com.se.simplicity.scenegraph.Node;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.editor.internal.ScenePickListener VisualScenePickListener}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class ScenePickListenerTest
{
    /**
     * An instance of the class being unit tested.
     */
    private ScenePickListener testObject;

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        SceneManager.getSceneManager().reset();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.ScenePickListener#scenePicked(PickEvent) scenePicked(PickEvent)}.
     * </p>
     */
    @Test
    public void scenePicked()
    {
        // Create dependencies.
        ContentProvider mockContentProvider = createMock(ContentProvider.class);

        PickEvent mockEvent = createMock(PickEvent.class);
        Hit mockHit = createMock(Hit.class);

        Node mockNode = createMock(Node.class);

        // Dictate correct behaviour.
        expect(mockEvent.getHitCount()).andStubReturn(1);
        expect(mockEvent.getCloseHit()).andStubReturn(mockHit);
        expect(mockHit.getNode()).andStubReturn(mockNode);
        replay(mockEvent, mockHit);

        // Initialise test environment.
        testObject = new ScenePickListener(mockContentProvider);

        // Dictate expected results.
        mockContentProvider.setSelectedSceneComponent(mockNode);
        replay(mockContentProvider);

        // Perform test.
        testObject.scenePicked(mockEvent);

        // Verify test results.
        verify(mockContentProvider);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.ScenePickListener#scenePicked(PickEvent) scenePicked(PickEvent)} with the special
     * condition that no hits were made.
     * </p>
     */
    @Test
    public void scenePickedNoHits()
    {
        // Create dependencies.
        ContentProvider mockContentProvider = createMock(ContentProvider.class);

        PickEvent mockEvent = createMock(PickEvent.class);

        // Dictate correct behaviour.
        expect(mockEvent.getHitCount()).andStubReturn(0);
        replay(mockEvent);

        // Initialise test environment.
        testObject = new ScenePickListener(mockContentProvider);

        // Dictate expected results.
        mockContentProvider.setSelectedSceneComponent(null);
        replay(mockContentProvider);

        // Perform test.
        testObject.scenePicked(mockEvent);

        // Verify test results.
        verify(mockContentProvider);
    }
}