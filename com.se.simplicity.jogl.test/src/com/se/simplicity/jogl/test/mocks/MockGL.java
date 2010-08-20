/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.jogl.test.mocks;

import java.nio.Buffer;
import java.nio.ByteBuffer;
import java.nio.DoubleBuffer;
import java.nio.FloatBuffer;
import java.nio.IntBuffer;
import java.nio.LongBuffer;
import java.nio.ShortBuffer;

import javax.media.opengl.GL;

import com.se.devenvy.mocks.MockObject;

public class MockGL extends MockObject implements GL
{
    @Override
    public Object getExtension(final String arg0)
    {
        // Stub method only.
        return null;
    }

    @Override
    public Object getPlatformGLExtensions()
    {
        // Stub method only.
        return null;
    }

    @Override
    public void glAccum(final int arg0, final float arg1)
    {
    // Stub method only.

    }

    @Override
    public void glActiveStencilFaceEXT(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glActiveTexture(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glActiveVaryingNV(final int arg0, final ByteBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glActiveVaryingNV(final int arg0, final byte[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public ByteBuffer glAllocateMemoryNV(final int arg0, final float arg1, final float arg2, final float arg3)
    {
        // Stub method only.
        return null;
    }

    @Override
    public void glAlphaFragmentOp1ATI(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5)
    {
    // Stub method only.

    }

    @Override
    public void glAlphaFragmentOp2ATI(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5, final int arg6,
            final int arg7, final int arg8)
    {
    // Stub method only.

    }

    @Override
    public void glAlphaFragmentOp3ATI(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5, final int arg6,
            final int arg7, final int arg8, final int arg9, final int arg10, final int arg11)
    {
    // Stub method only.

    }

    @Override
    public void glAlphaFunc(final int arg0, final float arg1)
    {
    // Stub method only.

    }

    @Override
    public void glApplyTextureEXT(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public boolean glAreProgramsResidentNV(final int arg0, final IntBuffer arg1, final ByteBuffer arg2)
    {
        // Stub method only.
        return false;
    }

    @Override
    public boolean glAreProgramsResidentNV(final int arg0, final int[] arg1, final int arg2, final byte[] arg3, final int arg4)
    {
        // Stub method only.
        return false;
    }

    @Override
    public boolean glAreTexturesResident(final int arg0, final IntBuffer arg1, final ByteBuffer arg2)
    {
        // Stub method only.
        return false;
    }

    @Override
    public boolean glAreTexturesResident(final int arg0, final int[] arg1, final int arg2, final byte[] arg3, final int arg4)
    {
        // Stub method only.
        return false;
    }

    @Override
    public void glArrayElement(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glArrayObjectATI(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5)
    {
    // Stub method only.

    }

    @Override
    public void glAsyncMarkerSGIX(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glAttachObjectARB(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glAttachShader(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glBegin(final int arg0)
    {
        addMethodCall("glBegin", new Object[] {arg0});

    }

    @Override
    public void glBeginFragmentShaderATI()
    {
    // Stub method only.

    }

    @Override
    public void glBeginOcclusionQueryNV(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glBeginQuery(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glBeginQueryARB(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glBeginTransformFeedbackNV(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glBeginVertexShaderEXT()
    {
    // Stub method only.

    }

    @Override
    public void glBindAttribLocation(final int arg0, final int arg1, final String arg2)
    {
    // Stub method only.

    }

    @Override
    public void glBindAttribLocationARB(final int arg0, final int arg1, final String arg2)
    {
    // Stub method only.

    }

    @Override
    public void glBindBuffer(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glBindBufferARB(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glBindBufferBaseNV(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glBindBufferOffsetNV(final int arg0, final int arg1, final int arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glBindBufferRangeNV(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glBindFragDataLocationEXT(final int arg0, final int arg1, final ByteBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glBindFragDataLocationEXT(final int arg0, final int arg1, final byte[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glBindFragmentShaderATI(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glBindFramebufferEXT(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public final int glBindLightParameterEXT(final int arg0, final int arg1)
    {
        // Stub method only.
        return 0;
    }

    @Override
    public final int glBindMaterialParameterEXT(final int arg0, final int arg1)
    {
        // Stub method only.
        return 0;
    }

    @Override
    public final int glBindParameterEXT(final int arg0)
    {
        // Stub method only.
        return 0;
    }

    @Override
    public void glBindProgramARB(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glBindProgramNV(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glBindRenderbufferEXT(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public final int glBindTexGenParameterEXT(final int arg0, final int arg1, final int arg2)
    {
        // Stub method only.
        return 0;
    }

    @Override
    public void glBindTexture(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public final int glBindTextureUnitParameterEXT(final int arg0, final int arg1)
    {
        // Stub method only.
        return 0;
    }

    @Override
    public void glBindVertexArrayAPPLE(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glBindVertexShaderEXT(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glBitmap(final int arg0, final int arg1, final float arg2, final float arg3, final float arg4, final float arg5, final ByteBuffer arg6)
    {
    // Stub method only.

    }

    @Override
    public void glBitmap(final int arg0, final int arg1, final float arg2, final float arg3, final float arg4, final float arg5, final long arg6)
    {
    // Stub method only.

    }

    @Override
    public void glBitmap(final int arg0, final int arg1, final float arg2, final float arg3, final float arg4, final float arg5, final byte[] arg6,
            final int arg7)
    {
    // Stub method only.

    }

    @Override
    public void glBlendColor(final float arg0, final float arg1, final float arg2, final float arg3)
    {
    // Stub method only.

    }

    @Override
    public void glBlendEquation(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glBlendEquationSeparate(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glBlendEquationSeparateEXT(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glBlendFunc(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glBlendFuncSeparate(final int arg0, final int arg1, final int arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glBlendFuncSeparateEXT(final int arg0, final int arg1, final int arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glBlendFuncSeparateINGR(final int arg0, final int arg1, final int arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glBlitFramebufferEXT(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5, final int arg6,
            final int arg7, final int arg8, final int arg9)
    {
    // Stub method only.

    }

    @Override
    public void glBufferData(final int arg0, final int arg1, final Buffer arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glBufferDataARB(final int arg0, final int arg1, final Buffer arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glBufferParameteriAPPLE(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public final int glBufferRegionEnabled()
    {
        // Stub method only.
        return 0;
    }

    @Override
    public void glBufferSubData(final int arg0, final int arg1, final int arg2, final Buffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glBufferSubDataARB(final int arg0, final int arg1, final int arg2, final Buffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glCallList(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glCallLists(final int arg0, final int arg1, final Buffer arg2)
    {
    // Stub method only.

    }

    @Override
    public final int glCheckFramebufferStatusEXT(final int arg0)
    {
        // Stub method only.
        return 0;
    }

    @Override
    public void glClampColorARB(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glClear(final int arg0)
    {
        addMethodCall("glClear", new Object[] {arg0});

    }

    @Override
    public void glClearAccum(final float arg0, final float arg1, final float arg2, final float arg3)
    {
    // Stub method only.

    }

    @Override
    public void glClearColor(final float arg0, final float arg1, final float arg2, final float arg3)
    {
    // Stub method only.

    }

    @Override
    public void glClearColorIiEXT(final int arg0, final int arg1, final int arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glClearColorIuiEXT(final int arg0, final int arg1, final int arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glClearDepth(final double arg0)
    {
    // Stub method only.

    }

    @Override
    public void glClearDepthdNV(final double arg0)
    {
    // Stub method only.

    }

    @Override
    public void glClearIndex(final float arg0)
    {
    // Stub method only.

    }

    @Override
    public void glClearStencil(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glClientActiveTexture(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glClientActiveVertexStreamATI(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glClipPlane(final int arg0, final DoubleBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glClipPlane(final int arg0, final double[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glColor3b(final byte arg0, final byte arg1, final byte arg2)
    {
    // Stub method only.

    }

    @Override
    public void glColor3bv(final ByteBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glColor3bv(final byte[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glColor3d(final double arg0, final double arg1, final double arg2)
    {
    // Stub method only.

    }

    @Override
    public void glColor3dv(final DoubleBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glColor3dv(final double[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glColor3f(final float arg0, final float arg1, final float arg2)
    {
        addMethodCall("glColor3f", new Object[] {arg0, arg1, arg2});

    }

    @Override
    public void glColor3fVertex3fSUN(final float arg0, final float arg1, final float arg2, final float arg3, final float arg4, final float arg5)
    {
    // Stub method only.

    }

    @Override
    public void glColor3fVertex3fvSUN(FloatBuffer arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glColor3fVertex3fvSUN(final float[] arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glColor3fv(FloatBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glColor3fv(final float[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glColor3hNV(final short arg0, final short arg1, final short arg2)
    {
    // Stub method only.

    }

    @Override
    public void glColor3hvNV(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glColor3hvNV(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glColor3i(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glColor3iv(final IntBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glColor3iv(final int[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glColor3s(final short arg0, final short arg1, final short arg2)
    {
    // Stub method only.

    }

    @Override
    public void glColor3sv(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glColor3sv(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glColor3ub(final byte arg0, final byte arg1, final byte arg2)
    {
    // Stub method only.

    }

    @Override
    public void glColor3ubv(final ByteBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glColor3ubv(final byte[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glColor3ui(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glColor3uiv(final IntBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glColor3uiv(final int[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glColor3us(final short arg0, final short arg1, final short arg2)
    {
    // Stub method only.

    }

    @Override
    public void glColor3usv(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glColor3usv(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glColor4b(final byte arg0, final byte arg1, final byte arg2, final byte arg3)
    {
    // Stub method only.

    }

    @Override
    public void glColor4bv(final ByteBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glColor4bv(final byte[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glColor4d(final double arg0, final double arg1, final double arg2, final double arg3)
    {
    // Stub method only.

    }

    @Override
    public void glColor4dv(final DoubleBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glColor4dv(final double[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glColor4f(final float arg0, final float arg1, final float arg2, final float arg3)
    {
    // Stub method only.

    }

    @Override
    public void glColor4fNormal3fVertex3fSUN(final float arg0, final float arg1, final float arg2, final float arg3, final float arg4,
            final float arg5, final float arg6, final float arg7, float arg8, final float arg9)
    {
    // Stub method only.

    }

    @Override
    public void glColor4fNormal3fVertex3fvSUN(FloatBuffer arg0, final FloatBuffer arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glColor4fNormal3fVertex3fvSUN(final float[] arg0, final int arg1, final float[] arg2, final int arg3, final float[] arg4,
            final int arg5)
    {
    // Stub method only.

    }

    @Override
    public void glColor4fv(FloatBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glColor4fv(final float[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glColor4hNV(final short arg0, final short arg1, final short arg2, final short arg3)
    {
    // Stub method only.

    }

    @Override
    public void glColor4hvNV(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glColor4hvNV(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glColor4i(final int arg0, final int arg1, final int arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glColor4iv(final IntBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glColor4iv(final int[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glColor4s(final short arg0, final short arg1, final short arg2, final short arg3)
    {
    // Stub method only.

    }

    @Override
    public void glColor4sv(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glColor4sv(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glColor4ub(final byte arg0, final byte arg1, final byte arg2, final byte arg3)
    {
    // Stub method only.

    }

    @Override
    public void glColor4ubVertex2fSUN(final byte arg0, final byte arg1, final byte arg2, final byte arg3, final float arg4, final float arg5)
    {
    // Stub method only.

    }

    @Override
    public void glColor4ubVertex2fvSUN(final ByteBuffer arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glColor4ubVertex2fvSUN(final byte[] arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glColor4ubVertex3fSUN(final byte arg0, final byte arg1, final byte arg2, final byte arg3, final float arg4, final float arg5,
            final float arg6)
    {
    // Stub method only.

    }

    @Override
    public void glColor4ubVertex3fvSUN(final ByteBuffer arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glColor4ubVertex3fvSUN(final byte[] arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glColor4ubv(final ByteBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glColor4ubv(final byte[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glColor4ui(final int arg0, final int arg1, final int arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glColor4uiv(final IntBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glColor4uiv(final int[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glColor4us(final short arg0, final short arg1, final short arg2, final short arg3)
    {
    // Stub method only.

    }

    @Override
    public void glColor4usv(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glColor4usv(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glColorFragmentOp1ATI(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5, final int arg6)
    {
    // Stub method only.

    }

    @Override
    public void glColorFragmentOp2ATI(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5, final int arg6,
            final int arg7, final int arg8, final int arg9)
    {
    // Stub method only.

    }

    @Override
    public void glColorFragmentOp3ATI(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5, final int arg6,
            final int arg7, final int arg8, final int arg9, final int arg10, final int arg11, final int arg12)
    {
    // Stub method only.

    }

    @Override
    public void glColorMask(final boolean arg0, final boolean arg1, final boolean arg2, final boolean arg3)
    {
    // Stub method only.

    }

    @Override
    public void glColorMaskIndexedEXT(final int arg0, final boolean arg1, final boolean arg2, final boolean arg3, final boolean arg4)
    {
    // Stub method only.

    }

    @Override
    public void glColorMaterial(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glColorPointer(final int arg0, final int arg1, final int arg2, final Buffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glColorPointer(final int arg0, final int arg1, final int arg2, final long arg3)
    {
    // Stub method only.

    }

    @Override
    public void glColorSubTable(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final Buffer arg5)
    {
    // Stub method only.

    }

    @Override
    public void glColorSubTable(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final long arg5)
    {
    // Stub method only.

    }

    @Override
    public void glColorTable(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final Buffer arg5)
    {
    // Stub method only.

    }

    @Override
    public void glColorTable(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final long arg5)
    {
    // Stub method only.

    }

    @Override
    public void glColorTableEXT(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final Buffer arg5)
    {
    // Stub method only.

    }

    @Override
    public void glColorTableParameterfv(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glColorTableParameterfv(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glColorTableParameteriv(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glColorTableParameteriv(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glCombinerInputNV(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5)
    {
    // Stub method only.

    }

    @Override
    public void glCombinerOutputNV(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5, final int arg6,
            final boolean arg7, final boolean arg8, final boolean arg9)
    {
    // Stub method only.

    }

    @Override
    public void glCombinerParameterfNV(final int arg0, final float arg1)
    {
    // Stub method only.

    }

    @Override
    public void glCombinerParameterfvNV(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glCombinerParameterfvNV(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glCombinerParameteriNV(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glCombinerParameterivNV(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glCombinerParameterivNV(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glCombinerStageParameterfvNV(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glCombinerStageParameterfvNV(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glCompileShader(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glCompileShaderARB(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glCompressedTexImage1D(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5,
            final Buffer arg6)
    {
    // Stub method only.

    }

    @Override
    public void glCompressedTexImage1D(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5, final long arg6)
    {
    // Stub method only.

    }

    @Override
    public void glCompressedTexImage2D(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5,
            final int arg6, final Buffer arg7)
    {
    // Stub method only.

    }

    @Override
    public void glCompressedTexImage2D(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5,
            final int arg6, final long arg7)
    {
    // Stub method only.

    }

    @Override
    public void glCompressedTexImage3D(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5,
            final int arg6, final int arg7, final Buffer arg8)
    {
    // Stub method only.

    }

    @Override
    public void glCompressedTexImage3D(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5,
            final int arg6, final int arg7, final long arg8)
    {
    // Stub method only.

    }

    @Override
    public void glCompressedTexSubImage1D(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5,
            final Buffer arg6)
    {
    // Stub method only.

    }

    @Override
    public void glCompressedTexSubImage1D(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5,
            final long arg6)
    {
    // Stub method only.

    }

    @Override
    public void glCompressedTexSubImage2D(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5,
            final int arg6, final int arg7, final Buffer arg8)
    {
    // Stub method only.

    }

    @Override
    public void glCompressedTexSubImage2D(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5,
            final int arg6, final int arg7, final long arg8)
    {
    // Stub method only.

    }

    @Override
    public void glCompressedTexSubImage3D(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5,
            final int arg6, final int arg7, final int arg8, final int arg9, Buffer arg10)
    {
    // Stub method only.

    }

    @Override
    public void glCompressedTexSubImage3D(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5,
            final int arg6, final int arg7, final int arg8, final int arg9, long arg10)
    {
    // Stub method only.

    }

    @Override
    public void glConvolutionFilter1D(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final Buffer arg5)
    {
    // Stub method only.

    }

    @Override
    public void glConvolutionFilter1D(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final long arg5)
    {
    // Stub method only.

    }

    @Override
    public void glConvolutionFilter2D(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5,
            final Buffer arg6)
    {
    // Stub method only.

    }

    @Override
    public void glConvolutionFilter2D(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5, final long arg6)
    {
    // Stub method only.

    }

    @Override
    public void glConvolutionParameterf(final int arg0, final int arg1, final float arg2)
    {
    // Stub method only.

    }

    @Override
    public void glConvolutionParameterfv(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glConvolutionParameterfv(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glConvolutionParameteri(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glConvolutionParameteriv(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glConvolutionParameteriv(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glCopyColorSubTable(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glCopyColorTable(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glCopyConvolutionFilter1D(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glCopyConvolutionFilter2D(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5)
    {
    // Stub method only.

    }

    @Override
    public void glCopyPixels(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glCopyTexImage1D(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5, final int arg6)
    {
    // Stub method only.

    }

    @Override
    public void glCopyTexImage2D(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5, final int arg6,
            final int arg7)
    {
    // Stub method only.

    }

    @Override
    public void glCopyTexSubImage1D(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5)
    {
    // Stub method only.

    }

    @Override
    public void glCopyTexSubImage2D(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5, final int arg6,
            final int arg7)
    {
    // Stub method only.

    }

    @Override
    public void glCopyTexSubImage3D(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5, final int arg6,
            final int arg7, final int arg8)
    {
    // Stub method only.

    }

    @Override
    public final int glCreateProgram()
    {
        // Stub method only.
        return 0;
    }

    @Override
    public final int glCreateProgramObjectARB()
    {
        // Stub method only.
        return 0;
    }

    @Override
    public final int glCreateShader(final int arg0)
    {
        // Stub method only.
        return 0;
    }

    @Override
    public final int glCreateShaderObjectARB(final int arg0)
    {
        // Stub method only.
        return 0;
    }

    @Override
    public void glCullFace(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glCullParameterdvEXT(final int arg0, final DoubleBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glCullParameterdvEXT(final int arg0, final double[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glCullParameterfvEXT(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glCullParameterfvEXT(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glCurrentPaletteMatrixARB(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glDeformSGIX(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glDeformationMap3dSGIX(final int arg0, final double arg1, final double arg2, final int arg3, final int arg4, final double arg5,
            final double arg6, final int arg7, final int arg8, double arg9, final double arg10, final int arg11, final int arg12,
            final DoubleBuffer arg13)
    {
    // Stub method only.

    }

    @Override
    public void glDeformationMap3dSGIX(final int arg0, final double arg1, final double arg2, final int arg3, final int arg4, final double arg5,
            final double arg6, final int arg7, final int arg8, double arg9, final double arg10, final int arg11, final int arg12,
            final double[] arg13, final int arg14)
    {
    // Stub method only.

    }

    @Override
    public void glDeformationMap3fSGIX(final int arg0, final float arg1, final float arg2, final int arg3, final int arg4, final float arg5,
            final float arg6, final int arg7, final int arg8, final float arg9, float arg10, final int arg11, final int arg12, final FloatBuffer arg13)
    {
    // Stub method only.

    }

    @Override
    public void glDeformationMap3fSGIX(final int arg0, final float arg1, final float arg2, final int arg3, final int arg4, final float arg5,
            final float arg6, final int arg7, final int arg8, final float arg9, float arg10, final int arg11, final int arg12, final float[] arg13,
            final int arg14)
    {
    // Stub method only.

    }

    @Override
    public void glDeleteAsyncMarkersSGIX(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glDeleteBufferRegion(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glDeleteBuffers(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glDeleteBuffers(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glDeleteBuffersARB(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glDeleteBuffersARB(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glDeleteFencesAPPLE(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glDeleteFencesAPPLE(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glDeleteFencesNV(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glDeleteFencesNV(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glDeleteFragmentShaderATI(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glDeleteFramebuffersEXT(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glDeleteFramebuffersEXT(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glDeleteLists(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glDeleteObjectARB(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glDeleteOcclusionQueriesNV(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glDeleteOcclusionQueriesNV(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glDeleteProgram(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glDeleteProgramsARB(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glDeleteProgramsARB(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glDeleteProgramsNV(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glDeleteProgramsNV(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glDeleteQueries(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glDeleteQueries(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glDeleteQueriesARB(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glDeleteQueriesARB(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glDeleteRenderbuffersEXT(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glDeleteRenderbuffersEXT(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glDeleteShader(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glDeleteTextures(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glDeleteTextures(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glDeleteVertexArraysAPPLE(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glDeleteVertexArraysAPPLE(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glDeleteVertexShaderEXT(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glDepthBoundsEXT(final double arg0, final double arg1)
    {
    // Stub method only.

    }

    @Override
    public void glDepthBoundsdNV(final double arg0, final double arg1)
    {
    // Stub method only.

    }

    @Override
    public void glDepthFunc(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glDepthMask(final boolean arg0)
    {
    // Stub method only.

    }

    @Override
    public void glDepthRange(final double arg0, final double arg1)
    {
    // Stub method only.

    }

    @Override
    public void glDepthRangedNV(final double arg0, final double arg1)
    {
    // Stub method only.

    }

    @Override
    public void glDetachObjectARB(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glDetachShader(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glDetailTexFuncSGIS(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glDetailTexFuncSGIS(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glDisable(final int arg0)
    {
        addMethodCall("glDisable", new Object[] {arg0});

    }

    @Override
    public void glDisableClientState(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glDisableIndexedEXT(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glDisableVariantClientStateEXT(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glDisableVertexAttribAPPLE(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glDisableVertexAttribArray(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glDisableVertexAttribArrayARB(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glDrawArrays(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glDrawArraysInstancedEXT(final int arg0, final int arg1, final int arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glDrawBuffer(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glDrawBufferRegion(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5, final int arg6)
    {
    // Stub method only.

    }

    @Override
    public void glDrawBuffers(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glDrawBuffers(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glDrawBuffersARB(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glDrawBuffersARB(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glDrawBuffersATI(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glDrawBuffersATI(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glDrawElementArrayAPPLE(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glDrawElementArrayATI(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glDrawElements(final int arg0, final int arg1, final int arg2, final Buffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glDrawElements(final int arg0, final int arg1, final int arg2, final long arg3)
    {
    // Stub method only.

    }

    @Override
    public void glDrawElementsInstancedEXT(final int arg0, final int arg1, final int arg2, final Buffer arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glDrawMeshArraysSUN(final int arg0, final int arg1, final int arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glDrawPixels(final int arg0, final int arg1, final int arg2, final int arg3, final Buffer arg4)
    {
    // Stub method only.

    }

    @Override
    public void glDrawPixels(final int arg0, final int arg1, final int arg2, final int arg3, final long arg4)
    {
    // Stub method only.

    }

    @Override
    public void glDrawRangeElementArrayAPPLE(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glDrawRangeElementArrayATI(final int arg0, final int arg1, final int arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glDrawRangeElements(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final Buffer arg5)
    {
    // Stub method only.

    }

    @Override
    public void glDrawRangeElements(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final long arg5)
    {
    // Stub method only.

    }

    @Override
    public void glEdgeFlag(final boolean arg0)
    {
    // Stub method only.

    }

    @Override
    public void glEdgeFlagPointer(final int arg0, final Buffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glEdgeFlagPointer(final int arg0, final long arg1)
    {
    // Stub method only.

    }

    @Override
    public void glEdgeFlagv(final ByteBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glEdgeFlagv(final byte[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glElementPointerAPPLE(final int arg0, final Buffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glElementPointerATI(final int arg0, final Buffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glElementPointerATI(final int arg0, final long arg1)
    {
    // Stub method only.

    }

    @Override
    public void glEnable(final int arg0)
    {
        addMethodCall("glEnable", new Object[] {arg0});

    }

    @Override
    public void glEnableClientState(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glEnableIndexedEXT(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glEnableVariantClientStateEXT(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glEnableVertexAttribAPPLE(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glEnableVertexAttribArray(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glEnableVertexAttribArrayARB(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glEnd()
    {
        addMethodCall("glEnd", null);

    }

    @Override
    public void glEndFragmentShaderATI()
    {
    // Stub method only.

    }

    @Override
    public void glEndList()
    {
    // Stub method only.

    }

    @Override
    public void glEndOcclusionQueryNV()
    {
    // Stub method only.

    }

    @Override
    public void glEndQuery(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glEndQueryARB(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glEndTransformFeedbackNV()
    {
    // Stub method only.

    }

    @Override
    public void glEndVertexShaderEXT()
    {
    // Stub method only.

    }

    @Override
    public void glEvalCoord1d(final double arg0)
    {
    // Stub method only.

    }

    @Override
    public void glEvalCoord1dv(final DoubleBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glEvalCoord1dv(final double[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glEvalCoord1f(final float arg0)
    {
    // Stub method only.

    }

    @Override
    public void glEvalCoord1fv(FloatBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glEvalCoord1fv(final float[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glEvalCoord2d(final double arg0, final double arg1)
    {
    // Stub method only.

    }

    @Override
    public void glEvalCoord2dv(final DoubleBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glEvalCoord2dv(final double[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glEvalCoord2f(final float arg0, final float arg1)
    {
    // Stub method only.

    }

    @Override
    public void glEvalCoord2fv(FloatBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glEvalCoord2fv(final float[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glEvalMapsNV(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glEvalMesh1(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glEvalMesh2(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glEvalPoint1(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glEvalPoint2(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glExecuteProgramNV(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glExecuteProgramNV(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glExtractComponentEXT(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glFeedbackBuffer(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glFinalCombinerInputNV(final int arg0, final int arg1, final int arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glFinish()
    {
    // Stub method only.

    }

    @Override
    public final int glFinishAsyncSGIX(final IntBuffer arg0)
    {
        // Stub method only.
        return 0;
    }

    @Override
    public final int glFinishAsyncSGIX(final int[] arg0, final int arg1)
    {
        // Stub method only.
        return 0;
    }

    @Override
    public void glFinishFenceAPPLE(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glFinishFenceNV(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glFinishObjectAPPLE(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glFinishRenderAPPLE()
    {
    // Stub method only.

    }

    @Override
    public void glFinishTextureSUNX()
    {
    // Stub method only.

    }

    @Override
    public void glFlush()
    {
    // Stub method only.

    }

    @Override
    public void glFlushMappedBufferRangeAPPLE(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glFlushPixelDataRangeNV(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glFlushRasterSGIX()
    {
    // Stub method only.

    }

    @Override
    public void glFlushRenderAPPLE()
    {
    // Stub method only.

    }

    @Override
    public void glFlushVertexArrayRangeAPPLE(final int arg0, final Buffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glFlushVertexArrayRangeNV()
    {
    // Stub method only.

    }

    @Override
    public void glFogCoordPointer(final int arg0, final int arg1, final Buffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glFogCoordPointer(final int arg0, final int arg1, final long arg2)
    {
    // Stub method only.

    }

    @Override
    public void glFogCoordPointerEXT(final int arg0, final int arg1, final Buffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glFogCoordPointerEXT(final int arg0, final int arg1, final long arg2)
    {
    // Stub method only.

    }

    @Override
    public void glFogCoordd(final double arg0)
    {
    // Stub method only.

    }

    @Override
    public void glFogCoorddEXT(final double arg0)
    {
    // Stub method only.

    }

    @Override
    public void glFogCoorddv(final DoubleBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glFogCoorddv(final double[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glFogCoorddvEXT(final DoubleBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glFogCoorddvEXT(final double[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glFogCoordf(final float arg0)
    {
    // Stub method only.

    }

    @Override
    public void glFogCoordfEXT(final float arg0)
    {
    // Stub method only.

    }

    @Override
    public void glFogCoordfv(FloatBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glFogCoordfv(final float[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glFogCoordfvEXT(FloatBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glFogCoordfvEXT(final float[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glFogCoordhNV(final short arg0)
    {
    // Stub method only.

    }

    @Override
    public void glFogCoordhvNV(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glFogCoordhvNV(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glFogFuncSGIS(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glFogFuncSGIS(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glFogf(final int arg0, final float arg1)
    {
    // Stub method only.

    }

    @Override
    public void glFogfv(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glFogfv(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glFogi(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glFogiv(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glFogiv(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glFragmentColorMaterialSGIX(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glFragmentLightModelfSGIX(final int arg0, final float arg1)
    {
    // Stub method only.

    }

    @Override
    public void glFragmentLightModelfvSGIX(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glFragmentLightModelfvSGIX(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glFragmentLightModeliSGIX(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glFragmentLightModelivSGIX(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glFragmentLightModelivSGIX(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glFragmentLightfSGIX(final int arg0, final int arg1, final float arg2)
    {
    // Stub method only.

    }

    @Override
    public void glFragmentLightfvSGIX(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glFragmentLightfvSGIX(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glFragmentLightiSGIX(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glFragmentLightivSGIX(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glFragmentLightivSGIX(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glFragmentMaterialfSGIX(final int arg0, final int arg1, final float arg2)
    {
    // Stub method only.

    }

    @Override
    public void glFragmentMaterialfvSGIX(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glFragmentMaterialfvSGIX(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glFragmentMaterialiSGIX(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glFragmentMaterialivSGIX(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glFragmentMaterialivSGIX(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glFrameZoomSGIX(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glFramebufferRenderbufferEXT(final int arg0, final int arg1, final int arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glFramebufferTexture1DEXT(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glFramebufferTexture2DEXT(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glFramebufferTexture3DEXT(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5)
    {
    // Stub method only.

    }

    @Override
    public void glFramebufferTextureEXT(final int arg0, final int arg1, final int arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glFramebufferTextureFaceEXT(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glFramebufferTextureLayerEXT(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glFreeObjectBufferATI(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glFrontFace(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glFrustum(final double arg0, final double arg1, final double arg2, final double arg3, final double arg4, final double arg5)
    {
        addMethodCall("glFrustum", new Object[] {arg0, arg1, arg2, arg3, arg4, arg5});

    }

    @Override
    public final int glGenAsyncMarkersSGIX(final int arg0)
    {
        // Stub method only.
        return 0;
    }

    @Override
    public void glGenBuffers(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glGenBuffers(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGenBuffersARB(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glGenBuffersARB(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGenFencesAPPLE(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glGenFencesAPPLE(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGenFencesNV(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glGenFencesNV(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public final int glGenFragmentShadersATI(final int arg0)
    {
        // Stub method only.
        return 0;
    }

    @Override
    public void glGenFramebuffersEXT(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glGenFramebuffersEXT(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public final int glGenLists(final int arg0)
    {
        // Stub method only.
        return 0;
    }

    @Override
    public void glGenOcclusionQueriesNV(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glGenOcclusionQueriesNV(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGenProgramsARB(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glGenProgramsARB(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGenProgramsNV(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glGenProgramsNV(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGenQueries(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glGenQueries(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGenQueriesARB(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glGenQueriesARB(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGenRenderbuffersEXT(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glGenRenderbuffersEXT(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public final int glGenSymbolsEXT(final int arg0, final int arg1, final int arg2, final int arg3)
    {
        // Stub method only.
        return 0;
    }

    @Override
    public void glGenTextures(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glGenTextures(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGenVertexArraysAPPLE(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glGenVertexArraysAPPLE(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public final int glGenVertexShadersEXT(final int arg0)
    {
        // Stub method only.
        return 0;
    }

    @Override
    public void glGenerateMipmapEXT(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glGetActiveAttrib(final int arg0, final int arg1, final int arg2, final IntBuffer arg3, final IntBuffer arg4, final IntBuffer arg5,
            final ByteBuffer arg6)
    {
    // Stub method only.

    }

    @Override
    public void glGetActiveAttrib(final int arg0, final int arg1, final int arg2, final int[] arg3, final int arg4, final int[] arg5, final int arg6,
            final int[] arg7, final int arg8, final byte[] arg9, final int arg10)
    {
    // Stub method only.

    }

    @Override
    public void glGetActiveAttribARB(final int arg0, final int arg1, final int arg2, final IntBuffer arg3, final IntBuffer arg4,
            final IntBuffer arg5, final ByteBuffer arg6)
    {
    // Stub method only.

    }

    @Override
    public void glGetActiveAttribARB(final int arg0, final int arg1, final int arg2, final int[] arg3, final int arg4, final int[] arg5,
            final int arg6, final int[] arg7, final int arg8, final byte[] arg9, final int arg10)
    {
    // Stub method only.

    }

    @Override
    public void glGetActiveUniform(final int arg0, final int arg1, final int arg2, final IntBuffer arg3, final IntBuffer arg4, final IntBuffer arg5,
            final ByteBuffer arg6)
    {
    // Stub method only.

    }

    @Override
    public void glGetActiveUniform(final int arg0, final int arg1, final int arg2, final int[] arg3, final int arg4, final int[] arg5,
            final int arg6, final int[] arg7, final int arg8, final byte[] arg9, final int arg10)
    {
    // Stub method only.

    }

    @Override
    public void glGetActiveUniformARB(final int arg0, final int arg1, final int arg2, final IntBuffer arg3, final IntBuffer arg4,
            final IntBuffer arg5, final ByteBuffer arg6)
    {
    // Stub method only.

    }

    @Override
    public void glGetActiveUniformARB(final int arg0, final int arg1, final int arg2, final int[] arg3, final int arg4, final int[] arg5,
            final int arg6, final int[] arg7, final int arg8, final byte[] arg9, final int arg10)
    {
    // Stub method only.

    }

    @Override
    public void glGetActiveVaryingNV(final int arg0, final int arg1, final int arg2, final IntBuffer arg3, final IntBuffer arg4,
            final IntBuffer arg5, final ByteBuffer arg6)
    {
    // Stub method only.

    }

    @Override
    public void glGetActiveVaryingNV(final int arg0, final int arg1, final int arg2, final int[] arg3, final int arg4, final int[] arg5,
            final int arg6, final int[] arg7, final int arg8, final byte[] arg9, final int arg10)
    {
    // Stub method only.

    }

    @Override
    public void glGetArrayObjectfvATI(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetArrayObjectfvATI(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetArrayObjectivATI(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetArrayObjectivATI(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetAttachedObjectsARB(final int arg0, final int arg1, final IntBuffer arg2, final IntBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetAttachedObjectsARB(final int arg0, final int arg1, final int[] arg2, final int arg3, final int[] arg4, final int arg5)
    {
    // Stub method only.

    }

    @Override
    public void glGetAttachedShaders(final int arg0, final int arg1, final IntBuffer arg2, final IntBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetAttachedShaders(final int arg0, final int arg1, final int[] arg2, final int arg3, final int[] arg4, final int arg5)
    {
    // Stub method only.

    }

    @Override
    public final int glGetAttribLocation(final int arg0, final String arg1)
    {
        // Stub method only.
        return 0;
    }

    @Override
    public final int glGetAttribLocationARB(final int arg0, final String arg1)
    {
        // Stub method only.
        return 0;
    }

    @Override
    public void glGetBooleanIndexedvEXT(final int arg0, final int arg1, final ByteBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetBooleanIndexedvEXT(final int arg0, final int arg1, final byte[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetBooleanv(final int arg0, final ByteBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glGetBooleanv(final int arg0, final byte[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetBufferParameteriv(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetBufferParameteriv(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetBufferParameterivARB(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetBufferParameterivARB(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetBufferSubData(final int arg0, final int arg1, final int arg2, final Buffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetBufferSubDataARB(final int arg0, final int arg1, final int arg2, final Buffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetClipPlane(final int arg0, final DoubleBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glGetClipPlane(final int arg0, final double[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetColorTable(final int arg0, final int arg1, final int arg2, final Buffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetColorTable(final int arg0, final int arg1, final int arg2, final long arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetColorTableEXT(final int arg0, final int arg1, final int arg2, final Buffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetColorTableParameterfv(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetColorTableParameterfv(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetColorTableParameterfvEXT(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetColorTableParameterfvEXT(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetColorTableParameteriv(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetColorTableParameteriv(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetColorTableParameterivEXT(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetColorTableParameterivEXT(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetCombinerInputParameterfvNV(final int arg0, final int arg1, final int arg2, final int arg3, final FloatBuffer arg4)
    {
    // Stub method only.

    }

    @Override
    public void glGetCombinerInputParameterfvNV(final int arg0, final int arg1, final int arg2, final int arg3, final float[] arg4, final int arg5)
    {
    // Stub method only.

    }

    @Override
    public void glGetCombinerInputParameterivNV(final int arg0, final int arg1, final int arg2, final int arg3, final IntBuffer arg4)
    {
    // Stub method only.

    }

    @Override
    public void glGetCombinerInputParameterivNV(final int arg0, final int arg1, final int arg2, final int arg3, final int[] arg4, final int arg5)
    {
    // Stub method only.

    }

    @Override
    public void glGetCombinerOutputParameterfvNV(final int arg0, final int arg1, final int arg2, final FloatBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetCombinerOutputParameterfvNV(final int arg0, final int arg1, final int arg2, final float[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glGetCombinerOutputParameterivNV(final int arg0, final int arg1, final int arg2, final IntBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetCombinerOutputParameterivNV(final int arg0, final int arg1, final int arg2, final int[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glGetCombinerStageParameterfvNV(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetCombinerStageParameterfvNV(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetCompressedTexImage(final int arg0, final int arg1, final Buffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetCompressedTexImage(final int arg0, final int arg1, final long arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetConvolutionFilter(final int arg0, final int arg1, final int arg2, final Buffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetConvolutionFilter(final int arg0, final int arg1, final int arg2, final long arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetConvolutionParameterfv(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetConvolutionParameterfv(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetConvolutionParameteriv(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetConvolutionParameteriv(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetDetailTexFuncSGIS(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glGetDetailTexFuncSGIS(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetDoublev(final int arg0, final DoubleBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glGetDoublev(final int arg0, final double[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public final int glGetError()
    {
        // Stub method only.
        return 0;
    }

    @Override
    public void glGetFenceivNV(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetFenceivNV(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetFinalCombinerInputParameterfvNV(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetFinalCombinerInputParameterfvNV(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetFinalCombinerInputParameterivNV(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetFinalCombinerInputParameterivNV(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetFloatv(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glGetFloatv(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetFogFuncSGIS(FloatBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glGetFogFuncSGIS(final float[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public final int glGetFragDataLocationEXT(final int arg0, final ByteBuffer arg1)
    {
        // Stub method only.
        return 0;
    }

    @Override
    public final int glGetFragDataLocationEXT(final int arg0, final byte[] arg1, final int arg2)
    {
        // Stub method only.
        return 0;
    }

    @Override
    public void glGetFragmentLightfvSGIX(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetFragmentLightfvSGIX(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetFragmentLightivSGIX(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetFragmentLightivSGIX(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetFragmentMaterialfvSGIX(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetFragmentMaterialfvSGIX(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetFragmentMaterialivSGIX(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetFragmentMaterialivSGIX(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetFramebufferAttachmentParameterivEXT(final int arg0, final int arg1, final int arg2, final IntBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetFramebufferAttachmentParameterivEXT(final int arg0, final int arg1, final int arg2, final int[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public final int glGetHandleARB(final int arg0)
    {
        // Stub method only.
        return 0;
    }

    @Override
    public void glGetHistogram(final int arg0, final boolean arg1, final int arg2, final int arg3, final Buffer arg4)
    {
    // Stub method only.

    }

    @Override
    public void glGetHistogram(final int arg0, final boolean arg1, final int arg2, final int arg3, final long arg4)
    {
    // Stub method only.

    }

    @Override
    public void glGetHistogramParameterfv(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetHistogramParameterfv(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetHistogramParameteriv(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetHistogramParameteriv(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetImageTransformParameterfvHP(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetImageTransformParameterfvHP(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetImageTransformParameterivHP(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetImageTransformParameterivHP(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetInfoLogARB(final int arg0, final int arg1, final IntBuffer arg2, final ByteBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetInfoLogARB(final int arg0, final int arg1, final int[] arg2, final int arg3, final byte[] arg4, final int arg5)
    {
    // Stub method only.

    }

    @Override
    public final int glGetInstrumentsSGIX()
    {
        // Stub method only.
        return 0;
    }

    @Override
    public void glGetIntegerIndexedvEXT(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetIntegerIndexedvEXT(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetIntegerv(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glGetIntegerv(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetInvariantBooleanvEXT(final int arg0, final int arg1, final ByteBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetInvariantBooleanvEXT(final int arg0, final int arg1, final byte[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetInvariantFloatvEXT(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetInvariantFloatvEXT(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetInvariantIntegervEXT(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetInvariantIntegervEXT(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetLightfv(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetLightfv(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetLightiv(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetLightiv(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetListParameterfvSGIX(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetListParameterfvSGIX(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetListParameterivSGIX(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetListParameterivSGIX(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetLocalConstantBooleanvEXT(final int arg0, final int arg1, final ByteBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetLocalConstantBooleanvEXT(final int arg0, final int arg1, final byte[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetLocalConstantFloatvEXT(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetLocalConstantFloatvEXT(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetLocalConstantIntegervEXT(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetLocalConstantIntegervEXT(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetMapAttribParameterfvNV(final int arg0, final int arg1, final int arg2, final FloatBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetMapAttribParameterfvNV(final int arg0, final int arg1, final int arg2, final float[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glGetMapAttribParameterivNV(final int arg0, final int arg1, final int arg2, final IntBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetMapAttribParameterivNV(final int arg0, final int arg1, final int arg2, final int[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glGetMapControlPointsNV(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final boolean arg5,
            final Buffer arg6)
    {
    // Stub method only.

    }

    @Override
    public void glGetMapParameterfvNV(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetMapParameterfvNV(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetMapParameterivNV(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetMapParameterivNV(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetMapdv(final int arg0, final int arg1, final DoubleBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetMapdv(final int arg0, final int arg1, final double[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetMapfv(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetMapfv(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetMapiv(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetMapiv(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetMaterialfv(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetMaterialfv(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetMaterialiv(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetMaterialiv(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetMinmax(final int arg0, final boolean arg1, final int arg2, final int arg3, final Buffer arg4)
    {
    // Stub method only.

    }

    @Override
    public void glGetMinmax(final int arg0, final boolean arg1, final int arg2, final int arg3, final long arg4)
    {
    // Stub method only.

    }

    @Override
    public void glGetMinmaxParameterfv(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetMinmaxParameterfv(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetMinmaxParameteriv(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetMinmaxParameteriv(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetObjectBufferfvATI(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetObjectBufferfvATI(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetObjectBufferivATI(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetObjectBufferivATI(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetObjectParameterfvARB(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetObjectParameterfvARB(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetObjectParameterivARB(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetObjectParameterivARB(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetOcclusionQueryivNV(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetOcclusionQueryivNV(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetOcclusionQueryuivNV(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetOcclusionQueryuivNV(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetPixelMapfv(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glGetPixelMapfv(final int arg0, final long arg1)
    {
    // Stub method only.

    }

    @Override
    public void glGetPixelMapfv(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetPixelMapuiv(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glGetPixelMapuiv(final int arg0, final long arg1)
    {
    // Stub method only.

    }

    @Override
    public void glGetPixelMapuiv(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetPixelMapusv(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glGetPixelMapusv(final int arg0, final long arg1)
    {
    // Stub method only.

    }

    @Override
    public void glGetPixelMapusv(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetPixelTexGenParameterfvSGIS(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glGetPixelTexGenParameterfvSGIS(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetPixelTexGenParameterivSGIS(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glGetPixelTexGenParameterivSGIS(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetPolygonStipple(final ByteBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glGetPolygonStipple(final long arg0)
    {
    // Stub method only.

    }

    @Override
    public void glGetPolygonStipple(final byte[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glGetProgramEnvParameterIivNV(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetProgramEnvParameterIivNV(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetProgramEnvParameterIuivNV(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetProgramEnvParameterIuivNV(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetProgramEnvParameterdvARB(final int arg0, final int arg1, final DoubleBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetProgramEnvParameterdvARB(final int arg0, final int arg1, final double[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetProgramEnvParameterfvARB(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetProgramEnvParameterfvARB(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetProgramInfoLog(final int arg0, final int arg1, final IntBuffer arg2, final ByteBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetProgramInfoLog(final int arg0, final int arg1, final int[] arg2, final int arg3, final byte[] arg4, final int arg5)
    {
    // Stub method only.

    }

    @Override
    public void glGetProgramLocalParameterIivNV(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetProgramLocalParameterIivNV(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetProgramLocalParameterIuivNV(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetProgramLocalParameterIuivNV(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetProgramLocalParameterdvARB(final int arg0, final int arg1, final DoubleBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetProgramLocalParameterdvARB(final int arg0, final int arg1, final double[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetProgramLocalParameterfvARB(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetProgramLocalParameterfvARB(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetProgramNamedParameterdvNV(final int arg0, final int arg1, final String arg2, final DoubleBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetProgramNamedParameterdvNV(final int arg0, final int arg1, final String arg2, final double[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glGetProgramNamedParameterfvNV(final int arg0, final int arg1, final String arg2, final FloatBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetProgramNamedParameterfvNV(final int arg0, final int arg1, final String arg2, final float[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glGetProgramParameterdvNV(final int arg0, final int arg1, final int arg2, final DoubleBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetProgramParameterdvNV(final int arg0, final int arg1, final int arg2, final double[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glGetProgramParameterfvNV(final int arg0, final int arg1, final int arg2, final FloatBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetProgramParameterfvNV(final int arg0, final int arg1, final int arg2, final float[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glGetProgramStringARB(final int arg0, final int arg1, final Buffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetProgramStringNV(final int arg0, final int arg1, final ByteBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetProgramStringNV(final int arg0, final int arg1, final byte[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetProgramiv(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetProgramiv(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetProgramivARB(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetProgramivARB(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetProgramivNV(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetProgramivNV(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetQueryObjecti64vEXT(final int arg0, final int arg1, LongBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetQueryObjecti64vEXT(final int arg0, final int arg1, final long[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetQueryObjectiv(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetQueryObjectiv(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetQueryObjectivARB(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetQueryObjectivARB(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetQueryObjectui64vEXT(final int arg0, final int arg1, LongBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetQueryObjectui64vEXT(final int arg0, final int arg1, final long[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetQueryObjectuiv(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetQueryObjectuiv(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetQueryObjectuivARB(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetQueryObjectuivARB(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetQueryiv(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetQueryiv(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetQueryivARB(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetQueryivARB(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetRenderbufferParameterivEXT(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetRenderbufferParameterivEXT(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetSeparableFilter(final int arg0, final int arg1, final int arg2, final Buffer arg3, final Buffer arg4, final Buffer arg5)
    {
    // Stub method only.

    }

    @Override
    public void glGetSeparableFilter(final int arg0, final int arg1, final int arg2, final long arg3, final long arg4, final long arg5)
    {
    // Stub method only.

    }

    @Override
    public void glGetShaderInfoLog(final int arg0, final int arg1, final IntBuffer arg2, final ByteBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetShaderInfoLog(final int arg0, final int arg1, final int[] arg2, final int arg3, final byte[] arg4, final int arg5)
    {
    // Stub method only.

    }

    @Override
    public void glGetShaderSource(final int arg0, final int arg1, final IntBuffer arg2, final ByteBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetShaderSource(final int arg0, final int arg1, final int[] arg2, final int arg3, final byte[] arg4, final int arg5)
    {
    // Stub method only.

    }

    @Override
    public void glGetShaderSourceARB(final int arg0, final int arg1, final IntBuffer arg2, final ByteBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetShaderSourceARB(final int arg0, final int arg1, final int[] arg2, final int arg3, final byte[] arg4, final int arg5)
    {
    // Stub method only.

    }

    @Override
    public void glGetShaderiv(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetShaderiv(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetSharpenTexFuncSGIS(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glGetSharpenTexFuncSGIS(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public final String glGetString(final int arg0)
    {
        // Stub method only.
        return null;
    }

    @Override
    public void glGetTexBumpParameterfvATI(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glGetTexBumpParameterfvATI(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetTexBumpParameterivATI(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glGetTexBumpParameterivATI(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetTexEnvfv(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetTexEnvfv(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetTexEnviv(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetTexEnviv(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetTexFilterFuncSGIS(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetTexFilterFuncSGIS(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetTexGendv(final int arg0, final int arg1, final DoubleBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetTexGendv(final int arg0, final int arg1, final double[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetTexGenfv(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetTexGenfv(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetTexGeniv(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetTexGeniv(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetTexImage(final int arg0, final int arg1, final int arg2, final int arg3, final Buffer arg4)
    {
    // Stub method only.

    }

    @Override
    public void glGetTexImage(final int arg0, final int arg1, final int arg2, final int arg3, final long arg4)
    {
    // Stub method only.

    }

    @Override
    public void glGetTexLevelParameterfv(final int arg0, final int arg1, final int arg2, final FloatBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetTexLevelParameterfv(final int arg0, final int arg1, final int arg2, final float[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glGetTexLevelParameteriv(final int arg0, final int arg1, final int arg2, final IntBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetTexLevelParameteriv(final int arg0, final int arg1, final int arg2, final int[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glGetTexParameterIivEXT(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetTexParameterIivEXT(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetTexParameterIuivEXT(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetTexParameterIuivEXT(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetTexParameterfv(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetTexParameterfv(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetTexParameteriv(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetTexParameteriv(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetTrackMatrixivNV(final int arg0, final int arg1, final int arg2, final IntBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetTrackMatrixivNV(final int arg0, final int arg1, final int arg2, final int[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glGetTransformFeedbackVaryingNV(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetTransformFeedbackVaryingNV(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public final int glGetUniformBufferSizeEXT(final int arg0, final int arg1)
    {
        // Stub method only.
        return 0;
    }

    @Override
    public final int glGetUniformLocation(final int arg0, final String arg1)
    {
        // Stub method only.
        return 0;
    }

    @Override
    public final int glGetUniformLocationARB(final int arg0, final String arg1)
    {
        // Stub method only.
        return 0;
    }

    @Override
    public final int glGetUniformOffsetEXT(final int arg0, final int arg1)
    {
        // Stub method only.
        return 0;
    }

    @Override
    public void glGetUniformfv(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetUniformfv(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetUniformfvARB(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetUniformfvARB(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetUniformiv(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetUniformiv(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetUniformivARB(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetUniformivARB(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetUniformuivEXT(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetUniformuivEXT(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetVariantArrayObjectfvATI(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetVariantArrayObjectfvATI(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetVariantArrayObjectivATI(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetVariantArrayObjectivATI(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetVariantBooleanvEXT(final int arg0, final int arg1, final ByteBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetVariantBooleanvEXT(final int arg0, final int arg1, final byte[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetVariantFloatvEXT(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetVariantFloatvEXT(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetVariantIntegervEXT(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetVariantIntegervEXT(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public final int glGetVaryingLocationNV(final int arg0, final ByteBuffer arg1)
    {
        // Stub method only.
        return 0;
    }

    @Override
    public final int glGetVaryingLocationNV(final int arg0, final byte[] arg1, final int arg2)
    {
        // Stub method only.
        return 0;
    }

    @Override
    public void glGetVertexAttribArrayObjectfvATI(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetVertexAttribArrayObjectfvATI(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetVertexAttribArrayObjectivATI(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetVertexAttribArrayObjectivATI(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetVertexAttribIivEXT(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetVertexAttribIivEXT(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetVertexAttribIuivEXT(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetVertexAttribIuivEXT(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetVertexAttribdv(final int arg0, final int arg1, final DoubleBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetVertexAttribdv(final int arg0, final int arg1, final double[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetVertexAttribdvARB(final int arg0, final int arg1, final DoubleBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetVertexAttribdvARB(final int arg0, final int arg1, final double[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetVertexAttribdvNV(final int arg0, final int arg1, final DoubleBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetVertexAttribdvNV(final int arg0, final int arg1, final double[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetVertexAttribfv(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetVertexAttribfv(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetVertexAttribfvARB(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetVertexAttribfvARB(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetVertexAttribfvNV(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetVertexAttribfvNV(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetVertexAttribiv(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetVertexAttribiv(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetVertexAttribivARB(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetVertexAttribivARB(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGetVertexAttribivNV(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glGetVertexAttribivNV(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glGlobalAlphaFactorbSUN(final byte arg0)
    {
    // Stub method only.

    }

    @Override
    public void glGlobalAlphaFactordSUN(final double arg0)
    {
    // Stub method only.

    }

    @Override
    public void glGlobalAlphaFactorfSUN(final float arg0)
    {
    // Stub method only.

    }

    @Override
    public void glGlobalAlphaFactoriSUN(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glGlobalAlphaFactorsSUN(final short arg0)
    {
    // Stub method only.

    }

    @Override
    public void glGlobalAlphaFactorubSUN(final byte arg0)
    {
    // Stub method only.

    }

    @Override
    public void glGlobalAlphaFactoruiSUN(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glGlobalAlphaFactorusSUN(final short arg0)
    {
    // Stub method only.

    }

    @Override
    public void glHint(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glHintPGI(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glHistogram(final int arg0, final int arg1, final int arg2, final boolean arg3)
    {
    // Stub method only.

    }

    @Override
    public void glIglooInterfaceSGIX(final int arg0, final Buffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glImageTransformParameterfHP(final int arg0, final int arg1, final float arg2)
    {
    // Stub method only.

    }

    @Override
    public void glImageTransformParameterfvHP(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glImageTransformParameterfvHP(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glImageTransformParameteriHP(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glImageTransformParameterivHP(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glImageTransformParameterivHP(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glIndexFuncEXT(final int arg0, final float arg1)
    {
    // Stub method only.

    }

    @Override
    public void glIndexMask(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glIndexMaterialEXT(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glIndexPointer(final int arg0, final int arg1, final Buffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glIndexd(final double arg0)
    {
    // Stub method only.

    }

    @Override
    public void glIndexdv(final DoubleBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glIndexdv(final double[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glIndexf(final float arg0)
    {
    // Stub method only.

    }

    @Override
    public void glIndexfv(FloatBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glIndexfv(final float[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glIndexi(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glIndexiv(final IntBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glIndexiv(final int[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glIndexs(final short arg0)
    {
    // Stub method only.

    }

    @Override
    public void glIndexsv(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glIndexsv(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glIndexub(final byte arg0)
    {
    // Stub method only.

    }

    @Override
    public void glIndexubv(final ByteBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glIndexubv(final byte[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glInitNames()
    {
    // Stub method only.

    }

    @Override
    public void glInsertComponentEXT(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glInstrumentsBufferSGIX(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glInstrumentsBufferSGIX(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glInterleavedArrays(final int arg0, final int arg1, final Buffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glInterleavedArrays(final int arg0, final int arg1, final long arg2)
    {
    // Stub method only.

    }

    @Override
    public boolean glIsAsyncMarkerSGIX(final int arg0)
    {
        // Stub method only.
        return false;
    }

    @Override
    public boolean glIsBuffer(final int arg0)
    {
        // Stub method only.
        return false;
    }

    @Override
    public boolean glIsBufferARB(final int arg0)
    {
        // Stub method only.
        return false;
    }

    @Override
    public boolean glIsEnabled(final int arg0)
    {
        // Stub method only.
        return false;
    }

    @Override
    public boolean glIsEnabledIndexedEXT(final int arg0, final int arg1)
    {
        // Stub method only.
        return false;
    }

    @Override
    public boolean glIsFenceAPPLE(final int arg0)
    {
        // Stub method only.
        return false;
    }

    @Override
    public boolean glIsFenceNV(final int arg0)
    {
        // Stub method only.
        return false;
    }

    @Override
    public boolean glIsFramebufferEXT(final int arg0)
    {
        // Stub method only.
        return false;
    }

    @Override
    public boolean glIsList(final int arg0)
    {
        // Stub method only.
        return false;
    }

    @Override
    public boolean glIsObjectBufferATI(final int arg0)
    {
        // Stub method only.
        return false;
    }

    @Override
    public boolean glIsOcclusionQueryNV(final int arg0)
    {
        // Stub method only.
        return false;
    }

    @Override
    public boolean glIsProgram(final int arg0)
    {
        // Stub method only.
        return false;
    }

    @Override
    public boolean glIsProgramARB(final int arg0)
    {
        // Stub method only.
        return false;
    }

    @Override
    public boolean glIsProgramNV(final int arg0)
    {
        // Stub method only.
        return false;
    }

    @Override
    public boolean glIsQuery(final int arg0)
    {
        // Stub method only.
        return false;
    }

    @Override
    public boolean glIsQueryARB(final int arg0)
    {
        // Stub method only.
        return false;
    }

    @Override
    public boolean glIsRenderbufferEXT(final int arg0)
    {
        // Stub method only.
        return false;
    }

    @Override
    public boolean glIsShader(final int arg0)
    {
        // Stub method only.
        return false;
    }

    @Override
    public boolean glIsTexture(final int arg0)
    {
        // Stub method only.
        return false;
    }

    @Override
    public boolean glIsVariantEnabledEXT(final int arg0, final int arg1)
    {
        // Stub method only.
        return false;
    }

    @Override
    public boolean glIsVertexArrayAPPLE(final int arg0)
    {
        // Stub method only.
        return false;
    }

    @Override
    public boolean glIsVertexAttribEnabledAPPLE(final int arg0, final int arg1)
    {
        // Stub method only.
        return false;
    }

    @Override
    public void glLightEnviSGIX(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glLightModelf(final int arg0, final float arg1)
    {
    // Stub method only.

    }

    @Override
    public void glLightModelfv(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glLightModelfv(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glLightModeli(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glLightModeliv(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glLightModeliv(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glLightf(final int arg0, final int arg1, final float arg2)
    {
    // Stub method only.

    }

    @Override
    public void glLightfv(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glLightfv(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
        addMethodCall("glLightfv", new Object[] {arg0, arg1, arg2});

    }

    @Override
    public void glLighti(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glLightiv(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glLightiv(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glLineStipple(final int arg0, final short arg1)
    {
    // Stub method only.

    }

    @Override
    public void glLineWidth(final float arg0)
    {
    // Stub method only.

    }

    @Override
    public void glLinkProgram(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glLinkProgramARB(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glListBase(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glListParameterfSGIX(final int arg0, final int arg1, final float arg2)
    {
    // Stub method only.

    }

    @Override
    public void glListParameterfvSGIX(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glListParameterfvSGIX(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glListParameteriSGIX(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glListParameterivSGIX(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glListParameterivSGIX(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glLoadIdentity()
    {
        addMethodCall("glLoadIdentity", null);

    }

    @Override
    public void glLoadIdentityDeformationMapSGIX(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glLoadMatrixd(final DoubleBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glLoadMatrixd(final double[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glLoadMatrixf(FloatBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glLoadMatrixf(final float[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glLoadName(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glLoadProgramNV(final int arg0, final int arg1, final int arg2, final String arg3)
    {
    // Stub method only.

    }

    @Override
    public void glLoadTransposeMatrixd(final DoubleBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glLoadTransposeMatrixd(final double[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glLoadTransposeMatrixf(FloatBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glLoadTransposeMatrixf(final float[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glLockArraysEXT(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glLogicOp(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glMap1d(final int arg0, final double arg1, final double arg2, final int arg3, final int arg4, final DoubleBuffer arg5)
    {
    // Stub method only.

    }

    @Override
    public void glMap1d(final int arg0, final double arg1, final double arg2, final int arg3, final int arg4, final double[] arg5, final int arg6)
    {
    // Stub method only.

    }

    @Override
    public void glMap1f(final int arg0, final float arg1, final float arg2, final int arg3, final int arg4, final FloatBuffer arg5)
    {
    // Stub method only.

    }

    @Override
    public void glMap1f(final int arg0, final float arg1, final float arg2, final int arg3, final int arg4, final float[] arg5, final int arg6)
    {
    // Stub method only.

    }

    @Override
    public void glMap2d(final int arg0, final double arg1, final double arg2, final int arg3, final int arg4, final double arg5, final double arg6,
            final int arg7, final int arg8, final DoubleBuffer arg9)
    {
    // Stub method only.

    }

    @Override
    public void glMap2d(final int arg0, final double arg1, final double arg2, final int arg3, final int arg4, final double arg5, final double arg6,
            final int arg7, final int arg8, final double[] arg9, final int arg10)
    {
    // Stub method only.

    }

    @Override
    public void glMap2f(final int arg0, final float arg1, final float arg2, final int arg3, final int arg4, final float arg5, final float arg6,
            final int arg7, final int arg8, final FloatBuffer arg9)
    {
    // Stub method only.

    }

    @Override
    public void glMap2f(final int arg0, final float arg1, final float arg2, final int arg3, final int arg4, final float arg5, final float arg6,
            final int arg7, final int arg8, final float[] arg9, final int arg10)
    {
    // Stub method only.

    }

    @Override
    public ByteBuffer glMapBuffer(final int arg0, final int arg1)
    {
        // Stub method only.
        return null;
    }

    @Override
    public ByteBuffer glMapBufferARB(final int arg0, final int arg1)
    {
        // Stub method only.
        return null;
    }

    @Override
    public void glMapControlPointsNV(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5, final int arg6,
            final boolean arg7, final Buffer arg8)
    {
    // Stub method only.

    }

    @Override
    public void glMapGrid1d(final int arg0, final double arg1, final double arg2)
    {
    // Stub method only.

    }

    @Override
    public void glMapGrid1f(final int arg0, final float arg1, final float arg2)
    {
    // Stub method only.

    }

    @Override
    public void glMapGrid2d(final int arg0, final double arg1, final double arg2, final int arg3, final double arg4, final double arg5)
    {
    // Stub method only.

    }

    @Override
    public void glMapGrid2f(final int arg0, final float arg1, final float arg2, final int arg3, final float arg4, final float arg5)
    {
    // Stub method only.

    }

    @Override
    public void glMapParameterfvNV(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glMapParameterfvNV(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glMapParameterivNV(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glMapParameterivNV(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glMapVertexAttrib1dAPPLE(final int arg0, final int arg1, final double arg2, final double arg3, final int arg4, final int arg5,
            final DoubleBuffer arg6)
    {
    // Stub method only.

    }

    @Override
    public void glMapVertexAttrib1dAPPLE(final int arg0, final int arg1, final double arg2, final double arg3, final int arg4, final int arg5,
            final double[] arg6, final int arg7)
    {
    // Stub method only.

    }

    @Override
    public void glMapVertexAttrib1fAPPLE(final int arg0, final int arg1, final float arg2, final float arg3, final int arg4, final int arg5,
            final FloatBuffer arg6)
    {
    // Stub method only.

    }

    @Override
    public void glMapVertexAttrib1fAPPLE(final int arg0, final int arg1, final float arg2, final float arg3, final int arg4, final int arg5,
            final float[] arg6, final int arg7)
    {
    // Stub method only.

    }

    @Override
    public void glMapVertexAttrib2dAPPLE(final int arg0, final int arg1, final double arg2, final double arg3, final int arg4, final int arg5,
            final double arg6, final double arg7, final int arg8, final int arg9, final DoubleBuffer arg10)
    {
    // Stub method only.

    }

    @Override
    public void glMapVertexAttrib2dAPPLE(final int arg0, final int arg1, final double arg2, final double arg3, final int arg4, final int arg5,
            final double arg6, final double arg7, final int arg8, final int arg9, final double[] arg10, final int arg11)
    {
    // Stub method only.

    }

    @Override
    public void glMapVertexAttrib2fAPPLE(final int arg0, final int arg1, final float arg2, final float arg3, final int arg4, final int arg5,
            final float arg6, final float arg7, final int arg8, final int arg9, FloatBuffer arg10)
    {
    // Stub method only.

    }

    @Override
    public void glMapVertexAttrib2fAPPLE(final int arg0, final int arg1, final float arg2, final float arg3, final int arg4, final int arg5,
            final float arg6, final float arg7, final int arg8, final int arg9, float[] arg10, final int arg11)
    {
    // Stub method only.

    }

    @Override
    public void glMaterialf(final int arg0, final int arg1, final float arg2)
    {
    // Stub method only.

    }

    @Override
    public void glMaterialfv(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glMaterialfv(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glMateriali(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glMaterialiv(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glMaterialiv(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glMatrixIndexPointerARB(final int arg0, final int arg1, final int arg2, final Buffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glMatrixIndexPointerARB(final int arg0, final int arg1, final int arg2, final long arg3)
    {
    // Stub method only.

    }

    @Override
    public void glMatrixIndexubvARB(final int arg0, final ByteBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glMatrixIndexubvARB(final int arg0, final byte[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glMatrixIndexuivARB(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glMatrixIndexuivARB(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glMatrixIndexusvARB(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glMatrixIndexusvARB(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glMatrixMode(final int arg0)
    {
        addMethodCall("glMatrixMode", new Object[] {arg0});

    }

    @Override
    public void glMinmax(final int arg0, final int arg1, final boolean arg2)
    {
    // Stub method only.

    }

    @Override
    public void glMultMatrixd(final DoubleBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glMultMatrixd(final double[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glMultMatrixf(FloatBuffer arg0)
    {
        addMethodCall("glMultMatrixf", new Object[] {arg0});
    }

    @Override
    public void glMultMatrixf(final float[] arg0, final int arg1)
    {
        addMethodCall("glMultMatrixf", new Object[] {arg0, arg1});
    }

    @Override
    public void glMultTransposeMatrixd(final DoubleBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glMultTransposeMatrixd(final double[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glMultTransposeMatrixf(FloatBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glMultTransposeMatrixf(final float[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glMultiDrawArrays(final int arg0, final IntBuffer arg1, final IntBuffer arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glMultiDrawArrays(final int arg0, final int[] arg1, final int arg2, final int[] arg3, final int arg4, final int arg5)
    {
    // Stub method only.

    }

    @Override
    public void glMultiDrawArraysEXT(final int arg0, final IntBuffer arg1, final IntBuffer arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glMultiDrawArraysEXT(final int arg0, final int[] arg1, final int arg2, final int[] arg3, final int arg4, final int arg5)
    {
    // Stub method only.

    }

    @Override
    public void glMultiDrawElementArrayAPPLE(final int arg0, final IntBuffer arg1, final IntBuffer arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glMultiDrawElementArrayAPPLE(final int arg0, final int[] arg1, final int arg2, final int[] arg3, final int arg4, final int arg5)
    {
    // Stub method only.

    }

    @Override
    public void glMultiDrawElements(final int arg0, final IntBuffer arg1, final int arg2, final Buffer[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glMultiDrawElements(final int arg0, final int[] arg1, final int arg2, final int arg3, final Buffer[] arg4, final int arg5)
    {
    // Stub method only.

    }

    @Override
    public void glMultiDrawElementsEXT(final int arg0, final IntBuffer arg1, final int arg2, final Buffer[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glMultiDrawElementsEXT(final int arg0, final int[] arg1, final int arg2, final int arg3, final Buffer[] arg4, final int arg5)
    {
    // Stub method only.

    }

    @Override
    public void glMultiDrawRangeElementArrayAPPLE(final int arg0, final int arg1, final int arg2, final IntBuffer arg3, final IntBuffer arg4,
            final int arg5)
    {
    // Stub method only.

    }

    @Override
    public void glMultiDrawRangeElementArrayAPPLE(final int arg0, final int arg1, final int arg2, final int[] arg3, final int arg4, final int[] arg5,
            final int arg6, final int arg7)
    {
    // Stub method only.

    }

    @Override
    public void glMultiModeDrawArraysIBM(final IntBuffer arg0, final IntBuffer arg1, final IntBuffer arg2, final int arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glMultiModeDrawArraysIBM(final int[] arg0, final int arg1, final int[] arg2, final int arg3, final int[] arg4, final int arg5,
            final int arg6, final int arg7)
    {
    // Stub method only.

    }

    @Override
    public void glMultiModeDrawElementsIBM(final IntBuffer arg0, final IntBuffer arg1, final int arg2, final Buffer[] arg3, final int arg4,
            final int arg5)
    {
    // Stub method only.

    }

    @Override
    public void glMultiModeDrawElementsIBM(final int[] arg0, final int arg1, final int[] arg2, final int arg3, final int arg4, final Buffer[] arg5,
            final int arg6, final int arg7)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord1d(final int arg0, final double arg1)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord1dv(final int arg0, final DoubleBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord1dv(final int arg0, final double[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord1f(final int arg0, final float arg1)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord1fv(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord1fv(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord1hNV(final int arg0, final short arg1)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord1hvNV(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord1hvNV(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord1i(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord1iv(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord1iv(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord1s(final int arg0, final short arg1)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord1sv(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord1sv(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord2d(final int arg0, final double arg1, final double arg2)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord2dv(final int arg0, final DoubleBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord2dv(final int arg0, final double[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord2f(final int arg0, final float arg1, final float arg2)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord2fv(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord2fv(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord2hNV(final int arg0, final short arg1, final short arg2)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord2hvNV(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord2hvNV(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord2i(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord2iv(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord2iv(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord2s(final int arg0, final short arg1, final short arg2)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord2sv(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord2sv(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord3d(final int arg0, final double arg1, final double arg2, final double arg3)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord3dv(final int arg0, final DoubleBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord3dv(final int arg0, final double[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord3f(final int arg0, final float arg1, final float arg2, final float arg3)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord3fv(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord3fv(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord3hNV(final int arg0, final short arg1, final short arg2, final short arg3)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord3hvNV(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord3hvNV(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord3i(final int arg0, final int arg1, final int arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord3iv(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord3iv(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord3s(final int arg0, final short arg1, final short arg2, final short arg3)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord3sv(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord3sv(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord4d(final int arg0, final double arg1, final double arg2, final double arg3, final double arg4)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord4dv(final int arg0, final DoubleBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord4dv(final int arg0, final double[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord4f(final int arg0, final float arg1, final float arg2, final float arg3, final float arg4)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord4fv(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord4fv(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord4hNV(final int arg0, final short arg1, final short arg2, final short arg3, final short arg4)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord4hvNV(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord4hvNV(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord4i(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord4iv(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord4iv(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord4s(final int arg0, final short arg1, final short arg2, final short arg3, final short arg4)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord4sv(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glMultiTexCoord4sv(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public final int glNewBufferRegion(final int arg0)
    {
        // Stub method only.
        return 0;
    }

    @Override
    public void glNewList(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public final int glNewObjectBufferATI(final int arg0, final Buffer arg1, final int arg2)
    {
        // Stub method only.
        return 0;
    }

    @Override
    public void glNormal3b(final byte arg0, final byte arg1, final byte arg2)
    {
    // Stub method only.

    }

    @Override
    public void glNormal3bv(final ByteBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glNormal3bv(final byte[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glNormal3d(final double arg0, final double arg1, final double arg2)
    {
    // Stub method only.

    }

    @Override
    public void glNormal3dv(final DoubleBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glNormal3dv(final double[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glNormal3f(final float arg0, final float arg1, final float arg2)
    {
        addMethodCall("glNormal3f", new Object[] {arg0, arg1, arg2});

    }

    @Override
    public void glNormal3fVertex3fSUN(final float arg0, final float arg1, final float arg2, final float arg3, final float arg4, final float arg5)
    {
    // Stub method only.

    }

    @Override
    public void glNormal3fVertex3fvSUN(FloatBuffer arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glNormal3fVertex3fvSUN(final float[] arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glNormal3fv(FloatBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glNormal3fv(final float[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glNormal3hNV(final short arg0, final short arg1, final short arg2)
    {
    // Stub method only.

    }

    @Override
    public void glNormal3hvNV(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glNormal3hvNV(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glNormal3i(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glNormal3iv(final IntBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glNormal3iv(final int[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glNormal3s(final short arg0, final short arg1, final short arg2)
    {
    // Stub method only.

    }

    @Override
    public void glNormal3sv(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glNormal3sv(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glNormalPointer(final int arg0, final int arg1, final Buffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glNormalPointer(final int arg0, final int arg1, final long arg2)
    {
    // Stub method only.

    }

    @Override
    public void glNormalStream3bATI(final int arg0, final byte arg1, final byte arg2, final byte arg3)
    {
    // Stub method only.

    }

    @Override
    public void glNormalStream3bvATI(final int arg0, final ByteBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glNormalStream3bvATI(final int arg0, final byte[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glNormalStream3dATI(final int arg0, final double arg1, final double arg2, final double arg3)
    {
    // Stub method only.

    }

    @Override
    public void glNormalStream3dvATI(final int arg0, final DoubleBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glNormalStream3dvATI(final int arg0, final double[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glNormalStream3fATI(final int arg0, final float arg1, final float arg2, final float arg3)
    {
    // Stub method only.

    }

    @Override
    public void glNormalStream3fvATI(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glNormalStream3fvATI(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glNormalStream3iATI(final int arg0, final int arg1, final int arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glNormalStream3ivATI(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glNormalStream3ivATI(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glNormalStream3sATI(final int arg0, final short arg1, final short arg2, final short arg3)
    {
    // Stub method only.

    }

    @Override
    public void glNormalStream3svATI(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glNormalStream3svATI(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glOrtho(final double arg0, final double arg1, final double arg2, final double arg3, final double arg4, final double arg5)
    {
    // Stub method only.

    }

    @Override
    public void glPNTrianglesfATI(final int arg0, final float arg1)
    {
    // Stub method only.

    }

    @Override
    public void glPNTrianglesiATI(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glPassTexCoordATI(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glPassThrough(final float arg0)
    {
    // Stub method only.

    }

    @Override
    public void glPixelDataRangeNV(final int arg0, final int arg1, final Buffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glPixelMapfv(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glPixelMapfv(final int arg0, final int arg1, final long arg2)
    {
    // Stub method only.

    }

    @Override
    public void glPixelMapfv(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glPixelMapuiv(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glPixelMapuiv(final int arg0, final int arg1, final long arg2)
    {
    // Stub method only.

    }

    @Override
    public void glPixelMapuiv(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glPixelMapusv(final int arg0, final int arg1, final ShortBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glPixelMapusv(final int arg0, final int arg1, final long arg2)
    {
    // Stub method only.

    }

    @Override
    public void glPixelMapusv(final int arg0, final int arg1, final short[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glPixelStoref(final int arg0, final float arg1)
    {
    // Stub method only.

    }

    @Override
    public void glPixelStorei(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glPixelTexGenParameterfSGIS(final int arg0, final float arg1)
    {
    // Stub method only.

    }

    @Override
    public void glPixelTexGenParameterfvSGIS(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glPixelTexGenParameterfvSGIS(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glPixelTexGenParameteriSGIS(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glPixelTexGenParameterivSGIS(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glPixelTexGenParameterivSGIS(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glPixelTexGenSGIX(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glPixelTransferf(final int arg0, final float arg1)
    {
    // Stub method only.

    }

    @Override
    public void glPixelTransferi(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glPixelTransformParameterfEXT(final int arg0, final int arg1, final float arg2)
    {
    // Stub method only.

    }

    @Override
    public void glPixelTransformParameterfvEXT(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glPixelTransformParameterfvEXT(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glPixelTransformParameteriEXT(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glPixelTransformParameterivEXT(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glPixelTransformParameterivEXT(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glPixelZoom(final float arg0, final float arg1)
    {
    // Stub method only.

    }

    @Override
    public void glPointParameterf(final int arg0, final float arg1)
    {
    // Stub method only.

    }

    @Override
    public void glPointParameterfARB(final int arg0, final float arg1)
    {
    // Stub method only.

    }

    @Override
    public void glPointParameterfEXT(final int arg0, final float arg1)
    {
    // Stub method only.

    }

    @Override
    public void glPointParameterfSGIS(final int arg0, final float arg1)
    {
    // Stub method only.

    }

    @Override
    public void glPointParameterfv(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glPointParameterfv(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glPointParameterfvARB(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glPointParameterfvARB(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glPointParameterfvEXT(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glPointParameterfvEXT(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glPointParameterfvSGIS(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glPointParameterfvSGIS(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glPointParameteri(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glPointParameteriNV(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glPointParameteriv(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glPointParameteriv(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glPointParameterivNV(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glPointParameterivNV(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glPointSize(final float arg0)
    {
    // Stub method only.

    }

    @Override
    public final int glPollAsyncSGIX(final IntBuffer arg0)
    {
        // Stub method only.
        return 0;
    }

    @Override
    public final int glPollAsyncSGIX(final int[] arg0, final int arg1)
    {
        // Stub method only.
        return 0;
    }

    @Override
    public final int glPollInstrumentsSGIX(final IntBuffer arg0)
    {
        // Stub method only.
        return 0;
    }

    @Override
    public final int glPollInstrumentsSGIX(final int[] arg0, final int arg1)
    {
        // Stub method only.
        return 0;
    }

    @Override
    public void glPolygonMode(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glPolygonOffset(final float arg0, final float arg1)
    {
    // Stub method only.

    }

    @Override
    public void glPolygonStipple(final ByteBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glPolygonStipple(final long arg0)
    {
    // Stub method only.

    }

    @Override
    public void glPolygonStipple(final byte[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glPopAttrib()
    {
    // Stub method only.

    }

    @Override
    public void glPopClientAttrib()
    {
    // Stub method only.

    }

    @Override
    public void glPopMatrix()
    {
        addMethodCall("glPopMatrix", null);

    }

    @Override
    public void glPopName()
    {
        addMethodCall("glPopName", null);

    }

    @Override
    public void glPrimitiveRestartIndexNV(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glPrimitiveRestartNV()
    {
    // Stub method only.

    }

    @Override
    public void glPrioritizeTextures(final int arg0, final IntBuffer arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glPrioritizeTextures(final int arg0, final int[] arg1, final int arg2, final float[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glProgramBufferParametersIivNV(final int arg0, final int arg1, final int arg2, final int arg3, final IntBuffer arg4)
    {
    // Stub method only.

    }

    @Override
    public void glProgramBufferParametersIivNV(final int arg0, final int arg1, final int arg2, final int arg3, final int[] arg4, final int arg5)
    {
    // Stub method only.

    }

    @Override
    public void glProgramBufferParametersIuivNV(final int arg0, final int arg1, final int arg2, final int arg3, final IntBuffer arg4)
    {
    // Stub method only.

    }

    @Override
    public void glProgramBufferParametersIuivNV(final int arg0, final int arg1, final int arg2, final int arg3, final int[] arg4, final int arg5)
    {
    // Stub method only.

    }

    @Override
    public void glProgramBufferParametersfvNV(final int arg0, final int arg1, final int arg2, final int arg3, final FloatBuffer arg4)
    {
    // Stub method only.

    }

    @Override
    public void glProgramBufferParametersfvNV(final int arg0, final int arg1, final int arg2, final int arg3, final float[] arg4, final int arg5)
    {
    // Stub method only.

    }

    @Override
    public void glProgramEnvParameter4dARB(final int arg0, final int arg1, final double arg2, final double arg3, final double arg4, final double arg5)
    {
    // Stub method only.

    }

    @Override
    public void glProgramEnvParameter4dvARB(final int arg0, final int arg1, final DoubleBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glProgramEnvParameter4dvARB(final int arg0, final int arg1, final double[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glProgramEnvParameter4fARB(final int arg0, final int arg1, final float arg2, final float arg3, final float arg4, final float arg5)
    {
    // Stub method only.

    }

    @Override
    public void glProgramEnvParameter4fvARB(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glProgramEnvParameter4fvARB(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glProgramEnvParameterI4iNV(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5)
    {
    // Stub method only.

    }

    @Override
    public void glProgramEnvParameterI4ivNV(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glProgramEnvParameterI4ivNV(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glProgramEnvParameterI4uiNV(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5)
    {
    // Stub method only.

    }

    @Override
    public void glProgramEnvParameterI4uivNV(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glProgramEnvParameterI4uivNV(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glProgramEnvParameters4fvEXT(final int arg0, final int arg1, final int arg2, final FloatBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glProgramEnvParameters4fvEXT(final int arg0, final int arg1, final int arg2, final float[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glProgramEnvParametersI4ivNV(final int arg0, final int arg1, final int arg2, final IntBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glProgramEnvParametersI4ivNV(final int arg0, final int arg1, final int arg2, final int[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glProgramEnvParametersI4uivNV(final int arg0, final int arg1, final int arg2, final IntBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glProgramEnvParametersI4uivNV(final int arg0, final int arg1, final int arg2, final int[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glProgramLocalParameter4dARB(final int arg0, final int arg1, final double arg2, final double arg3, final double arg4,
            final double arg5)
    {
    // Stub method only.

    }

    @Override
    public void glProgramLocalParameter4dvARB(final int arg0, final int arg1, final DoubleBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glProgramLocalParameter4dvARB(final int arg0, final int arg1, final double[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glProgramLocalParameter4fARB(final int arg0, final int arg1, final float arg2, final float arg3, final float arg4, final float arg5)
    {
    // Stub method only.

    }

    @Override
    public void glProgramLocalParameter4fvARB(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glProgramLocalParameter4fvARB(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glProgramLocalParameterI4iNV(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5)
    {
    // Stub method only.

    }

    @Override
    public void glProgramLocalParameterI4ivNV(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glProgramLocalParameterI4ivNV(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glProgramLocalParameterI4uiNV(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5)
    {
    // Stub method only.

    }

    @Override
    public void glProgramLocalParameterI4uivNV(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glProgramLocalParameterI4uivNV(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glProgramLocalParameters4fvEXT(final int arg0, final int arg1, final int arg2, final FloatBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glProgramLocalParameters4fvEXT(final int arg0, final int arg1, final int arg2, final float[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glProgramLocalParametersI4ivNV(final int arg0, final int arg1, final int arg2, final IntBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glProgramLocalParametersI4ivNV(final int arg0, final int arg1, final int arg2, final int[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glProgramLocalParametersI4uivNV(final int arg0, final int arg1, final int arg2, final IntBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glProgramLocalParametersI4uivNV(final int arg0, final int arg1, final int arg2, final int[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glProgramNamedParameter4dNV(final int arg0, final int arg1, final String arg2, final double arg3, final double arg4,
            final double arg5, final double arg6)
    {
    // Stub method only.

    }

    @Override
    public void glProgramNamedParameter4dvNV(final int arg0, final int arg1, final String arg2, final DoubleBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glProgramNamedParameter4dvNV(final int arg0, final int arg1, final String arg2, final double[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glProgramNamedParameter4fNV(final int arg0, final int arg1, final String arg2, final float arg3, final float arg4, final float arg5,
            final float arg6)
    {
    // Stub method only.

    }

    @Override
    public void glProgramNamedParameter4fvNV(final int arg0, final int arg1, final String arg2, final FloatBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glProgramNamedParameter4fvNV(final int arg0, final int arg1, final String arg2, final float[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glProgramParameter4dNV(final int arg0, final int arg1, final double arg2, final double arg3, final double arg4, final double arg5)
    {
    // Stub method only.

    }

    @Override
    public void glProgramParameter4dvNV(final int arg0, final int arg1, final DoubleBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glProgramParameter4dvNV(final int arg0, final int arg1, final double[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glProgramParameter4fNV(final int arg0, final int arg1, final float arg2, final float arg3, final float arg4, final float arg5)
    {
    // Stub method only.

    }

    @Override
    public void glProgramParameter4fvNV(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glProgramParameter4fvNV(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glProgramParameteriEXT(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glProgramParameters4dvNV(final int arg0, final int arg1, final int arg2, final DoubleBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glProgramParameters4dvNV(final int arg0, final int arg1, final int arg2, final double[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glProgramParameters4fvNV(final int arg0, final int arg1, final int arg2, final FloatBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glProgramParameters4fvNV(final int arg0, final int arg1, final int arg2, final float[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glProgramStringARB(final int arg0, final int arg1, final int arg2, final String arg3)
    {
    // Stub method only.

    }

    @Override
    public void glProgramVertexLimitNV(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glPushAttrib(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glPushClientAttrib(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glPushMatrix()
    {
        addMethodCall("glPushMatrix", null);

    }

    @Override
    public void glPushName(final int arg0)
    {
        addMethodCall("glPushName", new Object[] {arg0});

    }

    @Override
    public void glRasterPos2d(final double arg0, final double arg1)
    {
    // Stub method only.

    }

    @Override
    public void glRasterPos2dv(final DoubleBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glRasterPos2dv(final double[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glRasterPos2f(final float arg0, final float arg1)
    {
    // Stub method only.

    }

    @Override
    public void glRasterPos2fv(FloatBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glRasterPos2fv(final float[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glRasterPos2i(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glRasterPos2iv(final IntBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glRasterPos2iv(final int[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glRasterPos2s(final short arg0, final short arg1)
    {
    // Stub method only.

    }

    @Override
    public void glRasterPos2sv(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glRasterPos2sv(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glRasterPos3d(final double arg0, final double arg1, final double arg2)
    {
    // Stub method only.

    }

    @Override
    public void glRasterPos3dv(final DoubleBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glRasterPos3dv(final double[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glRasterPos3f(final float arg0, final float arg1, final float arg2)
    {
    // Stub method only.

    }

    @Override
    public void glRasterPos3fv(FloatBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glRasterPos3fv(final float[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glRasterPos3i(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glRasterPos3iv(final IntBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glRasterPos3iv(final int[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glRasterPos3s(final short arg0, final short arg1, final short arg2)
    {
    // Stub method only.

    }

    @Override
    public void glRasterPos3sv(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glRasterPos3sv(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glRasterPos4d(final double arg0, final double arg1, final double arg2, final double arg3)
    {
    // Stub method only.

    }

    @Override
    public void glRasterPos4dv(final DoubleBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glRasterPos4dv(final double[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glRasterPos4f(final float arg0, final float arg1, final float arg2, final float arg3)
    {
    // Stub method only.

    }

    @Override
    public void glRasterPos4fv(FloatBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glRasterPos4fv(final float[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glRasterPos4i(final int arg0, final int arg1, final int arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glRasterPos4iv(final IntBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glRasterPos4iv(final int[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glRasterPos4s(final short arg0, final short arg1, final short arg2, final short arg3)
    {
    // Stub method only.

    }

    @Override
    public void glRasterPos4sv(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glRasterPos4sv(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glReadBuffer(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glReadBufferRegion(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glReadInstrumentsSGIX(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glReadPixels(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5, final Buffer arg6)
    {
    // Stub method only.

    }

    @Override
    public void glReadPixels(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5, final long arg6)
    {
    // Stub method only.

    }

    @Override
    public void glRectd(final double arg0, final double arg1, final double arg2, final double arg3)
    {
    // Stub method only.

    }

    @Override
    public void glRectdv(final DoubleBuffer arg0, final DoubleBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glRectdv(final double[] arg0, final int arg1, final double[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glRectf(final float arg0, final float arg1, final float arg2, final float arg3)
    {
    // Stub method only.

    }

    @Override
    public void glRectfv(FloatBuffer arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glRectfv(final float[] arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glRecti(final int arg0, final int arg1, final int arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glRectiv(final IntBuffer arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glRectiv(final int[] arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glRects(final short arg0, final short arg1, final short arg2, final short arg3)
    {
    // Stub method only.

    }

    @Override
    public void glRectsv(final ShortBuffer arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glRectsv(final short[] arg0, final int arg1, final short[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glReferencePlaneSGIX(final DoubleBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glReferencePlaneSGIX(final double[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public final int glRenderMode(final int arg0)
    {
        // Stub method only.
        return 0;
    }

    @Override
    public void glRenderbufferStorageEXT(final int arg0, final int arg1, final int arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glRenderbufferStorageMultisampleCoverageNV(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4,
            final int arg5)
    {
    // Stub method only.

    }

    @Override
    public void glRenderbufferStorageMultisampleEXT(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glReplacementCodeuiColor3fVertex3fSUN(final int arg0, final float arg1, final float arg2, final float arg3, final float arg4,
            final float arg5, final float arg6)
    {
    // Stub method only.

    }

    @Override
    public void glReplacementCodeuiColor3fVertex3fvSUN(final IntBuffer arg0, final FloatBuffer arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glReplacementCodeuiColor3fVertex3fvSUN(final int[] arg0, final int arg1, final float[] arg2, final int arg3, final float[] arg4,
            final int arg5)
    {
    // Stub method only.

    }

    @Override
    public void glReplacementCodeuiColor4fNormal3fVertex3fSUN(final int arg0, final float arg1, final float arg2, final float arg3, final float arg4,
            final float arg5, final float arg6, float arg7, final float arg8, final float arg9, final float arg10)
    {
    // Stub method only.

    }

    @Override
    public void glReplacementCodeuiColor4fNormal3fVertex3fvSUN(final IntBuffer arg0, final FloatBuffer arg1, final FloatBuffer arg2,
            final FloatBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glReplacementCodeuiColor4fNormal3fVertex3fvSUN(final int[] arg0, final int arg1, final float[] arg2, final int arg3,
            final float[] arg4, final int arg5, final float[] arg6, final int arg7)
    {
    // Stub method only.

    }

    @Override
    public void glReplacementCodeuiColor4ubVertex3fSUN(final int arg0, final byte arg1, final byte arg2, final byte arg3, final byte arg4,
            final float arg5, final float arg6, final float arg7)
    {
    // Stub method only.

    }

    @Override
    public void glReplacementCodeuiColor4ubVertex3fvSUN(final IntBuffer arg0, final ByteBuffer arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glReplacementCodeuiColor4ubVertex3fvSUN(final int[] arg0, final int arg1, final byte[] arg2, final int arg3, final float[] arg4,
            final int arg5)
    {
    // Stub method only.

    }

    @Override
    public void glReplacementCodeuiNormal3fVertex3fSUN(final int arg0, final float arg1, final float arg2, final float arg3, final float arg4,
            final float arg5, final float arg6)
    {
    // Stub method only.

    }

    @Override
    public void glReplacementCodeuiNormal3fVertex3fvSUN(final IntBuffer arg0, final FloatBuffer arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glReplacementCodeuiNormal3fVertex3fvSUN(final int[] arg0, final int arg1, final float[] arg2, final int arg3, final float[] arg4,
            final int arg5)
    {
    // Stub method only.

    }

    @Override
    public void glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN(final int arg0, final float arg1, final float arg2, final float arg3,
            final float arg4, final float arg5, float arg6, final float arg7, final float arg8, final float arg9, final float arg10,
            final float arg11, final float arg12)
    {
    // Stub method only.

    }

    @Override
    public void glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN(final IntBuffer arg0, final FloatBuffer arg1, final FloatBuffer arg2,
            final FloatBuffer arg3, FloatBuffer arg4)
    {
    // Stub method only.

    }

    @Override
    public void glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN(final int[] arg0, final int arg1, final float[] arg2, final int arg3,
            final float[] arg4, final int arg5, float[] arg6, final int arg7, final float[] arg8, final int arg9)
    {
    // Stub method only.

    }

    @Override
    public void glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN(final int arg0, final float arg1, final float arg2, final float arg3,
            final float arg4, final float arg5, final float arg6, float arg7, final float arg8)
    {
    // Stub method only.

    }

    @Override
    public void glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN(final IntBuffer arg0, final FloatBuffer arg1, final FloatBuffer arg2,
            final FloatBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN(final int[] arg0, final int arg1, final float[] arg2, final int arg3,
            final float[] arg4, final int arg5, final float[] arg6, final int arg7)
    {
    // Stub method only.

    }

    @Override
    public void glReplacementCodeuiTexCoord2fVertex3fSUN(final int arg0, final float arg1, final float arg2, final float arg3, final float arg4,
            final float arg5)
    {
    // Stub method only.

    }

    @Override
    public void glReplacementCodeuiTexCoord2fVertex3fvSUN(final IntBuffer arg0, final FloatBuffer arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glReplacementCodeuiTexCoord2fVertex3fvSUN(final int[] arg0, final int arg1, final float[] arg2, final int arg3, final float[] arg4,
            final int arg5)
    {
    // Stub method only.

    }

    @Override
    public void glReplacementCodeuiVertex3fSUN(final int arg0, final float arg1, final float arg2, final float arg3)
    {
    // Stub method only.

    }

    @Override
    public void glReplacementCodeuiVertex3fvSUN(final IntBuffer arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glReplacementCodeuiVertex3fvSUN(final int[] arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glRequestResidentProgramsNV(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glRequestResidentProgramsNV(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glResetHistogram(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glResetMinmax(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glResizeBuffersMESA()
    {
    // Stub method only.

    }

    @Override
    public void glRotated(final double arg0, final double arg1, final double arg2, final double arg3)
    {
    // Stub method only.

    }

    @Override
    public void glRotatef(final float arg0, final float arg1, final float arg2, final float arg3)
    {
    // Stub method only.

    }

    @Override
    public void glSampleCoverage(final float arg0, final boolean arg1)
    {
    // Stub method only.

    }

    @Override
    public void glSampleMapATI(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glSampleMaskEXT(final float arg0, final boolean arg1)
    {
    // Stub method only.

    }

    @Override
    public void glSampleMaskSGIS(final float arg0, final boolean arg1)
    {
    // Stub method only.

    }

    @Override
    public void glSamplePatternEXT(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glSamplePatternSGIS(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glScaled(final double arg0, final double arg1, final double arg2)
    {
    // Stub method only.

    }

    @Override
    public void glScalef(final float arg0, final float arg1, final float arg2)
    {
    // Stub method only.

    }

    @Override
    public void glScissor(final int arg0, final int arg1, final int arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3b(final byte arg0, final byte arg1, final byte arg2)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3bEXT(final byte arg0, final byte arg1, final byte arg2)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3bv(final ByteBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3bv(final byte[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3bvEXT(final ByteBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3bvEXT(final byte[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3d(final double arg0, final double arg1, final double arg2)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3dEXT(final double arg0, final double arg1, final double arg2)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3dv(final DoubleBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3dv(final double[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3dvEXT(final DoubleBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3dvEXT(final double[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3f(final float arg0, final float arg1, final float arg2)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3fEXT(final float arg0, final float arg1, final float arg2)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3fv(FloatBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3fv(final float[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3fvEXT(FloatBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3fvEXT(final float[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3hNV(final short arg0, final short arg1, final short arg2)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3hvNV(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3hvNV(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3i(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3iEXT(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3iv(final IntBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3iv(final int[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3ivEXT(final IntBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3ivEXT(final int[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3s(final short arg0, final short arg1, final short arg2)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3sEXT(final short arg0, final short arg1, final short arg2)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3sv(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3sv(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3svEXT(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3svEXT(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3ub(final byte arg0, final byte arg1, final byte arg2)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3ubEXT(final byte arg0, final byte arg1, final byte arg2)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3ubv(final ByteBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3ubv(final byte[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3ubvEXT(final ByteBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3ubvEXT(final byte[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3ui(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3uiEXT(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3uiv(final IntBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3uiv(final int[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3uivEXT(final IntBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3uivEXT(final int[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3us(final short arg0, final short arg1, final short arg2)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3usEXT(final short arg0, final short arg1, final short arg2)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3usv(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3usv(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3usvEXT(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColor3usvEXT(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColorPointer(final int arg0, final int arg1, final int arg2, final Buffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColorPointer(final int arg0, final int arg1, final int arg2, final long arg3)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColorPointerEXT(final int arg0, final int arg1, final int arg2, final Buffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glSecondaryColorPointerEXT(final int arg0, final int arg1, final int arg2, final long arg3)
    {
    // Stub method only.

    }

    @Override
    public void glSelectBuffer(final int arg0, final IntBuffer arg1)
    {
        addMethodCall("glSelectBuffer", new Object[] {arg0, arg1});
    }

    @Override
    public void glSeparableFilter2D(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5,
            final Buffer arg6, final Buffer arg7)
    {
    // Stub method only.

    }

    @Override
    public void glSeparableFilter2D(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5, final long arg6,
            final long arg7)
    {
    // Stub method only.

    }

    @Override
    public void glSetFenceAPPLE(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glSetFenceNV(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glSetFragmentShaderConstantATI(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glSetFragmentShaderConstantATI(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glSetInvariantEXT(final int arg0, final int arg1, final Buffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glSetLocalConstantEXT(final int arg0, final int arg1, final Buffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glShadeModel(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glShaderOp1EXT(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glShaderOp2EXT(final int arg0, final int arg1, final int arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glShaderOp3EXT(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glShaderSource(final int arg0, final int arg1, final String[] arg2, final IntBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glShaderSource(final int arg0, final int arg1, final String[] arg2, final int[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glShaderSourceARB(final int arg0, final int arg1, final String[] arg2, final IntBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glShaderSourceARB(final int arg0, final int arg1, final String[] arg2, final int[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glSharpenTexFuncSGIS(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glSharpenTexFuncSGIS(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glSpriteParameterfSGIX(final int arg0, final float arg1)
    {
    // Stub method only.

    }

    @Override
    public void glSpriteParameterfvSGIX(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glSpriteParameterfvSGIX(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glSpriteParameteriSGIX(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glSpriteParameterivSGIX(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glSpriteParameterivSGIX(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glStartInstrumentsSGIX()
    {
    // Stub method only.

    }

    @Override
    public void glStencilClearTagEXT(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glStencilFunc(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glStencilFuncSeparate(final int arg0, final int arg1, final int arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glStencilFuncSeparateATI(final int arg0, final int arg1, final int arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glStencilMask(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glStencilMaskSeparate(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glStencilOp(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glStencilOpSeparate(final int arg0, final int arg1, final int arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glStencilOpSeparateATI(final int arg0, final int arg1, final int arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glStopInstrumentsSGIX(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glStringMarkerGREMEDY(final int arg0, final Buffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glSwapAPPLE()
    {
    // Stub method only.

    }

    @Override
    public void glSwizzleEXT(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5)
    {
    // Stub method only.

    }

    @Override
    public void glTagSampleBufferSGIX()
    {
    // Stub method only.

    }

    @Override
    public void glTbufferMask3DFX(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public boolean glTestFenceAPPLE(final int arg0)
    {
        // Stub method only.
        return false;
    }

    @Override
    public boolean glTestFenceNV(final int arg0)
    {
        // Stub method only.
        return false;
    }

    @Override
    public boolean glTestObjectAPPLE(final int arg0, final int arg1)
    {
        // Stub method only.
        return false;
    }

    @Override
    public void glTexBufferEXT(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glTexBumpParameterfvATI(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glTexBumpParameterfvATI(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glTexBumpParameterivATI(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glTexBumpParameterivATI(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord1d(final double arg0)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord1dv(final DoubleBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord1dv(final double[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord1f(final float arg0)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord1fv(final FloatBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord1fv(final float[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord1hNV(final short arg0)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord1hvNV(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord1hvNV(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord1i(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord1iv(final IntBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord1iv(final int[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord1s(final short arg0)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord1sv(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord1sv(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord2d(final double arg0, final double arg1)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord2dv(final DoubleBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord2dv(final double[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord2f(final float arg0, final float arg1)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord2fColor3fVertex3fSUN(final float arg0, final float arg1, final float arg2, final float arg3, final float arg4,
            final float arg5, final float arg6, final float arg7)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord2fColor3fVertex3fvSUN(final FloatBuffer arg0, final FloatBuffer arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord2fColor3fVertex3fvSUN(final float[] arg0, final int arg1, final float[] arg2, final int arg3, final float[] arg4,
            final int arg5)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord2fColor4fNormal3fVertex3fSUN(final float arg0, final float arg1, final float arg2, final float arg3, final float arg4,
            final float arg5, final float arg6, float arg7, final float arg8, final float arg9, final float arg10, final float arg11)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord2fColor4fNormal3fVertex3fvSUN(final FloatBuffer arg0, final FloatBuffer arg1, final FloatBuffer arg2, final FloatBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord2fColor4fNormal3fVertex3fvSUN(final float[] arg0, final int arg1, final float[] arg2, final int arg3, final float[] arg4,
            final int arg5, final float[] arg6, final int arg7)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord2fColor4ubVertex3fSUN(final float arg0, final float arg1, final byte arg2, final byte arg3, final byte arg4,
            final byte arg5, final float arg6, final float arg7, final float arg8)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord2fColor4ubVertex3fvSUN(final FloatBuffer arg0, final ByteBuffer arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord2fColor4ubVertex3fvSUN(final float[] arg0, final int arg1, final byte[] arg2, final int arg3, final float[] arg4,
            final int arg5)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord2fNormal3fVertex3fSUN(final float arg0, final float arg1, final float arg2, final float arg3, final float arg4,
            final float arg5, final float arg6, final float arg7)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord2fNormal3fVertex3fvSUN(final FloatBuffer arg0, final FloatBuffer arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord2fNormal3fVertex3fvSUN(final float[] arg0, final int arg1, final float[] arg2, final int arg3, final float[] arg4,
            final int arg5)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord2fVertex3fSUN(final float arg0, final float arg1, final float arg2, final float arg3, final float arg4)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord2fVertex3fvSUN(final FloatBuffer arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord2fVertex3fvSUN(final float[] arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord2fv(final FloatBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord2fv(final float[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord2hNV(final short arg0, final short arg1)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord2hvNV(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord2hvNV(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord2i(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord2iv(final IntBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord2iv(final int[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord2s(final short arg0, final short arg1)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord2sv(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord2sv(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord3d(final double arg0, final double arg1, final double arg2)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord3dv(final DoubleBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord3dv(final double[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord3f(final float arg0, final float arg1, final float arg2)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord3fv(final FloatBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord3fv(final float[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord3hNV(final short arg0, final short arg1, final short arg2)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord3hvNV(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord3hvNV(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord3i(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord3iv(final IntBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord3iv(final int[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord3s(final short arg0, final short arg1, final short arg2)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord3sv(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord3sv(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord4d(final double arg0, final double arg1, final double arg2, final double arg3)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord4dv(final DoubleBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord4dv(final double[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord4f(final float arg0, final float arg1, final float arg2, final float arg3)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord4fColor4fNormal3fVertex4fSUN(final float arg0, final float arg1, final float arg2, final float arg3, final float arg4,
            final float arg5, final float arg6, float arg7, final float arg8, final float arg9, final float arg10, final float arg11,
            final float arg12, final float arg13, final float arg14)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord4fColor4fNormal3fVertex4fvSUN(final FloatBuffer arg0, final FloatBuffer arg1, final FloatBuffer arg2, final FloatBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord4fColor4fNormal3fVertex4fvSUN(final float[] arg0, final int arg1, final float[] arg2, final int arg3, final float[] arg4,
            final int arg5, final float[] arg6, final int arg7)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord4fVertex4fSUN(final float arg0, final float arg1, final float arg2, final float arg3, final float arg4, final float arg5,
            final float arg6, final float arg7)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord4fVertex4fvSUN(final FloatBuffer arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord4fVertex4fvSUN(final float[] arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord4fv(final FloatBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord4fv(final float[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord4hNV(final short arg0, final short arg1, final short arg2, final short arg3)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord4hvNV(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord4hvNV(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord4i(final int arg0, final int arg1, final int arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord4iv(final IntBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord4iv(final int[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord4s(final short arg0, final short arg1, final short arg2, final short arg3)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord4sv(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoord4sv(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoordPointer(final int arg0, final int arg1, final int arg2, final Buffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glTexCoordPointer(final int arg0, final int arg1, final int arg2, final long arg3)
    {
    // Stub method only.

    }

    @Override
    public void glTexEnvf(final int arg0, final int arg1, final float arg2)
    {
    // Stub method only.

    }

    @Override
    public void glTexEnvfv(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glTexEnvfv(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glTexEnvi(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glTexEnviv(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glTexEnviv(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glTexFilterFuncSGIS(final int arg0, final int arg1, final int arg2, final FloatBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glTexFilterFuncSGIS(final int arg0, final int arg1, final int arg2, final float[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glTexGend(final int arg0, final int arg1, final double arg2)
    {
    // Stub method only.

    }

    @Override
    public void glTexGendv(final int arg0, final int arg1, final DoubleBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glTexGendv(final int arg0, final int arg1, final double[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glTexGenf(final int arg0, final int arg1, final float arg2)
    {
    // Stub method only.

    }

    @Override
    public void glTexGenfv(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glTexGenfv(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glTexGeni(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glTexGeniv(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glTexGeniv(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glTexImage1D(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5, final int arg6,
            final Buffer arg7)
    {
    // Stub method only.

    }

    @Override
    public void glTexImage1D(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5, final int arg6,
            final long arg7)
    {
    // Stub method only.

    }

    @Override
    public void glTexImage2D(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5, final int arg6,
            final int arg7, final Buffer arg8)
    {
    // Stub method only.

    }

    @Override
    public void glTexImage2D(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5, final int arg6,
            final int arg7, final long arg8)
    {
    // Stub method only.

    }

    @Override
    public void glTexImage3D(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5, final int arg6,
            final int arg7, final int arg8, final Buffer arg9)
    {
    // Stub method only.

    }

    @Override
    public void glTexImage3D(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5, final int arg6,
            final int arg7, final int arg8, final long arg9)
    {
    // Stub method only.

    }

    @Override
    public void glTexImage4DSGIS(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5, final int arg6,
            final int arg7, final int arg8, final int arg9, final Buffer arg10)
    {
    // Stub method only.

    }

    @Override
    public void glTexParameterIivEXT(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glTexParameterIivEXT(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glTexParameterIuivEXT(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glTexParameterIuivEXT(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glTexParameterf(final int arg0, final int arg1, final float arg2)
    {
    // Stub method only.

    }

    @Override
    public void glTexParameterfv(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glTexParameterfv(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glTexParameteri(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glTexParameteriv(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glTexParameteriv(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glTexSubImage1D(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5, final Buffer arg6)
    {
    // Stub method only.

    }

    @Override
    public void glTexSubImage1D(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5, final long arg6)
    {
    // Stub method only.

    }

    @Override
    public void glTexSubImage2D(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5, final int arg6,
            final int arg7, final Buffer arg8)
    {
    // Stub method only.

    }

    @Override
    public void glTexSubImage2D(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5, final int arg6,
            final int arg7, final long arg8)
    {
    // Stub method only.

    }

    @Override
    public void glTexSubImage3D(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5, final int arg6,
            final int arg7, final int arg8, final int arg9, final Buffer arg10)
    {
    // Stub method only.

    }

    @Override
    public void glTexSubImage3D(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5, final int arg6,
            final int arg7, final int arg8, final int arg9, final long arg10)
    {
    // Stub method only.

    }

    @Override
    public void glTexSubImage4DSGIS(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5, final int arg6,
            final int arg7, final int arg8, final int arg9, final int arg10, final int arg11, final Buffer arg12)
    {
    // Stub method only.

    }

    @Override
    public void glTextureColorMaskSGIS(final boolean arg0, final boolean arg1, final boolean arg2, final boolean arg3)
    {
    // Stub method only.

    }

    @Override
    public void glTextureLightEXT(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glTextureMaterialEXT(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glTextureNormalEXT(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glTextureRangeAPPLE(final int arg0, final int arg1, final Buffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glTrackMatrixNV(final int arg0, final int arg1, final int arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glTransformFeedbackAttribsNV(final int arg0, final IntBuffer arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glTransformFeedbackAttribsNV(final int arg0, final int[] arg1, final int arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glTransformFeedbackVaryingsNV(final int arg0, final int arg1, final IntBuffer arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glTransformFeedbackVaryingsNV(final int arg0, final int arg1, final int[] arg2, final int arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glTranslated(final double arg0, final double arg1, final double arg2)
    {
    // Stub method only.

    }

    @Override
    public void glTranslatef(final float arg0, final float arg1, final float arg2)
    {
    // Stub method only.

    }

    @Override
    public void glUniform1f(final int arg0, final float arg1)
    {
    // Stub method only.

    }

    @Override
    public void glUniform1fARB(final int arg0, final float arg1)
    {
    // Stub method only.

    }

    @Override
    public void glUniform1fv(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glUniform1fv(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glUniform1fvARB(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glUniform1fvARB(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glUniform1i(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glUniform1iARB(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glUniform1iv(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glUniform1iv(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glUniform1ivARB(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glUniform1ivARB(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glUniform1uiEXT(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glUniform1uivEXT(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glUniform1uivEXT(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glUniform2f(final int arg0, final float arg1, final float arg2)
    {
    // Stub method only.

    }

    @Override
    public void glUniform2fARB(final int arg0, final float arg1, final float arg2)
    {
    // Stub method only.

    }

    @Override
    public void glUniform2fv(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glUniform2fv(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glUniform2fvARB(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glUniform2fvARB(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glUniform2i(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glUniform2iARB(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glUniform2iv(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glUniform2iv(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glUniform2ivARB(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glUniform2ivARB(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glUniform2uiEXT(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glUniform2uivEXT(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glUniform2uivEXT(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glUniform3f(final int arg0, final float arg1, final float arg2, final float arg3)
    {
    // Stub method only.

    }

    @Override
    public void glUniform3fARB(final int arg0, final float arg1, final float arg2, final float arg3)
    {
    // Stub method only.

    }

    @Override
    public void glUniform3fv(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glUniform3fv(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glUniform3fvARB(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glUniform3fvARB(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glUniform3i(final int arg0, final int arg1, final int arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glUniform3iARB(final int arg0, final int arg1, final int arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glUniform3iv(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glUniform3iv(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glUniform3ivARB(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glUniform3ivARB(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glUniform3uiEXT(final int arg0, final int arg1, final int arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glUniform3uivEXT(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glUniform3uivEXT(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glUniform4f(final int arg0, final float arg1, final float arg2, final float arg3, final float arg4)
    {
    // Stub method only.

    }

    @Override
    public void glUniform4fARB(final int arg0, final float arg1, final float arg2, final float arg3, final float arg4)
    {
    // Stub method only.

    }

    @Override
    public void glUniform4fv(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glUniform4fv(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glUniform4fvARB(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glUniform4fvARB(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glUniform4i(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glUniform4iARB(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glUniform4iv(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glUniform4iv(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glUniform4ivARB(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glUniform4ivARB(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glUniform4uiEXT(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glUniform4uivEXT(final int arg0, final int arg1, final IntBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glUniform4uivEXT(final int arg0, final int arg1, final int[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glUniformBufferEXT(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glUniformMatrix2fv(final int arg0, final int arg1, final boolean arg2, final FloatBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glUniformMatrix2fv(final int arg0, final int arg1, final boolean arg2, final float[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glUniformMatrix2fvARB(final int arg0, final int arg1, final boolean arg2, final FloatBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glUniformMatrix2fvARB(final int arg0, final int arg1, final boolean arg2, final float[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glUniformMatrix2x3fv(final int arg0, final int arg1, final boolean arg2, final FloatBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glUniformMatrix2x3fv(final int arg0, final int arg1, final boolean arg2, final float[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glUniformMatrix2x4fv(final int arg0, final int arg1, final boolean arg2, final FloatBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glUniformMatrix2x4fv(final int arg0, final int arg1, final boolean arg2, final float[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glUniformMatrix3fv(final int arg0, final int arg1, final boolean arg2, final FloatBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glUniformMatrix3fv(final int arg0, final int arg1, final boolean arg2, final float[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glUniformMatrix3fvARB(final int arg0, final int arg1, final boolean arg2, final FloatBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glUniformMatrix3fvARB(final int arg0, final int arg1, final boolean arg2, final float[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glUniformMatrix3x2fv(final int arg0, final int arg1, final boolean arg2, final FloatBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glUniformMatrix3x2fv(final int arg0, final int arg1, final boolean arg2, final float[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glUniformMatrix3x4fv(final int arg0, final int arg1, final boolean arg2, final FloatBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glUniformMatrix3x4fv(final int arg0, final int arg1, final boolean arg2, final float[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glUniformMatrix4fv(final int arg0, final int arg1, final boolean arg2, final FloatBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glUniformMatrix4fv(final int arg0, final int arg1, final boolean arg2, final float[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glUniformMatrix4fvARB(final int arg0, final int arg1, final boolean arg2, final FloatBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glUniformMatrix4fvARB(final int arg0, final int arg1, final boolean arg2, final float[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glUniformMatrix4x2fv(final int arg0, final int arg1, final boolean arg2, final FloatBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glUniformMatrix4x2fv(final int arg0, final int arg1, final boolean arg2, final float[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glUniformMatrix4x3fv(final int arg0, final int arg1, final boolean arg2, final FloatBuffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glUniformMatrix4x3fv(final int arg0, final int arg1, final boolean arg2, final float[] arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glUnlockArraysEXT()
    {
    // Stub method only.

    }

    @Override
    public boolean glUnmapBuffer(final int arg0)
    {
        // Stub method only.
        return false;
    }

    @Override
    public boolean glUnmapBufferARB(final int arg0)
    {
        // Stub method only.
        return false;
    }

    @Override
    public void glUpdateObjectBufferATI(final int arg0, final int arg1, final int arg2, final Buffer arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glUseProgram(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glUseProgramObjectARB(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glValidateProgram(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glValidateProgramARB(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glVariantArrayObjectATI(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glVariantPointerEXT(final int arg0, final int arg1, final int arg2, final Buffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVariantPointerEXT(final int arg0, final int arg1, final int arg2, final long arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVariantbvEXT(final int arg0, final ByteBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVariantbvEXT(final int arg0, final byte[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVariantdvEXT(final int arg0, final DoubleBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVariantdvEXT(final int arg0, final double[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVariantfvEXT(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVariantfvEXT(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVariantivEXT(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVariantivEXT(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVariantsvEXT(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVariantsvEXT(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVariantubvEXT(final int arg0, final ByteBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVariantubvEXT(final int arg0, final byte[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVariantuivEXT(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVariantuivEXT(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVariantusvEXT(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVariantusvEXT(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertex2d(final double arg0, final double arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertex2dv(final DoubleBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glVertex2dv(final double[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertex2f(final float arg0, final float arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertex2fv(final FloatBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glVertex2fv(final float[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertex2hNV(final short arg0, final short arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertex2hvNV(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glVertex2hvNV(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertex2i(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertex2iv(final IntBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glVertex2iv(final int[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertex2s(final short arg0, final short arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertex2sv(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glVertex2sv(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertex3d(final double arg0, final double arg1, final double arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertex3dv(final DoubleBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glVertex3dv(final double[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertex3f(final float arg0, final float arg1, final float arg2)
    {
        addMethodCall("glVertex3f", new Object[] {arg0, arg1, arg2});

    }

    @Override
    public void glVertex3fv(final FloatBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glVertex3fv(final float[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertex3hNV(final short arg0, final short arg1, final short arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertex3hvNV(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glVertex3hvNV(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertex3i(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertex3iv(final IntBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glVertex3iv(final int[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertex3s(final short arg0, final short arg1, final short arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertex3sv(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glVertex3sv(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertex4d(final double arg0, final double arg1, final double arg2, final double arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertex4dv(final DoubleBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glVertex4dv(final double[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertex4f(final float arg0, final float arg1, final float arg2, final float arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertex4fv(final FloatBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glVertex4fv(final float[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertex4hNV(final short arg0, final short arg1, final short arg2, final short arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertex4hvNV(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glVertex4hvNV(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertex4i(final int arg0, final int arg1, final int arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertex4iv(final IntBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glVertex4iv(final int[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertex4s(final short arg0, final short arg1, final short arg2, final short arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertex4sv(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glVertex4sv(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexArrayParameteriAPPLE(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexArrayRangeAPPLE(final int arg0, final Buffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexArrayRangeNV(final int arg0, final Buffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib1d(final int arg0, final double arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib1dARB(final int arg0, final double arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib1dNV(final int arg0, final double arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib1dv(final int arg0, final DoubleBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib1dv(final int arg0, final double[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib1dvARB(final int arg0, final DoubleBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib1dvARB(final int arg0, final double[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib1dvNV(final int arg0, final DoubleBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib1dvNV(final int arg0, final double[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib1f(final int arg0, final float arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib1fARB(final int arg0, final float arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib1fNV(final int arg0, final float arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib1fv(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib1fv(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib1fvARB(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib1fvARB(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib1fvNV(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib1fvNV(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib1hNV(final int arg0, final short arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib1hvNV(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib1hvNV(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib1s(final int arg0, final short arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib1sARB(final int arg0, final short arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib1sNV(final int arg0, final short arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib1sv(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib1sv(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib1svARB(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib1svARB(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib1svNV(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib1svNV(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib2d(final int arg0, final double arg1, final double arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib2dARB(final int arg0, final double arg1, final double arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib2dNV(final int arg0, final double arg1, final double arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib2dv(final int arg0, final DoubleBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib2dv(final int arg0, final double[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib2dvARB(final int arg0, final DoubleBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib2dvARB(final int arg0, final double[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib2dvNV(final int arg0, final DoubleBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib2dvNV(final int arg0, final double[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib2f(final int arg0, final float arg1, final float arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib2fARB(final int arg0, final float arg1, final float arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib2fNV(final int arg0, final float arg1, final float arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib2fv(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib2fv(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib2fvARB(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib2fvARB(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib2fvNV(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib2fvNV(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib2hNV(final int arg0, final short arg1, final short arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib2hvNV(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib2hvNV(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib2s(final int arg0, final short arg1, final short arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib2sARB(final int arg0, final short arg1, final short arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib2sNV(final int arg0, final short arg1, final short arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib2sv(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib2sv(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib2svARB(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib2svARB(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib2svNV(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib2svNV(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib3d(final int arg0, final double arg1, final double arg2, final double arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib3dARB(final int arg0, final double arg1, final double arg2, final double arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib3dNV(final int arg0, final double arg1, final double arg2, final double arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib3dv(final int arg0, final DoubleBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib3dv(final int arg0, final double[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib3dvARB(final int arg0, final DoubleBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib3dvARB(final int arg0, final double[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib3dvNV(final int arg0, final DoubleBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib3dvNV(final int arg0, final double[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib3f(final int arg0, final float arg1, final float arg2, final float arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib3fARB(final int arg0, final float arg1, final float arg2, final float arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib3fNV(final int arg0, final float arg1, final float arg2, final float arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib3fv(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib3fv(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib3fvARB(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib3fvARB(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib3fvNV(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib3fvNV(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib3hNV(final int arg0, final short arg1, final short arg2, final short arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib3hvNV(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib3hvNV(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib3s(final int arg0, final short arg1, final short arg2, final short arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib3sARB(final int arg0, final short arg1, final short arg2, final short arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib3sNV(final int arg0, final short arg1, final short arg2, final short arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib3sv(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib3sv(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib3svARB(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib3svARB(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib3svNV(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib3svNV(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4Nbv(final int arg0, final ByteBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4Nbv(final int arg0, final byte[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4NbvARB(final int arg0, final ByteBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4NbvARB(final int arg0, final byte[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4Niv(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4Niv(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4NivARB(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4NivARB(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4Nsv(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4Nsv(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4NsvARB(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4NsvARB(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4Nub(final int arg0, final byte arg1, final byte arg2, final byte arg3, final byte arg4)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4NubARB(final int arg0, final byte arg1, final byte arg2, final byte arg3, final byte arg4)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4Nubv(final int arg0, final ByteBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4Nubv(final int arg0, final byte[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4NubvARB(final int arg0, final ByteBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4NubvARB(final int arg0, final byte[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4Nuiv(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4Nuiv(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4NuivARB(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4NuivARB(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4Nusv(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4Nusv(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4NusvARB(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4NusvARB(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4bv(final int arg0, final ByteBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4bv(final int arg0, final byte[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4bvARB(final int arg0, final ByteBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4bvARB(final int arg0, final byte[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4d(final int arg0, final double arg1, final double arg2, final double arg3, final double arg4)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4dARB(final int arg0, final double arg1, final double arg2, final double arg3, final double arg4)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4dNV(final int arg0, final double arg1, final double arg2, final double arg3, final double arg4)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4dv(final int arg0, final DoubleBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4dv(final int arg0, final double[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4dvARB(final int arg0, final DoubleBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4dvARB(final int arg0, final double[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4dvNV(final int arg0, final DoubleBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4dvNV(final int arg0, final double[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4f(final int arg0, final float arg1, final float arg2, final float arg3, final float arg4)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4fARB(final int arg0, final float arg1, final float arg2, final float arg3, final float arg4)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4fNV(final int arg0, final float arg1, final float arg2, final float arg3, final float arg4)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4fv(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4fv(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4fvARB(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4fvARB(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4fvNV(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4fvNV(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4hNV(final int arg0, final short arg1, final short arg2, final short arg3, final short arg4)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4hvNV(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4hvNV(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4iv(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4iv(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4ivARB(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4ivARB(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4s(final int arg0, final short arg1, final short arg2, final short arg3, final short arg4)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4sARB(final int arg0, final short arg1, final short arg2, final short arg3, final short arg4)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4sNV(final int arg0, final short arg1, final short arg2, final short arg3, final short arg4)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4sv(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4sv(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4svARB(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4svARB(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4svNV(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4svNV(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4ubNV(final int arg0, final byte arg1, final byte arg2, final byte arg3, final byte arg4)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4ubv(final int arg0, final ByteBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4ubv(final int arg0, final byte[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4ubvARB(final int arg0, final ByteBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4ubvARB(final int arg0, final byte[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4ubvNV(final int arg0, final ByteBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4ubvNV(final int arg0, final byte[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4uiv(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4uiv(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4uivARB(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4uivARB(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4usv(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4usv(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4usvARB(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttrib4usvARB(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribArrayObjectATI(final int arg0, final int arg1, final int arg2, final boolean arg3, final int arg4, final int arg5,
            final int arg6)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribI1iEXT(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribI1ivEXT(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribI1ivEXT(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribI1uiEXT(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribI1uivEXT(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribI1uivEXT(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribI2iEXT(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribI2ivEXT(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribI2ivEXT(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribI2uiEXT(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribI2uivEXT(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribI2uivEXT(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribI3iEXT(final int arg0, final int arg1, final int arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribI3ivEXT(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribI3ivEXT(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribI3uiEXT(final int arg0, final int arg1, final int arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribI3uivEXT(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribI3uivEXT(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribI4bvEXT(final int arg0, final ByteBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribI4bvEXT(final int arg0, final byte[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribI4iEXT(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribI4ivEXT(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribI4ivEXT(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribI4svEXT(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribI4svEXT(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribI4ubvEXT(final int arg0, final ByteBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribI4ubvEXT(final int arg0, final byte[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribI4uiEXT(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribI4uivEXT(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribI4uivEXT(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribI4usvEXT(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribI4usvEXT(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribIPointerEXT(final int arg0, final int arg1, final int arg2, final int arg3, final Buffer arg4)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribPointer(final int arg0, final int arg1, final int arg2, final boolean arg3, final int arg4, final Buffer arg5)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribPointer(final int arg0, final int arg1, final int arg2, final boolean arg3, final int arg4, final long arg5)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribPointerARB(final int arg0, final int arg1, final int arg2, final boolean arg3, final int arg4, final Buffer arg5)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribPointerARB(final int arg0, final int arg1, final int arg2, final boolean arg3, final int arg4, final long arg5)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribPointerNV(final int arg0, final int arg1, final int arg2, final int arg3, final Buffer arg4)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribPointerNV(final int arg0, final int arg1, final int arg2, final int arg3, final long arg4)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribs1dvNV(final int arg0, final int arg1, final DoubleBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribs1dvNV(final int arg0, final int arg1, final double[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribs1fvNV(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribs1fvNV(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribs1hvNV(final int arg0, final int arg1, final ShortBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribs1hvNV(final int arg0, final int arg1, final short[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribs1svNV(final int arg0, final int arg1, final ShortBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribs1svNV(final int arg0, final int arg1, final short[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribs2dvNV(final int arg0, final int arg1, final DoubleBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribs2dvNV(final int arg0, final int arg1, final double[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribs2fvNV(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribs2fvNV(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribs2hvNV(final int arg0, final int arg1, final ShortBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribs2hvNV(final int arg0, final int arg1, final short[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribs2svNV(final int arg0, final int arg1, final ShortBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribs2svNV(final int arg0, final int arg1, final short[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribs3dvNV(final int arg0, final int arg1, final DoubleBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribs3dvNV(final int arg0, final int arg1, final double[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribs3fvNV(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribs3fvNV(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribs3hvNV(final int arg0, final int arg1, final ShortBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribs3hvNV(final int arg0, final int arg1, final short[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribs3svNV(final int arg0, final int arg1, final ShortBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribs3svNV(final int arg0, final int arg1, final short[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribs4dvNV(final int arg0, final int arg1, final DoubleBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribs4dvNV(final int arg0, final int arg1, final double[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribs4fvNV(final int arg0, final int arg1, final FloatBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribs4fvNV(final int arg0, final int arg1, final float[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribs4hvNV(final int arg0, final int arg1, final ShortBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribs4hvNV(final int arg0, final int arg1, final short[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribs4svNV(final int arg0, final int arg1, final ShortBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribs4svNV(final int arg0, final int arg1, final short[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribs4ubvNV(final int arg0, final int arg1, final ByteBuffer arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexAttribs4ubvNV(final int arg0, final int arg1, final byte[] arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertexBlendARB(final int arg0)
    {
    // Stub method only.

    }

    @Override
    public void glVertexBlendEnvfATI(final int arg0, final float arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexBlendEnviATI(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexPointer(final int arg0, final int arg1, final int arg2, final Buffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertexPointer(final int arg0, final int arg1, final int arg2, final long arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream1dATI(final int arg0, final double arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream1dvATI(final int arg0, final DoubleBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream1dvATI(final int arg0, final double[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream1fATI(final int arg0, final float arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream1fvATI(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream1fvATI(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream1iATI(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream1ivATI(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream1ivATI(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream1sATI(final int arg0, final short arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream1svATI(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream1svATI(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream2dATI(final int arg0, final double arg1, final double arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream2dvATI(final int arg0, final DoubleBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream2dvATI(final int arg0, final double[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream2fATI(final int arg0, final float arg1, final float arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream2fvATI(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream2fvATI(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream2iATI(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream2ivATI(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream2ivATI(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream2sATI(final int arg0, final short arg1, final short arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream2svATI(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream2svATI(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream3dATI(final int arg0, final double arg1, final double arg2, final double arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream3dvATI(final int arg0, final DoubleBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream3dvATI(final int arg0, final double[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream3fATI(final int arg0, final float arg1, final float arg2, final float arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream3fvATI(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream3fvATI(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream3iATI(final int arg0, final int arg1, final int arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream3ivATI(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream3ivATI(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream3sATI(final int arg0, final short arg1, final short arg2, final short arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream3svATI(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream3svATI(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream4dATI(final int arg0, final double arg1, final double arg2, final double arg3, final double arg4)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream4dvATI(final int arg0, final DoubleBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream4dvATI(final int arg0, final double[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream4fATI(final int arg0, final float arg1, final float arg2, final float arg3, final float arg4)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream4fvATI(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream4fvATI(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream4iATI(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream4ivATI(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream4ivATI(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream4sATI(final int arg0, final short arg1, final short arg2, final short arg3, final short arg4)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream4svATI(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexStream4svATI(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glVertexWeightPointerEXT(final int arg0, final int arg1, final int arg2, final Buffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertexWeightPointerEXT(final int arg0, final int arg1, final int arg2, final long arg3)
    {
    // Stub method only.

    }

    @Override
    public void glVertexWeightfEXT(final float arg0)
    {
    // Stub method only.

    }

    @Override
    public void glVertexWeightfvEXT(final FloatBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glVertexWeightfvEXT(final float[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glVertexWeighthNV(final short arg0)
    {
    // Stub method only.

    }

    @Override
    public void glVertexWeighthvNV(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glVertexWeighthvNV(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glViewport(final int arg0, final int arg1, final int arg2, final int arg3)
    {
        addMethodCall("glViewport", new Object[] {arg0, arg1, arg2, arg3});

    }

    @Override
    public void glWeightPointerARB(final int arg0, final int arg1, final int arg2, final Buffer arg3)
    {
    // Stub method only.

    }

    @Override
    public void glWeightPointerARB(final int arg0, final int arg1, final int arg2, final long arg3)
    {
    // Stub method only.

    }

    @Override
    public void glWeightbvARB(final int arg0, final ByteBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWeightbvARB(final int arg0, final byte[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glWeightdvARB(final int arg0, final DoubleBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWeightdvARB(final int arg0, final double[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glWeightfvARB(final int arg0, final FloatBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWeightfvARB(final int arg0, final float[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glWeightivARB(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWeightivARB(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glWeightsvARB(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWeightsvARB(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glWeightubvARB(final int arg0, final ByteBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWeightubvARB(final int arg0, final byte[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glWeightuivARB(final int arg0, final IntBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWeightuivARB(final int arg0, final int[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glWeightusvARB(final int arg0, final ShortBuffer arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWeightusvARB(final int arg0, final short[] arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos2d(final double arg0, final double arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos2dARB(final double arg0, final double arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos2dMESA(final double arg0, final double arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos2dv(final DoubleBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos2dv(final double[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos2dvARB(final DoubleBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos2dvARB(final double[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos2dvMESA(final DoubleBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos2dvMESA(final double[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos2f(final float arg0, final float arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos2fARB(final float arg0, final float arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos2fMESA(final float arg0, final float arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos2fv(final FloatBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos2fv(final float[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos2fvARB(final FloatBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos2fvARB(final float[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos2fvMESA(final FloatBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos2fvMESA(final float[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos2i(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos2iARB(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos2iMESA(final int arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos2iv(final IntBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos2iv(final int[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos2ivARB(final IntBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos2ivARB(final int[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos2ivMESA(final IntBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos2ivMESA(final int[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos2s(final short arg0, final short arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos2sARB(final short arg0, final short arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos2sMESA(final short arg0, final short arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos2sv(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos2sv(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos2svARB(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos2svARB(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos2svMESA(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos2svMESA(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos3d(final double arg0, final double arg1, final double arg2)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos3dARB(final double arg0, final double arg1, final double arg2)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos3dMESA(final double arg0, final double arg1, final double arg2)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos3dv(final DoubleBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos3dv(final double[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos3dvARB(final DoubleBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos3dvARB(final double[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos3dvMESA(final DoubleBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos3dvMESA(final double[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos3f(final float arg0, final float arg1, final float arg2)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos3fARB(final float arg0, final float arg1, final float arg2)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos3fMESA(final float arg0, final float arg1, final float arg2)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos3fv(final FloatBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos3fv(final float[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos3fvARB(final FloatBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos3fvARB(final float[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos3fvMESA(final FloatBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos3fvMESA(final float[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos3i(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos3iARB(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos3iMESA(final int arg0, final int arg1, final int arg2)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos3iv(final IntBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos3iv(final int[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos3ivARB(final IntBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos3ivARB(final int[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos3ivMESA(final IntBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos3ivMESA(final int[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos3s(final short arg0, final short arg1, final short arg2)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos3sARB(final short arg0, final short arg1, final short arg2)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos3sMESA(final short arg0, final short arg1, final short arg2)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos3sv(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos3sv(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos3svARB(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos3svARB(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos3svMESA(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos3svMESA(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos4dMESA(final double arg0, final double arg1, final double arg2, final double arg3)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos4dvMESA(final DoubleBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos4dvMESA(final double[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos4fMESA(final float arg0, final float arg1, final float arg2, final float arg3)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos4fvMESA(final FloatBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos4fvMESA(final float[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos4iMESA(final int arg0, final int arg1, final int arg2, final int arg3)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos4ivMESA(final IntBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos4ivMESA(final int[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos4sMESA(final short arg0, final short arg1, final short arg2, final short arg3)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos4svMESA(final ShortBuffer arg0)
    {
    // Stub method only.

    }

    @Override
    public void glWindowPos4svMESA(final short[] arg0, final int arg1)
    {
    // Stub method only.

    }

    @Override
    public void glWriteMaskEXT(final int arg0, final int arg1, final int arg2, final int arg3, final int arg4, final int arg5)
    {
    // Stub method only.

    }

    @Override
    public boolean isExtensionAvailable(final String arg0)
    {
        // Stub method only.
        return false;
    }

    @Override
    public boolean isFunctionAvailable(final String arg0)
    {
        // Stub method only.
        return false;
    }

    @Override
    public void setSwapInterval(final int arg0)
    {
    // Stub method only.

    }

}
