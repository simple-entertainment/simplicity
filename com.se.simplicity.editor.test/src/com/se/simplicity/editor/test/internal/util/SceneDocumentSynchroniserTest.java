/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.test.internal.util;

import static org.easymock.EasyMock.expect;
import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.replay;
import static org.easymock.classextension.EasyMock.verify;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import java.util.ArrayList;

import org.eclipse.jface.text.BadLocationException;
import org.eclipse.wst.sse.core.internal.provisional.text.IStructuredDocument;
import org.eclipse.wst.sse.core.internal.provisional.text.IStructuredDocumentRegion;
import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.editor.internal.util.SceneDocumentSynchroniser;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.Light;
import com.se.simplicity.scene.Scene;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.SceneGraph;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.editor.internal.util.SceneDocumentSynchroniser SceneDocumentSynchroniser}.
 * </p>
 * 
 * @author Gary Buyn
 */
@SuppressWarnings("restriction")
public class SceneDocumentSynchroniserTest
{
    /**
     * An instance of the class being unit tested.
     */
    private SceneDocumentSynchroniser testObject;

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        testObject = new SceneDocumentSynchroniser();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.util.SceneDocumentSynchroniser#sameTag(String, String) sameTag(String, String)}.
     * </p>
     */
    @Test
    public void sameTag()
    {
        assertTrue(testObject.sameTag("<tagA>", "<tagA>"));
        assertFalse(testObject.sameTag("<tagA>", "<tagB>"));
        assertTrue(testObject.sameTag("<tagA>", "<tagA attribute=\"value\">"));
        assertFalse(testObject.sameTag("<tagA>", "</tagA>"));
        assertFalse(testObject.sameTag("<tagA>", "<?tagA?>"));

        assertTrue(testObject.sameTag("<tagA attribute=\"value\">", "<tagA>"));
        assertFalse(testObject.sameTag("<tagA attribute=\"value\">", "<tagB>"));
        assertTrue(testObject.sameTag("<tagA attribute=\"value\">", "<tagA attribute=\"value\">"));
        assertTrue(testObject.sameTag("<tagA attribute=\"value\">", "<tagA attribute=\"value2\">"));
        assertTrue(testObject.sameTag("<tagA attribute=\"value\">", "<tagA attribute=\"value\" attribute2=\"value2\">"));
        assertFalse(testObject.sameTag("<tagA attribute=\"value\">", "</tagA>"));
        assertFalse(testObject.sameTag("<tagA attribute=\"value\">", "<?tagA?>"));

        assertFalse(testObject.sameTag("</tagA>", "<tagA>"));
        assertFalse(testObject.sameTag("</tagA>", "</tagB>"));
        assertFalse(testObject.sameTag("</tagA>", "<tagA attribute=\"value\">"));
        assertTrue(testObject.sameTag("</tagA>", "</tagA>"));
        assertFalse(testObject.sameTag("</tagA>", "<?tagA?>"));

        assertFalse(testObject.sameTag("<?tagA?>", "<tagA>"));
        assertFalse(testObject.sameTag("<?tagA?>", "</tagB>"));
        assertFalse(testObject.sameTag("<?tagA?>", "<tagA attribute=\"value\">"));
        assertFalse(testObject.sameTag("<?tagA?>", "</tagA>"));
        assertTrue(testObject.sameTag("<?tagA?>", "<?tagA?>"));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.util.SceneDocumentSynchroniser#synchroniseToDocument(Scene, IStructuredDocument)
     * synchroniseToDocument(Scene, IStructuredDocument)} with the special condition that an new tag has been added.
     * </p>
     * 
     * @throws BadLocationException Thrown if a text replace is attempted in the document at an invalid location.
     */
    @Test
    public void synchroniseToDocumentAddTag() throws BadLocationException
    {
        // Create dependencies.
        Scene mockScene = createMock(Scene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);

        IStructuredDocument mockDocument = createMock(IStructuredDocument.class);
        IStructuredDocumentRegion mockRegion0 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion1 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion2 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion3 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion4 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion5 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion6 = createMock(IStructuredDocumentRegion.class);

        IStructuredDocumentRegion[] regions = new IStructuredDocumentRegion[14];
        regions[0] = mockRegion0;
        regions[2] = mockRegion1;
        regions[4] = mockRegion2;
        regions[6] = mockRegion3;
        regions[8] = mockRegion4;
        regions[10] = mockRegion5;
        regions[12] = mockRegion6;

        // Dictate correct behaviour.
        expect(mockScene.getCameras()).andStubReturn(new ArrayList<Camera>());
        expect(mockScene.getLights()).andStubReturn(new ArrayList<Light>());
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getSubgraphRoots()).andStubReturn(new ArrayList<Node>());
        expect(mockDocument.getStructuredDocumentRegions()).andStubReturn(regions);
        replay(mockScene, mockSceneGraph);

