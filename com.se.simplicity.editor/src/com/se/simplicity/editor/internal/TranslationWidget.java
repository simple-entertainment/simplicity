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

    // TODO use these to determine type of translation.
    private ModelNode xCapsuleNode;
    private ModelNode yCapsuleNode;
    private ModelNode zCapsuleNode;
    private ModelNode freeSphereNode;

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
        xCapsuleNode = new SimpleModelNode();
        xCapsuleNode.getTransformation().rotate((float) (90.0f * Math.PI / 180.0f), new SimpleTranslationVectorf4(0.0f, 1.0f, 0.0f, 1.0f));
        xCapsuleNode.setModel(xCapsule);

        Capsule yCapsule = new Capsule();
        yCapsule.setColour(new SimpleRGBColourVectorf4(0.0f, 1.0f, 0.0f, 0.5f));
        yCapsule.setLength(0.5f);
        yCapsule.setRadius(0.05f);
        yCapsuleNode = new SimpleModelNode();
        yCapsuleNode.getTransformation().rotate((float) (90.0f * Math.PI / 180.0f), new SimpleTranslationVectorf4(1.0f, 0.0f, 0.0f, 1.0f));
        yCapsuleNode.setModel(yCapsule);

        Capsule zCapsule = new Capsule();
        zCapsule.setColour(new SimpleRGBColourVectorf4(0.0f, 0.0f, 1.0f, 0.5f));
        zCapsule.setLength(0.5f);
        zCapsule.setRadius(0.05f);
        zCapsuleNode = new SimpleModelNode();
        yCapsuleNode.getTransformation().rotate((float) Math.PI, new SimpleTranslationVectorf4(0.0f, 1.0f, 0.0f, 1.0f));
        zCapsuleNode.setModel(zCapsule);

        Sphere freeSphere = new Sphere();
        freeSphere.setColour(new SimpleRGBColourVectorf4(1.0f, 1.0f, 1.0f, 0.5f));
        freeSphere.setRadius(0.1f);
        freeSphereNode = new SimpleModelNode();
        freeSphereNode.setModel(freeSphere);

        fRoot.addChild(xCapsuleNode);
        fRoot.addChild(yCapsuleNode);
        fRoot.addChild(zCapsuleNode);
        fRoot.addChild(freeSphereNode);
    }

    @Override
    public void executeMove(final int x, final int y)
    {
        if (fSelectedSceneComponent instanceof Node)
        {
            ((Node) fSelectedSceneComponent).getTransformation().translate(new SimpleTranslationVectorf4(x * 0.01f, y * 0.01f, 0.0f, 1.0f));
        }

        fRoot.getTransformation().translate(new SimpleTranslationVectorf4(x * 0.01f, y * 0.01f, 0.0f, 1.0f));
    }

    @Override
    public Node getRootNode()
    {
        return (fRoot);
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
