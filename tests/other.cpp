#include <gtest/gtest.h>
#include <mystring.h>


TEST(Other, swap) {
    my_str_t a{"some string"};
    my_str_t b{"some other string"};
    a.swap(b);
    EXPECT_STREQ(a.c_str(), "some other string");
    EXPECT_STREQ(b.c_str(), "some string");
}