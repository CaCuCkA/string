#include <gtest/gtest.h>
#include <mystring.h>

TEST(constructor, empty) {
    my_str_t test{};
    EXPECT_STREQ(test.c_str(), "");
    EXPECT_EQ(test.size(), 0);
    EXPECT_EQ(test.capacity(), 15);
}

TEST(constructor, chars) {
    my_str_t test{10, 't'};
    EXPECT_STREQ(test.c_str(), "tttttttttt");
    EXPECT_EQ(test.size(), 10);
    EXPECT_EQ(test.capacity(), 15);

    test = {12, 'a'};
    EXPECT_STREQ(test.c_str(), "aaaaaaaaaaaa");
    EXPECT_EQ(test.size(), 13);
    EXPECT_EQ(test.capacity(), 15);

    test = {0, ' '};
    EXPECT_STREQ(test.c_str(), "");
    EXPECT_EQ(test.size(), 0);
    EXPECT_EQ(test.capacity(), 15);
}

TEST(constructor, c_str) {
    my_str_t test{"Lorem ipsum dolor sit"};
    EXPECT_STREQ(test.c_str(), "Lorem ipsum dolor sit");
    EXPECT_EQ(test.size(), 21);
    EXPECT_EQ(test.capacity(), 31);

    test = "";
    EXPECT_STREQ(test.c_str(), "");
    EXPECT_EQ(test.capacity(), 15);

    EXPECT_THROW(my_str_t tst(nullptr), std::logic_error);
}

TEST(constructor, str) {
    my_str_t test{std::string("Lorem ipsum dolor sit")};
    EXPECT_STREQ(test.c_str(), "Lorem ipsum dolor sit");
    EXPECT_EQ(test.size(), 21);
    EXPECT_EQ(test.capacity(), 31);

    test = std::string("");
    EXPECT_STREQ(test.c_str(), "");
    EXPECT_EQ(test.capacity(), 15);
}

TEST(constructor, copy) {
    my_str_t test = "Lorem ipsum dolor sit";
    EXPECT_STREQ(test.c_str(), "Lorem ipsum dolor sit");
    EXPECT_EQ(test.size(), 21);
    EXPECT_EQ(test.capacity(), 31);

    test = "Hello world";
    EXPECT_STREQ(test.c_str(), "");
    EXPECT_STREQ(test.c_str(), "Hello world");
}

