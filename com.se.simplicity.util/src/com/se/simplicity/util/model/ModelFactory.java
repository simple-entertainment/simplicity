/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.util.model;

import static com.se.simplicity.model.ModelConstants.ITEMS_IN_CNV;
import static com.se.simplicity.model.ModelConstants.VERTICES_IN_A_FACE;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.util.ArrayList;

import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerException;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;

import org.apache.log4j.Logger;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.NodeList;

import com.se.simplicity.model.ArrayVG;
import com.se.simplicity.model.Model;
import com.se.simplicity.model.ModelConstants;
import com.se.simplicity.util.scene.SceneFactory;

/**
 * <p>
 * Creates {@link com.se.simplicity.model.Model Model}s from various standard model file formats.
 * </p>
 * 
 * @author Gary Buyn
 */
public final class ModelFactory
{
    /**
     * <p>
     * Creates a <code>ArrayVG</code> from a serialised source representation.
     * </p>
     * 
     * @param arrayVGElement The serialised source representation of the <code>ArrayVG</code>.
     * 
     * @return The instance of a <code>ArrayVG</code> created from a serialised source representation.
     */
    private static ArrayVG createArrayVGFromSource(final Element arrayVGElement)
    {
        ArrayVG arrayVG = null;
        try
        {
            arrayVG = (ArrayVG) Class.forName(arrayVGElement.getAttribute("class")).newInstance();
        }
        catch (Exception e)
        {
            throw new IllegalArgumentException("Invalid Model definition: Specifies an invalid class.", e);
        }

        // Retrieve the vertex data.
        NodeList verticesElement = arrayVGElement.getElementsByTagName("vertex");
        int vertexCount = verticesElement.getLength();

        // Create arrays to contain all vertex data.
        float[] colours = new float[vertexCount * ModelConstants.ITEMS_IN_CNV];
        float[] normals = new float[vertexCount * ModelConstants.ITEMS_IN_CNV];
        float[] vertices = new float[vertexCount * ModelConstants.ITEMS_IN_CNV];

        // For every vertex to be added to the Vertex Group.
        for (int index = 0; index < vertexCount; index++)
        {
            // Retrieve the individual vertex data.
            Element vertexElement = (Element) verticesElement.item(index);
            float[] vertexColours = getFloatArray(vertexElement.getAttribute("colour"));
            float[] vertexNormals = getFloatArray(vertexElement.getAttribute("normal"));
            float[] vertexVertices = getFloatArray(vertexElement.getAttribute("vertex"));

            // Copy the vertex data to the Vertex Group arrays.
            System.arraycopy(vertexColours, 0, colours, index * ModelConstants.ITEMS_IN_CNV, vertexColours.length);
            System.arraycopy(vertexNormals, 0, normals, index * ModelConstants.ITEMS_IN_CNV, vertexNormals.length);
            System.arraycopy(vertexVertices, 0, vertices, index * ModelConstants.ITEMS_IN_CNV, vertexVertices.length);
        }

        arrayVG.setColours(colours);
        arrayVG.setNormals(normals);
        arrayVG.setVertices(vertices);

        return (arrayVG);
    }

    /**
     * <p>
     * Creates a <code>Model</code> from a serialised source representation.
     * </p>
     * 
     * @param modelElement The serialised source representation of the <code>Model</code>.
     * 
     * @return The instance of a <code>Model</code> created from a serialised source representation.
     */
    public static Model createModelFromSource(final Element modelElement)
    {
        // Check that a class was specified.
        if (modelElement.getAttribute("class").isEmpty())
        {
            throw new IllegalArgumentException("Invalid Model definition: Does not specify a class.");
        }

        Model model = null;
        if (modelElement.getAttribute("class").equals("com.se.simplicity.model.ArrayVG"))
        {
            model = createArrayVGFromSource(modelElement);
        }

        return (model);
    }

    /**
     * <p>
     * Creates a serialised source representation from an instance of a <code>Model</code>.
     * </p>
     * 
     * @param document The document the serialised source representation will be included in.
     * @param model The <code>Model</code> to create a serialised source representation from.
     * 
     * @return The serialised source representation created from the <code>Model</code>.
     */
    public static Element createSourceFromModel(final Document document, final Model model)
    {
        Element modelElement = null;
        if (model instanceof ArrayVG)
        {
            modelElement = createSourceFromArrayVG(document, (ArrayVG) model);
        }

        return (modelElement);
    }

