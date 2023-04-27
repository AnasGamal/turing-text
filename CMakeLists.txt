cmake_minimum_required(VERSION 3.0)
project(turing-text)

# Include CPM.cmake
include(CPM.cmake)

# Add nlohmann_json as a dependency
CPMAddPackage(
    NAME nlohmann_json
    GITHUB_REPOSITORY nlohmann/json
    VERSION 3.9.1
)

# Find all source files in the current directory
file(GLOB SOURCES *.cpp)

# Add the executable target
add_executable(turing-text ${SOURCES})

# Find all header files in the current directory
file(GLOB HEADERS *.h)
file(GLOB HEADERS *.hpp)

# Add the header files to the target
target_sources(turing-text PRIVATE ${HEADERS})

# Find and include the cpr library
find_package(cpr REQUIRED)
target_link_libraries(turing-text PRIVATE cpr::cpr)

# Link the nlohmann_json library
target_link_libraries(turing-text PRIVATE nlohmann_json::nlohmann_json)
