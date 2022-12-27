cmake_minimum_required(VERSION 3.23)
project(FlightManager)

set(CMAKE_CXX_STANDARD 14)

add_executable(FlightManager src/main.cpp src/Graph.cpp src/Graph.h)
