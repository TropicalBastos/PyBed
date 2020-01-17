cmake_minimum_required (VERSION 2.6)

set(CMAKE_CXX_STANDARD 11)

set(PROJECT_TITLE "PyBed")
project (${PROJECT_TITLE})

include("cmake/FindPythonLibsNew.cmake")
# find_package(Python)
# file(GLOB_RECURSE PYTHON_HEADER "${CMAKE_PREFIX_PATH}/Python.h")
# set(PYTHON_INCLUDE_DIR "${PYTHON_HEADER}..")
message(STATUS "Python include dirs at: ${PYTHON_INCLUDE_DIRS}")
message(STATUS "Python library at: ${PYTHON_LIBRARY}")

include_directories(${PYTHON_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/src)

FILE(GLOB src_files ${PROJECT_SOURCE_DIR}/src/*.cpp)

# add_subdirectory(pybind11)
# pybind11_add_module(${PROJECT_TITLE} SHARED ${src_files})

add_library(PyBed STATIC
	${src_files}
)

target_link_libraries(PyBed PRIVATE ${PYTHON_LIBRARY})

