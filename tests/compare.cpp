#include <gtest/gtest.h>
#include <mystring.h>

TEST(compare, equal) {
    const char *str1 = "abc";
    const char *str2 = "abc";
    const char *str3 = "ab";
    const char *str4 = "abcd";
    const char *str5 = "acc";
    EXPECT_TRUE(my_str_t{str1} == my_str_t{str2});
    EXPECT_FALSE(my_str_t{str1} == my_str_t{str3});
    EXPECT_FALSE(my_str_t{str1} == my_str_t{str4});
    EXPECT_FALSE(my_str_t{str1} == my_str_t{str5});
    EXPECT_TRUE(my_str_t{str1} == str2);
    EXPECT_FALSE(my_str_t{str1} == str3);
    EXPECT_FALSE(my_str_t{str1} == str4);
    EXPECT_FALSE(my_str_t{str1} == str5);
    EXPECT_TRUE(str2 == my_str_t{str1});
    EXPECT_FALSE(str3 == my_str_t{str1});
    EXPECT_FALSE(str4 == my_str_t{str1});
    EXPECT_FALSE(str5 == my_str_t{str1});
}

TEST(compare, not_equal) {
    const char *str1 = "abc";
    const char *str2 = "abc";
    const char *str3 = "ab";
    const char *str4 = "abcd";
    const char *str5 = "acc";
    EXPECT_FALSE(my_str_t{str1} != my_str_t{str2});
    EXPECT_TRUE(my_str_t{str1} != my_str_t{str3});
    EXPECT_TRUE(my_str_t{str1} != my_str_t{str4});
    EXPECT_TRUE(my_str_t{str1} != my_str_t{str5});
    EXPECT_FALSE(my_str_t{str1} != str2);
    EXPECT_TRUE(my_str_t{str1} != str3);
    EXPECT_TRUE(my_str_t{str1} != str4);
    EXPECT_TRUE(my_str_t{str1} != str5);
    EXPECT_FALSE(str2 != my_str_t{str1});
    EXPECT_TRUE(str3 != my_str_t{str1});
    EXPECT_TRUE(str4 != my_str_t{str1});
    EXPECT_TRUE(str5 != my_str_t{str1});
}

TEST(compare, less_than) {
    const char *str1 = "abc";
    const char *str2 = "abc";
    const char *str3 = "ab";
    const char *str4 = "abcd";
    const char *str5 = "acc";
    EXPECT_FALSE(my_str_t{str1} < my_str_t{str2});
    EXPECT_FALSE(my_str_t{str1} < my_str_t{str3});
    EXPECT_TRUE(my_str_t{str1} < my_str_t{str4});
    EXPECT_FALSE(my_str_t{str1} < my_str_t{str5});
    EXPECT_FALSE(my_str_t{str1} < str2);
    EXPECT_FALSE(my_str_t{str1} < str3);
    EXPECT_TRUE(my_str_t{str1} < str4);
    EXPECT_FALSE(my_str_t{str1} < str5);
    EXPECT_FALSE(str2 < my_str_t{str1});
    EXPECT_TRUE(str3 < my_str_t{str1});
    EXPECT_FALSE(str4 < my_str_t{str1});
    EXPECT_FALSE(str5 < my_str_t{str1});
}

TEST(compare, less_equal) {
    const char *str1 = "abc";
    const char *str2 = "abc";
    const char *str3 = "ab";
    const char *str4 = "abcd";
    const char *str5 = "acc";
    EXPECT_TRUE(my_str_t{str1} <= my_str_t{str2});
    EXPECT_FALSE(my_str_t{str1} <= my_str_t{str3});
    EXPECT_TRUE(my_str_t{str1} <= my_str_t{str4});
    EXPECT_FALSE(my_str_t{str1} <= my_str_t{str5});
    EXPECT_TRUE(my_str_t{str1} <= str2);
    EXPECT_FALSE(my_str_t{str1} <= str3);
    EXPECT_TRUE(my_str_t{str1} <= str4);
    EXPECT_FALSE(my_str_t{str1} <= str5);
    EXPECT_TRUE(str2 <= my_str_t{str1});
    EXPECT_TRUE(str3 <= my_str_t{str1});
    EXPECT_FALSE(str4 <= my_str_t{str1});
    EXPECT_FALSE(str5 <= my_str_t{str1});
}

TEST(compare, great_than) {
    const char *str1 = "abc";
    const char *str2 = "abc";
    const char *str3 = "ab";
    const char *str4 = "abcd";
    const char *str5 = "acc";
    EXPECT_FALSE(my_str_t{str1} > my_str_t{str2});
    EXPECT_TRUE(my_str_t{str1} > my_str_t{str3});
    EXPECT_FALSE(my_str_t{str1} > my_str_t{str4});
    EXPECT_FALSE(my_str_t{str1} > my_str_t{str5});
    EXPECT_FALSE(my_str_t{str1} > str2);
    EXPECT_TRUE(my_str_t{str1} > str3);
    EXPECT_FALSE(my_str_t{str1} > str4);
    EXPECT_FALSE(my_str_t{str1} > str5);
    EXPECT_FALSE(str2 > my_str_t{str1});
    EXPECT_FALSE(str3 > my_str_t{str1});
    EXPECT_TRUE(str4 > my_str_t{str1});
    EXPECT_FALSE(str5 > my_str_t{str1});
}

TEST(compare, great_equal) {
    const char *str1 = "abc";
    const char *str2 = "abc";
    const char *str3 = "ab";
    const char *str4 = "abcd";
    const char *str5 = "acc";
    EXPECT_TRUE(my_str_t{str1} >= my_str_t{str2});
    EXPECT_TRUE(my_str_t{str1} >= my_str_t{str3});
    EXPECT_FALSE(my_str_t{str1} >= my_str_t{str4});
    EXPECT_FALSE(my_str_t{str1} >= my_str_t{str5});
    EXPECT_TRUE(my_str_t{str1} >= str2);
    EXPECT_TRUE(my_str_t{str1} >= str3);
    EXPECT_FALSE(my_str_t{str1} >= str4);
    EXPECT_FALSE(my_str_t{str1} >= str5);
    EXPECT_TRUE(str2 >= my_str_t{str1});
    EXPECT_FALSE(str3 >= my_str_t{str1});
    EXPECT_TRUE(str4 >= my_str_t{str1});
    EXPECT_FALSE(str5 >= my_str_t{str1});
}
