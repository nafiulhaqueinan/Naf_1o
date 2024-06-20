cmake_minimum_required(VERSION 3.22)
project(Chess_engine)

set(CMAKE_CXX_STANDARD 20)

add_executable(Chess_engine main.cpp init.cpp bitboard.cpp hashkey.cpp Board.cpp data.cpp)
