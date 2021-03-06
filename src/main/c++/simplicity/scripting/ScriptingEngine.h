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
#ifndef SCRIPTINGENGINE_H_
#define SCRIPTINGENGINE_H_

#include <map>

#include "../engine/Engine.h"
#include "ScriptingEngineState.h"

namespace simplicity
{
	/**
	 * <p>
	 * An engine that executes scripts every frame.
	 * </p>
	 */
	class SIMPLE_API ScriptingEngine : public Engine
	{
		public:
			ScriptingEngine();

			void advance(Scene& scene) override;

			void onBeforeOpenScene(Scene& scene) override;

			void onCloseScene(Scene& scene) override;

			void onOpenScene(Scene& scene) override;

			void onPauseScene(Scene& scene) override;

			void onResumeScene(Scene& scene) override;

		private:
			std::map<Scene*, ScriptingEngineState*> state;
	};
}

#endif /* SCRIPTINGENGINE_H_ */
