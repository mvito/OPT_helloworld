# - Find the libterra includes and library
# This module defines
#  TERRA_INCLUDE_DIR, path to terra/terra.h, etc.
#  TERRA_LIBRARIES, the libraries required to use terra.
#  TERRA_FOUND, If false, do not try to use terra.
# also defined, but not for general use are
#  TERRA_LIBRARY, where to find the terra library.

FIND_PATH(TERRA_INCLUDE_DIR terra/terra.h
  PATHS
  /usr/local/include
  /usr/include
  ${TERRA_ROOT_DIR}
  $ENV{HOME}/terra
  $ENV{TERRA_ROOT_DIR}
  ${TERRA_ROOT_DIR}
  PATH_SUFFIXES
  terra
  include
  release/include
  API/release/include
)

FIND_LIBRARY(TERRA_LIBRARY NAMES libterra.a
  PATHS
  /usr/local/lib
  /usr/lib
  ${TERRA_ROOT_DIR}
  $ENV{HOME}/terra
  $ENV{TERRA_ROOT_DIR}
  ${TERRA_ROOT_DIR}
  PATH_SUFFIXES
  terra
  lib
  release/lib
  API/release/lib
)

MARK_AS_ADVANCED(
  TERRA_INCLUDE_DIR
  TERRA_LIBRARY)

SET( TERRA_FOUND "NO" )
IF(TERRA_INCLUDE_DIR)
  IF(TERRA_LIBRARY)
    SET( TERRA_FOUND "YES" )
    SET( TERRA_LIBRARIES
      ${TERRA_LIBRARY})
  ENDIF(TERRA_LIBRARY)
ENDIF(TERRA_INCLUDE_DIR)

IF(TERRA_FOUND)
    MESSAGE(STATUS "Found terra:")
    MESSAGE(STATUS " - Includes: ${TERRA_INCLUDE_DIR}")
    MESSAGE(STATUS " - Libraries: ${TERRA_LIBRARIES}")
ELSE(TERRA_FOUND)
  IF(TERRA_FIND_REQUIRED)
    MESSAGE(FATAL_ERROR "Could not find libterra
-- please give some paths to CMake or make sure libterra is installed in your system")
  ELSE(TERRA_FIND_REQUIRED)
    MESSAGE(STATUS "Could not find libterra
-- please give some paths to CMake or make sure libterra is installed in your system")
  ENDIF(TERRA_FIND_REQUIRED)
ENDIF(TERRA_FOUND)
