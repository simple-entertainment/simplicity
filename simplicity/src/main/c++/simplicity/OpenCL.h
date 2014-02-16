#include <istream>
#include <string>

namespace simplicity
{
	namespace OpenCL
	{
		bool addProgram(std::istream& source, const std::string& name);

		bool executeKernel(const std::string& programName, const std::string& kernelName, float* lhs, float* rhs,
				float* product);

		void init();
	}
}
