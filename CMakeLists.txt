cmake_minimum_required(VERSION 3.10)
project(turing-text VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(turing-text main.cpp AiClass.cpp GameBook.cpp human.cpp)
