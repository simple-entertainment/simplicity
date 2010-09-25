package com.se.simplicity.editor.internal;

import com.se.simplicity.editor.internal.selection.SceneSelection;
import com.se.simplicity.model.ArrayVG;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.model.ModelNode;
import com.se.simplicity.scenegraph.model.SimpleModelNode;
import com.se.simplicity.vector.TransformationMatrixf;
import com.se.simplicity.vector.Vectorf;

/**
 * <p>
 * A widget that selects scene components.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SelectionWidget implements Widget
{
    /**
     * <p>
     * The root {@link com.se.simplicity.scenegraph.Node Node} of this widget.
     * </p>
     */
    private SimpleModelNode fRoot;

    /**
     * <p>
     * The selected scene component and primitive.
     * </p>
     */
    private SceneSelection fSelection;

    /**
     * <p>
     * Creates an instance of <code>TranslationWidget</code>.
     * </p>
     */
    public SelectionWidget()
    {
        fRoot = new SimpleModelNode();
        fSelection = new SceneSelection(null, null);
    }

    @Override
    public boolean alwaysFacesCamera()
    {
        return (true);
    }

    @Override
    public boolean atSelectionOnly()
    {
        return (false);
    }

    @Override
    public void executeMove(final int x, final int y)
    {}

    @Override
    public Node getRootNode()
    {
        return (fRoot);
    }

    @Override
    public ModelNode getSelectedWidgetNode()
    {
        return (fRoot);
    }

    @Override
    public SceneSelection getSelection()
    {
        return (fSelection);
    }

    @Override
    public void init(final Camera camera, final boolean isSelection)
    {
        // Determine the distance between the Camera and the Widget.
        TransformationMatrixf cameraTransformation = camera.getNode().getAbsoluteTransformation();
        Vectorf vectorCameraToWidget = cameraTransformation.getTranslation().subtractRightCopy(fRoot.getAbsoluteTransformation().getTranslation());
        float distanceCameraToWidget = Math.abs(vectorCameraToWidget.getLength());

        initModel(isSelection);

        // Scale the Widget based on the distance.
        ArrayVG selectionModel = (ArrayVG) fRoot.getModel();

        float[] vertices = selectionModel.getVertices();
        for (int index = 0; index < vertices.length; index++)
        {
            vertices[index] *= distanceCameraToWidget;
        }
    }

    /**
     * <p>
     * Initialises the {@link com.se.simplicity.model.Model Model} for this <code>Widget</code>.
     * </p>
     * 
     * @param isSelection Determines if the <code>Widget</code> is being rendered for the selected scene component / primitive.
     */
    protected void initModel(final boolean isSelection)
    {
        ArrayVG selectionModel = new ArrayVG();

        if (isSelection)
        {
            selectionModel.setColours(new float[] {0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f,
                    1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f});
        }
        else
        {
            selectionModel.setColours(new float[] {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
                    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f});
        }
        selectionModel.setNormals(new float[] {0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
                1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f});
        selectionModel.setVertices(new float[] {-0.015f, 0.007f, 0.0f, 0.015f, -0.007f, 0.0f, -0.007f, 0.015f, 0.0f, -0.015f, 0.007f, 0.0f, 0.007f,
                -0.015f, 0.0f, 0.015f, -0.007f, 0.0f, 0.015f, 0.007f, 0.0f, 0.007f, 0.015f, 0.0f, -0.015f, -0.007f, 0.0f, 0.015f, 0.007f, 0.0f,
                -0.015f, -0.007f, 0.0f, -0.007f, -0.015f, 0.0f});

        fRoot.setModel(selectionModel);
    }

    @Override
    public boolean isHittable()
    {
        return (false);
    }

    @Override
    public boolean isOutlined()
    {
        return (true);
    }

    @Override
    public void setSelectedWidgetNode(final ModelNode selectedWidgetNode)
    {}

    @Override
    public void setSelection(final SceneSelection selection)
    {
        fSelection = selection;
    }
}
