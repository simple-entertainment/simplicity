/*
 * Copyright © 2012 Simple Entertainment Limited
 *
 * This file is part of The Simplicity Engine.
 *
 * The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see
 * <http://www.gnu.org/licenses/>.
 */
#ifndef ADDRESSEQUALS_H_
#define ADDRESSEQUALS_H_

#include <functional>
#include <memory>

namespace simplicity
{
	template<class T>
	class AddressEquals
	{
		public:
			AddressEquals(const T& lhs) :
				lhs(lhs)
			{
			}

			bool operator()(const T& rhs) const
			{
				return &lhs == &rhs;
			}

			bool operator()(const std::reference_wrapper<T>& rhs) const
			{
				return &lhs == &rhs.get();
			}

			bool operator()(const std::shared_ptr<T>& rhs) const
			{
				return &lhs == rhs.get();
			}

			bool operator()(const std::unique_ptr<T>& rhs) const
			{
				return &lhs == rhs.get();
			}

		private:
			const T& lhs;
	};
}

#endif /* ADDRESSEQUALS_H_ */
