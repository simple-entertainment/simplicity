/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.test.ui.views;

import static org.easymock.EasyMock.expect;
import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.replay;
import static org.easymock.classextension.EasyMock.reset;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import org.eclipse.swt.SWT;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Control;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Text;
import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.editor.internal.SceneManager;
import com.se.simplicity.editor.internal.event.SceneChangedEvent;
import com.se.simplicity.editor.internal.event.SceneChangedEventType;
import com.se.simplicity.editor.ui.views.NodeView;
import com.se.simplicity.scene.Scene;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.SceneGraph;
import com.se.simplicity.scenegraph.SimpleNode;
import com.se.simplicity.util.metadata.scenegraph.MetaDataNode;
import com.se.simplicity.vector.TransformationMatrixf;
import com.se.simplicity.vector.TranslationVectorf;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.editor.ui.views.NodeView NodeView}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class NodeViewTest
{
    /**
     * An instance of the class being unit tested.
     */
    private NodeView testObject;

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        testObject = new NodeView(new Shell(), SWT.NONE);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.views.NodeView#setNode(Node) setNode(Node)} with the special condition that the Node is
     * a MetaDataNode.
     * </p>
     */
    @Test
    public void setNodeMetaDataNode()
    {
        // Create dependencies.
        MetaDataNode mockMetaDataNode = createMock(MetaDataNode.class);
        Node mockNode = createMock(Node.class);

        TransformationMatrixf mockTransformation = createMock(TransformationMatrixf.class);
        TranslationVectorf mockTranslation = createMock(TranslationVectorf.class);

        // Dictate correct behaviour.
        expect(mockMetaDataNode.getWrappedNode()).andStubReturn(mockNode);
        expect(mockMetaDataNode.getAttribute("name")).andStubReturn("Test");
        expect(mockMetaDataNode.getID()).andStubReturn(0);
        expect(mockMetaDataNode.isCollidable()).andStubReturn(true);
        expect(mockMetaDataNode.isModifiable()).andStubReturn(true);
        expect(mockMetaDataNode.isVisible()).andStubReturn(true);
        expect(mockMetaDataNode.getTransformation()).andStubReturn(mockTransformation);
        expect(mockTransformation.getXAxisRotation()).andStubReturn(90.0f * (float) Math.PI / 180.0f);
        expect(mockTransformation.getYAxisRotation()).andStubReturn(180.0f * (float) Math.PI / 180.0f);
        expect(mockTransformation.getZAxisRotation()).andStubReturn(270.0f * (float) Math.PI / 180.0f);
        expect(mockTransformation.getTranslation()).andStubReturn(mockTranslation);
        expect(mockTranslation.getX()).andStubReturn(5.0f);
        expect(mockTranslation.getY()).andStubReturn(10.0f);
        expect(mockTranslation.getZ()).andStubReturn(15.0f);
        replay(mockMetaDataNode, mockNode, mockTransformation, mockTranslation);

        // Verify test environment.
        Control[] sections = testObject.getChildren();

        Control[] idWidgets = ((Composite) sections[0]).getChildren();
        assertEquals("", ((Text) idWidgets[3]).getText());

        // Perform test.
        testObject.setNode(mockMetaDataNode);

        // Verify test.
        assertEquals("Test", ((Text) idWidgets[3]).getText());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.views.NodeView#setNode(Node) setNode(Node)}.
     * </p>
     */
    @Test
    public void setNode()
    {
        // Create dependencies.
        Node mockNode = createMock(Node.class);

        TransformationMatrixf mockTransformation = createMock(TransformationMatrixf.class);
        TranslationVectorf mockTranslation = createMock(TranslationVectorf.class);

        // Dictate correct behaviour.
        expect(mockNode.getID()).andStubReturn(0);
        expect(mockNode.isCollidable()).andStubReturn(true);
        expect(mockNode.isModifiable()).andStubReturn(true);
        expect(mockNode.isVisible()).andStubReturn(true);
        expect(mockNode.getTransformation()).andStubReturn(mockTransformation);
        expect(mockTransformation.getXAxisRotation()).andStubReturn(90.0f * (float) Math.PI / 180.0f);
        expect(mockTransformation.getYAxisRotation()).andStubReturn(180.0f * (float) Math.PI / 180.0f);
        expect(mockTransformation.getZAxisRotation()).andStubReturn(270.0f * (float) Math.PI / 180.0f);
        expect(mockTransformation.getTranslation()).andStubReturn(mockTranslation);
        expect(mockTranslation.getX()).andStubReturn(5.0f);
        expect(mockTranslation.getY()).andStubReturn(10.0f);
        expect(mockTranslation.getZ()).andStubReturn(15.0f);
        replay(mockNode, mockTransformation, mockTranslation);

        // Verify test environment.
        Control[] sections = testObject.getChildren();

        Control[] idWidgets = ((Composite) sections[0]).getChildren();
        assertEquals("", ((Text) idWidgets[1]).getText());

        Control[] propertyWidgets = ((Composite) sections[1]).getChildren();
        assertEquals(false, ((Button) propertyWidgets[0]).getSelection());
        assertEquals(false, ((Button) propertyWidgets[1]).getSelection());
        assertEquals(false, ((Button) propertyWidgets[2]).getSelection());

        Control[] translationWidgets = ((Composite) sections[2]).getChildren();
        assertEquals("", ((Text) translationWidgets[1]).getText());
        assertEquals("", ((Text) translationWidgets[3]).getText());
        assertEquals("", ((Text) translationWidgets[5]).getText());

        Control[] rotationWidgets = ((Composite) sections[3]).getChildren();
        assertEquals("", ((Text) rotationWidgets[1]).getText());
        assertEquals("", ((Text) rotationWidgets[3]).getText());
        assertEquals("", ((Text) rotationWidgets[5]).getText());

        // Perform test.
        testObject.setNode(mockNode);

        // Verify test.
        assertEquals("0", ((Text) idWidgets[1]).getText());

        assertEquals(true, ((Button) propertyWidgets[0]).getSelection());
        assertEquals(true, ((Button) propertyWidgets[1]).getSelection());
        assertEquals(true, ((Button) propertyWidgets[2]).getSelection());

        assertEquals("5.0", ((Text) translationWidgets[1]).getText());
        assertEquals("10.0", ((Text) translationWidgets[3]).getText());
        assertEquals("15.0", ((Text) translationWidgets[5]).getText());

        assertEquals("90.0", ((Text) rotationWidgets[1]).getText());
        assertEquals("180.0", ((Text) rotationWidgets[3]).getText());
        assertEquals("270.0", ((Text) rotationWidgets[5]).getText());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.views.NodeView#setNode(Node) setNode(Node)}, specifically the functionality related to
     * the type of the Node.
     * </p>
     */
    @Test
    public void setNodeType()
    {
        // Create dependencies.
        SimpleNode node = new SimpleNode();
        MetaDataNode mockMetaDataNode = createMock(MetaDataNode.class);

        TransformationMatrixf mockTransformation = createMock(TransformationMatrixf.class);
        TranslationVectorf mockTranslation = createMock(TranslationVectorf.class);

        // Dictate correct behaviour.
        expect(mockMetaDataNode.getAttribute("name")).andStubReturn("test");
        expect(mockMetaDataNode.getWrappedNode()).andStubReturn(node);
        expect(mockMetaDataNode.getID()).andStubReturn(0);
        expect(mockMetaDataNode.isCollidable()).andStubReturn(true);
        expect(mockMetaDataNode.isModifiable()).andStubReturn(true);
        expect(mockMetaDataNode.isVisible()).andStubReturn(true);
        expect(mockMetaDataNode.getTransformation()).andStubReturn(mockTransformation);
        expect(mockTransformation.getXAxisRotation()).andStubReturn(90.0f * (float) Math.PI / 180.0f);
        expect(mockTransformation.getYAxisRotation()).andStubReturn(180.0f * (float) Math.PI / 180.0f);
        expect(mockTransformation.getZAxisRotation()).andStubReturn(270.0f * (float) Math.PI / 180.0f);
        expect(mockTransformation.getTranslation()).andStubReturn(mockTranslation);
        expect(mockTranslation.getX()).andStubReturn(5.0f);
        expect(mockTranslation.getY()).andStubReturn(10.0f);
        expect(mockTranslation.getZ()).andStubReturn(15.0f);
        replay(mockMetaDataNode, mockTransformation, mockTranslation);

        // Verify test environment.
        Control[] sections = testObject.getChildren();

        Control[] idWidgets = ((Composite) sections[0]).getChildren();
        assertEquals("", ((Text) idWidgets[3]).getText());

        Control[] reflectiveWidgets = ((Composite) sections[4]).getChildren();
        assertEquals("", ((Text) reflectiveWidgets[1]).getText());

        // Perform test 1.
        testObject.setNode(node);

        // Verify test 1 results.
        assertEquals("SimpleNode0", ((Text) idWidgets[3]).getText());

        assertEquals("com.se.simplicity.scenegraph.SimpleNode", ((Text) reflectiveWidgets[1]).getText());

        // Perform test 2.
        testObject.setNode(mockMetaDataNode);

        // Verify test 2 results.
        assertEquals("com.se.simplicity.scenegraph.SimpleNode", ((Text) reflectiveWidgets[1]).getText());
    }
}
