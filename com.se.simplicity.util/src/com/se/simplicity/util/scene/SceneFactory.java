/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.util.scene;

import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;

import javax.xml.parsers.DocumentBuilderFactory;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.NodeList;

import com.se.simplicity.jogl.scene.SimpleJOGLScene;
import com.se.simplicity.model.ArrayVG;
import com.se.simplicity.model.ModelConstants;
import com.se.simplicity.model.VertexGroup;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.Light;
import com.se.simplicity.scene.Scene;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.SceneGraph;
import com.se.simplicity.scenegraph.SimpleNode;
import com.se.simplicity.scenegraph.SimpleSceneGraph;
import com.se.simplicity.util.metadata.rendering.MetaDataCamera;
import com.se.simplicity.util.metadata.rendering.MetaDataLight;
import com.se.simplicity.util.metadata.scene.MetaDataScene;
import com.se.simplicity.util.metadata.scenegraph.MetaDataNode;
import com.se.simplicity.util.metadata.scenegraph.MetaDataSceneGraph;
import com.se.simplicity.vector.TranslationVectorf;

/**
 * <p>
 * Builds <code>Scene</code>s from their serialised source and binary representations.
 * </p>
 * 
 * @author Gary Buyn
 */
public final class SceneFactory
{
    /**
     * <p>
     * Creates an instance of a <code>Camera</code> from a serialised source representation.
     * </p>
     * 
     * @param cameraXml The serialised source representation of the <code>Camera</code>.
     * @param sceneGraph The <code>SceneGraph</code> containing the <code>Node</code> the <code>Camera</code> should be linked to (if a link exists).
     * 
     * @return The instance of a <code>Camera</code> created from a serialised source representation.
     */
    private static Camera createCameraFromSource(final Element cameraXml, final SceneGraph sceneGraph)
    {
        // Check that a class was specified.
        if (cameraXml.getAttribute("class").isEmpty())
        {
            throw new IllegalArgumentException("Invalid Camera definition: Does not specify a class.");
        }

        MetaDataCamera camera = null;
        try
        {
            camera = new MetaDataCamera((Camera) Class.forName(cameraXml.getAttribute("class")).newInstance());
        }
        catch (Exception e)
        {
            throw new IllegalArgumentException("Invalid Camera definition: Specifies an invalid class.", e);
        }

        // Add the name to the Camera if one was specified.
        if (!cameraXml.getAttribute("name").isEmpty())
        {
            camera.setAttribute("name", cameraXml.getAttribute("name"));
        }

        // Link the Camera to the appropriate Node in the Scene Graph if one was specified.
        if (!cameraXml.getAttribute("node").isEmpty())
        {
            camera.setNode(sceneGraph.getNode(Integer.parseInt(cameraXml.getAttribute("node"))));
        }

        return (camera);
    }

    /**
     * <p>
     * Creates an instance of a <code>Light</code> from a serialised source representation.
     * </p>
     * 
     * @param lightXml The serialised source representation of the <code>Light</code>.
     * @param sceneGraph The <code>SceneGraph</code> containing the <code>Node</code> the <code>Light</code> should be linked to (if a link exists).
     * 
     * @return The instance of a <code>Light</code> created from a serialised source representation.
     */
    private static Light createLightFromSource(final Element lightXml, final SceneGraph sceneGraph)
    {
        // Check that a class was specified.
        if (lightXml.getAttribute("class").isEmpty())
        {
            throw new IllegalArgumentException("Invliad Light definition: Does not specify a class.");
        }

        MetaDataLight light = null;
        try
        {
            light = new MetaDataLight((Light) Class.forName(lightXml.getAttribute("class")).newInstance());
        }
        catch (Exception e)
        {
            throw new IllegalArgumentException("Invalid Light definition: Specifies an invalid class.", e);
        }

        // Add the name to the Light if one was specified.
        if (!lightXml.getAttribute("name").isEmpty())
        {
            light.setAttribute("name", lightXml.getAttribute("name"));
        }

        // Link the Light to the appropriate Node in the Scene Graph if one was specified.
        if (!lightXml.getAttribute("node").isEmpty())
        {
            light.setNode(sceneGraph.getNode(Integer.parseInt(lightXml.getAttribute("node"))));
        }

        // Set the colour of the Light if it was specified.
        Element ambientXml = (Element) lightXml.getElementsByTagName("ambient").item(0);
        if (ambientXml != null)
        {
            light.setAmbientLight(getFloatArray(ambientXml.getAttribute("colour") + ", 1.0"));
        }

        Element diffuseXml = (Element) lightXml.getElementsByTagName("diffuse").item(0);
        if (diffuseXml != null)
        {
            light.setDiffuseLight(getFloatArray(diffuseXml.getAttribute("colour") + ", 1.0"));
        }

        Element specularXml = (Element) lightXml.getElementsByTagName("specular").item(0);
        if (specularXml != null)
        {
            light.setSpecularLight(getFloatArray(specularXml.getAttribute("colour") + ", 1.0"));
        }

        return (light);
    }

