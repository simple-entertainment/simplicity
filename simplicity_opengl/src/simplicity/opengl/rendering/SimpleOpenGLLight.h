/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SIMPLEOPENGLLIGHT_H_
#define SIMPLEOPENGLLIGHT_H_

#include <log4cpp/Category.hh>

#include <simplicity/rendering/Light.h>

namespace simplicity
{
  namespace opengl
  {
    /**
     * <p>
     * A light within a {@link simplicity::SceneGraph SceneGraph} rendered by an OpenGL rendering environment. This implementation uses only simple
     * lighting techniques and properties.
     * </p>
     *
     * @author Gary Buyn
     */
    class SimpleOpenGLLight : public simplicity::Light
    {
      public:
        /**
         * <p>
         * Creates an instance of <code>SimpleOpenGLLight</code>.
         * </p>
         */
        SimpleOpenGLLight();

        /**
         * <p>
         * Disposes of an instance of <code>SimpleOpenGLLight</code>.
         * </p>
         */
        virtual
        ~SimpleOpenGLLight();

        void
        apply();

        simplicity::RGBAColourVector<float>&
        getAmbientLight() const;

        simplicity::RGBAColourVector<float>&
        getDiffuseLight() const;

        simplicity::Light::LightingMode
        getLightingMode() const;

        boost::shared_ptr<simplicity::Node>
        getNode() const;

        simplicity::RGBAColourVector<float>&
        getSpecularLight() const;

        const simplicity::TransformationMatrix<float>&
        getTransformation() const;

        void
        init();

        bool
        isInitialised() const;

        void
        setAmbientLight(boost::shared_ptr<simplicity::RGBAColourVector<float> > ambientLight);

        void
        setDiffuseLight(boost::shared_ptr<simplicity::RGBAColourVector<float> > diffuseLight);

        void
        setInitialised(const bool isInitialised);

        void
        setLightingMode(const simplicity::Light::LightingMode lightingMode);

        void
        setNode(boost::shared_ptr<simplicity::Node> node);

        void
        setSpecularLight(boost::shared_ptr<simplicity::RGBAColourVector<float> > specularLight);

      private:
        /**
         * <p>
         * Logs messages associated with this class.
         * </p>
         */
        static log4cpp::Category& fLogger;

        /**
         * <p>
         * The ambient component.
         * </p>
         */
        boost::shared_ptr<simplicity::RGBAColourVector<float> > fAmbientLight;

        /**
         * <p>
         * The diffuse component.
         * </p>
         */
        boost::shared_ptr<simplicity::RGBAColourVector<float> > fDiffuseLight;

        /**
         * <p>
         * Determines if this <code>SimpleOpenGLLight</code> is initialised.
         * </p>
         */
        bool fInitialised;

        /**
         * <p>
         * The lighting mode used to render the {@link simplicity::SceneGraph SceneGraph}.
         * </p>
         */
        simplicity::Light::LightingMode fLightingMode;

        /**
         * <p>
         * The node that represents this <code>SimpleOpenGLLight</code>'s location and orientation of this light.
         * </p>
         */
        boost::shared_ptr<simplicity::Node> fNode;

        /**
         * <p>
         * The specular component.
         * </p>
         */
        boost::shared_ptr<simplicity::RGBAColourVector<float> > fSpecularLight;

        /**
         * <p>
         * The inverted absolute transformation for the <code>Node</code> of this <code>Light</code>, or a zero vector if the <code>Node</code> does
         * not exist.
         * </p>
         */
        mutable boost::scoped_ptr<simplicity::TransformationMatrix<float> > fTransformation;
    };
  }
}

#endif /* SIMPLEOPENGLLIGHT_H_ */
