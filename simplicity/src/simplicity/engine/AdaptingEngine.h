/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef ADAPTINGENGINE_H_
#define ADAPTINGENGINE_H_

#include <boost/smart_ptr.hpp>

#include "RunnableEngine.h"

namespace simplicity
{
  /**
   * <p>
   * TODO
   * </p>
   *
   * @author Gary Buyn
   */
  class AdaptingEngine : public RunnableEngine
  {
    public:
      /**
       * <p>
       * Creates an instance of <code>AdaptingEngine</code>.
       * </p>
       *
       * <p>
       * This <code>AdaptingEngine</code> will assume ownership of the given {@link simplicity::Engine Engine}.
       * </p>
       *
       * @param engine The wrapped <code>Engine</code>.
       */
      AdaptingEngine(boost::shared_ptr<Engine> engine);

      /**
       * <p>
       * Disposes of an instance of <code>AdaptingEngine</code>.
       * </p>
       */
      virtual
      ~AdaptingEngine();

      EngineInput*
      advance(const EngineInput* const input);

      void
      destroy();

      /**
       * <p>
       * Retrieves the wrapped {@link simplicity::Engine Engine}.
       * </p>
       *
       * @return The wrapped <code>Engine</code>.
       */
      boost::shared_ptr<Engine>
      getEngine() const;

    private:
      /**
       * <p>
       * The wrapped {@link simplicity::Engine Engine}.
       * </p>
       */
      boost::shared_ptr<Engine> fEngine;
  };
}

#endif /* ADAPTINGENGINE_H_ */