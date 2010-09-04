/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.ui.views;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

import org.eclipse.swt.SWT;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Tree;
import org.eclipse.swt.widgets.TreeItem;
import org.eclipse.swt.widgets.Widget;
import org.eclipse.ui.part.ViewPart;

import com.se.simplicity.editor.internal.SceneChangedEvent;
import com.se.simplicity.editor.internal.SceneChangedEventType;
import com.se.simplicity.editor.internal.SceneChangedListener;
import com.se.simplicity.editor.internal.SceneManager;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.Light;
import com.se.simplicity.scene.Scene;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.SceneGraph;
import com.se.simplicity.scenegraph.SimpleTraversal;
import com.se.simplicity.util.metadata.MetaData;
import com.se.simplicity.util.metadata.rendering.MetaDataCamera;
import com.se.simplicity.util.metadata.rendering.MetaDataLight;
import com.se.simplicity.util.metadata.scenegraph.MetaDataNode;

/**
 * <p>
 * An eclipse view that displays a tree outline of the contents of the currently active <code>Scene</code> (if there is one).
 * </p>
 * 
 * @author Gary Buyn
 */
public class SceneOutlineView extends ViewPart implements SceneChangedListener
{
    /**
     * <p>
     * A map from <code>TreeItem</code> to scene components. Used for sending notifications of changes in active scene components.
     * </p>
     */
    private Map<TreeItem, Object> fSceneComponents;

    /**
     * <p>
     * Listens for selection events on a tree outline of the contents of the <code>Scene</code>.
     * </p>
     */
    private SceneOutlineSelectionListener fSceneOutlineSelectionListener;

    /**
     * <p>
     * The tree outline of the contents of the <code>Scene</code> displayed in the active editor (if there is one).
     * </p>
     */
    private Tree fTree;

    /**
     * <p>
     * A map from scene components to <code>TreeItem</code>. Used for receiving notifications of changes in active scene components.
     * </p>
     */
    private Map<Object, TreeItem> fTreeItems;

    /**
     * <p>
     * Creates an instance of <code>SceneOutlineView</code>.
     * </p>
     */
    public SceneOutlineView()
    {
        super();

        SceneManager.getSceneManager().addSceneChangedListener(this);
    }

    @Override
    public void createPartControl(final Composite parent)
    {
        fSceneComponents = new HashMap<TreeItem, Object>();
        fTree = new Tree(parent, SWT.NONE);
        fTreeItems = new HashMap<Object, TreeItem>();

        fSceneOutlineSelectionListener = new SceneOutlineSelectionListener(fSceneComponents);
        fTree.addSelectionListener(fSceneOutlineSelectionListener);

        Scene scene = SceneManager.getSceneManager().getActiveScene();
        if (scene != null)
        {
            update(scene);
        }
    }

    /**
     * <p>
     * Retrieves the <code>TreeItem</code> for the given parent and <code>Node</code> (or creates a new one if it does not exist).
     * </p>
     * 
     * @param parent The parent of the <code>TreeItem</code> to be created.
     * @param node The <code>Node</code> the <code>TreeItem</code> represents.
     * 
     * @return A <code>TreeItem</code> for the given parent and <code>Node</code>.
     */
    protected TreeItem getTreeItem(final Widget parent, final Node node)
    {
        TreeItem treeItem = fTreeItems.get(node);

        if (treeItem == null)
        {
            if (parent instanceof Tree)
            {
                treeItem = new TreeItem((Tree) parent, SWT.NONE);
            }
            else
            {
                treeItem = new TreeItem((TreeItem) parent, SWT.NONE);
            }

            if (node instanceof MetaDataNode)
            {
                treeItem.setText((String) ((MetaDataNode) node).getAttribute("name"));
            }
            else
            {
                treeItem.setText(MetaDataNode.getDefaultName(node));
            }

            fSceneComponents.put(treeItem, node);
            fTreeItems.put(node, treeItem);
        }

        return (treeItem);
    }

