cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
set(CMAKE_CXX_COMPILER "g++")
project(chess-game LANGUAGES CXX)
add_executable(chess chess.cpp)