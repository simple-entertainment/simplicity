/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include "../vector/SimpleTranslationVectorf4.h"
#include "IndexedVectorVG.h"
#include "ModelConstants.h"

namespace simplicity
{
    IndexedVectorVG::IndexedVectorVG() :
        fColours(0), fIndexWithinParent(-1), fIndices(0), fIsSubset(false), fNormals(0), fParent(0), fVertices(0)
    {
    }

    IndexedVectorVG::IndexedVectorVG(IndexedVectorVG* const parent) :
        fColours(0), fIndexWithinParent(-1), fIndices(0), fIsSubset(true), fNormals(0), fParent(parent), fVertices(0)
    {
    }

    IndexedVectorVG::~IndexedVectorVG()
    {
        delete fColours;
        delete fIndices;
        delete fNormals;
        delete fVertices;
    }

    VertexGroup*
    IndexedVectorVG::createEdgeSubsetVG(const int index)
    {
        return (createSubsetVG(index, 2));
    }

    VertexGroup*
    IndexedVectorVG::createFaceSubsetVG(const int index)
    {
        return (createSubsetVG(index * ModelConstants::VERTICES_IN_A_FACE, ModelConstants::VERTICES_IN_A_FACE));
    }

    VertexGroup*
    IndexedVectorVG::createSubsetVG(const int index, const int length)
    {
        int subsetStart = index * ModelConstants::ITEMS_IN_CNV;
        int subsetLength = length * ModelConstants::ITEMS_IN_CNV;

        vector<int>* subsetIndices = new vector<int> (fIndices->begin() + index, fIndices->begin() + index + length);
        vector<float>* subsetColours = new vector<float> (fColours->begin() + subsetStart, fColours->begin() + subsetStart + subsetLength);
        vector<float>* subsetNormals = new vector<float> (fNormals->begin() + subsetStart, fNormals->begin() + subsetStart + subsetLength);
        vector<float>* subsetVertices = new vector<float> (fVertices->begin() + subsetStart, fVertices->begin() + subsetStart + subsetLength);

        IndexedVectorVG* subsetVertexGroup = new IndexedVectorVG(this);
        subsetVertexGroup->setIndexWithinParent(index);
        subsetVertexGroup->setIndices(subsetIndices);
        subsetVertexGroup->setColours(subsetColours);
        subsetVertexGroup->setNormals(subsetNormals);
        subsetVertexGroup->setVertices(subsetVertices);

        return (subsetVertexGroup);
    }

    VertexGroup*
    IndexedVectorVG::createVertexSubsetVG(const int index)
    {
        return (createSubsetVG(index, 1));
    }

    TranslationVectorf*
    IndexedVectorVG::getCenter()
    {
        SimpleTranslationVectorf4* translation = new SimpleTranslationVectorf4();
        float x = 0.0f;
        float y = 0.0f;
        float z = 0.0f;

        for (unsigned int vertexIndex = 0; vertexIndex < fIndices->size(); vertexIndex++)
        {
            x += fVertices->at(fIndices->at(vertexIndex) * ModelConstants::ITEMS_IN_CNV);
            y += fVertices->at(fIndices->at(vertexIndex) * ModelConstants::ITEMS_IN_CNV + 1);
            z += fVertices->at(fIndices->at(vertexIndex) * ModelConstants::ITEMS_IN_CNV + 2);
        }

        x /= fIndices->size();
        y /= fIndices->size();
        z /= fIndices->size();

        translation->setX(x);
        translation->setY(y);
        translation->setZ(z);

        return (translation);
    }

    vector<float>*
    IndexedVectorVG::getColours()
    {
        return (fColours);
    }

    int
    IndexedVectorVG::getIndexWithinParent()
    {
        return (fIndexWithinParent);
    }

    vector<int>*
    IndexedVectorVG::getIndices()
    {
        return (fIndices);
    }

    vector<float>*
    IndexedVectorVG::getNormals()
    {
        return (fNormals);
    }

    VertexGroup*
    IndexedVectorVG::getParent()
    {
        return (fParent);
    }

    int
    IndexedVectorVG::getVertexCount()
    {
        return (fIndices->size());
    }

    vector<float>*
    IndexedVectorVG::getVertices()
    {
        return (fVertices);
    }

    bool
    IndexedVectorVG::isSubset()
    {
        return (fIsSubset);
    }

    void
    IndexedVectorVG::mergeWithParent() throw (SEInvalidOperationException)
    {
        if (!fIsSubset)
        {
            throw SEInvalidOperationException();
        }

        for (unsigned int index = 0; index < fIndices->size(); index++)
        {
            int vectorIndex = fIndices->at(index) * ModelConstants::ITEMS_IN_CNV;
            int parentVectorIndex = ((IndexedVectorVG*) fParent)->getIndices()->at(fIndexWithinParent + index) * ModelConstants::ITEMS_IN_CNV;

            for (int cnvIndex = 0; cnvIndex < ModelConstants::ITEMS_IN_CNV; cnvIndex++)
            {
                fParent->getColours()->at(parentVectorIndex + cnvIndex) = fColours->at(vectorIndex + cnvIndex);
                fParent->getNormals()->at(parentVectorIndex + cnvIndex) = fNormals->at(vectorIndex + cnvIndex);
                fParent->getVertices()->at(parentVectorIndex + cnvIndex) = fVertices->at(vectorIndex + cnvIndex);
            }
        }
    }

    void
    IndexedVectorVG::setColours(vector<float>* const colours)
    {
        fColours = colours;
    }

    void
    IndexedVectorVG::setIndexWithinParent(const int indexWithinParent)
    {
        fIndexWithinParent = indexWithinParent;
    }

    void
    IndexedVectorVG::setIndices(vector<int>* const indices)
    {
        fIndices = indices;
    }

    void
    IndexedVectorVG::setNormals(vector<float>* const normals)
    {
        fNormals = normals;
    }

    void
    IndexedVectorVG::setVertices(vector<float>* const vertices)
    {
        fVertices = vertices;
    }
}
