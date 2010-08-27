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
import org.eclipse.ui.IEditorPart;
import org.eclipse.ui.IFileEditorInput;
import org.eclipse.ui.part.ViewPart;

import com.se.simplicity.editor.internal.SceneManager;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.Light;
import com.se.simplicity.scene.Scene;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.SceneGraph;
import com.se.simplicity.scenegraph.SimpleTraversal;
import com.se.simplicity.util.metadata.MetaData;
import com.se.simplicity.util.metadata.scenegraph.MetaDataNode;

public class SceneOutlineView extends ViewPart
{
    private Tree tree;

    @Override
    public void createPartControl(final Composite parent)
    {
        tree = new Tree(parent, SWT.NONE);
    }

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
    public void setFocus()
    {}

    public void update()
    {
        IEditorPart activeEditor = getViewSite().getPage().getActiveEditor();
        String sceneId = ((IFileEditorInput) activeEditor.getEditorInput()).getFile().getFullPath().toString();
        Scene model = SceneManager.getSceneManager().getScene(sceneId);

        tree.removeAll();

        if (model != null)
        {
            updateCameras(model);
            updateLights(model);
            updateSceneGraph(model);
        }
    }

    protected void updateCameras(Scene model)
    {
        for (Camera camera : model.getCameras())
        {
            TreeItem treeItem = new TreeItem(tree, SWT.NONE);
            treeItem.setText((String) ((MetaData) camera).getAttribute("name"));
        }
    }

    protected void updateLights(Scene model)
    {
        for (Light light : model.getLights())
        {
            TreeItem treeItem = new TreeItem(tree, SWT.NONE);
            treeItem.setText((String) ((MetaData) light).getAttribute("name"));
        }
    }

    protected void updateSceneGraph(Scene model)
    {
        SceneGraph sceneGraph = model.getSceneGraph();

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
