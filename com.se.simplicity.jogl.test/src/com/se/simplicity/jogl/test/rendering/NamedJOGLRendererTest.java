/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.jogl.test.rendering;

import static org.easymock.EasyMock.expect;
import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.replay;
import static org.junit.Assert.assertTrue;

import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.jogl.rendering.NamedJOGLRenderer;
import com.se.simplicity.jogl.test.mocks.MockGL;
import com.se.simplicity.model.ArrayVG;
import com.se.simplicity.model.IndexedArrayVG;
import com.se.simplicity.rendering.DrawingMode;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.jogl.rendering.NamedJOGLRenderer NamedJOGLRenderer}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class NamedJOGLRendererTest
{
    /**
     * An instance of the class being unit tested.
     */
    private NamedJOGLRenderer testObject;

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public final void before()
    {
        testObject = new NamedJOGLRenderer();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.rendering.NamedJOGLRenderer.renderVertexGroup renderVertexGroup()} with the special
     * condition that the <code>VertexGroup</code> is an instance of <code>ArrayVG</code> and is to be rendered as vertices.
     * </p>
     */
    @Test
    public void renderVertexGroupArrayVGVertices()
    {
        MockGL mockGl = new MockGL();
        ArrayVG mockVertexGroup = createMock(ArrayVG.class);

        expect(mockVertexGroup.getColours()).andStubReturn(new float[] {1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f});
        expect(mockVertexGroup.getNormals()).andStubReturn(new float[] {0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f});
        expect(mockVertexGroup.getVertices()).andStubReturn(new float[] {0.0f, 2.0f, 0.0f, 1.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f});

        replay(mockVertexGroup);

        testObject.setGL(mockGl);
        testObject.renderVertexGroup(mockVertexGroup, DrawingMode.VERTICES, 123);

        assertTrue(mockGl.methodCallOrderCheck(0, "glPushName", new Object[] {123}, 0, "glPushName", new Object[] {0}));

        assertTrue(mockGl.methodCallOrderCheck(0, "glPushName", new Object[] {0}, 0, "glBegin", new Object[] {MockGL.GL_POINTS}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glBegin", new Object[] {MockGL.GL_POINTS}, 0, "glColor3f", new Object[] {1.0f, 0.0f, 0.0f}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glColor3f", new Object[] {1.0f, 0.0f, 0.0f}, 0, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}, 0, "glVertex3f", new Object[] {0.0f, 2.0f, 0.0f}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glVertex3f", new Object[] {0.0f, 2.0f, 0.0f}, 0, "glEnd", null));
        assertTrue(mockGl.methodCallOrderCheck(0, "glEnd", null, 0, "glPopName", null));
        assertTrue(mockGl.methodCallOrderCheck(0, "glPopName", null, 0, "glPushName", new Object[] {1}));

        assertTrue(mockGl.methodCallOrderCheck(0, "glPushName", new Object[] {1}, 1, "glBegin", new Object[] {MockGL.GL_POINTS}));
        assertTrue(mockGl.methodCallOrderCheck(1, "glBegin", new Object[] {MockGL.GL_POINTS}, 0, "glColor3f", new Object[] {0.0f, 1.0f, 0.0f}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glColor3f", new Object[] {0.0f, 1.0f, 0.0f}, 1, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}));
        assertTrue(mockGl.methodCallOrderCheck(1, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}, 0, "glVertex3f", new Object[] {1.0f, 0.0f, 0.0f}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glVertex3f", new Object[] {1.0f, 0.0f, 0.0f}, 1, "glEnd", null));
        assertTrue(mockGl.methodCallOrderCheck(1, "glEnd", null, 1, "glPopName", null));
        assertTrue(mockGl.methodCallOrderCheck(1, "glPopName", null, 0, "glPushName", new Object[] {2}));

        assertTrue(mockGl.methodCallOrderCheck(0, "glPushName", new Object[] {2}, 2, "glBegin", new Object[] {MockGL.GL_POINTS}));
        assertTrue(mockGl.methodCallOrderCheck(2, "glBegin", new Object[] {MockGL.GL_POINTS}, 0, "glColor3f", new Object[] {0.0f, 0.0f, 1.0f}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glColor3f", new Object[] {0.0f, 0.0f, 1.0f}, 2, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}));
        assertTrue(mockGl.methodCallOrderCheck(2, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}, 0, "glVertex3f", new Object[] {-1.0f, 0.0f, 0.0f}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glVertex3f", new Object[] {-1.0f, 0.0f, 0.0f}, 2, "glEnd", null));
        assertTrue(mockGl.methodCallOrderCheck(2, "glEnd", null, 2, "glPopName", null));
        assertTrue(mockGl.methodCallOrderCheck(2, "glPopName", null, 3, "glPopName", null));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.rendering.NamedJOGLRenderer.renderVertexGroup renderVertexGroup()} with the special
     * condition that the <code>VertexGroup</code> is an instance of <code>ArrayVG</code> and is to be rendered as edges.
     * </p>
     */
    @Test
    public void renderVertexGroupArrayVGEdges()
    {
        MockGL mockGl = new MockGL();
        ArrayVG mockVertexGroup = createMock(ArrayVG.class);

        expect(mockVertexGroup.getColours()).andStubReturn(new float[] {1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f});
        expect(mockVertexGroup.getNormals()).andStubReturn(new float[] {0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f});
        expect(mockVertexGroup.getVertices()).andStubReturn(new float[] {0.0f, 2.0f, 0.0f, 1.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f});

        replay(mockVertexGroup);

        testObject.setGL(mockGl);
        testObject.renderVertexGroup(mockVertexGroup, DrawingMode.EDGES, 123);

        assertTrue(mockGl.methodCallOrderCheck(0, "glPushName", new Object[] {123}, 0, "glPushName", new Object[] {0}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glPushName", new Object[] {0}, 0, "glBegin", new Object[] {MockGL.GL_LINE_LOOP}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glBegin", new Object[] {MockGL.GL_LINE_LOOP}, 0, "glColor3f", new Object[] {1.0f, 0.0f, 0.0f}));

        assertTrue(mockGl.methodCallOrderCheck(0, "glColor3f", new Object[] {1.0f, 0.0f, 0.0f}, 0, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}, 0, "glVertex3f", new Object[] {0.0f, 2.0f, 0.0f}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glVertex3f", new Object[] {0.0f, 2.0f, 0.0f}, 0, "glColor3f", new Object[] {0.0f, 1.0f, 0.0f}));

        assertTrue(mockGl.methodCallOrderCheck(0, "glColor3f", new Object[] {0.0f, 1.0f, 0.0f}, 1, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}));
        assertTrue(mockGl.methodCallOrderCheck(1, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}, 0, "glVertex3f", new Object[] {1.0f, 0.0f, 0.0f}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glVertex3f", new Object[] {1.0f, 0.0f, 0.0f}, 0, "glEnd", null));

        assertTrue(mockGl.methodCallOrderCheck(0, "glEnd", null, 0, "glPopName", null));
        assertTrue(mockGl.methodCallOrderCheck(0, "glPopName", null, 0, "glPushName", new Object[] {1}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glPushName", new Object[] {1}, 1, "glBegin", new Object[] {MockGL.GL_LINE_LOOP}));
        assertTrue(mockGl.methodCallOrderCheck(1, "glBegin", new Object[] {MockGL.GL_LINE_LOOP}, 1, "glColor3f", new Object[] {0.0f, 1.0f, 0.0f}));

        assertTrue(mockGl.methodCallOrderCheck(1, "glColor3f", new Object[] {0.0f, 1.0f, 0.0f}, 2, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}));
        assertTrue(mockGl.methodCallOrderCheck(2, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}, 1, "glVertex3f", new Object[] {1.0f, 0.0f, 0.0f}));
        assertTrue(mockGl.methodCallOrderCheck(1, "glVertex3f", new Object[] {1.0f, 0.0f, 0.0f}, 0, "glColor3f", new Object[] {0.0f, 0.0f, 1.0f}));

        assertTrue(mockGl.methodCallOrderCheck(0, "glColor3f", new Object[] {0.0f, 0.0f, 1.0f}, 3, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}));
        assertTrue(mockGl.methodCallOrderCheck(3, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}, 0, "glVertex3f", new Object[] {-1.0f, 0.0f, 0.0f}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glVertex3f", new Object[] {-1.0f, 0.0f, 0.0f}, 1, "glEnd", null));

        assertTrue(mockGl.methodCallOrderCheck(1, "glEnd", null, 1, "glPopName", null));
        assertTrue(mockGl.methodCallOrderCheck(1, "glPopName", null, 2, "glPopName", null));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.rendering.NamedJOGLRenderer.renderVertexGroup renderVertexGroup()} with the special
     * condition that the <code>VertexGroup</code> is an instance of <code>ArrayVG</code> and is to be rendered as faces.
     * </p>
     */
    @Test
    public void renderVertexGroupArrayVGFaces()
    {
        MockGL mockGl = new MockGL();
        ArrayVG mockVertexGroup = createMock(ArrayVG.class);

        expect(mockVertexGroup.getColours()).andStubReturn(new float[] {1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f});
        expect(mockVertexGroup.getNormals()).andStubReturn(new float[] {0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f});
        expect(mockVertexGroup.getVertices()).andStubReturn(new float[] {0.0f, 2.0f, 0.0f, 1.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f});

        replay(mockVertexGroup);

        testObject.setGL(mockGl);
        testObject.renderVertexGroup(mockVertexGroup, DrawingMode.FACES, 123);

        assertTrue(mockGl.methodCallOrderCheck(0, "glPushName", new Object[] {123}, 0, "glPushName", new Object[] {0}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glPushName", new Object[] {0}, 0, "glBegin", new Object[] {MockGL.GL_TRIANGLES}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glBegin", new Object[] {MockGL.GL_TRIANGLES}, 0, "glColor3f", new Object[] {1.0f, 0.0f, 0.0f}));

        assertTrue(mockGl.methodCallOrderCheck(0, "glColor3f", new Object[] {1.0f, 0.0f, 0.0f}, 0, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}, 0, "glVertex3f", new Object[] {0.0f, 2.0f, 0.0f}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glVertex3f", new Object[] {0.0f, 2.0f, 0.0f}, 0, "glColor3f", new Object[] {0.0f, 1.0f, 0.0f}));

        assertTrue(mockGl.methodCallOrderCheck(0, "glColor3f", new Object[] {0.0f, 1.0f, 0.0f}, 1, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}));
        assertTrue(mockGl.methodCallOrderCheck(1, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}, 0, "glVertex3f", new Object[] {1.0f, 0.0f, 0.0f}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glVertex3f", new Object[] {1.0f, 0.0f, 0.0f}, 0, "glColor3f", new Object[] {0.0f, 0.0f, 1.0f}));

        assertTrue(mockGl.methodCallOrderCheck(0, "glColor3f", new Object[] {0.0f, 0.0f, 1.0f}, 2, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}));
        assertTrue(mockGl.methodCallOrderCheck(2, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}, 0, "glVertex3f", new Object[] {-1.0f, 0.0f, 0.0f}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glVertex3f", new Object[] {-1.0f, 0.0f, 0.0f}, 0, "glEnd", null));

        assertTrue(mockGl.methodCallOrderCheck(0, "glEnd", null, 0, "glPopName", null));
        assertTrue(mockGl.methodCallOrderCheck(0, "glPopName", null, 1, "glPopName", null));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.rendering.NamedJOGLRenderer.renderVertexGroup renderVertexGroup()} with the special
     * condition that the <code>VertexGroup</code> is an instance of <code>IndexedArrayVG</code> and is to be rendered as vertices.
     * </p>
     */
    @Test
    public void renderVertexGroupIndexedArrayVGVertices()
    {
        MockGL mockGl = new MockGL();
        IndexedArrayVG mockVertexGroup = createMock(IndexedArrayVG.class);

        expect(mockVertexGroup.getIndices()).andStubReturn(new int[] {0, 1, 2});
        expect(mockVertexGroup.getColours()).andStubReturn(new float[] {1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f});
        expect(mockVertexGroup.getNormals()).andStubReturn(new float[] {0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f});
        expect(mockVertexGroup.getVertices()).andStubReturn(new float[] {0.0f, 2.0f, 0.0f, 1.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f});

        replay(mockVertexGroup);

        testObject.setGL(mockGl);
        testObject.renderVertexGroup(mockVertexGroup, DrawingMode.VERTICES, 123);

        assertTrue(mockGl.methodCallOrderCheck(0, "glPushName", new Object[] {123}, 0, "glPushName", new Object[] {0}));

        assertTrue(mockGl.methodCallOrderCheck(0, "glPushName", new Object[] {0}, 0, "glBegin", new Object[] {MockGL.GL_POINTS}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glBegin", new Object[] {MockGL.GL_POINTS}, 0, "glColor3f", new Object[] {1.0f, 0.0f, 0.0f}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glColor3f", new Object[] {1.0f, 0.0f, 0.0f}, 0, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}, 0, "glVertex3f", new Object[] {0.0f, 2.0f, 0.0f}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glVertex3f", new Object[] {0.0f, 2.0f, 0.0f}, 0, "glEnd", null));
        assertTrue(mockGl.methodCallOrderCheck(0, "glEnd", null, 0, "glPopName", null));
        assertTrue(mockGl.methodCallOrderCheck(0, "glPopName", null, 0, "glPushName", new Object[] {1}));

        assertTrue(mockGl.methodCallOrderCheck(0, "glPushName", new Object[] {1}, 1, "glBegin", new Object[] {MockGL.GL_POINTS}));
        assertTrue(mockGl.methodCallOrderCheck(1, "glBegin", new Object[] {MockGL.GL_POINTS}, 0, "glColor3f", new Object[] {0.0f, 1.0f, 0.0f}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glColor3f", new Object[] {0.0f, 1.0f, 0.0f}, 1, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}));
        assertTrue(mockGl.methodCallOrderCheck(1, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}, 0, "glVertex3f", new Object[] {1.0f, 0.0f, 0.0f}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glVertex3f", new Object[] {1.0f, 0.0f, 0.0f}, 1, "glEnd", null));
        assertTrue(mockGl.methodCallOrderCheck(1, "glEnd", null, 1, "glPopName", null));
        assertTrue(mockGl.methodCallOrderCheck(1, "glPopName", null, 0, "glPushName", new Object[] {2}));

        assertTrue(mockGl.methodCallOrderCheck(0, "glPushName", new Object[] {2}, 2, "glBegin", new Object[] {MockGL.GL_POINTS}));
        assertTrue(mockGl.methodCallOrderCheck(2, "glBegin", new Object[] {MockGL.GL_POINTS}, 0, "glColor3f", new Object[] {0.0f, 0.0f, 1.0f}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glColor3f", new Object[] {0.0f, 0.0f, 1.0f}, 2, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}));
        assertTrue(mockGl.methodCallOrderCheck(2, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}, 0, "glVertex3f", new Object[] {-1.0f, 0.0f, 0.0f}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glVertex3f", new Object[] {-1.0f, 0.0f, 0.0f}, 2, "glEnd", null));
        assertTrue(mockGl.methodCallOrderCheck(2, "glEnd", null, 2, "glPopName", null));
        assertTrue(mockGl.methodCallOrderCheck(2, "glPopName", null, 3, "glPopName", null));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.rendering.NamedJOGLRenderer.renderVertexGroup renderVertexGroup()} with the special
     * condition that the <code>VertexGroup</code> is an instance of <code>IndexedArrayVG</code> and is to be rendered as edges.
     * </p>
     */
    @Test
    public void renderVertexGroupIndexedArrayVGEdges()
    {
        MockGL mockGl = new MockGL();
        IndexedArrayVG mockVertexGroup = createMock(IndexedArrayVG.class);

        expect(mockVertexGroup.getIndices()).andStubReturn(new int[] {0, 1, 2});
        expect(mockVertexGroup.getColours()).andStubReturn(new float[] {1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f});
        expect(mockVertexGroup.getNormals()).andStubReturn(new float[] {0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f});
        expect(mockVertexGroup.getVertices()).andStubReturn(new float[] {0.0f, 2.0f, 0.0f, 1.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f});

        replay(mockVertexGroup);

        testObject.setGL(mockGl);
        testObject.renderVertexGroup(mockVertexGroup, DrawingMode.EDGES, 123);

        assertTrue(mockGl.methodCallOrderCheck(0, "glPushName", new Object[] {123}, 0, "glPushName", new Object[] {0}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glPushName", new Object[] {0}, 0, "glBegin", new Object[] {MockGL.GL_LINE_LOOP}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glBegin", new Object[] {MockGL.GL_LINE_LOOP}, 0, "glColor3f", new Object[] {1.0f, 0.0f, 0.0f}));

        assertTrue(mockGl.methodCallOrderCheck(0, "glColor3f", new Object[] {1.0f, 0.0f, 0.0f}, 0, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}, 0, "glVertex3f", new Object[] {0.0f, 2.0f, 0.0f}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glVertex3f", new Object[] {0.0f, 2.0f, 0.0f}, 0, "glColor3f", new Object[] {0.0f, 1.0f, 0.0f}));

        assertTrue(mockGl.methodCallOrderCheck(0, "glColor3f", new Object[] {0.0f, 1.0f, 0.0f}, 1, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}));
        assertTrue(mockGl.methodCallOrderCheck(1, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}, 0, "glVertex3f", new Object[] {1.0f, 0.0f, 0.0f}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glVertex3f", new Object[] {1.0f, 0.0f, 0.0f}, 0, "glEnd", null));

        assertTrue(mockGl.methodCallOrderCheck(0, "glEnd", null, 0, "glPopName", null));
        assertTrue(mockGl.methodCallOrderCheck(0, "glPopName", null, 0, "glPushName", new Object[] {1}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glPushName", new Object[] {1}, 1, "glBegin", new Object[] {MockGL.GL_LINE_LOOP}));
        assertTrue(mockGl.methodCallOrderCheck(1, "glBegin", new Object[] {MockGL.GL_LINE_LOOP}, 1, "glColor3f", new Object[] {0.0f, 1.0f, 0.0f}));

        assertTrue(mockGl.methodCallOrderCheck(1, "glColor3f", new Object[] {0.0f, 1.0f, 0.0f}, 2, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}));
        assertTrue(mockGl.methodCallOrderCheck(2, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}, 1, "glVertex3f", new Object[] {1.0f, 0.0f, 0.0f}));
        assertTrue(mockGl.methodCallOrderCheck(1, "glVertex3f", new Object[] {1.0f, 0.0f, 0.0f}, 0, "glColor3f", new Object[] {0.0f, 0.0f, 1.0f}));

        assertTrue(mockGl.methodCallOrderCheck(0, "glColor3f", new Object[] {0.0f, 0.0f, 1.0f}, 3, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}));
        assertTrue(mockGl.methodCallOrderCheck(3, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}, 0, "glVertex3f", new Object[] {-1.0f, 0.0f, 0.0f}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glVertex3f", new Object[] {-1.0f, 0.0f, 0.0f}, 1, "glEnd", null));

        assertTrue(mockGl.methodCallOrderCheck(1, "glEnd", null, 1, "glPopName", null));
        assertTrue(mockGl.methodCallOrderCheck(1, "glPopName", null, 2, "glPopName", null));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.rendering.NamedJOGLRenderer.renderVertexGroup renderVertexGroup()} with the special
     * condition that the <code>VertexGroup</code> is an instance of <code>IndexedArrayVG</code> and is to be rendered as faces.
     * </p>
     */
    @Test
    public void renderVertexGroupIndexedArrayVGFaces()
    {
        MockGL mockGl = new MockGL();
        IndexedArrayVG mockVertexGroup = createMock(IndexedArrayVG.class);

        expect(mockVertexGroup.getIndices()).andStubReturn(new int[] {0, 1, 2});
        expect(mockVertexGroup.getColours()).andStubReturn(new float[] {1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f});
        expect(mockVertexGroup.getNormals()).andStubReturn(new float[] {0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f});
        expect(mockVertexGroup.getVertices()).andStubReturn(new float[] {0.0f, 2.0f, 0.0f, 1.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f});

        replay(mockVertexGroup);

        testObject.setGL(mockGl);
        testObject.renderVertexGroup(mockVertexGroup, DrawingMode.FACES, 123);

        assertTrue(mockGl.methodCallOrderCheck(0, "glPushName", new Object[] {123}, 0, "glPushName", new Object[] {0}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glPushName", new Object[] {0}, 0, "glBegin", new Object[] {MockGL.GL_TRIANGLES}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glBegin", new Object[] {MockGL.GL_TRIANGLES}, 0, "glColor3f", new Object[] {1.0f, 0.0f, 0.0f}));

        assertTrue(mockGl.methodCallOrderCheck(0, "glColor3f", new Object[] {1.0f, 0.0f, 0.0f}, 0, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}, 0, "glVertex3f", new Object[] {0.0f, 2.0f, 0.0f}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glVertex3f", new Object[] {0.0f, 2.0f, 0.0f}, 0, "glColor3f", new Object[] {0.0f, 1.0f, 0.0f}));

        assertTrue(mockGl.methodCallOrderCheck(0, "glColor3f", new Object[] {0.0f, 1.0f, 0.0f}, 1, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}));
        assertTrue(mockGl.methodCallOrderCheck(1, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}, 0, "glVertex3f", new Object[] {1.0f, 0.0f, 0.0f}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glVertex3f", new Object[] {1.0f, 0.0f, 0.0f}, 0, "glColor3f", new Object[] {0.0f, 0.0f, 1.0f}));

        assertTrue(mockGl.methodCallOrderCheck(0, "glColor3f", new Object[] {0.0f, 0.0f, 1.0f}, 2, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}));
        assertTrue(mockGl.methodCallOrderCheck(2, "glNormal3f", new Object[] {0.0f, 0.0f, 1.0f}, 0, "glVertex3f", new Object[] {-1.0f, 0.0f, 0.0f}));
        assertTrue(mockGl.methodCallOrderCheck(0, "glVertex3f", new Object[] {-1.0f, 0.0f, 0.0f}, 0, "glEnd", null));

        assertTrue(mockGl.methodCallOrderCheck(0, "glEnd", null, 0, "glPopName", null));
        assertTrue(mockGl.methodCallOrderCheck(0, "glPopName", null, 1, "glPopName", null));
    }
}
