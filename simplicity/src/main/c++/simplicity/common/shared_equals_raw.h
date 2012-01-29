/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SHARED_EQUALS_RAW_H_
#define SHARED_EQUALS_RAW_H_

#include <memory>

/**
 * <p>
 * A predicate for comparing shared pointers with a raw pointer.
 * </p>
 *
 * @author Gary Buyn
 */
template<class T>
  struct shared_equals_raw
  {
      const T* raw;

      shared_equals_raw(const T* raw) :
        raw(raw)
      {
      }

      bool
      operator()(const std::shared_ptr<T> shared) const
      {
        return (shared.get() == raw);
      }
  };

#endif /* SHARED_EQUALS_RAW_H_ */
