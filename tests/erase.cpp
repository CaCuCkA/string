#include <gtest/gtest.h>
#include <mystring.h>

TEST(erase, test) {
    my_str_t test{"Hello my name is, Ivan"};
    test.erase(5, 11);
    size_t size = str_len(test.c_str());
    EXPECT_STREQ(test.c_str(), "Hello, Ivan");
    EXPECT_EQ(test.size(), size);
    EXPECT_EQ(test.capacity(), 31);

    test = "Hello my name is, Ivan";
    test.erase(4, 20);
    size = str_len(test.c_str());
    EXPECT_STREQ(test.c_str(), "Hello");
    EXPECT_EQ(test.size(), size);
    EXPECT_EQ(test.capacity(), 31);

    test = "Hello my name is, Ivan";
    size = str_len(test.c_str());
    EXPECT_THROW(test.erase(size + 1, 10), std::out_of_range);
}
