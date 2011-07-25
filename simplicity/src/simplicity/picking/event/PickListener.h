/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef PICKLISTENER_H_
#define PICKLISTENER_H_

#include "PickEvent.h"

namespace simplicity
{
  /**
   * <p>
   * A listener for {@link simplicity::PickEvent PickEvent} events.
   * </p>
   *
   * @author Gary Buyn
   */
  class PickListener
  {
    public:
      /**
       * <p>
       * Disposes of an instance of <code>PickListener</code> (included to allow polymorphic deletion).
       * </p>
       */
      virtual
      ~PickListener()
      {
      }

      /**
       * <p>
       * Processes a fired {@link simplicity::PickEvent PickEvent}.
       * </p>
       *
       * @param event The <code>PickEvent</code> to process.
       */
      virtual void
      scenePicked(const PickEvent& event) = 0;
  };
}

#endif /* PICKLISTENER_H_ */