    @Override
    public void dispose()
    {
        SceneManager.getSceneManager().removeSceneChangedListener(this);

        super.dispose();
    }

    /**
     * <p>
     * Retrieves the tree outline of the contents of the <code>Scene</code> displayed in the active editor (if there is one).
     * </p>
     * 
     * @return The tree outline of the contents of the <code>Scene</code> displayed in the active editor (if there is one).
     */
    public Tree getTree()
    {
        return (fTree);
    }

    @Override
    public void sceneChanged(final SceneChangedEvent event)
    {
        Scene scene = event.getScene();

        if (event.getType() == SceneChangedEventType.CAMERA_ACTIVATED)
        {
            selectTreeItem(event.getSceneComponent());
        }
        else if (event.getType() == SceneChangedEventType.CAMERA_MODIFIED)
        {
            if (event.getSceneComponent() instanceof MetaDataCamera)
            {
                MetaDataCamera camera = (MetaDataCamera) event.getSceneComponent();
                TreeItem treeItem = fTreeItems.get(event.getSceneComponent());
                treeItem.setText((String) camera.getAttribute("name"));
            }
        }
        else if (event.getType() == SceneChangedEventType.LIGHT_ACTIVATED)
        {
            selectTreeItem(event.getSceneComponent());
        }
        else if (event.getType() == SceneChangedEventType.LIGHT_MODIFIED)
        {
            if (event.getSceneComponent() instanceof MetaDataLight)
            {
                MetaDataLight light = (MetaDataLight) event.getSceneComponent();
                TreeItem treeItem = fTreeItems.get(event.getSceneComponent());
                treeItem.setText((String) light.getAttribute("name"));
            }
        }
        else if (event.getType() == SceneChangedEventType.NODE_ACTIVATED)
        {
            selectTreeItem(event.getSceneComponent());
        }
        else if (event.getType() == SceneChangedEventType.NODE_MODIFIED)
        {
            if (event.getSceneComponent() instanceof MetaDataNode)
            {
                MetaDataNode node = (MetaDataNode) event.getSceneComponent();
                TreeItem treeItem = fTreeItems.get(event.getSceneComponent());
                treeItem.setText((String) node.getAttribute("name"));
            }
        }
        else if (event.getType() == SceneChangedEventType.SCENE_ACTIVATED)
        {
            fTree.removeAll();
            fSceneComponents.clear();
            fTreeItems.clear();

            update(scene);
        }
        else if (event.getType() == SceneChangedEventType.SCENE_MODIFIED)
        {
            update(scene);
        }
    }

    /**
     * <p>
     * Selects a <code>TreeItem</code> depending on the given scene component (or deselects all <code>TreeItem</code> if no scene component is given).
     * </p>
     * 
     * @param sceneComponent The scene component to select a <code>TreeItem</code> for, or null.
     */
    protected void selectTreeItem(final Object sceneComponent)
    {
        fSceneOutlineSelectionListener.disable();

        if (sceneComponent == null)
        {
            fTree.deselectAll();
        }
        else
        {
            fTree.setSelection(fTreeItems.get(sceneComponent));
        }

        fSceneOutlineSelectionListener.enable();
    }

    @Override
    public void setFocus()
    {}

    /**
     * <p>
     * Updates the contents of the tree outline to reflect the given <code>Scene</code>.
     * </p>
     * 
     * @param scene The <code>Scene</code> the contents of the tree outline will be updated to reflect.
     */
    public void update(final Scene scene)
    {
        if (scene != null)
        {
            updateCameras(scene);
            updateLights(scene);
            updateSceneGraph(scene);
        }
    }

