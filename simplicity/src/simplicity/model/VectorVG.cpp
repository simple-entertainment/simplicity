/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include "../vector/SimpleTranslationVector4.h"
#include "VectorVG.h"
#include "ModelConstants.h"

namespace simplicity
{
  VectorVG::VectorVG() :
    fColours(0), fIndexWithinParent(-1), fIsSubset(false), fNormals(0), fParent(0), fVertices(0)
  {
  }

  VectorVG::VectorVG(VectorVG * const parent) :
    fColours(0), fIndexWithinParent(-1), fIsSubset(true), fNormals(0), fParent(parent), fVertices(0)
  {
  }

  VectorVG::~VectorVG()
  {
  }

  VertexGroup *
  VectorVG::createEdgeSubsetVG(int const index)
  {
    return (createSubsetVG(index, 2));
  }

  VertexGroup *
  VectorVG::createFaceSubsetVG(int const index)
  {
    return (createSubsetVG(index * ModelConstants::VERTICES_IN_A_FACE, ModelConstants::VERTICES_IN_A_FACE));
  }

  VertexGroup *
  VectorVG::createSubsetVG(int const index, int const length)
  {
    int subsetStart = index * ModelConstants::ITEMS_IN_CNV;
    int subsetLength = length * ModelConstants::ITEMS_IN_CNV;

    vector<float> subsetColours(fColours.begin() + subsetStart, fColours.begin() + subsetStart + subsetLength);
    vector<float> subsetNormals(fNormals.begin() + subsetStart, fNormals.begin() + subsetStart + subsetLength);
    vector<float> subsetVertices(fVertices.begin() + subsetStart, fVertices.begin() + subsetStart + subsetLength);

    VectorVG * subsetVertexGroup = new VectorVG(this);
    subsetVertexGroup->setIndexWithinParent(index);
    subsetVertexGroup->setColours(subsetColours);
    subsetVertexGroup->setNormals(subsetNormals);
    subsetVertexGroup->setVertices(subsetVertices);

    return (subsetVertexGroup);
  }

  VertexGroup *
  VectorVG::createVertexSubsetVG(int const index)
  {
    return (createSubsetVG(index, 1));
  }

  TranslationVector<float> *
  VectorVG::getCenter() const
  {
    SimpleTranslationVector4<float>* translation = new SimpleTranslationVector4<float> ();
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;

    int vertexCount = fVertices.size() / ModelConstants::ITEMS_IN_CNV;
    for (int vertexIndex = 0; vertexIndex < vertexCount; vertexIndex++)
      {
        x += fVertices.at(vertexIndex * ModelConstants::ITEMS_IN_CNV);
        y += fVertices.at(vertexIndex * ModelConstants::ITEMS_IN_CNV + 1);
        z += fVertices.at(vertexIndex * ModelConstants::ITEMS_IN_CNV + 2);
      }

    x /= vertexCount;
    y /= vertexCount;
    z /= vertexCount;

    translation->setX(x);
    translation->setY(y);
    translation->setZ(z);

    return (translation);
  }

  vector<float> &
  VectorVG::getColours()
  {
    return (fColours);
  }

  int
  VectorVG::getIndexWithinParent() const
  {
    return (fIndexWithinParent);
  }

  vector<float> &
  VectorVG::getNormals()
  {
    return (fNormals);
  }

  VertexGroup *
  VectorVG::getParent() const
  {
    return (fParent);
  }

  int
  VectorVG::getVertexCount() const
  {
    return (fVertices.size() / ModelConstants::ITEMS_IN_CNV);
  }

  vector<float> &
  VectorVG::getVertices()
  {
    return (fVertices);
  }

  bool
  VectorVG::isSubset() const
  {
    return (fIsSubset);
  }

  void
  VectorVG::mergeWithParent() const throw (SEInvalidOperationException)
  {
    if (!fIsSubset)
      {
        throw SEInvalidOperationException();
      }

    for (unsigned int index = 0; index < fColours.size(); index++)
      {
        fParent->getColours().at(index) = fColours.at(index);
        fParent->getNormals().at(index) = fNormals.at(index);
        fParent->getVertices().at(index) = fVertices.at(index);
      }
  }

  void
  VectorVG::setColours(vector<float> colours)
  {
    fColours = colours;
  }

  void
  VectorVG::setIndexWithinParent(int const indexWithinParent)
  {
    fIndexWithinParent = indexWithinParent;
  }

  void
  VectorVG::setNormals(vector<float> normals)
  {
    fNormals = normals;
  }

  void
  VectorVG::setVertices(vector<float> vertices)
  {
    fVertices = vertices;
  }
}
