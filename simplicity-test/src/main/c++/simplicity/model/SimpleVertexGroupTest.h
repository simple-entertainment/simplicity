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
#ifndef SIMPLEVERTEXGROUPTEST_H_
#define SIMPLEVERTEXGROUPTEST_H_

#include <gtest/gtest.h>

#include <simplicity/model/SimpleVertexGroup.h>

namespace simplicity
{
	/**
	 * <p>
	 * Unit tests for the class {@link simplicity::SimpleVertexGroup SimpleVertexGroup}.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class SimpleVertexGroupTest : public testing::Test
	{
		protected:
			/**
			 * An instance of the class being unit tested.
			 */
			SimpleVertexGroup objectUnderTest;

			/**
			 * <p>
			 * Setup to perform before each unit test.
			 * </p>
			 */
			void SetUp()
			{
				float colours[12] = {1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f};
				std::shared_ptr<std::vector<float> > coloursVector(new std::vector<float>(colours, colours + 12));
				objectUnderTest.setColours(coloursVector);
				float normals[12] = {-0.5f, -0.5f, 0.0f, -0.5f, 0.5f, 0.0f, 0.5f, 0.5f, 0.0f, 0.5f, -0.5f, 0.0f};
				std::shared_ptr<std::vector<float> > normalsVector(new std::vector<float>(normals, normals + 12));
				objectUnderTest.setNormals(normalsVector);
				float vertices[12] = {-1.0f, -1.0f, 0.0f, -1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, -1.0f, 0.0f};
				std::shared_ptr<std::vector<float> > verticesVector(new std::vector<float>(vertices, vertices + 12));
				objectUnderTest.setVertices(verticesVector);
			}
	};
}

#endif /* SIMPLEVERTEXGROUPTEST_H_ */
