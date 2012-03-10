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
#ifndef MOCKMODEL_H_
#define MOCKMODEL_H_

#include <gmock/gmock.h>

#include <simplicity/model/Model.h>

namespace simplicity
{
	/**
	 * <p>
	 * A mock implementation of {@link simplicity::Model Model}.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class MockModel : public Model
	{
		public:
			MOCK_CONST_METHOD0(getCenter, const TranslationVector<>&());
			MOCK_CONST_METHOD0(getEntity, const Entity&());
			MOCK_CONST_METHOD0(getNode, std::shared_ptr<ModelNode>());
			MOCK_METHOD1(setEntity, void(std::shared_ptr<Entity> entity));
			MOCK_METHOD1(setNode, void(std::shared_ptr<ModelNode> node));
	};
}

#endif /* MOCKMODEL_H_ */
