/*******************************************************************************
 * Copyright (c) 2006 IBM Corporation and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     IBM Corporation - initial API and implementation
 *******************************************************************************/
package com.se.simplicity.editor.ui.perspectives;

import org.eclipse.ui.IFolderLayout;
import org.eclipse.ui.IPageLayout;
import org.eclipse.ui.IPerspectiveFactory;

/**
 * This class is meant to serve as an example for how various contributions are made to a perspective. Note that some of the extension point id's are
 * referred to as API constants while others are hardcoded and may be subject to change.
 */
public class EditorPerspective implements IPerspectiveFactory
{
    /**
     * <p>
     * The percentage of the page width to cover with the <code>SceneOutlineView</code>.
     * </p>
     */
    private static final float OUTLINE_PERCENTAGE = 0.75f;

    /**
     * <p>
     * The percentage of the page width to cover with the Project Explorer view.
     * </p>
     */
    private static final float PROJECT_EXPLORER_PERCENTAGE = 0.2f;

    /**
     * <p>
     * The percentage of the page width to cover with the <code>SceneComponentView</code>.
     * </p>
     */
    private static final float PROP_SHEET_PERCENTAGE = 0.5f;

    /**
     * <p>
     * Creates an instance of <code>EditorPerspective</code>.
     * </p>
     */
    public EditorPerspective()
    {
        super();
    }

    /**
     * <p>
     * Adds the eclipse views to this perspective.
     * </p>
     * 
     * @param factory The page layout.
     */
    protected void addViews(final IPageLayout factory)
    {
        IFolderLayout topLeft = factory.createFolder("topLeft", IPageLayout.LEFT, PROJECT_EXPLORER_PERCENTAGE, factory.getEditorArea());
        topLeft.addView(IPageLayout.ID_PROJECT_EXPLORER);

        IFolderLayout topRight = factory.createFolder("topRight", IPageLayout.RIGHT, OUTLINE_PERCENTAGE, factory.getEditorArea());
        topRight.addView(IPageLayout.ID_OUTLINE);

        IFolderLayout bottomRight = factory.createFolder("bottomRight", IPageLayout.BOTTOM, PROP_SHEET_PERCENTAGE, "topRight");
        bottomRight.addView(IPageLayout.ID_PROP_SHEET);
    }

    @Override
    public void createInitialLayout(final IPageLayout factory)
    {
        addViews(factory);
    }

}