    /**
     * <p>
     * Creates an instance of a <code>Node</code> from a serialised source representation.
     * </p>
     * 
     * @param nodeXml The serialised source representation of the <code>Node</code>.
     * 
     * @return The instance of a <code>Node</code> created from a serialised source representation.
     */
    private static Node createNodeFromSource(final Element nodeXml)
    {
        // Check that a class was specified. If not, use a default implementation.
        MetaDataNode node = null;
        if (nodeXml.getAttribute("class").isEmpty())
        {
            node = new MetaDataNode(new SimpleNode());
        }
        else
        {
            try
            {
                node = new MetaDataNode((Node) Class.forName(nodeXml.getAttribute("class")).newInstance());
            }
            catch (Exception e)
            {
                throw new IllegalArgumentException("Invalid Node definition: Specifies an invalid class.", e);
            }
        }

        // Add the name to the Node if one was specified.
        if (!nodeXml.getAttribute("name").isEmpty())
        {
            node.setAttribute("name", nodeXml.getAttribute("name"));
        }
        else
        {
            node.addDefaultNameAttribute();
        }

        // Add content to the Node if any was specified.
        NodeList contentsXml = nodeXml.getElementsByTagName("content");
        for (int index = 0; index < contentsXml.getLength(); index++)
        {
            Element contentXml = (Element) contentsXml.item(index);

            if (contentXml.getAttribute("type").equals("transformation"))
            {
                performTransformationFromXml(contentXml, node);
            }
            if (contentXml.getAttribute("type").equals("vertexGroup"))
            {
                node.setVertexGroup(createVertexGroupFromSource(contentXml));
            }
        }

        return (node);
    }

    /**
     * <p>
     * Creates a subgraph of <code>Node</code>s from a serialised source representation.
     * </p>
     * 
     * @param subgraphRootXml The serialised source representation of the root <code>Node</code> of the subgraph.
     * 
     * @return The root <code>Node</code> of the subgraph created from a serialised source representation.
     */
    private static Node createSubgraphFromSource(final Element subgraphRootXml)
    {
        Node node = createNodeFromSource(subgraphRootXml);

        // For every child XML node of the subgraph root.
        for (int index = 0; index < subgraphRootXml.getChildNodes().getLength(); index++)
        {
            org.w3c.dom.Node childXml = subgraphRootXml.getChildNodes().item(index);

            // If the child is also a Node (i.e. not an XML text node or other XML node).
            if (childXml.getNodeName().equals("node"))
            {
                Node childNode = createSubgraphFromSource((Element) childXml);
                node.addChild(childNode);
            }
        }

        return (node);
    }

