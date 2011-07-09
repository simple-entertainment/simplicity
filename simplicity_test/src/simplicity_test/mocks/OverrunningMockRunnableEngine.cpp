/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <boost/thread.hpp>
using namespace boost;

#include "OverrunningMockRunnableEngine.h"

namespace simplicity_test
{
  Category * OverrunningMockRunnableEngine::fLogger = &Category::getInstance("simplicity::RunnableEngine");

  OverrunningMockRunnableEngine::OverrunningMockRunnableEngine() :
    fAdvanceIndex(0), fMockObject(), fOverrunIndex(-1)
  {
  }

  OverrunningMockRunnableEngine::~OverrunningMockRunnableEngine()
  {
  }

  EngineInput *
  OverrunningMockRunnableEngine::advance(EngineInput const * const input)
  {
    fMockObject.addMethodCall("advance", vector<any> ());

    if (++fAdvanceIndex == fOverrunIndex)
      {
        try
          {
            this_thread::sleep(
                posix_time::milliseconds(MILLISECONDS_IN_A_SECOND / getPreferredFrequency() * FRACTION_OF_FREQUENCY_TO_WAIT));
          }
        catch (thread_interrupted& e)
          {
            fLogger->error("The engine was interrupted while advancing.");
          }
      }

    return (NULL);
  }

  void
  OverrunningMockRunnableEngine::destroy()
  {
    fMockObject.addMethodCall("destroy", vector<any> ());
  }

  optional<MethodCall>
  OverrunningMockRunnableEngine::getMethodCall(int const callIndex, string const & name, vector<any> const & parameters) const
  {
    return (fMockObject.getMethodCall(callIndex, name, parameters));
  }

  int
  OverrunningMockRunnableEngine::getMethodCallCount(string const & name, vector<any> const & parameters) const
  {
    return (fMockObject.getMethodCallCount(name, parameters));
  }

  int
  OverrunningMockRunnableEngine::getMethodCallCountIgnoreParams(string const & name) const
  {
    return (fMockObject.getMethodCallCountIgnoreParams(name));
  }

  optional<MethodCall>
  OverrunningMockRunnableEngine::getMethodCallIgnoreParams(int const callIndex, string const & name) const
  {
    return (fMockObject.getMethodCallIgnoreParams(callIndex, name));
  }

  bool
  OverrunningMockRunnableEngine::methodCallOrderCheck(int const beforeCallIndex, string const & beforeMethodName,
      vector<any> const & beforeMethodParameters, int const afterCallIndex, string const & afterMethodName,
      vector<any> const & afterMethodParameters) const
  {
    return (fMockObject.methodCallOrderCheck(beforeCallIndex, beforeMethodName, beforeMethodParameters, afterCallIndex,
        afterMethodName, afterMethodParameters));
  }

  bool
  OverrunningMockRunnableEngine::methodCallOrderCheckIgnoreParams(int const beforeCallIndex, string const & beforeMethodName,
      int const afterCallIndex, string const & afterMethodName) const
  {
    return (fMockObject.methodCallOrderCheckIgnoreParams(beforeCallIndex, beforeMethodName, afterCallIndex, afterMethodName));
  }

  int
  OverrunningMockRunnableEngine::getOverrunIndex() const
  {
    return (fOverrunIndex);
  }

  void
  OverrunningMockRunnableEngine::initInternal()
  {
    fMockObject.addMethodCall("init", vector<any> ());

    RunnableEngine::initInternal();
  }

  void
  OverrunningMockRunnableEngine::reset()
  {
    fMockObject.addMethodCall("reset", vector<any> ());

    fMockObject.reset();
  }

  void
  OverrunningMockRunnableEngine::setOverrunIndex(int const overrunIndex)
  {
    fOverrunIndex = overrunIndex;
  }
}
