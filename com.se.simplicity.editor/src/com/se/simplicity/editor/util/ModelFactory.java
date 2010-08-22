/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.util;

// J2SE imports.
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

import com.se.simplicity.model.ArrayVG;
import com.se.simplicity.model.Model;
import com.se.simplicity.model.SimpleModel;
import com.se.simplicity.scenegraph.model.ModelNode;
import com.se.simplicity.scenegraph.model.SimpleModelNode;

/**
 * <p>
 * Creates internal model structures from various standard model file formats.
 * </p>
 * 
 * <p>
 * Copyright (c) 2007, simple entertainment
 * </p>
 * 
 * @author Gary Buyn
 */
public class ModelFactory
{
	/**
	 * <p>
	 * Creates an internal model structure from an .OBJ file.
	 * </p>
	 * 
	 * </p>
	 * The model described in the .OBJ file must be constructed entirely from triangle polygons.
	 * </p>
	 * 
	 * @param file The .OBJ file to create an internal model structure for.
	 * 
	 * @throws IOException Thrown if the filename is invalid.
	 * 
	 * @return The internal model structure.
	 */
	public static Model importOBJFile(File file) throws IOException
	{		
		// Open the file for reading with a buffer.
		BufferedReader reader = new BufferedReader(new FileReader(file));

		// Read the vertices and normals from the file into lists.
		String currentLine;
		String splitLine[];
		ArrayList<float[]> vertexList = new ArrayList<float[]>();
		ArrayList<float[]> normalList = new ArrayList<float[]>();
		int faces = 0;
		while ((currentLine = reader.readLine()) != null)
		{
			splitLine = currentLine.split(" ");

			if (splitLine[0].compareTo("v") == 0)
			{
				vertexList.add(new float[] { Float.parseFloat(splitLine[1]), Float.parseFloat(splitLine[2]),
						Float.parseFloat(splitLine[3]) });
			}
			else if (splitLine[0].compareTo("vn") == 0)
			{
				normalList.add(new float[] { Float.parseFloat(splitLine[1]), Float.parseFloat(splitLine[2]),
						Float.parseFloat(splitLine[3]) });
			}
			else if (splitLine[0].compareTo("f") == 0)
			{
				faces++;
			}
		}

		// Create the arrays for vertices, normals and triangles.
		float[] vertices = new float[faces * 9];
		float[] normals = new float[faces * 9];
		float[] colours = new float[faces * 9];

		// Read the faces from the file and populate the arrays.
		reader = new BufferedReader(new FileReader(file));

		int vertex = 0;
		String splitIndices[];
		while ((currentLine = reader.readLine()) != null)
		{
			splitLine = currentLine.split(" ");

			if (splitLine[0].compareTo("f") == 0)
			{
				for (int index = 1; index < splitLine.length; index++)
				{
					splitIndices = splitLine[index].split("/");

					System.arraycopy(vertexList.get(Integer.parseInt(splitIndices[0]) - 1), 0, vertices, vertex, 3);
					System.arraycopy(normalList.get(Integer.parseInt(splitIndices[2]) - 1), 0, normals, vertex, 3);
					colours[vertex] = 1.0f;
					colours[vertex + 1] = 1.0f;
					colours[vertex + 2] = 1.0f;

					vertex += 3;
				}
			}
		}

		// Build the internal model structure.
		ArrayVG vertexGroup = new ArrayVG();
		vertexGroup.setVertices(vertices);
		vertexGroup.setNormals(normals);
		vertexGroup.setColours(colours);
		
		ModelNode root = new SimpleModelNode();
		root.setVertexGroup(vertexGroup);
		SimpleModel model = new SimpleModel();
		model.setRoot(root);
		root.setModel(model);

		return (model);
	}
}
