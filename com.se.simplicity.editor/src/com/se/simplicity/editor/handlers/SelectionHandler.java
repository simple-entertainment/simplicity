package com.se.simplicity.editor.handlers;

import org.apache.log4j.Logger;
import org.eclipse.core.commands.AbstractHandler;
import org.eclipse.core.commands.ExecutionEvent;
import org.eclipse.core.commands.ExecutionException;
import org.eclipse.swt.widgets.Event;
import org.eclipse.ui.IEditorPart;
import org.eclipse.ui.IViewPart;
import org.eclipse.ui.IWorkbenchPage;
import org.eclipse.ui.handlers.HandlerUtil;

import com.se.simplicity.editor.internal.event.SceneChangedEvent;
import com.se.simplicity.editor.internal.event.SceneChangedEventType;
import com.se.simplicity.editor.ui.editors.SceneEditor;
import com.se.simplicity.editor.ui.views.SceneComponentView;
import com.se.simplicity.editor.ui.views.SceneOutlineView;
import com.se.simplicity.scenegraph.Node;

/**
 * <p>
 * Sets the currently selected scene component in the active editor.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SelectionHandler extends AbstractHandler
{
    /**
     * Creates an instance of <code>SelectionHandler</code>.
     */
    public SelectionHandler()
    {}

    @Override
    public Object execute(final ExecutionEvent event) throws ExecutionException
    {
        // Check that the correct editor is active.
        IEditorPart editor = HandlerUtil.getActiveEditor(event);
        if (!(editor instanceof SceneEditor))
        {
            Logger.getLogger(getClass()).error("This handler can only be executed when a Scene Editor is active.");
            throw new ExecutionException("This handler can only be executed when a Scene Editor is active.");
        }

        Event triggerEvent = (Event) event.getTrigger();
        Object selectedSceneComponent = triggerEvent.data;

        // Check that this handler has not been executed as a result of a Widget pick with no hits. If this is a case it will be followed by an
        // execution as a result of a Scene pick at the same location. The selected scene component should only be set to null if the Scene pick has
        // no hits.
        if (triggerEvent.type == 1 && selectedSceneComponent == null)
        {
            return (null);
        }

        // Update UI elements to reflect the change in Selection.
        updatePartStates(event, (Node) selectedSceneComponent);

        return (null);
    }

    /**
     * <p>
     * Updates any parts displaying the currently selected scene component.
     * </p>
     * 
     * @param event The {@link org.eclipse.core.commands.ExecutionEvent ExecutionEvent} being responded to.
     * @param node The currently selected {@link com.se.simplicity.scenegraph.Node Node}.
     */
    protected void updatePartStates(final ExecutionEvent event, final Node node)
    {
        IWorkbenchPage page = HandlerUtil.getActiveWorkbenchWindow(event).getActivePage();

        IViewPart outlineView = page.findView("com.se.simplicity.editor.ui.views.SceneOutlineView");
        if (outlineView != null)
        {
            SceneChangedEvent sceneEvent = new SceneChangedEvent(null, node, SceneChangedEventType.NODE_ACTIVATED);
            ((SceneOutlineView) outlineView).sceneChanged(sceneEvent);
        }

        IViewPart sceneComponentView = page.findView("com.se.simplicity.editor.ui.views.SceneComponentView");
        if (outlineView != null)
        {
            SceneChangedEvent sceneEvent = new SceneChangedEvent(null, node, SceneChangedEventType.NODE_ACTIVATED);
            ((SceneComponentView) sceneComponentView).sceneChanged(sceneEvent);
        }

        ((SceneEditor) page.getActiveEditor()).setSelectedSceneComponent(node);
    }
}
