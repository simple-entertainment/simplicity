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
#include <iostream>

#include "SimpleVertexGroupTest.h"

using namespace std;

namespace simplicity
{
	TEST_F(SimpleVertexGroupTest, random)
	{
		shared_ptr<VertexGroup> subsetVGUncasted(objectUnderTest.createEdgeSubsetVG(0));
	}

	/**
	 * <p>
	 * Unit test the method
	 * {@link simplicity::SimpleVertexGroup#createEdgeSubsetVG(const int) createEdgeSubsetVG(const int)}.
	 * </p>
	 */
	TEST_F(SimpleVertexGroupTest, createEdgeSubsetVG)
	{
		// Perform test.
		shared_ptr<VertexGroup> subsetVGUncasted(objectUnderTest.createEdgeSubsetVG(0));
		shared_ptr<SimpleVertexGroup> subsetVG(dynamic_pointer_cast < SimpleVertexGroup > (subsetVGUncasted));

		// Verify test results.
		vector<float>& subsetColours = subsetVG->getColours();

		ASSERT_EQ(6u, subsetColours.size());
		ASSERT_EQ(1.0f, subsetColours.at(0));
		ASSERT_EQ(0.0f, subsetColours.at(1));
		ASSERT_EQ(0.0f, subsetColours.at(2));
		ASSERT_EQ(0.0f, subsetColours.at(3));
		ASSERT_EQ(1.0f, subsetColours.at(4));
		ASSERT_EQ(0.0f, subsetColours.at(5));

		vector<float>& subsetNormals = subsetVG->getNormals();

		ASSERT_EQ(6u, subsetNormals.size());
		ASSERT_EQ(-0.5f, subsetNormals.at(0));
		ASSERT_EQ(-0.5f, subsetNormals.at(1));
		ASSERT_EQ(0.0f, subsetNormals.at(2));
		ASSERT_EQ(-0.5f, subsetNormals.at(3));
		ASSERT_EQ(0.5f, subsetNormals.at(4));
		ASSERT_EQ(0.0f, subsetNormals.at(5));

		vector<float>& subsetVertices = subsetVG->getVertices();

		ASSERT_EQ(6u, subsetVertices.size());
		ASSERT_EQ(-1.0f, subsetVertices.at(0));
		ASSERT_EQ(-1.0f, subsetVertices.at(1));
		ASSERT_EQ(0.0f, subsetVertices.at(2));
		ASSERT_EQ(-1.0f, subsetVertices.at(3));
		ASSERT_EQ(1.0f, subsetVertices.at(4));
		ASSERT_EQ(0.0f, subsetVertices.at(5));
	}

