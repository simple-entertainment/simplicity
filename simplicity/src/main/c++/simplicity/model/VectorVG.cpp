/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include "../math/SimpleTranslationVector4.h"
#include "VectorVG.h"
#include "ModelConstants.h"

using namespace boost;
using namespace simplicity::model_constants;
using namespace std;

namespace simplicity
{
  VectorVG::VectorVG() :
    fIndexWithinParent(-1), fIsSubset(false), fParent(0)
  {
  }

  VectorVG::VectorVG(VectorVG& parent) :
    fIndexWithinParent(-1), fIsSubset(true), fParent(&parent)
  {
  }

  VectorVG::~VectorVG()
  {
  }

  shared_ptr<VertexGroup>
  VectorVG::createEdgeSubsetVG(const int index)
  {
    return (createSubsetVG(index, 2));
  }

  shared_ptr<VertexGroup>
  VectorVG::createFaceSubsetVG(const int index)
  {
    return (createSubsetVG(index * VERTICES_IN_A_FACE, VERTICES_IN_A_FACE));
  }

  shared_ptr<VertexGroup>
  VectorVG::createSubsetVG(const int index, const int length)
  {
    int subsetStart = index * ITEMS_IN_CNV;
    int subsetLength = length * ITEMS_IN_CNV;

    shared_ptr<vector<float> > subsetColours(
        new vector<float> (fColours->begin() + subsetStart, fColours->begin() + subsetStart + subsetLength));
    shared_ptr<vector<float> > subsetNormals(
        new vector<float> (fNormals->begin() + subsetStart, fNormals->begin() + subsetStart + subsetLength));
    shared_ptr<vector<float> > subsetVertices(
        new vector<float> (fVertices->begin() + subsetStart, fVertices->begin() + subsetStart + subsetLength));

    shared_ptr<VectorVG> subsetVertexGroup(new VectorVG(*this));
    subsetVertexGroup->setIndexWithinParent(index);
    subsetVertexGroup->setColours(subsetColours);
    subsetVertexGroup->setNormals(subsetNormals);
    subsetVertexGroup->setVertices(subsetVertices);

    return (subsetVertexGroup);
  }

  shared_ptr<VertexGroup>
  VectorVG::createVertexSubsetVG(const int index)
  {
    return (createSubsetVG(index, 1));
  }

  const TranslationVector<float>&
  VectorVG::getCenter() const
  {
    SimpleTranslationVector4<float>* translation = new SimpleTranslationVector4<float> ();
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;

    int vertexCount = fVertices->size() / ITEMS_IN_CNV;
    for (int vertexIndex = 0; vertexIndex < vertexCount; vertexIndex++)
    {
      x += fVertices->at(vertexIndex * ITEMS_IN_CNV);
      y += fVertices->at(vertexIndex * ITEMS_IN_CNV + 1);
      z += fVertices->at(vertexIndex * ITEMS_IN_CNV + 2);
    }

    x /= vertexCount;
    y /= vertexCount;
    z /= vertexCount;

    translation->setX(x);
    translation->setY(y);
    translation->setZ(z);

    return (*translation);
  }

  vector<float>&
  VectorVG::getColours()
  {
    return (*fColours);
  }

  const vector<float>&
  VectorVG::getColours() const
  {
    return (*fColours);
  }

  int
  VectorVG::getIndexWithinParent() const
  {
    return (fIndexWithinParent);
  }

  vector<float>&
  VectorVG::getNormals()
  {
    return (*fNormals);
  }

  const vector<float>&
  VectorVG::getNormals() const
  {
    return (*fNormals);
  }

  VertexGroup*
  VectorVG::getParent() const
  {
    return (fParent);
  }

  int
  VectorVG::getVertexCount() const
  {
    return (fVertices->size() / ITEMS_IN_CNV);
  }

  vector<float>&
  VectorVG::getVertices()
  {
    return (*fVertices);
  }

  const vector<float>&
  VectorVG::getVertices() const
  {
    return (*fVertices);
  }

  bool
  VectorVG::isSubset() const
  {
    return (fIsSubset);
  }

  void
  VectorVG::mergeWithParent() const
  {
    if (!fIsSubset)
    {
      throw SEInvalidOperationException();
    }

    for (unsigned int index = 0; index < fColours->size(); index++)
    {
      fParent->getColours().at(index) = fColours->at(index);
      fParent->getNormals().at(index) = fNormals->at(index);
      fParent->getVertices().at(index) = fVertices->at(index);
    }
  }

  void
  VectorVG::setColours(shared_ptr<vector<float> > colours)
  {
    fColours = colours;
  }

  void
  VectorVG::setIndexWithinParent(const int indexWithinParent)
  {
    fIndexWithinParent = indexWithinParent;
  }

  void
  VectorVG::setNormals(shared_ptr<vector<float> > normals)
  {
    fNormals = normals;
  }

  void
  VectorVG::setVertices(shared_ptr<vector<float> > vertices)
  {
    fVertices = vertices;
  }
}
