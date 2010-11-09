/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "SimpleMockObjectTest.h"

namespace devenvy_test
{
    /**
     * <p>
     * Unit test the method {@link devenvy::SimpleMockObject#addMethodCall(const string&, const vector<void*>&) addMethodCall(const string&, const vector<void*>&)}.
     * </p>
     */
    TEST_F(SimpleMockObjectTest, addMethodCall)
    {
        // Create dependencies.
        vector<any> parameters;
        parameters.insert(parameters.end(), string());

        // Perform test.
        fTestObject.addMethodCall("test", parameters);

        // Verify test results.
        ASSERT_TRUE(fTestObject.getMethodCall(0, "test", parameters));
    }

    /**
     * <p>
     * Unit test the method {@link devenvy::SimpleMockObject#getMethodCall(const int&, const string&, const vector<void*>&) getMethodCall(const int&, const string&, const vector<void*>&)}.
     * </p>
     */
    TEST_F(SimpleMockObjectTest, getMethodCall)
    {
        // Create dependencies.
        vector<any> parameters;
        parameters.insert(parameters.end(), string());

        // Initialise test environment.
        fTestObject.addMethodCall("test", parameters);

        // Perform test - Verify test results.
        ASSERT_TRUE(fTestObject.getMethodCall(0, "test", parameters));
    }

    /**
     * <p>
     * Unit test the method {@link devenvy::SimpleMockObject#getMethodCallCount(const string&, const vector<void*>&) getMethodCallCount(const string&, const vector<void*>&)}.
     * </p>
     */
    TEST_F(SimpleMockObjectTest, getMethodCallCount)
    {
        // Create dependencies.
        vector<any> parameters;
        parameters.insert(parameters.end(), string());

        // Perform test 1 - Verify test 1 results.
        ASSERT_EQ(0, fTestObject.getMethodCallCount("test", parameters));

        // Initialise test environment.
        fTestObject.addMethodCall("test", parameters);

        // Perform test 2 - Verify test 2 results.
        ASSERT_EQ(1, fTestObject.getMethodCallCount("test", parameters));

        // Initialise test environment.
        fTestObject.addMethodCall("test", parameters);

        // Perform test 3 - Verify test 3 results.
        ASSERT_EQ(2, fTestObject.getMethodCallCount("test", parameters));
    }

    /**
     * <p>
     * Unit test the method {@link devenvy::SimpleMockObject#getMethodCallCountIgnoreParams(const string&)
     * getMethodCallCountIgnoreParams(const string&)}.
     * </p>
     */
    TEST_F(SimpleMockObjectTest, getMethodCallCountIgnoreParams)
    {
        // Create dependencies.
        vector<any> parameters0;
        vector<any> parameters1;
        parameters1.insert(parameters1.end(), string());
        vector<any> parameters2;
        parameters2.insert(parameters2.end(), string());

        // Perform test 1 - Verify test 1 results.
        ASSERT_EQ(0, fTestObject.getMethodCallCountIgnoreParams("test"));

        // Initialise test environment.
        fTestObject.addMethodCall("test", parameters0);

        // Perform test 2 - Verify test 2 results.
        ASSERT_EQ(1, fTestObject.getMethodCallCountIgnoreParams("test"));

        // Initialise test environment.
        fTestObject.addMethodCall("test", parameters1);

        // Perform test 3 - Verify test 3 results.
        ASSERT_EQ(2, fTestObject.getMethodCallCountIgnoreParams("test"));

        // Initialise test environment.
        fTestObject.addMethodCall("test", parameters2);

        // Perform test 4 - Verify test 4 results.
        ASSERT_EQ(3, fTestObject.getMethodCallCountIgnoreParams("test"));
    }

    /**
     * <p>
     * Unit test the method {@link devenvy::SimpleMockObject#getMethodCallIgnoreParams(const int&, const string&) getMethodCallIgnoreParams(const int&,
     * const string&)}.
     * </p>
     */
    TEST_F(SimpleMockObjectTest, getMethodCallIgnoreParams)
    {
        // Create dependencies.
        vector<any> parameters;
        parameters.insert(parameters.end(), string());

        // Initialise test environment.
        fTestObject.addMethodCall("test", parameters);

        // Perform test - Verify test results.
        ASSERT_TRUE(fTestObject.getMethodCallIgnoreParams(0, "test"));
    }

