/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SEENGINEADVANCEMENTEXCEPTION_H_
#define SEENGINEADVANCEMENTEXCEPTION_H_

#include <exception>

namespace simplicity
{
  /**
   * <p>
   * An exception thrown by The Simplicity Engine. Signifies that an {@link com.se.simplicity.engine.Engine Engine} failed to advance.
   * </p>
   *
   * @author Gary Buyn
   */
  class SEEngineAdvancementException : public std::exception
  {
    public:
      virtual char const *
      what() const throw ();
  };
}

#endif /* SEENGINEADVANCEMENTEXCEPTION_H_ */
