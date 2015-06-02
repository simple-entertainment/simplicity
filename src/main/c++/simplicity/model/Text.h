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
#ifndef TEXT_H_
#define TEXT_H_

#include "AbstractModel.h"

namespace simplicity
{
	/**
	 * <p>
	 * Some text. TODO Is this really a model?
	 * </p>
	 */
	class SIMPLE_API Text : public AbstractModel
	{
		public:
			/**
			 * <p>
			 * An ID unique to the this model class.
			 * </p>
			 */
			static const unsigned int TYPE_ID = 3;

			/**
			 * @param text The text.
			 */
			Text(const std::string& text);

			/**
			 * <p>
			 * Retrieves the text.
			 * </p>
			 *
			 * @return The text.
			 */
			const std::string& getText() const;

			unsigned short getTypeID() const override;

			/**
			 * <p>
			 * Sets the text.
			 * </p>
			 *
			 * @param text The text.
			 */
			void setText(const std::string& text);

		private:
			std::string text;
	};
}

#endif /* TEXT_H_ */
