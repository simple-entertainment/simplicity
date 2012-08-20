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

#include <simplicity/graph/NodeFactory.h>
#include <simplicity/graph/SimpleTree.h>
#include <simplicity/math/MathFactory.h>
#include <simplicity/model/ModelFactory.h>
#include <simplicity/scene/SimpleScene.h>
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

	string PathFindingDemo::TILE_ENTITY_NAME = "tile";

	string PathFindingDemo::WAYPOINT_ENTITY_NAME = "waypoint";

	PathFindingDemo::PathFindingDemo() :
		navigationMesh(), openNodeIndex(0), waypointIndex(0)
	{
	}

	void PathFindingDemo::addBackground()
	{
		bool dark;

		for (unsigned int column = 0; column < 10; column++)
		{
			dark = (column % 2 == 0);

			for (unsigned int row = 0; row < 10; row++)
			{
				string tileName = TILE_ENTITY_NAME + "-" + boost::lexical_cast<string>(column) + "-" +
					boost::lexical_cast<string>(row);
				shared_ptr<Entity> tile(new Entity(tileName));

				shared_ptr<Model> model = createGreySquareOnXZPlane(dark);
				tile->addComponent(model);

				shared_ptr<TreeNode> node = NodeFactory::getInstance().createTreeNode();
				node->setComponent(model.get());

				unique_ptr<TranslationVector<> > location = MathFactory::getInstance().createTranslationVector();
				location->setX(-5.0f + column);
				location->setY(0.0f);
				location->setZ(5.0f - row);
				node->getTransformation().translate(*location);

				Simplicity::addEntity(tile, node);
				entities.push_back(*tile);

				dark = !dark;
			}
		}
	}

	shared_ptr<Camera> PathFindingDemo::addCamera() const
	{
		shared_ptr<SimpleOpenGLCamera> camera(new SimpleOpenGLCamera);
		camera->setProjectionMode(Camera::ORTHOGONAL);
		camera->setFrameWidth(10.0f);
		camera->setFrameAspectRatio(1.0f);

		shared_ptr<TreeNode> node = NodeFactory::getInstance().createTreeNode();
		camera->setNode(node.get());

		unique_ptr<TranslationVector<> > location = MathFactory::getInstance().createTranslationVector();
		location->setY(10.0f);
		location->setZ(1.0f);
		node->getTransformation().translate(*location);

		unique_ptr<TranslationVector<> > rotationAxis = MathFactory::getInstance().createTranslationVector();
		rotationAxis->setX(1.0f);
		node->getTransformation().rotate(pi<float>() * 1.5f, *rotationAxis);

		Simplicity::getScene()->addCamera(camera);
		Simplicity::getScene()->getTree().add(node);
		Simplicity::getScene()->getTree().connect(Simplicity::getScene()->getTree().getRoot(), *node);

		return camera;
	}

	void PathFindingDemo::addDescription()
	{
		shared_ptr<Entity> description(new Entity("description"));

		unsigned int lineNum = 0;
		string text = getDescription();
		while (text.find('\n') != string::npos)
		{
			shared_ptr<Model> descriptionLine = createDescriptionLine(text.substr(0, text.find('\n')), lineNum);
			description->addComponent(descriptionLine);
			descriptionLine->setEntity(description);

			text = text.substr(text.find('\n') + 1);
			lineNum++;
		}

		shared_ptr<Model> descriptionLine = createDescriptionLine(text, lineNum);
		description->addComponent(descriptionLine);
		descriptionLine->setEntity(description);

		Simplicity::addEntity(description);
		entities.push_back(*description);
	}

	void PathFindingDemo::addLight() const
	{
		shared_ptr<SimpleOpenGLLight> light(new SimpleOpenGLLight);

		shared_ptr<TreeNode> node = NodeFactory::getInstance().createTreeNode();
		light->setNode(node.get());

		unique_ptr<TranslationVector<> > location = MathFactory::getInstance().createTranslationVector();
		location->setY(10.0f);
		node->getTransformation().translate(*location);

		unique_ptr<ColourVector<> > ambientLight = MathFactory::getInstance().createColourVector();
		ambientLight->setRed(0.25f);
		ambientLight->setGreen(0.25f);
		ambientLight->setBlue(0.25f);
		light->setAmbientLight(move(ambientLight));

		unique_ptr<ColourVector<> > diffuseLight = MathFactory::getInstance().createColourVector();
		diffuseLight->setRed(0.25f);
		diffuseLight->setGreen(0.25f);
		diffuseLight->setBlue(0.25f);
		light->setDiffuseLight(move(diffuseLight));

		unique_ptr<ColourVector<> > specularLight = MathFactory::getInstance().createColourVector();
		specularLight->setRed(0.1f);
		specularLight->setGreen(0.1f);
		specularLight->setBlue(0.1f);
		light->setSpecularLight(move(specularLight));

		Simplicity::getScene()->addLight(light);
		Simplicity::getScene()->getTree().add(node);
		Simplicity::getScene()->getTree().connect(Simplicity::getScene()->getTree().getRoot(), *node);
	}

	void PathFindingDemo::addObstacles(vector<pair<unsigned int, unsigned int> > obstacleLocations)
	{
		unsigned int obstacleIndex = 0;

		for (pair<unsigned int, unsigned int> obstacleLocation : obstacleLocations)
		{
			string name = OBSTACLE_ENTITY_NAME + boost::lexical_cast<string>(obstacleIndex++);
			shared_ptr<Entity> obstacle(new Entity(name));

			unique_ptr<ColourVector<> > colour = MathFactory::getInstance().createColourVector();
			colour->setRed(1.0f);

			shared_ptr<Model> model = createSquareOnXZPlane(*colour);
			obstacle->addComponent(model);
			model->setEntity(obstacle);

			shared_ptr<TreeNode> node = NodeFactory::getInstance().createTreeNode();
			node->setComponent(model.get());

			unique_ptr<TranslationVector<> > location = MathFactory::getInstance().createTranslationVector();
			location->setX(-5.0f + obstacleLocation.first);
			location->setY(1.0f);
			location->setZ(5.0f - obstacleLocation.second);
			node->getTransformation().translate(*location);

			Simplicity::addEntity(obstacle, node);
			entities.push_back(*obstacle);
		}
	}

	void PathFindingDemo::addTitle()
	{
		shared_ptr<Entity> title(new Entity("title"));

		shared_ptr<Text> model = ModelFactory::getInstance().createText();
		title->addComponent(model);
		model->setEntity(title);

		unique_ptr<ColourVector<> > colour = MathFactory::getInstance().createColourVector();
		colour->setRed(1.0f);
		colour->setGreen(1.0f);
		colour->setBlue(1.0f);
		model->setColour(move(colour));

		dynamic_cast<OpenGLText*>(model.get())->setFont(GLUT_BITMAP_HELVETICA_18);
		model->setText(getTitle());

		shared_ptr<TreeNode> node = NodeFactory::getInstance().createTreeNode();
		model->setNode(node.get());
		node->setComponent(model.get());

		unique_ptr<TranslationVector<> > location = MathFactory::getInstance().createTranslationVector();
		location->setX(-2.3f);
		location->setY(2.0f);
		location->setZ(-1.8f);
		node->getTransformation().setTranslation(*location);

		Simplicity::addEntity(title, node);
		entities.push_back(*title);
	}

	shared_ptr<Model> PathFindingDemo::createDescriptionLine(const string& line, const unsigned int lineNum) const
	{
		shared_ptr<Text> descriptionLine = ModelFactory::getInstance().createText();

		unique_ptr<ColourVector<> > colour = MathFactory::getInstance().createColourVector();
		colour->setRed(1.0f);
		colour->setGreen(1.0f);
		colour->setBlue(1.0f);
		descriptionLine->setColour(move(colour));

		descriptionLine->setText(line);

		shared_ptr<TreeNode> node = NodeFactory::getInstance().createTreeNode();
		descriptionLine->setNode(node.get());
		node->setComponent(descriptionLine.get());
		Simplicity::getScene()->getTree().add(node);
		Simplicity::getScene()->getTree().connect(Simplicity::getScene()->getTree().getRoot(), *node);

		unique_ptr<TranslationVector<> > location = MathFactory::getInstance().createTranslationVector();
		location->setX(-2.3f);
		location->setY(2.0f);
		location->setZ(-1.7f + (lineNum / 10.0f));
		node->getTransformation().setTranslation(*location);

		return descriptionLine;
	}

	shared_ptr<Model> PathFindingDemo::createGreySquareOnXZPlane(const bool dark) const
	{
		unique_ptr<ColourVector<> > colour = MathFactory::getInstance().createColourVector();

		if (dark)
		{
			colour->setRed(0.75f);
			colour->setBlue(0.75f);
			colour->setGreen(0.75f);
		}
		else
		{
			colour->setRed(0.25f);
			colour->setBlue(0.25f);
			colour->setGreen(0.25f);
		}

		return createSquareOnXZPlane(*colour);
	}

	void PathFindingDemo::createNavigationMesh()
	{
		navigationMesh = UndirectedGraph<Node>();

		for (unsigned int column = 0; column < 10; column++)
		{
			for (unsigned int row = 0; row < 10; row++)
			{
				shared_ptr<Node> node = NodeFactory::getInstance().createNode();

				unique_ptr<TranslationVector<> > location = MathFactory::getInstance().createTranslationVector();
				location->setX(-5.0f + column);
				location->setZ(5.0f - row);
				node->getTransformation().translate(*location);

				navigationMesh.add(node);
			}
		}

		for (unsigned int column = 0; column < 10; column++)
		{
			for (unsigned int row = 0; row < 10; row++)
			{
				if (column < 9)
				{
					navigationMesh.connect(navigationMesh.get(column * 10 + row), navigationMesh.get((column + 1) * 10 + row));
				}
				if (row < 9)
				{
					navigationMesh.connect(navigationMesh.get(column * 10 + row), navigationMesh.get(column * 10 + (row + 1)));
				}
			}
		}
	}

	shared_ptr<Model> PathFindingDemo::createSquareOnXZPlane(const ColourVector<>& colour) const
	{
		shared_ptr<VertexGroup> model = ModelFactory::getInstance().createVertexGroup();

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

	void PathFindingDemo::displayOpenNodes(const vector<reference_wrapper<const Node> >& openNodes)
	{
		for (reference_wrapper<const Node> openNode : openNodes)
		{
			string name(OPEN_NODE_ENTITY_NAME + boost::lexical_cast<string>(openNodeIndex++));
			shared_ptr<Entity> entity(new Entity(name));

			unique_ptr<ColourVector<> > colour = MathFactory::getInstance().createColourVector();
			colour->setBlue(1.0f);

			shared_ptr<Model> model = createSquareOnXZPlane(*colour);
			entity->addComponent(model);
			model->setEntity(entity);

			shared_ptr<TreeNode> node = NodeFactory::getInstance().createTreeNode();
			node->setComponent(model.get());

			unique_ptr<TransformationMatrix<> > transformation = MathFactory::getInstance().createTransformationMatrix();
			transformation->setData(openNode.get().getTransformation().getData());
			node->setTransformation(move(transformation));

			Simplicity::addEntity(entity, node);
			entities.push_back(*entity);
		}
	}

	void PathFindingDemo::displayPath(const vector<reference_wrapper<const Node> >& path)
	{
		for (reference_wrapper<const Node> pathNode : path)
		{
			string name(WAYPOINT_ENTITY_NAME + boost::lexical_cast<string>(waypointIndex++));
			shared_ptr<Entity> waypoint(new Entity(name));

			shared_ptr<Sphere> model = ModelFactory::getInstance().createSphere();
			waypoint->addComponent(model);
			model->setEntity(waypoint);

			unique_ptr<ColourVector<> > colour = MathFactory::getInstance().createColourVector();
			colour->setGreen(1.0f);
			model->setColour(move(colour));
			model->setRadius(0.1f);

			shared_ptr<TreeNode> node = NodeFactory::getInstance().createTreeNode();
			node->setComponent(model.get());

			unique_ptr<TransformationMatrix<> > transformation(MathFactory::getInstance().createTransformationMatrix());
			transformation->setData(pathNode.get().getTransformation().getData());
			node->setTransformation(move(transformation));

			unique_ptr<TranslationVector<> > location(MathFactory::getInstance().createTranslationVector());
			location->setX(0.5f);
			location->setZ(0.5f);
			node->getTransformation().translate(*location);

			Simplicity::addEntity(waypoint, node);
			entities.push_back(*waypoint);
		}
	}

	const Graph<Node>& PathFindingDemo::getNavigationMesh() const
	{
		return navigationMesh;
	}

	vector<pair<unsigned int, unsigned int> > PathFindingDemo::getRandomObstacleLocations() const
	{
		vector < pair<unsigned int, unsigned int> > obstacleLocations;
		srand((unsigned) time(0));

		for (unsigned int column = 0; column < 10; column++)
		{
			for (unsigned int row = 0; row < 10; row++)
			{
				// We can't put obstacles at the start or end!
				unsigned int index = column * 10 + row;
				if (index == 4 || index == 95)
				{
					continue;
				}

				// 20% chance
				if (rand() % 5 == 0)
				{
					obstacleLocations.push_back(pair<unsigned int, unsigned int>(column, row));
				}
			}
		}

		return obstacleLocations;
	}

	void PathFindingDemo::initScene() const
	{
		shared_ptr<TreeNode> root = NodeFactory::getInstance().createTreeNode();
		shared_ptr<Tree<TreeNode> > tree(new SimpleTree<TreeNode>(root));
		shared_ptr<Scene> scene(new SimpleScene(tree));
		Simplicity::setScene(scene);
	}

	void PathFindingDemo::removeAllEntities()
	{
		for (reference_wrapper<Entity> entity : entities)
		{
			Simplicity::removeEntity(entity.get().getName());
		}
		entities.clear();
	}

	void PathFindingDemo::removeLocationsFromNavigationMesh(vector<pair<unsigned int, unsigned int> > locations)
	{
		for (pair<unsigned int, unsigned int> location : locations)
		{
			navigationMesh.remove(navigationMesh.get(location.first * 10 + location.second));
		}
	}
}
