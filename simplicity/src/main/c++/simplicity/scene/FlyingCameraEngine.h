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
#ifndef FLYINGCAMERAENGINE_H_
#define FLYINGCAMERAENGINE_H_

#include <map>

#include "../engine/Engine.h"
#include "../input/Button.h"
#include "../input/Keyboard.h"

namespace simplicity
{
	class SIMPLE_API FlyingCameraEngine : public Engine
	{
		public:
			FlyingCameraEngine(Entity& camera);

			void addEntity(Entity& entity);

			void advance();

			void destroy();

			void init();

			void removeEntity(const Entity& entity);

		private:
			std::map<Keyboard::Button, Button::State> buttonStates;

			Entity& camera;

			int x;

			int y;

			void onKeyboardButton(const void* message);

			void onMouseMove(const void* message);
	};
}

#endif /* FLYINGCAMERAENGINE_H_ */