	/**
	 * <p>
	 * Unit test the method
	 * {@link simplicity::SimpleVertexGroup#createFaceSubsetVG(const int) createFaceSubsetVG(const int)}.
	 * </p>
	 */
	TEST_F(SimpleVertexGroupTest, createFaceSubsetVG)
	{
		// Perform test.
		shared_ptr<SimpleVertexGroup> subsetVG(
			dynamic_pointer_cast < SimpleVertexGroup > (objectUnderTest.createFaceSubsetVG(0)));

		// Verify test results.
		vector<float>& subsetColours = subsetVG->getColours();

		ASSERT_EQ(9u, subsetColours.size());
		ASSERT_EQ(1.0f, subsetColours.at(0));
		ASSERT_EQ(0.0f, subsetColours.at(1));
		ASSERT_EQ(0.0f, subsetColours.at(2));
		ASSERT_EQ(0.0f, subsetColours.at(3));
		ASSERT_EQ(1.0f, subsetColours.at(4));
		ASSERT_EQ(0.0f, subsetColours.at(5));
		ASSERT_EQ(0.0f, subsetColours.at(6));
		ASSERT_EQ(0.0f, subsetColours.at(7));
		ASSERT_EQ(1.0f, subsetColours.at(8));

		vector<float>& subsetNormals = subsetVG->getNormals();

		ASSERT_EQ(9u, subsetNormals.size());
		ASSERT_EQ(-0.5f, subsetNormals.at(0));
		ASSERT_EQ(-0.5f, subsetNormals.at(1));
		ASSERT_EQ(0.0f, subsetNormals.at(2));
		ASSERT_EQ(-0.5f, subsetNormals.at(3));
		ASSERT_EQ(0.5f, subsetNormals.at(4));
		ASSERT_EQ(0.0f, subsetNormals.at(5));
		ASSERT_EQ(0.5f, subsetNormals.at(6));
		ASSERT_EQ(0.5f, subsetNormals.at(7));
		ASSERT_EQ(0.0f, subsetNormals.at(8));

		vector<float>& subsetVertices = subsetVG->getVertices();

		ASSERT_EQ(9u, subsetVertices.size());
		ASSERT_EQ(-1.0f, subsetVertices.at(0));
		ASSERT_EQ(-1.0f, subsetVertices.at(1));
		ASSERT_EQ(0.0f, subsetVertices.at(2));
		ASSERT_EQ(-1.0f, subsetVertices.at(3));
		ASSERT_EQ(1.0f, subsetVertices.at(4));
		ASSERT_EQ(0.0f, subsetVertices.at(5));
		ASSERT_EQ(1.0f, subsetVertices.at(6));
		ASSERT_EQ(1.0f, subsetVertices.at(7));
		ASSERT_EQ(0.0f, subsetVertices.at(8));
	}