    /**
     * <p>
     * Unit test the method {@link devenvy::SimpleMockObject#getMethodCallIgnoreParams(const int&, const string&) getMethodCallIgnoreParams(const int&,
     * const string&)} with the special condition that there are multiple identical {@link devenvy::MethodCall MethodCall}s.
     * </p>
     */
    TEST_F(SimpleMockObjectTest, getMethodCallIgnoreParamsMultiple)
    {
        // Initialise test environment.
        fTestObject.addMethodCall("test", vector<any>());
        fTestObject.addMethodCall("test", vector<any>());

        // Perform test - Verify test results.
        ASSERT_TRUE(fTestObject.getMethodCallIgnoreParams(0, "test"));
        ASSERT_TRUE(fTestObject.getMethodCallIgnoreParams(1, "test"));
        // TODO Test that 0 and 1 are not the same MethodCall.
    }

    /**
     * <p>
     * Unit test the method {@link devenvy::SimpleMockObject#getMethodCallIgnoreParams(const int&, const string&) getMethodCallIgnoreParams(const int&,
     * const string&)} with the special condition that a matching {@link devenvy::MethodCall MethodCall} does not exist.
     * </p>
     */
    TEST_F(SimpleMockObjectTest, getMethodCallIgnoreParamsNoneExists)
    {
        // Perform test - Verify test results.
        ASSERT_FALSE(fTestObject.getMethodCallIgnoreParams(0, "test"));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.devenvy.mocks.SimpleMockObject#getMethodCall(const int&, const string&, const vector<void*>&) getMethodCall(const int&, const string&, const vector<void*>&)}
     * with the special condition that there are multiple identical {@link devenvy::MethodCall MethodCall}s.
     * </p>
     */
    TEST_F(SimpleMockObjectTest, getMethodCallMultiple)
    {
        // Initialise test environment.
        vector<any> parameters;
        fTestObject.addMethodCall("test", parameters);
        fTestObject.addMethodCall("test", parameters);

        // Perform test - Verify test results.
        ASSERT_TRUE(fTestObject.getMethodCall(0, "test", parameters));
        ASSERT_TRUE(fTestObject.getMethodCall(1, "test", parameters));
        // TODO Test that 0 and 1 are not the same MethodCall.
    }

    /**
     * <p>
     * Unit test the method {@link devenvy::SimpleMockObject#getMethodCall(const int&, const string&, const vector<void*>&) getMethodCall(const int&, const string&, const vector<void*>&)}
     * with the special condition that a matching {@link devenvy::MethodCall MethodCall} does not exist.
     * </p>
     */
    TEST_F(SimpleMockObjectTest, getMethodCallNoneExists)
    {
        // Perform test - Verify test results.
        ASSERT_FALSE(fTestObject.getMethodCall(0, "test", vector<any>()));
    }

    /**
     * <p>
     * Unit test the method {@link devenvy::SimpleMockObject#methodCallOrderCheck(const int&, const string&, const vector<void*>&, const int&, const string&, const vector<void*>&)
     * methodCallOrderCheck(const int&, const string&, const vector<void*>&, const int&, const string&, const vector<void*>&)}.
     * </p>
     */
    TEST_F(SimpleMockObjectTest, methodCallOrderCheck)
    {
        // Initialise test environment.
        vector<any> parameters0;
        parameters0.insert(parameters0.end(), string());
        vector<any> parameters1;
        parameters1.insert(parameters1.end(), string());

        fTestObject.addMethodCall("test0", parameters0);
        fTestObject.addMethodCall("test1", parameters1);

        // Perform test - Verify test results.
        ASSERT_FALSE(fTestObject.methodCallOrderCheck(0, "test1", parameters1, 0, "test0", parameters0));
        ASSERT_TRUE(fTestObject.methodCallOrderCheck(0, "test0", parameters0, 0, "test1", parameters1));
    }

    /**
     * <p>
     * Unit test the method {@link devenvy::SimpleMockObject#methodCallOrderCheck(const int&, const string&, const vector<void*>&, const int&, const string&, const vector<void*>&)
     * methodCallOrderCheck(const int&, const string&, const vector<void*>&, const int&, const string&, const vector<void*>&)} with the special condition that the after method was never called.
     * </p>
     */
    TEST_F(SimpleMockObjectTest, methodCallOrderCheckAfterNotExists)
    {
        // Initialise test environment.
        vector<any> parameters0;
        parameters0.insert(parameters0.end(), string());
        vector<any> parameters1;
        parameters1.insert(parameters1.end(), string());

        fTestObject.addMethodCall("test0", parameters0);

        // Perform test - Verify test results.
        ASSERT_FALSE(fTestObject.methodCallOrderCheck(0, "test1", parameters1, 0, "test0", parameters0));
        ASSERT_FALSE(fTestObject.methodCallOrderCheck(0, "test0", parameters0, 0, "test1", parameters1));
    }

    /**
     * <p>
     * Unit test the method {@link devenvy::SimpleMockObject#methodCallOrderCheck(const int&, const string&, const vector<void*>&, const int&, const string&, const vector<void*>&)
     * methodCallOrderCheck(const int&, const string&, const vector<void*>&, const int&, const string&, const vector<void*>&)} with the special condition that the before method was never called.
     * </p>
     */
    TEST_F(SimpleMockObjectTest, methodCallOrderCheckBeforeNotExists)
    {
        // Initialise test environment.
        vector<any> parameters0;
        parameters0.insert(parameters0.end(), string());
        vector<any> parameters1;
        parameters1.insert(parameters1.end(), string());

        fTestObject.addMethodCall("test1", parameters1);

        // Perform test - Verify test results.
        ASSERT_FALSE(fTestObject.methodCallOrderCheck(0, "test1", parameters1, 0, "test0", parameters0));
        ASSERT_FALSE(fTestObject.methodCallOrderCheck(0, "test0", parameters0, 0, "test1", parameters1));
    }

    /**
     * <p>
     * Unit test the method {@link devenvy::SimpleMockObject#methodCallOrderCheckIgnoreParams(const int&, const string&, const int&, const string&)
     * methodCallOrderCheckIgnoreParams(const int&, const string&, const int&, const string&)}.
     * </p>
     */
    TEST_F(SimpleMockObjectTest, methodCallOrderCheckIgnoreParams)
    {
        fTestObject.addMethodCall("test0", vector<any>());
        fTestObject.addMethodCall("test1", vector<any>());

        // Perform test - Verify test results.
        ASSERT_FALSE(fTestObject.methodCallOrderCheckIgnoreParams(0, "test1", 0, "test0"));
        ASSERT_TRUE(fTestObject.methodCallOrderCheckIgnoreParams(0, "test0", 0, "test1"));
    }

    /**
     * <p>
     * Unit test the method {@link devenvy::SimpleMockObject#methodCallOrderCheckIgnoreParams(const int&, const string&, const int&, const string&)
     * methodCallOrderCheckIgnoreParams(const int&, const string&, const int&, const string&)} with the special condition that the after method was never called.
     * </p>
     */
    TEST_F(SimpleMockObjectTest, methodCallOrderCheckIgnoreParamsAfterNotExists)
    {
        fTestObject.addMethodCall("test0", vector<any>());

        // Perform test - Verify test results.
        ASSERT_FALSE(fTestObject.methodCallOrderCheckIgnoreParams(0, "test1", 0, "test0"));
        ASSERT_FALSE(fTestObject.methodCallOrderCheckIgnoreParams(0, "test0", 0, "test1"));
    }

    /**
     * <p>
     * Unit test the method {@link devenvy::SimpleMockObject#methodCallOrderCheckIgnoreParams(const int&, const string&, const int&, const string&)
     * methodCallOrderCheckIgnoreParams(const int&, const string&, const int&, const string&)} with the special condition that the before method was never called.
     * </p>
     */
    TEST_F(SimpleMockObjectTest, methodCallOrderCheckIgnoreParamsBeforeNotExists)
    {
        fTestObject.addMethodCall("test1", vector<any>());

        // Perform test - Verify test results.
        ASSERT_FALSE(fTestObject.methodCallOrderCheckIgnoreParams(0, "test1", 0, "test0"));
        ASSERT_FALSE(fTestObject.methodCallOrderCheckIgnoreParams(0, "test0", 0, "test1"));
    }

    /**
     * <p>
     * Unit test the method {@link devenvy::SimpleMockObject#methodCallOrderCheckIgnoreParams(const int&, const string&, const int&, const string&)
     * methodCallOrderCheckIgnoreParams(const int&, const string&, const int&, const string&)} with the special condition that the before and after methods were never called.
     * </p>
     */
    TEST_F(SimpleMockObjectTest, methodCallOrderCheckIgnoreParamsNoneExists)
    {
        // Perform test - Verify test results.
        ASSERT_FALSE(fTestObject.methodCallOrderCheckIgnoreParams(0, "test1", 0, "test0"));
        ASSERT_FALSE(fTestObject.methodCallOrderCheckIgnoreParams(0, "test0", 0, "test1"));
    }

    /**
     * <p>
     * Unit test the method {@link devenvy::SimpleMockObject#methodCallOrderCheckIgnoreParams(const int&, const string&, const int&, const string&)
     * methodCallOrderCheckIgnoreParams(const int&, const string&, const int&, const string&)} with the special condition that the two method calls are the same.
     * </p>
     */
    TEST_F(SimpleMockObjectTest, methodCallOrderCheckIgnoreParamsSame)
    {
        fTestObject.addMethodCall("test", vector<any>());
        fTestObject.addMethodCall("test", vector<any>());

        // Perform test - Verify test results.
        ASSERT_FALSE(fTestObject.methodCallOrderCheckIgnoreParams(1, "test", 0, "test"));
        ASSERT_TRUE(fTestObject.methodCallOrderCheckIgnoreParams(0, "test", 1, "test"));
    }

    /**
     * <p>
     * Unit test the method {@link devenvy::SimpleMockObject#methodCallOrderCheck(const int&, const string&, const vector<void*>&, const int&, const string&, const vector<void*>&)
     * methodCallOrderCheck(const int&, const string&, const vector<void*>&, const int&, const string&, const vector<void*>&)} with the special condition that the before and after methods were never
     * called.
     * </p>
     */
    TEST_F(SimpleMockObjectTest, methodCallOrderCheckNoneExists)
    {
        // Initialise test environment.
        vector<any> parameters0;
        parameters0.insert(parameters0.end(), string());
        vector<any> parameters1;
        parameters1.insert(parameters1.end(), string());

        // Perform test - Verify test results.
        ASSERT_FALSE(fTestObject.methodCallOrderCheck(0, "test1", parameters1, 0, "test0", parameters0));
        ASSERT_FALSE(fTestObject.methodCallOrderCheck(0, "test0", parameters0, 0, "test1", parameters1));
    }

    /**
     * <p>
     * Unit test the method {@link devenvy::SimpleMockObject#methodCallOrderCheck(const int&, const string&, const vector<void*>&, const int&, const string&, const vector<void*>&)
     * methodCallOrderCheck(const int&, const string&, const vector<void*>&, const int&, const string&, const vector<void*>&)} with the special condition that the two method calls are the same.
     * </p>
     */
    TEST_F(SimpleMockObjectTest, methodCallOrderCheckSame)
    {
        // Initialise test environment.
        vector<any> parameters0;
        parameters0.insert(parameters0.end(), string());

        fTestObject.addMethodCall("test", parameters0);
        fTestObject.addMethodCall("test", parameters0);

        // Perform test - Verify test results.
        ASSERT_FALSE(fTestObject.methodCallOrderCheck(1, "test", parameters0, 0, "test", parameters0));
        ASSERT_TRUE(fTestObject.methodCallOrderCheck(0, "test", parameters0, 1, "test", parameters0));
    }

    /**
     * <p>
     * Unit test the method {@link devenvy::SimpleMockObject#parametersEqual(const vector<void*>&, const vector<void*>&) parametersEqual(const vector<void*>&, const vector<void*>&)} with
     * the special condition that one of the arrays is empty.
     * </p>
     */
    TEST_F(SimpleMockObjectTest, parametersEqualEmpty)
    {
        // Create dependencies.
        vector<any> parameters0;
        vector<any> parameters1;
        parameters1.insert(parameters1.end(), string());

        // Initialise test environment.
        fTestObject.addMethodCall("test", parameters0);

        // Perform test - Verify test results.
        ASSERT_FALSE(fTestObject.getMethodCall(0, "test", parameters1));
        ASSERT_TRUE(fTestObject.getMethodCall(0, "test", parameters0));
    }

    /**
     * <p>
     * Unit test the method {@link devenvy::SimpleMockObject#parametersEqual(const vector<void*>&, const vector<void*>&) parametersEqual(const vector<void*>&, const vector<void*>&)} with
     * the special condition that the arrays have different sizes.
     * </p>
     */
    TEST_F(SimpleMockObjectTest, parametersEqualDifferentSizes)
    {
        // Create dependencies.
        vector<any> parameters0;
        parameters0.insert(parameters0.end(), string());
        vector<any> parameters1;
        parameters1.insert(parameters1.end(), string());
        parameters1.insert(parameters1.end(), string());

        // Initialise test environment.
        fTestObject.addMethodCall("test", parameters0);

        // Perform test - Verify test results.
        ASSERT_FALSE(fTestObject.getMethodCall(0, "test", parameters1));
        ASSERT_TRUE(fTestObject.getMethodCall(0, "test", parameters0));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.devenvy.mocks.SimpleMockObject#parametersEqual(const vector<void*>&, const vector<void*>&) parametersEqual(const vector<void*>&, const vector<void*>&)} with
     * the special condition that one of the arrays contains the 'string' type.
     * </p>
     */
    TEST_F(SimpleMockObjectTest, parametersEqualString)
    {
        // Create dependencies.
        vector<any> parameters0;
        vector<any> parameters1;
        parameters1.insert(parameters1.end(), string("test0"));
        vector<any> parameters2;
        parameters2.insert(parameters2.end(), string("test0"));
        vector<any> parameters3;
        parameters3.insert(parameters3.end(), string("test1"));

        // Initialise test environment.
        fTestObject.addMethodCall("test", parameters1);

        // Perform test - Verify test results.
        ASSERT_FALSE(fTestObject.getMethodCall(0, "test", parameters0));
        ASSERT_FALSE(fTestObject.getMethodCall(0, "test", vector<any>()));
        ASSERT_FALSE(fTestObject.getMethodCall(0, "test", parameters3));
        ASSERT_TRUE(fTestObject.getMethodCall(0, "test", parameters1));
        ASSERT_TRUE(fTestObject.getMethodCall(0, "test", parameters2));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.devenvy.mocks.SimpleMockObject#parametersEqual(const vector<void*>&, const vector<void*>&) parametersEqual(const vector<void*>&, const vector<void*>&)} with
     * the special condition that one of the arrays contains an unsupported type.
     * </p>
     */
    TEST_F(SimpleMockObjectTest, parametersEqualUnsupportedType)
    {
        // Create dependencies.
        vector<any> parameters0;
        parameters0.insert(parameters0.end(), vector<string>());

        // Initialise test environment.
        fTestObject.addMethodCall("test", parameters0);

        // Perform test - Verify test results.
        ASSERT_ANY_THROW(fTestObject.getMethodCall(0, "test", parameters0));
    }

    /**
     * <p>
     * Unit test the method {@link devenvy::SimpleMockObject#reset() reset()}.
     * </p>
     */
    TEST_F(SimpleMockObjectTest, reset)
    {
        // Initialise test environment.
        fTestObject.addMethodCall("test", vector<any>());

        // Perform test.
        fTestObject.reset();

        // Verify test results.
        ASSERT_EQ(0, fTestObject.getMethodCallCount("test", vector<any>()));
    }
}
