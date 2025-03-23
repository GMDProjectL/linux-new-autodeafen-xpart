cmake_minimum_required(VERSION 3.10.0)
project(lnax VERSION 0.1.0 LANGUAGES C CXX)

find_package(X11 REQUIRED COMPONENTS XTest)
link_libraries(${X11_LIBRARIES} Xtst)
include_directories(${X11_INCLUDE_DIR})

add_executable(lnax main.cpp)

