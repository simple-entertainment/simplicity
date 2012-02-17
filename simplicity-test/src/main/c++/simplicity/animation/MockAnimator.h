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
#ifndef MOCKANIMATOR_H_
#define MOCKANIMATOR_H_

#include <gmock/gmock.h>

#include <simplicity/animation/Animator.h>

namespace simplicity
{
	/**
	 * <p>
	 * A mock implementation of {@link simplicity::Animator Animator}.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class MockAnimator : public Animator
	{
		public:
			MOCK_METHOD0(animate, void());
	};
}

#endif /* MOCKANIMATOR_H_ */
