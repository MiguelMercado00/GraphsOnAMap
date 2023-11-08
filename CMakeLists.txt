cmake_minimum_required(VERSION 3.26)
project(GraphsOnAMap)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(GraphsOnAMap
        Arista.cpp
        Arista.h
        GrafoDirigido.cpp
        GrafoDirigido.h
        Main.cpp
        Nodo.cpp
        Nodo.h)
