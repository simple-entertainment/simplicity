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
#include <ctime>

#include "MathFunctions.h"

namespace simplicity
{
	bool randomIsSeeded = false;

	bool getRandomBool()
	{
		return getRandomInt(0, 1) == 1;
	}

	bool getRandomBool(float trueChance)
	{
		return getRandomFloat(0.0f, 1.0f) < trueChance;
	}

	float getRandomFloat(float min, float max)
	{
		if (!randomIsSeeded)
		{
			setRandomSeed((unsigned) time(NULL));
		}

		return min + (float) rand() / ((float) RAND_MAX / (max - min));
	}

	int getRandomInt(int min, int max)
	{
		if (!randomIsSeeded)
		{
			setRandomSeed((unsigned) time(NULL));
		}

		return rand() % (max - min + 1) + min;
	}

	bool near(float a, float b)
	{
		return fabs(a - b) < 0.0001f;
	}

	void setRandomSeed(unsigned int seed)
	{
		srand(seed);
		randomIsSeeded = true;
	}
}
