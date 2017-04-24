#
# Linux implementation of opt warping image example
#
# Copyright (c) 2017 Marta <marta.villanuevat@estudiante.uam.es>
# Redistribution and use is allowed according to the terms of the 2-clause BSD license.

cmake_minimum_required(VERSION 2.6.0)

set(PROJECT_NAME OptExample)
project(${PROJECT_NAME})

########## Set debug mode ##########
set(CMAKE_BUILD_TYPE Debug)
####################################

set(CMAKE_VERBOSE_MAKEFILE ON) #create new variable value

# Add local path for finding packages, set the local version first
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package(OpenCV REQUIRED)
find_package(opt REQUIRED)
find_package(terra REQUIRED)
find_package(Threads REQUIRED)

include_directories(${OpenCV_INCLUDE_DIR})
include_directories(${OPT_INCLUDE_DIR})
include_directories(${Terra_INCLUDE_DIR})


set(SOURCES_DIR src)

file(GLOB srcs ${SOURCES_DIR}/*.cpp)
set(public_headers ${SOURCES_DIR}/*.h)

set(CMAKE_CXX_FLAGS "-O3 -msse2 -msse3 -Wall -std=c++11")

##### Executable
add_executable(${PROJECT_NAME}
        ${SOURCES_DIR}/main.cpp
        )
target_link_libraries(${PROJECT_NAME}
        ${OpenCV_LIBS}
        ${OPT_LIBRARIES}
        ${TERRA_LIBRARIES}
	${CMAKE_DL_LIBS}
        ${CMAKE_THREAD_LIBS_INIT}
 )
