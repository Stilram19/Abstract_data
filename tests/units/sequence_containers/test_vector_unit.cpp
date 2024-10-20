#include "ft_vector.hpp"
#include <gtest/gtest.h>

// test suite for ft::vector
TEST(VectorTest, DefaultConstructor) {
    ft::vector<int> vec;

    EXPECT_EQ(vec.size(), 0);
    EXPECT_EQ(vec.capacity(), 0);
}

TEST(VectorTest, FillConstructor) {
    ft::vector<int> vec(5, 42);

    EXPECT_EQ(vec.size(), 5);
    EXPECT_EQ(vec.capacity(), 5);
    for (size_t i = 0; i < vec.size(); i++) {
        EXPECT_EQ(vec[i], 42);
    }
}

TEST(VectorTest, CopyConstructor) {
    ft::vector<int> original(5, 99);
    ft::vector<int> copy(original);

    EXPECT_EQ(copy.size(), original.size());
    EXPECT_EQ(copy.capacity(), original.capacity());
    for (size_t i = 0; i < copy.size(); i++) {
        EXPECT_EQ(copy[i], original[i]);
    }
}

TEST(VectorTest, CopyAssignment) {
    ft::vector<int> original(3, 7);
    ft::vector<int> target;

    target = original;

    EXPECT_EQ(target.size(), original.size());
    EXPECT_EQ(target.capacity(), original.capacity());
    for (size_t i = 0; i < target.size(); i++) {
        EXPECT_EQ(target[i], original[i]);
    }

    // test self-assignment
    target = target;
    EXPECT_EQ(target.size(), original.size());
    EXPECT_EQ(target.capacity(), original.capacity());
}
