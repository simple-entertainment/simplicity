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

#include <simplicity/math/MathFactory.h>
#include <simplicity/model/VectorVG.h>
#include <simplicity/scene/model/SimpleModelNode.h>
#include <simplicity/scene/SimpleNode.h>

#include <simplicity/opengl/model/shape/GLUSphere.h>
#include <simplicity/opengl/rendering/SimpleOpenGLCamera.h>
#include <simplicity/opengl/rendering/SimpleOpenGLLight.h>

#include "PathFindingDemo.h"

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

				unique_ptr<TranslationVector<> > translation(MathFactory::getInstance().createTranslationVector());
				translation->setX(-5.0f + column);
				translation->setY(0.0f);
				translation->setZ(5.0f - row);
				tileNode->getTransformation().translate(*translation);

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

		unique_ptr<TranslationVector<> > translation(MathFactory::getInstance().createTranslationVector());
		translation->setY(10.0f);
		translation->setZ(1.0f);
		cameraNode->getTransformation().translate(*translation);

		unique_ptr<TranslationVector<> > rotationAxis(MathFactory::getInstance().createTranslationVector());
		rotationAxis->setX(1.0f);
		cameraNode->getTransformation().rotate(pi<float>() * 1.5f, *rotationAxis);

		camera->setNode(cameraNode);
		parentNode->addChild(cameraNode);

		return camera;
	}

	shared_ptr<Light> PathFindingDemo::addLight(shared_ptr<Node> parentNode)
	{
		shared_ptr<SimpleOpenGLLight> light(new SimpleOpenGLLight);
		shared_ptr<SimpleNode> lightNode(new SimpleNode);

		unique_ptr<RGBAColourVector<> > ambientLight(MathFactory::getInstance().createRGBAColourVector());
		ambientLight->setRed(0.25f);
		ambientLight->setGreen(0.25f);
		ambientLight->setBlue(0.25f);
		light->setAmbientLight(move(ambientLight));

		unique_ptr<RGBAColourVector<> > diffuseLight(MathFactory::getInstance().createRGBAColourVector());
		diffuseLight->setRed(0.25f);
		diffuseLight->setGreen(0.25f);
		diffuseLight->setBlue(0.25f);
		light->setDiffuseLight(move(diffuseLight));

		unique_ptr<RGBAColourVector<> > specularLight(MathFactory::getInstance().createRGBAColourVector());
		specularLight->setRed(0.1f);
		specularLight->setGreen(0.1f);
		specularLight->setBlue(0.1f);
		light->setSpecularLight(move(specularLight));

		unique_ptr<TranslationVector<> > translation(MathFactory::getInstance().createTranslationVector());
		translation->setY(10.0f);
		lightNode->getTransformation().translate(*translation);
		light->setNode(lightNode);

		parentNode->addChild(lightNode);

		return light;
	}

	shared_ptr<Node> PathFindingDemo::createGreySquareOnXZPlane(const bool dark)
	{
		shared_ptr<Node> squareNode;

		if (dark)
		{
			unique_ptr<RGBAColourVector<> > colour(MathFactory::getInstance().createRGBAColourVector());
			colour->setRed(0.75f);
			colour->setBlue(0.75f);
			colour->setGreen(0.75f);
			squareNode = createSquareOnXZPlane(*colour);
		}
		else
		{
			unique_ptr<RGBAColourVector<> > colour(MathFactory::getInstance().createRGBAColourVector());
			colour->setRed(0.25f);
			colour->setBlue(0.25f);
			colour->setGreen(0.25f);
			squareNode = createSquareOnXZPlane(*colour);
		}

		return squareNode;
	}

	vector<shared_ptr<Entity> > PathFindingDemo::createObstacles()
	{
		vector < shared_ptr<Entity> > obstacles;
		srand((unsigned) time(0));

		for (unsigned int column = 0; column < 10; column++)
		{
			for (unsigned int row = 0; row < 10; row++)
			{
				// 20% chance
				if (rand() % 5 == 0)
				{
					shared_ptr<Entity> obstacle(new Entity);

					unique_ptr<RGBAColourVector<> > colour(MathFactory::getInstance().createRGBAColourVector());
					colour->setRed(1.0f);
					shared_ptr<Node> obstacleNode(createSquareOnXZPlane(*colour));

					unique_ptr<TranslationVector<> > translation(MathFactory::getInstance().createTranslationVector());
					translation->setX(-5.0f + column);
					translation->setY(1.0f);
					translation->setZ(5.0f - row);
					obstacleNode->getTransformation().translate(*translation);

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

		return obstacles;
	}

	shared_ptr<Node> PathFindingDemo::createSquareOnXZPlane(const RGBAColourVector<>& colour)
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
		shared_ptr < vector<float> > coloursVector(new vector<float>(colours, colours + 18));
		squareModel->setColours(coloursVector);

		float normals[18] = {0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 1.0f, 0.0f};
		shared_ptr < vector<float> > normalsVector(new vector<float>(normals, normals + 18));
		squareModel->setNormals(normalsVector);

		float vertices[18] = {0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
			1.0f, 0.0f, 1.0f};
		shared_ptr < vector<float> > verticesVector(new vector<float>(vertices, vertices + 18));
		squareModel->setVertices(verticesVector);

		squareNode->setModel(squareModel);

		return squareNode;
	}

	void PathFindingDemo::displayOpenNodes(RenderingEngine& renderingEngine,
		const vector<shared_ptr<const Node> >& openNodes)
	{
		for (unsigned int index = 0; index < openNodes.size(); index++)
		{
			shared_ptr<Entity> possiblePathEntity(new Entity);

			unique_ptr<RGBAColourVector<> > colour(MathFactory::getInstance().createRGBAColourVector());
			colour->setBlue(1.0f);
			shared_ptr<Node> possiblePathNode(createSquareOnXZPlane(*colour));

			unique_ptr<TransformationMatrix<> > transformation(MathFactory::getInstance().createTransformationMatrix());
			transformation->setData(openNodes.at(index)->getTransformation().getData());
			possiblePathNode->setTransformation(move(transformation));

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

			unique_ptr<RGBAColourVector<> > colour(MathFactory::getInstance().createRGBAColourVector());
			colour->setGreen(1.0f);
			waypointModel->setColour(move(colour));
			waypointModel->setRadius(0.1f);
			waypointNode->setModel(waypointModel);

			unique_ptr<TransformationMatrix<> > transformation(MathFactory::getInstance().createTransformationMatrix());
			transformation->setData(path.at(index)->getTransformation().getData());
			waypointNode->setTransformation(move(transformation));

			unique_ptr<TranslationVector<> > translation(MathFactory::getInstance().createTranslationVector());
			translation->setX(0.5f);
			translation->setZ(0.5f);
			waypointNode->getTransformation().translate(*translation);
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

				unique_ptr<TranslationVector<> > translation(MathFactory::getInstance().createTranslationVector());
				translation->setX(-5.0f + column);
				translation->setZ(5.0f - row);
				meshNode->getTransformation().translate(*translation);

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
