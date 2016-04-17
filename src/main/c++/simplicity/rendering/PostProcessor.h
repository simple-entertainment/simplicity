/*      _                 _ _      _ _
 *     (_)               | (_)    (_) |
 *  ___ _ _ __ ___  _ __ | |_  ___ _| |_ _   _
 * / __| | '_ ` _ \| '_ \| | |/ __| | __| | | |
 * \__ \ | | | | | | |_) | | | (__| | |_| |_| |
 * |___/_|_| |_| |_| .__/|_|_|\___|_|\__|\__, |
 *                 | |                    __/ |
 *                 |_|                   |___/
 *
 * This file is part of simplicity. See the LICENSE file for the full license governing this code.
 */
#ifndef POSTPROCESSOR_H
#define POSTPROCESSOR_H

#include <vector>

namespace simplicity
{
	class RenderingEngine;

	class SIMPLE_API PostProcessor
	{
		public:
			/**
			 * <p>
			 * Allows polymorphism.
			 * </p>
			 */
			virtual ~PostProcessor()
			{
			}

			virtual void process(RenderingEngine& engine) = 0;
	};
}

#endif /* POSTPROCESSOR_H */
