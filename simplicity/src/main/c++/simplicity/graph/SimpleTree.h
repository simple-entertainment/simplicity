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
#ifndef SIMPLETREE_H_
#define SIMPLETREE_H_

#include "Tree.h"

namespace simplicity
{
	template<typename NodeType>
	class SimpleTree : public Tree<NodeType>
	{
		public:
			SimpleTree(std::shared_ptr<NodeType> root);

			NodeType& add(std::shared_ptr<NodeType> node);

			void connect(Node& parent, Node& child);

			void disconnect(Node& parent, Node& child);

			NodeType& get(int id);

			const NodeType& get(int id) const;

			const std::vector<std::shared_ptr<NodeType> >& getAll() const;

			NodeType& getRoot();

			const NodeType& getRoot() const;

			void remove(Node& node);

		private:
			int nextId;

			std::vector<std::shared_ptr<NodeType> > nodes;

			NodeType& root;
	};
}

#include "SimpleTree.tpp"

#endif /* SIMPLETREE_H_ */
