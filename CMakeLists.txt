cmake_minimum_required(VERSION 3.15)
project(Stack)

set(CMAKE_CXX_STANDARD 20)

add_executable (Stack main.cpp Subvector.cpp Subvector.h Subforwardlist2.cpp Subforwardlist2.h)