    /**
     * <p>
     * Updates the <code>Camera</code> contents of the tree outline to reflect the given <code>Scene</code>.
     * </p>
     * 
     * @param scene The <code>Scene</code> the <code>Camera</code> contents of the tree outline will be updated to reflect.
     */
    protected void updateCameras(final Scene scene)
    {
        // Remove Tree Items for Cameras not in Scene.
        Iterator<TreeItem> sceneComponentKeys = fSceneComponents.keySet().iterator();
        while (sceneComponentKeys.hasNext())
        {
            TreeItem treeItem = sceneComponentKeys.next();

            if (fSceneComponents.get(treeItem) instanceof Camera && !scene.getCameras().contains(fSceneComponents.get(treeItem)))
            {
                sceneComponentKeys.remove();
                fTreeItems.remove(scene);
                treeItem.dispose();
            }
        }

        // Insert Tree Items for Cameras in Scene.
        for (Camera camera : scene.getCameras())
        {
            if (fTreeItems.get(camera) == null)
            {
                TreeItem treeItem = new TreeItem(fTree, SWT.NONE);
                treeItem.setText((String) ((MetaData) camera).getAttribute("name"));

                fSceneComponents.put(treeItem, camera);
                fTreeItems.put(camera, treeItem);
            }
        }
    }

    /**
     * <p>
     * Updates the <code>Light</code> contents of the tree outline to reflect the given <code>Scene</code>.
     * </p>
     * 
     * @param scene The <code>Scene</code> the <code>Light</code> contents of the tree outline will be updated to reflect.
     */
    protected void updateLights(final Scene scene)
    {
        // Remove Tree Items for Lights not in Scene.
        Iterator<TreeItem> sceneComponentKeys = fSceneComponents.keySet().iterator();
        while (sceneComponentKeys.hasNext())
        {
            TreeItem treeItem = sceneComponentKeys.next();

            if (fSceneComponents.get(treeItem) instanceof Light && !scene.getLights().contains(fSceneComponents.get(treeItem)))
            {
                sceneComponentKeys.remove();
                fTreeItems.remove(scene);
                treeItem.dispose();
            }
        }

        // Insert Tree Items for Lights in Scene.
        for (Light light : scene.getLights())
        {
            if (fTreeItems.get(light) == null)
            {
                TreeItem treeItem = new TreeItem(fTree, SWT.NONE);
                treeItem.setText((String) ((MetaData) light).getAttribute("name"));

                fSceneComponents.put(treeItem, light);
                fTreeItems.put(light, treeItem);
            }
        }
    }

    /**
     * <p>
     * Updates the <code>SceneGraph</code> contents of the tree outline to reflect the given <code>Scene</code>.
     * </p>
     * 
     * @param scene The <code>Scene</code> the <code>SceneGraph</code> contents of the tree outline will be updated to reflect.
     */
    protected void updateSceneGraph(final Scene scene)
    {
        SceneGraph sceneGraph = scene.getSceneGraph();

        if (sceneGraph != null)
        {
            // Insert / Update Nodes in Scene.
            SimpleTraversal traversal = new SimpleTraversal(sceneGraph.getRoot());
            ArrayList<TreeItem> treeItemsInUse = new ArrayList<TreeItem>();

            Node parentNode = traversal.getNextNode();
            TreeItem parentItem = getTreeItem(fTree, parentNode);
            TreeItem currentItem = parentItem;
            treeItemsInUse.add(currentItem);

            while (traversal.hasMoreNodes())
            {
                int backtracks = traversal.getBacktracksToNextNode();
                Node currentNode = traversal.getNextNode();

                if (parentNode != currentNode.getParent())
                {
                    parentNode = currentNode.getParent();
                    parentItem = currentItem;

                    for (int index = 0; index < backtracks; index++)
                    {
                        parentItem = parentItem.getParentItem();
                    }
                }

                currentItem = getTreeItem(parentItem, currentNode);
                treeItemsInUse.add(currentItem);
            }

            // Remove Nodes not in Scene.
            Iterator<TreeItem> sceneComponentKeys = fSceneComponents.keySet().iterator();
            while (sceneComponentKeys.hasNext())
            {
                TreeItem treeItem = sceneComponentKeys.next();

                if (fSceneComponents.get(treeItem) instanceof Node && !treeItemsInUse.contains(treeItem))
                {
                    sceneComponentKeys.remove();
                    fTreeItems.remove(scene);
                    treeItem.dispose();
                }
            }
        }
    }
}
