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
#ifndef SIMPLICITY_H_
#define SIMPLICITY_H_

#include "engine/CompositeEngine.h"
#include "engine/Engine.h"
#include "graph/Graph.h"
#include "scene/Scene.h"

namespace simplicity
{
	namespace Simplicity
	{
		/**
		 * <p>
		 * Adds an engine to simplicity.
		 * </p>
		 *
		 * @param engine The engine.
		 */
		void addEngine(std::unique_ptr<Engine> engine);

		/**
		 * <p>
		 * Adds a scene to simplicity. The first scene added will be the initial scene.
		 * </p>
		 *
		 * @param name The name of the scene.
		 * @param scene The scene.
		 */
		void addScene(const std::string& name, std::unique_ptr<Scene> scene);

		/**
		 * <p>
		 * Retrieves the composite engine to which all other engines will be added.
		 * </p>
		 *
		 * @return The composite engine.
		 */
		CompositeEngine* getCompositeEngine();

        /**
         * <p>
         * Retrieves the elapsed time since the last frame.
         * </p>
         *
         * @return The elapsed time since the last frame.
         */
		float getDeltaTime();

		/**
		 * <p>
		 * Retrieves a single engine. If more than one engine of the specified type exist, the first one found will be
		 * returned.
		 * </p>
		 *
		 * @return The single engine.
		 */
		template<typename EngineType>
		EngineType* getEngine();

		/**
		 * <p>
		 * Retrieves the engines.
		 * </p>
		 *
		 * @return The engines.
		 */
		template<typename EngineType>
		std::vector<EngineType*> getEngines();

        /**
         * <p>
         * Retrieves the maximum frame rate allowed by simplicity. A value of 0 signifies that there is no maximum
         * frame rate.
         * </p>
         *
         * @return The maximum frame rate allowed by simplicity.
         */
		unsigned short getMaxFrameRate();

		/**
		 * <p>
		 * Retrieves the current scene.
		 * </p>
		 *
		 * @return The current scene.
		 */
		Scene* getScene();

        /**
         * <p>
         * Retrieves the elapsed time since simplicity started playing.
         * </p>
         *
         * @return The elapsed time since simplicity started playing.
         */
		float getTotalTime();

		/**
		 * <p>
		 * Opens a scene.
		 * </p>
		 *
		 * @param name The name of the scene to open.
		 */
		void openScene(const std::string& name);

		/**
		 * <p>
		 * Pauses all engines (after the completion of the current frame).
		 * </p>
		 */
		void pause();

		/**
		 * <p>
		 * Starts/resumes all engines.
		 * </p>
		 */
		void play();

		/**
		 * <p>
		 * Removes an engine from simplicity.
		 * </p>
		 *
		 * @param engine The engine to remove.
		 *
		 * @return The removed engine.
		 */
		std::unique_ptr<Engine> removeEngine(Engine* engine);

		/**
		 * <p>
		 * Sets the composite engine to which all other engines will be added.
		 * </p>
		 *
		 * @param compositeEngine The composite engine.
		 */
		void setCompositeEngine(std::unique_ptr<CompositeEngine> compositeEngine);

        /**
         * <p>
         * Sets the maximum frame rate allowed by simplicity. A value of 0 signifies that there is no maximum frame
         * rate.
         * </p>
         *
         * @param maxFrameRate The maximum frame rate allowed by simplicity.
         */
		void setMaxFrameRate(unsigned short maxFrameRate);

		/**
		 * <p>
		 * Stops all engines (after the completion of the current frame).
		 * </p>
		 */
		void stop();
	}
}

#include "Simplicity.tpp"

#endif /* SIMPLICITY_H_ */
