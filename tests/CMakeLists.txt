# find GoogleTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# set the same strict compilation flags for tests
add_compile_options(-Wall -Wextra -Werror -std=c++98)

# add unit test executable for vector
add_executable(test_vector_unit unit/sequence_containers/test_vector.cpp)
target_link_libraries(test_vector_unit ${GTEST_LIBRARIES} pthread)

# add integration test executable for vector
# add_executable(test_vector_integration integration/sequence_containers/test_vector.cpp)
# target_link_libraries(test_vector_integration ${GTEST_LIBRARIES} pthread)

# register the tests with CTest
add_test(NAME VectorUnitTest COMMAND test_vector_unit)
# add_test(NAME VectorIntegrationTest COMMAND test_vector_integration)
