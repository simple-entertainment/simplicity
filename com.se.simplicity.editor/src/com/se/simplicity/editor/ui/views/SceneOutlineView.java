/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.ui.views;

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
import com.se.simplicity.util.metadata.scenegraph.MetaDataNode;

/**
 * <p>
 * An eclipse view that displays a tree outline of the contents of the <code>Scene</code> displayed in the active editor (if there is one).
 * </p>
 * 
 * @author Gary Buyn
 */
public class SceneOutlineView extends ViewPart implements SceneChangedListener
{
    /**
     * <p>
     * The tree outline of the contents of the <code>Scene</code> displayed in the active editor (if there is one).
     * </p>
     */
    private Tree tree;

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
        tree = new Tree(parent, SWT.NONE);

        Scene scene = SceneManager.getSceneManager().getActiveScene();
        if (scene != null)
        {
            update(scene);
        }
    }

    /**
     * <p>
     * Creates a <code>TreeItem</code> for the given parent and <code>Node</code>.
     * </p>
     * 
     * @param parent The parent of the <code>TreeItem</code> to be created.
     * @param node The <code>Node</code> the <code>TreeItem</code> represents.
     * 
     * @return A <code>TreeItem</code> for the given parent and <code>Node</code>.
     */
    protected TreeItem createTreeItem(final Widget parent, final Node node)
    {
        TreeItem treeItem;
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
            treeItem.setText("Node" + node.getID());
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
        return (tree);
    }

    @Override
    public void sceneChanged(final SceneChangedEvent event)
    {
        Scene scene = event.getScene();

        if (event.getType() == SceneChangedEventType.ACTIVATED)
        {
            tree.removeAll();
        }

        update(scene);
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
        for (Camera camera : scene.getCameras())
        {
            TreeItem treeItem = new TreeItem(tree, SWT.NONE);
            treeItem.setText((String) ((MetaData) camera).getAttribute("name"));
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
        for (Light light : scene.getLights())
        {
            TreeItem treeItem = new TreeItem(tree, SWT.NONE);
            treeItem.setText((String) ((MetaData) light).getAttribute("name"));
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
            SimpleTraversal traversal = new SimpleTraversal(sceneGraph.getRoot());
            Node parentNode = traversal.getNextNode();

            TreeItem parentItem = createTreeItem(tree, parentNode);
            TreeItem currentItem = parentItem;

            while (traversal.hasMoreNodes())
            {
                int backtracks = traversal.getBacktracksToNextNode();
                Node currentNode = traversal.getNextNode();

                if (parentNode != currentNode.getParent())
                {
                    parentNode = currentNode.getParent();
                    parentItem = currentItem;

                    if (backtracks > 0)
                    {
                        for (int index = 0; index < backtracks; index++)
                        {
                            parentItem = parentItem.getParentItem();
                        }
                    }
                }

                currentItem = createTreeItem(parentItem, currentNode);
            }
        }
    }
}
