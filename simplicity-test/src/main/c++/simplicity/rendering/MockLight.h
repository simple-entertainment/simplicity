/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef MOCKLIGHT_H_
#define MOCKLIGHT_H_

#include <gmock/gmock.h>

#include <simplicity/rendering/Light.h>

namespace simplicity
{
  /**
   * <p>
   * A mock implementation of {@link simplicity::Camera Camera}.
   * </p>
   *
   * @author Gary Buyn
   */
  class MockLight : public Light
  {
    public:
      MOCK_METHOD0(apply, void());
      MOCK_CONST_METHOD0(getAmbientLight, ColourVector<>&());
      MOCK_CONST_METHOD0(getDiffuseLight, ColourVector<>&());
      MOCK_CONST_METHOD0(getLightingMode, LightingMode());
      MOCK_CONST_METHOD0(getNode, TreeNode*());
      MOCK_CONST_METHOD0(getSpecularLight, ColourVector<>&());
      MOCK_CONST_METHOD0(getTransformation, const TransformationMatrix<>&());
      MOCK_METHOD0(init, void());
      MOCK_CONST_METHOD0(isInitialised, bool());
      //MOCK_METHOD1(setAmbientLight, void(std::unique_ptr<ColourVector<> > ambientLight));
      //MOCK_METHOD1(setDiffuseLight, void(std::unique_ptr<ColourVector<> > ambientLight));
      MOCK_METHOD1(setLightingMode, void(const LightingMode lightingMode));
      MOCK_METHOD1(setInitialised, void(const bool isInitialised));
      MOCK_METHOD1(setNode, void(TreeNode* node));
      //MOCK_METHOD1(setSpecularLight, void(std::unique_ptr<ColourVector<> > ambientLight));

	  // TODO Mock this properly when it is supported!
      void setAmbientLight(std::unique_ptr<ColourVector<> > ambientLight)
      {
      }

	  // TODO Mock this properly when it is supported!
      void setDiffuseLight(std::unique_ptr<ColourVector<> > ambientLight)
      {
      }

      // TODO Mock this properly when it is supported!
      void setSpecularLight(std::unique_ptr<ColourVector<> > ambientLight)
      {
      }
  };
}

#endif /* MOCKLIGHT_H_ */
