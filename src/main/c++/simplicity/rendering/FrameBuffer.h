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
#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <memory>
#include <vector>

#include "Texture.h"

namespace simplicity
{
	class SIMPLE_API FrameBuffer
	{
		public:
			/**
			 * <p>
			 * Allows polymorphism.
			 * </p>
			 */
			virtual ~FrameBuffer()
			{
			}

			virtual void apply() = 0;

			virtual std::vector<std::shared_ptr<Texture>>& getTextures() = 0;
	};
}

#endif /* FRAMEBUFFER_H */
