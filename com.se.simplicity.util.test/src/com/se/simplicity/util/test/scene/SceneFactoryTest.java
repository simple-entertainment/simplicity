/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.util.test.scene;

import static org.easymock.EasyMock.expect;
import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.replay;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertNull;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;

import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;

import org.junit.Test;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

import com.se.simplicity.jogl.rendering.SimpleJOGLCamera;
import com.se.simplicity.jogl.rendering.SimpleJOGLLight;
import com.se.simplicity.model.ArrayVG;
import com.se.simplicity.model.VertexGroup;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.Light;
import com.se.simplicity.scene.Scene;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.SceneGraph;
import com.se.simplicity.scenegraph.SimpleNode;
import com.se.simplicity.scenegraph.SimpleSceneGraph;
import com.se.simplicity.scenegraph.model.SimpleModelNode;
import com.se.simplicity.test.mocks.NodeHierarchy;
import com.se.simplicity.util.metadata.MetaData;
import com.se.simplicity.util.metadata.rendering.MetaDataCamera;
import com.se.simplicity.util.metadata.rendering.MetaDataLight;
import com.se.simplicity.util.metadata.scenegraph.MetaDataNode;
import com.se.simplicity.util.metadata.scenegraph.MetaDataSceneGraph;
import com.se.simplicity.util.scene.SceneFactory;
import com.se.simplicity.vector.TranslationVectorf;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.util.scene.SceneFactory SceneFactory}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SceneFactoryTest
{
    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.util.scene.SceneFactory.loadFromSource loadFromSource()}, specifically the functionality that
     * loads a <code>Camera</code>.
     * </p>
     * 
     * @throws FileNotFoundException Thrown if source file is not found.
     */
    @Test
    public void loadFromSourceCamera() throws FileNotFoundException
    {
        Scene scene = SceneFactory.loadFromSource(new FileInputStream(new File("src/com/se/simplicity/util/test/scene/triangle.xml")));

        assertEquals(1, scene.getCameras().size(), 0);
        assertEquals(SimpleJOGLCamera.class, ((MetaDataCamera) scene.getCameras().get(0)).getWrappedCamera().getClass());
        assertEquals("Camera0", ((MetaDataCamera) scene.getCameras().get(0)).getAttribute("name"));
        assertNotNull(scene.getCameras().get(0).getNode());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.util.scene.SceneFactory.loadFromSource loadFromSource()} with the special condition that the
     * source file contains two camera definitions with the same name.
     * </p>
     * 
     * @throws FileNotFoundException Thrown if source file is not found.
     */
    @Test
    public void loadFromSourceCameraDuplicateNames() throws FileNotFoundException
    {
        // Perform test.
        Scene scene = SceneFactory.loadFromSource(new FileInputStream(new File(
                "src/com/se/simplicity/util/test/scene/triangleTwoCamerasDuplicate.xml")));

        // Verify test results.
        assertEquals(1, scene.getCameras().size(), 0);
        assertEquals("Camera0", ((MetaData) scene.getCameras().get(0)).getAttribute("name"));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.util.scene.SceneFactory.loadFromSource loadFromSource()} with the special condition that the
     * source file contains a camera definition with no class specified.
     * </p>
     * 
     * @throws FileNotFoundException Thrown if source file is not found.
     */
    @Test
    public void loadFromSourceCameraNoClass() throws FileNotFoundException
    {
        try
        {
            SceneFactory.loadFromSource(new FileInputStream(new File("src/com/se/simplicity/util/test/scene/triangleCameraNoClass.xml")));
        }
        catch (IllegalArgumentException e)
        {
            assertEquals("Invalid Camera definition: Does not specify a class.", e.getMessage());
        }
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.util.scene.SceneFactory.loadFromSource loadFromSource()} with the special condition that the
     * source file contains a camera definition with no name specified.
     * </p>
     * 
     * @throws FileNotFoundException Thrown if source file is not found.
     */
    @Test
    public void loadFromSourceCameraNoName() throws FileNotFoundException
    {
        try
        {
            SceneFactory.loadFromSource(new FileInputStream(new File("src/com/se/simplicity/util/test/scene/triangleCameraNoName.xml")));
        }
        catch (IllegalArgumentException e)
        {
            assertEquals("Invalid Camera definition: Does not specify a name.", e.getMessage());
        }
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.util.scene.SceneFactory.loadFromSource loadFromSource()}, specifically the functionality that
     * loads a <code>Light</code>.
     * </p>
     * 
     * @throws FileNotFoundException Thrown if source file is not found.
     */
    @Test
    public void loadFromSourceLight() throws FileNotFoundException
    {
        Scene scene = SceneFactory.loadFromSource(new FileInputStream(new File("src/com/se/simplicity/util/test/scene/triangle.xml")));

        assertEquals(1, scene.getLights().size(), 0);
        assertEquals(SimpleJOGLLight.class, ((MetaDataLight) scene.getLights().get(0)).getWrappedLight().getClass());
        assertEquals("Light0", ((MetaDataLight) scene.getLights().get(0)).getAttribute("name"));
        assertNotNull(scene.getLights().get(0).getNode());

        float[] ambientLight = scene.getLights().get(0).getAmbientLight();
        assertEquals(0.1f, ambientLight[0], 0.0f);
        assertEquals(0.1f, ambientLight[1], 0.0f);
        assertEquals(0.1f, ambientLight[2], 0.0f);
        assertEquals(1.0f, ambientLight[3], 0.0f);

        float[] diffuseLight = scene.getLights().get(0).getDiffuseLight();
        assertEquals(0.1f, diffuseLight[0], 0.0f);
        assertEquals(0.1f, diffuseLight[1], 0.0f);
        assertEquals(0.1f, diffuseLight[2], 0.0f);
        assertEquals(1.0f, diffuseLight[3], 0.0f);

        float[] specularLight = scene.getLights().get(0).getSpecularLight();
        assertEquals(0.1f, specularLight[0], 0.0f);
        assertEquals(0.1f, specularLight[1], 0.0f);
        assertEquals(0.1f, specularLight[2], 0.0f);
        assertEquals(1.0f, specularLight[3], 0.0f);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.util.scene.SceneFactory.loadFromSource loadFromSource()} with the special condition that the
     * source file contains two light definitions with the same name.
     * </p>
     * 
     * @throws FileNotFoundException Thrown if source file is not found.
     */
    @Test
    public void loadFromSourceLightDuplicateNames() throws FileNotFoundException
    {
        // Perform test.
        Scene scene = SceneFactory.loadFromSource(new FileInputStream(
                new File("src/com/se/simplicity/util/test/scene/triangleTwoLightsDuplicate.xml")));

        // Verify test results.
        assertEquals(1, scene.getLights().size(), 0);
        assertEquals("Light0", ((MetaData) scene.getLights().get(0)).getAttribute("name"));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.model.scene.SceneFactory.loadFromSourceFile loadFromSourceFile()} with the special
     * condition that the source file contains a light definition with no class specified.
     * </p>
     * 
     * @throws FileNotFoundException Thrown if source file is not found.
     */
    @Test
    public void loadFromSourceLightNoClass() throws FileNotFoundException
    {
        try
        {
            SceneFactory.loadFromSource(new FileInputStream(new File("src/com/se/simplicity/util/test/scene/triangleLightNoClass.xml")));
        }
        catch (IllegalArgumentException e)
        {
            assertEquals("Invalid Light definition: Does not specify a class.", e.getMessage());
        }
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.model.scene.SceneFactory.loadFromSourceFile loadFromSourceFile()} with the special
     * condition that the source file contains a light definition with no name specified.
     * </p>
     * 
     * @throws FileNotFoundException Thrown if source file is not found.
     */
    @Test
    public void loadFromSourceLightNoName() throws FileNotFoundException
    {
        try
        {
            SceneFactory.loadFromSource(new FileInputStream(new File("src/com/se/simplicity/util/test/scene/triangleLightNoName.xml")));
        }
        catch (IllegalArgumentException e)
        {
            assertEquals("Invalid Light definition: Does not specify a name.", e.getMessage());
        }
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.model.scene.SceneFactory.loadFromSourceFile loadFromSourceFile()} with the special
     * condition that the source file contains a node definition with no name specified.
     * 
     * @throws FileNotFoundException Thrown if source file is not found.
     */
    @Test
    public void loadFromSourceNodeNoName() throws FileNotFoundException
    {
        Scene scene = SceneFactory.loadFromSource(new FileInputStream(new File("src/com/se/simplicity/util/test/scene/triangleNodeNoName.xml")));

        MetaDataNode node1 = (MetaDataNode) scene.getSceneGraph().getRoot().getChildren().get(0);
        assertEquals(1, node1.getID(), 0);
        assertEquals("SimpleNode0", node1.getAttribute("name"));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.util.scene.SceneFactory.loadFromSource loadFromSource()}, specifically the functionality that
     * loads <code>Node</code>s.
     * </p>
     * 
     * @throws FileNotFoundException Thrown if source file is not found.
     */
    @Test
    public void loadFromSourceNodes() throws FileNotFoundException
    {
        Scene scene = SceneFactory.loadFromSource(new FileInputStream(new File("src/com/se/simplicity/util/test/scene/triangle.xml")));

        Node node0 = scene.getSceneGraph().getRoot();

        MetaDataNode node1 = (MetaDataNode) node0.getChildren().get(0);
        assertEquals(SimpleNode.class, node1.getWrappedNode().getClass());
        assertEquals("Camera", node1.getAttribute("name"));

        TranslationVectorf translation1 = node1.getTransformation().getTranslation();
        assertEquals(0.0f, translation1.getX(), 0.0f);
        assertEquals(0.0f, translation1.getY(), 0.0f);
        assertEquals(5.0f, translation1.getZ(), 0.0f);
        assertEquals(1.0f, translation1.getW(), 0.0f);

        assertEquals(1.0f, node1.getTransformation().getXAxisRotation(), 0.0f);
        assertEquals(0.0f, node1.getTransformation().getYAxisRotation(), 0.0f);
        assertEquals(0.0f, node1.getTransformation().getZAxisRotation(), 0.0f);

        MetaDataNode node2 = (MetaDataNode) node0.getChildren().get(1);
        assertEquals(SimpleNode.class, node2.getWrappedNode().getClass());
        assertEquals("Light", node2.getAttribute("name"));

        TranslationVectorf translation2 = node2.getTransformation().getTranslation();
        assertEquals(0.0f, translation2.getX(), 0.0f);
        assertEquals(5.0f, translation2.getY(), 0.0f);
        assertEquals(0.0f, translation2.getZ(), 0.0f);
        assertEquals(1.0f, translation2.getW(), 0.0f);

        MetaDataNode node3 = (MetaDataNode) node0.getChildren().get(2);
        assertEquals(SimpleModelNode.class, node3.getWrappedNode().getClass());
        assertEquals("Triangle", node3.getAttribute("name"));

        VertexGroup vertexGroup = node3.getVertexGroup();
        assertEquals(ArrayVG.class, vertexGroup.getClass());

        float[] colours = ((ArrayVG) vertexGroup).getColours();
        assertEquals(1.0f, colours[0], 0.0f);
        assertEquals(0.0f, colours[1], 0.0f);
        assertEquals(0.0f, colours[2], 0.0f);
        assertEquals(0.0f, colours[3], 0.0f);
        assertEquals(1.0f, colours[4], 0.0f);
        assertEquals(0.0f, colours[5], 0.0f);
        assertEquals(0.0f, colours[6], 0.0f);
        assertEquals(0.0f, colours[7], 0.0f);
        assertEquals(1.0f, colours[8], 0.0f);

        float[] normals = ((ArrayVG) vertexGroup).getNormals();
        assertEquals(0.0f, normals[0], 0.0f);
        assertEquals(0.0f, normals[1], 0.0f);
        assertEquals(1.0f, normals[2], 0.0f);
        assertEquals(0.0f, normals[3], 0.0f);
        assertEquals(0.0f, normals[4], 0.0f);
        assertEquals(1.0f, normals[5], 0.0f);
        assertEquals(0.0f, normals[6], 0.0f);
        assertEquals(0.0f, normals[7], 0.0f);
        assertEquals(1.0f, normals[8], 0.0f);

        float[] vertices = ((ArrayVG) vertexGroup).getVertices();
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
     * Unit test the method {@link com.se.simplicity.editor.model.scene.SceneFactory.loadFromSourceFile loadFromSourceFile()} with the special
     * condition that the source file contains a vertex group definition with no class specified.
     * 
     * @throws FileNotFoundException Thrown if source file is not found.
     */
    @Test
    public void loadFromSourceVertexGroupNoClass() throws FileNotFoundException
    {
        try
        {
            SceneFactory.loadFromSource(new FileInputStream(new File("src/com/se/simplicity/util/test/scene/triangleVertexGroupNoClass.xml")));
        }
        catch (IllegalArgumentException e)
        {
            assertEquals("Invalid Vertex Group definition: Does not specify a class.", e.getMessage());
        }
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.util.scene.SceneFactory#updateFromSource(Scene, InputStream) updateFromSource(Scene,
     * InputStream)}, specifically the functionality that updates <code>Camera</code>s.
     * 
     * @throws FileNotFoundException Thrown if source file is not found.
     */
    @Test
    public void updateFromSourceCamera() throws FileNotFoundException
    {
        // Initialise test environment.
        Scene scene = SceneFactory.loadFromSource(new FileInputStream(new File("src/com/se/simplicity/util/test/scene/triangle.xml")));
        Camera camera0 = scene.getCameras().get(0);

        // Perform test 1.
        SceneFactory.updateFromSource(scene, new FileInputStream(new File("src/com/se/simplicity/util/test/scene/triangleTwoCameras.xml")));

        // Verify test 1 results.
        assertEquals(2, scene.getCameras().size(), 0);
        assertEquals(camera0, scene.getCameras().get(0));
        assertEquals("Camera0", ((MetaData) scene.getCameras().get(0)).getAttribute("name"));
        assertEquals("Camera1", ((MetaData) scene.getCameras().get(1)).getAttribute("name"));

        // Perform test 2.
        SceneFactory.updateFromSource(scene, new FileInputStream(new File("src/com/se/simplicity/util/test/scene/triangle.xml")));

        // Verify test 2 results.
        assertEquals(1, scene.getCameras().size(), 0);
        assertEquals(camera0, scene.getCameras().get(0));
        assertEquals("Camera0", ((MetaData) scene.getCameras().get(0)).getAttribute("name"));

        // Perform test 3.
        SceneFactory.updateFromSource(scene, new FileInputStream(new File("src/com/se/simplicity/util/test/scene/triangleCameraNode.xml")));

        // Verify test 3 results.
        assertEquals(1, scene.getCameras().size(), 0);
        assertEquals(camera0, scene.getCameras().get(0));
        assertEquals(2, scene.getCameras().get(0).getNode().getID(), 0);

        // Perform test 4.
        SceneFactory.updateFromSource(scene, new FileInputStream(new File("src/com/se/simplicity/util/test/scene/triangleTwoCamerasDuplicate.xml")));

        // Verify test 4 results.
        assertEquals(1, scene.getCameras().size(), 0);
        assertEquals(camera0, scene.getCameras().get(0));
        assertEquals(1, scene.getCameras().get(0).getNode().getID(), 0);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.util.scene.SceneFactory#updateFromSource(Scene, InputStream) updateFromSource(Scene,
     * InputStream)}, specifically the functionality that updates <code>Light</code>s.
     * 
     * @throws FileNotFoundException Thrown if source file is not found.
     */
    @Test
    public void updateFromSourceLight() throws FileNotFoundException
    {
        // Initialise test environment.
        Scene scene = SceneFactory.loadFromSource(new FileInputStream(new File("src/com/se/simplicity/util/test/scene/triangle.xml")));
        Light light0 = scene.getLights().get(0);

        // Perform test 1.
        SceneFactory.updateFromSource(scene, new FileInputStream(new File("src/com/se/simplicity/util/test/scene/triangleTwoLights.xml")));

        // Verify test 1 results.
        assertEquals(2, scene.getLights().size(), 0);
        assertEquals(light0, scene.getLights().get(0));
        assertEquals("Light0", ((MetaData) scene.getLights().get(0)).getAttribute("name"));
        assertEquals("Light1", ((MetaData) scene.getLights().get(1)).getAttribute("name"));

        // Perform test 2.
        SceneFactory.updateFromSource(scene, new FileInputStream(new File("src/com/se/simplicity/util/test/scene/triangle.xml")));

        // Verify test 2 results.
        assertEquals(1, scene.getLights().size(), 0);
        assertEquals(light0, scene.getLights().get(0));
        assertEquals("Light0", ((MetaData) scene.getLights().get(0)).getAttribute("name"));

        // Perform test 3.
        SceneFactory.updateFromSource(scene, new FileInputStream(new File("src/com/se/simplicity/util/test/scene/triangleLightNode.xml")));

        // Verify test 3 results.
        assertEquals(1, scene.getLights().size(), 0);
        assertEquals(light0, scene.getLights().get(0));
        assertEquals(1, scene.getLights().get(0).getNode().getID(), 0);

        // Perform test 4.
        SceneFactory.updateFromSource(scene, new FileInputStream(new File("src/com/se/simplicity/util/test/scene/triangleTwoLightsDuplicate.xml")));

        // Verify test 4 results.
        assertEquals(1, scene.getLights().size(), 0);
        assertEquals(light0, scene.getLights().get(0));
        assertEquals(2, scene.getLights().get(0).getNode().getID(), 0);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.util.scene.SceneFactory.loadFromSource loadFromSource()}, specifically the functionality that
     * updates <code>Node</code>s.
     * </p>
     * 
     * @throws FileNotFoundException Thrown if source file is not found.
     */
    @Test
    public void updateFromSourceNodes() throws FileNotFoundException
    {
        // Initialise test environment.
        Scene scene = SceneFactory.loadFromSource(new FileInputStream(new File("src/com/se/simplicity/util/test/scene/triangle.xml")));
        Node cameraNode = scene.getSceneGraph().getSubgraphRoots().get(0);
        Node lightNode = scene.getSceneGraph().getSubgraphRoots().get(1);

        // Perform test 1.
        SceneFactory.updateFromSource(scene, new FileInputStream(new File("src/com/se/simplicity/util/test/scene/triangleNodes.xml")));

        // Verify test 1 results.
        Node node0 = scene.getSceneGraph().getRoot();
        assertEquals(2, scene.getSceneGraph().getSubgraphRoots().size(), 0);

        MetaDataNode node1 = (MetaDataNode) node0.getChildren().get(0);
        assertEquals(cameraNode, node1);
        assertEquals(SimpleNode.class, node1.getWrappedNode().getClass());
        assertEquals("Camera", node1.getAttribute("name"));

        TranslationVectorf translation1 = node1.getTransformation().getTranslation();
        assertEquals(0.0f, translation1.getX(), 0.0f);
        assertEquals(0.0f, translation1.getY(), 0.0f);
        assertEquals(5.0f, translation1.getZ(), 0.0f);
        assertEquals(1.0f, translation1.getW(), 0.0f);

        MetaDataNode node2 = (MetaDataNode) node0.getChildren().get(1);
        assertEquals(lightNode, node2);
        assertEquals(SimpleNode.class, node2.getWrappedNode().getClass());
        assertEquals("Light", node2.getAttribute("name"));

        TranslationVectorf translation2 = node2.getTransformation().getTranslation();
        assertEquals(1.0f, translation2.getX(), 0.0f);
        assertEquals(5.0f, translation2.getY(), 0.0f);
        assertEquals(-1.0f, translation2.getZ(), 0.0f);
        assertEquals(1.0f, translation2.getW(), 0.0f);

        // Perform test 2.
        SceneFactory.updateFromSource(scene, new FileInputStream(new File("src/com/se/simplicity/util/test/scene/triangle.xml")));

        // Verify test 2 results.
        node0 = scene.getSceneGraph().getRoot();
        assertEquals(3, scene.getSceneGraph().getSubgraphRoots().size(), 0);

        node1 = (MetaDataNode) node0.getChildren().get(0);
        assertEquals(cameraNode, node1);
        assertEquals(SimpleNode.class, node1.getWrappedNode().getClass());
        assertEquals("Camera", node1.getAttribute("name"));

        translation1 = node1.getTransformation().getTranslation();
        assertEquals(0.0f, translation1.getX(), 0.0f);
        assertEquals(0.0f, translation1.getY(), 0.0f);
        assertEquals(5.0f, translation1.getZ(), 0.0f);
        assertEquals(1.0f, translation1.getW(), 0.0f);

        node2 = (MetaDataNode) node0.getChildren().get(1);
        assertEquals(lightNode, node2);
        assertEquals(SimpleNode.class, node2.getWrappedNode().getClass());
        assertEquals("Light", node2.getAttribute("name"));

        translation2 = node2.getTransformation().getTranslation();
        assertEquals(0.0f, translation2.getX(), 0.0f);
        assertEquals(5.0f, translation2.getY(), 0.0f);
        assertEquals(0.0f, translation2.getZ(), 0.0f);
        assertEquals(1.0f, translation2.getW(), 0.0f);

        MetaDataNode node3 = (MetaDataNode) node0.getChildren().get(2);
        assertEquals(SimpleModelNode.class, node3.getWrappedNode().getClass());
        assertEquals("Triangle", node3.getAttribute("name"));

        VertexGroup vertexGroup = node3.getVertexGroup();
        assertEquals(ArrayVG.class, vertexGroup.getClass());

        float[] colours = ((ArrayVG) vertexGroup).getColours();
        assertEquals(1.0f, colours[0], 0.0f);
        assertEquals(0.0f, colours[1], 0.0f);
        assertEquals(0.0f, colours[2], 0.0f);
        assertEquals(0.0f, colours[3], 0.0f);
        assertEquals(1.0f, colours[4], 0.0f);
        assertEquals(0.0f, colours[5], 0.0f);
        assertEquals(0.0f, colours[6], 0.0f);
        assertEquals(0.0f, colours[7], 0.0f);
        assertEquals(1.0f, colours[8], 0.0f);

        float[] normals = ((ArrayVG) vertexGroup).getNormals();
        assertEquals(0.0f, normals[0], 0.0f);
        assertEquals(0.0f, normals[1], 0.0f);
        assertEquals(1.0f, normals[2], 0.0f);
        assertEquals(0.0f, normals[3], 0.0f);
        assertEquals(0.0f, normals[4], 0.0f);
        assertEquals(1.0f, normals[5], 0.0f);
        assertEquals(0.0f, normals[6], 0.0f);
        assertEquals(0.0f, normals[7], 0.0f);
        assertEquals(1.0f, normals[8], 0.0f);

        float[] vertices = ((ArrayVG) vertexGroup).getVertices();
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
     * Unit test the method {@link com.se.simplicity.util.scene.SceneFactory#writeToSource(Scene) writeToSource(Scene)}, specifically the
     * functionality that creates source from a <code>Camera</code>.
     * 
     * @throws ParserConfigurationException Thrown if the written source cannot be parsed.
     * @throws IOException Thrown if there is an error with the piped streams.
     * @throws SAXException Thrown if the written source cannot be parsed.
     * @throws InterruptedException
     */
    @Test
    public void writeToSourceCamera() throws SAXException, IOException, ParserConfigurationException, InterruptedException
    {
        // Create dependencies
        Scene mockScene = createMock(Scene.class);

        Camera mockCamera = createMock(Camera.class);
        ArrayList<Camera> cameras = new ArrayList<Camera>();
        cameras.add(mockCamera);

        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        Node mockNode = createMock(Node.class);

        // Dictate correct behaviour.
        expect(mockScene.getCameras()).andStubReturn(cameras);
        expect(mockCamera.getNode()).andStubReturn(mockNode);
        expect(mockScene.getLights()).andStubReturn(new ArrayList<Light>());
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getSubgraphRoots()).andStubReturn(new ArrayList<Node>());
        expect(mockNode.getID()).andStubReturn(0);
        replay(mockScene, mockCamera, mockSceneGraph, mockNode);

        // Perform test.
        Document source = DocumentBuilderFactory.newInstance().newDocumentBuilder().newDocument();
        ;
        SceneFactory.writeToSource(mockScene, source);

        // Verify test results.
        NodeList cameraElements = source.getElementsByTagName("camera");
        assertEquals(1, cameraElements.getLength(), 0);
        Element cameraElement = (Element) cameraElements.item(0);
        assertEquals("$Proxy5", cameraElement.getAttribute("class"));
        assertNull(cameraElement.getAttributes().getNamedItem("name"));
        assertEquals("0", cameraElement.getAttribute("node"));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.util.scene.SceneFactory#writeToSource(Scene) writeToSource(Scene)}, specifically the
     * functionality that creates source from a <code>Light</code>.
     * 
     * @throws ParserConfigurationException Thrown if the written source cannot be parsed.
     * @throws IOException Thrown if there is an error with the piped streams.
     * @throws SAXException Thrown if the written source cannot be parsed.
     */
    @Test
    public void writeToSourceLight() throws SAXException, IOException, ParserConfigurationException
    {
        // Create dependencies
        Scene mockScene = createMock(Scene.class);

        Light mockLight = createMock(Light.class);
        ArrayList<Light> lights = new ArrayList<Light>();
        lights.add(mockLight);

        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        Node mockNode = createMock(Node.class);

        // Dictate correct behaviour.
        expect(mockScene.getCameras()).andStubReturn(new ArrayList<Camera>());
        expect(mockScene.getLights()).andStubReturn(lights);
        expect(mockLight.getNode()).andStubReturn(mockNode);
        expect(mockLight.getAmbientLight()).andStubReturn(new float[] {0.1f, 0.1f, 0.1f, 1.0f});
        expect(mockLight.getDiffuseLight()).andStubReturn(new float[] {0.1f, 0.1f, 0.1f, 1.0f});
        expect(mockLight.getSpecularLight()).andStubReturn(new float[] {0.1f, 0.1f, 0.1f, 1.0f});
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getSubgraphRoots()).andStubReturn(new ArrayList<Node>());
        expect(mockNode.getID()).andStubReturn(0);
        replay(mockScene, mockLight, mockSceneGraph, mockNode);

        // Perform test.
        Document source = DocumentBuilderFactory.newInstance().newDocumentBuilder().newDocument();
        SceneFactory.writeToSource(mockScene, source);

        // Verify test results.
        NodeList lightElements = source.getElementsByTagName("light");
        assertEquals(1, lightElements.getLength(), 0);
        Element lightElement = (Element) lightElements.item(0);
        assertEquals("$Proxy8", lightElement.getAttribute("class"));
        assertNull(lightElement.getAttributes().getNamedItem("name"));
        assertEquals("0", lightElement.getAttribute("node"));

        Element ambientElement = (Element) source.getElementsByTagName("ambient").item(0);
        assertEquals("0.1, 0.1, 0.1, 1.0", ambientElement.getAttribute("colour"));
        Element diffuseElement = (Element) source.getElementsByTagName("diffuse").item(0);
        assertEquals("0.1, 0.1, 0.1, 1.0", diffuseElement.getAttribute("colour"));
        Element specularElement = (Element) source.getElementsByTagName("specular").item(0);
        assertEquals("0.1, 0.1, 0.1, 1.0", specularElement.getAttribute("colour"));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.util.scene.SceneFactory#writeToSource(Scene) writeToSource(Scene)}, specifically the
     * functionality that creates source from a <code>MetaDataCamera</code>.
     * 
     * @throws ParserConfigurationException Thrown if the written source cannot be parsed.
     * @throws IOException Thrown if there is an error with the piped streams.
     * @throws SAXException Thrown if the written source cannot be parsed.
     */
    @Test
    public void writeToSourceMetaDataCamera() throws SAXException, IOException, ParserConfigurationException
    {
        // Create dependencies
        Scene mockScene = createMock(Scene.class);

        Camera camera = new SimpleJOGLCamera();
        MetaDataCamera mockMetaDataCamera = createMock(MetaDataCamera.class);
        ArrayList<Camera> cameras = new ArrayList<Camera>();
        cameras.add(mockMetaDataCamera);

        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        Node mockNode = createMock(Node.class);

        // Dictate correct behaviour.
        expect(mockScene.getCameras()).andStubReturn(cameras);
        expect(mockMetaDataCamera.getAttribute("name")).andStubReturn("Test");
        expect(mockMetaDataCamera.getNode()).andStubReturn(mockNode);
        expect(mockMetaDataCamera.getWrappedCamera()).andStubReturn(camera);
        expect(mockScene.getLights()).andStubReturn(new ArrayList<Light>());
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getSubgraphRoots()).andStubReturn(new ArrayList<Node>());
        expect(mockNode.getID()).andStubReturn(0);
        replay(mockScene, mockMetaDataCamera, mockSceneGraph, mockNode);

        // Perform test.
        Document source = DocumentBuilderFactory.newInstance().newDocumentBuilder().newDocument();
        SceneFactory.writeToSource(mockScene, source);

        // Verify test results.
        NodeList cameraElements = source.getElementsByTagName("camera");
        Element cameraElement = (Element) cameraElements.item(0);
        assertEquals("com.se.simplicity.jogl.rendering.SimpleJOGLCamera", cameraElement.getAttribute("class"));
        assertEquals("Test", cameraElement.getAttribute("name"));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.util.scene.SceneFactory#writeToSource(Scene) writeToSource(Scene)}, specifically the
     * functionality that creates source from a <code>MetaDataLight</code>.
     * 
     * @throws ParserConfigurationException Thrown if the written source cannot be parsed.
     * @throws IOException Thrown if there is an error with the piped streams.
     * @throws SAXException Thrown if the written source cannot be parsed.
     */
    @Test
    public void writeToSourceMetaDataLight() throws SAXException, IOException, ParserConfigurationException
    {
        // Create dependencies
        Scene mockScene = createMock(Scene.class);

        Light light = new SimpleJOGLLight();
        MetaDataLight mockMetaDataLight = createMock(MetaDataLight.class);
        ArrayList<Light> lights = new ArrayList<Light>();
        lights.add(mockMetaDataLight);

        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        Node mockNode = createMock(Node.class);

        // Dictate correct behaviour.
        expect(mockScene.getCameras()).andStubReturn(new ArrayList<Camera>());
        expect(mockScene.getLights()).andStubReturn(lights);
        expect(mockMetaDataLight.getAttribute("name")).andStubReturn("Test");
        expect(mockMetaDataLight.getNode()).andStubReturn(mockNode);
        expect(mockMetaDataLight.getWrappedLight()).andStubReturn(light);
        expect(mockMetaDataLight.getAmbientLight()).andStubReturn(new float[] {0.1f, 0.1f, 0.1f, 1.0f});
        expect(mockMetaDataLight.getDiffuseLight()).andStubReturn(new float[] {0.1f, 0.1f, 0.1f, 1.0f});
        expect(mockMetaDataLight.getSpecularLight()).andStubReturn(new float[] {0.1f, 0.1f, 0.1f, 1.0f});
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getSubgraphRoots()).andStubReturn(new ArrayList<Node>());
        expect(mockNode.getID()).andStubReturn(0);
        replay(mockScene, mockMetaDataLight, mockSceneGraph, mockNode);

        // Perform test.
        Document source = DocumentBuilderFactory.newInstance().newDocumentBuilder().newDocument();
        SceneFactory.writeToSource(mockScene, source);

        // Verify test results.
        NodeList lightElements = source.getElementsByTagName("light");
        Element lightElement = (Element) lightElements.item(0);
        assertEquals("com.se.simplicity.jogl.rendering.SimpleJOGLLight", lightElement.getAttribute("class"));
        assertEquals("Test", lightElement.getAttribute("name"));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.util.scene.SceneFactory#writeToSource(Scene) writeToSource(Scene)}, specifically the
     * functionality that creates source from a graph of <code>MetaDataNode</code>s.
     * 
     * @throws ParserConfigurationException Thrown if the written source cannot be parsed.
     * @throws IOException Thrown if there is an error with the piped streams.
     * @throws SAXException Thrown if the written source cannot be parsed.
     */
    @Test
    public void writeToSourceMetaDataNodes() throws SAXException, IOException, ParserConfigurationException
    {
        // Create dependencies
        Scene mockScene = createMock(Scene.class);

        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        NodeHierarchy nodes = new NodeHierarchy();
        nodes.setBasicNodeHierarchy();

        MetaDataSceneGraph metaDataSceneGraph = new MetaDataSceneGraph(new SimpleSceneGraph());
        metaDataSceneGraph.addSubgraph(nodes.node1);

        // Dictate correct behaviour.
        expect(mockScene.getCameras()).andStubReturn(new ArrayList<Camera>());
        expect(mockScene.getLights()).andStubReturn(new ArrayList<Light>());
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getSubgraphRoots()).andStubReturn(metaDataSceneGraph.getSubgraphRoots());
        replay(mockScene, mockSceneGraph);

        // Perform test.
        Document source = DocumentBuilderFactory.newInstance().newDocumentBuilder().newDocument();
        SceneFactory.writeToSource(mockScene, source);

        // Verify test results.
        NodeList nodeElements = source.getElementsByTagName("node");

        Element node0Element = (Element) nodeElements.item(1);
        assertEquals("com.se.simplicity.scenegraph.SimpleNode", node0Element.getAttribute("class"));
        assertEquals("SimpleNode1", node0Element.getAttribute("name"));

        Element node1Element = (Element) nodeElements.item(2);
        assertEquals("com.se.simplicity.scenegraph.SimpleNode", node1Element.getAttribute("class"));
        assertEquals("SimpleNode2", node1Element.getAttribute("name"));

        Element node2Element = (Element) nodeElements.item(3);
        assertEquals("com.se.simplicity.scenegraph.model.SimpleModelNode", node2Element.getAttribute("class"));
        assertEquals("SimpleModelNode3", node2Element.getAttribute("name"));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.util.scene.SceneFactory#writeToSource(Scene) writeToSource(Scene)}, specifically the
     * functionality that creates source from a graph of <code>Node</code>s.
     * 
     * @throws ParserConfigurationException Thrown if the written source cannot be parsed.
     * @throws IOException Thrown if there is an error with the piped streams.
     * @throws SAXException Thrown if the written source cannot be parsed.
     */
    @Test
    public void writeToSourceNodes() throws SAXException, IOException, ParserConfigurationException
    {
        // Create dependencies
        Scene mockScene = createMock(Scene.class);

        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        NodeHierarchy nodes = new NodeHierarchy();
        nodes.setBasicNodeHierarchy();
        ArrayList<Node> subgraphRoots = new ArrayList<Node>();
        subgraphRoots.add(nodes.node1);

        // Dictate correct behaviour.
        expect(mockScene.getCameras()).andStubReturn(new ArrayList<Camera>());
        expect(mockScene.getLights()).andStubReturn(new ArrayList<Light>());
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getSubgraphRoots()).andStubReturn(subgraphRoots);
        replay(mockScene, mockSceneGraph);

        // Perform test.
        Document source = DocumentBuilderFactory.newInstance().newDocumentBuilder().newDocument();
        SceneFactory.writeToSource(mockScene, source);

        // Verify test results.
        NodeList nodeElements = source.getElementsByTagName("node");
        assertEquals(4, nodeElements.getLength(), 0);

        Element node0Element = (Element) nodeElements.item(1);
        assertEquals("com.se.simplicity.scenegraph.SimpleNode", node0Element.getAttribute("class"));
        assertNull(node0Element.getAttributes().getNamedItem("name"));
        assertEquals("0", node0Element.getAttribute("id"));

        Element nodeOContentElement = (Element) node0Element.getChildNodes().item(0);
        assertEquals("transformation", nodeOContentElement.getAttribute("type"));
        Element nodeOTranslationElement = (Element) nodeOContentElement.getChildNodes().item(0);
        assertEquals("0.0, 0.0, 0.0, 1.0", nodeOTranslationElement.getAttribute("vector"));
        Element nodeORotationElement = (Element) nodeOContentElement.getChildNodes().item(1);
        // TODO fix after fixing Y axis rotation thing!
        // assertEquals("0.0, 0.0, 0.0", nodeORotationElement.getAttribute("axisAngles"));

        Element node1Element = (Element) nodeElements.item(2);
        assertEquals("com.se.simplicity.scenegraph.SimpleNode", node1Element.getAttribute("class"));
        assertNull(node1Element.getAttributes().getNamedItem("name"));
        assertEquals("1", node1Element.getAttribute("id"));

        Element node1ContentElement = (Element) node1Element.getChildNodes().item(0);
        assertEquals("transformation", node1ContentElement.getAttribute("type"));
        Element node1TranslationElement = (Element) node1ContentElement.getChildNodes().item(0);
        assertEquals("0.0, 0.0, 0.0, 1.0", node1TranslationElement.getAttribute("vector"));
        Element node1RotationElement = (Element) node1ContentElement.getChildNodes().item(1);

        Element node2Element = (Element) nodeElements.item(3);
        assertEquals("com.se.simplicity.scenegraph.model.SimpleModelNode", node2Element.getAttribute("class"));
        assertNull(node2Element.getAttributes().getNamedItem("name"));
        assertEquals("2", node2Element.getAttribute("id"));

        Element node2Content0Element = (Element) node2Element.getChildNodes().item(0);
        assertEquals("transformation", node2Content0Element.getAttribute("type"));
        Element node2TranslationElement = (Element) node2Content0Element.getChildNodes().item(0);
        assertEquals("0.0, 0.0, 0.0, 1.0", node2TranslationElement.getAttribute("vector"));
        Element node2RotationElement = (Element) node2Content0Element.getChildNodes().item(1);

        Element node2Content1Element = (Element) node2Element.getChildNodes().item(1);
        assertEquals("com.se.simplicity.model.ArrayVG", node2Content1Element.getAttribute("class"));
        assertEquals("vertexGroup", node2Content1Element.getAttribute("type"));
        Element node2Vertex0Element = (Element) node2Content1Element.getChildNodes().item(0);
        assertEquals("1.0, 1.0, 1.0", node2Vertex0Element.getAttribute("colour"));
        assertEquals("0.0, 0.0, 1.0", node2Vertex0Element.getAttribute("normal"));
        assertEquals("-1.0, 0.0, 0.0", node2Vertex0Element.getAttribute("vertex"));
        Element node2Vertex1Element = (Element) node2Content1Element.getChildNodes().item(1);
        assertEquals("1.0, 1.0, 1.0", node2Vertex1Element.getAttribute("colour"));
        assertEquals("0.0, 0.0, 1.0", node2Vertex1Element.getAttribute("normal"));
        assertEquals("0.0, 1.0, 0.0", node2Vertex1Element.getAttribute("vertex"));
        Element node2Vertex2Element = (Element) node2Content1Element.getChildNodes().item(2);
        assertEquals("1.0, 1.0, 1.0", node2Vertex2Element.getAttribute("colour"));
        assertEquals("0.0, 0.0, 1.0", node2Vertex2Element.getAttribute("normal"));
        assertEquals("1.0, 0.0, 0.0", node2Vertex2Element.getAttribute("vertex"));
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
    public void writeToSourceRootTags() throws SAXException, IOException, ParserConfigurationException
    {
        // Create dependencies
        Scene mockScene = createMock(Scene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);

        // Dictate correct behaviour.
        expect(mockScene.getCameras()).andStubReturn(new ArrayList<Camera>());
        expect(mockScene.getLights()).andStubReturn(new ArrayList<Light>());
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getSubgraphRoots()).andStubReturn(new ArrayList<Node>());
        replay(mockScene, mockSceneGraph);

        // Perform test.
        Document source = DocumentBuilderFactory.newInstance().newDocumentBuilder().newDocument();
        SceneFactory.writeToSource(mockScene, source);

        // Verify test results.
        assertEquals(1, source.getElementsByTagName("simplicity").getLength(), 0);
        assertEquals(1, source.getElementsByTagName("scene").getLength(), 0);
        assertEquals(1, source.getElementsByTagName("sceneGraph").getLength(), 0);
        assertEquals(1, source.getElementsByTagName("node").getLength(), 0);
    }
}
