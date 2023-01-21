#include <gtest/gtest.h>
#include <mystring.h>

TEST(substr, test) {
    my_str_t test("Hello my name is Ivan");
    my_str_t sub_test = test.substr(6, 7);
    EXPECT_STREQ(sub_test.c_str(), "my name");
    sub_test = test.substr(6, 15);
    EXPECT_STREQ(sub_test.c_str(), "my name is Ivan");
    sub_test = test.substr(6, 100);
    EXPECT_STREQ(sub_test.c_str(), "my name is Ivan");
    EXPECT_THROW(test.substr(100, 1000), std::out_of_range);
}