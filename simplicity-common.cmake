# C++11
IF(UNIX)
	add_compile_options(-std=c++11)
ENDIF(UNIX)

# Linking
IF(SIMPLE_LINK_TYPE MATCHES SHARED)
	add_compile_options(-fPIC)
ELSE()
	set(SIMPLE_LINK_TYPE STATIC)
ENDIF(SIMPLE_LINK_TYPE MATCHES SHARED)

# Debugging
IF(CMAKE_BUILD_TYPE MATCHES Debug)
	add_definitions(-D_DEBUG)
ELSEIF(CMAKE_BUILD_TYPE MATCHES RelWithDebInfo)
	add_definitions(-D_DEBUG)
ELSE()
	add_definitions(-DNDEBUG)
ENDIF(CMAKE_BUILD_TYPE MATCHES Debug)

# Warnings
IF(MSVC)
	# new behavior: elements of array 'x' will be default initialized
	add_compile_options(/wd4351)

	# Stupid Windows "security" warnings
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
	add_definitions(-D_SCL_SECURE_NO_WARNINGS)
ENDIF(MSVC)
