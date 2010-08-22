/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.controller.outline;

import org.eclipse.swt.SWT;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Tree;
import org.eclipse.swt.widgets.TreeItem;
import org.eclipse.swt.widgets.Widget;

import com.se.simplicity.editor.controller.ViewPartController;
import com.se.simplicity.editor.model.scene.MetaData;
import com.se.simplicity.editor.model.scene.MetaDataNode;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.Light;
import com.se.simplicity.rendering.engine.RenderingEngine;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.SceneGraph;
import com.se.simplicity.scenegraph.SimpleTraversal;

public class OutlineController implements ViewPartController
{
    private RenderingEngine model;

    private Tree view;

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
    public void init(final Composite parent)
    {
        view.setParent(parent);

        update();
    }

    @Override
    public void setFocus()
    {}

    @Override
    public void setModel(final Object newModel)
    {
        this.model = (RenderingEngine) newModel;
    }

    @Override
    public void setView(final Object newView)
    {
        this.view = (Tree) newView;
    }

    @Override
    public void update()
    {
        view.removeAll();

        if (model.getScene() != null)
        {
            updateCameras();
            updateLights();
            updateSceneGraph();
        }
    }

    protected void updateCameras()
    {
        for (Camera camera : model.getScene().getCameras())
        {
            TreeItem treeItem = new TreeItem(view, SWT.NONE);
            treeItem.setText((String) ((MetaData) camera).getAttribute("name"));
        }
    }

    protected void updateLights()
    {
        for (Light light : model.getScene().getLights())
        {
            TreeItem treeItem = new TreeItem(view, SWT.NONE);
            treeItem.setText((String) ((MetaData) light).getAttribute("name"));
        }
    }

    protected void updateSceneGraph()
    {
        SceneGraph sceneGraph = model.getScene().getSceneGraph();

        if (sceneGraph != null)
        {
            SimpleTraversal traversal = new SimpleTraversal(sceneGraph.getRoot());
            Node parentNode = traversal.getNextNode();

            TreeItem parentItem = createTreeItem(view, parentNode);
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
