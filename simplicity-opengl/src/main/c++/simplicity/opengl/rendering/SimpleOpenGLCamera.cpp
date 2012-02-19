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
#include <GL/glew.h>

#include <simplicity/math/MathFactory.h>
#include <simplicity/SEInvalidOperationException.h>

#include "SimpleOpenGLCamera.h"

using namespace std;

namespace simplicity
{
	namespace opengl
	{
		const float SimpleOpenGLCamera::DEFAULT_FAR_CLIPPING_PLANE = 1000.0f;

		const float SimpleOpenGLCamera::DEFAULT_FRAME_ASPECT_RATIO = 0.75f; // 3:4

		const float SimpleOpenGLCamera::DEFAULT_FRAME_WIDTH = 0.1f;

		const float SimpleOpenGLCamera::DEFAULT_NEAR_CLIPPING_PLANE = 0.1f;

		log4cpp::Category& SimpleOpenGLCamera::logger = log4cpp::Category::getInstance(
			"simplicity_opengl::SimpleOpenGLCamera");

		SimpleOpenGLCamera::SimpleOpenGLCamera() :
			farClippingDistance(DEFAULT_FAR_CLIPPING_PLANE), frameAspectRatio(DEFAULT_FRAME_ASPECT_RATIO), frameWidth(
				DEFAULT_FRAME_WIDTH), frameX(0.0f), frameY(0.0f), initialised(false), nearClippingDistance(
				DEFAULT_NEAR_CLIPPING_PLANE), projectionMode(Camera::PERSPECTIVE)
		{
		}

		SimpleOpenGLCamera::~SimpleOpenGLCamera()
		{
		}

		void SimpleOpenGLCamera::apply()
		{
			if (!initialised)
			{
				init();
			}

			glMultMatrixf(getTransformation().getData().data());
		}

		float SimpleOpenGLCamera::getFarClippingDistance() const
		{
			return farClippingDistance;
		}

		float SimpleOpenGLCamera::getFrameAspectRatio() const
		{
			return frameAspectRatio;
		}

		float SimpleOpenGLCamera::getFrameHeight() const
		{
			return frameWidth * frameAspectRatio;
		}

		float SimpleOpenGLCamera::getFrameWidth() const
		{
			return frameWidth;
		}

		float SimpleOpenGLCamera::getFrameX() const
		{
			return frameX;
		}

		float SimpleOpenGLCamera::getFrameY() const
		{
			return frameY;
		}

		float SimpleOpenGLCamera::getNearClippingDistance() const
		{
			return nearClippingDistance;
		}

		std::shared_ptr<Node> SimpleOpenGLCamera::getNode() const
		{
			return node;
		}

		std::shared_ptr<Camera> SimpleOpenGLCamera::getPickCamera(const Pick pick) const
		{
			// Create the Camera to pick with.
			std::shared_ptr<Camera> pickCamera(new SimpleOpenGLCamera);
			pickCamera->setFarClippingDistance(getFarClippingDistance());
			pickCamera->setFrameAspectRatio(getFrameAspectRatio());
			pickCamera->setFrameWidth(pick.width);
			pickCamera->setFrameX(pick.x - (getFrameWidth() / 2) + getFrameX());
			pickCamera->setFrameY((getFrameWidth() * getFrameAspectRatio() / 2) - pick.y + getFrameY());
			pickCamera->setNearClippingDistance(getNearClippingDistance());
			pickCamera->setNode(getNode());

			return pickCamera;
		}

		Camera::ProjectionMode SimpleOpenGLCamera::getProjectionMode() const
		{
			return projectionMode;
		}

		const TransformationMatrix<>& SimpleOpenGLCamera::getTransformation() const
		{
			transformation = MathFactory::getInstance().createTransformationMatrix();

			if (node.get() == NULL)
			{
				return *transformation;
			}

			transformation->setData(node->getAbsoluteTransformation()->getData());

			try
			{
				transformation->invert();
			}
			catch (SEInvalidOperationException& e)
			{
				logger.error("Failed to invert the transformation: s%", e.what());
			}

			return *transformation;
		}

		void SimpleOpenGLCamera::init()
		{
			glMatrixMode(GL_PROJECTION);

			glLoadIdentity();

			if (projectionMode == Camera::ORTHOGONAL)
			{
				glOrtho(-frameWidth / 2 + frameX, frameWidth / 2 + frameX,
					-frameWidth * frameAspectRatio / 2 + frameY, frameWidth * frameAspectRatio / 2 + frameY,
					nearClippingDistance, farClippingDistance);
			}
			else if (projectionMode == Camera::PERSPECTIVE)
			{
				glFrustum(-frameWidth / 2 + frameX, frameWidth / 2 + frameX,
					-frameWidth * frameAspectRatio / 2 + frameY, frameWidth * frameAspectRatio / 2 + frameY,
					nearClippingDistance, farClippingDistance);
			}

			glMatrixMode(GL_MODELVIEW);

			initialised = true;
		}

		bool SimpleOpenGLCamera::isInitialised() const
		{
			return initialised;
		}

		void SimpleOpenGLCamera::setFarClippingDistance(const float farClippingDistance)
		{
			this->farClippingDistance = farClippingDistance;

			initialised = false;
		}

		/**
		 * <p>
		 * Sets the aspect ratio of the frame. An aspect ratio of 3:4 is stored as 3 / 4 (0.75). When setting the aspect ratio the frame width is left
		 * unchanged. Only the height is changed to meet the new aspect ratio.
		 * </p>
		 *
		 * @param frameAspectRatio The aspect ratio of the frame.
		 */
		void SimpleOpenGLCamera::setFrameAspectRatio(const float frameAspectRatio)
		{
			this->frameAspectRatio = frameAspectRatio;

			initialised = false;
		}

		void SimpleOpenGLCamera::setFrameHeight(const float frameHeight)
		{
			setFrameAspectRatio(frameHeight / frameWidth);
		}

		void SimpleOpenGLCamera::setFrameWidth(const float frameWidth)
		{
			this->frameWidth = frameWidth;

			initialised = false;
		}

		void SimpleOpenGLCamera::setFrameX(const float frameX)
		{
			this->frameX = frameX;

			initialised = false;
		}

		void SimpleOpenGLCamera::setFrameY(const float frameY)
		{
			this->frameY = frameY;

			initialised = false;
		}

		void SimpleOpenGLCamera::setInitialised(const bool isInitialised)
		{
			this->initialised = isInitialised;
		}

		void SimpleOpenGLCamera::setNearClippingDistance(const float nearClippingDistance)
		{
			this->nearClippingDistance = nearClippingDistance;

			initialised = false;
		}

		void SimpleOpenGLCamera::setNode(std::shared_ptr<Node> node)
		{
			this->node = node;
		}

		void SimpleOpenGLCamera::setProjectionMode(const Camera::ProjectionMode projectionMode)
		{
			this->projectionMode = projectionMode;

			initialised = false;
		}
	}
}
