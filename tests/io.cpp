#include <gtest/gtest.h>
#include <mystring.h>

TEST(IO, istream) {
    my_str_t a{"Some string"};
    std::stringstream stream{"\nstring1 \t string2   string3 \n  "};
    stream >> a;
    EXPECT_STREQ(a.c_str(), "string1");
    stream >> a;
    EXPECT_STREQ(a.c_str(), "string2");
    stream >> a;
    EXPECT_STREQ(a.c_str(), "string3");
    stream >> a;
    EXPECT_STREQ(a.c_str(), "");
}

TEST(IO, ostream) {
    my_str_t a{"String to be outputted"};
    std::stringstream out;
    out << a;
    EXPECT_STREQ(out.str().c_str(), "String to be outputted");
}

TEST(IO, readline) {
    my_str_t a{"Some string"};
    std::stringstream stream{"\nstring1 \t string2   string3 \n  "};
    readline(stream, a);
    EXPECT_STREQ(a.c_str(), "");
    readline(stream, a);
    EXPECT_STREQ(a.c_str(), "string1 \t string2   string3 ");
    readline(stream, a);
    EXPECT_STREQ(a.c_str(), "  ");
}