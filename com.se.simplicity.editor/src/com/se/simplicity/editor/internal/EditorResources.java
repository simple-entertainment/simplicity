package com.se.simplicity.editor.internal;

import java.net.MalformedURLException;
import java.net.URL;

import org.apache.log4j.Logger;
import org.eclipse.jface.resource.ImageDescriptor;
import org.eclipse.jface.resource.ImageRegistry;

/**
 * <p>
 * Provides resources required by different elements of the editor.
 * </p>
 * 
 * @author Gary Buyn
 */
public final class EditorResources
{
    /**
     * <p>
     * The singleton instance of <code>SceneManager</code>.
     * </p>
     */
    private static EditorResources fEditorResources = new EditorResources();

    /**
     * <p>
     * Returns the singleton instance of <code>SceneManager</code>.
     * </p>
     * 
     * @return The singleton instance of <code>SceneManager</code>.
     */
    public static EditorResources getEditorResources()
    {
        return (fEditorResources);
    }

    /**
     * <p>
     * The image registry.
     * </p>
     */
    private ImageRegistry fImageRegistry;

    /**
     * <p>
     * Logs messages associated with this class.
     * </p>
     */
    private Logger fLogger;

    /**
     * <p>
     * Creates an instance of <code>SceneManager</code>. Hidden because only one instance of the <code>SceneManager</code> should exist.
     * </p>
     */
    private EditorResources()
    {
        fImageRegistry = new ImageRegistry();
        fLogger = Logger.getLogger(getClass().getName());

        try
        {
            fImageRegistry.put("sceneComponentEmpty", ImageDescriptor.createFromURL(new URL(
                    "file:///home/simple/workspace/com.se.simplicity.editor/images/Simple Eddy (Small).gif")));
        }
        catch (MalformedURLException e)
        {
            fLogger.error("Failed to load image.", e);
        }
    }

    /**
     * <p>
     * Retrieves the image registry.
     * </p>
     * 
     * @return The image registry.
     */
    public ImageRegistry getImageRegistry()
    {
        return (fImageRegistry);
    }
}
