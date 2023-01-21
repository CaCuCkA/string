#ifndef LABSTRING_MYSTRING_H
#define LABSTRING_MYSTRING_H


#include <cstddef>
#include <string>

class my_str_t {
private:
    char *data_m;
    size_t size_m;
    size_t capacity_m;
public:
    my_str_t();
    my_str_t(size_t size, char initial);
    my_str_t(const char *cstr);
    my_str_t(const char *cstr, size_t size);
    my_str_t(const std::string &str);
    my_str_t(const my_str_t &mystr);
    my_str_t(my_str_t &&str) noexcept;

    my_str_t &operator=(const my_str_t &str);

    void swap(my_str_t &other) noexcept;

    char &operator[](size_t idx);
    const char &operator[](size_t idx) const;

    char &at(size_t idx);
    const char &at(size_t idx) const;

    void reserve(size_t new_capacity);
    void shrink_to_fit();
    void resize(size_t new_size, char new_char = ' ');

    void clear();

    void insert(size_t idx, const my_str_t &str);
    void insert(size_t idx, char c);
    void insert(size_t idx, const char *cstr);
    void insert(size_t idx, std::string &str);

    void append(const my_str_t &str);
    void append(char c);
    void append(const char *cstr);
    void append(const std::string &str);

    void erase(size_t begin, size_t size);

    size_t size() const noexcept;
    size_t capacity() const noexcept;
    const char *c_str() const { return data_m; }

    static constexpr size_t not_found = -1;

    size_t find(char c, size_t idx = 0);
    size_t find(const std::string &str, size_t idx = 0);
    size_t find(const char *cstr, size_t idx = 0);
    size_t find(const my_str_t &str, size_t idx = 0);

    my_str_t substr(size_t begin, size_t size);

    my_str_t &operator+=(const my_str_t &str);
    my_str_t &operator*=(size_t amount);

    ~my_str_t();

private:
    static size_t get_capacity(size_t size);

    void increase_capacity(size_t capacity);
};

my_str_t operator+(const my_str_t &str1, const my_str_t &str2);
my_str_t operator*(const my_str_t& str, size_t amount);

std::ostream &operator<<(std::ostream &stream, const my_str_t &str);
std::istream &operator>>(std::istream &stream, my_str_t &str);

bool operator==(const my_str_t &lhs, const my_str_t &rhs);
bool operator!=(const my_str_t &lhs, const my_str_t &rhs);
bool operator>(const my_str_t &lhs, const my_str_t &rhs);
bool operator>=(const my_str_t &lhs, const my_str_t &rhs);
bool operator<(const my_str_t &lhs, const my_str_t &rhs);
bool operator<=(const my_str_t &lhs, const my_str_t &rhs);

bool operator==(const my_str_t &lhs, const char *rhs);
bool operator!=(const my_str_t &lhs, const char *rhs);
bool operator>(const my_str_t &lhs, const char *rhs);
bool operator>=(const my_str_t &lhs, const char *rhs);
bool operator<(const my_str_t &lhs, const char *rhs);
bool operator<=(const my_str_t &lhs, const char *rhs);

bool operator==(const char *lhs, const my_str_t &rhs);
bool operator!=(const char *lhs, const my_str_t &rhs);
bool operator>(const char *lhs, const my_str_t &rhs);
bool operator>=(const char *lhs, const my_str_t &rhs);
bool operator<(const char *lhs, const my_str_t &rhs);
bool operator<=(const char *lhs, const my_str_t &rhs);

std::istream &readline(std::istream &stream, my_str_t &str);

size_t str_len(const char *c_str);

int str_cmp(const char *lhs, const char *rhs);

#endif //LABSTRING_MYSTRING_H
