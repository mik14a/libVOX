cmake_minimum_required(VERSION 3.0.0)
project(libVOX VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(libVOX
	source/libvox.cpp
	source/vox.cpp
	source/chunk/layr.cpp
	source/chunk/main.cpp
	source/chunk/pack.cpp
	source/chunk/rgba.cpp
	source/chunk/size.cpp
	source/chunk/xyzi.cpp
	source/node/group.cpp
	source/node/shape.cpp
	source/node/transform.cpp
)
include_directories("include")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
