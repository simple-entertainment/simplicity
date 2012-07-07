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
#include <algorithm>

#include "SimpleAnimationEngine.h"

using namespace std;

namespace simplicity
{
	SimpleAnimationEngine::SimpleAnimationEngine()
	{
	}

	SimpleAnimationEngine::~SimpleAnimationEngine()
	{
	}

	void SimpleAnimationEngine::addEntity(shared_ptr<Entity> entity)
	{
		for (shared_ptr<Animator> animator : entity->getComponents<Animator>())
		{
			animators.push_back(animator);
		}
	}

	shared_ptr<EngineInput> SimpleAnimationEngine::advance(const shared_ptr<EngineInput> input)
	{
		for (unsigned int index = 0; index < animators.size(); index++)
		{
			animators.at(index)->animate();
		}

		return shared_ptr<EngineInput>();
	}

	void SimpleAnimationEngine::destroy()
	{
	}

	const std::vector<shared_ptr<Animator> > SimpleAnimationEngine::getAnimators()
	{
		return animators;
	}

	void SimpleAnimationEngine::onInit()
	{
	}

	void SimpleAnimationEngine::onReset()
	{
	}

	void SimpleAnimationEngine::removeEntity(const Entity& entity)
	{
		for (shared_ptr<Animator> animator : entity.getComponents<Animator>())
		{
			animators.erase(remove(animators.begin(), animators.end(), animator));
		}
	}
}
