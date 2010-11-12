/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include "../SENotSupportedException.h"
#include "SimpleCompositeEngine.h"

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
    SimpleCompositeEngine::addEngine(Engine* const engine)
    {
        fEngines.push_back(engine);
    }

    EngineInput*
    SimpleCompositeEngine::advance(EngineInput* const input)
    {
        fAdvanceIndex++;
        EngineInput* currentInput = input;

        for (unsigned int index = 0; index < fEngines.size(); index++)
        {
            if (fAdvanceIndex % (fCompositeFrequency / fEngines.at(index)->getPreferredFrequency()) == 0)
            {
                currentInput = fEngines.at(index)->advance(currentInput);
            }
        }

        return (currentInput);
    }

    int
    SimpleCompositeEngine::calculateLCD(const int a, const int b)
    {
        int gcd = a;

        if (b != 0)
        {
            gcd = a % b;
        }

        if (gcd == 0)
        {
            return (a);
        }

        return (a * b / gcd);
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
    SimpleCompositeEngine::getCompositeFrequency()
    {
        int newCompositeFrequency = 1;

        if (!fEngines.empty())
        {
            newCompositeFrequency = fEngines.at(0)->getPreferredFrequency();

            for (unsigned int index = 0; index < fEngines.size(); index++)
            {
                int preferredFrequency = fEngines.at(index)->getPreferredFrequency();

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
    SimpleCompositeEngine::removeEngine(Engine* const engine)
    {
        vector<Engine*>::iterator iterator = fEngines.begin();
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
