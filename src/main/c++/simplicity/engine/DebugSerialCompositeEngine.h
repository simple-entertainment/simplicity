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
#ifndef DEBUGSERIALCOMPOSITEENGINE_H_
#define DEBUGSERIALCOMPOSITEENGINE_H_

#include <chrono>

#include "CompositeEngine.h"

namespace simplicity
{
	/**
	 * <p>
	 * A composite engine that advances its contained engines in serial.
	 * </p>
	 *
	 * <p>
	 * Provides debug information about the running times of the contained engines.
	 * </p>
	 */
	class SIMPLE_API DebugSerialCompositeEngine : public CompositeEngine
	{
		public:
			DebugSerialCompositeEngine();

			void addEngine(std::unique_ptr<Engine> engine);

			void advance() override;

			/**
			 * <p>
			 * Retrieves the times spent by the individual contained engines during the previous frame.
			 * </p>
			 *
			 * @return The times spent by the individual contained engines during the previous frame.
			 */
			const std::vector<float>& getEngineFrameTimes() const;

			const std::vector<std::unique_ptr<Engine>>& getEngines() const override;

			/**
			 * <p>
			 * Retrieves the number of advances by this engine in the last full second.
			 * </p>
			 *
			 * @return The number of advances by this engine in the last full second.
			 */
			unsigned int getFramesPerSecond() const;

			/**
			 * <p>
			 * Retrieves the times spent by this engine during the previous frame.
			 * </p>
			 *
			 * @return The times spent by this engine during the previous frame.
			 */
			float getFrameTime() const;

			void onAddEntity(Entity& entity) override;
			
			void onCloseScene(Scene& scene) override;

			void onOpenScene(Scene& scene) override;

			void onPause() override;

			void onPauseScene(Scene& scene) override;

			void onPlay() override;

			void onRemoveEntity(Entity& entity) override;

			void onResume() override;

			void onResumeScene(Scene& scene) override;

			void onStop() override;

			std::unique_ptr<Engine> removeEngine(Engine* engine) override;

		private:
			std::vector<float> engineFrameTimes;

			std::vector<std::unique_ptr<Engine>> engines;

			unsigned int frameCount;

			unsigned int framesPerSecond;

			float frameTime;

			std::chrono::time_point<std::chrono::high_resolution_clock> lastFrameCountTime;
	};
}

#endif /* DEBUGSERIALCOMPOSITEENGINE_H_ */
