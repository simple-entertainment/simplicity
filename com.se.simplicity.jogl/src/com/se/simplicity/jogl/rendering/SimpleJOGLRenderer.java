/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.jogl.rendering;

import static com.se.simplicity.model.ModelConstants.CNV_ITEMS_IN_FACE;
import static com.se.simplicity.model.ModelConstants.ITEMS_IN_CNV;
import static com.se.simplicity.model.ModelConstants.VERTICES_IN_A_FACE;

import javax.media.opengl.GL;
import javax.media.opengl.glu.GLU;

import com.se.simplicity.jogl.JOGLComponent;
import com.se.simplicity.model.ArrayVG;
import com.se.simplicity.model.IndexedArrayVG;
import com.se.simplicity.model.Model;
import com.se.simplicity.model.shapes.Capsule;
import com.se.simplicity.model.shapes.Cylinder;
import com.se.simplicity.model.shapes.Sphere;
import com.se.simplicity.model.shapes.Torus;
import com.se.simplicity.rendering.DrawingMode;
import com.se.simplicity.rendering.Renderer;
import com.se.simplicity.vector.SimpleTransformationMatrixf44;
import com.se.simplicity.vector.SimpleTranslationVectorf4;
import com.se.simplicity.vector.TranslationVectorf;
import com.sun.opengl.util.GLUT;

