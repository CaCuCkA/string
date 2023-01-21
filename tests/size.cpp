#include <gtest/gtest.h>
#include <mystring.h>

TEST(size, shrink_to_fit) {
    my_str_t test{"I like banana"};
    test.reserve(1000);
    EXPECT_EQ(test.capacity(), 1000);
    test.shrink_to_fit();
    EXPECT_STREQ(test.c_str(), "I like banana");
    EXPECT_EQ(test.capacity(), 15);
}

TEST(size, reserve) {
    my_str_t test{"Hello world!"};
    size_t size = test.capacity() * 2;
    for (size_t i = test.capacity(); i < size; ++i) {
        EXPECT_STREQ(test.c_str(), "Hello world!");
        EXPECT_EQ(test.capacity(), i);
    }
}

TEST(size, resize) {
    my_str_t test{16, 'v'};
    for (size_t i = 31; i < 47; ++i) {
        my_str_t check{i, 'v'};
        test.resize(i, 'v');
        EXPECT_STREQ(test.c_str(), check.c_str());
        EXPECT_EQ(test.size(), i);
    }
}

TEST(size, clear) {
    my_str_t test{20, 'm'};
    test.clear();
    EXPECT_STREQ(test.c_str(), "");
    EXPECT_EQ(test.size(), 0);
    EXPECT_EQ(test.capacity(), 31);
}