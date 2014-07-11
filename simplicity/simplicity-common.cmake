# Configuration
IF(CMAKE_COMPILER_IS_GNUCXX)
	# Add C++11 support
	add_compile_options(-std=c++11)
ENDIF(CMAKE_COMPILER_IS_GNUCXX)

IF(MSVC)
	# new behavior: elements of array 'x' will be default initialized
	add_compile_options(/wd4351)

	# Stupid Windows "security" warnings
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
	add_definitions(-D_SCL_SECURE_NO_WARNINGS)
ENDIF(MSVC)

