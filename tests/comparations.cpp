#include <gtest/gtest.h>
#include <mystring.h>

TEST(Comparations, eq) {
    const char *str1 = "abc";
    const char *str2 = "abcd";
    const char *str3 = "abb";
    const char *str4 = "abc";
    const char *str5 = "ab";
    EXPECT_FALSE(my_str_t{str1} == my_str_t{str2});
    EXPECT_FALSE(my_str_t{str1} == my_str_t{str3});
    EXPECT_TRUE(my_str_t{str1} == my_str_t{str4});
    EXPECT_FALSE(my_str_t{str1} == my_str_t{str5});
    EXPECT_FALSE(my_str_t{str1} == str2);
    EXPECT_FALSE(my_str_t{str1} == str3);
    EXPECT_TRUE(my_str_t{str1} == str4);
    EXPECT_FALSE(my_str_t{str1} == str5);
    EXPECT_FALSE(str1 == my_str_t{str2});
    EXPECT_FALSE(str1 == my_str_t{str3});
    EXPECT_TRUE(str1 == my_str_t{str4});
    EXPECT_FALSE(str1 == my_str_t{str5});
}

TEST(Comparations, ne) {
    const char *str1 = "abc";
    const char *str2 = "abcd";
    const char *str3 = "abb";
    const char *str4 = "abc";
    const char *str5 = "ab";
    EXPECT_TRUE(my_str_t{str1} != my_str_t{str2});
    EXPECT_TRUE(my_str_t{str1} != my_str_t{str3});
    EXPECT_FALSE(my_str_t{str1} != my_str_t{str4});
    EXPECT_TRUE(my_str_t{str1} != my_str_t{str5});
    EXPECT_TRUE(my_str_t{str1} != str2);
    EXPECT_TRUE(my_str_t{str1} != str3);
    EXPECT_FALSE(my_str_t{str1} != str4);
    EXPECT_TRUE(my_str_t{str1} != str5);
    EXPECT_TRUE(str1 != my_str_t{str2});
    EXPECT_TRUE(str1 != my_str_t{str3});
    EXPECT_FALSE(str1 != my_str_t{str4});
    EXPECT_TRUE(str1 != my_str_t{str5});
}

TEST(Comparations, lt) {
    const char *str1 = "abc";
    const char *str2 = "abcd";
    const char *str3 = "abb";
    const char *str4 = "abc";
    const char *str5 = "ab";
    EXPECT_TRUE(my_str_t{str1} < my_str_t{str2});
    EXPECT_FALSE(my_str_t{str1} < my_str_t{str3});
    EXPECT_FALSE(my_str_t{str1} < my_str_t{str4});
    EXPECT_FALSE(my_str_t{str1} < my_str_t{str5});
    EXPECT_TRUE(my_str_t{str1} < str2);
    EXPECT_FALSE(my_str_t{str1} < str3);
    EXPECT_FALSE(my_str_t{str1} < str4);
    EXPECT_FALSE(my_str_t{str1} < str5);
    EXPECT_TRUE(str1 < my_str_t{str2});
    EXPECT_FALSE(str1 < my_str_t{str3});
    EXPECT_FALSE(str1 < my_str_t{str4});
    EXPECT_FALSE(str1 < my_str_t{str5});
}

TEST(Comparations, le) {
    const char *str1 = "abc";
    const char *str2 = "abcd";
    const char *str3 = "abb";
    const char *str4 = "abc";
    const char *str5 = "ab";
    EXPECT_TRUE(my_str_t{str1} <= my_str_t{str2});
    EXPECT_FALSE(my_str_t{str1} <= my_str_t{str3});
    EXPECT_TRUE(my_str_t{str1} <= my_str_t{str4});
    EXPECT_FALSE(my_str_t{str1} <= my_str_t{str5});
    EXPECT_TRUE(my_str_t{str1} <= str2);
    EXPECT_FALSE(my_str_t{str1} <= str3);
    EXPECT_TRUE(my_str_t{str1} <= str4);
    EXPECT_FALSE(my_str_t{str1} <= str5);
    EXPECT_TRUE(str1 <= my_str_t{str2});
    EXPECT_FALSE(str1 <= my_str_t{str3});
    EXPECT_TRUE(str1 <= my_str_t{str4});
    EXPECT_FALSE(str1 <= my_str_t{str5});
}

TEST(Comparations, gt) {
    const char *str1 = "abc";
    const char *str2 = "abcd";
    const char *str3 = "abb";
    const char *str4 = "abc";
    const char *str5 = "ab";
    EXPECT_FALSE(my_str_t{str1} > my_str_t{str2});
    EXPECT_TRUE(my_str_t{str1} > my_str_t{str3});
    EXPECT_FALSE(my_str_t{str1} > my_str_t{str4});
    EXPECT_TRUE(my_str_t{str1} > my_str_t{str5});
    EXPECT_FALSE(my_str_t{str1} > str2);
    EXPECT_TRUE(my_str_t{str1} > str3);
    EXPECT_FALSE(my_str_t{str1} > str4);
    EXPECT_TRUE(my_str_t{str1} > str5);
    EXPECT_FALSE(str1 > my_str_t{str2});
    EXPECT_TRUE(str1 > my_str_t{str3});
    EXPECT_FALSE(str1 > my_str_t{str4});
    EXPECT_TRUE(str1 > my_str_t{str5});
}

TEST(Comparations, ge) {
    const char *str1 = "abc";
    const char *str2 = "abcd";
    const char *str3 = "abb";
    const char *str4 = "abc";
    const char *str5 = "ab";
    EXPECT_FALSE(my_str_t{str1} >= my_str_t{str2});
    EXPECT_TRUE(my_str_t{str1} >= my_str_t{str3});
    EXPECT_TRUE(my_str_t{str1} >= my_str_t{str4});
    EXPECT_TRUE(my_str_t{str1} >= my_str_t{str5});
    EXPECT_FALSE(my_str_t{str1} >= str2);
    EXPECT_TRUE(my_str_t{str1} >= str3);
    EXPECT_TRUE(my_str_t{str1} >= str4);
    EXPECT_TRUE(my_str_t{str1} >= str5);
    EXPECT_FALSE(str1 >= my_str_t{str2});
    EXPECT_TRUE(str1 >= my_str_t{str3});
    EXPECT_TRUE(str1 >= my_str_t{str4});
    EXPECT_TRUE(str1 >= my_str_t{str5});
}