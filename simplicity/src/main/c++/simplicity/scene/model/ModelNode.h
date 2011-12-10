/*
 * Copyright © 2011 Simple Entertainment Limited
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
#ifndef MODELNODE_H_
#define MODELNODE_H_

#include "../Node.h"
#include "../../model/Model.h"

namespace simplicity
{
	/**
	 * <p>
	 * A {@link simplicity::Node Node} that contains a {@link simplicity::Model Model}.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class ModelNode : public virtual Node
	{
		public:
			/**
			 * <p>
			 * Retrieves the {@link simplicity::Model Model} at this <code>ModelNode</code>'s position and orientation.
			 * </p>
			 *
			 * @return The <code>Model</code> at this <code>ModelNode</code>'s position and orientation.
			 */
			virtual boost::shared_ptr<Model> getModel() const = 0;

			/**
			 * <p>
			 * Sets the {@link simplicity::Model Model} at this <code>ModelNode</code>'s position and orientation.
			 * </p>
			 *
			 * @param model The <code>Model</code> at this <code>ModelNode</code>'s position and orientation.
			 */
			virtual void setModel(boost::shared_ptr<Model> model) = 0;
	};
}

#endif /* MODELNODE_H_ */
