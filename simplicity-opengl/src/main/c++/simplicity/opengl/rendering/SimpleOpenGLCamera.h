/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SIMPLEOPENGLCAMERA_H_
#define SIMPLEOPENGLCAMERA_H_

#include <log4cpp/Category.hh>

#include <simplicity/rendering/Camera.h>

namespace simplicity
{
  namespace opengl
  {
    /**
     * <p>
     * A viewpoint within a <code>SceneGraph</code> rendered by a JOGL rendering environment. This implementation uses only simple camera techniques and
     * properties.
     * </p>
     *
     * <p>
     * The viewing frustum is the shape that contains all components of the <code>SceneGraph</code> displayed when viewing through a
     * <code>SimpleJOGLCamera</code>. The following diagram shows the 'side' and 'front' views of a viewing frustum.
     * </p>
     *
     * <pre>
     *              _______
     *       /|    |\     /|
     *      / |    | \___/ |
     * _\  |  |    | |   | |
     *  /  |  |    | |___| |
     *      \ |    | /   \ |
     *       \|    |/_____\|
     *
     *   side        front
     * </pre>
     *
     * <p>
     * <b>Eye</b>
     * </p>
     *
     * <p>
     * The eye is the position of the viewer. The 'front' of the frustum in the context of this explanation is the side of the frustum that is closest to
     * the eye. In the 'side' view the eye is shown as the arrow to the left of the frustum.
     * </p>
     *
     * <p>
     * <b>Near Clipping Plane</b>
     * </p>
     *
     * <p>
     * The near clipping plane is a plane in the <code>SceneGraph</code> a distance from the eye in front of which the viewer cannot see i.e. all
     * components of the <code>SceneGraph</code> nearer to the eye than the near clipping plane will be clipped (not drawn). The area on the near clipping
     * plane that constitutes a face of the frustum is shown as the short vertical line in the 'side' view and the smaller rectangle in the 'front' view.
     * This face can be thought of as analogous to the screen and is referred to as the frame.
     * </p>
     *
     * <p>
     * <b>Far Clipping Plane</b>
     * </p>
     *
     * <p>
     * The far clipping plane is a plane in the <code>SceneGraph</code> a distance from the eye past which the viewer cannot see i.e. all components of
     * the <code>SceneGraph</code> further from the eye than the far clipping plane will be clipped (not drawn). The area on the far clipping plane that
     * constitutes a face of the frustum is shown as the long vertical line in the 'side' view and the larger rectangle in the 'front' view.
     * </p>
     *
     * <p>
     * <b>Frame Position and Dimensions</b>
     * </p>
     *
     * <p>
     * The dimensions of the areas of the clipping planes that are used as faces of the frustum are calculated automatically by the
     * <code>SimpleJOGLCamera</code>. The diagonal lines in the diagram extend from the four corners of the far clipping plane to the four corners of the
     * near clipping plane and finally (by default) converge at the eye. The frame can be moved on the <code>x</code> and <code>y</code> axis so that the
     * eye no longer resides at this convergence. Also, the aspect ratio of the frame (4:3 by default) can be changed.
     * </p>
     *
     * @author Gary Buyn
     */
    class SimpleOpenGLCamera : public simplicity::Camera
    {
      public:
        /**
         * <p>
         * Creates an instance of <code>SimpleOpenGLCamera</code>.
         * </p>
         */
        SimpleOpenGLCamera();

        /**
         * <p>
         * Disposes of an instance of <code>SimpleOpenGLCamera</code>.
         * </p>
         */
        virtual
        ~SimpleOpenGLCamera();

        void
        apply();

        float
        getFarClippingDistance() const;

        float
        getFrameAspectRatio() const;

        float
        getFrameHeight() const;

        float
        getFrameWidth() const;

        float
        getFrameX() const;

        float
        getFrameY() const;

        float
        getNearClippingDistance() const;

        boost::shared_ptr<simplicity::Node>
        getNode() const;

        boost::shared_ptr<simplicity::Camera>
        getPickCamera(const simplicity::Pick pick) const;

        simplicity::Camera::ProjectionMode
        getProjectionMode() const;

        const simplicity::TransformationMatrix<float>&
        getTransformation() const;

        void
        init();

        bool
        isInitialised() const;

        void
        setFarClippingDistance(const float farClippingDistance);

        void
        setFrameAspectRatio(const float frameAspectRatio);

        void
        setFrameHeight(const float frameHeight);

        void
        setFrameWidth(const float frameWidth);

        void
        setFrameX(const float frameX);

        void
        setFrameY(const float frameY);

        void
        setInitialised(const bool isInitialised);

        void
        setNearClippingDistance(const float nearClippingDistance);

        void
        setNode(boost::shared_ptr<simplicity::Node> node);

        void
        setProjectionMode(const simplicity::Camera::ProjectionMode projectionMode);

      private:
        /**
         * <p>
         * Logs messages associated with this class.
         * </p>
         */
        static log4cpp::Category& fLogger;

        /**
         * <p>
         * The default far clipping plane.
         * </p>
         */
        static const float DEFAULT_FAR_CLIPPING_PLANE = 1000.0f;

        /**
         * <p>
         * The default frame aspect ratio.
         * </p>
         */
        static const float DEFAULT_FRAME_ASPECT_RATIO = 0.75f; // 3:4

        /**
         * <p>
         * The default frame width.
         * </p>
         */
        static const float DEFAULT_FRAME_WIDTH = 0.1f;

        /**
         * <p>
         * The default near clipping plane.
         * </p>
         */
        static const float DEFAULT_NEAR_CLIPPING_PLANE = 0.1f;

        /**
         * <p>
         * The distance from the eye past which components of the <code>SceneGraph</code> will be clipped (not drawn).
         * </p>
         */
        float fFarClippingDistance;

        /**
         * <p>
         * The aspect ratio of the frame. An aspect ratio of 3:4 is stored as 3 / 4 (0.75).
         * </p>
         */
        float fFrameAspectRatio;

        /**
         * <p>
         * The width of the frame.
         * </p>
         */
        float fFrameWidth;

        /**
         * <p>
         * The location of the frame on the <code>x</code> axis relative to the location and orientation of this <code>SimpleJOGLCamera</code>.
         * </p>
         */
        float fFrameX;

        /**
         * <p>
         * The location of the frame on the <code>y</code> axis relative to the location and orientation of this <code>SimpleJOGLCamera</code>.
         * </p>
         */
        float fFrameY;

        /**
         * The initialisation status. Determines if this <code>SimpleJOGLCamera</code> is initialised.
         */
        bool fInitialised;

        /**
         * <p>
         * The distance from the eye before which components of the <code>SceneGraph</code> will be clipped (not drawn).
         * </p>
         */
        float fNearClippingDistance;

        /**
         * <p>
         * The <code>Node</code> that represents this <code>SimpleJOGLCamera</code>'s location and orientation.
         * </p>
         */
        boost::shared_ptr<simplicity::Node> fNode;

        /**
         * <p>
         * The projection mode used to render a <code>SceneGraph</code>.
         * </p>
         */
        simplicity::Camera::ProjectionMode fProjectionMode;

        /**
         * <p>
         * The inverted absolute transformation for the <code>Node</code> of this <code>Camera</code>, or a zero vector if the <code>Node</code>
         * does not exist.
         * </p>
         */
        mutable boost::scoped_ptr<simplicity::TransformationMatrix<float> > fTransformation;
    };
  }
}

#endif /* SIMPLEOPENGLCAMERA_H_ */
