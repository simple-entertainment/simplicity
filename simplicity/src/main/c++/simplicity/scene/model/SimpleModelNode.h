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
#ifndef SIMPLEMODELNODE_H_
#define SIMPLEMODELNODE_H_

#include "ModelNode.h"
#include "../SimpleNode.h"

namespace simplicity
{
	/**
	 * <p>
	 * A simple implementation of a {@link simplicity::ModelNode ModelNode}.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class SimpleModelNode : public SimpleNode, public ModelNode
	{
		public:
			/**
			 * <p>
			 * Creates an instance of <code>SimpleModelNode</code>.
			 * </p>
			 */
			SimpleModelNode();

			/**
			 * <p>
			 * Disposes of an instance of <code>SimpleModelNode</code>.
			 * </p>
			 */
			virtual ~SimpleModelNode();

			std::shared_ptr<Model> getModel() const;

			void setModel(std::shared_ptr<Model> model);

		private:
			/**
			 * <p>
			 * The {@link simplicity::Model Model} at this <code>SimpleModelNode</code>'s position and orientation.
			 * </p>
			 */
			std::shared_ptr<Model> model;
	};
}

#endif /* SIMPLEMODELNODE_H_ */