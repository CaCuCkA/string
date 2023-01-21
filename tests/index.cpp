#include <gtest/gtest.h>
#include <mystring.h>

TEST(index, scopes) {
    my_str_t test = {"abcdefgh"};
    for (int i = 0; i < test.size(); ++i) {
        EXPECT_EQ(test[i], 'a' + i);
        test[i] = (char) ('A' + i);
        EXPECT_EQ(test[i], 'A' + i);
    }
}

TEST(index, const_scopes) {
    const my_str_t test = {"abcdefgh"};
    for (int i = 0; i < test.size(); ++i) {
        EXPECT_EQ(test[i], 'a' + i);
    }
}

TEST(index, at) {
    my_str_t test{"abcdefgh"};
    for (int i = 0; i < test.size(); ++i) {
        EXPECT_EQ(test.at(i), 'a' + i);
        test.at(i) = (char) ('A' + i);
        EXPECT_EQ(test.at(i), 'A' + i);
    }
    EXPECT_THROW(test.at(10), std::out_of_range);
}

TEST(index, const_at) {
    const my_str_t test{"abcdefgh"};
    for (int i = 0; i < test.size(); ++i) {
        EXPECT_EQ(test.at(i), 'a' + i);
    }
    EXPECT_THROW(test.at(10), std::out_of_range);
}