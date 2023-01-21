#include <gtest/gtest.h>
#include <mystring.h>


TEST(Indexes, op) {
    my_str_t a{"0123456789"};
    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ(a[i], '0' + i);
        a[i] = (char) ('a' + i);
        EXPECT_EQ(a[i], 'a' + i);
    }
}

TEST(Imdexes, const_op) {
    const my_str_t a{"0123456789"};
    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ(a[i], '0' + i);
    }
}

TEST(Indexes, at) {
    my_str_t a{"0123456789"};
    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ(a.at(i), '0' + i);
        a.at(i) = (char) ('a' + i);
        EXPECT_EQ(a.at(i), 'a' + i);
    }
    EXPECT_THROW(a.at(10), std::out_of_range);
    EXPECT_THROW(a.at(11), std::out_of_range);
    EXPECT_THROW(a.at(22), std::out_of_range);
}

TEST(Indexes, const_at) {
    const my_str_t a{"0123456789"};
    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ(a.at(i), '0' + i);
    }
    EXPECT_THROW(a.at(10), std::out_of_range);
    EXPECT_THROW(a.at(11), std::out_of_range);
    EXPECT_THROW(a.at(22), std::out_of_range);
}