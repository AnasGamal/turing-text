cmake_minimum_required(VERSION 3.0)
project(turing-text)

# Find all source and header files in the current directory
file(GLOB SOURCES *.cpp)
file(GLOB HEADERS *.h)

# Add the executable target
add_executable(MyProject ${SOURCES} ${HEADERS})
