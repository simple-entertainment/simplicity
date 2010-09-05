/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.internal.util;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;

import org.apache.log4j.Logger;
import org.eclipse.jface.text.BadLocationException;
import org.eclipse.wst.sse.core.internal.provisional.text.IStructuredDocumentRegion;
import org.eclipse.wst.sse.core.internal.text.BasicStructuredDocument;

import com.se.simplicity.scene.Scene;
import com.se.simplicity.util.scene.SceneFactory;

/**
 * <p>
 * Synchronises between {@link com.se.simplicity.scene.Scene Scene}s and {@link org.eclipse.wst.sse.core.internal.text.BasicStructuredDocument
 * BasicStructuredDocument}s. <code>BasicStructuredDocument</code>s are used to store the serialised source representation for editing.
 * </p>
 * 
 * @author Gary Buyn
 */
@SuppressWarnings("restriction")
public class SceneDocumentSynchroniser
{
    /**
     * <p>
     * Retrieves the regions from the text of this <code>SourceSceneEditor</code> that contain XML tags.
     * </p>
     * 
     * @param document The document containing the regions from the text of this <code>SourceSceneEditor</code>.
     * 
     * @return The regions from the text of this <code>SourceSceneEditor</code> that contain XML tags.
     */
    protected IStructuredDocumentRegion[] getDocumentRegions(final BasicStructuredDocument document)
    {
        IStructuredDocumentRegion[] sourceRegions = document.getStructuredDocumentRegions();
        IStructuredDocumentRegion[] nonEmptySourceRegions = new IStructuredDocumentRegion[(sourceRegions.length / 2) + (sourceRegions.length % 2)];

        for (int index = 0; index < sourceRegions.length; index += 2)
        {
            nonEmptySourceRegions[index / 2] = sourceRegions[index];
        }

        return (nonEmptySourceRegions);
    }

    /**
     * <p>
     * Retrieves the XML tags from the updated serialised source representation as <code>String</code>s.
     * </p>
     * 
     * @param scene The {@link com.se.simplicity.scene.Scene Scene} produce an updated serialised source representation from.
     * 
     * @return The XML tags from the updated serialised source representation as <code>String</code>s.
     */
    protected String[] getSceneLines(final Scene scene)
    {
        ByteArrayOutputStream source = new ByteArrayOutputStream();
        SceneFactory.writeToSource(scene, source);

        String[] sceneLines = source.toString().replaceAll(">", ">\n").split("\n");

        return (sceneLines);
    }

    /**
     * <p>
     * Determines if the two given tags are the same.
     * </p>
     * 
     * @param tagA The first tag to check for equality.
     * @param tagB The second tag to check for equality.
     * 
     * @return True if the two given tags are the same, false otherwise.
     */
    protected boolean sameTag(final String tagA, final String tagB)
    {
        boolean sameTag = false;

        if (tagA.startsWith("<?") || tagA.startsWith("</") || tagA.matches("<[a-zA-Z]+>"))
        {
            if (tagA.equals(tagB))
            {
                sameTag = true;
            }
        }
        else if (tagA.matches("<[a-zA-Z]+ .*>"))
        {
            if (tagA.split(" ")[0].equals(tagB.split(" ")[0]))
            {
                sameTag = true;
            }
        }

        return (sameTag);
    }

    /**
     * <p>
     * Updates the given {@link org.eclipse.wst.sse.core.internal.text.BasicStructuredDocument BasicStructuredDocument} to match the given
     * {@link com.se.simplicity.scene.Scene Scene}.
     * </p>
     * 
     * @param scene The <code>Scene</code> to update the <code>BasicStructuredDocument</code> with.
     * @param document The <code>BasicStructuredDocument</code> to update.
     */
    public void synchroniseToDocument(final Scene scene, final BasicStructuredDocument document)
    {
        String[] sceneLines = getSceneLines(scene);
        IStructuredDocumentRegion[] documentRegions = getDocumentRegions(document);

        // For every XML tag in the updated serialised source representation.
        int documentRegionIndex = 0;
        for (int sceneLineIndex = 0; sceneLineIndex < sceneLines.length; sceneLineIndex++)
        {
            try
            {
                // If the end of the text of this SourceSceneEditor has been reached.
                if (documentRegionIndex >= documentRegions.length)
                {
                    // Add text in this SourceSceneEditor.
                    document.replace(document.length(), 0, sceneLines[sceneLineIndex]);
                }

                // If the end of the updated serialised source representation has been reached.
                else if (sceneLineIndex >= sceneLines.length)
                {
                    // Remove any remaining text in this SourceSceneEditor.
                    document.replace(documentRegions[documentRegionIndex].getStart(), document.length()
                            - documentRegions[documentRegionIndex].getStart(), "");
                    break;
                }

                // If the lines represent different tags.
                else if (!sameTag(sceneLines[sceneLineIndex], documentRegions[documentRegionIndex].getText()))
                {
                    // Insert the text into this SourceSceneEditor.
                    document.replace(documentRegions[documentRegionIndex].getStart(), 0, sceneLines[sceneLineIndex] + "\n");
                    documentRegionIndex--;
                }

                // If the lines represent the same tags but their contents does not match.
                else if (!sceneLines[sceneLineIndex].replaceAll("\\s", "").equals(
                        documentRegions[documentRegionIndex].getText().replaceAll("\\s", "")))
                {
                    // Replace the text in this SourceSceneEditor.
                    document.replace(documentRegions[documentRegionIndex].getStart(), documentRegions[documentRegionIndex].getLength(),
                            sceneLines[sceneLineIndex]);
                }

                documentRegionIndex++;
            }
            catch (BadLocationException e)
            {
                Logger.getLogger(getClass()).error("Failed to update Source.", e);
            }
        }
    }

    /**
     * <p>
     * Updates the given {@link com.se.simplicity.scene.Scene Scene} to match the given
     * {@link org.eclipse.wst.sse.core.internal.text.BasicStructuredDocument BasicStructuredDocument}.
     * </p>
     * 
     * @param document The <code>BasicStructuredDocument</code> to update the <code>Scene</code> with.
     * @param scene The <code>Scene</code> to update.
     */
    public void synchroniseToScene(final BasicStructuredDocument document, final Scene scene)
    {
        SceneFactory.updateFromSource(scene, new ByteArrayInputStream(document.getText().getBytes()));
    }
}
