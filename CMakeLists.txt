cmake_minimum_required(VERSION 3.10)

# project name and C++ Standard
project(Abstract_data CXX)
set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set compiler flags for stricter compilation
add_compile_options(-Wall -Wextra -Werror -std=c++98)

# enable testing support
enable_testing()

# add GTest as a subdirectory
add_subdirectory(external/googletest)

# include GTest headers
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# add the include directory for the sequence containers
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/srcs/sequence_containers)

# add tests as a subdirectory
add_subdirectory(tests)
