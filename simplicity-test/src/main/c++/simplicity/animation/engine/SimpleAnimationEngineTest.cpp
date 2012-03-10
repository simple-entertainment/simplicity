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
#include "../../MockComponent.h"
#include "../MockAnimator.h"
#include "SimpleAnimationEngineTest.h"

using namespace std;
using namespace testing;

namespace simplicity
{
	/**
	 * <p>
	 * Unit test the method
	 * {@link simplicity::SimpleAnimationEngine#addEntities(std::vector<std::shared_ptr<Entity> >) addEntities(std::vector<std::shared_ptr<Entity> >)}.
	 * </p>
	 */
	TEST_F(SimpleAnimationEngineTest, addEntities)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		vector<shared_ptr<Entity> > entities;
		shared_ptr<Entity> entity0(new Entity("entity0"));
		shared_ptr<Entity> entity1(new Entity("entity1"));
		shared_ptr<Entity> entity2(new Entity("entity2"));
		shared_ptr<Animator> mockComponent0(new NiceMock<MockAnimator>);
		shared_ptr<Animator> mockComponent1(new NiceMock<MockAnimator>);
		shared_ptr<Animator> mockComponent2(new NiceMock<MockAnimator>);
		shared_ptr<Component> mockComponent3(new NiceMock<MockComponent>);

		// Initialise the test environment.
		// //////////////////////////////////////////////////
		entities.push_back(entity0);
		entities.push_back(entity1);
		entities.push_back(entity2);
		entity1->addComponent(mockComponent0);
		entity2->addComponent(mockComponent1);
		entity2->addComponent(mockComponent2);
		entity2->addComponent(mockComponent3);

		// Perform test.
		// //////////////////////////////////////////////////
		objectUnderTest.addEntities(entities);

		// Verify test results.
		// //////////////////////////////////////////////////
		ASSERT_EQ(3u, objectUnderTest.getAnimators().size());
		ASSERT_EQ(mockComponent0, objectUnderTest.getAnimators().at(0));
		ASSERT_EQ(mockComponent1, objectUnderTest.getAnimators().at(1));
		ASSERT_EQ(mockComponent2, objectUnderTest.getAnimators().at(2));
	}

	/**
	 * <p>
	 * Unit test the method
	 * {@link simplicity::SimpleAnimationEngine#advance(const EngineInput* const) advance(const EngineInput* const)}.
	 * </p>
	 */
	TEST_F(SimpleAnimationEngineTest, advance)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		vector<shared_ptr<Entity> > entities;
		shared_ptr<Entity> entity0(new Entity("entity0"));
		shared_ptr<Entity> entity1(new Entity("entity1"));
		shared_ptr<Entity> entity2(new Entity("entity2"));
		shared_ptr<MockAnimator> mockComponent0(new NiceMock<MockAnimator>);
		shared_ptr<MockAnimator> mockComponent1(new NiceMock<MockAnimator>);
		shared_ptr<MockAnimator> mockComponent2(new NiceMock<MockAnimator>);
		shared_ptr<Component> mockComponent3(new NiceMock<MockComponent>);

		// Initialise the test environment.
		// //////////////////////////////////////////////////
		entities.push_back(entity0);
		entities.push_back(entity1);
		entities.push_back(entity2);
		entity1->addComponent(mockComponent0);
		entity2->addComponent(mockComponent1);
		entity2->addComponent(mockComponent2);
		entity2->addComponent(mockComponent3);
		objectUnderTest.addEntities(entities);

		// Dictate expected behaviour.
		// //////////////////////////////////////////////////
		EXPECT_CALL(*mockComponent0, animate());
		EXPECT_CALL(*mockComponent1, animate());
		EXPECT_CALL(*mockComponent2, animate());

		// Perform test.
		// //////////////////////////////////////////////////
		objectUnderTest.advance(shared_ptr<EngineInput>());
	}
}