	/**
	 * <p>
	 * Unit test the method
	 * {@link simplicity::SimpleVertexGroup#createVertexSubsetVG(const int) createVertexSubsetVG(const int)}.
	 * </p>
	 */
	TEST_F(SimpleVertexGroupTest, createVertexSubsetVG)
	{
		// Perform test.
		shared_ptr<SimpleVertexGroup> subsetVG(
			dynamic_pointer_cast < SimpleVertexGroup > (objectUnderTest.createVertexSubsetVG(0)));

		// Verify test results.
		vector<float>& subsetColours = subsetVG->getColours();

		ASSERT_EQ(3u, subsetColours.size());
		ASSERT_EQ(1.0f, subsetColours.at(0));
		ASSERT_EQ(0.0f, subsetColours.at(1));
		ASSERT_EQ(0.0f, subsetColours.at(2));

		vector<float>& subsetNormals = subsetVG->getNormals();

		ASSERT_EQ(3u, subsetNormals.size());
		ASSERT_EQ(-0.5f, subsetNormals.at(0));
		ASSERT_EQ(-0.5f, subsetNormals.at(1));
		ASSERT_EQ(0.0f, subsetNormals.at(2));

		vector<float>& subsetVertices = subsetVG->getVertices();

		ASSERT_EQ(3u, subsetVertices.size());
		ASSERT_EQ(-1.0f, subsetVertices.at(0));
		ASSERT_EQ(-1.0f, subsetVertices.at(1));
		ASSERT_EQ(0.0f, subsetVertices.at(2));
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimpleVertexGroup#getCenter() getCenter()}.
	 * </p>
	 */
	TEST_F(SimpleVertexGroupTest, getCenter)
	{
		// Perform test.
		const TranslationVector<>& center(objectUnderTest.getCenter());

		// Verify test results.
		ASSERT_EQ(0.0f, center.getX());
		ASSERT_EQ(0.0f, center.getY());
		ASSERT_EQ(0.0f, center.getZ());
		ASSERT_EQ(1.0f, center.getW());
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimpleVertexGroup#getVertexCount() getVertexCount()}.
	 * </p>
	 */
	TEST_F(SimpleVertexGroupTest, getVertexCount)
	{
		// Perform test / Verify test results.
		ASSERT_EQ(4, objectUnderTest.getVertexCount());
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimpleVertexGroup#mergeWithParent() mergeWithParent()}.
	 * </p>
	 */
	TEST_F(SimpleVertexGroupTest, mergeWithParent)
	{
		// Initialise test environment.
		shared_ptr<SimpleVertexGroup> subsetVG(
			dynamic_pointer_cast < SimpleVertexGroup > (objectUnderTest.createFaceSubsetVG(0)));

		float newColours[9] = {0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f};
		shared_ptr<vector<float> > coloursVector(new vector<float>(newColours, newColours + 9));
		subsetVG->setColours(coloursVector);
		float newNormals[9] = {0.5f, 0.5f, 0.0f, 0.5f, -0.5f, 0.0f, -0.5f, -0.5f, 0.0f};
		shared_ptr<vector<float> > normalsVector(new vector<float>(newNormals, newNormals + 9));
		subsetVG->setNormals(normalsVector);
		float newVertices[9] = {-2.0f, -2.0f, 0.0f, -2.0f, 2.0f, 0.0f, 2.0f, 2.0f, 0.0f};
		shared_ptr<vector<float> > verticesVector(new vector<float>(newVertices, newVertices + 9));
		subsetVG->setVertices(verticesVector);

		// Perform test.
		subsetVG->mergeWithParent();

		// Verify test results.
		vector<float>& colours = objectUnderTest.getColours();

		ASSERT_EQ(12u, colours.size());
		ASSERT_EQ(0.0f, colours.at(0));
		ASSERT_EQ(0.0f, colours.at(1));
		ASSERT_EQ(1.0f, colours.at(2));
		ASSERT_EQ(0.0f, colours.at(3));
		ASSERT_EQ(1.0f, colours.at(4));
		ASSERT_EQ(0.0f, colours.at(5));
		ASSERT_EQ(1.0f, colours.at(6));
		ASSERT_EQ(0.0f, colours.at(7));
		ASSERT_EQ(0.0f, colours.at(8));
		ASSERT_EQ(1.0f, colours.at(9));
		ASSERT_EQ(1.0f, colours.at(10));
		ASSERT_EQ(1.0f, colours.at(11));

		vector<float>& normals = objectUnderTest.getNormals();

		ASSERT_EQ(12u, normals.size());
		ASSERT_EQ(0.5f, normals.at(0));
		ASSERT_EQ(0.5f, normals.at(1));
		ASSERT_EQ(0.0f, normals.at(2));
		ASSERT_EQ(0.5f, normals.at(3));
		ASSERT_EQ(-0.5f, normals.at(4));
		ASSERT_EQ(0.0f, normals.at(5));
		ASSERT_EQ(-0.5f, normals.at(6));
		ASSERT_EQ(-0.5f, normals.at(7));
		ASSERT_EQ(0.0f, normals.at(8));
		ASSERT_EQ(0.5f, normals.at(9));
		ASSERT_EQ(-0.5f, normals.at(10));
		ASSERT_EQ(0.0f, normals.at(11));

		vector<float>& vertices = objectUnderTest.getVertices();

		ASSERT_EQ(12u, vertices.size());
		ASSERT_EQ(-2.0f, vertices.at(0));
		ASSERT_EQ(-2.0f, vertices.at(1));
		ASSERT_EQ(0.0f, vertices.at(2));
		ASSERT_EQ(-2.0f, vertices.at(3));
		ASSERT_EQ(2.0f, vertices.at(4));
		ASSERT_EQ(0.0f, vertices.at(5));
		ASSERT_EQ(2.0f, vertices.at(6));
		ASSERT_EQ(2.0f, vertices.at(7));
		ASSERT_EQ(0.0f, vertices.at(8));
		ASSERT_EQ(1.0f, vertices.at(9));
		ASSERT_EQ(-1.0f, vertices.at(10));
		ASSERT_EQ(0.0f, vertices.at(11));
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimpleVertexGroup#mergeWithParent() mergeWithParent()} for the special
	 * condition where the {@link simplicity::SimpleVertexGroup SimpleVertexGroup} being tested is not a subset.
	 * </p>
	 */
	TEST_F(SimpleVertexGroupTest, mergeWithParentNotSubset)
	{
		ASSERT_THROW(objectUnderTest.mergeWithParent(), SEInvalidOperationException);
	}
}