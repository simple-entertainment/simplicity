/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef MOCKCOMPONENT_H_
#define MOCKCOMPONENT_H_

#include <gmock/gmock.h>

#include <simplicity/Component.h>

namespace simplicity
{
  /**
   * <p>
   * A mock implementation of {@link simplicity::Component Component}.
   * </p>
   *
   * @author Gary Buyn
   */
  class MockComponent : public Component
  {
  };
}

#endif /* MOCKCOMPONENT_H_ */
