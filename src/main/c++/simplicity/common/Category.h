/*
 * Copyright © 2014 Simple Entertainment Limited
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
#ifndef CATEGORY_H_
#define CATEGORY_H_

namespace simplicity
{
	namespace Category
	{
		/**
		 * <p>
		 * Denotes that no category is assigned.
		 * </p>
		 */
		static const unsigned short UNCATEGORIZED = 0;

		/**
		 * <p>
		 * Includes all categories, even UNCATEGORIZED.
		 * </p>
		 */
		static const unsigned short ALL_CATEGORIES = 1;

		/**
		 * <p>
		 * User defined categories should start with this ID.
		 * </p>
		 *
		 * <p>
		 * For example:
		 * </p>
		 *
		 * <pre><code>
		 * const unsigned short MY_CATEGORY_1 = USER_ID_0;
		 * const unsigned short MY_CATEGORY_2 = USER_ID_0 + 1;
		 * </code></pre>
		 */
		static const unsigned short USER_ID_0 = 128;
	}
}

#endif /* CATEGORY_H_ */
