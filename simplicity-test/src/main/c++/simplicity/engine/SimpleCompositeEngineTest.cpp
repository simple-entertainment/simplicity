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
#include <simplicity/engine/EngineInput.h>

#include "MockEngine.h"
#include "MockEngineInput.h"
#include "SimpleCompositeEngineTest.h"

using namespace std;
using namespace testing;

namespace simplicity
{
	/**
	 * <p>
	 * Unit test the method
	 * {@link simplicity::SimpleCompositeEngine#advance(std::vector<Action>) advance(std::vector<Action>)}.
	 * </p>
	 */
	TEST_F(SimpleCompositeEngineTest, advance)
	{
		// Create dependencies.
		shared_ptr<MockEngine> mockEngine1(new MockEngine);
		shared_ptr<MockEngine> mockEngine2(new MockEngine);
		shared_ptr<MockEngine> mockEngine3(new MockEngine);

		// Initialise test environment.
		objectUnderTest.addEngine(mockEngine1);
		objectUnderTest.addEngine(mockEngine2);
		objectUnderTest.addEngine(mockEngine3);

		// Dictate correct behaviour.
		EXPECT_CALL(*mockEngine1, getPreferredFrequency()).WillRepeatedly(Return(3));
		EXPECT_CALL(*mockEngine2, getPreferredFrequency()).WillRepeatedly(Return(4));
		EXPECT_CALL(*mockEngine3, getPreferredFrequency()).WillRepeatedly(Return(6));
		EXPECT_CALL(*mockEngine1, init());
		EXPECT_CALL(*mockEngine2, init());
		EXPECT_CALL(*mockEngine3, init());

		// Dictate expected results.
		// First advance.
		// No engines advance.

		// Second advance.
		EXPECT_CALL(*mockEngine3, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();

		// Third advance.
		EXPECT_CALL(*mockEngine2, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();

		// Fourth advance.
		EXPECT_CALL(*mockEngine1, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();
		EXPECT_CALL(*mockEngine3, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();

		// Fifth advance.
		// No engines advance.

		// Sixth advance.
		EXPECT_CALL(*mockEngine2, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();
		EXPECT_CALL(*mockEngine3, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();

		// Seventh advance.
		// No engines advance.

		// Eighth advance.
		EXPECT_CALL(*mockEngine1, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();
		EXPECT_CALL(*mockEngine3, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();

		// Ninth advance.
		EXPECT_CALL(*mockEngine2, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();

		// Tenth advance.
		EXPECT_CALL(*mockEngine3, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();

		// Eleventh advance.
		// No engines advance.

		// Twelfth advance.
		EXPECT_CALL(*mockEngine1, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();
		EXPECT_CALL(*mockEngine2, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();
		EXPECT_CALL(*mockEngine3, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();

		// Thirteenth advance.
		// No engines advance.

		// Fourteenth advance.
		EXPECT_CALL(*mockEngine3, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();

		// Fifteenth advance.
		EXPECT_CALL(*mockEngine2, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();

		// Sixteenth advance.
		EXPECT_CALL(*mockEngine1, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();
		EXPECT_CALL(*mockEngine3, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();

		// Seventeenth advance.
		// No engines advance.);

		// Eighteenth advance.
		EXPECT_CALL(*mockEngine2, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();
		EXPECT_CALL(*mockEngine3, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();

		// Nineteenth advance.
		// No engines advance.

		// Twentieth advance.
		EXPECT_CALL(*mockEngine1, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();
		EXPECT_CALL(*mockEngine3, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();

		// Twenty First advance.
		EXPECT_CALL(*mockEngine2, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();

		// Twenty Second advance.
		EXPECT_CALL(*mockEngine3, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();

		// Twenty Third advance.
		// No engines advance.

		// Twenty Fourth advance.
		EXPECT_CALL(*mockEngine1, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();
		EXPECT_CALL(*mockEngine2, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();
		EXPECT_CALL(*mockEngine3, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();

		// Perform test.
		objectUnderTest.init();

		for (int index = 0; index < 24; index++)
		{
			objectUnderTest.advance(vector<shared_ptr<Action> >());
		}
	}

	/**
	 * <p>
	 * Unit test the method
	 * {@link simplicity::SimpleCompositeEngine#advance(std::vector<Action>) advance(std::vector<Action>)}, specifically
	 * the functionality that passes the actions from one {@link simplicity::Engine Engine} to the next.
	 * </p>
	 */
	TEST_F(SimpleCompositeEngineTest, advancePassActions)
	{
		// Create dependencies.
		shared_ptr<MockEngine> mockEngine1(new NiceMock<MockEngine>);
		shared_ptr<MockEngine> mockEngine2(new NiceMock<MockEngine>);
		shared_ptr<MockEngine> mockEngine3(new NiceMock<MockEngine>);
		vector<Action> actions0;
		vector<Action> actions1;
		vector<Action> actions2;
		vector<Action> actions3;

		// Provide stub behaviour.
		ON_CALL(*mockEngine1, getPreferredFrequency()).WillByDefault(Return(1));
		ON_CALL(*mockEngine2, getPreferredFrequency()).WillByDefault(Return(1));
		ON_CALL(*mockEngine3, getPreferredFrequency()).WillByDefault(Return(1));

		// Initialise test environment.
		objectUnderTest.addEngine(mockEngine1);
		objectUnderTest.addEngine(mockEngine2);
		objectUnderTest.addEngine(mockEngine3);
		objectUnderTest.init();

		// Dictate expected results.
		// FIXME
		/*EXPECT_CALL(*mockEngine1, advance(actions0)).WillOnce(Return(actions1));
		EXPECT_CALL(*mockEngine2, advance(actions1)).WillOnce(Return(actions2));
		EXPECT_CALL(*mockEngine3, advance(actions2)).WillOnce(Return(actions3));*/

		// Perform test.
		/*objectUnderTest.advance(actions0);*/
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimpleCompositeEngine#getCompositeFrequency() getCompositeFrequency()}.
	 * </p>
	 */TEST_F(SimpleCompositeEngineTest, getCompositeFrequency)
	{
		// Create dependencies.
		shared_ptr<MockEngine> mockEngine1(new MockEngine);
		shared_ptr<MockEngine> mockEngine2(new MockEngine);
		shared_ptr<MockEngine> mockEngine3(new MockEngine);

		// Dictate correct behaviour.
		EXPECT_CALL(*mockEngine1, getPreferredFrequency()).WillRepeatedly(Return(3));
		EXPECT_CALL(*mockEngine2, getPreferredFrequency()).WillRepeatedly(Return(4));
		EXPECT_CALL(*mockEngine3, getPreferredFrequency()).WillRepeatedly(Return(6));
		EXPECT_CALL(*mockEngine1, init());
		EXPECT_CALL(*mockEngine2, init());
		EXPECT_CALL(*mockEngine3, init());

		// Initialise test environment.
		objectUnderTest.addEngine(mockEngine1);
		objectUnderTest.addEngine(mockEngine2);
		objectUnderTest.addEngine(mockEngine3);
		objectUnderTest.init();

		// Perform test - Verify test results.
		ASSERT_EQ(12, objectUnderTest.getPreferredFrequency());
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimpleCompositeEngine#getCompositeFrequency() getCompositeFrequency()}
	 * with the special condition that the {@link simplicity::SimpleCompositeEngine SimpleCompositeEngine} being tested
	 * does not have any sub-engines.
	 * </p>
	 */TEST_F(SimpleCompositeEngineTest, getCompositeFrequencyNoEngines)
	{
		// Perform test - Verify test results.
		ASSERT_EQ(1, objectUnderTest.getPreferredFrequency());
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimpleCompositeEngine#reset() reset()}.
	 * </p>
	 */TEST_F(SimpleCompositeEngineTest, reset)
	{
		// Create dependencies.
		shared_ptr<MockEngine> mockEngine1(new NiceMock<MockEngine>);
		shared_ptr<MockEngine> mockEngine2(new NiceMock<MockEngine>);
		shared_ptr<MockEngine> mockEngine3(new NiceMock<MockEngine>);

		// Initialise test environment.
		objectUnderTest.addEngine(mockEngine1);
		objectUnderTest.addEngine(mockEngine2);
		objectUnderTest.addEngine(mockEngine3);

		// Provide stub behaviour.
		ON_CALL(*mockEngine1, getPreferredFrequency()).WillByDefault(Return(3));
		ON_CALL(*mockEngine2, getPreferredFrequency()).WillByDefault(Return(4));
		ON_CALL(*mockEngine3, getPreferredFrequency()).WillByDefault(Return(6));

		// Dictate expected results.
		// First advance.
		// No engines advance.

		// Second advance.
		EXPECT_CALL(*mockEngine3, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();

		// Third advance.
		EXPECT_CALL(*mockEngine2, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();

		// Fourth advance.
		EXPECT_CALL(*mockEngine1, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();
		EXPECT_CALL(*mockEngine3, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();

		// Fifth advance.
		// No engines advance.

		// Reset.
		EXPECT_CALL(*mockEngine1, reset());
		EXPECT_CALL(*mockEngine2, reset());
		EXPECT_CALL(*mockEngine3, reset());

		// First advance.
		// No engines advance.

		// Second advance.
		EXPECT_CALL(*mockEngine3, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();

		// Third advance.
		EXPECT_CALL(*mockEngine2, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();

		// Fourth advance.
		EXPECT_CALL(*mockEngine1, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();
		EXPECT_CALL(*mockEngine3, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();

		// Fifth advance.
		// No engines advance.

		// Sixth advance.
		EXPECT_CALL(*mockEngine2, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();
		EXPECT_CALL(*mockEngine3, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();

		// Seventh advance.
		// No engines advance.

		// Eighth advance.
		EXPECT_CALL(*mockEngine1, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();
		EXPECT_CALL(*mockEngine3, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();

		// Ninth advance.
		EXPECT_CALL(*mockEngine2, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();

		// Tenth advance.
		EXPECT_CALL(*mockEngine3, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();

		// Eleventh advance.
		// No engines advance.

		// Twelfth advance.
		EXPECT_CALL(*mockEngine1, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();
		EXPECT_CALL(*mockEngine2, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();
		EXPECT_CALL(*mockEngine3, advance(_)).WillOnce(Return(vector<shared_ptr<Action> >())).RetiresOnSaturation();

		// Perform test.
		objectUnderTest.init();

		for (int index = 0; index < 5; index++)
		{
			objectUnderTest.advance(vector<shared_ptr<Action> >());
		}

		objectUnderTest.reset();

		for (int index = 0; index < 12; index++)
		{
			objectUnderTest.advance(vector<shared_ptr<Action> >());
		}
	}
}
