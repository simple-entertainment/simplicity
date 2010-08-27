/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.util.test.scene;

import static org.junit.Assert.assertEquals;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

import org.junit.Test;

import com.se.simplicity.model.ArrayVG;
import com.se.simplicity.model.VertexGroup;
import com.se.simplicity.scene.Scene;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.SimpleNode;
import com.se.simplicity.scenegraph.model.SimpleModelNode;
import com.se.simplicity.util.metadata.MetaData;
import com.se.simplicity.util.metadata.scenegraph.MetaDataNode;
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
     * Unit test the method {@link com.se.simplicity.util.scene.SceneFactory.loadFromSource loadFromSource()}.
     * </p>
     * 
     * @throws FileNotFoundException Thrown if source file is not found.
     */
    @Test
    public void loadFromSource() throws FileNotFoundException
    {
        Scene scene = SceneFactory.loadFromSource(new FileInputStream(new File("src/com/se/simplicity/util/test/scene/triangle.xml")));

        assertEquals(1, scene.getCameras().size(), 0);
        assertEquals("Camera0", ((MetaData) scene.getCameras().get(0)).getAttribute("name"));
        assertEquals("Camera", ((MetaData) scene.getCameras().get(0).getNode()).getAttribute("name"));

        assertEquals(1, scene.getLights().size(), 0);
        assertEquals("Light0", ((MetaData) scene.getLights().get(0)).getAttribute("name"));
        assertEquals("Light", ((MetaData) scene.getLights().get(0).getNode()).getAttribute("name"));

        float[] ambientLight = scene.getLights().get(0).getAmbientLight();
        assertEquals(0.1f, ambientLight[0], 0.0f);
        assertEquals(0.1f, ambientLight[1], 0.0f);
        assertEquals(0.1f, ambientLight[2], 0.0f);

        float[] diffuseLight = scene.getLights().get(0).getDiffuseLight();
        assertEquals(0.1f, diffuseLight[0], 0.0f);
        assertEquals(0.1f, diffuseLight[1], 0.0f);
        assertEquals(0.1f, diffuseLight[2], 0.0f);

        float[] specularLight = scene.getLights().get(0).getSpecularLight();
        assertEquals(0.1f, specularLight[0], 0.0f);
        assertEquals(0.1f, specularLight[1], 0.0f);
        assertEquals(0.1f, specularLight[2], 0.0f);

        Node node0 = scene.getSceneGraph().getRoot();

        MetaDataNode node1 = (MetaDataNode) node0.getChildren().get(0);
        assertEquals(SimpleNode.class, node1.getWrappedNode().getClass());
        assertEquals("Camera", node1.getAttribute("name"));

        TranslationVectorf translation1 = node1.getTransformation().getTranslation();
        assertEquals(0.0f, translation1.getX(), 0.0f);
        assertEquals(0.0f, translation1.getY(), 0.0f);
        assertEquals(5.0f, translation1.getZ(), 0.0f);

        MetaDataNode node2 = (MetaDataNode) node0.getChildren().get(1);
        assertEquals(SimpleNode.class, node2.getWrappedNode().getClass());
        assertEquals("Light", node2.getAttribute("name"));

        TranslationVectorf translation2 = node2.getTransformation().getTranslation();
        assertEquals(0.0f, translation2.getX(), 0.0f);
        assertEquals(5.0f, translation2.getY(), 0.0f);
        assertEquals(0.0f, translation2.getZ(), 0.0f);

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
     * Unit test the method {@link com.se.simplicity.util.scene.SceneFactory.loadFromSource loadFromSource()} with the special
     * condition that the source file contains a camera definition with no class specified.
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
            assertEquals("Invliad Light definition: Does not specify a class.", e.getMessage());
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
        assertEquals("Node (0)", node1.getAttribute("name"));
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
}
