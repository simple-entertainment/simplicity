/*
 * Copyright © 2012 Simple Entertainment Limited
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
#include <boost/lexical_cast.hpp>
#include <boost/math/constants/constants.hpp>

#include <GL/glew.h>
#include <GL/glut.h>

#include <simplicity/math/MathFactory.h>
#include <simplicity/model/ModelFactory.h>
#include <simplicity/scene/SceneFactory.h>
#include <simplicity/Simplicity.h>

#include <simplicity/opengl/model/OpenGLText.h>
#include <simplicity/opengl/rendering/SimpleOpenGLCamera.h>
#include <simplicity/opengl/rendering/SimpleOpenGLLight.h>

#include "PathFindingDemo.h"

using namespace boost::math::constants;
using namespace simplicity::opengl;
using namespace std;

namespace simplicity
{
	string PathFindingDemo::OBSTACLE_ENTITY_NAME = "obstacle";

	string PathFindingDemo::OPEN_NODE_ENTITY_NAME = "pathNode";

	string PathFindingDemo::WAYPOINT_ENTITY_NAME = "waypoint";

	PathFindingDemo::PathFindingDemo() :
		navigationMesh(), obstacleIndex(0), openNodeIndex(0), waypointIndex(0)
	{
	}

	void PathFindingDemo::addBackground(shared_ptr<Node> parentNode)
	{
		bool dark;

		for (unsigned int column = 0; column < 10; column++)
		{
			dark = (column % 2 == 0);

			for (unsigned int row = 0; row < 10; row++)
			{
				shared_ptr<Model> tile(createGreySquareOnXZPlane(dark));

				unique_ptr<TranslationVector<> > location(MathFactory::getInstance().createTranslationVector());
				location->setX(-5.0f + column);
				location->setY(0.0f);
				location->setZ(5.0f - row);
				tile->getNode()->getTransformation().translate(*location);

				parentNode->addChild(tile->getNode());

				dark = !dark;
			}
		}
	}

	shared_ptr<Camera> PathFindingDemo::addCamera(shared_ptr<Node> parentNode)
	{
		shared_ptr<SimpleOpenGLCamera> camera(new SimpleOpenGLCamera);
		camera->setProjectionMode(Camera::ORTHOGONAL);
		camera->setFrameWidth(10.0f);
		camera->setFrameAspectRatio(1.0f);

		shared_ptr<Node> node(SceneFactory::getInstance().createNode());
		camera->setNode(node);

		unique_ptr<TranslationVector<> > location(MathFactory::getInstance().createTranslationVector());
		location->setY(10.0f);
		location->setZ(1.0f);
		node->getTransformation().translate(*location);

		unique_ptr<TranslationVector<> > rotationAxis(MathFactory::getInstance().createTranslationVector());
		rotationAxis->setX(1.0f);
		node->getTransformation().rotate(pi<float>() * 1.5f, *rotationAxis);

		parentNode->addChild(node);

		return camera;
	}

	shared_ptr<Light> PathFindingDemo::addLight(shared_ptr<Node> parentNode)
	{
		shared_ptr<SimpleOpenGLLight> light(new SimpleOpenGLLight);

		shared_ptr<Node> lightNode(SceneFactory::getInstance().createNode());
		light->setNode(lightNode);

		unique_ptr<TranslationVector<> > location(MathFactory::getInstance().createTranslationVector());
		location->setY(10.0f);
		lightNode->getTransformation().translate(*location);

		unique_ptr<ColourVector<> > ambientLight(MathFactory::getInstance().createColourVector());
		ambientLight->setRed(0.25f);
		ambientLight->setGreen(0.25f);
		ambientLight->setBlue(0.25f);
		light->setAmbientLight(move(ambientLight));

		unique_ptr<ColourVector<> > diffuseLight(MathFactory::getInstance().createColourVector());
		diffuseLight->setRed(0.25f);
		diffuseLight->setGreen(0.25f);
		diffuseLight->setBlue(0.25f);
		light->setDiffuseLight(move(diffuseLight));

		unique_ptr<ColourVector<> > specularLight(MathFactory::getInstance().createColourVector());
		specularLight->setRed(0.1f);
		specularLight->setGreen(0.1f);
		specularLight->setBlue(0.1f);
		light->setSpecularLight(move(specularLight));

		parentNode->addChild(lightNode);

		return light;
	}

	vector<shared_ptr<Entity> > PathFindingDemo::createDescription()
	{
		vector <shared_ptr<Entity> > description;
		string text(getDescription());

		unsigned int lineNum = 0;
		while (text.find('\n') != string::npos)
		{
			description.push_back(createDescriptionLine(text.substr(0, text.find('\n')), lineNum));
			text = text.substr(text.find('\n') + 1);
			lineNum++;
		}
		description.push_back(createDescriptionLine(text, lineNum));

		return description;
	}

	shared_ptr<Entity> PathFindingDemo::createDescriptionLine(const string& line, const unsigned int lineNum)
	{
		shared_ptr<Entity> descriptionLine(new Entity("PathFindingDemo.descriptionLine"));

		shared_ptr<Text> model(ModelFactory::getInstance().createText());
		descriptionLine->addComponent(model);
		model->setEntity(descriptionLine);

		unique_ptr<ColourVector<> > colour(MathFactory::getInstance().createColourVector());
		colour->setRed(1.0f);
		colour->setGreen(1.0f);
		colour->setBlue(1.0f);
		model->setColour(move(colour));

		model->setText(line);

		shared_ptr<ModelNode> node(SceneFactory::getInstance().createModelNode());
		model->setNode(node);
		node->setModel(model);

		unique_ptr<TranslationVector<> > location(MathFactory::getInstance().createTranslationVector());
		location->setX(-2.3f);
		location->setY(2.0f);
		location->setZ(-1.7f + (lineNum / 10.0f));
		node->getTransformation().setTranslation(*location);

		return descriptionLine;
	}

	shared_ptr<Model> PathFindingDemo::createGreySquareOnXZPlane(const bool dark)
	{
		shared_ptr<Model> square;

		if (dark)
		{
			unique_ptr<ColourVector<> > colour(MathFactory::getInstance().createColourVector());
			colour->setRed(0.75f);
			colour->setBlue(0.75f);
			colour->setGreen(0.75f);
			square = createSquareOnXZPlane(*colour);
		}
		else
		{
			unique_ptr<ColourVector<> > colour(MathFactory::getInstance().createColourVector());
			colour->setRed(0.25f);
			colour->setBlue(0.25f);
			colour->setGreen(0.25f);
			square = createSquareOnXZPlane(*colour);
		}

		return square;
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
					string name(OBSTACLE_ENTITY_NAME + boost::lexical_cast < string > (obstacleIndex));
					shared_ptr<Entity> obstacle(new Entity(name));
					obstacleIndex++;

					unique_ptr<ColourVector<> > colour(MathFactory::getInstance().createColourVector());
					colour->setRed(1.0f);

					shared_ptr<Model> model(createSquareOnXZPlane(*colour));
					obstacle->addComponent(model);
					model->setEntity(obstacle);

					unique_ptr<TranslationVector<> > location(MathFactory::getInstance().createTranslationVector());
					location->setX(-5.0f + column);
					location->setY(1.0f);
					location->setZ(5.0f - row);
					model->getNode()->getTransformation().translate(*location);

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

	shared_ptr<Model> PathFindingDemo::createSquareOnXZPlane(const ColourVector<>& colour)
	{
		shared_ptr<VertexGroup> model(ModelFactory::getInstance().createVertexGroup());

		shared_ptr<ModelNode> node(SceneFactory::getInstance().createModelNode());
		node->setModel(model);
		model->setNode(node);

		float colours[18];
		for (unsigned int index = 0; index < 6; index++)
		{
			colours[index * 3] = colour.getRed();
			colours[index * 3 + 1] = colour.getGreen();
			colours[index * 3 + 2] = colour.getBlue();
		}
		shared_ptr < vector<float> > coloursVector(new vector<float>(colours, colours + 18));
		model->setColours(coloursVector);

		float normals[18] = {0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 1.0f, 0.0f};
		shared_ptr < vector<float> > normalsVector(new vector<float>(normals, normals + 18));
		model->setNormals(normalsVector);

		float vertices[18] = {0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
			1.0f, 0.0f, 1.0f};
		shared_ptr < vector<float> > verticesVector(new vector<float>(vertices, vertices + 18));
		model->setVertices(verticesVector);

		return model;
	}

	shared_ptr<Entity> PathFindingDemo::createTitle()
	{
		shared_ptr<Entity> title(new Entity("PathFindingDemo.title"));

		shared_ptr<Text> model(ModelFactory::getInstance().createText());
		title->addComponent(model);
		model->setEntity(title);

		unique_ptr<ColourVector<> > colour(MathFactory::getInstance().createColourVector());
		colour->setRed(1.0f);
		colour->setGreen(1.0f);
		colour->setBlue(1.0f);
		model->setColour(move(colour));

		dynamic_cast<OpenGLText*>(model.get())->setFont(GLUT_BITMAP_HELVETICA_18);
		model->setText(getTitle());

		shared_ptr<ModelNode> node(SceneFactory::getInstance().createModelNode());
		model->setNode(node);
		node->setModel(model);

		unique_ptr<TranslationVector<> > location(MathFactory::getInstance().createTranslationVector());
		location->setX(-2.3f);
		location->setY(2.0f);
		location->setZ(-1.8f);
		node->getTransformation().setTranslation(*location);

		return title;
	}

	void PathFindingDemo::displayOpenNodes(const vector<shared_ptr<const Node> >& openNodes)
	{
		for (unsigned int index = 0; index < openNodes.size(); index++)
		{
			string name(OPEN_NODE_ENTITY_NAME + boost::lexical_cast < string > (openNodeIndex));
			shared_ptr<Entity> openNode(new Entity(name));
			openNodeIndex++;

			unique_ptr<ColourVector<> > colour(MathFactory::getInstance().createColourVector());
			colour->setBlue(1.0f);

			shared_ptr<Model> model(createSquareOnXZPlane(*colour));
			openNode->addComponent(model);
			model->setEntity(openNode);

			unique_ptr<TransformationMatrix<> > transformation(MathFactory::getInstance().createTransformationMatrix());
			transformation->setData(openNodes.at(index)->getTransformation().getData());
			model->getNode()->setTransformation(move(transformation));

			Simplicity::addEntity(openNode);
		}
	}

	vector<shared_ptr<Node> >& PathFindingDemo::getNavigationMesh()
	{
		return navigationMesh;
	}

	void PathFindingDemo::displayPath(const vector<shared_ptr<const Node> >& path)
	{
		for (unsigned int index = 0; index < path.size(); index++)
		{
			string name(WAYPOINT_ENTITY_NAME + boost::lexical_cast < string > (waypointIndex));
			shared_ptr<Entity> waypoint(new Entity(name));
			waypointIndex++;

			shared_ptr<Sphere> model(ModelFactory::getInstance().createSphere());
			waypoint->addComponent(model);
			model->setEntity(waypoint);

			unique_ptr<ColourVector<> > colour(MathFactory::getInstance().createColourVector());
			colour->setGreen(1.0f);
			model->setColour(move(colour));
			model->setRadius(0.1f);

			shared_ptr<ModelNode> node(SceneFactory::getInstance().createModelNode());
			model->setNode(node);
			node->setModel(model);

			unique_ptr<TransformationMatrix<> > transformation(MathFactory::getInstance().createTransformationMatrix());
			transformation->setData(path.at(index)->getTransformation().getData());
			node->setTransformation(move(transformation));

			unique_ptr<TranslationVector<> > location(MathFactory::getInstance().createTranslationVector());
			location->setX(0.5f);
			location->setZ(0.5f);
			node->getTransformation().translate(*location);

			Simplicity::addEntity(waypoint);
		}
	}

	void PathFindingDemo::populateNavigationMesh()
	{
		navigationMesh.clear();

		for (unsigned int column = 0; column < 10; column++)
		{
			for (unsigned int row = 0; row < 10; row++)
			{
				shared_ptr<Node> node(SceneFactory::getInstance().createNode());

				unique_ptr<TranslationVector<> > location(MathFactory::getInstance().createTranslationVector());
				location->setX(-5.0f + column);
				location->setZ(5.0f - row);
				node->getTransformation().translate(*location);

				navigationMesh.push_back(node);
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
