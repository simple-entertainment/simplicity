/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <boost/math/constants/constants.hpp>

#include <simplicity/scenegraph/model/SimpleModelNode.h>
#include <simplicity/scenegraph/SimpleNode.h>
#include <simplicity/vector/SimpleRGBAColourVector4.h>
#include <simplicity/vector/SimpleTranslationVector4.h>

#include <simplicity/opengl/model/shape/GLUCapsule.h>
#include <simplicity/opengl/model/shape/GLUCylinder.h>
#include <simplicity/opengl/model/shape/GLUSphere.h>
#include <simplicity/opengl/model/shape/GLUTorus.h>
#include <simplicity/opengl/rendering/AlwaysStencilOpenGLRenderer.h>
#include <simplicity/opengl/rendering/NotEqualStencilOpenGLRenderer.h>
#include <simplicity/opengl/rendering/SimpleOpenGLRenderer.h>
#include <simplicity/opengl/rendering/StencilClearingOpenGLRenderer.h>

#include "StencilClearingOpenGLRendererDemo.h"

namespace simplicity
{
  namespace opengl
  {
    StencilClearingOpenGLRendererDemo::StencilClearingOpenGLRendererDemo() :
      fFirstRoot(shared_ptr<Node> (new SimpleNode)), fSecondRoot(shared_ptr<Node> (new SimpleNode))
    {
    }

    StencilClearingOpenGLRendererDemo::~StencilClearingOpenGLRendererDemo()
    {
    }

    void
    StencilClearingOpenGLRendererDemo::dispose(RenderingEngine& renderingEngine)
    {
      renderingEngine.getScene()->getSceneGraph()->removeSubgraph(*fFirstRoot);
      renderingEngine.removeRenderer(*renderingEngine.getRenderers().at(0));

      renderingEngine.getScene()->getSceneGraph()->removeSubgraph(*fSecondRoot);
      renderingEngine.removeRenderer(*renderingEngine.getRenderers().at(0));
    }

    string
    StencilClearingOpenGLRendererDemo::getDescription()
    {
      return ("Pass #1 Renders the sphere, cylinder and capsule and assigns a value to the stencil buffer.\nBefore Pass #2 Clears the stencil buffer.\nPass #2 Renders the torus only where the stencil buffer has not been assigned a value.\nThe result of this is that the torus can be rendered over the other shapes.");
    }

    string
    StencilClearingOpenGLRendererDemo::getTitle()
    {
      return ("StencilClearingOpenGLRenderer");
    }

    void
    StencilClearingOpenGLRendererDemo::init(RenderingEngine& renderingEngine)
    {
      shared_ptr<SimpleModelNode> capsuleNode(new SimpleModelNode);
      capsuleNode->getTransformation().translate(SimpleTranslationVector4<float> (-3.0f, 3.0f, 0.0f, 1.0f));
      shared_ptr<GLUCapsule> capsule(new GLUCapsule);
      capsule->setColour(
          shared_ptr<SimpleRGBAColourVector4<float> > (new SimpleRGBAColourVector4<float> (0.75f, 0.0f, 0.0f, 1.0f)));
      capsuleNode->setModel(capsule);
      fFirstRoot->addChild(capsuleNode);

      shared_ptr<SimpleModelNode> cylinderNode(new SimpleModelNode);
      cylinderNode->getTransformation().translate(SimpleTranslationVector4<float> (0.0f, 3.0f, 0.0f, 1.0f));
      shared_ptr<GLUCylinder> cylinder(new GLUCylinder);
      cylinder->setColour(
          shared_ptr<SimpleRGBAColourVector4<float> > (new SimpleRGBAColourVector4<float> (0.0f, 0.75f, 0.0f, 1.0f)));
      cylinderNode->setModel(cylinder);
      fFirstRoot->addChild(cylinderNode);

      shared_ptr<SimpleModelNode> sphereNode(new SimpleModelNode);
      sphereNode->getTransformation().translate(SimpleTranslationVector4<float> (3.0f, 3.0f, 0.0f, 1.0f));
      shared_ptr<GLUSphere> sphere(new GLUSphere);
      sphere->setColour(
          shared_ptr<SimpleRGBAColourVector4<float> > (new SimpleRGBAColourVector4<float> (0.0f, 0.0f, 0.75f, 1.0f)));
      sphereNode->setModel(sphere);
      fFirstRoot->addChild(sphereNode);

      shared_ptr<SimpleModelNode> torusNode(new SimpleModelNode);
      torusNode->getTransformation().translate(SimpleTranslationVector4<float> (0.0f, -2.0f, 0.0f, 1.0f));
      shared_ptr<GLUTorus> torus(new GLUTorus);
      torusNode->setModel(torus);
      fSecondRoot->addChild(torusNode);

      renderingEngine.getScene()->getSceneGraph()->addSubgraph(fFirstRoot);
      renderingEngine.getScene()->getSceneGraph()->addSubgraph(fSecondRoot);

      shared_ptr<SimpleOpenGLRenderer> wrappedRenderer(new SimpleOpenGLRenderer);

      shared_ptr<AlwaysStencilOpenGLRenderer> firstRenderer(new AlwaysStencilOpenGLRenderer(wrappedRenderer));
      renderingEngine.addRenderer(firstRenderer);
      renderingEngine.setRendererRoot(*firstRenderer, fFirstRoot);

      shared_ptr<StencilClearingOpenGLRenderer> secondRenderer(
          new StencilClearingOpenGLRenderer(
              shared_ptr<NotEqualStencilOpenGLRenderer> (new NotEqualStencilOpenGLRenderer(wrappedRenderer))));
      renderingEngine.addRenderer(secondRenderer);
      renderingEngine.setRendererRoot(*secondRenderer, fSecondRoot);
    }
  }
}
