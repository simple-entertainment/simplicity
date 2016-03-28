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
#ifndef COMPOSITEENGINE_H_
#define COMPOSITEENGINE_H_

#include "Engine.h"

namespace simplicity
{
	/**
	 * <p>
	 * An engine that is composed of several other engines i.e. the composite design pattern. The member functions from
	 * Engine are delegated to the contained engines.
	 * </p>
	 */
	class SIMPLE_API CompositeEngine : public Engine
	{
		public:
			/**
			 * <p>
			 * Adds an engine.
			 * </p>
			 *
			 * @param engine The engine to be added.
			 */
			virtual void addEngine(std::unique_ptr<Engine> engine) = 0;

			/**
			 * <p>
			 * Retrieves the engines contained in this engine.
			 * </p>
			 *
			 * @return The engines contained in this engine.
			 */
			virtual const std::vector<std::unique_ptr<Engine>>& getEngines() const = 0;

			/**
			 * <p>
			 * Removes an engine.
			 * </p>
			 *
			 * @param engine The engine to be removed.
			 *
			 * @return The removed engine.
			 */
			virtual std::unique_ptr<Engine> removeEngine(Engine& engine) = 0;
	};
}

#endif /* COMPOSITEENGINE_H_ */
