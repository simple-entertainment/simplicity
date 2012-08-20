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
#ifndef MOCKRENDERINGENGINE_H_
#define MOCKRENDERINGENGINE_H_

#include <gmock/gmock.h>

#include <simplicity/rendering/engine/RenderingEngine.h>

namespace simplicity
{
	/**
	 * <p>
	 * A mock implementation of {@link simplicity::RenderingEngine RenderingEngine}.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class MockRenderingEngine : public RenderingEngine
	{
		public:
			MOCK_METHOD1(addEntity, void(std::shared_ptr<Entity> entity));
			MOCK_METHOD1(addRenderer, void(std::shared_ptr<Renderer> renderer));
			MOCK_METHOD2(addRenderer, void(const int index, std::shared_ptr<Renderer> renderer));
			MOCK_METHOD1(advance, std::shared_ptr<EngineInput>(const std::shared_ptr<EngineInput> input));
			MOCK_CONST_METHOD0(clearsBeforeRender, bool());MOCK_METHOD0(destroy, void());
			MOCK_CONST_METHOD0(getCamera, std::shared_ptr<Camera>());
			MOCK_CONST_METHOD0(getClearingColour, const ColourVector<>&());
			MOCK_CONST_METHOD0(getPreferredFrequency, int());
			MOCK_CONST_METHOD1(getRendererRoot, TreeNode*(const Renderer& renderer));
			MOCK_CONST_METHOD0(getRenderers, std::vector<std::shared_ptr<Renderer> >());
			MOCK_CONST_METHOD0(getViewportHeight, int());
			MOCK_CONST_METHOD0(getViewportWidth, int());
			MOCK_METHOD0(init, void());
			MOCK_METHOD1(removeEntity, void(const Entity& entity));
			MOCK_METHOD1(removeRenderer, void(const Renderer& renderer));
			MOCK_METHOD2(renderSceneGraph, void(Renderer& renderer, const TreeNode& root));
			MOCK_METHOD0(reset, void());
			MOCK_METHOD0(run, void());
			MOCK_METHOD1(setCamera, void(std::shared_ptr<Camera> camera));
			//MOCK_METHOD1(setClearingColour, void(std::unique_ptr<ColourVector<> > clearingColour));
			MOCK_METHOD1(setClearsBeforeRender, void(const bool clearsBeforeRender));
			MOCK_METHOD1(setPreferredFrequency, void(const int preferredFrequency));
			MOCK_METHOD2(setRendererRoot, void(const Renderer& renderer, TreeNode* root));
			MOCK_METHOD1(setViewportHeight, void(const int viewportHeight));
			MOCK_METHOD1(setViewportWidth, void(const int viewportWidth));

			// TODO Mock this properly when it is supported!
			void setClearingColour(std::unique_ptr<ColourVector<> > clearingColour)
			{
			}
	};
}

#endif /* MOCKRENDERINGENGINE_H_ */
