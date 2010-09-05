/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.util;

import java.io.File;

import com.se.simplicity.model.ArrayVG;
import com.se.simplicity.model.Model;
import com.se.simplicity.model.VertexGroup;
import com.se.simplicity.rendering.Light;
import com.se.simplicity.scene.Scene;
import com.se.simplicity.scenegraph.SceneGraph;
import com.se.simplicity.scenegraph.SimpleNode;
import com.se.simplicity.scenegraph.model.SimpleModelNode;
import com.se.simplicity.vector.SimpleTranslationVectorf4;

public class SceneFactory
{
    public static void addXSceneAtOrigin(SceneGraph sceneGraph)
    {
        try
        {
            // Import the X model.
            Model xModel = ModelFactory.importOBJFile(new File("/home/simple/workspace/com.se.simplicity.editor/objects/models/x.obj"));

            // Colour in the X model blue.
            float[] xNodeColors = ((ArrayVG) xModel).getColours();
            for (int index = 0; index < xNodeColors.length; index += 3)
            {
                xNodeColors[index] = 0.0f;
                xNodeColors[index + 1] = 0.0f;
                xNodeColors[index + 2] = 0.85f;
            }

            SimpleModelNode xNode = new SimpleModelNode();
            xNode.setModel(xModel);
            sceneGraph.addSubgraph(xNode);
        }
        catch (Exception ex)
        {
            System.out.println("Could not add X scene to SceneGraph: " + ex.getMessage());
            ex.printStackTrace();
        }

        SimpleModelNode umbrellaNode = new SimpleModelNode();
        umbrellaNode.getTransformation().translate(new SimpleTranslationVectorf4(0.0f, -5.0f, 0.0f, 1.0f));
        umbrellaNode.setModel(createUmbrellaVertexGroup());

        sceneGraph.addSubgraph(umbrellaNode);
    }

    protected static VertexGroup createUmbrellaVertexGroup()
    {
        ArrayVG vertexGroup = new ArrayVG();

        vertexGroup.setVertices(new float[] {0.0f, 0.0f, 0.0f, -20.0f, 0.0f, -40.0f, 20.0f, 0.0f, -40.0f, 0.0f, 0.0f, 0.0f, 20.0f, 0.0f, -40.0f,
                40.0f, 0.0f, -20.0f, 0.0f, 0.0f, 0.0f, 40.0f, 0.0f, -20.0f, 40.0f, 0.0f, 20.0f, 0.0f, 0.0f, 0.0f, 40.0f, 0.0f, 20.0f, 20.0f, 0.0f,
                40.0f, 0.0f, 0.0f, 0.0f, 20.0f, 0.0f, 40.0f, -20.0f, 0.0f, 40.0f, 0.0f, 0.0f, 0.0f, -20.0f, 0.0f, 40.0f, -40.0f, 0.0f, 20.0f, 0.0f,
                0.0f, 0.0f, -40.0f, 0.0f, 20.0f, -40.0f, 0.0f, -20.0f, 0.0f, 0.0f, 0.0f, -40.0f, 0.0f, -20.0f, -20.0f, 0.0f, -40.0f});
        vertexGroup.setColours(new float[] {1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
                0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f});
        vertexGroup.setNormals(new float[] {0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
                0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
                0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
                1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f});

        return (vertexGroup);
    }

    public static void addSimpleLightingAtOrigin(Scene scene, Light light)
    {
        light.setAmbientLight(new float[] {0.1f, 0.1f, 0.1f});
        light.setDiffuseLight(new float[] {0.1f, 0.1f, 0.1f});
        light.setSpecularLight(new float[] {0.1f, 0.1f, 0.1f});

        light.setNode(new SimpleNode());
        light.getNode().getTransformation().translate(new SimpleTranslationVectorf4(0.0f, 0.0f, 20.0f, 1.0f));

        scene.addLight(light);
        scene.getSceneGraph().addSubgraph(light.getNode());
    }
}
