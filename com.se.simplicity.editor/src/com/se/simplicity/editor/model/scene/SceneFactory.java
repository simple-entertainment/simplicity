package com.se.simplicity.editor.model.scene;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;

import org.w3c.dom.DOMException;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

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
import com.se.simplicity.vector.TranslationVectorf;

public final class SceneFactory
{
    private SceneFactory()
    {}

    protected static Camera createCameraFromXml(Element cameraXml, SceneGraph sceneGraph) throws DOMException, InstantiationException,
            IllegalAccessException, ClassNotFoundException
    {
        if (cameraXml.getAttribute("class").isEmpty())
        {
            throw new IllegalArgumentException("Camera definitions must specify a class.");
        }

        MetaDataCamera camera = new MetaDataCamera((Camera) Class.forName(cameraXml.getAttribute("class")).newInstance());

        if (!cameraXml.getAttribute("name").isEmpty())
        {
            camera.setAttribute("name", cameraXml.getAttribute("name"));
        }

        if (!cameraXml.getAttribute("node").isEmpty())
        {
            camera.setNode(sceneGraph.getNode(Integer.parseInt(cameraXml.getAttribute("node"))));
        }

        return (camera);
    }

    protected static Light createLightFromXml(Element lightXml, SceneGraph sceneGraph) throws DOMException, InstantiationException,
            IllegalAccessException, ClassNotFoundException
    {
        if (lightXml.getAttribute("class").isEmpty())
        {
            throw new IllegalArgumentException("Light definitions must specify a class.");
        }

        MetaDataLight light = new MetaDataLight((Light) Class.forName(lightXml.getAttribute("class")).newInstance());

        if (!lightXml.getAttribute("name").isEmpty())
        {
            light.setAttribute("name", lightXml.getAttribute("name"));
        }

        if (!lightXml.getAttribute("node").isEmpty())
        {
            light.setNode(sceneGraph.getNode(Integer.parseInt(lightXml.getAttribute("node"))));
        }

        Element ambientXml = (Element) lightXml.getElementsByTagName("ambient").item(0);
        if (ambientXml != null)
        {
            light.setAmbientLight(getFloatArrayFromCommaSeparatedList(ambientXml.getAttribute("colour") + ", 1.0"));
        }

        Element diffuseXml = (Element) lightXml.getElementsByTagName("diffuse").item(0);
        if (diffuseXml != null)
        {
            light.setDiffuseLight(getFloatArrayFromCommaSeparatedList(diffuseXml.getAttribute("colour") + ", 1.0"));
        }

        Element specularXml = (Element) lightXml.getElementsByTagName("specular").item(0);
        if (specularXml != null)
        {
            light.setSpecularLight(getFloatArrayFromCommaSeparatedList(specularXml.getAttribute("colour") + ", 1.0"));
        }

        return (light);
    }

    protected static Node createNodeFromXml(Element nodeXml) throws DOMException, InstantiationException, IllegalAccessException,
            ClassNotFoundException
    {
        MetaDataNode node = null;
        if (nodeXml.getAttribute("class").isEmpty())
        {
            node = new MetaDataNode(new SimpleNode());
        }
        else
        {
            node = new MetaDataNode((Node) Class.forName(nodeXml.getAttribute("class")).newInstance());
        }

        if (!nodeXml.getAttribute("name").isEmpty())
        {
            node.setAttribute("name", nodeXml.getAttribute("name"));
        }
        else
        {
            node.addDefaultNameAttribute();
        }

        NodeList contentsXml = nodeXml.getElementsByTagName("content");
        for (int index = 0; index < contentsXml.getLength(); index++)
        {
            Element contentXml = (Element) contentsXml.item(index);

            if (contentXml.getAttribute("type").equals("transformation"))
            {
                transformationFromXml(contentXml, node);
            }
            if (contentXml.getAttribute("type").equals("vertexGroup"))
            {
                node.setVertexGroup(createVertexGroupFromXml(contentXml));
            }
        }

        return (node);
    }

    private static void transformationFromXml(Element contentXml, Node node)
    {
        Element translationXml = (Element) contentXml.getElementsByTagName("translation").item(0);

        float[] translationArray = getFloatArrayFromCommaSeparatedList(translationXml.getAttribute("vector"));

        TranslationVectorf translation = node.getTransformation().getTranslation();
        translation.setX(translationArray[0]);
        translation.setY(translationArray[1]);
        translation.setZ(translationArray[2]);
        node.getTransformation().translate(translation);
    }

    protected static Node createSubgraphFromXml(org.w3c.dom.Node subgraphRootXml) throws DOMException, InstantiationException,
            IllegalAccessException, ClassNotFoundException
    {
        Node node = createNodeFromXml((Element) subgraphRootXml);

        for (int index = 0; index < subgraphRootXml.getChildNodes().getLength(); index++)
        {
            org.w3c.dom.Node childXml = subgraphRootXml.getChildNodes().item(index);

            if (childXml.getNodeName().equals("node"))
            {
                Node childNode = createSubgraphFromXml(childXml);
                node.addChild(childNode);
            }
        }

        return (node);
    }