        // Prepare Document contents.
        expect(mockRegion0.getText()).andStubReturn("<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>");
        expect(mockRegion1.getText()).andStubReturn("<simplicity>");
        expect(mockRegion2.getText()).andStubReturn("<scene>");
        expect(mockRegion3.getText()).andStubReturn("<sceneGraph>");
        expect(mockRegion4.getText()).andStubReturn("</sceneGraph>");
        expect(mockRegion4.getStart()).andStubReturn(85);
        expect(mockRegion5.getText()).andStubReturn("</scene>");
        expect(mockRegion6.getText()).andStubReturn("</simplicity>");
        replay(mockRegion0, mockRegion1, mockRegion2, mockRegion3, mockRegion4, mockRegion5, mockRegion6);

        // Dictate expected results.
        mockDocument.replace(85, 0, "<node name=\"Internally Managed Node(s)\"/>\n");
        replay(mockDocument);

        // Perform test.
        testObject.synchroniseToDocument(mockScene, mockDocument);

        // Verify test results.
        verify(mockDocument);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.util.SceneDocumentSynchroniser#synchroniseToDocument(Scene, IStructuredDocument)
     * synchroniseToDocument(Scene, IStructuredDocument)} with the special condition that an new tag has been added at the end to the end.
     * </p>
     * 
     * @throws BadLocationException Thrown if a text replace is attempted in the document at an invalid location.
     */
    @Test
    public void synchroniseToDocumentAddTagAtEnd() throws BadLocationException
    {
        // Create dependencies.
        Scene mockScene = createMock(Scene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);

        IStructuredDocument mockDocument = createMock(IStructuredDocument.class);
        IStructuredDocumentRegion mockRegion0 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion1 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion2 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion3 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion4 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion5 = createMock(IStructuredDocumentRegion.class);

        IStructuredDocumentRegion[] regions = new IStructuredDocumentRegion[12];
        regions[0] = mockRegion0;
        regions[2] = mockRegion1;
        regions[4] = mockRegion2;
        regions[6] = mockRegion3;
        regions[8] = mockRegion4;
        regions[10] = mockRegion5;

        // Dictate correct behaviour.
        expect(mockScene.getCameras()).andStubReturn(new ArrayList<Camera>());
        expect(mockScene.getLights()).andStubReturn(new ArrayList<Light>());
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getSubgraphRoots()).andStubReturn(new ArrayList<Node>());
        expect(mockDocument.getStructuredDocumentRegions()).andStubReturn(regions);
        replay(mockScene, mockSceneGraph);

        // Prepare Document contents.
        expect(mockRegion0.getText()).andStubReturn("<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>");
        expect(mockRegion1.getText()).andStubReturn("<scene>");
        expect(mockRegion1.getStart()).andStubReturn(54);
        expect(mockRegion2.getText()).andStubReturn("<sceneGraph>");
        expect(mockRegion3.getText()).andStubReturn("<node name=\"Internally Managed Node(s)\"/>");
        expect(mockRegion4.getText()).andStubReturn("</sceneGraph>");
        expect(mockRegion5.getText()).andStubReturn("</scene>");
        replay(mockRegion0, mockRegion1, mockRegion2, mockRegion3, mockRegion4, mockRegion5);

        // Dictate expected results.
        mockDocument.replace(54, 0, "<simplicity>\n");
        expect(mockDocument.getLength()).andReturn(147);
        mockDocument.replace(147, 0, "</simplicity>");
        replay(mockDocument);

        // Perform test.
        testObject.synchroniseToDocument(mockScene, mockDocument);

        // Verify test results.
        verify(mockDocument);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.util.SceneDocumentSynchroniser#synchroniseToDocument(Scene, IStructuredDocument)
     * synchroniseToDocument(Scene, IStructuredDocument)} with the special condition that both the scene content and the document content are equal.
     * </p>
     */
    @Test
    public void synchroniseToDocumentEqual()
    {
        // Create dependencies.
        Scene mockScene = createMock(Scene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);

        IStructuredDocument mockDocument = createMock(IStructuredDocument.class);
        IStructuredDocumentRegion mockRegion0 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion1 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion2 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion3 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion4 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion5 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion6 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion7 = createMock(IStructuredDocumentRegion.class);

        IStructuredDocumentRegion[] regions = new IStructuredDocumentRegion[16];
        regions[0] = mockRegion0;
        regions[2] = mockRegion1;
        regions[4] = mockRegion2;
        regions[6] = mockRegion3;
        regions[8] = mockRegion4;
        regions[10] = mockRegion5;
        regions[12] = mockRegion6;
        regions[14] = mockRegion7;

        // Dictate correct behaviour.
        expect(mockScene.getCameras()).andStubReturn(new ArrayList<Camera>());
        expect(mockScene.getLights()).andStubReturn(new ArrayList<Light>());
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getSubgraphRoots()).andStubReturn(new ArrayList<Node>());
        expect(mockDocument.getStructuredDocumentRegions()).andStubReturn(regions);
        replay(mockScene, mockSceneGraph, mockDocument);

        // Prepare Document contents.
        expect(mockRegion0.getText()).andStubReturn("<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>");
        expect(mockRegion1.getText()).andStubReturn("<simplicity>");
        expect(mockRegion2.getText()).andStubReturn("<scene>");
        expect(mockRegion3.getText()).andStubReturn("<sceneGraph>");
        expect(mockRegion4.getText()).andStubReturn("<node name=\"Internally Managed Node(s)\"/>");
        expect(mockRegion5.getText()).andStubReturn("</sceneGraph>");
        expect(mockRegion6.getText()).andStubReturn("</scene>");
        expect(mockRegion7.getText()).andStubReturn("</simplicity>");
        replay(mockRegion0, mockRegion1, mockRegion2, mockRegion3, mockRegion4, mockRegion5, mockRegion6, mockRegion7);

        // Perform test.
        testObject.synchroniseToDocument(mockScene, mockDocument);

        // Verify test results.
        verify(mockDocument); // Verify nothing was synchronised to the Document.
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.util.SceneDocumentSynchroniser#synchroniseToDocument(Scene, IStructuredDocument)
     * synchroniseToDocument(Scene, IStructuredDocument)} with the special condition that an existing tag has been modified.
     * </p>
     * 
     * @throws BadLocationException Thrown if a text replace is attempted in the document at an invalid location.
     */
    @Test
    public void synchroniseToDocumentModifyTag() throws BadLocationException
    {
        // Create dependencies.
        Scene mockScene = createMock(Scene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);

        IStructuredDocument mockDocument = createMock(IStructuredDocument.class);
        IStructuredDocumentRegion mockRegion0 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion1 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion2 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion3 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion4 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion5 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion6 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion7 = createMock(IStructuredDocumentRegion.class);

        IStructuredDocumentRegion[] regions = new IStructuredDocumentRegion[16];
        regions[0] = mockRegion0;
        regions[2] = mockRegion1;
        regions[4] = mockRegion2;
        regions[6] = mockRegion3;
        regions[8] = mockRegion4;
        regions[10] = mockRegion5;
        regions[12] = mockRegion6;
        regions[14] = mockRegion7;

        // Dictate correct behaviour.
        expect(mockScene.getCameras()).andStubReturn(new ArrayList<Camera>());
        expect(mockScene.getLights()).andStubReturn(new ArrayList<Light>());
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getSubgraphRoots()).andStubReturn(new ArrayList<Node>());
        expect(mockDocument.getStructuredDocumentRegions()).andStubReturn(regions);
        replay(mockScene, mockSceneGraph);

        // Prepare Document contents.
        expect(mockRegion0.getText()).andStubReturn("<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>");
        expect(mockRegion1.getText()).andStubReturn("<simplicity>");
        expect(mockRegion2.getText()).andStubReturn("<scene attribute=\"value\">"); // Not equal to the corresponding tag from the Scene.
        expect(mockRegion2.getStart()).andStubReturn(66);
        expect(mockRegion2.getLength()).andStubReturn(25);
        expect(mockRegion3.getText()).andStubReturn("<sceneGraph>");
        expect(mockRegion4.getText()).andStubReturn("<node name=\"Internally Managed Node(s)\"/>");
        expect(mockRegion5.getText()).andStubReturn("</sceneGraph>");
        expect(mockRegion6.getText()).andStubReturn("</scene>");
        expect(mockRegion7.getText()).andStubReturn("</simplicity>");
        replay(mockRegion0, mockRegion1, mockRegion2, mockRegion3, mockRegion4, mockRegion5, mockRegion6, mockRegion7);

        // Dictate expected results.
        mockDocument.replace(66, 25, "<scene>");
        replay(mockDocument);

        // Perform test.
        testObject.synchroniseToDocument(mockScene, mockDocument);

        // Verify test results.
        verify(mockDocument);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.util.SceneDocumentSynchroniser#synchroniseToDocument(Scene, IStructuredDocument)
     * synchroniseToDocument(Scene, IStructuredDocument)} with the special condition that an existing tag has been removed.
     * </p>
     * 
     * @throws BadLocationException Thrown if a text replace is attempted in the document at an invalid location.
     */
    @Test
    public void synchroniseToDocumentRemoveTag() throws BadLocationException
    {
        // Create dependencies.
        Scene mockScene = createMock(Scene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);

        IStructuredDocument mockDocument = createMock(IStructuredDocument.class);
        IStructuredDocumentRegion mockRegion0 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion1 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion2 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion3 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion4 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion5 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion6 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion7 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion8 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion9 = createMock(IStructuredDocumentRegion.class);

        IStructuredDocumentRegion[] regions = new IStructuredDocumentRegion[20];
        regions[0] = mockRegion0;
        regions[2] = mockRegion1;
        regions[4] = mockRegion2;
        regions[6] = mockRegion3;
        regions[8] = mockRegion4;
        regions[10] = mockRegion5;
        regions[12] = mockRegion6;
        regions[14] = mockRegion7;
        regions[16] = mockRegion8;
        regions[18] = mockRegion9;

        // Dictate correct behaviour.
        expect(mockScene.getCameras()).andStubReturn(new ArrayList<Camera>());
        expect(mockScene.getLights()).andStubReturn(new ArrayList<Light>());
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getSubgraphRoots()).andStubReturn(new ArrayList<Node>());
        expect(mockDocument.getStructuredDocumentRegions()).andStubReturn(regions);
        replay(mockScene, mockSceneGraph);

        // Prepare Document contents.
        expect(mockRegion0.getText()).andStubReturn("<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>");
        expect(mockRegion1.getText()).andStubReturn("<simplicity>");
        expect(mockRegion2.getText()).andStubReturn("<scene>");
        expect(mockRegion3.getText()).andStubReturn("<sceneGraph>");
        expect(mockRegion4.getText()).andStubReturn("<node name=\"Internally Managed Node(s)\">");
        expect(mockRegion4.getStart()).andStubReturn(85);
        expect(mockRegion4.getLength()).andStubReturn(40);
        expect(mockRegion5.getText()).andStubReturn("<node/>");
        expect(mockRegion5.getStart()).andStubReturn(125);
        expect(mockRegion5.getLength()).andStubReturn(7);
        expect(mockRegion6.getText()).andStubReturn("</node>");
        expect(mockRegion6.getStart()).andStubReturn(131);
        expect(mockRegion6.getLength()).andStubReturn(7);
        expect(mockRegion7.getText()).andStubReturn("</sceneGraph>");
        expect(mockRegion8.getText()).andStubReturn("</scene>");
        expect(mockRegion9.getText()).andStubReturn("</simplicity>");
        replay(mockRegion0, mockRegion1, mockRegion2, mockRegion3, mockRegion4, mockRegion5, mockRegion6, mockRegion7, mockRegion8, mockRegion9);

        // Dictate expected results.
        mockDocument.replace(85, 40, "<node name=\"Internally Managed Node(s)\"/>");
        mockDocument.replace(125, 8, "");
        mockDocument.replace(131, 8, "");
        replay(mockDocument);

        // Perform test.
        testObject.synchroniseToDocument(mockScene, mockDocument);

        // Verify test results.
        verify(mockDocument);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.util.SceneDocumentSynchroniser#synchroniseToDocument(Scene, IStructuredDocument)
     * synchroniseToDocument(Scene, IStructuredDocument)} with the special condition that an existing tag has been removed at the end.
     * </p>
     * 
     * @throws BadLocationException Thrown if a text replace is attempted in the document at an invalid location.
     */
    @Test
    public void synchroniseToDocumentRemoveTagAtEnd() throws BadLocationException
    {
        // Create dependencies.
        Scene mockScene = createMock(Scene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);

        IStructuredDocument mockDocument = createMock(IStructuredDocument.class);
        IStructuredDocumentRegion mockRegion0 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion1 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion2 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion3 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion4 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion5 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion6 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion7 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion8 = createMock(IStructuredDocumentRegion.class);
        IStructuredDocumentRegion mockRegion9 = createMock(IStructuredDocumentRegion.class);

        IStructuredDocumentRegion[] regions = new IStructuredDocumentRegion[20];
        regions[0] = mockRegion0;
        regions[2] = mockRegion1;
        regions[4] = mockRegion2;
        regions[6] = mockRegion3;
        regions[8] = mockRegion4;
        regions[10] = mockRegion5;
        regions[12] = mockRegion6;
        regions[14] = mockRegion7;
        regions[16] = mockRegion8;
        regions[18] = mockRegion9;

        // Dictate correct behaviour.
        expect(mockScene.getCameras()).andStubReturn(new ArrayList<Camera>());
        expect(mockScene.getLights()).andStubReturn(new ArrayList<Light>());
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getSubgraphRoots()).andStubReturn(new ArrayList<Node>());
        expect(mockDocument.getStructuredDocumentRegions()).andStubReturn(regions);
        replay(mockScene, mockSceneGraph);

        // Prepare Document contents.
        expect(mockRegion0.getText()).andStubReturn("<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>");
        expect(mockRegion1.getText()).andStubReturn("<blah>");
        expect(mockRegion1.getStart()).andStubReturn(54);
        expect(mockRegion1.getLength()).andStubReturn(6);
        expect(mockRegion2.getText()).andStubReturn("<simplicity>");
        expect(mockRegion3.getText()).andStubReturn("<scene>");
        expect(mockRegion4.getText()).andStubReturn("<sceneGraph>");
        expect(mockRegion5.getText()).andStubReturn("<node name=\"Internally Managed Node(s)\"/>");
        expect(mockRegion6.getText()).andStubReturn("</sceneGraph>");
        expect(mockRegion7.getText()).andStubReturn("</scene>");
        expect(mockRegion8.getText()).andStubReturn("</simplicity>");
        expect(mockRegion9.getText()).andStubReturn("</blah>");
        expect(mockRegion9.getStart()).andStubReturn(147);
        expect(mockRegion9.getLength()).andStubReturn(7);

        replay(mockRegion0, mockRegion1, mockRegion2, mockRegion3, mockRegion4, mockRegion5, mockRegion6, mockRegion7, mockRegion8, mockRegion9);

        // Dictate expected results.
        mockDocument.replace(54, 7, "");
        expect(mockDocument.getLength()).andReturn(154);
        mockDocument.replace(147, 7, "");
        replay(mockDocument);

        // Perform test.
        testObject.synchroniseToDocument(mockScene, mockDocument);

        // Verify test results.
        verify(mockDocument);
    }
}
