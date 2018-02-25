# Authors: Alessio Rocchi
# CopyPolicy: Released under the terms of the GNU GPL v2.0.

CMAKE_MINIMUM_REQUIRED(VERSION 2.8.12)
INCLUDE(ExternalProject)
LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

SET(PROJECT_NAME opensim-python-utils)
PROJECT(${PROJECT_NAME})

FIND_PACKAGE(OpenSim REQUIRED)
FIND_PACKAGE(PythonLibs 2.7 REQUIRED)
FIND_PACKAGE(PythonInterp 2.7 REQUIRED)
FIND_PACKAGE(SWIG)
INCLUDE(UseSWIG)

INCLUDE_DIRECTORIES(. ${PYTHON_INCLUDE_PATH} ${OPENSIMSIMBODY_INCLUDE_DIRS})
LINK_LIBRARIES(${PYTHON_LIBRARY} ${OPENSIMSIMBODY_LIBRARIES})

set_source_files_properties(opensim-python-utils.i PROPERTIES CPLUSPLUS ON)

set(CMAKE_SWIG_FLAGS "-Wall;-module;opensim_pyutils;-threads")

set(target_name opensim_pytils)

swig_add_module(${target_name} python opensim-python-utils.i)
set_target_properties(_${target_name} PROPERTIES OUTPUT_NAME "_opensim_pyutils")
set_target_properties(_${target_name} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/python)

# installation path is determined reliably on most platforms using distutils
execute_process(COMMAND ${PYTHON_EXECUTABLE} -c "from distutils import sysconfig; print(sysconfig.get_python_lib(1,0,prefix=''))"
OUTPUT_VARIABLE PYTHON_INSTDIR OUTPUT_STRIP_TRAILING_WHITESPACE )
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/opensim_pyutils.py DESTINATION ${PYTHON_INSTDIR} )
install(TARGETS _${target_name} DESTINATION ${PYTHON_INSTDIR} )
