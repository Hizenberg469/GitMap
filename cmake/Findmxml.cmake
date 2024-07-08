# Findmxml.cmake


# Locate the mxml library
message(STATUS "Searching for mxml library")
find_library(MXML_LIBRARY_STATIC
  NAMES libmxml4.a
  HINTS
    ${CMAKE_SOURCE_DIR}/utils/mxml/lib
    ${CMAKE_SOURCE_DIR}/utils/mxml
  PATH_SUFFIXES lib
  DOC "Path to the mxml library"
)

message(STATUS "MXML_LIBRARY: ${MXML_LIBRARY_STATIC}")


# Locate the directory containing mxml.h
message(STATUS "Searching for mxml.h")
find_path(MXML_INCLUDE_DIR
  NAMES mxml.h
  HINTS
    ${CMAKE_SOURCE_DIR}/utils/mxml/include
    ${CMAKE_SOURCE_DIR}/utils/mxml
  PATH_SUFFIXES include
  DOC "Path to the mxml.h file"
)
message(STATUS "MXML_INCLUDE_DIR: ${MXML_INCLUDE_DIR}")
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(mxml REQUIRED_VARS MXML_LIBRARY_STATIC MXML_INCLUDE_DIR
                                  HANDLE_COMPONENTS)

if(MXML_FOUND)
  set(MXML_LIBRARIES ${MXML_LIBRARY_STATIC})
  set(MXML_INCLUDE_DIRS ${MXML_INCLUDE_DIR})
else()
  set(MXML_LIBRARIES)
  set(MXML_INCLUDE_DIRS)
endif()

mark_as_advanced(MXML_INCLUDE_DIR MXML_LIBRARY_STATIC)