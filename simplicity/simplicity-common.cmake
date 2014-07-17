# C++11
IF(UNIX)
	add_compile_options(-std=c++11)
ENDIF(UNIX)

# Debugging
IF(CMAKE_BUILD_TYPE MATCHES Debug)
	add_definitions(-D_DEBUG)
ELSE(CMAKE_BUILD_TYPE MATCHES RelWithDebInfo)
	add_definitions(-D_DEBUG)
ELSE()
	add_definitions(-DNDEBUG)
ENDIF()

# Warnings
IF(MSVC)
	# new behavior: elements of array 'x' will be default initialized
	add_compile_options(/wd4351)

	# Stupid Windows "security" warnings
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
	add_definitions(-D_SCL_SECURE_NO_WARNINGS)
ENDIF(MSVC)

