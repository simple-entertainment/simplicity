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
#ifndef MODEL_H_
#define MODEL_H_

#include "../Component.h"
#include "../graph/TreeNode.h"

namespace simplicity
{
	/**
	 * <p>
	 * A visible element in a virtual universe.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class Model : public virtual Component
	{
		public:
			/**
			 * <p>
			 * Retrieves the point at the center of this <code>Model</code>.
			 * </p>
			 *
			 * @return The point at the center of this <code>Model</code>.
			 */
			virtual const TranslationVector<>& getCenter() const = 0;

			/**
			 * <p>
			 * Retrieves the location of this <code>Model</code> within the scene.
			 * </p>
			 *
			 * @return The location of this <code>Model</code> within the scene.
			 */
			virtual TreeNode* getNode() const = 0;

			/**
			 * <p>
			 * Sets the location of this <code>Model</code> within the scene.
			 * </p>
			 *
			 * @param node The location of this <code>Model</code> within the scene.
			 */
			virtual void setNode(TreeNode* node) = 0;
	};
}

#endif /* MODEL_H_ */
