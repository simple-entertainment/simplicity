/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor;

import java.io.File;
import java.util.HashMap;
import java.util.Map;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import com.se.simplicity.editor.controller.Controller;
import com.se.simplicity.model.Model;

public class Editor
{
    private ApplicationContext context;
    
    private Map<String, Controller> controllers;
    
	public static Editor editor = new Editor();
	
	private Map<Model, File> files = null;
	
	private Editor()
	{
	    context = new ClassPathXmlApplicationContext("editorContext.xml");
	    controllers = new HashMap<String, Controller>();
		files = new HashMap<Model, File>();
	}
	
	public void addModel(Model model, File file) throws InstantiationException, IllegalAccessException, ClassNotFoundException
	{
		//scene.addModel(model);

		if (file != null)
		{
			files.put(model, file);
		}
	}
	
	public Controller getController(String name)
	{
	    Controller controller = (Controller) context.getBean(name + "Controller");
	    
	    controllers.remove(name);
	    controllers.put(name, controller);
	    
	    return (controller);
	}
	
	public void updateController(String name)
    {
	    controllers.get(name).update();
    }
}
