/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include "../math/SimpleTranslationVector4.h"
#include "ModelConstants.h"
#include "SimpleIndexedVertexGroup.h"

using namespace simplicity::model_constants;
using namespace std;

namespace simplicity
{
	SimpleIndexedVertexGroup::SimpleIndexedVertexGroup() :
		indexWithinParent(-1), parent(0), subset(false)
	{
	}

	SimpleIndexedVertexGroup::SimpleIndexedVertexGroup(SimpleIndexedVertexGroup& parent) :
		indexWithinParent(-1), parent(&parent), subset(true)
	{
	}

	std::shared_ptr<VertexGroup> SimpleIndexedVertexGroup::createEdgeSubsetVG(const int index)
	{
		return createSubsetVG(index, 2);
	}

	std::shared_ptr<VertexGroup> SimpleIndexedVertexGroup::createFaceSubsetVG(const int index)
	{
		return createSubsetVG(index * VERTICES_IN_A_FACE, VERTICES_IN_A_FACE);
	}

	std::shared_ptr<VertexGroup> SimpleIndexedVertexGroup::createSubsetVG(const int index, const int length)
	{
		int subsetStart = index * ITEMS_IN_CNV;
		int subsetLength = length * ITEMS_IN_CNV;

		std::shared_ptr<vector<int> > subsetIndices(
			new vector<int>(indices->begin() + index, indices->begin() + index + length));
		std::shared_ptr<vector<float> > subsetColours(
			new vector<float>(colours->begin() + subsetStart, colours->begin() + subsetStart + subsetLength));
		std::shared_ptr<vector<float> > subsetNormals(
			new vector<float>(normals->begin() + subsetStart, normals->begin() + subsetStart + subsetLength));
		std::shared_ptr<vector<float> > subsetVertices(
			new vector<float>(vertices->begin() + subsetStart, vertices->begin() + subsetStart + subsetLength));

		std::shared_ptr<SimpleIndexedVertexGroup> subsetVertexGroup(new SimpleIndexedVertexGroup(*this));
		subsetVertexGroup->setIndexWithinParent(index);
		subsetVertexGroup->setIndices(subsetIndices);
		subsetVertexGroup->setColours(subsetColours);
		subsetVertexGroup->setNormals(subsetNormals);
		subsetVertexGroup->setVertices(subsetVertices);

		return subsetVertexGroup;
	}

	std::shared_ptr<VertexGroup> SimpleIndexedVertexGroup::createVertexSubsetVG(const int index)
	{
		return createSubsetVG(index, 1);
	}

	const TranslationVector<>& SimpleIndexedVertexGroup::getCenter() const
	{
		// FIXME Memory leak!
		SimpleTranslationVector4<>* translation(new SimpleTranslationVector4<>);
		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;

		for (unsigned int vertexIndex = 0; vertexIndex < indices->size(); vertexIndex++)
		{
			x += vertices->at(indices->at(vertexIndex) * ITEMS_IN_CNV);
			y += vertices->at(indices->at(vertexIndex) * ITEMS_IN_CNV + 1);
			z += vertices->at(indices->at(vertexIndex) * ITEMS_IN_CNV + 2);
		}

		x /= indices->size();
		y /= indices->size();
		z /= indices->size();

		translation->setX(x);
		translation->setY(y);
		translation->setZ(z);

		return *translation;
	}

	vector<float>& SimpleIndexedVertexGroup::getColours()
	{
		return *colours;
	}

	const vector<float>& SimpleIndexedVertexGroup::getColours() const
	{
		return *colours;
	}

	int SimpleIndexedVertexGroup::getIndexWithinParent() const
	{
		return indexWithinParent;
	}

	vector<int>& SimpleIndexedVertexGroup::getIndices()
	{
		return *indices;
	}

	const vector<int>& SimpleIndexedVertexGroup::getIndices() const
	{
		return *indices;
	}

	vector<float>& SimpleIndexedVertexGroup::getNormals()
	{
		return *normals;
	}

	const vector<float>& SimpleIndexedVertexGroup::getNormals() const
	{
		return *normals;
	}

	VertexGroup* SimpleIndexedVertexGroup::getParent() const
	{
		return parent;
	}

	shared_ptr<Texture> SimpleIndexedVertexGroup::getTexture() const
	{
		return texture;
	}

	vector<float>& SimpleIndexedVertexGroup::getTextureCoordinates()
	{
		return *textureCoordinates;
	}

	const vector<float>& SimpleIndexedVertexGroup::getTextureCoordinates() const
	{
		return *textureCoordinates;
	}

	int SimpleIndexedVertexGroup::getVertexCount() const
	{
		return indices->size();
	}

	vector<float>& SimpleIndexedVertexGroup::getVertices()
	{
		return *vertices;
	}

	const vector<float>& SimpleIndexedVertexGroup::getVertices() const
	{
		return *vertices;
	}

	bool SimpleIndexedVertexGroup::isSubset() const
	{
		return subset;
	}

	void SimpleIndexedVertexGroup::mergeWithParent() const
	{
		if (!subset)
		{
			throw SEInvalidOperationException();
		}

		for (unsigned int index = 0; index < indices->size(); index++)
		{
			int vectorIndex = indices->at(index) * ITEMS_IN_CNV;
			int parentVectorIndex = parent->getIndices().at(indexWithinParent + index) * ITEMS_IN_CNV;

			for (int cnvIndex = 0; cnvIndex < ITEMS_IN_CNV; cnvIndex++)
			{
				parent->getColours().at(parentVectorIndex + cnvIndex) = colours->at(vectorIndex + cnvIndex);
				parent->getNormals().at(parentVectorIndex + cnvIndex) = normals->at(vectorIndex + cnvIndex);
				parent->getVertices().at(parentVectorIndex + cnvIndex) = vertices->at(vectorIndex + cnvIndex);
			}
		}
	}

	void SimpleIndexedVertexGroup::setColours(std::shared_ptr<vector<float> > colours)
	{
		this->colours = colours;
	}

	void SimpleIndexedVertexGroup::setIndexWithinParent(int const indexWithinParent)
	{
		this->indexWithinParent = indexWithinParent;
	}

	void SimpleIndexedVertexGroup::setIndices(std::shared_ptr<vector<int> > indices)
	{
		this->indices = indices;
	}

	void SimpleIndexedVertexGroup::setNormals(std::shared_ptr<vector<float> > normals)
	{
		this->normals = normals;
	}

	void SimpleIndexedVertexGroup::setTexture(std::shared_ptr<Texture> texture)
	{
		this->texture = texture;
	}

	void SimpleIndexedVertexGroup::setTextureCoordinates(std::shared_ptr<vector<float> > textureCoordinates)
	{
		this->textureCoordinates = textureCoordinates;
	}

	void SimpleIndexedVertexGroup::setVertices(std::shared_ptr<vector<float> > vertices)
	{
		this->vertices = vertices;
	}
}
