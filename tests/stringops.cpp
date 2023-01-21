#include <gtest/gtest.h>
#include <mystring.h>

TEST(Stringops, insert_char) {
    my_str_t a{"012345"};
    a.insert(0, a[5]);
    EXPECT_STREQ(a.c_str(), "5012345");
    a.insert(1, '1');
    EXPECT_STREQ(a.c_str(), "51012345");
    a.insert(5, '5');
    EXPECT_STREQ(a.c_str(), "510125345");
    a.insert(9, '9');
    EXPECT_STREQ(a.c_str(), "5101253459");
    EXPECT_THROW(a.insert(11, 'q'), std::out_of_range);
}

TEST(Stringops, insert_c_str) {
    my_str_t a{"012345"};
    a.insert(0, "5");
    EXPECT_STREQ(a.c_str(), "5012345");
    a.insert(3, "345");
    EXPECT_STREQ(a.c_str(), "5013452345");
    a.insert(10, "Something long");
    EXPECT_STREQ(a.c_str(), "5013452345Something long");
    EXPECT_THROW(a.insert(110, "12"), std::out_of_range);
}

TEST(Stringops, insert_std_str) {
    my_str_t a{"012345"};
    a.insert(0, std::string("5"));
    EXPECT_STREQ(a.c_str(), "5012345");
    a.insert(3, std::string{"345"});
    EXPECT_STREQ(a.c_str(), "5013452345");
    a.insert(10, std::string{"Something long"});
    EXPECT_STREQ(a.c_str(), "5013452345Something long");
    EXPECT_THROW(a.insert(110, std::string{"12"}), std::out_of_range);
}

TEST(Stringops, insert_my_str) {
    my_str_t a{"012345"};
    a.insert(0, my_str_t{"5"});
    EXPECT_STREQ(a.c_str(), "5012345");
    a.insert(3, my_str_t{"345"});
    EXPECT_STREQ(a.c_str(), "5013452345");
    a.insert(10, my_str_t{"Something long"});
    EXPECT_STREQ(a.c_str(), "5013452345Something long");
    EXPECT_THROW(a.insert(110, my_str_t{"12"}), std::out_of_range);
}

TEST(Stringops, append_char) {
    my_str_t a{"012345"};
    a.append('6');
    EXPECT_STREQ(a.c_str(), "0123456");
    a.append(a[6]);
    EXPECT_STREQ(a.c_str(), "01234566");
}

TEST(Stringops, append_c_str) {
    my_str_t a{"012345"};
    a.append("345");
    EXPECT_STREQ(a.c_str(), "012345345");
    a.append("Something long");
    EXPECT_STREQ(a.c_str(), "012345345Something long");
}

TEST(Stringops, append_std_str) {
    my_str_t a{"012345"};
    a.append(std::string{"345"});
    EXPECT_STREQ(a.c_str(), "012345345");
    a.append(std::string{"Something long"});
    EXPECT_STREQ(a.c_str(), "012345345Something long");
}

TEST(Stringops, append_my_str) {
    my_str_t a{"Some_string "};
    a.append(my_str_t{a});
    EXPECT_STREQ(a.c_str(), "Some_string Some_string ");
    a = {"012345"};
    a.append(my_str_t{"345"});
    EXPECT_STREQ(a.c_str(), "012345345");
    a.append(my_str_t{"Something long"});
    EXPECT_STREQ(a.c_str(), "012345345Something long");
}

TEST(Stringops, erase) {
    my_str_t a{"Some_string "};
    a.erase(5, 4);
    EXPECT_STREQ(a.c_str(), "Some_ng ");
    a.erase(7, 10);
    EXPECT_STREQ(a.c_str(), "Some_ng");
    a.erase(7, 10);
    EXPECT_STREQ(a.c_str(), "Some_ng");
    EXPECT_THROW(a.erase(10, 10), std::out_of_range);
}

TEST(Stringops, substr) {
    my_str_t a{"Some_string"};
    my_str_t b = a.substr(5, 4);
    EXPECT_STREQ(b.c_str(), "stri");
    b = a.substr(5, 6);
    EXPECT_STREQ(b.c_str(), "string");
    b = a.substr(5, 7);
    EXPECT_STREQ(b.c_str(), "string");
    b = a.substr(5, 400);
    EXPECT_STREQ(b.c_str(), "string");
    EXPECT_THROW(a.substr(20, 400), std::out_of_range);
}