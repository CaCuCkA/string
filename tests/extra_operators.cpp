#include <gtest/gtest.h>
#include <mystring.h>

TEST(Operations, add) {
    my_str_t str1{"abdc"};
    my_str_t str2{"cdba"};
    EXPECT_STREQ((str1 + str2).c_str(), "abdccdba");
    EXPECT_STREQ((str1 + str1).c_str(), "abdcabdc");
    str1 += str2;
    EXPECT_STREQ(str1.c_str(), "abdccdba");
    str2 += str2;
    EXPECT_STREQ(str2.c_str(), "cdbacdba");
}

TEST(Operations, mul) {
    my_str_t test{"a"};
    EXPECT_STREQ((test * 2).c_str(), "aa");
    EXPECT_STREQ((test * 5).c_str(), "aaaaa");
    EXPECT_STREQ((test * 10).c_str(), "aaaaaaaaaa");
    EXPECT_STREQ((test * 20).c_str(), "aaaaaaaaaaaaaaaaaaaa");
    test *= 10;
    EXPECT_STREQ(test.c_str(), "aaaaaaaaaa");

    test = "Hello";
    EXPECT_STREQ((test * 2).c_str(), "HelloHello");

    test *= 8;
    EXPECT_STREQ((test).c_str(), "HelloHelloHelloHelloHelloHelloHelloHello");
    size_t size = str_len(test.c_str());
    EXPECT_EQ(test.size(), size);
}