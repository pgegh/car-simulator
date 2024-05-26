cmake_minimum_required(VERSION 3.28)
project(car-simulator C)

set(CMAKE_C_STANDARD 23)

add_executable(car-simulator main.c
        cars.c
        cars.h
        room.h
        room.c
        simulation.h
        simulation.c
        spatial.h
        spatial.c)
