/*
 * Copyright © 2014 Simple Entertainment Limited
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

// Core
#include "Simplicity.h"

// Common
#include "common/AddressEquals.h"
#include "common/Timer.h"

// Engine
#include "engine/CompositeEngine.h"
#include "engine/DebugSerialCompositeEngine.h"
#include "engine/Engine.h"
#include "engine/SerialCompositeEngine.h"

// Entity
#include "entity/Categories.h"
#include "entity/Component.h"
#include "entity/Entity.h"

// Graph
#include "graph/Graph.h"
#include "graph/OcTree.h"
#include "graph/QuadTree.h"
#include "graph/SimpleGraph.h"

// Input
#include "input/Button.h"
#include "input/Keyboard.h"
#include "input/KeyboardButtonEvent.h"
#include "input/Mouse.h"
#include "input/MouseButtonEvent.h"
#include "input/MouseMoveEvent.h"

// Math
#include "math/Distance.h"
#include "math/Interpolation.h"
#include "math/Intersection.h"
#include "math/MathConstants.h"
#include "math/MathFunctions.h"
#include "math/Matrix.h"
#include "math/Vector.h"

// Messaging
#include "messaging/Events.h"
#include "messaging/Messages.h"

// Model
#include "model/Line.h"
#include "model/Mesh.h"
#include "model/Model.h"
#include "model/ModelFactory.h"
#include "model/ModelFunctions.h"
#include "model/Plane.h"
#include "model/shape/Box.h"
#include "model/shape/Capsule.h"
#include "model/shape/Circle.h"
#include "model/shape/Cube.h"
#include "model/shape/Cylinder.h"
#include "model/shape/Shape.h"
#include "model/shape/Sphere.h"
#include "model/shape/Square.h"
#include "model/shape/Torus.h"
#include "model/shape/Triangle.h"
#include "model/SimpleMesh.h"
#include "model/SimpleModelFactory.h"
#include "model/Text.h"
#include "model/Vertex.h"

// Parallel
#include "parallel/OpenCL.h"

// Physics
#include "physics/Body.h"
#include "physics/PhysicsFactory.h"

// Rendering
#include "rendering/Renderer.h"
#include "rendering/RenderingEngine.h"
#include "rendering/RenderingFactory.h"
#include "rendering/Shader.h"
#include "rendering/Texture.h"

// Scene
#include "scene/Camera.h"
#include "scene/FlyingCameraEngine.h"
#include "scene/Light.h"

// Scripting
#include "scripting/Script.h"
#include "scripting/ScriptingEngine.h"

// Windowing
#include "windowing/WindowEngine.h"
