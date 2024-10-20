# use strict compilation flags for tests
add_compile_options(-Wall -Wextra -Werror -std=c++98)

# include GTest headers from the submodule
include_directories(${gtest_SOURCE_DIR}/include)

# add unit test executable for vector
add_executable(test_vector_unit units/sequence_containers/test_vector_unit.cpp)
target_link_libraries(test_vector_unit gtest gtest_main pthread)

# Register the test with CTest
add_test(NAME VectorUnitTest COMMAND test_vector_unit)
