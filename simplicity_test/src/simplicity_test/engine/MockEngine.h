/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef MOCKENGINE_H_
#define MOCKENGINE_H_

#include <gmock/gmock.h>

#include <simplicity/engine/Engine.h>
using namespace simplicity;

namespace simplicity_test
{
    /**
     * <p>
     * A mock implementation of {@link simplicity::Engine Engine}.
     * </p>
     *
     * @author Gary Buyn
     */
    class MockEngine : public Engine
    {
        public:
            MOCK_METHOD1(advance, EngineInput*(EngineInput* const input));
            MOCK_METHOD0(destroy, void());
            MOCK_METHOD0(getPreferredFrequency, int());
            MOCK_METHOD0(init, void());
            MOCK_METHOD0(reset, void());
            MOCK_METHOD1(setPreferredFrequency, void(const int preferredFrequency));
    };
}

#endif /* MOCKENGINE_H_ */
