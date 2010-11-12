/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef OVERRUNNINGMOCKENGINE_H_
#define OVERRUNNINGMOCKENGINE_H_

#include <log4cpp/Category.hh>
using namespace log4cpp;

#include <devenvy/mocks/SimpleMockObject.h>
#include <simplicity/engine/Engine.h>
#include <simplicity/engine/RunnableEngine.h>
using namespace devenvy;
using namespace simplicity;

namespace simplicity_test
{
    /**
     * <p>
     * A mock engine that does not perform any work except to sleep for 1.5 times its preferred frequency the third time it advances. Used to test the
     * behaviour of composite engines when one or more of their sub-engines runs over time.
     * </p>
     *
     * @author Gary Buyn
     */
    class OverrunningMockRunnableEngine : public RunnableEngine, public MockObject
    {
        public:
            /**
             * <p>
             * Creates an instance of <code>OverrunningMockRunnableEngine</code>.
             * </p>
             */
            OverrunningMockRunnableEngine();

            /**
             * <p>
             * Disposes of an instance of <code>OverrunningMockRunnableEngine</code>.
             * </p>
             */
            virtual
            ~OverrunningMockRunnableEngine();

            EngineInput*
            advance(EngineInput* const input);

            void
            destroy();

            optional<MethodCall>
            getMethodCall(const int callIndex, const string& name, const vector<any>& parameters);

            int
            getMethodCallCount(const string& name, const vector<any>& parameters);

            int
            getMethodCallCountIgnoreParams(const string& name);

            optional<MethodCall>
            getMethodCallIgnoreParams(const int callIndex, const string& name);

            bool
            methodCallOrderCheck(const int beforeCallIndex, const string& beforeMethodName, const vector<any>& beforeMethodParameters,
                    const int afterCallIndex, const string& afterMethodName, const vector<any>& afterMethodParameters);

            bool
            methodCallOrderCheckIgnoreParams(const int beforeCallIndex, const string& beforeMethodName, const int afterCallIndex,
                    const string& afterMethodName);

            /**
             * <p>
             * Retrieves the index of the advancement in which this engine will overrun.
             * </p>
             *
             * @return The index of the advancement in which this engine will overrun.
             */
            int
            getOverrunIndex();

            void
            reset();

            /**
             * <p>
             * Sets the index of the advancement in which this engine will overrun.
             * </p>
             *
             * @param overrunIndex The index of the advancement in which this engine will overrun.
             */
            void
            setOverrunIndex(const int overrunIndex);

        private:
            /**
             * <p>
             * The fraction of the preferred frequency this <code>MockEngine</code> should wait. This should be above 1 to test over-running the frequency.
             * </p>
             */
            static const double FRACTION_OF_FREQUENCY_TO_WAIT = 1.5;

            /**
             * <p>
             * Logs messages associated with this class.
             * </p>
             */
            static Category* fLogger;

            /**
             * <p>
             * The number of milliseconds in a second.
             * </p>
             */
            static const double MILLISECONDS_IN_A_SECOND = 1000.0;

            void
            initInternal();

            /**
             * <p>
             * The index of the current advancement.
             * </p>
             */
            int fAdvanceIndex;

            /**
             * <p>
             * Performs actual mocking.
             * </p>
             */
            SimpleMockObject fMockObject;

            /**
             * <p>
             * The index of the advancement in which this engine will overrun.
             * </p>
             */
            int fOverrunIndex;
    };
}

#endif /* OVERRUNNINGMOCKENGINE_H_ */
