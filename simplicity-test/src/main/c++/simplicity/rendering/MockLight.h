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
      MOCK_CONST_METHOD0(getAmbientLight, RGBAColourVector<float>&());
      MOCK_CONST_METHOD0(getDiffuseLight, RGBAColourVector<float>&());
      MOCK_CONST_METHOD0(getLightingMode, LightingMode());
      MOCK_CONST_METHOD0(getNode, boost::shared_ptr<Node>());
      MOCK_CONST_METHOD0(getSpecularLight, RGBAColourVector<float>&());
      MOCK_CONST_METHOD0(getTransformation, const TransformationMatrix<float>&());
      MOCK_METHOD0(init, void());
      MOCK_CONST_METHOD0(isInitialised, bool());
      MOCK_METHOD1(setAmbientLight, void(boost::shared_ptr<RGBAColourVector<float> > ambientLight));
      MOCK_METHOD1(setDiffuseLight, void(boost::shared_ptr<RGBAColourVector<float> > ambientLight));
      MOCK_METHOD1(setLightingMode, void(const LightingMode lightingMode));
      MOCK_METHOD1(setInitialised, void(const bool isInitialised));
      MOCK_METHOD1(setNode, void(boost::shared_ptr<Node> node));
      MOCK_METHOD1(setSpecularLight, void(boost::shared_ptr<RGBAColourVector<float> > ambientLight));
  };
}

#endif /* MOCKLIGHT_H_ */
