/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <simplicity/engine/SimpleCompositeEngine.h>
#include <simplicity/input/InputEvent.h>
#include <simplicity/Simplicity.h>
#include <simplicity/SimpleEvents.h>

#include <simplicity/opengl/model/OpenGLModelFactory.h>

#include <simplicity/freeglut/engine/FreeglutEngine.h>

#include "picking/SimpleOpenGLPickerDemo.h"
#include "rendering/AlwaysAndNotEqualStencilOpenGLRenderersDemo.h"
#include "rendering/BlendingOpenGLRendererDemo.h"
#include "rendering/CullFaceOpenGLRendererDemo.h"
#include "rendering/DepthClearingOpenGLRendererDemo.h"
#include "rendering/MonoColourOpenGLRendererDemo.h"
#include "rendering/OutlineOpenGLRendererDemo.h"
#include "rendering/SimpleOpenGLRendererDemo.h"
#include "rendering/StencilClearingOpenGLRendererDemo.h"

using namespace simplicity;
using namespace simplicity::freeglut;
using namespace simplicity::opengl;
using namespace std;

unique_ptr<CompositeEngine> engine(new SimpleCompositeEngine);
CompositeEngine& engineRef = *engine;

vector<unique_ptr<Demo> > demos;
unsigned int demoIndex = 0;

void nextDemo()
{
	if (demoIndex < demos.size() - 1)
	{
		engineRef.removeEngine(demos.at(demoIndex)->getEngine());
		demos.at(demoIndex)->dispose();

		demoIndex++;

		demos.at(demoIndex)->init();
		engineRef.addEngine(demos.at(demoIndex)->getEngine());
	}
}

void previousDemo()
{
	if (demoIndex > 0)
	{
		engineRef.removeEngine(demos.at(demoIndex)->getEngine());
		demos.at(demoIndex)->dispose();

		demoIndex--;

		demos.at(demoIndex)->init();
		engineRef.addEngine(demos.at(demoIndex)->getEngine());
	}
}

void changeDemo(const boost::any data)
{
	const InputEvent& event = boost::any_cast<InputEvent>(data);

	if (event.key == ' ')
	{
		nextDemo();
	}
	else if (event.key == 8) // backspace
	{
		previousDemo();
	}
}

int main(int argc, char** argv)
{
	shared_ptr<Engine> freeglutEngine(new FreeglutEngine);
	freeglutEngine->setPreferredFrequency(100);
	engine->addEngine(freeglutEngine);

	Simplicity::init(move(engine));

	Simplicity::registerObserver(INPUT_EVENT, changeDemo);

	unique_ptr<ModelFactory> modelFactory(new OpenGLModelFactory);
	ModelFactory::setInstance(move(modelFactory));

	unique_ptr<Demo> simpleOpenGLRendererDemo(new SimpleOpenGLRendererDemo);
	demos.push_back(move(simpleOpenGLRendererDemo));
	unique_ptr<Demo> monoColourOpenGLRendererDemo(new MonoColourOpenGLRendererDemo);
	demos.push_back(move(monoColourOpenGLRendererDemo));
	unique_ptr<Demo> cullFaceOpenGLRendererDemo(new CullFaceOpenGLRendererDemo);
	demos.push_back(move(cullFaceOpenGLRendererDemo));
	unique_ptr<Demo> blendingOpenGLRendererDemo(new BlendingOpenGLRendererDemo);
	demos.push_back(move(blendingOpenGLRendererDemo));
	unique_ptr<Demo> alwaysAndNotEqualStencilOpenGLRenderersDemo(new AlwaysAndNotEqualStencilOpenGLRenderersDemo);
	demos.push_back(move(alwaysAndNotEqualStencilOpenGLRenderersDemo));
	unique_ptr<Demo> stencilClearingOpenGLRendererDemo(new StencilClearingOpenGLRendererDemo);
	demos.push_back(move(stencilClearingOpenGLRendererDemo));
	unique_ptr<Demo> depthClearingOpenGLRendererDemo(new DepthClearingOpenGLRendererDemo);
	demos.push_back(move(depthClearingOpenGLRendererDemo));
	unique_ptr<Demo> outlineOpenGLRendererDemo(new OutlineOpenGLRendererDemo);
	demos.push_back(move(outlineOpenGLRendererDemo));
	unique_ptr<Demo> simpleOpenGLPickerDemo(new SimpleOpenGLPickerDemo);
	demos.push_back(move(simpleOpenGLPickerDemo));

	demos.at(demoIndex)->init();
	engineRef.addEngine(demos.at(demoIndex)->getEngine());

	Simplicity::start();

	return 0;
}
