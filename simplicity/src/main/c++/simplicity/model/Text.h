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

#include "../math/RGBAColourVector.h"
#include "BaseModel.h"

namespace simplicity
{
	/**
	 * <p>
	 * A {@link simplicity::Model Model} for displaying text.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class Text : public BaseModel
	{
		public:
			Text();

			const TranslationVector<>& getCenter() const;

			const RGBAColourVector<>& getColour() const;

			const std::string& getText() const;

			void setColour(std::unique_ptr<RGBAColourVector<> > colour);

			void setText(const std::string& text);

		private:
			/**
			 * <p>
			 * The point at the center of this <code>Text</code>.
			 * </p>
			 */
			std::unique_ptr<TranslationVector<> > center;

			std::unique_ptr<RGBAColourVector<> > colour;

			std::string text;
	};
}

#endif /* TEXT_H_ */
