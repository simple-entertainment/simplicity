/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <GL/glew.h>

#include <simplicity/vector/SimpleTransformationMatrix44.h>

#include "SimpleOpenGLCamera.h"

using namespace boost;

namespace simplicity
{
  namespace opengl
  {
    log4cpp::Category& SimpleOpenGLCamera::fLogger = log4cpp::Category::getInstance("simplicity_opengl::SimpleOpenGLCamera");

    SimpleOpenGLCamera::SimpleOpenGLCamera() :
      fFarClippingDistance(DEFAULT_FAR_CLIPPING_PLANE), fFrameAspectRatio(DEFAULT_FRAME_ASPECT_RATIO),
          fFrameWidth(DEFAULT_FRAME_WIDTH), fFrameX(0.0f), fFrameY(0.0f), fInitialised(false),
          fNearClippingDistance(DEFAULT_NEAR_CLIPPING_PLANE), fProjectionMode(Camera::PERSPECTIVE)
    {
    }

    SimpleOpenGLCamera::~SimpleOpenGLCamera()
    {
    }

    void
    SimpleOpenGLCamera::apply()
    {
      if (!fInitialised)
      {
        init();
      }

      glMultMatrixf(getTransformation().getRawData());
    }

    float
    SimpleOpenGLCamera::getFarClippingDistance() const
    {
      return (fFarClippingDistance);
    }

    float
    SimpleOpenGLCamera::getFrameAspectRatio() const
    {
      return (fFrameAspectRatio);
    }

    float
    SimpleOpenGLCamera::getFrameHeight() const
    {
      return (fFrameWidth * fFrameAspectRatio);
    }

    float
    SimpleOpenGLCamera::getFrameWidth() const
    {
      return (fFrameWidth);
    }

    float
    SimpleOpenGLCamera::getFrameX() const
    {
      return (fFrameX);
    }

    float
    SimpleOpenGLCamera::getFrameY() const
    {
      return (fFrameY);
    }

    float
    SimpleOpenGLCamera::getNearClippingDistance() const
    {
      return (fNearClippingDistance);
    }

    shared_ptr<Node>
    SimpleOpenGLCamera::getNode() const
    {
      return (fNode);
    }

    shared_ptr<Camera>
    SimpleOpenGLCamera::getPickCamera(const Pick pick) const
    {
      // Create the Camera to pick with.
      shared_ptr<Camera> pickCamera(new SimpleOpenGLCamera);
      pickCamera->setFarClippingDistance(getFarClippingDistance());
      pickCamera->setFrameAspectRatio(getFrameAspectRatio());
      pickCamera->setFrameWidth(pick.width);
      pickCamera->setFrameX(pick.x - (getFrameWidth() / 2) + getFrameX());
      pickCamera->setFrameY((getFrameWidth() * getFrameAspectRatio() / 2) - pick.y + getFrameY());
      pickCamera->setNearClippingDistance(getNearClippingDistance());
      pickCamera->setNode(getNode());

      return (pickCamera);
    }

    Camera::ProjectionMode
    SimpleOpenGLCamera::getProjectionMode() const
    {
      return (fProjectionMode);
    }

    const TransformationMatrix<float>&
    SimpleOpenGLCamera::getTransformation() const
    {
      if (!fNode)
      {
        fTransformation.reset(new SimpleTransformationMatrix44<float> );
        return (*fTransformation);
      }

      fTransformation.reset(
          new SimpleTransformationMatrix44<float> (
              dynamic_cast<const SimpleMatrix44<float>&> (fNode->getAbsoluteTransformation()).getData()));

      try
      {
        fTransformation->invert();
      }
      catch (SEInvalidOperationException& e)
      {
        fLogger.error("Failed to invert the transformation: s%", e.what());
      }

      return (*fTransformation);
    }

    void
    SimpleOpenGLCamera::init()
    {
      if (!fProjectionMode)
      {
        throw new SEInvalidOperationException();
      }

      glMatrixMode(GL_PROJECTION);

      glLoadIdentity();

      if (fProjectionMode == Camera::ORTHOGONAL)
      {
        glOrtho(-fFrameWidth / 2 + fFrameX, fFrameWidth / 2 + fFrameX, -fFrameWidth * fFrameAspectRatio / 2 + fFrameY,
            fFrameWidth * fFrameAspectRatio / 2 + fFrameY, fNearClippingDistance, fFarClippingDistance);
      }
      else if (fProjectionMode == Camera::PERSPECTIVE)
      {
        glFrustum(-fFrameWidth / 2 + fFrameX, fFrameWidth / 2 + fFrameX, -fFrameWidth * fFrameAspectRatio / 2 + fFrameY,
            fFrameWidth * fFrameAspectRatio / 2 + fFrameY, fNearClippingDistance, fFarClippingDistance);
      }

      glMatrixMode(GL_MODELVIEW);

      fInitialised = true;
    }

    bool
    SimpleOpenGLCamera::isInitialised() const
    {
      return (fInitialised);
    }

    void
    SimpleOpenGLCamera::setFarClippingDistance(const float farClippingDistance)
    {
      fFarClippingDistance = farClippingDistance;

      fInitialised = false;
    }

    /**
     * <p>
     * Sets the aspect ratio of the frame. An aspect ratio of 3:4 is stored as 3 / 4 (0.75). When setting the aspect ratio the frame width is left
     * unchanged. Only the height is changed to meet the new aspect ratio.
     * </p>
     *
     * @param frameAspectRatio The aspect ratio of the frame.
     */
    void
    SimpleOpenGLCamera::setFrameAspectRatio(const float frameAspectRatio)
    {
      fFrameAspectRatio = frameAspectRatio;

      fInitialised = false;
    }

    void
    SimpleOpenGLCamera::setFrameHeight(const float frameHeight)
    {
      setFrameAspectRatio(frameHeight / fFrameWidth);
    }

    void
    SimpleOpenGLCamera::setFrameWidth(const float frameWidth)
    {
      fFrameWidth = frameWidth;

      fInitialised = false;
    }

    void
    SimpleOpenGLCamera::setFrameX(const float frameX)
    {
      fFrameX = frameX;

      fInitialised = false;
    }

    void
    SimpleOpenGLCamera::setFrameY(const float frameY)
    {
      fFrameY = frameY;

      fInitialised = false;
    }

    void
    SimpleOpenGLCamera::setInitialised(const bool isInitialised)
    {
      fInitialised = isInitialised;
    }

    void
    SimpleOpenGLCamera::setNearClippingDistance(const float nearClippingDistance)
    {
      fNearClippingDistance = nearClippingDistance;

      fInitialised = false;
    }

    void
    SimpleOpenGLCamera::setNode(shared_ptr<Node> node)
    {
      fNode = node;
    }

    void
    SimpleOpenGLCamera::setProjectionMode(const Camera::ProjectionMode projectionMode)
    {
      fProjectionMode = projectionMode;

      fInitialised = false;
    }
  }
}
