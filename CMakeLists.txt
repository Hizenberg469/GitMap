# CMakeList.txt : CMake project for GitMap, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project(GitMap VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

#File structure for output executable and library directory...
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/$<CONFIG>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/$<CONFIG>")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/$<CONFIG>")


set(GITMAP_LIBRARY GitMap)

set(HEADER_DIR "${CMAKE_SOURCE_DIR}/include")
set(SOURCE_DIR$ "${CMAKE_SOUCRE_DIR}/src")
set(EXTERNAL_DIR "${CMAKE_SOURCE_DIR}/utils")
set(TEST_DIR "${CMAKE_SOURCE_DIR}/test")
set(EXECUTABLE_DIR "${CMAKE_SOURCE_DIR}/main")

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
include(AddGitSubmodule)

add_git_submodule(utils mxml https://github.com/michaelrsweet/mxml.git)

find_package(mxml REQUIRED)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(main)
