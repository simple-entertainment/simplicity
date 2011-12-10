/*
 * Copyright © Simple Entertainment Limited 2011
 *
 * This file is part of The Simplicity Engine.
 *
 * The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see
 * <http://www.gnu.org/licenses/>.
 */
#include <boost/math/constants/constants.hpp>

#include <simplicity/math/SimpleRGBAColourVector4.h>
#include <simplicity/math/SimpleTransformationMatrix44.h>
#include <simplicity/math/SimpleTranslationVector4.h>
#include <simplicity/model/VectorVG.h>
#include <simplicity/scene/model/SimpleModelNode.h>
#include <simplicity/scene/SimpleNode.h>

#include <simplicity/opengl/model/shape/GLUSphere.h>
#include <simplicity/opengl/rendering/SimpleOpenGLCamera.h>
#include <simplicity/opengl/rendering/SimpleOpenGLLight.h>

#include "PathFindingDemo.h"

using namespace boost;
using namespace boost::math::constants;
using namespace simplicity::opengl;
using namespace std;

namespace simplicity
{
	void PathFindingDemo::addBackground(shared_ptr<Node> parentNode)
	{
		bool darkTile;

		for (unsigned int column = 0; column < 10; column++)
		{
			darkTile = (column % 2 == 0);

			for (unsigned int row = 0; row < 10; row++)
			{
				shared_ptr<Node> tileNode = createGreySquareOnXZPlane(darkTile);
				tileNode->getTransformation().translate(
					SimpleTranslationVector4<float>(-5.0f + column, 0.0f, 5.0f - row, 1.0f));
				parentNode->addChild(tileNode);

				darkTile = !darkTile;
			}
		}
	}

	shared_ptr<Camera> PathFindingDemo::addCamera(shared_ptr<Node> parentNode)
	{
		shared_ptr<SimpleOpenGLCamera> camera(new SimpleOpenGLCamera);
		camera->setProjectionMode(Camera::ORTHOGONAL);
		camera->setFrameWidth(10.0f);
		camera->setFrameAspectRatio(1.0f);

		shared_ptr<SimpleNode> cameraNode(new SimpleNode);
		cameraNode->getTransformation().translate(SimpleTranslationVector4<float>(0.0f, 10.0f, 1.0f, 1.0f));
		cameraNode->getTransformation().rotate(pi<float>() * 1.5f,
			SimpleTranslationVector4<float>(1.0f, 0.0f, 0.0f, 1.0f));
		camera->setNode(cameraNode);
		parentNode->addChild(cameraNode);

		return (camera);
	}

	shared_ptr<Light> PathFindingDemo::addLight(shared_ptr<Node> parentNode)
	{
		shared_ptr<SimpleOpenGLLight> light(new SimpleOpenGLLight);
		light->setAmbientLight(
			shared_ptr<SimpleRGBAColourVector4<float>
				> (new SimpleRGBAColourVector4<float>(0.25f, 0.25f, 0.25f, 1.0f)));
		light->setDiffuseLight(
			shared_ptr<SimpleRGBAColourVector4<float>
				> (new SimpleRGBAColourVector4<float>(0.25f, 0.25f, 0.25f, 1.0f)));
		light->setSpecularLight(
			shared_ptr<SimpleRGBAColourVector4<float> > (new SimpleRGBAColourVector4<float>(0.1f, 0.1f, 0.1f, 1.0f)));
		shared_ptr<SimpleNode> lightNode(new SimpleNode);
		lightNode->getTransformation().translate(SimpleTranslationVector4<float>(0.0f, 10.0f, 0.0f, 1.0f));
		light->setNode(lightNode);
		parentNode->addChild(lightNode);

		return (light);
	}

	shared_ptr<Node> PathFindingDemo::createGreySquareOnXZPlane(const bool dark)
	{
		shared_ptr<Node> squareNode;

		if (dark)
		{
			squareNode = createSquareOnXZPlane(SimpleRGBAColourVector4<float>(0.75f, 0.75f, 0.75f, 1.0f));
		}
		else
		{
			squareNode = createSquareOnXZPlane(SimpleRGBAColourVector4<float>(0.25f, 0.25f, 0.25f, 1.0f));
		}

		return (squareNode);
	}

	vector<shared_ptr<Entity> > PathFindingDemo::createObstacles()
	{
		vector<shared_ptr<Entity> > obstacles;
		srand((unsigned) time(0));

		for (unsigned int column = 0; column < 10; column++)
		{
			for (unsigned int row = 0; row < 10; row++)
			{
				// 20% chance
				if (rand() % 5 == 0)
				{
					shared_ptr<Entity> obstacle(new Entity);
					shared_ptr<Node> obstacleNode(
						createSquareOnXZPlane(SimpleRGBAColourVector4<float>(1.0f, 0.0f, 0.0f, 1.0f)));
					obstacleNode->getTransformation().translate(
						SimpleTranslationVector4<float>(-5.0f + column, 1.0f, 5.0f - row, 1.0f));
					obstacle->addComponent(obstacleNode);
					obstacles.push_back(obstacle);

					shared_ptr<Node> pathNode = navigationMesh.at(column * 10 + row);
					for (unsigned int index = 0; index < pathNode->getChildren().size(); index++)
					{
						pathNode->getChildren().at(index)->removeChild(*pathNode);
					}
				}
			}
		}

		return (obstacles);
	}

