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
	/**
	 * <p>
	 * A composite engine that advances its contained engines in serial.
	 * </p>
	 */
	class SIMPLE_API SerialCompositeEngine : public CompositeEngine
	{
		public:
			SerialCompositeEngine();

			void addEngine(std::unique_ptr<Engine> engine);

			void advance(Scene& scene) override;

			const std::vector<std::unique_ptr<Engine>>& getEngines() const override;

			void onBeforeOpenScene(Scene& scene) override;

			void onCloseScene(Scene& scene) override;

			void onOpenScene(Scene& scene) override;

			void onPause() override;

			void onPauseScene(Scene& scene) override;

			void onPlay() override;

			void onResume() override;

			void onResumeScene(Scene& scene) override;

			void onStop() override;

			std::unique_ptr<Engine> removeEngine(Engine& engine) override;

		private:
			std::vector<std::unique_ptr<Engine>> engines;
	};
}

#endif /* SERIALCOMPOSITEENGINE_H_ */
