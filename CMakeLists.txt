cmake_minimum_required(VERSION 3.11)
project(bank-system)

cmake_policy(SET CMP0054 NEW)

# Set default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Build type flags
set(CMAKE_CXX_FLAGS_DEBUG "-g3")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Load module for speeding up builds
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(cotire)

# Download unit testing framework
include(cmake/CPM.cmake)
CPMAddPackage("gh:catchorg/Catch2@3.1.0")

# Public libraries needed for both main executable and tests
add_library(lib
    src/utils.cpp
    src/bank.cpp
    src/account.cpp)

# Make executable link against library
add_executable(${PROJECT_NAME} src/main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} PUBLIC lib)

# Same here for tests
add_executable(tests
    test/testUtils.cpp
    test/testBank.cpp
    test/testAccount.cpp)
target_link_libraries(tests PUBLIC lib)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

# Speed up both builds
cotire(${PROJECT_NAME} tests)

if (MSVC)
    # Warning level 4 and all warnings as errors
    add_compile_options(/W4 /Wx)
else()
    # Lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()
