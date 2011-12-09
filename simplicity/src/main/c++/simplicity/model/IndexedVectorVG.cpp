/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include "../math/SimpleTranslationVector4.h"
#include "IndexedVectorVG.h"
#include "ModelConstants.h"

using namespace boost;
using namespace simplicity::model_constants;
using namespace std;

namespace simplicity
{
  IndexedVectorVG::IndexedVectorVG() :
    fIndexWithinParent(-1), fIsSubset(false), fParent(0)
  {
  }

  IndexedVectorVG::IndexedVectorVG(IndexedVectorVG& parent) :
    fIndexWithinParent(-1), fIsSubset(true), fParent(&parent)
  {
  }

  IndexedVectorVG::~IndexedVectorVG()
  {
  }

  shared_ptr<VertexGroup>
  IndexedVectorVG::createEdgeSubsetVG(const int index)
  {
    return (createSubsetVG(index, 2));
  }

  shared_ptr<VertexGroup>
  IndexedVectorVG::createFaceSubsetVG(const int index)
  {
    return (createSubsetVG(index * VERTICES_IN_A_FACE, VERTICES_IN_A_FACE));
  }

  shared_ptr<VertexGroup>
  IndexedVectorVG::createSubsetVG(const int index, const int length)
  {
    int subsetStart = index * ITEMS_IN_CNV;
    int subsetLength = length * ITEMS_IN_CNV;

    shared_ptr<vector<int> > subsetIndices(new vector<int> (fIndices->begin() + index, fIndices->begin() + index + length));
    shared_ptr<vector<float> > subsetColours(
        new vector<float> (fColours->begin() + subsetStart, fColours->begin() + subsetStart + subsetLength));
    shared_ptr<vector<float> > subsetNormals(
        new vector<float> (fNormals->begin() + subsetStart, fNormals->begin() + subsetStart + subsetLength));
    shared_ptr<vector<float> > subsetVertices(
        new vector<float> (fVertices->begin() + subsetStart, fVertices->begin() + subsetStart + subsetLength));

    shared_ptr<IndexedVectorVG> subsetVertexGroup(new IndexedVectorVG(*this));
    subsetVertexGroup->setIndexWithinParent(index);
    subsetVertexGroup->setIndices(subsetIndices);
    subsetVertexGroup->setColours(subsetColours);
    subsetVertexGroup->setNormals(subsetNormals);
    subsetVertexGroup->setVertices(subsetVertices);

    return (subsetVertexGroup);
  }

  shared_ptr<VertexGroup>
  IndexedVectorVG::createVertexSubsetVG(const int index)
  {
    return (createSubsetVG(index, 1));
  }

  const TranslationVector<float>&
  IndexedVectorVG::getCenter() const
  {
    // FIXME Memory leak!
    SimpleTranslationVector4<float>* translation(new SimpleTranslationVector4<float> );
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;

    for (unsigned int vertexIndex = 0; vertexIndex < fIndices->size(); vertexIndex++)
    {
      x += fVertices->at(fIndices->at(vertexIndex) * ITEMS_IN_CNV);
      y += fVertices->at(fIndices->at(vertexIndex) * ITEMS_IN_CNV + 1);
      z += fVertices->at(fIndices->at(vertexIndex) * ITEMS_IN_CNV + 2);
    }

    x /= fIndices->size();
    y /= fIndices->size();
    z /= fIndices->size();

    translation->setX(x);
    translation->setY(y);
    translation->setZ(z);

    return (*translation);
  }

  vector<float>&
  IndexedVectorVG::getColours()
  {
    return (*fColours);
  }

  const vector<float>&
  IndexedVectorVG::getColours() const
  {
    return (*fColours);
  }

  int
  IndexedVectorVG::getIndexWithinParent() const
  {
    return (fIndexWithinParent);
  }

  vector<int>&
  IndexedVectorVG::getIndices()
  {
    return (*fIndices);
  }

  const vector<int>&
  IndexedVectorVG::getIndices() const
  {
    return (*fIndices);
  }

  vector<float>&
  IndexedVectorVG::getNormals()
  {
    return (*fNormals);
  }

  const vector<float>&
  IndexedVectorVG::getNormals() const
  {
    return (*fNormals);
  }

  VertexGroup*
  IndexedVectorVG::getParent() const
  {
    return (fParent);
  }

  int
  IndexedVectorVG::getVertexCount() const
  {
    return (fIndices->size());
  }

  vector<float>&
  IndexedVectorVG::getVertices()
  {
    return (*fVertices);
  }

  const vector<float>&
  IndexedVectorVG::getVertices() const
  {
    return (*fVertices);
  }

  bool
  IndexedVectorVG::isSubset() const
  {
    return (fIsSubset);
  }

  void
  IndexedVectorVG::mergeWithParent() const
  {
    if (!fIsSubset)
    {
      throw SEInvalidOperationException();
    }

    for (unsigned int index = 0; index < fIndices->size(); index++)
    {
      int vectorIndex = fIndices->at(index) * ITEMS_IN_CNV;
      int parentVectorIndex = fParent->getIndices().at(fIndexWithinParent + index) * ITEMS_IN_CNV;

      for (int cnvIndex = 0; cnvIndex < ITEMS_IN_CNV; cnvIndex++)
      {
        fParent->getColours().at(parentVectorIndex + cnvIndex) = fColours->at(vectorIndex + cnvIndex);
        fParent->getNormals().at(parentVectorIndex + cnvIndex) = fNormals->at(vectorIndex + cnvIndex);
        fParent->getVertices().at(parentVectorIndex + cnvIndex) = fVertices->at(vectorIndex + cnvIndex);
      }
    }
  }

  void
  IndexedVectorVG::setColours(shared_ptr<vector<float> > colours)
  {
    fColours = colours;
  }

  void
  IndexedVectorVG::setIndexWithinParent(int const indexWithinParent)
  {
    fIndexWithinParent = indexWithinParent;
  }

  void
  IndexedVectorVG::setIndices(shared_ptr<vector<int> > indices)
  {
    fIndices = indices;
  }

  void
  IndexedVectorVG::setNormals(shared_ptr<vector<float> > normals)
  {
    fNormals = normals;
  }

  void
  IndexedVectorVG::setVertices(shared_ptr<vector<float> > vertices)
  {
    fVertices = vertices;
  }
}
