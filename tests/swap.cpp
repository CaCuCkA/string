#include <gtest/gtest.h>
#include <mystring.h>


TEST(other, swap) {
    my_str_t a{"Ivan"};
    my_str_t b{"Mykola"};
    a.swap(b);
    EXPECT_STREQ(a.c_str(), "Mykola");
    EXPECT_STREQ(b.c_str(), "Ivan");
}