package com.se.simplicity.editor.internal;

import com.se.simplicity.model.ArrayVG;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.model.ModelNode;
import com.se.simplicity.scenegraph.model.SimpleModelNode;
import com.se.simplicity.vector.ArrayBackedObjectf;
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
     * The currently selected scene component.
     * </p>
     */
    private Object fSelectedSceneComponent;

    /**
     * <p>
     * Creates an instance of <code>TranslationWidget</code>.
     * </p>
     */
    public SelectionWidget()
    {
        fRoot = new SimpleModelNode();
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
    public Object getSelectedSceneComponent()
    {
        return (fSelectedSceneComponent);
    }

    @Override
    public ModelNode getSelectedWidgetNode()
    {
        return (fRoot);
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

    @Override
    public void setSelectedSceneComponent(final Object selectedSceneComponent)
    {
        fSelectedSceneComponent = selectedSceneComponent;
    }

    @Override
    public void setSelectedWidgetNode(final ModelNode selectedWidgetNode)
    {}

    @Override
    public void updateView(final Camera camera)
    {
        // Transform the Widget to the orientation of the camera.
        float[] cameraArray = ((ArrayBackedObjectf) camera.getNode().getParent().getTransformation()).getArrayCopy();
        ((ArrayBackedObjectf) fRoot.getTransformation()).setArray(cameraArray);

        // Transform the Widget to the position of the selected scene component.
        if (fSelectedSceneComponent != null)
        {
            if (fSelectedSceneComponent instanceof Node)
            {
                fRoot.getTransformation().setTranslation(((Node) fSelectedSceneComponent).getAbsoluteTransformation().getTranslation());
            }
        }

        // Determine the distance between the Camera and the Widget.
        TransformationMatrixf cameraTransformation = camera.getNode().getAbsoluteTransformation();
        Vectorf vectorCameraToWidget = cameraTransformation.getTranslation().subtractRightCopy(fRoot.getAbsoluteTransformation().getTranslation());
        float distanceCameraToWidget = Math.abs(vectorCameraToWidget.getLength());

        // Scale the Widget based on the distance.
        initModel();
        ArrayVG selectionModel = (ArrayVG) fRoot.getModel();

        float[] vertices = selectionModel.getVertices();
        for (int index = 0; index < vertices.length; index++)
        {
            vertices[index] *= distanceCameraToWidget;
        }
    }
}
