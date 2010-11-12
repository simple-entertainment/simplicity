/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <simplicity/engine/EngineInput.h>
using namespace simplicity;

#include "MockEngine.h"
#include "MockEngineInput.h"
#include "SimpleCompositeEngineTest.h"

namespace simplicity_test
{
    /**
     * <p>
     * Unit test the method {@link simplicity::SimpleCompositeEngine#advance() advance()}.
     * </p>
     */
    TEST_F(SimpleCompositeEngineTest, advance)
    {
        // Create dependencies.
        MockEngine* mockEngine1 = new MockEngine;
        MockEngine* mockEngine2 = new MockEngine;
        MockEngine* mockEngine3 = new MockEngine;

        // Initialise test environment.
        fTestObject.addEngine(mockEngine1);
        fTestObject.addEngine(mockEngine2);
        fTestObject.addEngine(mockEngine3);

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
        EXPECT_CALL(*mockEngine3, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();

        // Third advance.
        EXPECT_CALL(*mockEngine2, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();

        // Fourth advance.
        EXPECT_CALL(*mockEngine1, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();
        EXPECT_CALL(*mockEngine3, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();

        // Fifth advance.
        // No engines advance.

        // Sixth advance.
        EXPECT_CALL(*mockEngine2, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();
        EXPECT_CALL(*mockEngine3, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();

        // Seventh advance.
        // No engines advance.

        // Eighth advance.
        EXPECT_CALL(*mockEngine1, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();
        EXPECT_CALL(*mockEngine3, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();

        // Ninth advance.
        EXPECT_CALL(*mockEngine2, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();

        // Tenth advance.
        EXPECT_CALL(*mockEngine3, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();

        // Eleventh advance.
        // No engines advance.

        // Twelfth advance.
        EXPECT_CALL(*mockEngine1, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();
        EXPECT_CALL(*mockEngine2, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();
        EXPECT_CALL(*mockEngine3, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();

        // Thirteenth advance.
        // No engines advance.

        // Fourteenth advance.
        EXPECT_CALL(*mockEngine3, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();

        // Fifteenth advance.
        EXPECT_CALL(*mockEngine2, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();

        // Sixteenth advance.
        EXPECT_CALL(*mockEngine1, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();
        EXPECT_CALL(*mockEngine3, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();

        // Seventeenth advance.
        // No engines advance.);

        // Eighteenth advance.
        EXPECT_CALL(*mockEngine2, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();
        EXPECT_CALL(*mockEngine3, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();

        // Nineteenth advance.
        // No engines advance.

        // Twentieth advance.
        EXPECT_CALL(*mockEngine1, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();
        EXPECT_CALL(*mockEngine3, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();

        // Twenty First advance.
        EXPECT_CALL(*mockEngine2, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();

        // Twenty Second advance.
        EXPECT_CALL(*mockEngine3, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();

        // Twenty Third advance.
        // No engines advance.

        // Twenty Fourth advance.
        EXPECT_CALL(*mockEngine1, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();
        EXPECT_CALL(*mockEngine2, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();
        EXPECT_CALL(*mockEngine3, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();

        // Perform test.
        fTestObject.init();

        for (int index = 0; index < 24; index++)
        {
            fTestObject.advance(NULL);
        }

        // Cleanup.
        delete mockEngine1;
        delete mockEngine2;
        delete mockEngine3;
    }

    /**
     * <p>
     * Unit test the method {@link simplicity::SimpleCompositeEngine#advance(EngineInput* const) advance(EngineInput* const)}, specifically the
     * functionality that passes the {@link simplicity::EngineInput EngineInput} from one {@link simplicity::Engine Engine}
     * to the next.
     * </p>
     */
    TEST_F(SimpleCompositeEngineTest, advancePassEngineInput)
    {
        // Create dependencies.
        MockEngine* mockEngine1 = new MockEngine;
        MockEngine* mockEngine2 = new MockEngine;
        MockEngine* mockEngine3 = new MockEngine;
        MockEngineInput* mockInput0 = new MockEngineInput;
        MockEngineInput* mockInput1 = new MockEngineInput;
        MockEngineInput* mockInput2 = new MockEngineInput;
        MockEngineInput* mockInput3 = new MockEngineInput;

        // Dictate correct behaviour.
        EXPECT_CALL(*mockEngine1, getPreferredFrequency()).WillRepeatedly(Return(1));
        EXPECT_CALL(*mockEngine2, getPreferredFrequency()).WillRepeatedly(Return(1));
        EXPECT_CALL(*mockEngine3, getPreferredFrequency()).WillRepeatedly(Return(1));
        EXPECT_CALL(*mockEngine1, init());
        EXPECT_CALL(*mockEngine2, init());
        EXPECT_CALL(*mockEngine3, init());

        // Initialise test environment.
        fTestObject.addEngine(mockEngine1);
        fTestObject.addEngine(mockEngine2);
        fTestObject.addEngine(mockEngine3);
        fTestObject.init();

        // Dictate expected results.
        EXPECT_CALL(*mockEngine1, advance(mockInput0)).WillOnce(Return(mockInput1));
        EXPECT_CALL(*mockEngine2, advance(mockInput1)).WillOnce(Return(mockInput2));
        EXPECT_CALL(*mockEngine3, advance(mockInput2)).WillOnce(Return(mockInput3));

        // Perform test.
        fTestObject.advance(mockInput0);

        // Cleanup.
        delete mockEngine1;
        delete mockEngine2;
        delete mockEngine3;
        delete mockInput0;
        delete mockInput1;
        delete mockInput2;
        delete mockInput3;
    }

    /**
     * <p>
     * Unit test the method {@link simplicity::SimpleCompositeEngine#getCompositeFrequency() getCompositeFrequency()}.
     * </p>
     */
    TEST_F(SimpleCompositeEngineTest, getCompositeFrequency)
    {
        // Create dependencies.
        MockEngine* mockEngine1 = new MockEngine;
        MockEngine* mockEngine2 = new MockEngine;
        MockEngine* mockEngine3 = new MockEngine;

        // Dictate correct behaviour.
        EXPECT_CALL(*mockEngine1, getPreferredFrequency()).WillRepeatedly(Return(3));
        EXPECT_CALL(*mockEngine2, getPreferredFrequency()).WillRepeatedly(Return(4));
        EXPECT_CALL(*mockEngine3, getPreferredFrequency()).WillRepeatedly(Return(6));
        EXPECT_CALL(*mockEngine1, init());
        EXPECT_CALL(*mockEngine2, init());
        EXPECT_CALL(*mockEngine3, init());

        // Initialise test environment.
        fTestObject.addEngine(mockEngine1);
        fTestObject.addEngine(mockEngine2);
        fTestObject.addEngine(mockEngine3);
        fTestObject.init();

        // Perform test - Verify test results.
        ASSERT_EQ(12, fTestObject.getPreferredFrequency());

        // Cleanup.
        delete mockEngine1;
        delete mockEngine2;
        delete mockEngine3;
    }

    /**
     * <p>
     * Unit test the method {@link simplicity::SimpleCompositeEngine#getCompositeFrequency() getCompositeFrequency()} with the special
     * condition that the {@link simplicity::SimpleCompositeEngine SimpleCompositeEngine} being tested does not have any sub-engines.
     * </p>
     */
    TEST_F(SimpleCompositeEngineTest, getCompositeFrequencyNoEngines)
    {
        // Perform test - Verify test results.
        ASSERT_EQ(1, fTestObject.getPreferredFrequency());
    }

    /**
     * <p>
     * Unit test the method {@link simplicity::SimpleCompositeEngine#reset() reset()}.
     * </p>
     */
    TEST_F(SimpleCompositeEngineTest, reset)
    {
        // Create dependencies.
        MockEngine* mockEngine1 = new MockEngine;
        MockEngine* mockEngine2 = new MockEngine;
        MockEngine* mockEngine3 = new MockEngine;

        // Initialise test environment.
        fTestObject.addEngine(mockEngine1);
        fTestObject.addEngine(mockEngine2);
        fTestObject.addEngine(mockEngine3);

        // Dictate correct behaviour.
        EXPECT_CALL(*mockEngine1, getPreferredFrequency()).WillRepeatedly(Return(3));
        EXPECT_CALL(*mockEngine2, getPreferredFrequency()).WillRepeatedly(Return(4));
        EXPECT_CALL(*mockEngine3, getPreferredFrequency()).WillRepeatedly(Return(6));
        EXPECT_CALL(*mockEngine1, init()).Times(2);
        EXPECT_CALL(*mockEngine2, init()).Times(2);
        EXPECT_CALL(*mockEngine3, init()).Times(2);

        // Dictate expected results.
        // First advance.
        // No engines advance.

        // Second advance.
        EXPECT_CALL(*mockEngine3, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();

        // Third advance.
        EXPECT_CALL(*mockEngine2, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();

        // Fourth advance.
        EXPECT_CALL(*mockEngine1, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();
        EXPECT_CALL(*mockEngine3, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();

        // Fifth advance.
        // No engines advance.

        // Reset.
        EXPECT_CALL(*mockEngine1, reset());
        EXPECT_CALL(*mockEngine2, reset());
        EXPECT_CALL(*mockEngine3, reset());

        // First advance.
        // No engines advance.

        // Second advance.
        EXPECT_CALL(*mockEngine3, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();

        // Third advance.
        EXPECT_CALL(*mockEngine2, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();

        // Fourth advance.
        EXPECT_CALL(*mockEngine1, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();
        EXPECT_CALL(*mockEngine3, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();

        // Fifth advance.
        // No engines advance.

        // Sixth advance.
        EXPECT_CALL(*mockEngine2, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();
        EXPECT_CALL(*mockEngine3, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();

        // Seventh advance.
        // No engines advance.

        // Eighth advance.
        EXPECT_CALL(*mockEngine1, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();
        EXPECT_CALL(*mockEngine3, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();

        // Ninth advance.
        EXPECT_CALL(*mockEngine2, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();

        // Tenth advance.
        EXPECT_CALL(*mockEngine3, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();

        // Eleventh advance.
        // No engines advance.

        // Twelfth advance.
        EXPECT_CALL(*mockEngine1, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();
        EXPECT_CALL(*mockEngine2, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();
        EXPECT_CALL(*mockEngine3, advance(NULL)).WillOnce(Return((EngineInput*) NULL)).RetiresOnSaturation();

        // Perform test.
        fTestObject.init();

        for (int index = 0; index < 5; index++)
        {
            fTestObject.advance(NULL);
        }

        fTestObject.reset();

        for (int index = 0; index < 12; index++)
        {
            fTestObject.advance(NULL);
        }

        // Cleanup.
        delete mockEngine1;
        delete mockEngine2;
        delete mockEngine3;
    }
}
