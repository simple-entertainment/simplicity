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
#include "../graph/PreorderConstNodeIterator.h"
#include "../graph/PreorderNodeIterator.h"
#include "SimpleScene.h"

using namespace std;

namespace simplicity
{
	SimpleScene::SimpleScene(shared_ptr<Tree<TreeNode> > tree) :
		tree(tree)
	{
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

	vector<shared_ptr<Camera> > SimpleScene::getCameras() const
	{
		return cameras;
	}

	vector<shared_ptr<Light> > SimpleScene::getLights() const
	{
		return lights;
	}

	Tree<TreeNode>& SimpleScene::getTree()
	{
		return *tree;
	}

	const Tree<TreeNode>& SimpleScene::getTree() const
	{
		return *tree;
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
