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
#include "../../MockComponent.h"
#include "../MockAgent.h"
#include "SimpleAIEngineTest.h"

using namespace std;
using namespace testing;

namespace simplicity
{
	/**
	 * <p>
	 * Unit test the method
	 * {@link simplicity::SimpleAIEngine#addEntity(std::shared_ptr<Entity>) addEntity(std::shared_ptr<Entity>)}.
	 * </p>
	 */
	TEST_F(SimpleAIEngineTest, addEntity)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		shared_ptr<Entity> entity(new Entity("entity"));
		shared_ptr<Agent> mockComponent0(new NiceMock<MockAgent>);
		shared_ptr<Component> mockComponent1(new NiceMock<MockComponent>);

		// Initialise the test environment.
		// //////////////////////////////////////////////////
		entity->addComponent(mockComponent0);
		entity->addComponent(mockComponent1);

		// Perform test.
		// //////////////////////////////////////////////////
		objectUnderTest.addEntity(entity);

		// Verify test results.
		// //////////////////////////////////////////////////
		ASSERT_EQ(1u, objectUnderTest.getAgents().size());
		ASSERT_EQ(mockComponent0, objectUnderTest.getAgents().at(0));
	}

	/**
	 * <p>
	 * Unit test the method
	 * {@link simplicity::SimpleAIEngine#advance(const EngineInput* const) advance(const EngineInput* const)}.
	 * </p>
	 */
	TEST_F(SimpleAIEngineTest, advance)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		vector<shared_ptr<Entity> > entities;
		shared_ptr<Entity> entity0(new Entity("entity0"));
		shared_ptr<Entity> entity1(new Entity("entity1"));
		shared_ptr<Entity> entity2(new Entity("entity2"));
		shared_ptr<MockAgent> mockComponent0(new NiceMock<MockAgent>);
		shared_ptr<MockAgent> mockComponent1(new NiceMock<MockAgent>);
		shared_ptr<MockAgent> mockComponent2(new NiceMock<MockAgent>);
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
		objectUnderTest.addEntity(entity0);
		objectUnderTest.addEntity(entity1);
		objectUnderTest.addEntity(entity2);

		// Dictate expected behaviour.
		// //////////////////////////////////////////////////
		EXPECT_CALL(*mockComponent0, think()).WillOnce(Return(vector<shared_ptr<Action> >()));
		EXPECT_CALL(*mockComponent1, think()).WillOnce(Return(vector<shared_ptr<Action> >()));
		EXPECT_CALL(*mockComponent2, think()).WillOnce(Return(vector<shared_ptr<Action> >()));

		// Perform test.
		// //////////////////////////////////////////////////
		objectUnderTest.advance(vector<shared_ptr<Action> >());
	}
}
