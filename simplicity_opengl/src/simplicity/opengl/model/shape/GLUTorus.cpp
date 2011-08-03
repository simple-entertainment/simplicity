/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include "GLUTorus.h"

namespace simplicity
{
  namespace opengl
  {
    GLUTorus::GLUTorus() :
      fSlices(DEFALUT_SLICES), fStacks(DEFALUT_STACKS)
    {
    }

    GLUTorus::~GLUTorus()
    {
    }

    int
    GLUTorus::getSlices() const
    {
      return (fSlices);
    }

    int
    GLUTorus::getStacks() const
    {
      return (fStacks);
    }

    void
    GLUTorus::setSlices(const int slices)
    {
      fSlices = slices;
    }

    void
    GLUTorus::setStacks(const int stacks)
    {
      fStacks = stacks;
    }
  }
}
