/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef RENDERER_H_
#define RENDERER_H_

namespace simplicity
{
	class Capsule;
	class Circle;
	class Cube;
	class Cylinder;
	template<unsigned int Dimensions>
	class Line;
	class Mesh;
	class Model;
	class Sphere;
	class Text;
	class Torus;

	class Renderer
	{
		public:
			virtual ~Renderer()
			{
			}

			virtual void dispose() = 0;

			virtual void init() = 0;

			virtual void render(const Capsule& model) = 0;

			virtual void render(const Circle& model) = 0;

			virtual void render(const Cube& model) = 0;

			virtual void render(const Cylinder& model) = 0;

			virtual void render(const Line<2>& model) = 0;

			virtual void render(const Mesh& model) = 0;

			virtual void render(const Sphere& model) = 0;

			virtual void render(const Text& model) = 0;

			virtual void render(const Torus& model) = 0;
	};
}

#endif /* RENDERER_H_ */
