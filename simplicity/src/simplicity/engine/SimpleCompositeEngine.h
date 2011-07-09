/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SIMPLECOMPOSITEENGINE_H_
#define SIMPLECOMPOSITEENGINE_H_

#include <vector>
using namespace std;

#include "CompositeEngine.h"
#include "Engine.h"
#include "RunnableEngine.h"

namespace simplicity
{
  /**
   * <p>
   * Manages its sub-engines by running at the lowest common frequency (advancements per second) of these sub-engines and advancing them at their
   * preferred frequency.
   * </p>
   *
   * @author Gary Buyn
   */
  class SimpleCompositeEngine : public RunnableEngine, public CompositeEngine
  {
    public:
      /**
       * <p>
       * Creates an instance of <code>SimpleCompositeEngine</code>.
       * </p>
       */
      SimpleCompositeEngine();

      /**
       * <p>
       * Disposes of an instance of <code>SimpleCompositeEngine</code>.
       * </p>
       */
      virtual
      ~SimpleCompositeEngine();

      void
      addEngine(Engine const * const engine);

      EngineInput *
      advance(EngineInput const * const input);

      void
      destroy();

      void
      removeEngine(Engine const * const engine);

      void
      reset();

    private:
      /**
       * <p>
       * Calculates the lowest common denominator of the two integer values given.
       * </p>
       *
       * @param a The largest of the two integers to calculate the lowest common denominator of.
       * @param b The smallest of the two integers to calculate the lowest common denominator of.
       *
       * @return The lowest common denominator of the two integer values given.
       */
      int
      calculateLCD(int const a, int const b) const;

      /**
       * <p>
       * Retrieves the lowest common frequency (advancements per second) at which this <code>SimpleCompositeEngine</code> can run that will support the
       * preferred frequencies of its sub-engines.
       * </p>
       *
       * @return the lowest common frequency (advancements per second) at which this <code>SimpleCompositeEngine</code> can run that will support the
       * preferred frequencies of its sub-engines.
       */
      int
      getCompositeFrequency() const;

      /**
       * <p>
       * Initialises the internal components of this <code>SimpleCompositeEngine</code> only. Does not initialise the sub-engines.
       * </p>
       */
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
       * The lowest common frequency (advancements per second) at which this <code>SimpleCompositeEngine</code> can run that will support the preferred
       * frequencies of its sub-engines.
       * </p>
       */
      int fCompositeFrequency;

      /**
       * <p>
       * The sub-engines managed by this <code>SimpleCompositeEngine</code>.
       * </p>
       */
      vector<Engine *> fEngines;
  };
}

#endif /* SIMPLECOMPOSITEENGINE_H_ */
