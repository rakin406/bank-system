cmake_minimum_required(VERSION 3.11)
project(bank-system)

cmake_policy(SET CMP0054 NEW)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

message(STATUS ${CMAKE_BUILD_TYPE})

# Build type flags
set(CMAKE_CXX_FLAGS_DEBUG "-g3")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
string(APPEND CMAKE_CXX_FLAGS " -Wall -Wextra -pedantic -Werror")

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Download dependencies
include(cmake/CPM.cmake)
CPMAddPackage("gh:nlohmann/json@3.11.2")
CPMAddPackage("gh:catchorg/Catch2@3.1.0")

# Public libraries needed for both main executable and tests
add_library(lib
    src/utils.cpp
    src/bank.cpp
    src/client.cpp)

# Make executable link against library
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/setup.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} PUBLIC lib)
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)

# Same here for tests
add_executable(tests
    test/testUtils.cpp
    test/testBank.cpp
    test/testClient.cpp)
target_link_libraries(tests PUBLIC lib)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