    protected static VertexGroup createVertexGroupFromXml(Element vertexGroupXml) throws DOMException, InstantiationException,
            IllegalAccessException, ClassNotFoundException
    {
        if (vertexGroupXml.getAttribute("class").isEmpty())
        {
            throw new IllegalArgumentException("Vertex Group definitions must specify a class.");
        }

        VertexGroup vertexGroup = (VertexGroup) Class.forName(vertexGroupXml.getAttribute("class")).newInstance();

        NodeList verticesXml = vertexGroupXml.getElementsByTagName("vertex");
        int vertexCount = verticesXml.getLength();

        if (vertexGroup instanceof ArrayVG)
        {
            float[] colours = new float[vertexCount * ModelConstants.ITEMS_IN_CNV];
            float[] normals = new float[vertexCount * ModelConstants.ITEMS_IN_CNV];
            float[] vertices = new float[vertexCount * ModelConstants.ITEMS_IN_CNV];

            for (int index = 0; index < vertexCount; index++)
            {
                Element vertexXml = (Element) verticesXml.item(index);
                float[] vertexColours = getFloatArrayFromCommaSeparatedList(vertexXml.getAttribute("colour"));
                float[] vertexNormals = getFloatArrayFromCommaSeparatedList(vertexXml.getAttribute("normal"));
                float[] vertexVertices = getFloatArrayFromCommaSeparatedList(vertexXml.getAttribute("vertex"));

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

    public static Scene loadFromBinaryFile(File file)
    {
        return (null);
    }

    public static Scene loadFromSourceFile(File file) throws ParserConfigurationException, SAXException, IOException, DOMException,
            InstantiationException, IllegalAccessException, ClassNotFoundException
    {
        MetaDataScene scene = new MetaDataScene(new SimpleJOGLScene());

        Document document = DocumentBuilderFactory.newInstance().newDocumentBuilder().parse(file);

        scene.setSceneGraph(loadSceneGraphFromSourceFile(document.getElementsByTagName("sceneGraph").item(0)));

        scene.setCameras(loadCamerasFromSourceFile(document.getElementsByTagName("camera"), scene.getSceneGraph()));
        scene.setLights(loadLightsFromSourceFile(document.getElementsByTagName("light"), scene.getSceneGraph()));

        return (scene);
    }

    protected static float[] getFloatArrayFromCommaSeparatedList(String commaSeparatedList)
    {
        String[] stringValues = commaSeparatedList.split(",");
        float[] floatValues = new float[stringValues.length];

        for (int index = 0; index < stringValues.length; index++)
        {
            floatValues[index] = Float.parseFloat(stringValues[index].trim());
        }

        return (floatValues);
    }

    protected static List<Camera> loadCamerasFromSourceFile(NodeList camerasXml, SceneGraph sceneGraph) throws DOMException, InstantiationException,
            IllegalAccessException, ClassNotFoundException
    {
        ArrayList<Camera> cameras = new ArrayList<Camera>();

        for (int index = 0; index < camerasXml.getLength(); index++)
        {
            cameras.add(createCameraFromXml((Element) camerasXml.item(index), sceneGraph));
        }

        return (cameras);
    }

    protected static List<Light> loadLightsFromSourceFile(NodeList lightsXml, SceneGraph sceneGraph) throws DOMException, InstantiationException,
            IllegalAccessException, ClassNotFoundException
    {
        ArrayList<Light> lights = new ArrayList<Light>();

        for (int index = 0; index < lightsXml.getLength(); index++)
        {
            lights.add(createLightFromXml((Element) lightsXml.item(index), sceneGraph));
        }

        return (lights);
    }

    protected static SceneGraph loadSceneGraphFromSourceFile(org.w3c.dom.Node sceneGraphXml) throws DOMException, InstantiationException,
            IllegalAccessException, ClassNotFoundException
    {
        MetaDataSceneGraph sceneGraph = new MetaDataSceneGraph(new SimpleSceneGraph());
        NodeList childrenXml = sceneGraphXml.getChildNodes().item(1).getChildNodes();

        for (int index = 0; index < childrenXml.getLength(); index++)
        {
            org.w3c.dom.Node childXml = childrenXml.item(index);

            if (childXml.getNodeName().equals("node"))
            {
                sceneGraph.addSubgraph(createSubgraphFromXml(childXml));
            }
        }

        return (sceneGraph);
    }

    public void writeToBinaryFile(Scene scene)
    {}

    public void writeToSourceFile(Scene scene)
    {}
}