	shared_ptr<Node> PathFindingDemo::createSquareOnXZPlane(const RGBAColourVector<float>& colour)
	{
		shared_ptr<ModelNode> squareNode(new SimpleModelNode);
		shared_ptr<VectorVG> squareModel(new VectorVG);

		float colours[18];
		for (unsigned int index = 0; index < 6; index++)
		{
			colours[index * 3] = colour.getRed();
			colours[index * 3 + 1] = colour.getGreen();
			colours[index * 3 + 2] = colour.getBlue();
		}
		shared_ptr<vector<float> > coloursVector(new vector<float>(colours, colours + 18));
		squareModel->setColours(coloursVector);

		float normals[18] = {0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 1.0f, 0.0f};
		shared_ptr<vector<float> > normalsVector(new vector<float>(normals, normals + 18));
		squareModel->setNormals(normalsVector);

		float vertices[18] = {0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
			1.0f, 0.0f, 1.0f};
		shared_ptr<vector<float> > verticesVector(new vector<float>(vertices, vertices + 18));
		squareModel->setVertices(verticesVector);

		squareNode->setModel(squareModel);

		return (squareNode);
	}

	void PathFindingDemo::displayOpenNodes(RenderingEngine& renderingEngine,
		const vector<shared_ptr<const Node> >& openNodes)
	{
		for (unsigned int index = 0; index < openNodes.size(); index++)
		{
			shared_ptr<Entity> possiblePathEntity(new Entity);

			shared_ptr<Node> possiblePathNode = createSquareOnXZPlane(
				SimpleRGBAColourVector4<float>(0.0f, 0.0f, 1.0f, 1.0f));

			shared_ptr<SimpleTransformationMatrix44<float> > transformation(
				new SimpleTransformationMatrix44<float>(
					static_cast<SimpleTransformationMatrix44<float>&>(openNodes.at(index)->getTransformation())));
			possiblePathNode->setTransformation(transformation);

			possiblePathEntity->addComponent(possiblePathNode);
			renderingEngine.addEntity(possiblePathEntity);
		}
	}

	vector<shared_ptr<Node> >& PathFindingDemo::getNavigationMesh()
	{
		return navigationMesh;
	}

	void PathFindingDemo::displayPath(RenderingEngine& renderingEngine, const vector<shared_ptr<const Node> >& path)
	{
		shared_ptr<Entity> pathEntity(new Entity);
		shared_ptr<Node> pathRootNode(new SimpleNode);

		for (unsigned int index = 0; index < path.size(); index++)
		{
			shared_ptr<ModelNode> waypointNode(new SimpleModelNode);
			pathRootNode->addChild(waypointNode);

			shared_ptr<Sphere> waypointModel(new GLUSphere);
			waypointModel->setColour(
				shared_ptr<RGBAColourVector<float> > (new SimpleRGBAColourVector4<float>(0.0f, 1.0f, 0.0f, 1.0f)));
			waypointModel->setRadius(0.1f);
			waypointNode->setModel(waypointModel);

			shared_ptr<SimpleTransformationMatrix44<float> > transformation(
				new SimpleTransformationMatrix44<float>(
					static_cast<SimpleTransformationMatrix44<float>&>(path.at(index)->getTransformation())));
			waypointNode->setTransformation(transformation);
			waypointNode->getTransformation().translate(SimpleTranslationVector4<float>(0.5f, 0.0f, 0.5f, 1.0f));
		}

		pathEntity->addComponent(pathRootNode);
		renderingEngine.addEntity(pathEntity);
	}

	void PathFindingDemo::populateNavigationMesh()
	{
		navigationMesh.clear();

		for (unsigned int column = 0; column < 10; column++)
		{
			for (unsigned int row = 0; row < 10; row++)
			{
				shared_ptr<Node> meshNode(new SimpleNode);
				meshNode->getTransformation().translate(
					SimpleTranslationVector4<float>(-5.0f + column, 0.0f, 5.0f - row, 1.0f));
				navigationMesh.push_back(meshNode);
			}
		}

		for (unsigned int column = 0; column < 10; column++)
		{
			for (unsigned int row = 0; row < 10; row++)
			{
				if (column > 0)
				{
					navigationMesh.at(column * 10 + row)->addChild(navigationMesh.at((column - 1) * 10 + row));
				}
				if (column < 9)
				{
					navigationMesh.at(column * 10 + row)->addChild(navigationMesh.at((column + 1) * 10 + row));
				}
				if (row > 0)
				{
					navigationMesh.at(column * 10 + row)->addChild(navigationMesh.at(column * 10 + (row - 1)));
				}
				if (row < 9)
				{
					navigationMesh.at(column * 10 + row)->addChild(navigationMesh.at(column * 10 + (row + 1)));
				}
			}
		}
	}
}
