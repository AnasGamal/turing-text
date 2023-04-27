cmake_minimum_required(VERSION 3.0)
project(turing-text)

# Find all source files in the current directory
file(GLOB SOURCES *.cpp)

# Add the executable target
add_executable(turing-text ${SOURCES})

# Find all header files in the current directory
file(GLOB HEADERS *.h)

# Add the header files to the target
target_sources(turing-text PRIVATE ${HEADERS})

# Find and include the cpr library
find_package(cpr CONFIG REQUIRED)
target_link_libraries(turing-text PRIVATE cpr::cpr)
