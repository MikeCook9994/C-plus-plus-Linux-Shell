cmake_minimum_required(VERSION 3.2.2)
project(LeShell)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Shell.cpp ExecuteExternalCommand.cpp ExecuteInternalCommand.cpp)
add_executable(LeShell ${SOURCE_FILES})