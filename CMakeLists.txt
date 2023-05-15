cmake_minimum_required(VERSION 3.0)
project(turing-text)
set(BUILD_TESTING OFF)

# Include CPM.cmake
include(CPM.cmake)

# Add nlohmann_json as a dependency
CPMAddPackage(
    NAME nlohmann_json
    VERSION 3.9.1
    GITHUB_REPOSITORY "nlohmann/json"
    GIT_TAG "v3.9.1"
)

# Add Boost as a dependency
CPMAddPackage(
        NAME Boost
        VERSION 1.81.0
        GITHUB_REPOSITORY "boostorg/boost"
        GIT_TAG "boost-1.81.0"
)
# Add cpr as a dependency
CPMAddPackage(
        NAME cpr
        VERSION 1.10.0
        GITHUB_REPOSITORY "libcpr/cpr"
        GIT_TAG "1.10.0"
)


# Find all source files in the current directory
file(GLOB SOURCES *.cpp)

# Add the executable target
add_executable(turing-text ${SOURCES})

# Find all header files in the current directory
file(GLOB HEADERS *.h *.hpp)

# Add the header files to the target
target_sources(turing-text PRIVATE ${HEADERS})

# Find and include the cpr library
target_link_libraries(turing-text PRIVATE cpr::cpr)

# Find and include the nlohmann_json library
target_link_libraries(turing-text PRIVATE nlohmann_json::nlohmann_json)

# Find and include the Boost library
target_link_libraries(turing-text PRIVATE Boost::asio Boost::property_tree Boost::beast)
