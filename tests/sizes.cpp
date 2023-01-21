#include <gtest/gtest.h>
#include <mystring.h>


TEST(Sizes, reserve) {
    my_str_t a{"Some string"};
    for (int i = 15; i < 20; ++i) {
        a.reserve(i);
        EXPECT_STREQ(a.c_str(), "Some string");
        EXPECT_EQ(a.capacity(), i);
    }
    a.reserve(50);;
    EXPECT_STREQ(a.c_str(), "Some string");
    a.reserve(45);;
    EXPECT_STREQ(a.c_str(), "Some string");
    EXPECT_EQ(a.capacity(), 50);
}

TEST(Sizes, shrink_to_fit) {
    my_str_t a{"Some string"};
    a.reserve(50);
    EXPECT_EQ(a.capacity(), 50);
    a.shrink_to_fit();
    EXPECT_STREQ(a.c_str(), "Some string");
    EXPECT_EQ(a.capacity(), 15);
}

TEST(Sizes, resize) {
    my_str_t a{12, 'a'};
    for (size_t i = 17; i < 32; ++i) {
        my_str_t b{i, 'a'};
        a.resize(i, 'a');
        EXPECT_STREQ(a.c_str(), b.c_str());
        EXPECT_EQ(a.size(), i);
        EXPECT_EQ(a.capacity(), i);
        a.resize(32 - i, ' ');
        b = {32 - i, 'a'};
        EXPECT_STREQ(a.c_str(), b.c_str());
        EXPECT_EQ(a.size(), 32 - i);
        EXPECT_EQ(a.capacity(), i);
    }
}

TEST(Sizes, clear) {
    my_str_t a{20, 'i'};
    a.clear();
    EXPECT_EQ(a.size(), 0);
    EXPECT_STREQ(a.c_str(), "");
    EXPECT_EQ(a.capacity(), 31);
}