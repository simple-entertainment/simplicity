/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <boost/thread.hpp>

#include "OverrunningMockRunnableEngine.h"

using namespace boost;
using namespace devenvy;
using namespace simplicity;
using namespace std;

namespace simplicity
{
  log4cpp::Category& OverrunningMockRunnableEngine::fLogger = log4cpp::Category::getInstance("simplicity::RunnableEngine");

  OverrunningMockRunnableEngine::OverrunningMockRunnableEngine() :
    fAdvanceIndex(0), fMockObject(), fOverrunIndex(-1)
  {
  }

  OverrunningMockRunnableEngine::~OverrunningMockRunnableEngine()
  {
  }

  EngineInput*
  OverrunningMockRunnableEngine::advance(const EngineInput* const input)
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
        fLogger.error("The engine was interrupted while advancing.");
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
  OverrunningMockRunnableEngine::getMethodCall(const int callIndex, const string& name, const vector<any>& parameters) const
  {
    return (fMockObject.getMethodCall(callIndex, name, parameters));
  }

  int
  OverrunningMockRunnableEngine::getMethodCallCount(const string& name, const vector<any>& parameters) const
  {
    return (fMockObject.getMethodCallCount(name, parameters));
  }

  int
  OverrunningMockRunnableEngine::getMethodCallCountIgnoreParams(const string& name) const
  {
    return (fMockObject.getMethodCallCountIgnoreParams(name));
  }

  optional<MethodCall>
  OverrunningMockRunnableEngine::getMethodCallIgnoreParams(const int callIndex, const string& name) const
  {
    return (fMockObject.getMethodCallIgnoreParams(callIndex, name));
  }

  bool
  OverrunningMockRunnableEngine::methodCallOrderCheck(const int beforeCallIndex, const string& beforeMethodName,
      const vector<any>& beforeMethodParameters, const int afterCallIndex, const string& afterMethodName,
      const vector<any>& afterMethodParameters) const
  {
    return (fMockObject.methodCallOrderCheck(beforeCallIndex, beforeMethodName, beforeMethodParameters, afterCallIndex,
        afterMethodName, afterMethodParameters));
  }

  bool
  OverrunningMockRunnableEngine::methodCallOrderCheckIgnoreParams(const int beforeCallIndex, const string& beforeMethodName,
      const int afterCallIndex, const string& afterMethodName) const
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
  OverrunningMockRunnableEngine::setOverrunIndex(const int overrunIndex)
  {
    fOverrunIndex = overrunIndex;
  }
}
