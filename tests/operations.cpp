#include <gtest/gtest.h>
#include <mystring.h>


TEST(Operations, add) {
    my_str_t a{"abdc"};
    my_str_t b{"cdba"};
    EXPECT_STREQ((a + b).c_str(), "abdccdba");
    EXPECT_STREQ((a + a).c_str(), "abdcabdc");
    a += b;
    EXPECT_STREQ(a.c_str(), "abdccdba");
    b += b;
    EXPECT_STREQ(b.c_str(), "cdbacdba");
}

TEST(Operations, mul) {
    my_str_t a{"a"};
    EXPECT_STREQ((a * 2).c_str(), "aa");
    EXPECT_STREQ((a * 5).c_str(), "aaaaa");
    EXPECT_STREQ((a * 10).c_str(), "aaaaaaaaaa");
    EXPECT_STREQ((a * 20).c_str(), "aaaaaaaaaaaaaaaaaaaa");
    a *= 10;
    EXPECT_STREQ(a.c_str(), "aaaaaaaaaa");
}