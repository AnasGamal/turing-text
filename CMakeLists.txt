cmake_minimum_required(VERSION 3.16)
project(turing-text)

set(CMAKE_CXX_STANDARD 17)

# Set the paths for the include directories and source files
set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")
set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")

# Add the include directories to the include path
include_directories(${INCLUDE_DIR})

# Find all the source files in the src directory
file(GLOB SOURCES "${SRC_DIR}/*.cpp")

# Define the executable target
add_executable(${PROJECT_NAME} ${SOURCES})

# Add any required libraries
target_link_libraries(${PROJECT_NAME} PRIVATE cpr nlohmann_json)

# Set compiler flags
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
