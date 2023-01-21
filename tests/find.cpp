#include <gtest/gtest.h>
#include <mystring.h>

TEST(find, ch) {
    my_str_t test{"Neque porro quisquam est qui "
                  "dolorem ipsum quia dolor sit amet, consectetur, adipisci velit"};
    size_t index = test.find('q');
    EXPECT_EQ(index, 2);
    index = test.find('j');
    EXPECT_EQ(index, 5);
    index = test.find('w');
    EXPECT_EQ(index, my_str_t::not_found);
}

TEST(find, c_str) {
    my_str_t test{"Neque porro quisquam est qui "
                  "dolorem ipsum quia dolor sit amet, consectetur, adipisci velit"};
    size_t index = test.find("sit");
    EXPECT_EQ(index, 54);
    index = test.find("Hello world");
    EXPECT_EQ(index, 0);
    index = test.find("qui", 30);
    EXPECT_EQ(index, 43);
    index = test.find("qui", 43);
    EXPECT_EQ(index, my_str_t::not_found);
}

TEST(find, str) {
    my_str_t test{"Neque porro quisquam est qui "
                  "dolorem ipsum quia dolor sit amet, consectetur, adipisci velit"};
    size_t index = test.find(std::string("sit"));
    EXPECT_EQ(index, 54);
    index = test.find(std::string("Hello world"));
    EXPECT_EQ(index, 0);
    index = test.find(std::string("qui"), 30);
    EXPECT_EQ(index, 43);
    index = test.find(std::string("qui"), 43);
    EXPECT_EQ(index, my_str_t::not_found);
}

TEST(find, my_str) {
    my_str_t test{"Neque porro quisquam est qui "
                  "dolorem ipsum quia dolor sit amet, consectetur, adipisci velit"};
    size_t index = test.find(my_str_t("sit"));
    EXPECT_EQ(index, 54);
    index = test.find(my_str_t("Hello world"));
    EXPECT_EQ(index, 0);
    index = test.find(my_str_t("qui"), 30);
    EXPECT_EQ(index, 43);
    index = test.find(my_str_t("qui"), 43);
    EXPECT_EQ(index, my_str_t::not_found);
}