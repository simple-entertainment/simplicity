/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef MOCKPICKLISTENER_H_
#define MOCKPICKLISTENER_H_

#include <gmock/gmock.h>

#include <simplicity/picking/event/PickListener.h>

namespace simplicity
{
  /**
   * <p>
   * A mock implementation of {@link simplicity::MockPickListener MockPickListener}.
   * </p>
   *
   * @author Gary Buyn
   */
  class MockPickListener : public PickListener
  {
    public:
      MOCK_METHOD1(scenePicked, void(const PickEvent& event));
  };
}

#endif /* MOCKPICKLISTENER_H_ */
