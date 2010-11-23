/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include "../vector/SimpleTranslationVectorf4.h"
#include "VectorVG.h"
#include "ModelConstants.h"

namespace simplicity
{
    VectorVG::VectorVG() :
        fColours(0), fIndexWithinParent(-1), fIsSubset(false), fNormals(0), fParent(0), fVertices(0)
    {
    }

    VectorVG::VectorVG(VectorVG* const parent) :
        fColours(0), fIndexWithinParent(-1), fIsSubset(true), fNormals(0), fParent(parent), fVertices(0)
    {
    }

    VectorVG::~VectorVG()
    {
        delete fColours;
        delete fNormals;
        delete fVertices;
    }

    VertexGroup*
    VectorVG::createEdgeSubsetVG(const int index)
    {
        return (createSubsetVG(index, 2));
    }

    VertexGroup*
    VectorVG::createFaceSubsetVG(const int index)
    {
        return (createSubsetVG(index * ModelConstants::VERTICES_IN_A_FACE, ModelConstants::VERTICES_IN_A_FACE));
    }

    VertexGroup*
    VectorVG::createSubsetVG(const int index, const int length)
    {
        int subsetStart = index * ModelConstants::ITEMS_IN_CNV;
        int subsetLength = length * ModelConstants::ITEMS_IN_CNV;

        vector<float>* subsetColours = new vector<float> (fColours->begin() + subsetStart, fColours->begin() + subsetStart + subsetLength);
        vector<float>* subsetNormals = new vector<float> (fNormals->begin() + subsetStart, fNormals->begin() + subsetStart + subsetLength);
        vector<float>* subsetVertices = new vector<float> (fVertices->begin() + subsetStart, fVertices->begin() + subsetStart + subsetLength);

        VectorVG* subsetVertexGroup = new VectorVG(this);
        subsetVertexGroup->setIndexWithinParent(index);
        subsetVertexGroup->setColours(subsetColours);
        subsetVertexGroup->setNormals(subsetNormals);
        subsetVertexGroup->setVertices(subsetVertices);

        return (subsetVertexGroup);
    }

    VertexGroup*
    VectorVG::createVertexSubsetVG(const int index)
    {
        return (createSubsetVG(index, 1));
    }

    TranslationVectorf*
    VectorVG::getCenter()
    {
        SimpleTranslationVectorf4* translation = new SimpleTranslationVectorf4();
        float x = 0.0f;
        float y = 0.0f;
        float z = 0.0f;

        int vertexCount = fVertices->size() / ModelConstants::ITEMS_IN_CNV;
        for (int vertexIndex = 0; vertexIndex < vertexCount; vertexIndex++)
        {
            x += fVertices->at(vertexIndex * ModelConstants::ITEMS_IN_CNV);
            y += fVertices->at(vertexIndex * ModelConstants::ITEMS_IN_CNV + 1);
            z += fVertices->at(vertexIndex * ModelConstants::ITEMS_IN_CNV + 2);
        }

        x /= vertexCount;
        y /= vertexCount;
        z /= vertexCount;

        translation->setX(x);
        translation->setY(y);
        translation->setZ(z);

        return (translation);
    }

    vector<float>*
    VectorVG::getColours()
    {
        return (fColours);
    }

    int
    VectorVG::getIndexWithinParent()
    {
        return (fIndexWithinParent);
    }

    vector<float>*
    VectorVG::getNormals()
    {
        return (fNormals);
    }

    VertexGroup*
    VectorVG::getParent()
    {
        return (fParent);
    }

    int
    VectorVG::getVertexCount()
    {
        return (fVertices->size() / ModelConstants::ITEMS_IN_CNV);
    }

    vector<float>*
    VectorVG::getVertices()
    {
        return (fVertices);
    }

    bool
    VectorVG::isSubset()
    {
        return (fIsSubset);
    }

    void
    VectorVG::mergeWithParent() throw (SEInvalidOperationException)
    {
        if (!fIsSubset)
        {
            throw SEInvalidOperationException();
        }

        for (unsigned int index = 0; index < fColours->size(); index++)
        {
            fParent->getColours()->at(index) = fColours->at(index);
            fParent->getNormals()->at(index) = fNormals->at(index);
            fParent->getVertices()->at(index) = fVertices->at(index);
        }
    }

    void
    VectorVG::setColours(vector<float>* const colours)
    {
        fColours = colours;
    }

    void
    VectorVG::setIndexWithinParent(const int indexWithinParent)
    {
        fIndexWithinParent = indexWithinParent;
    }

    void
    VectorVG::setNormals(vector<float>* const normals)
    {
        fNormals = normals;
    }

    void
    VectorVG::setVertices(vector<float>* const vertices)
    {
        fVertices = vertices;
    }
}
