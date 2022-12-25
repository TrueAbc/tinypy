cmake_minimum_required(VERSION 3.20)
project(tinypy)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

SET(CMAKE_CXX_FLAGS_DEBUG "-O0 -Wall -g -ggdb -rdynamic")
SET(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall -rdynamic")
include_directories(.)

aux_source_directory (runtime libruntime)
aux_source_directory (object libobj)
aux_source_directory (code libcode)
aux_source_directory (util libutil)

add_executable(
        tinypy main.cpp
        ${libobj}
        ${libruntime}
        ${libcode}
        ${libutil}
)