    /**
     * <p>
     * Creates a serialised source representation from an instance of an <code>ArrayVG</code>.
     * </p>
     * 
     * @param document The document the serialised source representation will be included in.
     * @param arrayVG The <code>ArrayVG</code> to create a serialised source representation from.
     * 
     * @return The serialised source representation created from the <code>ArrayVG</code>.
     */
    public static Element createSourceFromArrayVG(final Document document, final ArrayVG arrayVG)
    {
        Element modelElement = document.createElement("model");
        modelElement.setAttribute("class", arrayVG.getClass().getName());

        float[] colours = arrayVG.getColours();
        float[] normals = arrayVG.getNormals();
        float[] vertices = arrayVG.getVertices();
        float[] tempArray = new float[ITEMS_IN_CNV];

        for (int vertexIndex = 0; vertexIndex < vertices.length / ITEMS_IN_CNV; vertexIndex++)
        {
            Element vertexElement = document.createElement("vertex");
            modelElement.appendChild(vertexElement);

            System.arraycopy(colours, vertexIndex * ITEMS_IN_CNV, tempArray, 0, ITEMS_IN_CNV);
            vertexElement.setAttribute("colour", getCommaSeparatedList(tempArray));
            System.arraycopy(normals, vertexIndex * ITEMS_IN_CNV, tempArray, 0, ITEMS_IN_CNV);
            vertexElement.setAttribute("normal", getCommaSeparatedList(tempArray));
            System.arraycopy(vertices, vertexIndex * ITEMS_IN_CNV, tempArray, 0, ITEMS_IN_CNV);
            vertexElement.setAttribute("vertex", getCommaSeparatedList(tempArray));
        }

        return (modelElement);
    }

    /**
     * <p>
     * Retrieves a comma separated list from an array of float data.
     * </p>
     * 
     * @param numbers The float data to retrieve the comma separated list from.
     * 
     * @return A comma separated list from an array of float data.
     */
    private static String getCommaSeparatedList(final float[] numbers)
    {
        String list = "";

        for (float number : numbers)
        {
            if (list.isEmpty())
            {
                list = Float.toString(number);
            }
            else
            {
                list = list + ", " + Float.toString(number);
            }
        }

        return (list);
    }

    /**
     * <p>
     * Retrieves an array of float data from a comma separated list.
     * </p>
     * 
     * @param commaSeparatedList The comma separated list to retrieve the float data from.
     * 
     * @return An array of float data from a comma separated list.
     */
    private static float[] getFloatArray(final String commaSeparatedList)
    {
        String[] stringValues = commaSeparatedList.split(",");
        float[] floatValues = new float[stringValues.length];

        for (int index = 0; index < stringValues.length; index++)
        {
            floatValues[index] = Float.parseFloat(stringValues[index].trim());
        }

        return (floatValues);
    }

    /**
     * <p>
     * Loads a {@link com.se.simplicity.model.Model Model} from data in the .OBJ format.
     * </p>
     * 
     * <p>
     * NOTE: The <code>Model</code> described in the .OBJ data must be constructed entirely from triangle polygons.
     * </p>
     * 
     * @param obj The data in the .OBJ format.
     * 
     * @return The <code>Model</code> from the data in the .OBJ format.
     */
    public static Model loadFromOBJ(final InputStream obj)
    {
        Model model = null;
        try
        {
            // Open the file for reading with a buffer.
            BufferedReader reader = new BufferedReader(new InputStreamReader(obj));

            ArrayList<String> faceLines = new ArrayList<String>();

            // Read the vertices and normals from the file into lists.
            String currentLine;
            String[] splitLine;
            ArrayList<float[]> vertexList = new ArrayList<float[]>();
            ArrayList<float[]> normalList = new ArrayList<float[]>();
            while ((currentLine = reader.readLine()) != null)
            {
                splitLine = currentLine.split(" ");

                if (splitLine[0].compareTo("v") == 0)
                {
                    vertexList.add(new float[] {Float.parseFloat(splitLine[1]), Float.parseFloat(splitLine[2]), Float.parseFloat(splitLine[3])});
                }
                else if (splitLine[0].compareTo("vn") == 0)
                {
                    normalList.add(new float[] {Float.parseFloat(splitLine[1]), Float.parseFloat(splitLine[2]), Float.parseFloat(splitLine[3])});
                }
                else if (splitLine[0].compareTo("f") == 0)
                {
                    faceLines.add(currentLine);
                }
            }

            // Create the arrays for vertices, normals and triangles.
            float[] vertices = new float[faceLines.size() * VERTICES_IN_A_FACE * ITEMS_IN_CNV];
            float[] normals = new float[faceLines.size() * VERTICES_IN_A_FACE * ITEMS_IN_CNV];
            float[] colours = new float[faceLines.size() * VERTICES_IN_A_FACE * ITEMS_IN_CNV];

            // Read the faces from the file and populate the arrays.
            int vertex = 0;
            String[] splitIndices;
            for (String faceLine : faceLines)
            {
                splitLine = faceLine.split(" ");

                if (splitLine[0].compareTo("f") == 0)
                {
                    for (int index = 1; index < splitLine.length; index++)
                    {
                        splitIndices = splitLine[index].split("/");

                        System.arraycopy(vertexList.get(Integer.parseInt(splitIndices[0]) - 1), 0, vertices, vertex, ITEMS_IN_CNV);
                        System.arraycopy(normalList.get(Integer.parseInt(splitIndices[2]) - 1), 0, normals, vertex, ITEMS_IN_CNV);
                        colours[vertex] = 1.0f;
                        colours[vertex + 1] = 1.0f;
                        colours[vertex + 2] = 1.0f;

                        vertex += 3;
                    }
                }
            }

            // Build the internal model structure.
            model = new ArrayVG();
            ((ArrayVG) model).setVertices(vertices);
            ((ArrayVG) model).setNormals(normals);
            ((ArrayVG) model).setColours(colours);
        }
        catch (IOException e)
        {
            Logger.getLogger(ModelFactory.class).error("Failed to read input.", e);
        }

        return (model);
    }

