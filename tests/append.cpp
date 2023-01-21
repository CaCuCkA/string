#include <gtest/gtest.h>
#include <mystring.h>

TEST(append, chars) {
    my_str_t test{"Hello worl"};
    test.append('d');
    EXPECT_STREQ(test.c_str(), "Hello world");
    test.append('!');
    EXPECT_STREQ(test.c_str(), "Hello world!");
}

TEST(append, c_str) {
    my_str_t test{"My name is "};
    test.append("Ivan.");
    EXPECT_STREQ(test.c_str(), "My name is Ivan.");
    test.append(" How are you?");
    EXPECT_STREQ(test.c_str(), "My name is Ivan. I am 18 years old");
}

TEST(append, str) {
    my_str_t test{"My name is "};
    test.append(std::string("Ivan."));
    EXPECT_STREQ(test.c_str(), "My name is Ivan.");
    test.append(std::string(""));
    EXPECT_STREQ(test.c_str(), "My name is Ivan.");
}

TEST(append, my_str) {
    my_str_t test{"My name is "};
    test.append(my_str_t("Ivan."));
    EXPECT_STREQ(test.c_str(), "My name is Ivan.");
    test.append(my_str_t(" Nick"));
    EXPECT_STREQ(test.c_str(), "My name is Ivan. Nick");
}