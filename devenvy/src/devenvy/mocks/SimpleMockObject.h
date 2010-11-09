/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SIMPLEMOCKOBJECT_H_
#define SIMPLEMOCKOBJECT_H_

#include "MockObject.h"

namespace devenvy
{
    /**
     * <p>
     * Implements a mock object that can be used in situations where EasyMock cannot provide a suitable mock. To create a mock object of a specific class,
     * extend / implement it and call {@link ::addMethodCall(string, const vector<void*>)} in each method.
     * </p>
     *
     * @author Gary Buyn
     */
    class SimpleMockObject : public MockObject
    {
        public:
            /**
             * <p>
             * Creates an instance of <code>SimpleMockObject</code>.
             * </p>
             */
            SimpleMockObject();

            /**
             * <p>
             * Disposes of an instance of <code>SimpleMockObject</code>.
             * </p>
             */
            virtual
            ~SimpleMockObject();

            /**
             * <p>
             * Adds a method call that has been made on this <code>SimpleMockObject</code>.
             * </p>
             *
             * @param name The name of the method that has been called on this <code>SimpleMockObject</code>.
             * @param parameters The parameters passed to this <code>SimpleMockObject</code> when the method was called, or <code>null</code> if no parameters were
             *            given.
             */
            void
            addMethodCall(const string& name, const vector<any>& parameters);

            optional<MethodCall>
            getMethodCall(const int& callIndex, const string& name, const vector<any>& parameters);

            int
            getMethodCallCount(const string& name, const vector<any>& parameters);

            int
            getMethodCallCountIgnoreParams(const string& name);

            optional<MethodCall>
            getMethodCallIgnoreParams(const int& callIndex, const string& name);

            bool
            methodCallOrderCheck(const int& beforeCallIndex, const string& beforeMethodName, const vector<any>& beforeMethodParameters,
                    const int& afterCallIndex, const string& afterMethodName, const vector<any>& afterMethodParameters);

            bool
            methodCallOrderCheckIgnoreParams(const int& beforeCallIndex, const string& beforeMethodName, const int& afterCallIndex,
                    const string& afterMethodName);

            void
            reset();

        private:
            /**
             * <p>
             * The method calls that have been made on this <code>SimpleMockObject</code>.
             * </p>
             */
            vector<MethodCall> fMethodCalls;

            /**
             * <p>
             * Checks the equality of the two given sets of parameters.
             * </p>
             *
             * @param parameterSetA The first set of parameters to compare.
             * @param parameterSetB The second set of parameters to compare.
             *
             * @return True if the sets of parameters are equal, false otherwise.
             */
            bool
            parametersEqual(const vector<any>& parameterSetA, const vector<any>& parameterSetB);
    };
}

#endif /* MOCKOBJECT_H_ */
