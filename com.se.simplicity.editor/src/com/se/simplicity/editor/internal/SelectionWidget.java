package com.se.simplicity.editor.internal;

import static com.se.simplicity.model.ModelConstants.ITEMS_IN_CNV;

import com.se.simplicity.editor.internal.selection.SceneSelection;
import com.se.simplicity.model.ArrayVG;
import com.se.simplicity.model.Model;
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

    /**
     * <p>
     * Initialises the {@link com.se.simplicity.model.Model Model} for this <code>Widget</code>.
     * </p>
     */
    protected void initModel()
    {
        ArrayVG selectionModel = new ArrayVG();

        selectionModel.setColours(new float[] {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
                0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f});
        selectionModel.setNormals(new float[] {0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
                1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f});
        selectionModel.setVertices(new float[] {-0.015f, 0.007f, 0.0f, 0.015f, -0.007f, 0.0f, -0.007f, 0.015f, 0.0f, -0.015f, 0.007f, 0.0f, 0.007f,
                -0.015f, 0.0f, 0.015f, -0.007f, 0.0f, 0.015f, 0.007f, 0.0f, 0.007f, 0.015f, 0.0f, -0.015f, -0.007f, 0.0f, 0.015f, 0.007f, 0.0f,
                -0.015f, -0.007f, 0.0f, -0.007f, -0.015f, 0.0f});

        fRoot.setModel(selectionModel);
    }

    /**
     * <p>
     * Sets the colour of the widget based on whether the given {@link com.se.simplicity.model.Model Model} is the selected scene component.
     * </p>
     * 
     * @param model The <code>Model</code> to check against the selected scene component.
     */
    public void initColours(final Model model)
    {
        if (!fSelection.isEmpty() && fSelection.getSceneComponent() instanceof ModelNode)
        {
            if (model == ((ModelNode) fSelection.getSceneComponent()).getModel())
            {
                float[] colours = ((ArrayVG) fRoot.getModel()).getColours();
                for (int index = 0; index < colours.length; index += ITEMS_IN_CNV)
                {
                    colours[index] = 0.0f;
                    colours[index + 1] = 1.0f;
                    colours[index + 2] = 1.0f;
                }
            }
        }
    }

    @Override
    public void setSelectedWidgetNode(final ModelNode selectedWidgetNode)
    {}

    @Override
    public void setSelection(final SceneSelection selection)
    {
        fSelection = selection;
    }

    @Override
    public void updateView(final Camera camera, final TransformationMatrixf sceneTransformation, final Model model)
    {
        // Transform the Widget to the orientation of the camera.
        fRoot.setTransformation(camera.getNode().getAbsoluteTransformation());

        // Transform the Widget to the position of the selected scene component.
        fRoot.getTransformation().setTranslation(sceneTransformation.getTranslation());

        // Determine the distance between the Camera and the Widget.
        TransformationMatrixf cameraTransformation = camera.getNode().getAbsoluteTransformation();
        Vectorf vectorCameraToWidget = cameraTransformation.getTranslation().subtractRightCopy(fRoot.getAbsoluteTransformation().getTranslation());
        float distanceCameraToWidget = Math.abs(vectorCameraToWidget.getLength());

        initModel();
        initColours(model);

        // Scale the Widget based on the distance.
        ArrayVG selectionModel = (ArrayVG) fRoot.getModel();

        float[] vertices = selectionModel.getVertices();
        for (int index = 0; index < vertices.length; index++)
        {
            vertices[index] *= distanceCameraToWidget;
        }
    }
}
