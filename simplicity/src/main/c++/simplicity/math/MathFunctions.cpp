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
#include "MathFunctions.h"

namespace simplicity
{
	namespace MathFunctions
	{
		bool randomIsSeeded = false;

		float getRandomFloat(float min, float max)
		{
			if (!randomIsSeeded)
			{
				srand((unsigned) time(NULL));
				randomIsSeeded = true;
			}

			return min + (float) rand() / ((float) RAND_MAX / (max - min));
		}

		int getRandomInt(int min, int max)
		{
			if (!randomIsSeeded)
			{
				srand((unsigned) time(NULL));
				randomIsSeeded = true;
			}

			return rand() % (max - min + 1) + min;
		}
	}
}