    /**
     * <p>
     * Loads a {@link com.se.simplicity.model.Model Model} from a serialised source representation.
     * </p>
     * 
     * @param source The serialised source representation.
     * 
     * @return A <code>Model</code> from a serialised source representation.
     */
    public static Model loadFromSource(final InputStream source)
    {
        Document document = null;
        try
        {
            document = DocumentBuilderFactory.newInstance().newDocumentBuilder().parse(source);
        }
        catch (Exception e)
        {
            throw new IllegalArgumentException("Invalid serialised source representation.", e);
        }

        Model model = createModelFromSource((Element) document.getElementsByTagName("model").item(0));

        return (model);
    }

    /**
     * <p>
     * Writes a serialised source representation of a <code>Model</code> to a <code>Document</code>.
     * </p>
     * 
     * @param model The <code>Model</code> to write a serialised source representation of.
     * @param document The <code>Document</code> that will contain serialised source representation.
     */
    public static void writeToSource(final Model model, final Document document)
    {
        Element simplicityElement = document.createElement("simplicity");
        document.appendChild(simplicityElement);

        Element modelElement = createSourceFromModel(document, model);
        simplicityElement.appendChild(modelElement);
    }

    /**
     * <p>
     * Writes a serialised source representation of a <code>Model</code> to a <code>File</code>.
     * </p>
     * 
     * @param model The <code>Model</code> to write a serialised source representation of.
     * @param source The <code>File</code> that will contain serialised source representation.
     */
    public static void writeToSource(final Model model, final File source)
    {
        Document document = null;
        try
        {
            document = DocumentBuilderFactory.newInstance().newDocumentBuilder().newDocument();
        }
        catch (Exception e)
        {
            Logger.getLogger(SceneFactory.class).error("Failed to create XML Document", e);
            return;
        }

        writeToSource(model, document);

        try
        {
            StreamResult result = new StreamResult(source);
            Transformer transformer = TransformerFactory.newInstance().newTransformer();
            transformer.transform(new DOMSource(document), result);
        }
        catch (TransformerException e)
        {
            Logger.getLogger(SceneFactory.class).error("Failed to transform XML Document", e);
        }
    }

    /**
     * <p>
     * Writes a serialised source representation of a <code>Model</code> to an <code>OutputStream</code>.
     * </p>
     * 
     * @param model The <code>Model</code> to write a serialised source representation of.
     * @param source The <code>OutputStream</code> that will contain serialised source representation.
     */
    public static void writeToSource(final Model model, final OutputStream source)
    {
        Document document = null;
        try
        {
            document = DocumentBuilderFactory.newInstance().newDocumentBuilder().newDocument();
        }
        catch (Exception e)
        {
            Logger.getLogger(SceneFactory.class).error("Failed to create XML Document", e);
            return;
        }

        writeToSource(model, document);

        try
        {
            StreamResult result = new StreamResult(new OutputStreamWriter(source));
            Transformer transformer = TransformerFactory.newInstance().newTransformer();
            transformer.transform(new DOMSource(document), result);
        }
        catch (TransformerException e)
        {
            Logger.getLogger(SceneFactory.class).error("Failed to transform XML Document", e);
        }
    }

    /**
     * <p>
     * Creates an instance of <code>ModelFactory</code>.
     * </p>
     */
    private ModelFactory()
    {}
}
