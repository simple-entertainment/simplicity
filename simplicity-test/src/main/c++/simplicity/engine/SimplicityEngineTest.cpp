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
#include <simplicity/engine/EntityDoesNotExistException.h>
#include <simplicity/Events.h>
#include <simplicity/Messages.h>

#include "../graph/MockTreeNode.h"
#include "../graph/MockTree.h"
#include "../MockComponent.h"
#include "../scene/MockScene.h"
#include "../Utilities.h"
#include "MockEngine.h"
#include "SimplicityEngineTest.h"

using namespace std;
using namespace testing;

namespace simplicity
{
	/**
	 * <p>
	 * Unit test the method
	 * {@link simplicity::SimplicityEngine#addEntity(std::shared_ptr<Entity>) addEntity(std::shared_ptr<Entity>)}.
	 * </p>
	 */
	TEST_F(SimplicityEngineTest, addEntity)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		shared_ptr<MockEngine> mockEngine(new NiceMock<MockEngine>);
		shared_ptr<Entity> entity(new Entity("entity"));

		// Provide stub behaviour.
		// //////////////////////////////////////////////////
		ON_CALL(*mockEngine, advance(_)).WillByDefault(Return(vector<shared_ptr<Action> >()));

		// Initialise test environment.
		// //////////////////////////////////////////////////
		Messages::registerRecipient(ADD_ENTITY_EVENT, Utilities::testRecipient);
		Utilities::resetTestRecipient();
		objectUnderTest.setEngine(mockEngine);

		// Dictate expected behaviour.
		// //////////////////////////////////////////////////
		EXPECT_CALL(*mockEngine, addEntity(entity));

		// Perform test.
		// //////////////////////////////////////////////////
		objectUnderTest.addEntity(entity);
		objectUnderTest.advance(vector<shared_ptr<Action> >());

		// Verify test results.
		// //////////////////////////////////////////////////
		ASSERT_NO_THROW(objectUnderTest.getEntity("entity"));
		ASSERT_TRUE(Utilities::hasTestRecipientBeenCalled());