    /**
     * <p>
     * Creates a <code>XertexGroup</code> from a serialised source representation.
     * </p>
     * 
     * @param vertexGroupXml The serialised source representation of the root <code>XertexGroup</code> of the subgraph.
     * 
     * @return The instance of a <code>XertexGroup</code> created from a serialised source representation.
     */
    private static VertexGroup createVertexGroupFromSource(final Element vertexGroupXml)
    {
        // Check that a class was specified.
        if (vertexGroupXml.getAttribute("class").isEmpty())
        {
            throw new IllegalArgumentException("Invalid Vertex Group definition: Does not specify a class.");
        }

        VertexGroup vertexGroup = null;
        try
        {
            vertexGroup = (VertexGroup) Class.forName(vertexGroupXml.getAttribute("class")).newInstance();
        }
        catch (Exception e)
        {
            throw new IllegalArgumentException("Invalid Vertex Group definition: Specifies an invalid class.", e);
        }

        // Retrieve the vertex data.
        NodeList verticesXml = vertexGroupXml.getElementsByTagName("vertex");
        int vertexCount = verticesXml.getLength();

        if (vertexGroup instanceof ArrayVG)
        {
            // Create arrays to contain all vertex data.
            float[] colours = new float[vertexCount * ModelConstants.ITEMS_IN_CNV];
            float[] normals = new float[vertexCount * ModelConstants.ITEMS_IN_CNV];
            float[] vertices = new float[vertexCount * ModelConstants.ITEMS_IN_CNV];

            // For every vertex to be added to the Vertex Group.
            for (int index = 0; index < vertexCount; index++)
            {
                // Retrieve the individual vertex data.
                Element vertexXml = (Element) verticesXml.item(index);
                float[] vertexColours = getFloatArray(vertexXml.getAttribute("colour"));
                float[] vertexNormals = getFloatArray(vertexXml.getAttribute("normal"));
                float[] vertexVertices = getFloatArray(vertexXml.getAttribute("vertex"));

                // Copy the vertex data to the Vertex Group arrays.
                System.arraycopy(vertexColours, 0, colours, index * ModelConstants.ITEMS_IN_CNV, vertexColours.length);
                System.arraycopy(vertexNormals, 0, normals, index * ModelConstants.ITEMS_IN_CNV, vertexNormals.length);
                System.arraycopy(vertexVertices, 0, vertices, index * ModelConstants.ITEMS_IN_CNV, vertexVertices.length);
            }

            ((ArrayVG) vertexGroup).setColours(colours);
            ((ArrayVG) vertexGroup).setNormals(normals);
            ((ArrayVG) vertexGroup).setVertices(vertices);
        }

        return (vertexGroup);
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
     * Loads a list of <code>Camera</code>s from a serialised source representation.
     * </p>
     * 
     * @param camerasXml The serialised source representation of the <code>Camera</code>s.
     * @param sceneGraph The <code>SceneGraph</code> containing the <code>Node</code>s the <code>Camera</code>s should be linked to (if a link
     * exists).
     * 
     * @return A list of <code>Camera</code>s loaded from a serialised source representation.
     */
    private static List<Camera> loadCamerasFromSource(final NodeList camerasXml, final SceneGraph sceneGraph)
    {
        ArrayList<Camera> cameras = new ArrayList<Camera>();

        for (int index = 0; index < camerasXml.getLength(); index++)
        {
            cameras.add(createCameraFromSource((Element) camerasXml.item(index), sceneGraph));
        }

        return (cameras);
    }

    /**
     * <p>
     * Loads a <code>Scene</code> from a serialised binary representation.
     * </p>
     * 
     * @param binary The serialised binary representation.
     * 
     * @return A <code>Scene</code> from a serialised binary representation.
     */
    public static Scene loadFromBinary(final InputStream binary)
    {
        return (null);
    }

    /**
     * <p>
     * Loads a <code>Scene</code> from a serialised source representation.
     * </p>
     * 
     * @param source The serialised source representation.
     * 
     * @return A <code>Scene</code> from a serialised source representation.
     */
    public static Scene loadFromSource(final InputStream source)
    {
        MetaDataScene scene = new MetaDataScene(new SimpleJOGLScene());

        Document document = null;
        try
        {
            document = DocumentBuilderFactory.newInstance().newDocumentBuilder().parse(source);
        }
        catch (Exception e)
        {
            throw new IllegalArgumentException("Invalid serialised source representation.", e);
        }

        scene.setSceneGraph(loadSceneGraphFromSource((Element) document.getElementsByTagName("sceneGraph").item(0)));
        scene.setCameras(loadCamerasFromSource(document.getElementsByTagName("camera"), scene.getSceneGraph()));
        scene.setLights(loadLightsFromSource(document.getElementsByTagName("light"), scene.getSceneGraph()));

        return (scene);
    }

    /**
     * <p>
     * Loads a list of <code>Light</code>s from a serialised source representation.
     * </p>
     * 
     * @param lightsXml The serialised source representation of the <code>Light</code>s.
     * @param sceneGraph The <code>SceneGraph</code> containing the <code>Node</code>s the <code>Light</code>s should be linked to (if a link exists).
     * 
     * @return A list of <code>Light</code>s loaded from a serialised source representation.
     */
    private static List<Light> loadLightsFromSource(final NodeList lightsXml, final SceneGraph sceneGraph)
    {
        ArrayList<Light> lights = new ArrayList<Light>();

        for (int index = 0; index < lightsXml.getLength(); index++)
        {
            lights.add(createLightFromSource((Element) lightsXml.item(index), sceneGraph));
        }

        return (lights);
    }

    /**
     * <p>
     * Loads a <code>SceneGraph</code> from a serialised source representation.
     * </p>
     * 
     * @param sceneGraphXml The serialised source representation of the <code>SceneGraph</code>.
     * 
     * @return A <code>SceneGraph</code> loaded from a serialised source representation.
     */
    private static SceneGraph loadSceneGraphFromSource(final Element sceneGraphXml)
    {
        MetaDataSceneGraph sceneGraph = new MetaDataSceneGraph(new SimpleSceneGraph());
        NodeList childrenXml = sceneGraphXml.getChildNodes().item(1).getChildNodes();

        for (int index = 0; index < childrenXml.getLength(); index++)
        {
            org.w3c.dom.Node childXml = childrenXml.item(index);

            if (childXml.getNodeName().equals("node"))
            {
                sceneGraph.addSubgraph(createSubgraphFromSource((Element) childXml));
            }
        }

        return (sceneGraph);
    }

    /**
     * <p>
     * Performs a transformation from a serialised source representation on a <code>Node</code>.
     * </p>
     * 
     * @param contentXml The serialised source representation of the transformation.
     * @param node The <code>Node</code> to perform the transformation on.
     */
    private static void performTransformationFromXml(final Element contentXml, final Node node)
    {
        Element translationXml = (Element) contentXml.getElementsByTagName("translation").item(0);

        float[] translationArray = getFloatArray(translationXml.getAttribute("vector"));

        TranslationVectorf translation = node.getTransformation().getTranslation();
        translation.setX(translationArray[0]);
        translation.setY(translationArray[1]);
        translation.setZ(translationArray[2]);
        node.getTransformation().translate(translation);
    }

    /**
     * <p>
     * Creates an instance of <code>SceneFactory</code>. Hidden as an instance should never need to be created.
     * </p>
     */
    private SceneFactory()
    {}
}
