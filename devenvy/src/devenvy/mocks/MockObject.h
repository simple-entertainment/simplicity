/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef MOCKOBJECT_H_
#define MOCKOBJECT_H_

#include <vector>
#include <string>
using namespace std;

#include <boost/any.hpp>
#include <boost/optional.hpp>
using namespace boost;

namespace devenvy
{
    /**
     * <p>
     * A method call that has been made to a {@link devenvy::MockObject MockObject}.
     * </p>
     *
     * @author Gary Buyn
     */
    struct MethodCall
    {
        public:
            /**
             * <p>
             * The name of the method called.
             * </p>
             */
            string name;

            /**
             * <p>
             * The parameters passed to the method.
             * </p>
             */
            vector<any> parameters;
    };

    /**
     * <p>
     * A mock object that can be used in situations where EasyMock cannot provide a suitable mock. Can count method calls and assert the number of calls
     * made.
     * </p>
     *
     * @author Gary Buyn
     */
    class MockObject
    {
        public:
            /**
             * <p>
             * Retrieves the nth call made to the given method with the given parameters on this <code>MockObject</code>.
             * </p>
             *
             * @param callIndex The index of the call to return.
             * @param name The name of the method to check the method calls for.
             * @param parameters The parameters to check the method calls for.
             *
             * @return The nth call made to the given method with the given parameters on this <code>MockObject</code>.
             */
            virtual optional<MethodCall>
            getMethodCall(const int callIndex, const string& name, const vector<any>& parameters) = 0;

            /**
             * <p>
             * Retrieves the number of calls made to the given method with the given parameters on this <code>MockObject</code>.
             * </p>
             *
             * @param name The name of the method to check the number of method calls for.
             * @param parameters The parameters to check the number of method calls for.
             *
             * @return The number of calls made to the given method with the given parameters on this <code>MockObject</code>.
             */
            virtual int
            getMethodCallCount(const string& name, const vector<any>& parameters) = 0;

            /**
             * <p>
             * Retrieves the number of calls made to the given method on this <code>MockObject</code>.
             * </p>
             *
             * @param name The name of the method to check the number of method calls for.
             *
             * @return The number of calls made to the given method on this <code>MockObject</code>.
             */
            virtual int
            getMethodCallCountIgnoreParams(const string& name) = 0;

            /**
             * <p>
             * Retrieves the nth call made to the given method on this <code>MockObject</code>.
             * </p>
             *
             * @param callIndex The index of the call to return.
             * @param name The name of the method to check the method calls for.
             *
             * @return The nth call made to the given method on this <code>MockObject</code>.
             */
            virtual optional<MethodCall>
            getMethodCallIgnoreParams(const int callIndex, const string& name) = 0;

            /**
             * <p>
             * Determines whether the nth call to one method with the given parameters was made before the mth call to another method with the given
             * parameters.
             * </p>
             *
             * @param beforeCallIndex The index of the call to the method that is expected to have come before (the nth call). The first call is index 0.
             * @param beforeMethodName The method that is expected to have been called before.
             * @param beforeMethodParameters The parameters of the method that is expected to have been called before.
             * @param afterCallIndex The index of the call to the method that is expected to have come after (the mth call). The first call is index 0.
             * @param afterMethodName The method that is expected to have been called after.
             * @param afterMethodParameters The parameters of the method that is expected to have been called after.
             *
             * @return True if the <code>n</code>th call to one method was made before the <code>m</code>th call to another.
             */
            virtual bool
            methodCallOrderCheck(const int beforeCallIndex, const string& beforeMethodName, const vector<any>& beforeMethodParameters,
                    const int afterCallIndex, const string& afterMethodName, const vector<any>& afterMethodParameters) = 0;

            /**
             * <p>
             * Determines whether the nth call to one method was made before the mth call to another method.
             * </p>
             *
             * @param beforeCallIndex The index of the call to the method that is expected to have come before (the nth call). The first call is index 0.
             * @param beforeMethodName The method that is expected to have been called before.
             * @param afterCallIndex The index of the call to the method that is expected to have come after (the mth call). The first call is index 0.
             * @param afterMethodName The method that is expected to have been called after.
             *
             * @return True if the <code>n</code>th call to one method was made before the <code>m</code>th call to another.
             */
            virtual bool
            methodCallOrderCheckIgnoreParams(const int beforeCallIndex, const string& beforeMethodName, const int afterCallIndex,
                    const string& afterMethodName) = 0;

            /**
             * <p>
             * Resets this <code>MockObject</code>.
             * </p>
             */
            virtual void
            reset() = 0;
    };
}

#endif /* MOCKOBJECT_H_ */
