cmake_minimum_required(VERSION 3.16)
project(turing-text)

set(CMAKE_CXX_STANDARD 17)

# Set the paths for the include directories and source files
set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")
set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")

# Add the include directories to the include path
include_directories(${INCLUDE_DIR})

# Define the source files
set(SOURCES ${SRC_DIR}/AiClass.cpp
            ${SRC_DIR}/Delegator.h
            ${SRC_DIR}/Delegator.cpp
            ${SRC_DIR}/GameBook.h
            ${SRC_DIR}/GameBook.cpp
            ${SRC_DIR}/HelpTool.h
            ${SRC_DIR}/HelpTool.cpp
            ${SRC_DIR}/Human.h
            ${SRC_DIR}/Human.cpp
            ${SRC_DIR}/main.cpp)

# Define the executable target
add_executable(${PROJECT_NAME} ${SOURCES})

# Add any required libraries
target_link_libraries(${PROJECT_NAME} PRIVATE cpr nlohmann_json)

# Set compiler flags
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
