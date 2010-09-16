/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.util.test.model;

import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.expect;
import static org.easymock.classextension.EasyMock.replay;
import static org.junit.Assert.assertEquals;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;

import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;

import org.junit.Test;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

import com.se.simplicity.model.ArrayVG;
import com.se.simplicity.model.Model;
import com.se.simplicity.scene.Scene;
import com.se.simplicity.util.model.ModelFactory;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.util.scene.ModelFactory ModelFactory}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class ModelFactoryTest
{
    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.util.model.ModelFactory#loadFromSource(InputStream) loadFromSource(InputStream)} with the special
     * condition that the source file contains a model definition with no class specified.
     * 
     * @throws FileNotFoundException Thrown if source file is not found.
     */
    @Test
    public void loadFromSourceModelNoClass() throws FileNotFoundException
    {
        try
        {
            ModelFactory.loadFromSource(new FileInputStream("src/com/se/simplicity/util/test/model/triangleNoClass.xml"));
        }
        catch (IllegalArgumentException e)
        {
            assertEquals("Invalid Model definition: Does not specify a class.", e.getMessage());
        }
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.util.model.ModelFactory#loadFromSource(InputStream) loadFromSource(InputStream)} with the special
     * condition that the model is an ArrayVG.
     * </p>
     * 
     * @throws FileNotFoundException Thrown if source file is not found.
     */
    @Test
    public void loadFromSourceArrayVG() throws FileNotFoundException
    {
        // Perform test.
        Model model = ModelFactory.loadFromSource(new FileInputStream("src/com/se/simplicity/util/test/model/triangle.xml"));

        // Verify test results.
        assertEquals(ArrayVG.class, model.getClass());

        float[] colours = ((ArrayVG) model).getColours();
        assertEquals(1.0f, colours[0], 0.0f);
        assertEquals(0.0f, colours[1], 0.0f);
        assertEquals(0.0f, colours[2], 0.0f);
        assertEquals(0.0f, colours[3], 0.0f);
        assertEquals(1.0f, colours[4], 0.0f);
        assertEquals(0.0f, colours[5], 0.0f);
        assertEquals(0.0f, colours[6], 0.0f);
        assertEquals(0.0f, colours[7], 0.0f);
        assertEquals(1.0f, colours[8], 0.0f);

        float[] normals = ((ArrayVG) model).getNormals();
        assertEquals(0.0f, normals[0], 0.0f);
        assertEquals(0.0f, normals[1], 0.0f);
        assertEquals(1.0f, normals[2], 0.0f);
        assertEquals(0.0f, normals[3], 0.0f);
        assertEquals(0.0f, normals[4], 0.0f);
        assertEquals(1.0f, normals[5], 0.0f);
        assertEquals(0.0f, normals[6], 0.0f);
        assertEquals(0.0f, normals[7], 0.0f);
        assertEquals(1.0f, normals[8], 0.0f);

        float[] vertices = ((ArrayVG) model).getVertices();
        assertEquals(0.0f, vertices[0], 0.0f);
        assertEquals(1.0f, vertices[1], 0.0f);
        assertEquals(0.0f, vertices[2], 0.0f);
        assertEquals(-1.0f, vertices[3], 0.0f);
        assertEquals(-1.0f, vertices[4], 0.0f);
        assertEquals(0.0f, vertices[5], 0.0f);
        assertEquals(1.0f, vertices[6], 0.0f);
        assertEquals(-1.0f, vertices[7], 0.0f);
        assertEquals(0.0f, vertices[8], 0.0f);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.util.model.ModelFactory#writeToSource(Model, Document) writeToSource(Model, Document)} with the
     * special condition that the model is an ArrayVG.
     * 
     * @throws ParserConfigurationException Thrown if the written source cannot be parsed.
     * @throws IOException Thrown if there is an error with the piped streams.
     * @throws SAXException Thrown if the written source cannot be parsed.
     */
    @Test
    public void writeToSourceArrayVG() throws SAXException, IOException, ParserConfigurationException
    {
        // Create dependencies.
        ArrayVG model = new ArrayVG();
        float[] colours = new float[] {1, 0, 0, 0, 1, 0, 0, 0, 1};
        float[] normals = new float[] {0, 0, 1, 0, 0, 1, 0, 0, 1};
        float[] vertices = new float[] {0, 1, 0, -1, -1, 0, 1, -1, 0};
        model.setColours(colours);
        model.setNormals(normals);
        model.setVertices(vertices);

        // Perform test.
        Document source = DocumentBuilderFactory.newInstance().newDocumentBuilder().newDocument();
        ModelFactory.writeToSource(model, source);

        // Verify test results.
        NodeList modelElements = source.getElementsByTagName("model");
        assertEquals(1, modelElements.getLength(), 0);

        Element model0Element = (Element) modelElements.item(0);
        assertEquals("com.se.simplicity.model.ArrayVG", model0Element.getAttribute("class"));

        NodeList vertexElements = model0Element.getElementsByTagName("vertex");
        assertEquals(3, vertexElements.getLength(), 0);

        Element model0Vertex0Element = (Element) vertexElements.item(0);
        assertEquals("1.0, 0.0, 0.0", model0Vertex0Element.getAttribute("colour"));
        assertEquals("0.0, 0.0, 1.0", model0Vertex0Element.getAttribute("normal"));
        assertEquals("0.0, 1.0, 0.0", model0Vertex0Element.getAttribute("vertex"));
        Element model0Vertex1Element = (Element) vertexElements.item(1);
        assertEquals("0.0, 1.0, 0.0", model0Vertex1Element.getAttribute("colour"));
        assertEquals("0.0, 0.0, 1.0", model0Vertex1Element.getAttribute("normal"));
        assertEquals("-1.0, -1.0, 0.0", model0Vertex1Element.getAttribute("vertex"));
        Element model0Vertex2Element = (Element) vertexElements.item(2);
        assertEquals("0.0, 0.0, 1.0", model0Vertex2Element.getAttribute("colour"));
        assertEquals("0.0, 0.0, 1.0", model0Vertex2Element.getAttribute("normal"));
        assertEquals("1.0, -1.0, 0.0", model0Vertex2Element.getAttribute("vertex"));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.util.scene.SceneFactory#writeToSource(Scene) writeToSource(Scene)}, specifically the
     * functionality that creates the root tags of the source.
     * 
     * @throws ParserConfigurationException Thrown if the written source cannot be parsed.
     * @throws IOException Thrown if there is an error with the piped streams.
     * @throws SAXException Thrown if the written source cannot be parsed.
     */
    @Test
    public void writeToSourceRootTag() throws SAXException, IOException, ParserConfigurationException
    {
        // Create dependencies
        ArrayVG mockModel = createMock(ArrayVG.class);

        // Dictate correct behaviour.
        expect(mockModel.getColours()).andStubReturn(new float[0]);
        expect(mockModel.getNormals()).andStubReturn(new float[0]);
        expect(mockModel.getVertices()).andStubReturn(new float[0]);
        replay(mockModel);

        // Perform test.
        Document source = DocumentBuilderFactory.newInstance().newDocumentBuilder().newDocument();
        ModelFactory.writeToSource(mockModel, source);

        // Verify test results.
        assertEquals(1, source.getElementsByTagName("simplicity").getLength(), 0);
    }
}
