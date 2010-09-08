package com.se.simplicity.editor.internal;

import com.se.simplicity.model.shape.Shape;
import com.se.simplicity.model.shape.Sphere;
import com.se.simplicity.model.shape.Torus;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.SimpleNode;
import com.se.simplicity.scenegraph.model.ModelNode;
import com.se.simplicity.scenegraph.model.SimpleModelNode;
import com.se.simplicity.vector.SimpleRGBColourVectorf4;
import com.se.simplicity.vector.SimpleTranslationVectorf4;

/**
 * <p>
 * A widget that manipulates the rotation of the currently selected scene component.
 * </p>
 * 
 * @author Gary Buyn
 */
public class RotationWidget implements Widget
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

    /**
     * <p>
     * Creates an instance of <code>RotationWidget</code>.
     * </p>
     */
    public RotationWidget()
    {
        fRoot = new SimpleNode();

        Torus xTorus = new Torus();
        xTorus.setColour(new SimpleRGBColourVectorf4(1.0f, 0.0f, 0.0f, 0.5f));
        xTorus.setInnerRadius(0.05f);
        xTorus.setOuterRadius(0.5f);
        SimpleModelNode xTorusNode = new SimpleModelNode();
        xTorusNode.getTransformation().rotate((float) (90.0f * Math.PI / 180.0f), new SimpleTranslationVectorf4(0.0f, 1.0f, 0.0f, 1.0f));
        xTorusNode.setModel(xTorus);

        Torus yTorus = new Torus();
        yTorus.setColour(new SimpleRGBColourVectorf4(0.0f, 1.0f, 0.0f, 0.5f));
        yTorus.setInnerRadius(0.05f);
        yTorus.setOuterRadius(0.5f);
        SimpleModelNode yTorusNode = new SimpleModelNode();
        yTorusNode.getTransformation().rotate((float) (90.0f * Math.PI / 180.0f), new SimpleTranslationVectorf4(1.0f, 0.0f, 0.0f, 1.0f));
        yTorusNode.setModel(yTorus);

        Torus zTorus = new Torus();
        zTorus.setColour(new SimpleRGBColourVectorf4(0.0f, 0.0f, 1.0f, 0.5f));
        zTorus.setInnerRadius(0.05f);
        zTorus.setOuterRadius(0.5f);
        SimpleModelNode zTorusNode = new SimpleModelNode();
        zTorusNode.setModel(zTorus);

        Sphere freeSphere = new Sphere();
        freeSphere.setColour(new SimpleRGBColourVectorf4(1.0f, 1.0f, 1.0f, 0.5f));
        freeSphere.setRadius(0.1f);

        SimpleModelNode freeSphereNode0 = new SimpleModelNode();
        freeSphereNode0.getTransformation().setXAxisTranslation(0.5f);
        freeSphereNode0.setModel(freeSphere);

        SimpleModelNode freeSphereNode1 = new SimpleModelNode();
        freeSphereNode1.getTransformation().setXAxisTranslation(-0.5f);
        freeSphereNode1.setModel(freeSphere);

        SimpleModelNode freeSphereNode2 = new SimpleModelNode();
        freeSphereNode2.getTransformation().setYAxisTranslation(0.5f);
        freeSphereNode2.setModel(freeSphere);

        SimpleModelNode freeSphereNode3 = new SimpleModelNode();
        freeSphereNode3.getTransformation().setYAxisTranslation(-0.5f);
        freeSphereNode3.setModel(freeSphere);

        SimpleModelNode freeSphereNode4 = new SimpleModelNode();
        freeSphereNode4.getTransformation().setZAxisTranslation(0.5f);
        freeSphereNode4.setModel(freeSphere);

        SimpleModelNode freeSphereNode5 = new SimpleModelNode();
        freeSphereNode5.getTransformation().setZAxisTranslation(-0.5f);
        freeSphereNode5.setModel(freeSphere);

        fRoot.addChild(xTorusNode);
        fRoot.addChild(yTorusNode);
        fRoot.addChild(zTorusNode);
        fRoot.addChild(freeSphereNode0);
        fRoot.addChild(freeSphereNode1);
        fRoot.addChild(freeSphereNode2);
        fRoot.addChild(freeSphereNode3);
        fRoot.addChild(freeSphereNode4);
        fRoot.addChild(freeSphereNode5);
    }

    @Override
    public void executeMove(final int x, final int y)
    {
        ((Node) fSelectedSceneComponent).getTransformation().rotate((float) Math.toRadians(x), new SimpleTranslationVectorf4(0.0f, 1.0f, 0.0f, 1.0f));
        ((Node) fSelectedSceneComponent).getTransformation().rotate((float) Math.toRadians(y), new SimpleTranslationVectorf4(1.0f, 0.0f, 0.0f, 1.0f));

        fRoot.getTransformation().rotate((float) Math.toRadians(x), new SimpleTranslationVectorf4(0.0f, 1.0f, 0.0f, 1.0f));
        fRoot.getTransformation().rotate((float) Math.toRadians(y), new SimpleTranslationVectorf4(1.0f, 0.0f, 0.0f, 1.0f));
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
