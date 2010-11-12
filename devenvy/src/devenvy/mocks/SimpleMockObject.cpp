/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include "SimpleMockObject.h"

namespace devenvy
{
    SimpleMockObject::SimpleMockObject() :
        fMethodCalls()
    {
    }

    SimpleMockObject::~SimpleMockObject()
    {
    }

    void
    SimpleMockObject::addMethodCall(const string& name, const vector<any>& parameters)
    {
        MethodCall methodCall;

        methodCall.name = name;
        methodCall.parameters = parameters;

        fMethodCalls.push_back(methodCall);
    }

    optional<MethodCall>
    SimpleMockObject::getMethodCall(const int callIndex, const string& name, const vector<any>& parameters)
    {
        int calls = 0;

        for (unsigned int index = 0; index < fMethodCalls.size(); index++)
        {
            MethodCall methodCall = fMethodCalls.at(index);

            // If the current Method Call is a match.
            if (methodCall.name == name && parametersEqual(methodCall.parameters, parameters))
            {
                // If the correct index has been reached.
                if (calls == callIndex)
                {
                    return (methodCall);
                }

                calls++;
            }
        }

        return (optional<MethodCall> ());
    }

    int
    SimpleMockObject::getMethodCallCount(const string& name, const vector<any>& parameters)
    {
        int methodCallCount = 0;

        for (unsigned int index = 0; index < fMethodCalls.size(); index++)
        {
            MethodCall methodCall = fMethodCalls.at(index);

            // If the current Method Call is a match.
            if (methodCall.name == name && parametersEqual(methodCall.parameters, parameters))
            {
                methodCallCount++;
            }
        }

        return (methodCallCount);
    }

    int
    SimpleMockObject::getMethodCallCountIgnoreParams(const string& name)
    {
        int methodCallCount = 0;

        for (unsigned int index = 0; index < fMethodCalls.size(); index++)
        {
            MethodCall methodCall = fMethodCalls.at(index);

            // If the current Method Call is a match.
            if (methodCall.name == name)
            {
                methodCallCount++;
            }
        }

        return (methodCallCount);
    }

    optional<MethodCall>
    SimpleMockObject::getMethodCallIgnoreParams(const int callIndex, const string& name)
    {
        int calls = 0;

        for (unsigned int index = 0; index < fMethodCalls.size(); index++)
        {
            MethodCall methodCall = fMethodCalls.at(index);

            // If the current Method Call is a match.
            if (methodCall.name == name)
            {
                // If the correct index has been reached.
                if (calls == callIndex)
                {
                    return (methodCall);
                }

                calls++;
            }
        }

        return (optional<MethodCall> ());
    }

    bool
    SimpleMockObject::methodCallOrderCheck(const int beforeCallIndex, const string& beforeMethodName, const vector<any>& beforeMethodParameters,
            const int afterCallIndex, const string& afterMethodName, const vector<any>& afterMethodParameters)
    {
        int beforeCalls = 0;
        int afterCalls = 0;
        bool beforeMethodFound = false;

        for (unsigned int index = 0; index < fMethodCalls.size(); index++)
        {
            MethodCall methodCall = fMethodCalls.at(index);

            // If the current Method Call is a match for the before method.
            if (methodCall.name == beforeMethodName && parametersEqual(methodCall.parameters, beforeMethodParameters))
            {
                // If the before index has been reached.
                if (beforeCalls == beforeCallIndex)
                {
                    beforeMethodFound = true;
                }

                beforeCalls++;
            }

            // If the current Method Call is a match for the after method.
            if (methodCall.name == afterMethodName && parametersEqual(methodCall.parameters, afterMethodParameters))
            {
                // If the after index has been reached.
                if (afterCalls == afterCallIndex)
                {
                    // If the before method has not yet been found.
                    if (!beforeMethodFound)
                    {
                        return (false);
                    }
                    else
                    {
                        return (true);
                    }
                }

                afterCalls++;
            }
        }

        return (false);
    }

    bool
    SimpleMockObject::methodCallOrderCheckIgnoreParams(const int beforeCallIndex, const string& beforeMethodName, const int afterCallIndex,
            const string& afterMethodName)
    {
        int beforeCalls = 0;
        int afterCalls = 0;
        bool beforeMethodFound = false;

        for (unsigned int index = 0; index < fMethodCalls.size(); index++)
        {
            MethodCall methodCall = fMethodCalls.at(index);

            // If the current Method Call is a match for the before method.
            if (methodCall.name == beforeMethodName)
            {
                // If the before index has been reached.
                if (beforeCalls == beforeCallIndex)
                {
                    beforeMethodFound = true;
                }

                beforeCalls++;
            }

            // If the current Method Call is a match for the after method.
            if (methodCall.name == afterMethodName)
            {
                // If the after index has been reached.
                if (afterCalls == afterCallIndex)
                {
                    // If the before method has not yet been found.
                    if (!beforeMethodFound)
                    {
                        return (false);
                    }
                    else
                    {
                        return (true);
                    }
                }

                afterCalls++;
            }
        }

        return (false);
    }

    bool
    SimpleMockObject::parametersEqual(const vector<any>& parameterSetA, const vector<any>& parameterSetB)
    {
        // If the parameter sets have different lengths, return false.
        if (parameterSetA.size() != parameterSetB.size())
        {
            return (false);
        }

        // If the contents of the parameter sets are different, return false.
        for (unsigned int index = 0; index < parameterSetA.size(); index++)
        {
            // Compare types.
            if (parameterSetA.at(index).type() != parameterSetB.at(index).type())
            {
                return (false);
            }

            // TODO Find a way of comparing arbitrary types.

            // Compare strings.
            if (parameterSetA.at(index).type() == typeid(string))
            {
                if (any_cast<string> (parameterSetA.at(index)) != any_cast<string> (parameterSetB.at(index)))
                {
                    return (false);
                }
            }

            // Type is not supported.
            else
            {
                throw std::exception();
            }
        }

        return (true);
    }

    void
    SimpleMockObject::reset()
    {
        fMethodCalls.clear();
    }
}
