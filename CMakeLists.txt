cmake_minimum_required(VERSION 2.8...3.20)

project(ModernCpp)

#set(CMAKE_BUILD_TYPE Release)
#set(CMAKE_BUILD_TYPE Release CACHE STRING "set build type to release")

#message(project_dir=${PROJECT_SOURCE_DIR})

# 指定为C++ 17 版本
set(CMAKE_CXX_STANDARD 17)

if (${CMAKE_BINARY_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
	message(FATAL_ERROR "Please into another dir to build!")
endif()

if (CMAKE_SYSTEM_NAME MATCHES "Linux")
	add_definitions("-O2")
	set(UNIX_OS true)
elseif (CMAKE_SYSTEM_NAME MATCHES "Darwin")
	add_definitions("-O3")
	add_definitions("-Wno-invalid-source-encoding")
	add_definitions("-fdata-sections -ffunction-sections")
	add_definitions("-flto")
	add_definitions("-Os")
	set(UNIX_OS true)
else()
	message(FATAL_ERROR "unknown CMAKE_SYSTEM_NAME=${CMAKE_SYSTEM_NAME}")
endif()

##############################################################################

include_directories(
	
)

set(source_01  ${CMAKE_CURRENT_SOURCE_DIR}/src/1-1.cpp)
set(source_02  ${CMAKE_CURRENT_SOURCE_DIR}/src/2-1.cpp)
set(source_0202  ${CMAKE_CURRENT_SOURCE_DIR}/src/2-2.cpp)
set(source_03  ${CMAKE_CURRENT_SOURCE_DIR}/src/3-1.cpp)
set(source_04  ${CMAKE_CURRENT_SOURCE_DIR}/src/4-1.cpp)
set(source_06_05  ${CMAKE_CURRENT_SOURCE_DIR}/src/6-5.cpp)
set(source_06_08  ${CMAKE_CURRENT_SOURCE_DIR}/src/6-8.cpp)
##############################################################################

#if (CMAKE_BUILD_TYPE STREQUAL "")
#	set(CMAKE_BUILD_TYPE "DEBUG")
#else()
#	string(TOUPPER CMAKE_BUILD_TYPE CMAKE_BUILD_TYPE)
#endif()


if (${UNIX_OS})
	add_definitions(
		"-W"
		"-fPIC"
		"-Wall"
		"-Wshadow"
		"-Wpointer-arith"
		"-Waggregate-return"
		"-Wno-long-long"
		"-Wuninitialized"
		"-fno-elide-constructors"
	)

	if (!CMAKE_BUILD_TYPE STREQUAL "RELEASE")
		add_definitions("-g")
	endif()
endif()


add_executable(ex01 ${source_01})
add_executable(ex02-01 ${source_02})
add_executable(ex02-02 ${source_0202})
add_executable(ex03 ${source_03})
add_executable(ex04 ${source_04})
add_executable(ex06_05 ${source_06_05})
add_executable(ex06_08 ${source_06_08})