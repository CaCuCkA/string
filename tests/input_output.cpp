#include <gtest/gtest.h>
#include <mystring.h>

TEST(IO, istream) {
    my_str_t test;
    std::stringstream stream{"first \nsecond\t third fourth"};
    stream >> test;
    EXPECT_STREQ(test.c_str(), "first");
    stream >> test;
    EXPECT_STREQ(test.c_str(), "second");
    stream >> test;
    EXPECT_STREQ(test.c_str(), "third");
    stream >> test;
    EXPECT_STREQ(test.c_str(), "fourth");
}

TEST(IO, ostream) {
    my_str_t test{"Hello my name is Nick"};
    std::stringstream out;
    out << test;
    EXPECT_STREQ(out.str().c_str(), "Hello my name is Nick");
}

TEST(IO, readline) {
    my_str_t test;
    std::stringstream stream{"\nstr1 \t str2   str3 \n  "};
    readline(stream, test);
    EXPECT_STREQ(test.c_str(), "str1 \t str2   str3");
    EXPECT_STREQ(test.c_str(), "");
    readline(stream, test);
}