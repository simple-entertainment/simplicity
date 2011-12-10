/*
 * Copyright © 2011 Simple Entertainment Limited
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
#include "PreorderNodeIterator.h"
#include "SimpleNode.h"
#include "SimpleScene.h"

using namespace boost;
using namespace std;

namespace simplicity
{
	SimpleScene::SimpleScene() :
		nextNodeId(0), root(new SimpleNode)
	{
		root->setId(getNextNodeId());
		nodes.insert(pair<int, shared_ptr<Node> >(root->getId(), root));
	}

	SimpleScene::~SimpleScene()
	{
	}

	void SimpleScene::addCamera(shared_ptr<Camera> camera)
	{
		cameras.push_back(camera);
	}

	void SimpleScene::addLight(shared_ptr<Light> light)
	{
		lights.push_back(light);
	}

	void SimpleScene::addNode(shared_ptr<Node> node)
	{
		addNode(node, *root);
	}

	void SimpleScene::addNode(shared_ptr<Node> node, Node& parent)
	{
		PreorderNodeIterator iterator(*node);

		while (iterator.hasMoreNodes())
		{
			shared_ptr<Node> node(iterator.getNextNode());

			node->setId(getNextNodeId());
			nodes.insert(pair<int, shared_ptr<Node> >(node->getId(), node));
		}

		parent.addChild(node);
	}

	vector<shared_ptr<Camera> > SimpleScene::getCameras() const
	{
		return (cameras);
	}

	vector<shared_ptr<Light> > SimpleScene::getLights() const
	{
		return (lights);
	}

	int SimpleScene::getNextNodeId()
	{
		return (nextNodeId++);
	}

	shared_ptr<Node> SimpleScene::getNode(const int id) const
	{
		return (nodes.find(id)->second);
	}

	shared_ptr<Node> SimpleScene::getRoot() const
	{
		return (root);
	}

	vector<shared_ptr<Node> > SimpleScene::getTopLevelNodes() const
	{
		return root->getChildren();
	}

	void SimpleScene::removeNode(Node& node)
	{
		PreorderNodeIterator iterator(node);

		while (iterator.hasMoreNodes())
		{
			nodes.erase(iterator.getNextNode()->getId());
		}

		node.getParent()->removeChild(node);
	}

	void SimpleScene::resetIds()
	{
		nextNodeId = 0;
		nodes.clear();

		PreorderNodeIterator iterator(*root);

		while (iterator.hasMoreNodes())
		{
			shared_ptr<Node> node(iterator.getNextNode());

			node->setId(getNextNodeId());
			nodes.insert(pair<int, shared_ptr<Node> >(node->getId(), node));
		}
	}

	void SimpleScene::setCameras(vector<shared_ptr<Camera> > cameras)
	{
		this->cameras = cameras;
	}

	void SimpleScene::setLights(vector<shared_ptr<Light> > lights)
	{
		this->lights = lights;
	}
}
