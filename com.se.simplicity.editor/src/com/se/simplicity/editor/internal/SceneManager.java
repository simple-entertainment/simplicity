package com.se.simplicity.editor.internal;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.xml.parsers.ParserConfigurationException;

import org.eclipse.core.runtime.CoreException;
import org.eclipse.ui.IFileEditorInput;
import org.w3c.dom.DOMException;
import org.xml.sax.SAXException;

import com.se.simplicity.jogl.rendering.SimpleJOGLRenderer;
import com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine;
import com.se.simplicity.jogl.viewport.SimpleJOGLViewport;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.Renderer;
import com.se.simplicity.rendering.engine.RenderingEngine;
import com.se.simplicity.util.metadata.rendering.MetaDataCamera;
import com.se.simplicity.util.metadata.scene.MetaDataScene;
import com.se.simplicity.util.scene.SceneFactory;
import com.se.simplicity.viewport.Viewport;

public class SceneManager
{
    private static SceneManager sceneManager = new SceneManager();
    
    public static SceneManager getSceneManager()
    {
        return (sceneManager);
    }

    private List<SceneChangedListener> sceneModifiedListeners;

    private Map<String, MetaDataScene> scenes;

    private SceneManager()
    {
        sceneModifiedListeners = new ArrayList<SceneChangedListener>();
        scenes = new HashMap<String, MetaDataScene>();
    }

    public void addSceneDefinition(IFileEditorInput input) throws DOMException, ParserConfigurationException, SAXException, IOException,
            InstantiationException, IllegalAccessException, ClassNotFoundException, CoreException
    {
        scenes.put(input.getFile().getFullPath().toString(), (MetaDataScene) SceneFactory.loadFromSource(input.getFile().getContents()));
    }
    
    public void addSceneModifiedListener(SceneChangedListener listener)
    {
        sceneModifiedListeners.add(listener);
    }

    public void fireSceneModifiedEvent(String id)
    {
        SceneChangedEvent event = new SceneChangedEvent(scenes.get(id));
        
        for (SceneChangedListener listener : sceneModifiedListeners)
        {
            listener.sceneGraphChanged(event);
        }
    }

    public MetaDataScene getScene(String id)
    {
        return (scenes.get(id));
    }

    public Viewport getViewportToScene(String id)
    {
        SimpleJOGLViewport viewport = new SimpleJOGLViewport();
        MetaDataScene scene = scenes.get(id);

        RenderingEngine renderingEngine = null;
        String preferredRenderingEngine = (String) scene.getAttribute("preferredRenderingEngine");
        if (preferredRenderingEngine == null)
        {
            renderingEngine = new SimpleJOGLRenderingEngine();
        }
        else
        {
            try
            {
                renderingEngine = (RenderingEngine) Class.forName(preferredRenderingEngine).newInstance();
            }
            catch (Exception e)
            {
                renderingEngine = new SimpleJOGLRenderingEngine();
            }
        }
        viewport.setRenderingEngine(renderingEngine);
        renderingEngine.setScene(scene);

        Renderer renderer = null;
        String preferredRenderer = (String) scene.getAttribute("preferredRenderer");
        if (preferredRenderer == null)
        {
            renderer = new SimpleJOGLRenderer();
        }
        else
        {
            try
            {
                renderer = (Renderer) Class.forName(preferredRenderer).newInstance();
            }
            catch (Exception e)
            {
                renderer = new SimpleJOGLRenderer();
            }
        }
        renderingEngine.setRenderer(renderer);

        for (Camera camera : scene.getCameras())
        {
            String isDefault = (String) ((MetaDataCamera) camera).getAttribute("default");

            if (isDefault != null && isDefault.equals("true"))
            {
                renderingEngine.setCamera(camera);
                break;
            }

            renderingEngine.setCamera(scene.getCameras().get(0));
        }

        return (viewport);
    }
}