/**
 * <p>
 * Renders a {@link com.se.simplicity.model.Model Model} in a JOGL environment. This implementation uses only simple rendering techniques and
 * properties.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SimpleJOGLRenderer implements Renderer, JOGLComponent
{
    /**
     * <p>
     * The subdivisions to use when rendering GLU shapes.
     * </p>
     */
    private static final int GLU_SHAPE_SUBDIVISIONS = 10;

    /**
     * <p>
     * The drawing mode used to render the {@link com.se.simplicity.model.Model Model}s.
     * </p>
     */
    private DrawingMode fDrawingMode;
    /**
     * <p>
     * The JOGL rendering environment.
     * </p>
     */
    private GL fGl;

    /**
     * <p>
     * Creates an instance of <code>SimpleJOGLRenderer</code>.
     * </p>
     */
    public SimpleJOGLRenderer()
    {
        fDrawingMode = DrawingMode.FACES;
        fGl = null;
    }

    @Override
    public void dispose()
    {
        fGl.glPointSize(1.0f);
    }

    @Override
    public DrawingMode getDrawingMode()
    {
        return (fDrawingMode);
    }

    @Override
    public GL getGL()
    {
        return (fGl);
    }

    /**
     * <p>
     * Retrieves the JOGL drawing mode used to render the {@link com.se.simplicity.model.Model Model}.
     * </p>
     * 
     * @param drawingMode The <code>DrawingMode</code> to retrieve the JOGL drawing mode for.
     * 
     * @return The JOGL drawing mode used to render the <code>Model</code>.
     */
    protected int getJOGLDrawingMode(final DrawingMode drawingMode)
    {
        int joglDrawingMode = -1;

        if (drawingMode == DrawingMode.VERTICES)
        {
            joglDrawingMode = GL.GL_POINTS;
        }
        else if (drawingMode == DrawingMode.EDGES)
        {
            joglDrawingMode = GL.GL_LINE_LOOP;
        }
        else if (drawingMode == DrawingMode.FACES)
        {
            joglDrawingMode = GL.GL_TRIANGLES;
        }

        return (joglDrawingMode);
    }

    @Override
    public void init()
    {
        fGl.glPointSize(2.0f);
    }

    /**
     * <p>
     * Renders an <code>ArrayVG</code>.
     * </p>
     * 
     * @param vertexGroup The <code>ArrayVG</code> to render.
     */
    protected void renderArrayVG(final ArrayVG vertexGroup)
    {
        float[] colours = vertexGroup.getColours();
        float[] normals = vertexGroup.getNormals();
        float[] vertices = vertexGroup.getVertices();

        for (int faceIndex = 0; faceIndex < vertices.length / CNV_ITEMS_IN_FACE; faceIndex++)
        {
            fGl.glBegin(getJOGLDrawingMode(fDrawingMode));
            {
                for (int vertexIndex = 0; vertexIndex < CNV_ITEMS_IN_FACE; vertexIndex += ITEMS_IN_CNV)
                {
                    int vertex = faceIndex * CNV_ITEMS_IN_FACE + vertexIndex;

                    fGl.glColor3f(colours[vertex], colours[vertex + 1], colours[vertex + 2]);
                    fGl.glNormal3f(normals[vertex], normals[vertex + 1], normals[vertex + 2]);
                    fGl.glVertex3f(vertices[vertex], vertices[vertex + 1], vertices[vertex + 2]);
                }
            }
            fGl.glEnd();
        }
    }

    /**
     * <p>
     * Renders a <code>Capsule</code>.
     * </p>
     * 
     * @param capsule The <code>Capsule</code> to render.
     */
    protected void renderCapsule(final Capsule capsule)
    {
        fGl.glColor3f(capsule.getColour().getRed(), capsule.getColour().getGreen(), capsule.getColour().getBlue());

        GLU glu = new GLU();
        glu.gluCylinder(glu.gluNewQuadric(), capsule.getRadius(), capsule.getRadius(), capsule.getLength(), GLU_SHAPE_SUBDIVISIONS, 1);

        fGl.glPushMatrix();
        {
            glu.gluSphere(glu.gluNewQuadric(), capsule.getRadius(), GLU_SHAPE_SUBDIVISIONS, GLU_SHAPE_SUBDIVISIONS);

            SimpleTransformationMatrixf44 transformation = new SimpleTransformationMatrixf44();
            TranslationVectorf translation = transformation.getTranslation();
            translation.translateZ(capsule.getLength());
            transformation.setTranslation(translation);

            fGl.glMultMatrixf(transformation.getArray(), 0);

            glu.gluSphere(glu.gluNewQuadric(), capsule.getRadius(), GLU_SHAPE_SUBDIVISIONS, GLU_SHAPE_SUBDIVISIONS);
        }
        fGl.glPopMatrix();
        ;
    }

    /**
     * <p>
     * Renders a <code>Cylinder</code>.
     * </p>
     * 
     * @param cylinder The <code>Cylinder</code> to render.
     */
    protected void renderCylinder(final Cylinder cylinder)
    {
        fGl.glColor3f(cylinder.getColour().getRed(), cylinder.getColour().getGreen(), cylinder.getColour().getBlue());

        GLU glu = new GLU();
        glu.gluCylinder(glu.gluNewQuadric(), cylinder.getRadius(), cylinder.getRadius(), cylinder.getLength(), GLU_SHAPE_SUBDIVISIONS, 1);

        fGl.glPushMatrix();
        {
            SimpleTransformationMatrixf44 transformation = new SimpleTransformationMatrixf44();
            transformation.rotate((float) Math.PI, new SimpleTranslationVectorf4(0.0f, 1.0f, 0.0f, 1.0f));

            fGl.glMultMatrixf(transformation.getArray(), 0);

            glu.gluDisk(glu.gluNewQuadric(), 0.0f, cylinder.getRadius(), GLU_SHAPE_SUBDIVISIONS, 1);
        }
        fGl.glPopMatrix();

        fGl.glPushMatrix();
        {
            SimpleTransformationMatrixf44 transformation = new SimpleTransformationMatrixf44();
            TranslationVectorf translation = transformation.getTranslation();
            translation.translateZ(cylinder.getLength());
            transformation.setTranslation(translation);

            fGl.glMultMatrixf(transformation.getArray(), 0);

            glu.gluDisk(glu.gluNewQuadric(), 0.0f, cylinder.getRadius(), GLU_SHAPE_SUBDIVISIONS, 1);
        }
        fGl.glPopMatrix();
    }

    /**
     * <p>
     * Renders an <code>IndexedArrayVG</code>.
     * </p>
     * 
     * @param vertexGroup The <code>IndexedArrayVG</code> to render.
     */
    protected void renderIndexedArrayVG(final IndexedArrayVG vertexGroup)
    {
        int[] indices = vertexGroup.getIndices();
        float[] colours = vertexGroup.getColours();
        float[] normals = vertexGroup.getNormals();
        float[] vertices = vertexGroup.getVertices();
        int vertex;

        for (int faceIndex = 0; faceIndex < indices.length / VERTICES_IN_A_FACE; faceIndex++)
        {
            fGl.glBegin(getJOGLDrawingMode(fDrawingMode));
            {
                for (int vertexIndex = 0; vertexIndex < CNV_ITEMS_IN_FACE; vertexIndex += ITEMS_IN_CNV)
                {
                    vertex = indices[faceIndex * VERTICES_IN_A_FACE] * ITEMS_IN_CNV + vertexIndex;

                    fGl.glColor3f(colours[vertex], colours[vertex + 1], colours[vertex + 2]);
                    fGl.glNormal3f(normals[vertex], normals[vertex + 1], normals[vertex + 2]);
                    fGl.glVertex3f(vertices[vertex], vertices[vertex + 1], vertices[vertex + 2]);
                }
            }
            fGl.glEnd();
        }
    }

    @Override
    public void renderModel(final Model model)
    {
        if (model instanceof ArrayVG)
        {
            renderArrayVG((ArrayVG) model);
        }
        else if (model instanceof Capsule)
        {
            renderCapsule((Capsule) model);
        }
        else if (model instanceof Cylinder)
        {
            renderCylinder((Cylinder) model);
        }
        else if (model instanceof IndexedArrayVG)
        {
            renderIndexedArrayVG((IndexedArrayVG) model);
        }
        else if (model instanceof Sphere)
        {
            renderSphere((Sphere) model);
        }
        else if (model instanceof Torus)
        {
            renderTorus((Torus) model);
        }
    }

    @Override
    public void setDrawingMode(final DrawingMode mode)
    {
        fDrawingMode = mode;
    }

    /**
     * <p>
     * Renders a <code>Sphere</code>.
     * </p>
     * 
     * @param sphere The <code>Sphere</code> to render.
     */
    protected void renderSphere(final Sphere sphere)
    {
        fGl.glColor3f(sphere.getColour().getRed(), sphere.getColour().getGreen(), sphere.getColour().getBlue());

        GLU glu = new GLU();
        glu.gluSphere(glu.gluNewQuadric(), sphere.getRadius(), GLU_SHAPE_SUBDIVISIONS, GLU_SHAPE_SUBDIVISIONS);
    }

    /**
     * <p>
     * Renders a <code>Torus</code>.
     * </p>
     * 
     * @param torus The <code>Torus</code> to render.
     */
    protected void renderTorus(final Torus torus)
    {
        fGl.glColor3f(torus.getColour().getRed(), torus.getColour().getGreen(), torus.getColour().getBlue());

        GLUT glut = new GLUT();
        glut.glutSolidTorus(torus.getInnerRadius(), torus.getOuterRadius(), GLU_SHAPE_SUBDIVISIONS, GLU_SHAPE_SUBDIVISIONS);
    }

    @Override
    public void setGL(final GL newGl)
    {
        fGl = newGl;
    }
}
