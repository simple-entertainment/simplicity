/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SIMPLESCENE_H_
#define SIMPLESCENE_H_

#include "Scene.h"

namespace simplicity
{
    /**
     * <p>
     * A simple implementation of a {@link simplicity::Scene Scene}.
     * </p>
     *
     * @author Gary Buyn
     */
    class SimpleScene : public Scene
    {
        public:
            /**
             * Creates an instance of <code>SimpleScene</code>.
             */
            SimpleScene();

            /**
             * Disposes of an instance of <code>SimpleScene</code>.
             */
            virtual
            ~SimpleScene();

            void
            addCamera(Camera* const camera);

            void
            addLight(Light* const light);

            vector<Camera*>*
            getCameras();

            vector<Light*>*
            getLights();

            SceneGraph*
            getSceneGraph();

            void
            setCameras(vector<Camera*>* const cameras);

            void
            setLights(vector<Light*>* const lights);

            void
            setSceneGraph(SceneGraph* const sceneGraph);

        private:
            /**
             * <p>
             * The {@link simplicity::Camera Camera}s that can be used to view this <code>Scene</code> from specific angles.
             * </p>
             */
            vector<Camera*>* fCameras;

            /**
             * <p>
             * The {@link simplicity::Light Light}s that can be used to illuminate this <code>Scene</code>.
             * </p>
             */
            vector<Light*>* fLights;

            /**
             * <p>
             * The {@link simplicity::SceneGraph SceneGraph} that describes the relative locations of this <code>Scene</code>'s content.
             * </p>
             */
            SceneGraph* fSceneGraph;
    };
}

#endif /* SIMPLESCENE_H_ */