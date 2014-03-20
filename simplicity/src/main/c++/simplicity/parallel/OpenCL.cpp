#include <map>

#include <CL/opencl.h>

#include "../common/Timer.h"

using namespace std;

namespace simplicity
{
	namespace OpenCL
	{
		cl_context context;
		cl_device_id device;
		map<string, cl_kernel> kernels;
		cl_platform_id platform;
		map<string, cl_program> programs;
		cl_command_queue queue;

		bool addProgram(Resource& source, const string& name)
		{
			string sourceString = source.getData();

			cl_int error = 0;
			const char* cSourceString = sourceString.c_str();
			size_t sourceStringSize = sourceString.size();

			cl_program program = clCreateProgramWithSource(context, 1, &cSourceString, &sourceStringSize, &error);
			if (error != CL_SUCCESS) {
			   cout << "Error creating program: " << error << endl;
			   return false;
			}

			// Builds the program
			error = clBuildProgram(program, 1, &device, NULL, NULL, NULL);
			if (error != CL_SUCCESS) {
			   cout << "Error building program: " << error << endl;
			   return false;
			}

			// First call to know the proper size
			size_t logSize;
			clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG, 0, NULL, &logSize);

			// Second call to get the log
			string log(logSize, 'a');
			clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG, logSize, &log[0], NULL);
			cout << log << endl;

			programs[name] = program;

			return true;
		}

		bool executeKernel(const string& programName, const string& kernelName, float* lhs, float* rhs, float* product)
		{
			Timer timer;
			cl_int error = 0;

			// Extracting the kernel
			cl_kernel kernel = clCreateKernel(programs[programName], kernelName.c_str(), &error);
			if (error != CL_SUCCESS) {
			   cout << "Error creating kernel: " << error << endl;
			   return false;
			}

			float timer0 = timer.getElapsedTime();

			// Allocates a buffer of size mem_size and copies mem_size bytes from src_a_h
			cl_mem clLhs = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, sizeof(float) * 16, lhs,
					&error);
			cl_mem clRhs = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, sizeof(float) * 16, rhs,
					&error);
			cl_mem clProduct = clCreateBuffer(context, CL_MEM_WRITE_ONLY | CL_MEM_COPY_HOST_PTR, sizeof(float) * 16,
					product, &error);

			float timer1 = timer.getElapsedTime();

			// Enqueuing parameters
			// Note that we inform the size of the cl_mem object, not the size of the memory pointed by it
			error = clSetKernelArg(kernel, 0, sizeof(cl_mem), &clLhs);
			error |= clSetKernelArg(kernel, 1, sizeof(cl_mem), &clRhs);
			error |= clSetKernelArg(kernel, 2, sizeof(cl_mem), &clProduct);
			if (error != CL_SUCCESS) {
			   cout << "Error setting kernel arg: " << error << endl;
			   return false;
			}

			float timer2 = timer.getElapsedTime();

			// Launching kernel
			size_t one = 1;
			size_t workItems = 16;
			error = clEnqueueNDRangeKernel(queue, kernel, 1, NULL, &workItems, &one, 0, NULL, NULL);
			if (error != CL_SUCCESS) {
			   cout << "Error executing kernel: " << error << endl;
			   return false;
			}

			float timer3 = timer.getElapsedTime();

			// Reading back
			clEnqueueReadBuffer(queue, clProduct, CL_TRUE, 0, sizeof(float) * 16, product, 0, NULL, NULL);

			float timer4 = timer.getElapsedTime();

			// Cleaning up
			clReleaseKernel(kernel);
			//clReleaseCommandQueue(queue);
			//clReleaseContext(context);
			clReleaseMemObject(clLhs);
			clReleaseMemObject(clRhs);
			clReleaseMemObject(clProduct);

			float timer5 = timer.getElapsedTime();

			return true;
		}

		void init()
		{
			cl_int error = 0;

			// Platform
			error = clGetPlatformIDs(1, &platform, NULL);
			if (error != CL_SUCCESS) {
			   cout << "Error getting platform id: " << error << endl;
			   exit(error);
			}
			// Device
			error = clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 1, &device, NULL);
			if (error != CL_SUCCESS) {
			   cout << "Error getting device ids: " << error << endl;
			   exit(error);
			}
			// Context
			context = clCreateContext(0, 1, &device, NULL, NULL, &error);
			if (error != CL_SUCCESS) {
			   cout << "Error creating context: " << error << endl;
			   exit(error);
			}
			// Command-queue
			queue = clCreateCommandQueue(context, device, 0, &error);
			if (error != CL_SUCCESS) {
			   cout << "Error creating command queue: " << error << endl;
			   exit(error);
			}
		}
	}
}
