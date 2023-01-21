#include <gtest/gtest.h>
#include <mystring.h>


TEST(Constructors, empty) {
    my_str_t a{};
    EXPECT_STREQ(a.c_str(), "");
    EXPECT_EQ(a.capacity(), 15);
}

TEST(Constructors, fill) {
    my_str_t a{5, 's'};
    EXPECT_STREQ(a.c_str(), "sssss");
    EXPECT_EQ(a.capacity(), 15);
    a = {21, 'a'};
    EXPECT_EQ(a.capacity(), 31);
    a = {0, ' '};
    EXPECT_STREQ(a.c_str(), "");
    EXPECT_EQ(a.capacity(), 15);
}

TEST(Constructor, c_str) {
    my_str_t a{"abcde"};
    EXPECT_STREQ(a.c_str(), "abcde");
    EXPECT_EQ(a.capacity(), 15);
    a = "";
    EXPECT_STREQ(a.c_str(), "");
    EXPECT_EQ(a.capacity(), 15);
    EXPECT_THROW(my_str_t b(nullptr), std::logic_error);
}

TEST(Constructors, std_str) {
    my_str_t a{std::string{"abcde"}};
    EXPECT_STREQ(a.c_str(), "abcde");
    EXPECT_EQ(a.capacity(), 15);
    a = std::string{""};
    EXPECT_STREQ(a.c_str(), "");
    EXPECT_EQ(a.capacity(), 15);
}

TEST(Constructors, copy) {
    my_str_t a{"abcde"};
    my_str_t b{a};
    EXPECT_STREQ(a.c_str(), b.c_str());
    a[2] = '0';
    EXPECT_STREQ(b.c_str(), "abcde");
    a = "tuvwxyz";
    EXPECT_STREQ(b.c_str(), "abcde");
    b = "hello world!";
    EXPECT_STREQ(a.c_str(), "tuvwxyz");
    EXPECT_STREQ(b.c_str(), "hello world!");
}

TEST(Constructors, move) {
    my_str_t a{"abcd"};
    const char* a_cst = a.c_str();
    my_str_t b = std::move(a);
    const char* b_cst = b.c_str();
    EXPECT_EQ(a_cst, b_cst);
}
