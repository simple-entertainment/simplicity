/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <exception>
#include <string>
using namespace std;

#include <boost/date_time.hpp>
#include <boost/thread.hpp>
#include <log4cpp/Category.hh>
using namespace boost;
using namespace boost::posix_time;
using namespace boost::this_thread;
using namespace log4cpp;

#include "../SENotSupportedException.h"
#include "RunnableEngine.h"

namespace simplicity
{
  Category * RunnableEngine::fLogger = &Category::getInstance("simplicity::RunnableEngine");

  RunnableEngine::RunnableEngine() :
    fPreferredFrequency(1), fSleepTime(0L)
  {
  }

  RunnableEngine::~RunnableEngine()
  {
  }

  int
  RunnableEngine::getPreferredFrequency() const
  {
    return (fPreferredFrequency);
  }

  void
  RunnableEngine::init()
  {
    initInternal();
  }

  void
  RunnableEngine::initInternal()
  {
    fInterrupted = false;
    fSleepTime = (long) (MILLISECONDS_IN_A_SECOND / fPreferredFrequency);
  }

  void
  RunnableEngine::run()
  {
    init();

    // Start by sleeping.
    ptime beforeAdvanceTime;
    long adjustedSleepTime = sleep(fSleepTime);

    // While the engine has not been interrupted.
    while (!fInterrupted)
      {
        // Interrupt the engine if the thread has been interrupted.
        interruption_point();

        beforeAdvanceTime = microsec_clock::local_time();

        try
          {
            advance(NULL);
          }
        catch (std::exception& e)
          {
            // Interrupt the engine.
            fInterrupted = true;
            fLogger->error("Failed to advance the engine.");
          }

        // Subtract the time taken to advance the engine from the time it needs to sleep for.
        adjustedSleepTime -= time_period(beforeAdvanceTime, microsec_clock::local_time()).length().total_milliseconds();

        // Sleep until the next advancement is due.
        adjustedSleepTime = sleep(adjustedSleepTime);
      }

    destroy();
  }

  void
  RunnableEngine::setPreferredFrequency(int const preferredFrequency)
  {
    fPreferredFrequency = preferredFrequency;
  }

  long
  RunnableEngine::sleep(long const adjustedSleepTime)
  {
    // If the engine needs to sleep.
    if (adjustedSleepTime > 0)
      {
        try
          {
            this_thread::sleep(milliseconds(adjustedSleepTime));
          }
        catch (thread_interrupted& e)
          {
            // Interrupt the engine.
            fInterrupted = true;
            fLogger->debug("The engine was interrupted while sleeping.");
          }

        // Return the standard sleep duration.
        return (fSleepTime);
      }
    else
      {
        fLogger->warn("The engine ran over time.");

        // The engine has not slept as a result it has 'caught up' by the standard sleep duration.
        return (adjustedSleepTime + fSleepTime);
      }
  }
}
