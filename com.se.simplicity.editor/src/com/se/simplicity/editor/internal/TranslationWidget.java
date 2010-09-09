package com.se.simplicity.editor.internal;

import com.se.simplicity.model.shape.Capsule;
import com.se.simplicity.model.shape.Shape;
import com.se.simplicity.model.shape.Sphere;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.SimpleNode;
import com.se.simplicity.scenegraph.model.ModelNode;
import com.se.simplicity.scenegraph.model.SimpleModelNode;
import com.se.simplicity.vector.SimpleRGBColourVectorf4;
import com.se.simplicity.vector.SimpleTranslationVectorf4;

/**
 * <p>
 * A widget that manipulates the translation of the currently selected scene component.
 * </p>
 * 
 * @author Gary Buyn
 */
public class TranslationWidget implements Widget
{
    /**
     * <p>
     * The {@link com.se.simplicity.rendering.Camera Camera} the widget will be viewing through (used to scale the widget correctly).
     * </p>
     */
    private Camera fCamera;

    /**
     * <p>
     * The {@link com.se.simplicity.scenegraph.model.ModelNode ModelNode} that free translation on the viewport's z plane when selected.
     * </p>
     */
    private ModelNode fFreeSphereNode;

    /**
     * <p>
     * The root {@link com.se.simplicity.scenegraph.Node Node} of this widget.
     * </p>
     */
    private Node fRoot;

    /**
     * <p>
     * The currently selected scene component.
     * </p>
     */
    private Object fSelectedSceneComponent;

    /**
     * <p>
     * The currently selected {@link com.se.simplicity.scenegraph.model.ModelNode ModelNode} of this widget.
     * </p>
     */
    private ModelNode fSelectedWidgetNode;

    /**
     * <p>
     * The {@link com.se.simplicity.scenegraph.model.ModelNode ModelNode} that causes translation on the x axis when selected.
     * </p>
     */
    private ModelNode fXCapsuleNode;

    /**
     * <p>
     * The {@link com.se.simplicity.scenegraph.model.ModelNode ModelNode} that causes translation on the y axis when selected.
     * </p>
     */
    private ModelNode fYCapsuleNode;

    /**
     * <p>
     * The {@link com.se.simplicity.scenegraph.model.ModelNode ModelNode} that causes translation on the z axis when selected.
     * </p>
     */
    private ModelNode fZCapsuleNode;

    /**
     * <p>
     * Creates an instance of <code>TranslationWidget</code>.
     * </p>
     */
    public TranslationWidget()
    {
        fRoot = new SimpleNode();

        Capsule xCapsule = new Capsule();
        xCapsule.setColour(new SimpleRGBColourVectorf4(1.0f, 0.0f, 0.0f, 0.5f));
        xCapsule.setLength(0.5f);
        xCapsule.setRadius(0.05f);
        fXCapsuleNode = new SimpleModelNode();
        fXCapsuleNode.getTransformation().rotate((float) (90.0f * Math.PI / 180.0f), new SimpleTranslationVectorf4(0.0f, 1.0f, 0.0f, 1.0f));
        fXCapsuleNode.setModel(xCapsule);

        Capsule yCapsule = new Capsule();
        yCapsule.setColour(new SimpleRGBColourVectorf4(0.0f, 1.0f, 0.0f, 0.5f));
        yCapsule.setLength(0.5f);
        yCapsule.setRadius(0.05f);
        fYCapsuleNode = new SimpleModelNode();
        fYCapsuleNode.getTransformation().rotate((float) (90.0f * Math.PI / 180.0f), new SimpleTranslationVectorf4(1.0f, 0.0f, 0.0f, 1.0f));
        fYCapsuleNode.setModel(yCapsule);

        Capsule zCapsule = new Capsule();
        zCapsule.setColour(new SimpleRGBColourVectorf4(0.0f, 0.0f, 1.0f, 0.5f));
        zCapsule.setLength(0.5f);
        zCapsule.setRadius(0.05f);
        fZCapsuleNode = new SimpleModelNode();
        fYCapsuleNode.getTransformation().rotate((float) Math.PI, new SimpleTranslationVectorf4(0.0f, 1.0f, 0.0f, 1.0f));
        fZCapsuleNode.setModel(zCapsule);

        Sphere freeSphere = new Sphere();
        freeSphere.setColour(new SimpleRGBColourVectorf4(1.0f, 1.0f, 1.0f, 0.5f));
        freeSphere.setRadius(0.1f);
        fFreeSphereNode = new SimpleModelNode();
        fFreeSphereNode.setModel(freeSphere);

        fRoot.addChild(fXCapsuleNode);
        fRoot.addChild(fYCapsuleNode);
        fRoot.addChild(fZCapsuleNode);
        fRoot.addChild(fFreeSphereNode);
    }

    @Override
    public void executeMove(final int x, final int y)
    {
        if (fSelectedSceneComponent instanceof Node)
        {
            int invertedY = y * -1;
            SimpleTranslationVectorf4 translation = new SimpleTranslationVectorf4();

            if (fSelectedWidgetNode == fXCapsuleNode)
            {
                translation.translateX((x + invertedY) * 0.01f);
            }
            else if (fSelectedWidgetNode == fYCapsuleNode)
            {
                translation.translateY((x + invertedY) * 0.01f);
            }
            else if (fSelectedWidgetNode == fZCapsuleNode)
            {
                translation.translateZ((x + invertedY) * 0.01f);
            }

            ((Node) fSelectedSceneComponent).getTransformation().translate(translation);
            fRoot.getTransformation().translate(translation);
        }
    }

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
        return (fSelectedWidgetNode);
    }

    @Override
    public void setCamera(final Camera camera)
    {
        fCamera = camera;
    }

    @Override
    public void setSelectedSceneComponent(final Object selectedSceneComponent)
    {
        fSelectedSceneComponent = selectedSceneComponent;
    }

    @Override
    public void setSelectedWidgetNode(final ModelNode selectedWidgetNode)
    {
        if (fSelectedWidgetNode != null)
        {
            ((SimpleRGBColourVectorf4) ((Shape) fSelectedWidgetNode.getModel()).getColour()).setAlpha(0.5f);
        }

        if (selectedWidgetNode != null)
        {
            ((SimpleRGBColourVectorf4) ((Shape) selectedWidgetNode.getModel()).getColour()).setAlpha(1.0f);
        }

        fSelectedWidgetNode = selectedWidgetNode;
    }
}
