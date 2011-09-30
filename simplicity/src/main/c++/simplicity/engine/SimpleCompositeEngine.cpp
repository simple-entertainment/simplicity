/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <algorithm>

#include "../SENotSupportedException.h"
#include "SimpleCompositeEngine.h"

using namespace boost;
using namespace std;

namespace simplicity
{
  SimpleCompositeEngine::SimpleCompositeEngine() :
    fEngines()
  {
  }

  SimpleCompositeEngine::~SimpleCompositeEngine()
  {
  }

  void
  SimpleCompositeEngine::addEngine(shared_ptr<Engine> engine)
  {
    fEngines.push_back(engine);
  }

  void
  SimpleCompositeEngine::addEntities(std::vector<boost::shared_ptr<Entity> > entities)
  {
    for (unsigned int index = 0; index < fEngines.size(); index++)
    {
      fEngines.at(index)->addEntities(entities);
    }
  }

  void
  SimpleCompositeEngine::addEntity(boost::shared_ptr<Entity> entity)
  {
    for (unsigned int index = 0; index < fEngines.size(); index++)
    {
      fEngines.at(index)->addEntity(entity);
    }
  }

  shared_ptr<EngineInput>
  SimpleCompositeEngine::advance(const shared_ptr<EngineInput> input)
  {
    fAdvanceIndex++;
    shared_ptr<EngineInput> currentInput = input;

    // For every sub-engine.
    for (unsigned int index = 0; index < fEngines.size(); index++)
    {
      // If the sub-engine should be advanced at this time (if it's preferred frequency is a multiple of the composite frequency).
      if (fAdvanceIndex % (fCompositeFrequency / fEngines.at(index)->getPreferredFrequency()) == 0)
      {
        currentInput = fEngines.at(index)->advance(currentInput);
      }
    }

    return (currentInput);
  }

  int
  SimpleCompositeEngine::calculateLCD(const int big, const int small) const
  {
    int gcd = big;

    if (small != 0)
    {
      gcd = big % small;
    }

    if (gcd == 0)
    {
      return (big);
    }

    return (big * small / gcd);
  }

  void
  SimpleCompositeEngine::destroy()
  {
    for (unsigned int index = 0; index < fEngines.size(); index++)
    {
      fEngines.at(index)->destroy();
    }
  }

  int
  SimpleCompositeEngine::getCompositeFrequency() const
  {
    int newCompositeFrequency = 1;

    if (!fEngines.empty())
    {
      newCompositeFrequency = fEngines.at(0)->getPreferredFrequency();

      // For every sub-engine (except for the first one).
      for (unsigned int index = 0; index < fEngines.size(); index++)
      {
        int preferredFrequency = fEngines.at(index)->getPreferredFrequency();

        // Ensure that preferreFrequency contains the smaller of the two frequencies (required for the calculateLCD method).
        if (newCompositeFrequency < preferredFrequency)
        {
          int temp = newCompositeFrequency;
          newCompositeFrequency = preferredFrequency;
          preferredFrequency = temp;
        }

        newCompositeFrequency = calculateLCD(newCompositeFrequency, preferredFrequency);
      }
    }

    return (newCompositeFrequency);
  }

  void
  SimpleCompositeEngine::initInternal()
  {
    fAdvanceIndex = 0;
    fCompositeFrequency = getCompositeFrequency();

    RunnableEngine::setPreferredFrequency(fCompositeFrequency);
    RunnableEngine::initInternal();

    for (unsigned int index = 0; index < fEngines.size(); index++)
    {
      fEngines.at(index)->init();
    }
  }

  void
  SimpleCompositeEngine::removeEngine(const shared_ptr<Engine> engine)
  {
    vector<shared_ptr<Engine> >::iterator iterator = fEngines.begin();
    for (unsigned int index = 0; index < fEngines.size(); index++)
    {
      if (fEngines.at(index) == engine)
      {
        fEngines.erase(iterator);
        break;
      }

      iterator++;
    }
  }

  void
  SimpleCompositeEngine::reset()
  {
    initInternal();

    for (unsigned int index = 0; index < fEngines.size(); index++)
    {
      fEngines.at(index)->reset();
    }
  }
}
