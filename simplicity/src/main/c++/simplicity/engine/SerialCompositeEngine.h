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
#ifndef SERIALCOMPOSITEENGINE_H_
#define SERIALCOMPOSITEENGINE_H_

#include "CompositeEngine.h"

namespace simplicity
{
	class SerialCompositeEngine : public CompositeEngine
	{
		public:
			SerialCompositeEngine();

			void addEngine(std::unique_ptr<Engine> engine);

			void addEntity(Entity& entity);

			void advance();

			void destroy();

			void init();

			std::unique_ptr<Engine> removeEngine(Engine* engine);

			void removeEntity(const Entity& entity);

		private:
			std::vector<std::unique_ptr<Engine>> engines;
	};
}

#endif /* SERIALCOMPOSITEENGINE_H_ */
