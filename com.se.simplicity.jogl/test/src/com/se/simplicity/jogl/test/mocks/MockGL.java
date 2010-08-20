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
	public Object getExtension(String arg0)
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
	public void glAccum(int arg0, float arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glActiveStencilFaceEXT(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glActiveTexture(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glActiveVaryingNV(int arg0, ByteBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glActiveVaryingNV(int arg0, byte[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public ByteBuffer glAllocateMemoryNV(int arg0, float arg1, float arg2, float arg3)
	{
		// Stub method only.
		return null;
	}

	@Override
	public void glAlphaFragmentOp1ATI(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glAlphaFragmentOp2ATI(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8)
	{
		// Stub method only.
		
	}

	@Override
	public void glAlphaFragmentOp3ATI(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8,
			int arg9, int arg10, int arg11)
	{
		// Stub method only.
		
	}

	@Override
	public void glAlphaFunc(int arg0, float arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glApplyTextureEXT(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public boolean glAreProgramsResidentNV(int arg0, IntBuffer arg1, ByteBuffer arg2)
	{
		// Stub method only.
		return false;
	}

	@Override
	public boolean glAreProgramsResidentNV(int arg0, int[] arg1, int arg2, byte[] arg3, int arg4)
	{
		// Stub method only.
		return false;
	}

	@Override
	public boolean glAreTexturesResident(int arg0, IntBuffer arg1, ByteBuffer arg2)
	{
		// Stub method only.
		return false;
	}

	@Override
	public boolean glAreTexturesResident(int arg0, int[] arg1, int arg2, byte[] arg3, int arg4)
	{
		// Stub method only.
		return false;
	}

	@Override
	public void glArrayElement(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glArrayObjectATI(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glAsyncMarkerSGIX(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glAttachObjectARB(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glAttachShader(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glBegin(int arg0)
	{
		addMethodCall("glBegin", new Object[] {arg0});
		
	}

	@Override
	public void glBeginFragmentShaderATI()
	{
		// Stub method only.
		
	}

	@Override
	public void glBeginOcclusionQueryNV(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glBeginQuery(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glBeginQueryARB(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glBeginTransformFeedbackNV(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glBeginVertexShaderEXT()
	{
		// Stub method only.
		
	}

	@Override
	public void glBindAttribLocation(int arg0, int arg1, String arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glBindAttribLocationARB(int arg0, int arg1, String arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glBindBuffer(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glBindBufferARB(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glBindBufferBaseNV(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glBindBufferOffsetNV(int arg0, int arg1, int arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glBindBufferRangeNV(int arg0, int arg1, int arg2, int arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glBindFragDataLocationEXT(int arg0, int arg1, ByteBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glBindFragDataLocationEXT(int arg0, int arg1, byte[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glBindFragmentShaderATI(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glBindFramebufferEXT(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public int glBindLightParameterEXT(int arg0, int arg1)
	{
		// Stub method only.
		return 0;
	}

	@Override
	public int glBindMaterialParameterEXT(int arg0, int arg1)
	{
		// Stub method only.
		return 0;
	}

	@Override
	public int glBindParameterEXT(int arg0)
	{
		// Stub method only.
		return 0;
	}

	@Override
	public void glBindProgramARB(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glBindProgramNV(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glBindRenderbufferEXT(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public int glBindTexGenParameterEXT(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		return 0;
	}

	@Override
	public void glBindTexture(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public int glBindTextureUnitParameterEXT(int arg0, int arg1)
	{
		// Stub method only.
		return 0;
	}

	@Override
	public void glBindVertexArrayAPPLE(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glBindVertexShaderEXT(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glBitmap(int arg0, int arg1, float arg2, float arg3, float arg4, float arg5, ByteBuffer arg6)
	{
		// Stub method only.
		
	}

	@Override
	public void glBitmap(int arg0, int arg1, float arg2, float arg3, float arg4, float arg5, long arg6)
	{
		// Stub method only.
		
	}

	@Override
	public void glBitmap(int arg0, int arg1, float arg2, float arg3, float arg4, float arg5, byte[] arg6, int arg7)
	{
		// Stub method only.
		
	}

	@Override
	public void glBlendColor(float arg0, float arg1, float arg2, float arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glBlendEquation(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glBlendEquationSeparate(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glBlendEquationSeparateEXT(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glBlendFunc(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glBlendFuncSeparate(int arg0, int arg1, int arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glBlendFuncSeparateEXT(int arg0, int arg1, int arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glBlendFuncSeparateINGR(int arg0, int arg1, int arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glBlitFramebufferEXT(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8,
			int arg9)
	{
		// Stub method only.
		
	}

	@Override
	public void glBufferData(int arg0, int arg1, Buffer arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glBufferDataARB(int arg0, int arg1, Buffer arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glBufferParameteriAPPLE(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public int glBufferRegionEnabled()
	{
		// Stub method only.
		return 0;
	}

	@Override
	public void glBufferSubData(int arg0, int arg1, int arg2, Buffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glBufferSubDataARB(int arg0, int arg1, int arg2, Buffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glCallList(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glCallLists(int arg0, int arg1, Buffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public int glCheckFramebufferStatusEXT(int arg0)
	{
		// Stub method only.
		return 0;
	}

	@Override
	public void glClampColorARB(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glClear(int arg0)
	{
		addMethodCall("glClear", new Object[] {arg0});
		
	}

	@Override
	public void glClearAccum(float arg0, float arg1, float arg2, float arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glClearColor(float arg0, float arg1, float arg2, float arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glClearColorIiEXT(int arg0, int arg1, int arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glClearColorIuiEXT(int arg0, int arg1, int arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glClearDepth(double arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glClearDepthdNV(double arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glClearIndex(float arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glClearStencil(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glClientActiveTexture(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glClientActiveVertexStreamATI(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glClipPlane(int arg0, DoubleBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glClipPlane(int arg0, double[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor3b(byte arg0, byte arg1, byte arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor3bv(ByteBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor3bv(byte[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor3d(double arg0, double arg1, double arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor3dv(DoubleBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor3dv(double[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor3f(float arg0, float arg1, float arg2)
	{
	    addMethodCall("glColor3f", new Object[] {arg0, arg1, arg2});
		
	}

	@Override
	public void glColor3fVertex3fSUN(float arg0, float arg1, float arg2, float arg3, float arg4, float arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor3fVertex3fvSUN(FloatBuffer arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor3fVertex3fvSUN(float[] arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor3fv(FloatBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor3fv(float[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor3hNV(short arg0, short arg1, short arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor3hvNV(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor3hvNV(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor3i(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor3iv(IntBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor3iv(int[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor3s(short arg0, short arg1, short arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor3sv(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor3sv(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor3ub(byte arg0, byte arg1, byte arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor3ubv(ByteBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor3ubv(byte[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor3ui(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor3uiv(IntBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor3uiv(int[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor3us(short arg0, short arg1, short arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor3usv(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor3usv(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor4b(byte arg0, byte arg1, byte arg2, byte arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor4bv(ByteBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor4bv(byte[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor4d(double arg0, double arg1, double arg2, double arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor4dv(DoubleBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor4dv(double[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor4f(float arg0, float arg1, float arg2, float arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor4fNormal3fVertex3fSUN(float arg0, float arg1, float arg2, float arg3, float arg4, float arg5, float arg6,
			float arg7, float arg8, float arg9)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor4fNormal3fVertex3fvSUN(FloatBuffer arg0, FloatBuffer arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor4fNormal3fVertex3fvSUN(float[] arg0, int arg1, float[] arg2, int arg3, float[] arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor4fv(FloatBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor4fv(float[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor4hNV(short arg0, short arg1, short arg2, short arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor4hvNV(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor4hvNV(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor4i(int arg0, int arg1, int arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor4iv(IntBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor4iv(int[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor4s(short arg0, short arg1, short arg2, short arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor4sv(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor4sv(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor4ub(byte arg0, byte arg1, byte arg2, byte arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor4ubVertex2fSUN(byte arg0, byte arg1, byte arg2, byte arg3, float arg4, float arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor4ubVertex2fvSUN(ByteBuffer arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor4ubVertex2fvSUN(byte[] arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor4ubVertex3fSUN(byte arg0, byte arg1, byte arg2, byte arg3, float arg4, float arg5, float arg6)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor4ubVertex3fvSUN(ByteBuffer arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor4ubVertex3fvSUN(byte[] arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor4ubv(ByteBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor4ubv(byte[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor4ui(int arg0, int arg1, int arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor4uiv(IntBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor4uiv(int[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor4us(short arg0, short arg1, short arg2, short arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor4usv(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glColor4usv(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glColorFragmentOp1ATI(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6)
	{
		// Stub method only.
		
	}

	@Override
	public void glColorFragmentOp2ATI(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8,
			int arg9)
	{
		// Stub method only.
		
	}

	@Override
	public void glColorFragmentOp3ATI(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8,
			int arg9, int arg10, int arg11, int arg12)
	{
		// Stub method only.
		
	}

	@Override
	public void glColorMask(boolean arg0, boolean arg1, boolean arg2, boolean arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glColorMaskIndexedEXT(int arg0, boolean arg1, boolean arg2, boolean arg3, boolean arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glColorMaterial(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glColorPointer(int arg0, int arg1, int arg2, Buffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glColorPointer(int arg0, int arg1, int arg2, long arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glColorSubTable(int arg0, int arg1, int arg2, int arg3, int arg4, Buffer arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glColorSubTable(int arg0, int arg1, int arg2, int arg3, int arg4, long arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glColorTable(int arg0, int arg1, int arg2, int arg3, int arg4, Buffer arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glColorTable(int arg0, int arg1, int arg2, int arg3, int arg4, long arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glColorTableEXT(int arg0, int arg1, int arg2, int arg3, int arg4, Buffer arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glColorTableParameterfv(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glColorTableParameterfv(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glColorTableParameteriv(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glColorTableParameteriv(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glCombinerInputNV(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glCombinerOutputNV(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, boolean arg7,
			boolean arg8, boolean arg9)
	{
		// Stub method only.
		
	}

	@Override
	public void glCombinerParameterfNV(int arg0, float arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glCombinerParameterfvNV(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glCombinerParameterfvNV(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glCombinerParameteriNV(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glCombinerParameterivNV(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glCombinerParameterivNV(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glCombinerStageParameterfvNV(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glCombinerStageParameterfvNV(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glCompileShader(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glCompileShaderARB(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glCompressedTexImage1D(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, Buffer arg6)
	{
		// Stub method only.
		
	}

	@Override
	public void glCompressedTexImage1D(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, long arg6)
	{
		// Stub method only.
		
	}

	@Override
	public void glCompressedTexImage2D(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, Buffer arg7)
	{
		// Stub method only.
		
	}

	@Override
	public void glCompressedTexImage2D(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, long arg7)
	{
		// Stub method only.
		
	}

	@Override
	public void glCompressedTexImage3D(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, Buffer arg8)
	{
		// Stub method only.
		
	}

	@Override
	public void glCompressedTexImage3D(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, long arg8)
	{
		// Stub method only.
		
	}

	@Override
	public void glCompressedTexSubImage1D(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, Buffer arg6)
	{
		// Stub method only.
		
	}

	@Override
	public void glCompressedTexSubImage1D(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, long arg6)
	{
		// Stub method only.
		
	}

	@Override
	public void glCompressedTexSubImage2D(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7,
			Buffer arg8)
	{
		// Stub method only.
		
	}

	@Override
	public void glCompressedTexSubImage2D(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7,
			long arg8)
	{
		// Stub method only.
		
	}

	@Override
	public void glCompressedTexSubImage3D(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7,
			int arg8, int arg9, Buffer arg10)
	{
		// Stub method only.
		
	}

	@Override
	public void glCompressedTexSubImage3D(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7,
			int arg8, int arg9, long arg10)
	{
		// Stub method only.
		
	}

	@Override
	public void glConvolutionFilter1D(int arg0, int arg1, int arg2, int arg3, int arg4, Buffer arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glConvolutionFilter1D(int arg0, int arg1, int arg2, int arg3, int arg4, long arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glConvolutionFilter2D(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, Buffer arg6)
	{
		// Stub method only.
		
	}

	@Override
	public void glConvolutionFilter2D(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, long arg6)
	{
		// Stub method only.
		
	}

	@Override
	public void glConvolutionParameterf(int arg0, int arg1, float arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glConvolutionParameterfv(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glConvolutionParameterfv(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glConvolutionParameteri(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glConvolutionParameteriv(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glConvolutionParameteriv(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glCopyColorSubTable(int arg0, int arg1, int arg2, int arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glCopyColorTable(int arg0, int arg1, int arg2, int arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glCopyConvolutionFilter1D(int arg0, int arg1, int arg2, int arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glCopyConvolutionFilter2D(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glCopyPixels(int arg0, int arg1, int arg2, int arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glCopyTexImage1D(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6)
	{
		// Stub method only.
		
	}

	@Override
	public void glCopyTexImage2D(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7)
	{
		// Stub method only.
		
	}

	@Override
	public void glCopyTexSubImage1D(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glCopyTexSubImage2D(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7)
	{
		// Stub method only.
		
	}

	@Override
	public void glCopyTexSubImage3D(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8)
	{
		// Stub method only.
		
	}

	@Override
	public int glCreateProgram()
	{
		// Stub method only.
		return 0;
	}

	@Override
	public int glCreateProgramObjectARB()
	{
		// Stub method only.
		return 0;
	}

	@Override
	public int glCreateShader(int arg0)
	{
		// Stub method only.
		return 0;
	}

	@Override
	public int glCreateShaderObjectARB(int arg0)
	{
		// Stub method only.
		return 0;
	}

	@Override
	public void glCullFace(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glCullParameterdvEXT(int arg0, DoubleBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glCullParameterdvEXT(int arg0, double[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glCullParameterfvEXT(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glCullParameterfvEXT(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glCurrentPaletteMatrixARB(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glDeformSGIX(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glDeformationMap3dSGIX(int arg0, double arg1, double arg2, int arg3, int arg4, double arg5, double arg6,
			int arg7, int arg8, double arg9, double arg10, int arg11, int arg12, DoubleBuffer arg13)
	{
		// Stub method only.
		
	}

	@Override
	public void glDeformationMap3dSGIX(int arg0, double arg1, double arg2, int arg3, int arg4, double arg5, double arg6,
			int arg7, int arg8, double arg9, double arg10, int arg11, int arg12, double[] arg13, int arg14)
	{
		// Stub method only.
		
	}

	@Override
	public void glDeformationMap3fSGIX(int arg0, float arg1, float arg2, int arg3, int arg4, float arg5, float arg6, int arg7,
			int arg8, float arg9, float arg10, int arg11, int arg12, FloatBuffer arg13)
	{
		// Stub method only.
		
	}

	@Override
	public void glDeformationMap3fSGIX(int arg0, float arg1, float arg2, int arg3, int arg4, float arg5, float arg6, int arg7,
			int arg8, float arg9, float arg10, int arg11, int arg12, float[] arg13, int arg14)
	{
		// Stub method only.
		
	}

	@Override
	public void glDeleteAsyncMarkersSGIX(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glDeleteBufferRegion(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glDeleteBuffers(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glDeleteBuffers(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glDeleteBuffersARB(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glDeleteBuffersARB(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glDeleteFencesAPPLE(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glDeleteFencesAPPLE(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glDeleteFencesNV(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glDeleteFencesNV(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glDeleteFragmentShaderATI(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glDeleteFramebuffersEXT(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glDeleteFramebuffersEXT(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glDeleteLists(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glDeleteObjectARB(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glDeleteOcclusionQueriesNV(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glDeleteOcclusionQueriesNV(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glDeleteProgram(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glDeleteProgramsARB(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glDeleteProgramsARB(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glDeleteProgramsNV(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glDeleteProgramsNV(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glDeleteQueries(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glDeleteQueries(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glDeleteQueriesARB(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glDeleteQueriesARB(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glDeleteRenderbuffersEXT(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glDeleteRenderbuffersEXT(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glDeleteShader(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glDeleteTextures(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glDeleteTextures(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glDeleteVertexArraysAPPLE(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glDeleteVertexArraysAPPLE(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glDeleteVertexShaderEXT(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glDepthBoundsEXT(double arg0, double arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glDepthBoundsdNV(double arg0, double arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glDepthFunc(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glDepthMask(boolean arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glDepthRange(double arg0, double arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glDepthRangedNV(double arg0, double arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glDetachObjectARB(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glDetachShader(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glDetailTexFuncSGIS(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glDetailTexFuncSGIS(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glDisable(int arg0)
	{
		addMethodCall("glDisable", new Object[] {arg0});
		
	}

	@Override
	public void glDisableClientState(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glDisableIndexedEXT(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glDisableVariantClientStateEXT(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glDisableVertexAttribAPPLE(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glDisableVertexAttribArray(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glDisableVertexAttribArrayARB(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glDrawArrays(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glDrawArraysInstancedEXT(int arg0, int arg1, int arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glDrawBuffer(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glDrawBufferRegion(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6)
	{
		// Stub method only.
		
	}

	@Override
	public void glDrawBuffers(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glDrawBuffers(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glDrawBuffersARB(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glDrawBuffersARB(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glDrawBuffersATI(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glDrawBuffersATI(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glDrawElementArrayAPPLE(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glDrawElementArrayATI(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glDrawElements(int arg0, int arg1, int arg2, Buffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glDrawElements(int arg0, int arg1, int arg2, long arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glDrawElementsInstancedEXT(int arg0, int arg1, int arg2, Buffer arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glDrawMeshArraysSUN(int arg0, int arg1, int arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glDrawPixels(int arg0, int arg1, int arg2, int arg3, Buffer arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glDrawPixels(int arg0, int arg1, int arg2, int arg3, long arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glDrawRangeElementArrayAPPLE(int arg0, int arg1, int arg2, int arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glDrawRangeElementArrayATI(int arg0, int arg1, int arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glDrawRangeElements(int arg0, int arg1, int arg2, int arg3, int arg4, Buffer arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glDrawRangeElements(int arg0, int arg1, int arg2, int arg3, int arg4, long arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glEdgeFlag(boolean arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glEdgeFlagPointer(int arg0, Buffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glEdgeFlagPointer(int arg0, long arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glEdgeFlagv(ByteBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glEdgeFlagv(byte[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glElementPointerAPPLE(int arg0, Buffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glElementPointerATI(int arg0, Buffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glElementPointerATI(int arg0, long arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glEnable(int arg0)
	{
		addMethodCall("glEnable", new Object[] {arg0});
		
	}

	@Override
	public void glEnableClientState(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glEnableIndexedEXT(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glEnableVariantClientStateEXT(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glEnableVertexAttribAPPLE(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glEnableVertexAttribArray(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glEnableVertexAttribArrayARB(int arg0)
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
	public void glEndQuery(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glEndQueryARB(int arg0)
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
	public void glEvalCoord1d(double arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glEvalCoord1dv(DoubleBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glEvalCoord1dv(double[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glEvalCoord1f(float arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glEvalCoord1fv(FloatBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glEvalCoord1fv(float[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glEvalCoord2d(double arg0, double arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glEvalCoord2dv(DoubleBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glEvalCoord2dv(double[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glEvalCoord2f(float arg0, float arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glEvalCoord2fv(FloatBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glEvalCoord2fv(float[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glEvalMapsNV(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glEvalMesh1(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glEvalMesh2(int arg0, int arg1, int arg2, int arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glEvalPoint1(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glEvalPoint2(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glExecuteProgramNV(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glExecuteProgramNV(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glExtractComponentEXT(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glFeedbackBuffer(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glFinalCombinerInputNV(int arg0, int arg1, int arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glFinish()
	{
		// Stub method only.
		
	}

	@Override
	public int glFinishAsyncSGIX(IntBuffer arg0)
	{
		// Stub method only.
		return 0;
	}

	@Override
	public int glFinishAsyncSGIX(int[] arg0, int arg1)
	{
		// Stub method only.
		return 0;
	}

	@Override
	public void glFinishFenceAPPLE(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glFinishFenceNV(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glFinishObjectAPPLE(int arg0, int arg1)
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
	public void glFlushMappedBufferRangeAPPLE(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glFlushPixelDataRangeNV(int arg0)
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
	public void glFlushVertexArrayRangeAPPLE(int arg0, Buffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glFlushVertexArrayRangeNV()
	{
		// Stub method only.
		
	}

	@Override
	public void glFogCoordPointer(int arg0, int arg1, Buffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glFogCoordPointer(int arg0, int arg1, long arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glFogCoordPointerEXT(int arg0, int arg1, Buffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glFogCoordPointerEXT(int arg0, int arg1, long arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glFogCoordd(double arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glFogCoorddEXT(double arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glFogCoorddv(DoubleBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glFogCoorddv(double[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glFogCoorddvEXT(DoubleBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glFogCoorddvEXT(double[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glFogCoordf(float arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glFogCoordfEXT(float arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glFogCoordfv(FloatBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glFogCoordfv(float[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glFogCoordfvEXT(FloatBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glFogCoordfvEXT(float[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glFogCoordhNV(short arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glFogCoordhvNV(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glFogCoordhvNV(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glFogFuncSGIS(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glFogFuncSGIS(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glFogf(int arg0, float arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glFogfv(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glFogfv(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glFogi(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glFogiv(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glFogiv(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glFragmentColorMaterialSGIX(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glFragmentLightModelfSGIX(int arg0, float arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glFragmentLightModelfvSGIX(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glFragmentLightModelfvSGIX(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glFragmentLightModeliSGIX(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glFragmentLightModelivSGIX(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glFragmentLightModelivSGIX(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glFragmentLightfSGIX(int arg0, int arg1, float arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glFragmentLightfvSGIX(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glFragmentLightfvSGIX(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glFragmentLightiSGIX(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glFragmentLightivSGIX(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glFragmentLightivSGIX(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glFragmentMaterialfSGIX(int arg0, int arg1, float arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glFragmentMaterialfvSGIX(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glFragmentMaterialfvSGIX(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glFragmentMaterialiSGIX(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glFragmentMaterialivSGIX(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glFragmentMaterialivSGIX(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glFrameZoomSGIX(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glFramebufferRenderbufferEXT(int arg0, int arg1, int arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glFramebufferTexture1DEXT(int arg0, int arg1, int arg2, int arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glFramebufferTexture2DEXT(int arg0, int arg1, int arg2, int arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glFramebufferTexture3DEXT(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glFramebufferTextureEXT(int arg0, int arg1, int arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glFramebufferTextureFaceEXT(int arg0, int arg1, int arg2, int arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glFramebufferTextureLayerEXT(int arg0, int arg1, int arg2, int arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glFreeObjectBufferATI(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glFrontFace(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glFrustum(double arg0, double arg1, double arg2, double arg3, double arg4, double arg5)
	{
		addMethodCall("glFrustum", new Object[] {arg0, arg1, arg2, arg3, arg4, arg5});
		
	}

	@Override
	public int glGenAsyncMarkersSGIX(int arg0)
	{
		// Stub method only.
		return 0;
	}

	@Override
	public void glGenBuffers(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glGenBuffers(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGenBuffersARB(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glGenBuffersARB(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGenFencesAPPLE(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glGenFencesAPPLE(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGenFencesNV(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glGenFencesNV(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public int glGenFragmentShadersATI(int arg0)
	{
		// Stub method only.
		return 0;
	}

	@Override
	public void glGenFramebuffersEXT(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glGenFramebuffersEXT(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public int glGenLists(int arg0)
	{
		// Stub method only.
		return 0;
	}

	@Override
	public void glGenOcclusionQueriesNV(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glGenOcclusionQueriesNV(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGenProgramsARB(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glGenProgramsARB(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGenProgramsNV(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glGenProgramsNV(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGenQueries(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glGenQueries(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGenQueriesARB(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glGenQueriesARB(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGenRenderbuffersEXT(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glGenRenderbuffersEXT(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public int glGenSymbolsEXT(int arg0, int arg1, int arg2, int arg3)
	{
		// Stub method only.
		return 0;
	}

	@Override
	public void glGenTextures(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glGenTextures(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGenVertexArraysAPPLE(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glGenVertexArraysAPPLE(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public int glGenVertexShadersEXT(int arg0)
	{
		// Stub method only.
		return 0;
	}

	@Override
	public void glGenerateMipmapEXT(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetActiveAttrib(int arg0, int arg1, int arg2, IntBuffer arg3, IntBuffer arg4, IntBuffer arg5, ByteBuffer arg6)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetActiveAttrib(int arg0, int arg1, int arg2, int[] arg3, int arg4, int[] arg5, int arg6, int[] arg7, int arg8,
			byte[] arg9, int arg10)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetActiveAttribARB(int arg0, int arg1, int arg2, IntBuffer arg3, IntBuffer arg4, IntBuffer arg5, ByteBuffer arg6)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetActiveAttribARB(int arg0, int arg1, int arg2, int[] arg3, int arg4, int[] arg5, int arg6, int[] arg7,
			int arg8, byte[] arg9, int arg10)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetActiveUniform(int arg0, int arg1, int arg2, IntBuffer arg3, IntBuffer arg4, IntBuffer arg5, ByteBuffer arg6)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetActiveUniform(int arg0, int arg1, int arg2, int[] arg3, int arg4, int[] arg5, int arg6, int[] arg7,
			int arg8, byte[] arg9, int arg10)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetActiveUniformARB(int arg0, int arg1, int arg2, IntBuffer arg3, IntBuffer arg4, IntBuffer arg5,
			ByteBuffer arg6)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetActiveUniformARB(int arg0, int arg1, int arg2, int[] arg3, int arg4, int[] arg5, int arg6, int[] arg7,
			int arg8, byte[] arg9, int arg10)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetActiveVaryingNV(int arg0, int arg1, int arg2, IntBuffer arg3, IntBuffer arg4, IntBuffer arg5, ByteBuffer arg6)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetActiveVaryingNV(int arg0, int arg1, int arg2, int[] arg3, int arg4, int[] arg5, int arg6, int[] arg7,
			int arg8, byte[] arg9, int arg10)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetArrayObjectfvATI(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetArrayObjectfvATI(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetArrayObjectivATI(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetArrayObjectivATI(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetAttachedObjectsARB(int arg0, int arg1, IntBuffer arg2, IntBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetAttachedObjectsARB(int arg0, int arg1, int[] arg2, int arg3, int[] arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetAttachedShaders(int arg0, int arg1, IntBuffer arg2, IntBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetAttachedShaders(int arg0, int arg1, int[] arg2, int arg3, int[] arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public int glGetAttribLocation(int arg0, String arg1)
	{
		// Stub method only.
		return 0;
	}

	@Override
	public int glGetAttribLocationARB(int arg0, String arg1)
	{
		// Stub method only.
		return 0;
	}

	@Override
	public void glGetBooleanIndexedvEXT(int arg0, int arg1, ByteBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetBooleanIndexedvEXT(int arg0, int arg1, byte[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetBooleanv(int arg0, ByteBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetBooleanv(int arg0, byte[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetBufferParameteriv(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetBufferParameteriv(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetBufferParameterivARB(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetBufferParameterivARB(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetBufferSubData(int arg0, int arg1, int arg2, Buffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetBufferSubDataARB(int arg0, int arg1, int arg2, Buffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetClipPlane(int arg0, DoubleBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetClipPlane(int arg0, double[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetColorTable(int arg0, int arg1, int arg2, Buffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetColorTable(int arg0, int arg1, int arg2, long arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetColorTableEXT(int arg0, int arg1, int arg2, Buffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetColorTableParameterfv(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetColorTableParameterfv(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetColorTableParameterfvEXT(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetColorTableParameterfvEXT(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetColorTableParameteriv(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetColorTableParameteriv(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetColorTableParameterivEXT(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetColorTableParameterivEXT(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetCombinerInputParameterfvNV(int arg0, int arg1, int arg2, int arg3, FloatBuffer arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetCombinerInputParameterfvNV(int arg0, int arg1, int arg2, int arg3, float[] arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetCombinerInputParameterivNV(int arg0, int arg1, int arg2, int arg3, IntBuffer arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetCombinerInputParameterivNV(int arg0, int arg1, int arg2, int arg3, int[] arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetCombinerOutputParameterfvNV(int arg0, int arg1, int arg2, FloatBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetCombinerOutputParameterfvNV(int arg0, int arg1, int arg2, float[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetCombinerOutputParameterivNV(int arg0, int arg1, int arg2, IntBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetCombinerOutputParameterivNV(int arg0, int arg1, int arg2, int[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetCombinerStageParameterfvNV(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetCombinerStageParameterfvNV(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetCompressedTexImage(int arg0, int arg1, Buffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetCompressedTexImage(int arg0, int arg1, long arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetConvolutionFilter(int arg0, int arg1, int arg2, Buffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetConvolutionFilter(int arg0, int arg1, int arg2, long arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetConvolutionParameterfv(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetConvolutionParameterfv(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetConvolutionParameteriv(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetConvolutionParameteriv(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetDetailTexFuncSGIS(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetDetailTexFuncSGIS(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetDoublev(int arg0, DoubleBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetDoublev(int arg0, double[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public int glGetError()
	{
		// Stub method only.
		return 0;
	}

	@Override
	public void glGetFenceivNV(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetFenceivNV(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetFinalCombinerInputParameterfvNV(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetFinalCombinerInputParameterfvNV(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetFinalCombinerInputParameterivNV(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetFinalCombinerInputParameterivNV(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetFloatv(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetFloatv(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetFogFuncSGIS(FloatBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetFogFuncSGIS(float[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public int glGetFragDataLocationEXT(int arg0, ByteBuffer arg1)
	{
		// Stub method only.
		return 0;
	}

	@Override
	public int glGetFragDataLocationEXT(int arg0, byte[] arg1, int arg2)
	{
		// Stub method only.
		return 0;
	}

	@Override
	public void glGetFragmentLightfvSGIX(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetFragmentLightfvSGIX(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetFragmentLightivSGIX(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetFragmentLightivSGIX(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetFragmentMaterialfvSGIX(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetFragmentMaterialfvSGIX(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetFragmentMaterialivSGIX(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetFragmentMaterialivSGIX(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetFramebufferAttachmentParameterivEXT(int arg0, int arg1, int arg2, IntBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetFramebufferAttachmentParameterivEXT(int arg0, int arg1, int arg2, int[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public int glGetHandleARB(int arg0)
	{
		// Stub method only.
		return 0;
	}

	@Override
	public void glGetHistogram(int arg0, boolean arg1, int arg2, int arg3, Buffer arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetHistogram(int arg0, boolean arg1, int arg2, int arg3, long arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetHistogramParameterfv(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetHistogramParameterfv(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetHistogramParameteriv(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetHistogramParameteriv(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetImageTransformParameterfvHP(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetImageTransformParameterfvHP(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetImageTransformParameterivHP(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetImageTransformParameterivHP(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetInfoLogARB(int arg0, int arg1, IntBuffer arg2, ByteBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetInfoLogARB(int arg0, int arg1, int[] arg2, int arg3, byte[] arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public int glGetInstrumentsSGIX()
	{
		// Stub method only.
		return 0;
	}

	@Override
	public void glGetIntegerIndexedvEXT(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetIntegerIndexedvEXT(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetIntegerv(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetIntegerv(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetInvariantBooleanvEXT(int arg0, int arg1, ByteBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetInvariantBooleanvEXT(int arg0, int arg1, byte[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetInvariantFloatvEXT(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetInvariantFloatvEXT(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetInvariantIntegervEXT(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetInvariantIntegervEXT(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetLightfv(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetLightfv(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetLightiv(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetLightiv(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetListParameterfvSGIX(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetListParameterfvSGIX(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetListParameterivSGIX(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetListParameterivSGIX(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetLocalConstantBooleanvEXT(int arg0, int arg1, ByteBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetLocalConstantBooleanvEXT(int arg0, int arg1, byte[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetLocalConstantFloatvEXT(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetLocalConstantFloatvEXT(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetLocalConstantIntegervEXT(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetLocalConstantIntegervEXT(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetMapAttribParameterfvNV(int arg0, int arg1, int arg2, FloatBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetMapAttribParameterfvNV(int arg0, int arg1, int arg2, float[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetMapAttribParameterivNV(int arg0, int arg1, int arg2, IntBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetMapAttribParameterivNV(int arg0, int arg1, int arg2, int[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetMapControlPointsNV(int arg0, int arg1, int arg2, int arg3, int arg4, boolean arg5, Buffer arg6)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetMapParameterfvNV(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetMapParameterfvNV(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetMapParameterivNV(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetMapParameterivNV(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetMapdv(int arg0, int arg1, DoubleBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetMapdv(int arg0, int arg1, double[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetMapfv(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetMapfv(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetMapiv(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetMapiv(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetMaterialfv(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetMaterialfv(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetMaterialiv(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetMaterialiv(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetMinmax(int arg0, boolean arg1, int arg2, int arg3, Buffer arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetMinmax(int arg0, boolean arg1, int arg2, int arg3, long arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetMinmaxParameterfv(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetMinmaxParameterfv(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetMinmaxParameteriv(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetMinmaxParameteriv(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetObjectBufferfvATI(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetObjectBufferfvATI(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetObjectBufferivATI(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetObjectBufferivATI(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetObjectParameterfvARB(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetObjectParameterfvARB(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetObjectParameterivARB(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetObjectParameterivARB(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetOcclusionQueryivNV(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetOcclusionQueryivNV(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetOcclusionQueryuivNV(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetOcclusionQueryuivNV(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetPixelMapfv(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetPixelMapfv(int arg0, long arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetPixelMapfv(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetPixelMapuiv(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetPixelMapuiv(int arg0, long arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetPixelMapuiv(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetPixelMapusv(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetPixelMapusv(int arg0, long arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetPixelMapusv(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetPixelTexGenParameterfvSGIS(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetPixelTexGenParameterfvSGIS(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetPixelTexGenParameterivSGIS(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetPixelTexGenParameterivSGIS(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetPolygonStipple(ByteBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetPolygonStipple(long arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetPolygonStipple(byte[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetProgramEnvParameterIivNV(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetProgramEnvParameterIivNV(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetProgramEnvParameterIuivNV(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetProgramEnvParameterIuivNV(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetProgramEnvParameterdvARB(int arg0, int arg1, DoubleBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetProgramEnvParameterdvARB(int arg0, int arg1, double[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetProgramEnvParameterfvARB(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetProgramEnvParameterfvARB(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetProgramInfoLog(int arg0, int arg1, IntBuffer arg2, ByteBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetProgramInfoLog(int arg0, int arg1, int[] arg2, int arg3, byte[] arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetProgramLocalParameterIivNV(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetProgramLocalParameterIivNV(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetProgramLocalParameterIuivNV(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetProgramLocalParameterIuivNV(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetProgramLocalParameterdvARB(int arg0, int arg1, DoubleBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetProgramLocalParameterdvARB(int arg0, int arg1, double[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetProgramLocalParameterfvARB(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetProgramLocalParameterfvARB(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetProgramNamedParameterdvNV(int arg0, int arg1, String arg2, DoubleBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetProgramNamedParameterdvNV(int arg0, int arg1, String arg2, double[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetProgramNamedParameterfvNV(int arg0, int arg1, String arg2, FloatBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetProgramNamedParameterfvNV(int arg0, int arg1, String arg2, float[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetProgramParameterdvNV(int arg0, int arg1, int arg2, DoubleBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetProgramParameterdvNV(int arg0, int arg1, int arg2, double[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetProgramParameterfvNV(int arg0, int arg1, int arg2, FloatBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetProgramParameterfvNV(int arg0, int arg1, int arg2, float[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetProgramStringARB(int arg0, int arg1, Buffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetProgramStringNV(int arg0, int arg1, ByteBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetProgramStringNV(int arg0, int arg1, byte[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetProgramiv(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetProgramiv(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetProgramivARB(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetProgramivARB(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetProgramivNV(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetProgramivNV(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetQueryObjecti64vEXT(int arg0, int arg1, LongBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetQueryObjecti64vEXT(int arg0, int arg1, long[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetQueryObjectiv(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetQueryObjectiv(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetQueryObjectivARB(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetQueryObjectivARB(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetQueryObjectui64vEXT(int arg0, int arg1, LongBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetQueryObjectui64vEXT(int arg0, int arg1, long[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetQueryObjectuiv(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetQueryObjectuiv(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetQueryObjectuivARB(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetQueryObjectuivARB(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetQueryiv(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetQueryiv(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetQueryivARB(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetQueryivARB(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetRenderbufferParameterivEXT(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetRenderbufferParameterivEXT(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetSeparableFilter(int arg0, int arg1, int arg2, Buffer arg3, Buffer arg4, Buffer arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetSeparableFilter(int arg0, int arg1, int arg2, long arg3, long arg4, long arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetShaderInfoLog(int arg0, int arg1, IntBuffer arg2, ByteBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetShaderInfoLog(int arg0, int arg1, int[] arg2, int arg3, byte[] arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetShaderSource(int arg0, int arg1, IntBuffer arg2, ByteBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetShaderSource(int arg0, int arg1, int[] arg2, int arg3, byte[] arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetShaderSourceARB(int arg0, int arg1, IntBuffer arg2, ByteBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetShaderSourceARB(int arg0, int arg1, int[] arg2, int arg3, byte[] arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetShaderiv(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetShaderiv(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetSharpenTexFuncSGIS(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetSharpenTexFuncSGIS(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public String glGetString(int arg0)
	{
		// Stub method only.
		return null;
	}

	@Override
	public void glGetTexBumpParameterfvATI(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetTexBumpParameterfvATI(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetTexBumpParameterivATI(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetTexBumpParameterivATI(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetTexEnvfv(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetTexEnvfv(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetTexEnviv(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetTexEnviv(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetTexFilterFuncSGIS(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetTexFilterFuncSGIS(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetTexGendv(int arg0, int arg1, DoubleBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetTexGendv(int arg0, int arg1, double[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetTexGenfv(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetTexGenfv(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetTexGeniv(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetTexGeniv(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetTexImage(int arg0, int arg1, int arg2, int arg3, Buffer arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetTexImage(int arg0, int arg1, int arg2, int arg3, long arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetTexLevelParameterfv(int arg0, int arg1, int arg2, FloatBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetTexLevelParameterfv(int arg0, int arg1, int arg2, float[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetTexLevelParameteriv(int arg0, int arg1, int arg2, IntBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetTexLevelParameteriv(int arg0, int arg1, int arg2, int[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetTexParameterIivEXT(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetTexParameterIivEXT(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetTexParameterIuivEXT(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetTexParameterIuivEXT(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetTexParameterfv(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetTexParameterfv(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetTexParameteriv(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetTexParameteriv(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetTrackMatrixivNV(int arg0, int arg1, int arg2, IntBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetTrackMatrixivNV(int arg0, int arg1, int arg2, int[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetTransformFeedbackVaryingNV(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetTransformFeedbackVaryingNV(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public int glGetUniformBufferSizeEXT(int arg0, int arg1)
	{
		// Stub method only.
		return 0;
	}

	@Override
	public int glGetUniformLocation(int arg0, String arg1)
	{
		// Stub method only.
		return 0;
	}

	@Override
	public int glGetUniformLocationARB(int arg0, String arg1)
	{
		// Stub method only.
		return 0;
	}

	@Override
	public int glGetUniformOffsetEXT(int arg0, int arg1)
	{
		// Stub method only.
		return 0;
	}

	@Override
	public void glGetUniformfv(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetUniformfv(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetUniformfvARB(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetUniformfvARB(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetUniformiv(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetUniformiv(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetUniformivARB(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetUniformivARB(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetUniformuivEXT(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetUniformuivEXT(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetVariantArrayObjectfvATI(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetVariantArrayObjectfvATI(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetVariantArrayObjectivATI(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetVariantArrayObjectivATI(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetVariantBooleanvEXT(int arg0, int arg1, ByteBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetVariantBooleanvEXT(int arg0, int arg1, byte[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetVariantFloatvEXT(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetVariantFloatvEXT(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetVariantIntegervEXT(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetVariantIntegervEXT(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public int glGetVaryingLocationNV(int arg0, ByteBuffer arg1)
	{
		// Stub method only.
		return 0;
	}

	@Override
	public int glGetVaryingLocationNV(int arg0, byte[] arg1, int arg2)
	{
		// Stub method only.
		return 0;
	}

	@Override
	public void glGetVertexAttribArrayObjectfvATI(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetVertexAttribArrayObjectfvATI(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetVertexAttribArrayObjectivATI(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetVertexAttribArrayObjectivATI(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetVertexAttribIivEXT(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetVertexAttribIivEXT(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetVertexAttribIuivEXT(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetVertexAttribIuivEXT(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetVertexAttribdv(int arg0, int arg1, DoubleBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetVertexAttribdv(int arg0, int arg1, double[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetVertexAttribdvARB(int arg0, int arg1, DoubleBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetVertexAttribdvARB(int arg0, int arg1, double[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetVertexAttribdvNV(int arg0, int arg1, DoubleBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetVertexAttribdvNV(int arg0, int arg1, double[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetVertexAttribfv(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetVertexAttribfv(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetVertexAttribfvARB(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetVertexAttribfvARB(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetVertexAttribfvNV(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetVertexAttribfvNV(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetVertexAttribiv(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetVertexAttribiv(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetVertexAttribivARB(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetVertexAttribivARB(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetVertexAttribivNV(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glGetVertexAttribivNV(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glGlobalAlphaFactorbSUN(byte arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glGlobalAlphaFactordSUN(double arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glGlobalAlphaFactorfSUN(float arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glGlobalAlphaFactoriSUN(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glGlobalAlphaFactorsSUN(short arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glGlobalAlphaFactorubSUN(byte arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glGlobalAlphaFactoruiSUN(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glGlobalAlphaFactorusSUN(short arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glHint(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glHintPGI(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glHistogram(int arg0, int arg1, int arg2, boolean arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glIglooInterfaceSGIX(int arg0, Buffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glImageTransformParameterfHP(int arg0, int arg1, float arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glImageTransformParameterfvHP(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glImageTransformParameterfvHP(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glImageTransformParameteriHP(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glImageTransformParameterivHP(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glImageTransformParameterivHP(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glIndexFuncEXT(int arg0, float arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glIndexMask(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glIndexMaterialEXT(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glIndexPointer(int arg0, int arg1, Buffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glIndexd(double arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glIndexdv(DoubleBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glIndexdv(double[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glIndexf(float arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glIndexfv(FloatBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glIndexfv(float[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glIndexi(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glIndexiv(IntBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glIndexiv(int[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glIndexs(short arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glIndexsv(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glIndexsv(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glIndexub(byte arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glIndexubv(ByteBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glIndexubv(byte[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glInitNames()
	{
		// Stub method only.
		
	}

	@Override
	public void glInsertComponentEXT(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glInstrumentsBufferSGIX(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glInstrumentsBufferSGIX(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glInterleavedArrays(int arg0, int arg1, Buffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glInterleavedArrays(int arg0, int arg1, long arg2)
	{
		// Stub method only.
		
	}

	@Override
	public boolean glIsAsyncMarkerSGIX(int arg0)
	{
		// Stub method only.
		return false;
	}

	@Override
	public boolean glIsBuffer(int arg0)
	{
		// Stub method only.
		return false;
	}

	@Override
	public boolean glIsBufferARB(int arg0)
	{
		// Stub method only.
		return false;
	}

	@Override
	public boolean glIsEnabled(int arg0)
	{
		// Stub method only.
		return false;
	}

	@Override
	public boolean glIsEnabledIndexedEXT(int arg0, int arg1)
	{
		// Stub method only.
		return false;
	}

	@Override
	public boolean glIsFenceAPPLE(int arg0)
	{
		// Stub method only.
		return false;
	}

	@Override
	public boolean glIsFenceNV(int arg0)
	{
		// Stub method only.
		return false;
	}

	@Override
	public boolean glIsFramebufferEXT(int arg0)
	{
		// Stub method only.
		return false;
	}

	@Override
	public boolean glIsList(int arg0)
	{
		// Stub method only.
		return false;
	}

	@Override
	public boolean glIsObjectBufferATI(int arg0)
	{
		// Stub method only.
		return false;
	}

	@Override
	public boolean glIsOcclusionQueryNV(int arg0)
	{
		// Stub method only.
		return false;
	}

	@Override
	public boolean glIsProgram(int arg0)
	{
		// Stub method only.
		return false;
	}

	@Override
	public boolean glIsProgramARB(int arg0)
	{
		// Stub method only.
		return false;
	}

	@Override
	public boolean glIsProgramNV(int arg0)
	{
		// Stub method only.
		return false;
	}

	@Override
	public boolean glIsQuery(int arg0)
	{
		// Stub method only.
		return false;
	}

	@Override
	public boolean glIsQueryARB(int arg0)
	{
		// Stub method only.
		return false;
	}

	@Override
	public boolean glIsRenderbufferEXT(int arg0)
	{
		// Stub method only.
		return false;
	}

	@Override
	public boolean glIsShader(int arg0)
	{
		// Stub method only.
		return false;
	}

	@Override
	public boolean glIsTexture(int arg0)
	{
		// Stub method only.
		return false;
	}

	@Override
	public boolean glIsVariantEnabledEXT(int arg0, int arg1)
	{
		// Stub method only.
		return false;
	}

	@Override
	public boolean glIsVertexArrayAPPLE(int arg0)
	{
		// Stub method only.
		return false;
	}

	@Override
	public boolean glIsVertexAttribEnabledAPPLE(int arg0, int arg1)
	{
		// Stub method only.
		return false;
	}

	@Override
	public void glLightEnviSGIX(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glLightModelf(int arg0, float arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glLightModelfv(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glLightModelfv(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glLightModeli(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glLightModeliv(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glLightModeliv(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glLightf(int arg0, int arg1, float arg2)
	{
	    // Stub method only.
		
	}

	@Override
	public void glLightfv(int arg0, int arg1, FloatBuffer arg2)
	{
	    // Stub method only.
		
	}

	@Override
	public void glLightfv(int arg0, int arg1, float[] arg2, int arg3)
	{
	    addMethodCall("glLightfv", new Object[] {arg0, arg1, arg2});
		
	}

	@Override
	public void glLighti(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glLightiv(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glLightiv(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glLineStipple(int arg0, short arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glLineWidth(float arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glLinkProgram(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glLinkProgramARB(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glListBase(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glListParameterfSGIX(int arg0, int arg1, float arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glListParameterfvSGIX(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glListParameterfvSGIX(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glListParameteriSGIX(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glListParameterivSGIX(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glListParameterivSGIX(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glLoadIdentity()
	{
		addMethodCall("glLoadIdentity", null);
		
	}

	@Override
	public void glLoadIdentityDeformationMapSGIX(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glLoadMatrixd(DoubleBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glLoadMatrixd(double[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glLoadMatrixf(FloatBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glLoadMatrixf(float[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glLoadName(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glLoadProgramNV(int arg0, int arg1, int arg2, String arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glLoadTransposeMatrixd(DoubleBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glLoadTransposeMatrixd(double[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glLoadTransposeMatrixf(FloatBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glLoadTransposeMatrixf(float[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glLockArraysEXT(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glLogicOp(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glMap1d(int arg0, double arg1, double arg2, int arg3, int arg4, DoubleBuffer arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glMap1d(int arg0, double arg1, double arg2, int arg3, int arg4, double[] arg5, int arg6)
	{
		// Stub method only.
		
	}

	@Override
	public void glMap1f(int arg0, float arg1, float arg2, int arg3, int arg4, FloatBuffer arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glMap1f(int arg0, float arg1, float arg2, int arg3, int arg4, float[] arg5, int arg6)
	{
		// Stub method only.
		
	}

	@Override
	public void glMap2d(int arg0, double arg1, double arg2, int arg3, int arg4, double arg5, double arg6, int arg7, int arg8,
			DoubleBuffer arg9)
	{
		// Stub method only.
		
	}

	@Override
	public void glMap2d(int arg0, double arg1, double arg2, int arg3, int arg4, double arg5, double arg6, int arg7, int arg8,
			double[] arg9, int arg10)
	{
		// Stub method only.
		
	}

	@Override
	public void glMap2f(int arg0, float arg1, float arg2, int arg3, int arg4, float arg5, float arg6, int arg7, int arg8,
			FloatBuffer arg9)
	{
		// Stub method only.
		
	}

	@Override
	public void glMap2f(int arg0, float arg1, float arg2, int arg3, int arg4, float arg5, float arg6, int arg7, int arg8,
			float[] arg9, int arg10)
	{
		// Stub method only.
		
	}

	@Override
	public ByteBuffer glMapBuffer(int arg0, int arg1)
	{
		// Stub method only.
		return null;
	}

	@Override
	public ByteBuffer glMapBufferARB(int arg0, int arg1)
	{
		// Stub method only.
		return null;
	}

	@Override
	public void glMapControlPointsNV(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, boolean arg7,
			Buffer arg8)
	{
		// Stub method only.
		
	}

	@Override
	public void glMapGrid1d(int arg0, double arg1, double arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glMapGrid1f(int arg0, float arg1, float arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glMapGrid2d(int arg0, double arg1, double arg2, int arg3, double arg4, double arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glMapGrid2f(int arg0, float arg1, float arg2, int arg3, float arg4, float arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glMapParameterfvNV(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glMapParameterfvNV(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glMapParameterivNV(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glMapParameterivNV(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glMapVertexAttrib1dAPPLE(int arg0, int arg1, double arg2, double arg3, int arg4, int arg5, DoubleBuffer arg6)
	{
		// Stub method only.
		
	}

	@Override
	public void glMapVertexAttrib1dAPPLE(int arg0, int arg1, double arg2, double arg3, int arg4, int arg5, double[] arg6, int arg7)
	{
		// Stub method only.
		
	}

	@Override
	public void glMapVertexAttrib1fAPPLE(int arg0, int arg1, float arg2, float arg3, int arg4, int arg5, FloatBuffer arg6)
	{
		// Stub method only.
		
	}

	@Override
	public void glMapVertexAttrib1fAPPLE(int arg0, int arg1, float arg2, float arg3, int arg4, int arg5, float[] arg6, int arg7)
	{
		// Stub method only.
		
	}

	@Override
	public void glMapVertexAttrib2dAPPLE(int arg0, int arg1, double arg2, double arg3, int arg4, int arg5, double arg6,
			double arg7, int arg8, int arg9, DoubleBuffer arg10)
	{
		// Stub method only.
		
	}

	@Override
	public void glMapVertexAttrib2dAPPLE(int arg0, int arg1, double arg2, double arg3, int arg4, int arg5, double arg6,
			double arg7, int arg8, int arg9, double[] arg10, int arg11)
	{
		// Stub method only.
		
	}

	@Override
	public void glMapVertexAttrib2fAPPLE(int arg0, int arg1, float arg2, float arg3, int arg4, int arg5, float arg6, float arg7,
			int arg8, int arg9, FloatBuffer arg10)
	{
		// Stub method only.
		
	}

	@Override
	public void glMapVertexAttrib2fAPPLE(int arg0, int arg1, float arg2, float arg3, int arg4, int arg5, float arg6, float arg7,
			int arg8, int arg9, float[] arg10, int arg11)
	{
		// Stub method only.
		
	}

	@Override
	public void glMaterialf(int arg0, int arg1, float arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glMaterialfv(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glMaterialfv(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glMateriali(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glMaterialiv(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glMaterialiv(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glMatrixIndexPointerARB(int arg0, int arg1, int arg2, Buffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glMatrixIndexPointerARB(int arg0, int arg1, int arg2, long arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glMatrixIndexubvARB(int arg0, ByteBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glMatrixIndexubvARB(int arg0, byte[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glMatrixIndexuivARB(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glMatrixIndexuivARB(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glMatrixIndexusvARB(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glMatrixIndexusvARB(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glMatrixMode(int arg0)
	{
	    addMethodCall("glMatrixMode", new Object[] {arg0});
		
	}

	@Override
	public void glMinmax(int arg0, int arg1, boolean arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultMatrixd(DoubleBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultMatrixd(double[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultMatrixf(FloatBuffer arg0)
	{
		addMethodCall("glMultMatrixf", new Object[] {arg0});
	}

	@Override
	public void glMultMatrixf(float[] arg0, int arg1)
	{
		addMethodCall("glMultMatrixf", new Object[] {arg0, arg1});
	}

	@Override
	public void glMultTransposeMatrixd(DoubleBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultTransposeMatrixd(double[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultTransposeMatrixf(FloatBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultTransposeMatrixf(float[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiDrawArrays(int arg0, IntBuffer arg1, IntBuffer arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiDrawArrays(int arg0, int[] arg1, int arg2, int[] arg3, int arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiDrawArraysEXT(int arg0, IntBuffer arg1, IntBuffer arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiDrawArraysEXT(int arg0, int[] arg1, int arg2, int[] arg3, int arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiDrawElementArrayAPPLE(int arg0, IntBuffer arg1, IntBuffer arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiDrawElementArrayAPPLE(int arg0, int[] arg1, int arg2, int[] arg3, int arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiDrawElements(int arg0, IntBuffer arg1, int arg2, Buffer[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiDrawElements(int arg0, int[] arg1, int arg2, int arg3, Buffer[] arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiDrawElementsEXT(int arg0, IntBuffer arg1, int arg2, Buffer[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiDrawElementsEXT(int arg0, int[] arg1, int arg2, int arg3, Buffer[] arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiDrawRangeElementArrayAPPLE(int arg0, int arg1, int arg2, IntBuffer arg3, IntBuffer arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiDrawRangeElementArrayAPPLE(int arg0, int arg1, int arg2, int[] arg3, int arg4, int[] arg5, int arg6,
			int arg7)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiModeDrawArraysIBM(IntBuffer arg0, IntBuffer arg1, IntBuffer arg2, int arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiModeDrawArraysIBM(int[] arg0, int arg1, int[] arg2, int arg3, int[] arg4, int arg5, int arg6, int arg7)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiModeDrawElementsIBM(IntBuffer arg0, IntBuffer arg1, int arg2, Buffer[] arg3, int arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiModeDrawElementsIBM(int[] arg0, int arg1, int[] arg2, int arg3, int arg4, Buffer[] arg5, int arg6, int arg7)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord1d(int arg0, double arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord1dv(int arg0, DoubleBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord1dv(int arg0, double[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord1f(int arg0, float arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord1fv(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord1fv(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord1hNV(int arg0, short arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord1hvNV(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord1hvNV(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord1i(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord1iv(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord1iv(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord1s(int arg0, short arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord1sv(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord1sv(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord2d(int arg0, double arg1, double arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord2dv(int arg0, DoubleBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord2dv(int arg0, double[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord2f(int arg0, float arg1, float arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord2fv(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord2fv(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord2hNV(int arg0, short arg1, short arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord2hvNV(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord2hvNV(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord2i(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord2iv(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord2iv(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord2s(int arg0, short arg1, short arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord2sv(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord2sv(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord3d(int arg0, double arg1, double arg2, double arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord3dv(int arg0, DoubleBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord3dv(int arg0, double[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord3f(int arg0, float arg1, float arg2, float arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord3fv(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord3fv(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord3hNV(int arg0, short arg1, short arg2, short arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord3hvNV(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord3hvNV(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord3i(int arg0, int arg1, int arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord3iv(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord3iv(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord3s(int arg0, short arg1, short arg2, short arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord3sv(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord3sv(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord4d(int arg0, double arg1, double arg2, double arg3, double arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord4dv(int arg0, DoubleBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord4dv(int arg0, double[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord4f(int arg0, float arg1, float arg2, float arg3, float arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord4fv(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord4fv(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord4hNV(int arg0, short arg1, short arg2, short arg3, short arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord4hvNV(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord4hvNV(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord4i(int arg0, int arg1, int arg2, int arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord4iv(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord4iv(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord4s(int arg0, short arg1, short arg2, short arg3, short arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord4sv(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glMultiTexCoord4sv(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public int glNewBufferRegion(int arg0)
	{
		// Stub method only.
		return 0;
	}

	@Override
	public void glNewList(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public int glNewObjectBufferATI(int arg0, Buffer arg1, int arg2)
	{
		// Stub method only.
		return 0;
	}

	@Override
	public void glNormal3b(byte arg0, byte arg1, byte arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glNormal3bv(ByteBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glNormal3bv(byte[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glNormal3d(double arg0, double arg1, double arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glNormal3dv(DoubleBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glNormal3dv(double[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glNormal3f(float arg0, float arg1, float arg2)
	{
	    addMethodCall("glNormal3f", new Object[] {arg0, arg1, arg2});
		
	}

	@Override
	public void glNormal3fVertex3fSUN(float arg0, float arg1, float arg2, float arg3, float arg4, float arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glNormal3fVertex3fvSUN(FloatBuffer arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glNormal3fVertex3fvSUN(float[] arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glNormal3fv(FloatBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glNormal3fv(float[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glNormal3hNV(short arg0, short arg1, short arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glNormal3hvNV(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glNormal3hvNV(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glNormal3i(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glNormal3iv(IntBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glNormal3iv(int[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glNormal3s(short arg0, short arg1, short arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glNormal3sv(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glNormal3sv(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glNormalPointer(int arg0, int arg1, Buffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glNormalPointer(int arg0, int arg1, long arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glNormalStream3bATI(int arg0, byte arg1, byte arg2, byte arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glNormalStream3bvATI(int arg0, ByteBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glNormalStream3bvATI(int arg0, byte[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glNormalStream3dATI(int arg0, double arg1, double arg2, double arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glNormalStream3dvATI(int arg0, DoubleBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glNormalStream3dvATI(int arg0, double[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glNormalStream3fATI(int arg0, float arg1, float arg2, float arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glNormalStream3fvATI(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glNormalStream3fvATI(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glNormalStream3iATI(int arg0, int arg1, int arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glNormalStream3ivATI(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glNormalStream3ivATI(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glNormalStream3sATI(int arg0, short arg1, short arg2, short arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glNormalStream3svATI(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glNormalStream3svATI(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glOrtho(double arg0, double arg1, double arg2, double arg3, double arg4, double arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glPNTrianglesfATI(int arg0, float arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glPNTrianglesiATI(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glPassTexCoordATI(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glPassThrough(float arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glPixelDataRangeNV(int arg0, int arg1, Buffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glPixelMapfv(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glPixelMapfv(int arg0, int arg1, long arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glPixelMapfv(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glPixelMapuiv(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glPixelMapuiv(int arg0, int arg1, long arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glPixelMapuiv(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glPixelMapusv(int arg0, int arg1, ShortBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glPixelMapusv(int arg0, int arg1, long arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glPixelMapusv(int arg0, int arg1, short[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glPixelStoref(int arg0, float arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glPixelStorei(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glPixelTexGenParameterfSGIS(int arg0, float arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glPixelTexGenParameterfvSGIS(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glPixelTexGenParameterfvSGIS(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glPixelTexGenParameteriSGIS(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glPixelTexGenParameterivSGIS(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glPixelTexGenParameterivSGIS(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glPixelTexGenSGIX(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glPixelTransferf(int arg0, float arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glPixelTransferi(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glPixelTransformParameterfEXT(int arg0, int arg1, float arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glPixelTransformParameterfvEXT(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glPixelTransformParameterfvEXT(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glPixelTransformParameteriEXT(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glPixelTransformParameterivEXT(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glPixelTransformParameterivEXT(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glPixelZoom(float arg0, float arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glPointParameterf(int arg0, float arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glPointParameterfARB(int arg0, float arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glPointParameterfEXT(int arg0, float arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glPointParameterfSGIS(int arg0, float arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glPointParameterfv(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glPointParameterfv(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glPointParameterfvARB(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glPointParameterfvARB(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glPointParameterfvEXT(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glPointParameterfvEXT(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glPointParameterfvSGIS(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glPointParameterfvSGIS(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glPointParameteri(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glPointParameteriNV(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glPointParameteriv(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glPointParameteriv(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glPointParameterivNV(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glPointParameterivNV(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glPointSize(float arg0)
	{
		// Stub method only.
		
	}

	@Override
	public int glPollAsyncSGIX(IntBuffer arg0)
	{
		// Stub method only.
		return 0;
	}

	@Override
	public int glPollAsyncSGIX(int[] arg0, int arg1)
	{
		// Stub method only.
		return 0;
	}

	@Override
	public int glPollInstrumentsSGIX(IntBuffer arg0)
	{
		// Stub method only.
		return 0;
	}

	@Override
	public int glPollInstrumentsSGIX(int[] arg0, int arg1)
	{
		// Stub method only.
		return 0;
	}

	@Override
	public void glPolygonMode(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glPolygonOffset(float arg0, float arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glPolygonStipple(ByteBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glPolygonStipple(long arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glPolygonStipple(byte[] arg0, int arg1)
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
	public void glPrimitiveRestartIndexNV(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glPrimitiveRestartNV()
	{
		// Stub method only.
		
	}

	@Override
	public void glPrioritizeTextures(int arg0, IntBuffer arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glPrioritizeTextures(int arg0, int[] arg1, int arg2, float[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramBufferParametersIivNV(int arg0, int arg1, int arg2, int arg3, IntBuffer arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramBufferParametersIivNV(int arg0, int arg1, int arg2, int arg3, int[] arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramBufferParametersIuivNV(int arg0, int arg1, int arg2, int arg3, IntBuffer arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramBufferParametersIuivNV(int arg0, int arg1, int arg2, int arg3, int[] arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramBufferParametersfvNV(int arg0, int arg1, int arg2, int arg3, FloatBuffer arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramBufferParametersfvNV(int arg0, int arg1, int arg2, int arg3, float[] arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramEnvParameter4dARB(int arg0, int arg1, double arg2, double arg3, double arg4, double arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramEnvParameter4dvARB(int arg0, int arg1, DoubleBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramEnvParameter4dvARB(int arg0, int arg1, double[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramEnvParameter4fARB(int arg0, int arg1, float arg2, float arg3, float arg4, float arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramEnvParameter4fvARB(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramEnvParameter4fvARB(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramEnvParameterI4iNV(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramEnvParameterI4ivNV(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramEnvParameterI4ivNV(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramEnvParameterI4uiNV(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramEnvParameterI4uivNV(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramEnvParameterI4uivNV(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramEnvParameters4fvEXT(int arg0, int arg1, int arg2, FloatBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramEnvParameters4fvEXT(int arg0, int arg1, int arg2, float[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramEnvParametersI4ivNV(int arg0, int arg1, int arg2, IntBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramEnvParametersI4ivNV(int arg0, int arg1, int arg2, int[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramEnvParametersI4uivNV(int arg0, int arg1, int arg2, IntBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramEnvParametersI4uivNV(int arg0, int arg1, int arg2, int[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramLocalParameter4dARB(int arg0, int arg1, double arg2, double arg3, double arg4, double arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramLocalParameter4dvARB(int arg0, int arg1, DoubleBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramLocalParameter4dvARB(int arg0, int arg1, double[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramLocalParameter4fARB(int arg0, int arg1, float arg2, float arg3, float arg4, float arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramLocalParameter4fvARB(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramLocalParameter4fvARB(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramLocalParameterI4iNV(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramLocalParameterI4ivNV(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramLocalParameterI4ivNV(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramLocalParameterI4uiNV(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramLocalParameterI4uivNV(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramLocalParameterI4uivNV(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramLocalParameters4fvEXT(int arg0, int arg1, int arg2, FloatBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramLocalParameters4fvEXT(int arg0, int arg1, int arg2, float[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramLocalParametersI4ivNV(int arg0, int arg1, int arg2, IntBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramLocalParametersI4ivNV(int arg0, int arg1, int arg2, int[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramLocalParametersI4uivNV(int arg0, int arg1, int arg2, IntBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramLocalParametersI4uivNV(int arg0, int arg1, int arg2, int[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramNamedParameter4dNV(int arg0, int arg1, String arg2, double arg3, double arg4, double arg5, double arg6)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramNamedParameter4dvNV(int arg0, int arg1, String arg2, DoubleBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramNamedParameter4dvNV(int arg0, int arg1, String arg2, double[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramNamedParameter4fNV(int arg0, int arg1, String arg2, float arg3, float arg4, float arg5, float arg6)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramNamedParameter4fvNV(int arg0, int arg1, String arg2, FloatBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramNamedParameter4fvNV(int arg0, int arg1, String arg2, float[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramParameter4dNV(int arg0, int arg1, double arg2, double arg3, double arg4, double arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramParameter4dvNV(int arg0, int arg1, DoubleBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramParameter4dvNV(int arg0, int arg1, double[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramParameter4fNV(int arg0, int arg1, float arg2, float arg3, float arg4, float arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramParameter4fvNV(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramParameter4fvNV(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramParameteriEXT(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramParameters4dvNV(int arg0, int arg1, int arg2, DoubleBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramParameters4dvNV(int arg0, int arg1, int arg2, double[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramParameters4fvNV(int arg0, int arg1, int arg2, FloatBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramParameters4fvNV(int arg0, int arg1, int arg2, float[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramStringARB(int arg0, int arg1, int arg2, String arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glProgramVertexLimitNV(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glPushAttrib(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glPushClientAttrib(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glPushMatrix()
	{
		addMethodCall("glPushMatrix", null);
		
	}

	@Override
	public void glPushName(int arg0)
	{
	    addMethodCall("glPushName", new Object[] {arg0});
		
	}

	@Override
	public void glRasterPos2d(double arg0, double arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glRasterPos2dv(DoubleBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glRasterPos2dv(double[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glRasterPos2f(float arg0, float arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glRasterPos2fv(FloatBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glRasterPos2fv(float[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glRasterPos2i(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glRasterPos2iv(IntBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glRasterPos2iv(int[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glRasterPos2s(short arg0, short arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glRasterPos2sv(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glRasterPos2sv(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glRasterPos3d(double arg0, double arg1, double arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glRasterPos3dv(DoubleBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glRasterPos3dv(double[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glRasterPos3f(float arg0, float arg1, float arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glRasterPos3fv(FloatBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glRasterPos3fv(float[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glRasterPos3i(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glRasterPos3iv(IntBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glRasterPos3iv(int[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glRasterPos3s(short arg0, short arg1, short arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glRasterPos3sv(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glRasterPos3sv(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glRasterPos4d(double arg0, double arg1, double arg2, double arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glRasterPos4dv(DoubleBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glRasterPos4dv(double[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glRasterPos4f(float arg0, float arg1, float arg2, float arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glRasterPos4fv(FloatBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glRasterPos4fv(float[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glRasterPos4i(int arg0, int arg1, int arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glRasterPos4iv(IntBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glRasterPos4iv(int[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glRasterPos4s(short arg0, short arg1, short arg2, short arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glRasterPos4sv(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glRasterPos4sv(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glReadBuffer(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glReadBufferRegion(int arg0, int arg1, int arg2, int arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glReadInstrumentsSGIX(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glReadPixels(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, Buffer arg6)
	{
		// Stub method only.
		
	}

	@Override
	public void glReadPixels(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, long arg6)
	{
		// Stub method only.
		
	}

	@Override
	public void glRectd(double arg0, double arg1, double arg2, double arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glRectdv(DoubleBuffer arg0, DoubleBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glRectdv(double[] arg0, int arg1, double[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glRectf(float arg0, float arg1, float arg2, float arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glRectfv(FloatBuffer arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glRectfv(float[] arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glRecti(int arg0, int arg1, int arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glRectiv(IntBuffer arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glRectiv(int[] arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glRects(short arg0, short arg1, short arg2, short arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glRectsv(ShortBuffer arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glRectsv(short[] arg0, int arg1, short[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glReferencePlaneSGIX(DoubleBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glReferencePlaneSGIX(double[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public int glRenderMode(int arg0)
	{
		// Stub method only.
		return 0;
	}

	@Override
	public void glRenderbufferStorageEXT(int arg0, int arg1, int arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glRenderbufferStorageMultisampleCoverageNV(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glRenderbufferStorageMultisampleEXT(int arg0, int arg1, int arg2, int arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glReplacementCodeuiColor3fVertex3fSUN(int arg0, float arg1, float arg2, float arg3, float arg4, float arg5,
			float arg6)
	{
		// Stub method only.
		
	}

	@Override
	public void glReplacementCodeuiColor3fVertex3fvSUN(IntBuffer arg0, FloatBuffer arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glReplacementCodeuiColor3fVertex3fvSUN(int[] arg0, int arg1, float[] arg2, int arg3, float[] arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glReplacementCodeuiColor4fNormal3fVertex3fSUN(int arg0, float arg1, float arg2, float arg3, float arg4,
			float arg5, float arg6, float arg7, float arg8, float arg9, float arg10)
	{
		// Stub method only.
		
	}

	@Override
	public void glReplacementCodeuiColor4fNormal3fVertex3fvSUN(IntBuffer arg0, FloatBuffer arg1, FloatBuffer arg2,
			FloatBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glReplacementCodeuiColor4fNormal3fVertex3fvSUN(int[] arg0, int arg1, float[] arg2, int arg3, float[] arg4,
			int arg5, float[] arg6, int arg7)
	{
		// Stub method only.
		
	}

	@Override
	public void glReplacementCodeuiColor4ubVertex3fSUN(int arg0, byte arg1, byte arg2, byte arg3, byte arg4, float arg5,
			float arg6, float arg7)
	{
		// Stub method only.
		
	}

	@Override
	public void glReplacementCodeuiColor4ubVertex3fvSUN(IntBuffer arg0, ByteBuffer arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glReplacementCodeuiColor4ubVertex3fvSUN(int[] arg0, int arg1, byte[] arg2, int arg3, float[] arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glReplacementCodeuiNormal3fVertex3fSUN(int arg0, float arg1, float arg2, float arg3, float arg4, float arg5,
			float arg6)
	{
		// Stub method only.
		
	}

	@Override
	public void glReplacementCodeuiNormal3fVertex3fvSUN(IntBuffer arg0, FloatBuffer arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glReplacementCodeuiNormal3fVertex3fvSUN(int[] arg0, int arg1, float[] arg2, int arg3, float[] arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN(int arg0, float arg1, float arg2, float arg3, float arg4,
			float arg5, float arg6, float arg7, float arg8, float arg9, float arg10, float arg11, float arg12)
	{
		// Stub method only.
		
	}

	@Override
	public void glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN(IntBuffer arg0, FloatBuffer arg1, FloatBuffer arg2,
			FloatBuffer arg3, FloatBuffer arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN(int[] arg0, int arg1, float[] arg2, int arg3,
			float[] arg4, int arg5, float[] arg6, int arg7, float[] arg8, int arg9)
	{
		// Stub method only.
		
	}

	@Override
	public void glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN(int arg0, float arg1, float arg2, float arg3, float arg4,
			float arg5, float arg6, float arg7, float arg8)
	{
		// Stub method only.
		
	}

	@Override
	public void glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN(IntBuffer arg0, FloatBuffer arg1, FloatBuffer arg2,
			FloatBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN(int[] arg0, int arg1, float[] arg2, int arg3, float[] arg4,
			int arg5, float[] arg6, int arg7)
	{
		// Stub method only.
		
	}

	@Override
	public void glReplacementCodeuiTexCoord2fVertex3fSUN(int arg0, float arg1, float arg2, float arg3, float arg4, float arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glReplacementCodeuiTexCoord2fVertex3fvSUN(IntBuffer arg0, FloatBuffer arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glReplacementCodeuiTexCoord2fVertex3fvSUN(int[] arg0, int arg1, float[] arg2, int arg3, float[] arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glReplacementCodeuiVertex3fSUN(int arg0, float arg1, float arg2, float arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glReplacementCodeuiVertex3fvSUN(IntBuffer arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glReplacementCodeuiVertex3fvSUN(int[] arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glRequestResidentProgramsNV(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glRequestResidentProgramsNV(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glResetHistogram(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glResetMinmax(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glResizeBuffersMESA()
	{
		// Stub method only.
		
	}

	@Override
	public void glRotated(double arg0, double arg1, double arg2, double arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glRotatef(float arg0, float arg1, float arg2, float arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glSampleCoverage(float arg0, boolean arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glSampleMapATI(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glSampleMaskEXT(float arg0, boolean arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glSampleMaskSGIS(float arg0, boolean arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glSamplePatternEXT(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glSamplePatternSGIS(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glScaled(double arg0, double arg1, double arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glScalef(float arg0, float arg1, float arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glScissor(int arg0, int arg1, int arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3b(byte arg0, byte arg1, byte arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3bEXT(byte arg0, byte arg1, byte arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3bv(ByteBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3bv(byte[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3bvEXT(ByteBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3bvEXT(byte[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3d(double arg0, double arg1, double arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3dEXT(double arg0, double arg1, double arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3dv(DoubleBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3dv(double[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3dvEXT(DoubleBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3dvEXT(double[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3f(float arg0, float arg1, float arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3fEXT(float arg0, float arg1, float arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3fv(FloatBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3fv(float[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3fvEXT(FloatBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3fvEXT(float[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3hNV(short arg0, short arg1, short arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3hvNV(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3hvNV(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3i(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3iEXT(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3iv(IntBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3iv(int[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3ivEXT(IntBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3ivEXT(int[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3s(short arg0, short arg1, short arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3sEXT(short arg0, short arg1, short arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3sv(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3sv(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3svEXT(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3svEXT(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3ub(byte arg0, byte arg1, byte arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3ubEXT(byte arg0, byte arg1, byte arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3ubv(ByteBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3ubv(byte[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3ubvEXT(ByteBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3ubvEXT(byte[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3ui(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3uiEXT(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3uiv(IntBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3uiv(int[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3uivEXT(IntBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3uivEXT(int[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3us(short arg0, short arg1, short arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3usEXT(short arg0, short arg1, short arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3usv(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3usv(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3usvEXT(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColor3usvEXT(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColorPointer(int arg0, int arg1, int arg2, Buffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColorPointer(int arg0, int arg1, int arg2, long arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColorPointerEXT(int arg0, int arg1, int arg2, Buffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glSecondaryColorPointerEXT(int arg0, int arg1, int arg2, long arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glSelectBuffer(int arg0, IntBuffer arg1)
	{
		addMethodCall("glSelectBuffer", new Object[] {arg0, arg1});
	}

	@Override
	public void glSeparableFilter2D(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, Buffer arg6, Buffer arg7)
	{
		// Stub method only.
		
	}

	@Override
	public void glSeparableFilter2D(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, long arg6, long arg7)
	{
		// Stub method only.
		
	}

	@Override
	public void glSetFenceAPPLE(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glSetFenceNV(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glSetFragmentShaderConstantATI(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glSetFragmentShaderConstantATI(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glSetInvariantEXT(int arg0, int arg1, Buffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glSetLocalConstantEXT(int arg0, int arg1, Buffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glShadeModel(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glShaderOp1EXT(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glShaderOp2EXT(int arg0, int arg1, int arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glShaderOp3EXT(int arg0, int arg1, int arg2, int arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glShaderSource(int arg0, int arg1, String[] arg2, IntBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glShaderSource(int arg0, int arg1, String[] arg2, int[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glShaderSourceARB(int arg0, int arg1, String[] arg2, IntBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glShaderSourceARB(int arg0, int arg1, String[] arg2, int[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glSharpenTexFuncSGIS(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glSharpenTexFuncSGIS(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glSpriteParameterfSGIX(int arg0, float arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glSpriteParameterfvSGIX(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glSpriteParameterfvSGIX(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glSpriteParameteriSGIX(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glSpriteParameterivSGIX(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glSpriteParameterivSGIX(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glStartInstrumentsSGIX()
	{
		// Stub method only.
		
	}

	@Override
	public void glStencilClearTagEXT(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glStencilFunc(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glStencilFuncSeparate(int arg0, int arg1, int arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glStencilFuncSeparateATI(int arg0, int arg1, int arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glStencilMask(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glStencilMaskSeparate(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glStencilOp(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glStencilOpSeparate(int arg0, int arg1, int arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glStencilOpSeparateATI(int arg0, int arg1, int arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glStopInstrumentsSGIX(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glStringMarkerGREMEDY(int arg0, Buffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glSwapAPPLE()
	{
		// Stub method only.
		
	}

	@Override
	public void glSwizzleEXT(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glTagSampleBufferSGIX()
	{
		// Stub method only.
		
	}

	@Override
	public void glTbufferMask3DFX(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public boolean glTestFenceAPPLE(int arg0)
	{
		// Stub method only.
		return false;
	}

	@Override
	public boolean glTestFenceNV(int arg0)
	{
		// Stub method only.
		return false;
	}

	@Override
	public boolean glTestObjectAPPLE(int arg0, int arg1)
	{
		// Stub method only.
		return false;
	}

	@Override
	public void glTexBufferEXT(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexBumpParameterfvATI(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexBumpParameterfvATI(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexBumpParameterivATI(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexBumpParameterivATI(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord1d(double arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord1dv(DoubleBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord1dv(double[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord1f(float arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord1fv(FloatBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord1fv(float[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord1hNV(short arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord1hvNV(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord1hvNV(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord1i(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord1iv(IntBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord1iv(int[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord1s(short arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord1sv(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord1sv(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord2d(double arg0, double arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord2dv(DoubleBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord2dv(double[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord2f(float arg0, float arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord2fColor3fVertex3fSUN(float arg0, float arg1, float arg2, float arg3, float arg4, float arg5,
			float arg6, float arg7)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord2fColor3fVertex3fvSUN(FloatBuffer arg0, FloatBuffer arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord2fColor3fVertex3fvSUN(float[] arg0, int arg1, float[] arg2, int arg3, float[] arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord2fColor4fNormal3fVertex3fSUN(float arg0, float arg1, float arg2, float arg3, float arg4, float arg5,
			float arg6, float arg7, float arg8, float arg9, float arg10, float arg11)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord2fColor4fNormal3fVertex3fvSUN(FloatBuffer arg0, FloatBuffer arg1, FloatBuffer arg2, FloatBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord2fColor4fNormal3fVertex3fvSUN(float[] arg0, int arg1, float[] arg2, int arg3, float[] arg4, int arg5,
			float[] arg6, int arg7)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord2fColor4ubVertex3fSUN(float arg0, float arg1, byte arg2, byte arg3, byte arg4, byte arg5, float arg6,
			float arg7, float arg8)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord2fColor4ubVertex3fvSUN(FloatBuffer arg0, ByteBuffer arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord2fColor4ubVertex3fvSUN(float[] arg0, int arg1, byte[] arg2, int arg3, float[] arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord2fNormal3fVertex3fSUN(float arg0, float arg1, float arg2, float arg3, float arg4, float arg5,
			float arg6, float arg7)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord2fNormal3fVertex3fvSUN(FloatBuffer arg0, FloatBuffer arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord2fNormal3fVertex3fvSUN(float[] arg0, int arg1, float[] arg2, int arg3, float[] arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord2fVertex3fSUN(float arg0, float arg1, float arg2, float arg3, float arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord2fVertex3fvSUN(FloatBuffer arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord2fVertex3fvSUN(float[] arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord2fv(FloatBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord2fv(float[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord2hNV(short arg0, short arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord2hvNV(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord2hvNV(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord2i(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord2iv(IntBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord2iv(int[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord2s(short arg0, short arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord2sv(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord2sv(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord3d(double arg0, double arg1, double arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord3dv(DoubleBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord3dv(double[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord3f(float arg0, float arg1, float arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord3fv(FloatBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord3fv(float[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord3hNV(short arg0, short arg1, short arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord3hvNV(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord3hvNV(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord3i(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord3iv(IntBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord3iv(int[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord3s(short arg0, short arg1, short arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord3sv(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord3sv(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord4d(double arg0, double arg1, double arg2, double arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord4dv(DoubleBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord4dv(double[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord4f(float arg0, float arg1, float arg2, float arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord4fColor4fNormal3fVertex4fSUN(float arg0, float arg1, float arg2, float arg3, float arg4, float arg5,
			float arg6, float arg7, float arg8, float arg9, float arg10, float arg11, float arg12, float arg13, float arg14)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord4fColor4fNormal3fVertex4fvSUN(FloatBuffer arg0, FloatBuffer arg1, FloatBuffer arg2, FloatBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord4fColor4fNormal3fVertex4fvSUN(float[] arg0, int arg1, float[] arg2, int arg3, float[] arg4, int arg5,
			float[] arg6, int arg7)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord4fVertex4fSUN(float arg0, float arg1, float arg2, float arg3, float arg4, float arg5, float arg6,
			float arg7)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord4fVertex4fvSUN(FloatBuffer arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord4fVertex4fvSUN(float[] arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord4fv(FloatBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord4fv(float[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord4hNV(short arg0, short arg1, short arg2, short arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord4hvNV(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord4hvNV(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord4i(int arg0, int arg1, int arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord4iv(IntBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord4iv(int[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord4s(short arg0, short arg1, short arg2, short arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord4sv(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoord4sv(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoordPointer(int arg0, int arg1, int arg2, Buffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexCoordPointer(int arg0, int arg1, int arg2, long arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexEnvf(int arg0, int arg1, float arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexEnvfv(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexEnvfv(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexEnvi(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexEnviv(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexEnviv(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexFilterFuncSGIS(int arg0, int arg1, int arg2, FloatBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexFilterFuncSGIS(int arg0, int arg1, int arg2, float[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexGend(int arg0, int arg1, double arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexGendv(int arg0, int arg1, DoubleBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexGendv(int arg0, int arg1, double[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexGenf(int arg0, int arg1, float arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexGenfv(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexGenfv(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexGeni(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexGeniv(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexGeniv(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexImage1D(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, Buffer arg7)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexImage1D(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, long arg7)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexImage2D(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, Buffer arg8)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexImage2D(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, long arg8)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexImage3D(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, Buffer arg9)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexImage3D(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, long arg9)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexImage4DSGIS(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8,
			int arg9, Buffer arg10)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexParameterIivEXT(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexParameterIivEXT(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexParameterIuivEXT(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexParameterIuivEXT(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexParameterf(int arg0, int arg1, float arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexParameterfv(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexParameterfv(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexParameteri(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexParameteriv(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexParameteriv(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexSubImage1D(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, Buffer arg6)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexSubImage1D(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, long arg6)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexSubImage2D(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, Buffer arg8)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexSubImage2D(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, long arg8)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexSubImage3D(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8,
			int arg9, Buffer arg10)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexSubImage3D(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8,
			int arg9, long arg10)
	{
		// Stub method only.
		
	}

	@Override
	public void glTexSubImage4DSGIS(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8,
			int arg9, int arg10, int arg11, Buffer arg12)
	{
		// Stub method only.
		
	}

	@Override
	public void glTextureColorMaskSGIS(boolean arg0, boolean arg1, boolean arg2, boolean arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glTextureLightEXT(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glTextureMaterialEXT(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glTextureNormalEXT(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glTextureRangeAPPLE(int arg0, int arg1, Buffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glTrackMatrixNV(int arg0, int arg1, int arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glTransformFeedbackAttribsNV(int arg0, IntBuffer arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glTransformFeedbackAttribsNV(int arg0, int[] arg1, int arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glTransformFeedbackVaryingsNV(int arg0, int arg1, IntBuffer arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glTransformFeedbackVaryingsNV(int arg0, int arg1, int[] arg2, int arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glTranslated(double arg0, double arg1, double arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glTranslatef(float arg0, float arg1, float arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform1f(int arg0, float arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform1fARB(int arg0, float arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform1fv(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform1fv(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform1fvARB(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform1fvARB(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform1i(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform1iARB(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform1iv(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform1iv(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform1ivARB(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform1ivARB(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform1uiEXT(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform1uivEXT(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform1uivEXT(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform2f(int arg0, float arg1, float arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform2fARB(int arg0, float arg1, float arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform2fv(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform2fv(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform2fvARB(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform2fvARB(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform2i(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform2iARB(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform2iv(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform2iv(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform2ivARB(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform2ivARB(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform2uiEXT(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform2uivEXT(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform2uivEXT(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform3f(int arg0, float arg1, float arg2, float arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform3fARB(int arg0, float arg1, float arg2, float arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform3fv(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform3fv(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform3fvARB(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform3fvARB(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform3i(int arg0, int arg1, int arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform3iARB(int arg0, int arg1, int arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform3iv(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform3iv(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform3ivARB(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform3ivARB(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform3uiEXT(int arg0, int arg1, int arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform3uivEXT(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform3uivEXT(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform4f(int arg0, float arg1, float arg2, float arg3, float arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform4fARB(int arg0, float arg1, float arg2, float arg3, float arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform4fv(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform4fv(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform4fvARB(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform4fvARB(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform4i(int arg0, int arg1, int arg2, int arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform4iARB(int arg0, int arg1, int arg2, int arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform4iv(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform4iv(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform4ivARB(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform4ivARB(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform4uiEXT(int arg0, int arg1, int arg2, int arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform4uivEXT(int arg0, int arg1, IntBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniform4uivEXT(int arg0, int arg1, int[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniformBufferEXT(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniformMatrix2fv(int arg0, int arg1, boolean arg2, FloatBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniformMatrix2fv(int arg0, int arg1, boolean arg2, float[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniformMatrix2fvARB(int arg0, int arg1, boolean arg2, FloatBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniformMatrix2fvARB(int arg0, int arg1, boolean arg2, float[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniformMatrix2x3fv(int arg0, int arg1, boolean arg2, FloatBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniformMatrix2x3fv(int arg0, int arg1, boolean arg2, float[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniformMatrix2x4fv(int arg0, int arg1, boolean arg2, FloatBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniformMatrix2x4fv(int arg0, int arg1, boolean arg2, float[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniformMatrix3fv(int arg0, int arg1, boolean arg2, FloatBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniformMatrix3fv(int arg0, int arg1, boolean arg2, float[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniformMatrix3fvARB(int arg0, int arg1, boolean arg2, FloatBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniformMatrix3fvARB(int arg0, int arg1, boolean arg2, float[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniformMatrix3x2fv(int arg0, int arg1, boolean arg2, FloatBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniformMatrix3x2fv(int arg0, int arg1, boolean arg2, float[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniformMatrix3x4fv(int arg0, int arg1, boolean arg2, FloatBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniformMatrix3x4fv(int arg0, int arg1, boolean arg2, float[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniformMatrix4fv(int arg0, int arg1, boolean arg2, FloatBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniformMatrix4fv(int arg0, int arg1, boolean arg2, float[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniformMatrix4fvARB(int arg0, int arg1, boolean arg2, FloatBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniformMatrix4fvARB(int arg0, int arg1, boolean arg2, float[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniformMatrix4x2fv(int arg0, int arg1, boolean arg2, FloatBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniformMatrix4x2fv(int arg0, int arg1, boolean arg2, float[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniformMatrix4x3fv(int arg0, int arg1, boolean arg2, FloatBuffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glUniformMatrix4x3fv(int arg0, int arg1, boolean arg2, float[] arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glUnlockArraysEXT()
	{
		// Stub method only.
		
	}

	@Override
	public boolean glUnmapBuffer(int arg0)
	{
		// Stub method only.
		return false;
	}

	@Override
	public boolean glUnmapBufferARB(int arg0)
	{
		// Stub method only.
		return false;
	}

	@Override
	public void glUpdateObjectBufferATI(int arg0, int arg1, int arg2, Buffer arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glUseProgram(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glUseProgramObjectARB(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glValidateProgram(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glValidateProgramARB(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glVariantArrayObjectATI(int arg0, int arg1, int arg2, int arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glVariantPointerEXT(int arg0, int arg1, int arg2, Buffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVariantPointerEXT(int arg0, int arg1, int arg2, long arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVariantbvEXT(int arg0, ByteBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVariantbvEXT(int arg0, byte[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVariantdvEXT(int arg0, DoubleBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVariantdvEXT(int arg0, double[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVariantfvEXT(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVariantfvEXT(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVariantivEXT(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVariantivEXT(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVariantsvEXT(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVariantsvEXT(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVariantubvEXT(int arg0, ByteBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVariantubvEXT(int arg0, byte[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVariantuivEXT(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVariantuivEXT(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVariantusvEXT(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVariantusvEXT(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex2d(double arg0, double arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex2dv(DoubleBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex2dv(double[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex2f(float arg0, float arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex2fv(FloatBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex2fv(float[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex2hNV(short arg0, short arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex2hvNV(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex2hvNV(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex2i(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex2iv(IntBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex2iv(int[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex2s(short arg0, short arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex2sv(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex2sv(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex3d(double arg0, double arg1, double arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex3dv(DoubleBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex3dv(double[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex3f(float arg0, float arg1, float arg2)
	{
		addMethodCall("glVertex3f", new Object[] {arg0, arg1, arg2});
		
	}

	@Override
	public void glVertex3fv(FloatBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex3fv(float[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex3hNV(short arg0, short arg1, short arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex3hvNV(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex3hvNV(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex3i(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex3iv(IntBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex3iv(int[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex3s(short arg0, short arg1, short arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex3sv(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex3sv(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex4d(double arg0, double arg1, double arg2, double arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex4dv(DoubleBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex4dv(double[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex4f(float arg0, float arg1, float arg2, float arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex4fv(FloatBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex4fv(float[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex4hNV(short arg0, short arg1, short arg2, short arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex4hvNV(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex4hvNV(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex4i(int arg0, int arg1, int arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex4iv(IntBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex4iv(int[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex4s(short arg0, short arg1, short arg2, short arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex4sv(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertex4sv(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexArrayParameteriAPPLE(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexArrayRangeAPPLE(int arg0, Buffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexArrayRangeNV(int arg0, Buffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib1d(int arg0, double arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib1dARB(int arg0, double arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib1dNV(int arg0, double arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib1dv(int arg0, DoubleBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib1dv(int arg0, double[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib1dvARB(int arg0, DoubleBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib1dvARB(int arg0, double[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib1dvNV(int arg0, DoubleBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib1dvNV(int arg0, double[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib1f(int arg0, float arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib1fARB(int arg0, float arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib1fNV(int arg0, float arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib1fv(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib1fv(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib1fvARB(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib1fvARB(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib1fvNV(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib1fvNV(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib1hNV(int arg0, short arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib1hvNV(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib1hvNV(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib1s(int arg0, short arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib1sARB(int arg0, short arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib1sNV(int arg0, short arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib1sv(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib1sv(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib1svARB(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib1svARB(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib1svNV(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib1svNV(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib2d(int arg0, double arg1, double arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib2dARB(int arg0, double arg1, double arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib2dNV(int arg0, double arg1, double arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib2dv(int arg0, DoubleBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib2dv(int arg0, double[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib2dvARB(int arg0, DoubleBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib2dvARB(int arg0, double[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib2dvNV(int arg0, DoubleBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib2dvNV(int arg0, double[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib2f(int arg0, float arg1, float arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib2fARB(int arg0, float arg1, float arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib2fNV(int arg0, float arg1, float arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib2fv(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib2fv(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib2fvARB(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib2fvARB(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib2fvNV(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib2fvNV(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib2hNV(int arg0, short arg1, short arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib2hvNV(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib2hvNV(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib2s(int arg0, short arg1, short arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib2sARB(int arg0, short arg1, short arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib2sNV(int arg0, short arg1, short arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib2sv(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib2sv(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib2svARB(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib2svARB(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib2svNV(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib2svNV(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib3d(int arg0, double arg1, double arg2, double arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib3dARB(int arg0, double arg1, double arg2, double arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib3dNV(int arg0, double arg1, double arg2, double arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib3dv(int arg0, DoubleBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib3dv(int arg0, double[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib3dvARB(int arg0, DoubleBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib3dvARB(int arg0, double[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib3dvNV(int arg0, DoubleBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib3dvNV(int arg0, double[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib3f(int arg0, float arg1, float arg2, float arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib3fARB(int arg0, float arg1, float arg2, float arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib3fNV(int arg0, float arg1, float arg2, float arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib3fv(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib3fv(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib3fvARB(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib3fvARB(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib3fvNV(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib3fvNV(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib3hNV(int arg0, short arg1, short arg2, short arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib3hvNV(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib3hvNV(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib3s(int arg0, short arg1, short arg2, short arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib3sARB(int arg0, short arg1, short arg2, short arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib3sNV(int arg0, short arg1, short arg2, short arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib3sv(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib3sv(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib3svARB(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib3svARB(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib3svNV(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib3svNV(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4Nbv(int arg0, ByteBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4Nbv(int arg0, byte[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4NbvARB(int arg0, ByteBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4NbvARB(int arg0, byte[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4Niv(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4Niv(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4NivARB(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4NivARB(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4Nsv(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4Nsv(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4NsvARB(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4NsvARB(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4Nub(int arg0, byte arg1, byte arg2, byte arg3, byte arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4NubARB(int arg0, byte arg1, byte arg2, byte arg3, byte arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4Nubv(int arg0, ByteBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4Nubv(int arg0, byte[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4NubvARB(int arg0, ByteBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4NubvARB(int arg0, byte[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4Nuiv(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4Nuiv(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4NuivARB(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4NuivARB(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4Nusv(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4Nusv(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4NusvARB(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4NusvARB(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4bv(int arg0, ByteBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4bv(int arg0, byte[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4bvARB(int arg0, ByteBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4bvARB(int arg0, byte[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4d(int arg0, double arg1, double arg2, double arg3, double arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4dARB(int arg0, double arg1, double arg2, double arg3, double arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4dNV(int arg0, double arg1, double arg2, double arg3, double arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4dv(int arg0, DoubleBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4dv(int arg0, double[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4dvARB(int arg0, DoubleBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4dvARB(int arg0, double[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4dvNV(int arg0, DoubleBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4dvNV(int arg0, double[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4f(int arg0, float arg1, float arg2, float arg3, float arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4fARB(int arg0, float arg1, float arg2, float arg3, float arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4fNV(int arg0, float arg1, float arg2, float arg3, float arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4fv(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4fv(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4fvARB(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4fvARB(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4fvNV(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4fvNV(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4hNV(int arg0, short arg1, short arg2, short arg3, short arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4hvNV(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4hvNV(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4iv(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4iv(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4ivARB(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4ivARB(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4s(int arg0, short arg1, short arg2, short arg3, short arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4sARB(int arg0, short arg1, short arg2, short arg3, short arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4sNV(int arg0, short arg1, short arg2, short arg3, short arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4sv(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4sv(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4svARB(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4svARB(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4svNV(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4svNV(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4ubNV(int arg0, byte arg1, byte arg2, byte arg3, byte arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4ubv(int arg0, ByteBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4ubv(int arg0, byte[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4ubvARB(int arg0, ByteBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4ubvARB(int arg0, byte[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4ubvNV(int arg0, ByteBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4ubvNV(int arg0, byte[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4uiv(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4uiv(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4uivARB(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4uivARB(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4usv(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4usv(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4usvARB(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttrib4usvARB(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribArrayObjectATI(int arg0, int arg1, int arg2, boolean arg3, int arg4, int arg5, int arg6)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribI1iEXT(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribI1ivEXT(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribI1ivEXT(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribI1uiEXT(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribI1uivEXT(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribI1uivEXT(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribI2iEXT(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribI2ivEXT(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribI2ivEXT(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribI2uiEXT(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribI2uivEXT(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribI2uivEXT(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribI3iEXT(int arg0, int arg1, int arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribI3ivEXT(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribI3ivEXT(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribI3uiEXT(int arg0, int arg1, int arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribI3uivEXT(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribI3uivEXT(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribI4bvEXT(int arg0, ByteBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribI4bvEXT(int arg0, byte[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribI4iEXT(int arg0, int arg1, int arg2, int arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribI4ivEXT(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribI4ivEXT(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribI4svEXT(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribI4svEXT(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribI4ubvEXT(int arg0, ByteBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribI4ubvEXT(int arg0, byte[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribI4uiEXT(int arg0, int arg1, int arg2, int arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribI4uivEXT(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribI4uivEXT(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribI4usvEXT(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribI4usvEXT(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribIPointerEXT(int arg0, int arg1, int arg2, int arg3, Buffer arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribPointer(int arg0, int arg1, int arg2, boolean arg3, int arg4, Buffer arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribPointer(int arg0, int arg1, int arg2, boolean arg3, int arg4, long arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribPointerARB(int arg0, int arg1, int arg2, boolean arg3, int arg4, Buffer arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribPointerARB(int arg0, int arg1, int arg2, boolean arg3, int arg4, long arg5)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribPointerNV(int arg0, int arg1, int arg2, int arg3, Buffer arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribPointerNV(int arg0, int arg1, int arg2, int arg3, long arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribs1dvNV(int arg0, int arg1, DoubleBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribs1dvNV(int arg0, int arg1, double[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribs1fvNV(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribs1fvNV(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribs1hvNV(int arg0, int arg1, ShortBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribs1hvNV(int arg0, int arg1, short[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribs1svNV(int arg0, int arg1, ShortBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribs1svNV(int arg0, int arg1, short[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribs2dvNV(int arg0, int arg1, DoubleBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribs2dvNV(int arg0, int arg1, double[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribs2fvNV(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribs2fvNV(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribs2hvNV(int arg0, int arg1, ShortBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribs2hvNV(int arg0, int arg1, short[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribs2svNV(int arg0, int arg1, ShortBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribs2svNV(int arg0, int arg1, short[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribs3dvNV(int arg0, int arg1, DoubleBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribs3dvNV(int arg0, int arg1, double[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribs3fvNV(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribs3fvNV(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribs3hvNV(int arg0, int arg1, ShortBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribs3hvNV(int arg0, int arg1, short[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribs3svNV(int arg0, int arg1, ShortBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribs3svNV(int arg0, int arg1, short[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribs4dvNV(int arg0, int arg1, DoubleBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribs4dvNV(int arg0, int arg1, double[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribs4fvNV(int arg0, int arg1, FloatBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribs4fvNV(int arg0, int arg1, float[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribs4hvNV(int arg0, int arg1, ShortBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribs4hvNV(int arg0, int arg1, short[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribs4svNV(int arg0, int arg1, ShortBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribs4svNV(int arg0, int arg1, short[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribs4ubvNV(int arg0, int arg1, ByteBuffer arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexAttribs4ubvNV(int arg0, int arg1, byte[] arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexBlendARB(int arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexBlendEnvfATI(int arg0, float arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexBlendEnviATI(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexPointer(int arg0, int arg1, int arg2, Buffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexPointer(int arg0, int arg1, int arg2, long arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream1dATI(int arg0, double arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream1dvATI(int arg0, DoubleBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream1dvATI(int arg0, double[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream1fATI(int arg0, float arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream1fvATI(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream1fvATI(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream1iATI(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream1ivATI(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream1ivATI(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream1sATI(int arg0, short arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream1svATI(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream1svATI(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream2dATI(int arg0, double arg1, double arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream2dvATI(int arg0, DoubleBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream2dvATI(int arg0, double[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream2fATI(int arg0, float arg1, float arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream2fvATI(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream2fvATI(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream2iATI(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream2ivATI(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream2ivATI(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream2sATI(int arg0, short arg1, short arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream2svATI(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream2svATI(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream3dATI(int arg0, double arg1, double arg2, double arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream3dvATI(int arg0, DoubleBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream3dvATI(int arg0, double[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream3fATI(int arg0, float arg1, float arg2, float arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream3fvATI(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream3fvATI(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream3iATI(int arg0, int arg1, int arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream3ivATI(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream3ivATI(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream3sATI(int arg0, short arg1, short arg2, short arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream3svATI(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream3svATI(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream4dATI(int arg0, double arg1, double arg2, double arg3, double arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream4dvATI(int arg0, DoubleBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream4dvATI(int arg0, double[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream4fATI(int arg0, float arg1, float arg2, float arg3, float arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream4fvATI(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream4fvATI(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream4iATI(int arg0, int arg1, int arg2, int arg3, int arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream4ivATI(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream4ivATI(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream4sATI(int arg0, short arg1, short arg2, short arg3, short arg4)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream4svATI(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexStream4svATI(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexWeightPointerEXT(int arg0, int arg1, int arg2, Buffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexWeightPointerEXT(int arg0, int arg1, int arg2, long arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexWeightfEXT(float arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexWeightfvEXT(FloatBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexWeightfvEXT(float[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexWeighthNV(short arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexWeighthvNV(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glVertexWeighthvNV(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glViewport(int arg0, int arg1, int arg2, int arg3)
	{
		addMethodCall("glViewport", new Object[] {arg0, arg1, arg2, arg3});
		
	}

	@Override
	public void glWeightPointerARB(int arg0, int arg1, int arg2, Buffer arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glWeightPointerARB(int arg0, int arg1, int arg2, long arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glWeightbvARB(int arg0, ByteBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWeightbvARB(int arg0, byte[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glWeightdvARB(int arg0, DoubleBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWeightdvARB(int arg0, double[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glWeightfvARB(int arg0, FloatBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWeightfvARB(int arg0, float[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glWeightivARB(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWeightivARB(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glWeightsvARB(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWeightsvARB(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glWeightubvARB(int arg0, ByteBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWeightubvARB(int arg0, byte[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glWeightuivARB(int arg0, IntBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWeightuivARB(int arg0, int[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glWeightusvARB(int arg0, ShortBuffer arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWeightusvARB(int arg0, short[] arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos2d(double arg0, double arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos2dARB(double arg0, double arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos2dMESA(double arg0, double arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos2dv(DoubleBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos2dv(double[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos2dvARB(DoubleBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos2dvARB(double[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos2dvMESA(DoubleBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos2dvMESA(double[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos2f(float arg0, float arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos2fARB(float arg0, float arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos2fMESA(float arg0, float arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos2fv(FloatBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos2fv(float[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos2fvARB(FloatBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos2fvARB(float[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos2fvMESA(FloatBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos2fvMESA(float[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos2i(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos2iARB(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos2iMESA(int arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos2iv(IntBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos2iv(int[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos2ivARB(IntBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos2ivARB(int[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos2ivMESA(IntBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos2ivMESA(int[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos2s(short arg0, short arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos2sARB(short arg0, short arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos2sMESA(short arg0, short arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos2sv(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos2sv(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos2svARB(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos2svARB(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos2svMESA(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos2svMESA(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos3d(double arg0, double arg1, double arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos3dARB(double arg0, double arg1, double arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos3dMESA(double arg0, double arg1, double arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos3dv(DoubleBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos3dv(double[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos3dvARB(DoubleBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos3dvARB(double[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos3dvMESA(DoubleBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos3dvMESA(double[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos3f(float arg0, float arg1, float arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos3fARB(float arg0, float arg1, float arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos3fMESA(float arg0, float arg1, float arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos3fv(FloatBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos3fv(float[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos3fvARB(FloatBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos3fvARB(float[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos3fvMESA(FloatBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos3fvMESA(float[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos3i(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos3iARB(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos3iMESA(int arg0, int arg1, int arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos3iv(IntBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos3iv(int[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos3ivARB(IntBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos3ivARB(int[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos3ivMESA(IntBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos3ivMESA(int[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos3s(short arg0, short arg1, short arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos3sARB(short arg0, short arg1, short arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos3sMESA(short arg0, short arg1, short arg2)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos3sv(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos3sv(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos3svARB(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos3svARB(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos3svMESA(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos3svMESA(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos4dMESA(double arg0, double arg1, double arg2, double arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos4dvMESA(DoubleBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos4dvMESA(double[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos4fMESA(float arg0, float arg1, float arg2, float arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos4fvMESA(FloatBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos4fvMESA(float[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos4iMESA(int arg0, int arg1, int arg2, int arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos4ivMESA(IntBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos4ivMESA(int[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos4sMESA(short arg0, short arg1, short arg2, short arg3)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos4svMESA(ShortBuffer arg0)
	{
		// Stub method only.
		
	}

	@Override
	public void glWindowPos4svMESA(short[] arg0, int arg1)
	{
		// Stub method only.
		
	}

	@Override
	public void glWriteMaskEXT(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
	{
		// Stub method only.
		
	}

	@Override
	public boolean isExtensionAvailable(String arg0)
	{
		// Stub method only.
		return false;
	}

	@Override
	public boolean isFunctionAvailable(String arg0)
	{
		// Stub method only.
		return false;
	}

	@Override
	public void setSwapInterval(int arg0)
	{
		// Stub method only.
		
	}

}
