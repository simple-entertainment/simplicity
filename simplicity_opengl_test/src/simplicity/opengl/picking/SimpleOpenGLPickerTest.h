/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SIMPLEOPENGLPICKERTEST_H_
#define SIMPLEOPENGLPICKERTEST_H_

#include <gtest/gtest.h>

#include <simplicity/opengl/picking/SimpleOpenGLPicker.h>

namespace simplicity
{
  namespace opengl
  {
    /**
     * <p>
     * Unit tests for the class {@link simplicity::opengl::SimpleOpenGLPicker SimpleOpenGLPicker}.
     * </p>
     *
     * @author Gary Buyn
     */
    class SimpleOpenGLPickerTest : public testing::Test
    {
      protected:
        /**
         * An instance of the class being unit tested.
         */
        simplicity::opengl::SimpleOpenGLPicker fTestObject;

        /**
         * <p>
         * Provides access to the private method
         * {@link simplicity::opengl::SimpleOpenGLPicker#createPickEvent(const Scene&, const int) createPickEvent(const Scene&, const int)}.
         * </p>
         */
        PickEvent
        createPickEventPublic(const Scene& scene, const int numberOfHits) const
        {
          return (fTestObject.createPickEvent(scene, numberOfHits));
        }
    };
  }
}

#endif /* SIMPLEOPENGLPICKERTEST_H_ */