		// Cleanup test environment.
		// //////////////////////////////////////////////////
		Messages::deregisterRecipient(ADD_ENTITY_EVENT, Utilities::testRecipient);
	}

	/**
	 * <p>
	 * Unit test the method
	 * {@link simplicity::SimplicityEngine#addEntity(std::shared_ptr<Entity>) addEntity(std::shared_ptr<Entity>)} with
	 * the special condition that advance has not been called after the addition.
	 * </p>
	 */
	TEST_F(SimplicityEngineTest, addEntityNoAdvance)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		shared_ptr<MockEngine> mockEngine(new NiceMock<MockEngine>);
		shared_ptr<Entity> entity(new Entity("entity"));

		// Provide stub behaviour.
		// //////////////////////////////////////////////////
		ON_CALL(*mockEngine, advance(_)).WillByDefault(Return(vector<shared_ptr<Action> >()));

		// Initialise test environment.
		// //////////////////////////////////////////////////
		objectUnderTest.setEngine(mockEngine);

		// Perform test.
		// //////////////////////////////////////////////////
		objectUnderTest.addEntity(entity);

		// Verify test results.
		// //////////////////////////////////////////////////
		ASSERT_THROW(objectUnderTest.getEntity("entity"), EntityDoesNotExistException);
	}

	/**
	 * <p>
	 * Unit test the method
	 * {@link simplicity::SimplicityEngine#addEntity(std::shared_ptr<Entity>, std::shared_ptr<TreeNode>) addEntity(std::shared_ptr<Entity>, std::shared_ptr<TreeNode>)}.
	 * </p>
	 */
	TEST_F(SimplicityEngineTest, addEntityNode)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		shared_ptr<MockEngine> mockEngine(new NiceMock<MockEngine>);
		shared_ptr<Entity> entity(new Entity("entity"));
		shared_ptr<MockScene> mockScene(new NiceMock<MockScene>);
		NiceMock<MockTree<> > mockTree;
		NiceMock<MockTreeNode> mockRoot;
		shared_ptr<TreeNode> mockNode(new NiceMock<MockTreeNode>);

		// Provide stub behaviour.
		// //////////////////////////////////////////////////
		ON_CALL(*mockEngine, advance(_)).WillByDefault(Return(vector<shared_ptr<Action> >()));
		ON_CALL(*mockScene, getTree()).WillByDefault(ReturnRef(mockTree));
		ON_CALL(mockTree, getRoot()).WillByDefault(ReturnRef(mockRoot));

		// Initialise test environment.
		// //////////////////////////////////////////////////
		objectUnderTest.setEngine(mockEngine);
		objectUnderTest.setScene(mockScene);

		// Dictate expected behaviour.
		// //////////////////////////////////////////////////
		EXPECT_CALL(*mockEngine, addEntity(entity));
		EXPECT_CALL(mockTree, add(mockNode)).WillOnce(ReturnRef(*mockNode));
		EXPECT_CALL(mockTree, connect(Ref(mockRoot), Ref(*mockNode)));

		// Perform test.
		// //////////////////////////////////////////////////
		objectUnderTest.addEntity(entity, mockNode);
		objectUnderTest.advance(vector<shared_ptr<Action> >());

		// Verify test results.
		// //////////////////////////////////////////////////
		ASSERT_NO_THROW(objectUnderTest.getEntity("entity"));
	}

	/**
	 * <p>
	 * Unit test the method
	 * {@link simplicity::SimplicityEngine#addEntity(std::shared_ptr<Entity>, std::shared_ptr<TreeNode>, TreeNode&) addEntity(std::shared_ptr<Entity>, std::shared_ptr<TreeNode>, TreeNode&)}.
	 * </p>
	 */
	TEST_F(SimplicityEngineTest, addEntityNodeSpecificParent)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		shared_ptr<MockEngine> mockEngine(new NiceMock<MockEngine>);
		shared_ptr<Entity> entity(new Entity("entity"));
		shared_ptr<MockScene> mockScene(new NiceMock<MockScene>);
		NiceMock<MockTree<> > mockTree;
		NiceMock<MockTreeNode> mockParent;
		shared_ptr<TreeNode> mockNode(new NiceMock<MockTreeNode>);

		// Provide stub behaviour.
		// //////////////////////////////////////////////////
		ON_CALL(*mockEngine, advance(_)).WillByDefault(Return(vector<shared_ptr<Action> >()));
		ON_CALL(*mockScene, getTree()).WillByDefault(ReturnRef(mockTree));

		// Initialise test environment.
		// //////////////////////////////////////////////////
		objectUnderTest.setEngine(mockEngine);
		objectUnderTest.setScene(mockScene);

		// Dictate expected behaviour.
		// //////////////////////////////////////////////////
		EXPECT_CALL(*mockEngine, addEntity(entity));
		EXPECT_CALL(mockTree, add(mockNode)).WillOnce(ReturnRef(*mockNode));
		EXPECT_CALL(mockTree, connect(Ref(mockParent), Ref(*mockNode)));

		// Perform test.
		// //////////////////////////////////////////////////
		objectUnderTest.addEntity(entity, mockNode, mockParent);
		objectUnderTest.advance(vector<shared_ptr<Action> >());

		// Verify test results.
		// //////////////////////////////////////////////////
		ASSERT_NO_THROW(objectUnderTest.getEntity("entity"));
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimplicityEngine#getEntity(std::string) getEntity(std::string)}.
	 * </p>
	 */
	TEST_F(SimplicityEngineTest, getEntity)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		shared_ptr<MockEngine> mockEngine(new NiceMock<MockEngine>);
		shared_ptr<Entity> entity(new Entity("entity"));

		// Provide stub behaviour.
		// //////////////////////////////////////////////////
		ON_CALL(*mockEngine, advance(_)).WillByDefault(Return(vector<shared_ptr<Action> >()));

		// Initialise test environment.
		// //////////////////////////////////////////////////
		objectUnderTest.setEngine(mockEngine);
		objectUnderTest.addEntity(entity);
		objectUnderTest.advance(vector<shared_ptr<Action> >());

		// Perform test.
		// //////////////////////////////////////////////////
		Entity& entityRef = objectUnderTest.getEntity("entity");

		// Verify test results.
		// //////////////////////////////////////////////////
		ASSERT_EQ(entity.get(), &entityRef);
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimplicityEngine#getEntity(std::string) getEntity(std::string)} with the
	 * special case that an <code>Entity</code> with the given name cannot be found.
	 * </p>
	 */
	TEST_F(SimplicityEngineTest, getEntityNotExists)
	{
		// Perform test - Verify test results.
		// //////////////////////////////////////////////////
		ASSERT_THROW(objectUnderTest.getEntity("entity"), EntityDoesNotExistException);
	}

	/**
	 * <p>
	 * Unit test the method
	 * {@link simplicity::SimplicityEngine#removeEntity(const Entity&) removeEntity(const Entity&)}.
	 * </p>
	 */
	TEST_F(SimplicityEngineTest, removeEntity)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		shared_ptr<MockEngine> mockEngine(new NiceMock<MockEngine>);
		shared_ptr<Entity> entity(new Entity("entity"));

		// Provide stub behaviour.
		// //////////////////////////////////////////////////
		ON_CALL(*mockEngine, advance(_)).WillByDefault(Return(vector<shared_ptr<Action> >()));

		// Initialise test environment.
		// //////////////////////////////////////////////////
		Messages::registerRecipient(REMOVE_ENTITY_EVENT, Utilities::testRecipient);
		Utilities::resetTestRecipient();
		objectUnderTest.setEngine(mockEngine);
		objectUnderTest.addEntity(entity);
		objectUnderTest.advance(vector<shared_ptr<Action> >());

		// Dictate expected behaviour.
		// //////////////////////////////////////////////////
		EXPECT_CALL(*mockEngine, removeEntity(Ref(*entity)));

		// Perform test.
		// //////////////////////////////////////////////////
		objectUnderTest.removeEntity(*entity);

		// Verify test results.
		// //////////////////////////////////////////////////
		ASSERT_THROW(objectUnderTest.getEntity("entity"), EntityDoesNotExistException);
		ASSERT_TRUE(Utilities::hasTestRecipientBeenCalled());

		// Cleanup test environment.
		// //////////////////////////////////////////////////
		Messages::deregisterRecipient(ADD_ENTITY_EVENT, Utilities::testRecipient);
	}

	/**
	 * <p>
	 * Unit test the method
	 * {@link simplicity::SimplicityEngine#removeEntity(const Entity&) removeEntity(const Entity&)}.
	 * </p>
	 */
	TEST_F(SimplicityEngineTest, removeEntityNode)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		shared_ptr<MockEngine> mockEngine(new NiceMock<MockEngine>);
		shared_ptr<Entity> entity(new Entity("entity"));
		shared_ptr<MockScene> mockScene(new NiceMock<MockScene>);
		NiceMock<MockTree<> > mockTree;
		NiceMock<MockTreeNode> mockRoot;
		shared_ptr<TreeNode> mockNode(new NiceMock<MockTreeNode>);

		// Provide stub behaviour.
		// //////////////////////////////////////////////////
		ON_CALL(*mockEngine, advance(_)).WillByDefault(Return(vector<shared_ptr<Action> >()));
		ON_CALL(*mockScene, getTree()).WillByDefault(ReturnRef(mockTree));
		ON_CALL(mockTree, add(mockNode)).WillByDefault(ReturnRef(*mockNode));
		ON_CALL(mockTree, getRoot()).WillByDefault(ReturnRef(mockRoot));

		// Initialise test environment.
		// //////////////////////////////////////////////////
		objectUnderTest.setEngine(mockEngine);
		objectUnderTest.setScene(mockScene);
		objectUnderTest.addEntity(entity, mockNode);
		objectUnderTest.advance(vector<shared_ptr<Action> >());

		// Dictate expected behaviour.
		// //////////////////////////////////////////////////
		EXPECT_CALL(*mockEngine, removeEntity(Ref(*entity)));
		EXPECT_CALL(mockTree, remove(Ref(*mockNode)));

		// Perform test.
		// //////////////////////////////////////////////////
		objectUnderTest.removeEntity(*entity);

		// Verify test results.
		// //////////////////////////////////////////////////
		ASSERT_THROW(objectUnderTest.getEntity("entity"), EntityDoesNotExistException);
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimplicityEngine#reset() reset()}.
	 * </p>
	 */
	TEST_F(SimplicityEngineTest, reset)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		shared_ptr<MockEngine> mockEngine(new NiceMock<MockEngine>);
		shared_ptr<Entity> entity(new Entity("entity"));

		// Initialise test environment.
		// //////////////////////////////////////////////////
		objectUnderTest.setEngine(mockEngine);
		objectUnderTest.addEntity(entity);

		// Perform test.
		// //////////////////////////////////////////////////
		objectUnderTest.reset();

		// Verify test results.
		// //////////////////////////////////////////////////
		ASSERT_THROW(objectUnderTest.getEntity("entity"), EntityDoesNotExistException);
	}
}
