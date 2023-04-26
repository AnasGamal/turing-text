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

# Loop over each source file and create an executable for each one
# Loop over each source file and create an executable for each one
foreach(SOURCE_FILE ${SOURCES})
    # Extract the name of the source file without the extension
    get_filename_component(EXEC_NAME ${SOURCE_FILE} NAME_WE)

    # Append the name of the executable to a common prefix to create a unique target name
    set(TARGET_NAME "${PROJECT_NAME}_${EXEC_NAME}")

    # Add the source file to the executable
    add_executable(${TARGET_NAME} ${SOURCE_FILE})

    # Add any required libraries
    target_link_libraries(${TARGET_NAME} PRIVATE cpr nlohmann_json)

    # Set compiler flags
    target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra -pedantic)
endforeach()
