cmake_minimum_required(VERSION 3.23)
project(FlightManager)

set(CMAKE_CXX_STANDARD 14)

add_executable(FlightManager
        src/Airline.cpp
        src/Airline.h
        src/Airport.cpp
        src/Airport.h
        src/Graph.cpp
        src/Graph.h
        src/main.cpp src/Flight.cpp src/Flight.h)
