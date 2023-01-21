#include <gtest/gtest.h>
#include <mystring.h>

TEST(insert, chars) {
    my_str_t test{"My nme is Ivan"};
    test.insert(4, 'a');
    size_t size = str_len(test.c_str());
    EXPECT_STREQ(test.c_str(), "My name is Ivan");
    EXPECT_EQ(test.size(), size);
    EXPECT_EQ(test.capacity(), 15);

    test = "I am 1 years old";
    test.insert(6, '8');
    size = str_len(test.c_str());
    EXPECT_STREQ(test.c_str(), "I am 18 years old");
    EXPECT_EQ(test.size(), size);
    EXPECT_EQ(test.capacity(), 31);

    test = "How are you?";
    EXPECT_THROW(test.insert(20, 'a'), std::out_of_range);
}

TEST(insert, c_str) {
    my_str_t test{"Hello my  is Ivan"};
    test.insert(9, "name");
    size_t size = str_len(test.c_str());
    EXPECT_STREQ(test.c_str(), "Hello my name is Ivan");
    EXPECT_EQ(test.size(), size);
    EXPECT_EQ(test.capacity(), 31);

    test = " years old";
    test.insert(0, "I am 18");
    size = str_len(test.c_str());
    EXPECT_STREQ(test.c_str(), "I am 18 years old");
    EXPECT_EQ(test.size(), size);
    EXPECT_EQ(test.capacity(), 31);

    test = "How are you?";
    EXPECT_THROW(test.insert(20, "Nick"), std::out_of_range);
}

TEST(insert, str) {
    my_str_t test{"Hello my  is Ivan"};
    test.insert(9, std::string("name"));
    size_t size = str_len(test.c_str());
    EXPECT_STREQ(test.c_str(), "Hello my name is Ivan");
    EXPECT_EQ(test.size(), size);
    EXPECT_EQ(test.capacity(), 31);

    test = " years old";
    test.insert(0, std::string("I am 18"));
    size = str_len(test.c_str());
    EXPECT_STREQ(test.c_str(), "I am 18 years old");
    EXPECT_EQ(test.size(), size);
    EXPECT_EQ(test.capacity(), 31);

    test = "How are you?";
    EXPECT_THROW(test.insert(20, std::string("Nick")), std::out_of_range);
}

TEST(insert, my_str) {
    my_str_t test{"Hello my  is Ivan"};
    test.insert(9, my_str_t("name"));
    size_t size = str_len(test.c_str());
    EXPECT_STREQ(test.c_str(), "Hello my name is Ivan");
    EXPECT_EQ(test.size(), size);
    EXPECT_EQ(test.capacity(), 31);

    test = " years old";
    test.insert(0, my_str_t("I am 18"));
    size = str_len(test.c_str());
    EXPECT_STREQ(test.c_str(), "I am 18 years old");
    EXPECT_EQ(test.size(), size);
    EXPECT_EQ(test.capacity(), 31);

    test = "How are you?";
    EXPECT_THROW(test.insert(20, my_str_t("Nick")), std::out_of_range);
}