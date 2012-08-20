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
#ifndef SIMPLENODE_H_
#define SIMPLENODE_H_

#include "Node.h"

namespace simplicity
{
	/**
	 * <p>
	 * A simple component of a {@link simplicity::Scene Scene}.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class SimpleNode : public virtual Node
	{
		public:
			SimpleNode();

			SimpleNode(const SimpleNode& original);

			virtual ~SimpleNode();

			void addChild(std::shared_ptr<Node> child);

			void connectTo(Node& otherNode);

			void disconnectFrom(Node& otherNode);

			Component* getComponent() const;

			std::vector<std::reference_wrapper<Node> > getConnectedNodes() const;

			int getId() const;

			TransformationMatrix<>& getTransformation() const;

			SimpleNode& operator=(const SimpleNode& original);

			void setComponent(Component* component);

			void setId(const int id);

			void setTransformation(std::unique_ptr<TransformationMatrix<> > transformation);

		private:
			Component* component;

			/**
			 * <p>
			 * The <code>SimpleNode</code>s directly connected to this <code>SimpleNode</code>.
			 * </p>
			 */
			std::vector<std::reference_wrapper<Node> > connectedNodes;

			int id;

			/**
			 * <p>
			 * This <code>SimpleNode</code>'s relative position and orientation.
			 * </p>
			 */
			std::unique_ptr<TransformationMatrix<> > transformation;
	};
}

#endif /* SIMPLENODE_H_ */
