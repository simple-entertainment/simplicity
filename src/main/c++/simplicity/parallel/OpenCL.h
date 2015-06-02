#include <string>

#include "../resources/Resource.h"

namespace simplicity
{
	namespace OpenCL
	{
		bool addProgram(Resource& source, const std::string& name);

		bool executeKernel(const std::string& programName, const std::string& kernelName, float* lhs, float* rhs,
				float* product);

		void init();
	}
}
