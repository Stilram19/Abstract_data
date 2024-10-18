cmake_minimum_required(VERSION 3.10)

# project name and C++ Standard
project(Abstract_data CXX)
set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set compiler flags for stricter compilation
add_compile_options(-Wall -Wextra -Werror -std=c++98)

# set global include directories (for all tests)
include_directories("${CMAKE_SOURCE_DIR}/srcs/sequence_containers")
include_directories("${CMAKE_SOURCE_DIR}/srcs/associative_containers")
include_directories("${CMAKE_SOURCE_DIR}/srcs/adaptive_containers")

# Enable testing support
enable_testing()

# Add GTest as a subdirectory
add_subdirectory(external/googletest)

# Include GTest headers
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Add each container test as an executable and link it to gtest
add_subdirectory(tests)
