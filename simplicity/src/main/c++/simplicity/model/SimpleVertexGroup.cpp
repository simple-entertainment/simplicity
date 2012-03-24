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
#include "../math/SimpleTranslationVector4.h"
#include "SimpleVertexGroup.h"
#include "ModelConstants.h"

using namespace simplicity::model_constants;
using namespace std;

namespace simplicity
{
	SimpleVertexGroup::SimpleVertexGroup() :
		indexWithinParent(-1), parent(0), subset(false)
	{
	}

	SimpleVertexGroup::SimpleVertexGroup(SimpleVertexGroup& parent) :
		indexWithinParent(-1), parent(&parent), subset(true)
	{
	}

	std::shared_ptr<VertexGroup> SimpleVertexGroup::createEdgeSubsetVG(const int index)
	{
		return createSubsetVG(index, 2);
	}

	std::shared_ptr<VertexGroup> SimpleVertexGroup::createFaceSubsetVG(const int index)
	{
		return createSubsetVG(index * VERTICES_IN_A_FACE, VERTICES_IN_A_FACE);
	}

	std::shared_ptr<VertexGroup> SimpleVertexGroup::createSubsetVG(const int index, const int length)
	{
		int subsetStart = index * ITEMS_IN_CNV;
		int subsetLength = length * ITEMS_IN_CNV;

		std::shared_ptr<vector<float> > subsetColours(
			new vector<float>(colours->begin() + subsetStart, colours->begin() + subsetStart + subsetLength));
		std::shared_ptr<vector<float> > subsetNormals(
			new vector<float>(normals->begin() + subsetStart, normals->begin() + subsetStart + subsetLength));
		std::shared_ptr<vector<float> > subsetVertices(
			new vector<float>(vertices->begin() + subsetStart, vertices->begin() + subsetStart + subsetLength));

		std::shared_ptr<SimpleVertexGroup> subsetVertexGroup(new SimpleVertexGroup(*this));
		subsetVertexGroup->setIndexWithinParent(index);
		subsetVertexGroup->setColours(subsetColours);
		subsetVertexGroup->setNormals(subsetNormals);
		subsetVertexGroup->setVertices(subsetVertices);

		return subsetVertexGroup;
	}

	std::shared_ptr<VertexGroup> SimpleVertexGroup::createVertexSubsetVG(const int index)
	{
		return createSubsetVG(index, 1);
	}

	const TranslationVector<>& SimpleVertexGroup::getCenter() const
	{
		// FIXME Memory leak!
		SimpleTranslationVector4<>* translation = new SimpleTranslationVector4<>();
		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;

		int vertexCount = vertices->size() / ITEMS_IN_CNV;
		for (int vertexIndex = 0; vertexIndex < vertexCount; vertexIndex++)
		{
			x += vertices->at(vertexIndex * ITEMS_IN_CNV);
			y += vertices->at(vertexIndex * ITEMS_IN_CNV + 1);
			z += vertices->at(vertexIndex * ITEMS_IN_CNV + 2);
		}

		x /= vertexCount;
		y /= vertexCount;
		z /= vertexCount;

		translation->setX(x);
		translation->setY(y);
		translation->setZ(z);

		return *translation;
	}

	vector<float>& SimpleVertexGroup::getColours()
	{
		return *colours;
	}

	const vector<float>& SimpleVertexGroup::getColours() const
	{
		return *colours;
	}

	int SimpleVertexGroup::getIndexWithinParent() const
	{
		return indexWithinParent;
	}

	vector<float>& SimpleVertexGroup::getNormals()
	{
		return *normals;
	}

	const vector<float>& SimpleVertexGroup::getNormals() const
	{
		return *normals;
	}

	VertexGroup* SimpleVertexGroup::getParent() const
	{
		return parent;
	}

	shared_ptr<Texture> SimpleVertexGroup::getTexture() const
	{
		return texture;
	}

	vector<float>& SimpleVertexGroup::getTextureCoordinates()
	{
		return *textureCoordinates;
	}

	const vector<float>& SimpleVertexGroup::getTextureCoordinates() const
	{
		return *textureCoordinates;
	}

	int SimpleVertexGroup::getVertexCount() const
	{
		return vertices->size() / ITEMS_IN_CNV;
	}

	vector<float>& SimpleVertexGroup::getVertices()
	{
		return *vertices;
	}

	const vector<float>& SimpleVertexGroup::getVertices() const
	{
		return *vertices;
	}

	bool SimpleVertexGroup::isSubset() const
	{
		return subset;
	}

	void SimpleVertexGroup::mergeWithParent() const
	{
		if (!subset)
		{
			throw SEInvalidOperationException();
		}

		for (unsigned int index = 0; index < colours->size(); index++)
		{
			parent->getColours().at(index) = colours->at(index);
			parent->getNormals().at(index) = normals->at(index);
			parent->getVertices().at(index) = vertices->at(index);
		}
	}

	void SimpleVertexGroup::setColours(std::shared_ptr<vector<float> > colours)
	{
		this->colours = colours;
	}

	void SimpleVertexGroup::setIndexWithinParent(const int indexWithinParent)
	{
		this->indexWithinParent = indexWithinParent;
	}

	void SimpleVertexGroup::setNormals(std::shared_ptr<vector<float> > normals)
	{
		this->normals = normals;
	}

	void SimpleVertexGroup::setTexture(std::shared_ptr<Texture> texture)
	{
		this->texture = texture;
	}

	void SimpleVertexGroup::setTextureCoordinates(std::shared_ptr<vector<float> > textureCoordinates)
	{
		this->textureCoordinates = textureCoordinates;
	}

	void SimpleVertexGroup::setVertices(std::shared_ptr<vector<float> > vertices)
	{
		this->vertices = vertices;
	}
}
