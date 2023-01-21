// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include <stdexcept>
#include <iostream>
#include <cstring>
#include "../include/mystring.h"

size_t my_str_t::get_capacity(size_t size) {
    return (size / 16 + 1) * 16 - 1;
}

my_str_t::my_str_t() : my_str_t{""} {}
my_str_t::my_str_t(size_t size, char initial) :
        size_m{size}, capacity_m{get_capacity(size_m)} {
    data_m = new char[capacity_m];
    for (size_t i = 0; i < size; ++i) {
        data_m[i] = initial;
    }
    data_m[size] = '\0';
}
my_str_t::my_str_t(const char *cstr, size_t size) :
        size_m{size}, capacity_m{get_capacity(size)} {
    if (!cstr) {
        throw std::logic_error("nullptr was given");
    }
    data_m = new char[capacity_m];
    memcpy(data_m, cstr, size_m);
    data_m[size_m] = '\0';

}
my_str_t::my_str_t(const char *cstr) : my_str_t(cstr, str_len(cstr)) {}
my_str_t::my_str_t(const std::string &str) : my_str_t{str.c_str(), str.length()} {}
my_str_t::my_str_t(const my_str_t &mystr) : my_str_t{mystr.c_str(), mystr.size_m} {}
my_str_t::my_str_t(my_str_t &&str) noexcept:
data_m{str.data_m}, size_m{str.size_m}, capacity_m{str.capacity_m} {
str.data_m = nullptr;
str.size_m = 0;
str.capacity_m = 0;
}

my_str_t &my_str_t::operator=(const my_str_t &str) {
    my_str_t temp{str};
    swap(temp);
    return *this;
}

void my_str_t::swap(my_str_t &other) noexcept {
std::swap(other.capacity_m, capacity_m);
std::swap(other.size_m, size_m);
std::swap(other.data_m, data_m);
}

char &my_str_t::operator[](size_t idx) {
    return *(data_m + idx);
}
const char &my_str_t::operator[](size_t idx) const {
    return *(data_m + idx);
}
char &my_str_t::at(size_t idx) {
    if (idx >= size_m) {
        throw std::out_of_range("Your pointer is out of range!");
    }
    return operator[](idx);
}
const char &my_str_t::at(size_t idx) const {
    if (idx >= size_m) {
        throw std::out_of_range("Your pointer is out fo range!");
    }
    return operator[](idx);
}

void my_str_t::reserve(size_t new_capacity) {
    if (new_capacity <= capacity_m) {
        return;
    }
    capacity_m = new_capacity;
    char *buffer = new char[capacity_m];
    memmove(buffer, data_m, size_m);
    buffer[size_m] = '\0';
    delete[] data_m;
    data_m = buffer;
}
void my_str_t::shrink_to_fit() {
    capacity_m = size_m;
    char *buffer = new char[capacity_m];
    memmove(buffer, data_m, size_m);
    buffer[size_m] = '\0';
    delete[] data_m;
    data_m = buffer;
}
void my_str_t::resize(size_t new_size, char new_char) {
    reserve(get_capacity(new_size));
    for (size_t i = size_m; i < new_size; ++i) {
        data_m[i] = new_char;
    }
    data_m[new_size] = '\0';
    size_m = new_size;
}
void my_str_t::clear() {
    size_m = 0;
}

void my_str_t::insert(size_t idx, const my_str_t &str) {
    insert(idx, str.c_str());
}
void my_str_t::insert(size_t idx, char c) {
    if (idx > size_m) {
        throw std::out_of_range("Your pointer is out of range");
    }
    if (idx > size_m) {
        throw std::out_of_range("Your pointer is out of range");
    }
    increase_capacity(size_m + 1);
    memmove(data_m + idx + 1, data_m + idx, size_m - idx + 1);
    data_m[idx] = c;
    size_m++;
    data_m[size_m] = '\0';
}
void my_str_t::insert(size_t idx, const char *cstr) {
    if (!cstr) {
        throw std::logic_error("Nullptr was given");
    }
    if (idx > size_m) {
        throw std::out_of_range("Your pointer is out of range");
    }
    size_t size = str_len(cstr);
    increase_capacity(size_m + size);
    memmove(data_m + idx + size, data_m + idx, size_m - idx + size);
    for (size_t i = idx, sub_index = 0; sub_index < size; ++i, ++sub_index) {
        data_m[i] = cstr[sub_index];
    }
    size_m += size;
    data_m[size_m] = '\0';

}
void my_str_t::insert(size_t idx, std::string &str) {
    insert(idx, str.c_str());
}

void my_str_t::append(const my_str_t &str) {
    append(str.c_str());
}
void my_str_t::append(char c) {
    increase_capacity(size_m + 1);
    data_m[size_m] = c;
    data_m[size_m + 1] = '\0';
    size_m++;
}
void my_str_t::append(const char *cstr) {
    if (!cstr) {
        throw std::logic_error("Nullptr was given");
    }
    size_t size = str_len(cstr);
    increase_capacity(size_m + size);
    for (size_t i = size_m, sub_index = 0; sub_index < size; ++i, ++sub_index) {
        data_m[i] = cstr[sub_index];
    }
    size_m += size;
    data_m[size_m] = '\0';
}
void my_str_t::append(const std::string &str) {
    append(str.c_str());
}

void my_str_t::erase(size_t begin, size_t size) {
    if (begin > size_m) {
        throw std::out_of_range("Your pointer is out of range!");
    }
    if (!begin && begin + size >= size_m) {
        size_m = 0;
        data_m[0] = '\0';
        return;
    } else if (begin + size >= size_m) {
        size_m = begin + 1;
        data_m[size_m] = '\0';
        return;
    }
    for (size_t i = begin, sufix = begin + size; data_m[sufix] != '\0'; ++i, ++sufix) {
        data_m[i] = data_m[sufix];
    }
    size_m -= size;
    data_m[size_m] = '\0';
}

size_t my_str_t::size() const noexcept {
return size_m;
}
size_t my_str_t::capacity() const noexcept {
return capacity_m;
}

size_t my_str_t::find(char c, size_t idx) {
    if (idx >= size_m) {
        throw std::out_of_range("Your pointer is out of range!");
    }

    for (size_t i = 0; i < size_m; ++i) {
        if (data_m[i] == c) {
            return i;
        }
    }
    return my_str_t::not_found;
}
size_t my_str_t::find(const std::string &str, size_t idx) {
    return find(str.c_str(), idx);
}
size_t my_str_t::find(const char *cstr, size_t idx) {
    if (!cstr) {
        throw std::logic_error("Nullptr was give");
    }
    if (idx >= size_m) {
        throw std::out_of_range("Your pointer is out of range!");
    }
    if (str_len(cstr) > size_m) {
        return my_str_t::not_found;
    }
    size_t size = str_len(cstr);
    for (size_t i = idx; i < size_m; ++i) {
        size_t j = 0;
        while (data_m[i] == cstr[j]) {
            ++i, ++j;
            if (j == size) {
                return i - size;
            }
        }
    }
    return my_str_t::not_found;
}
size_t my_str_t::find(const my_str_t &str, size_t idx) {
    return find(str.c_str(), idx);
}

my_str_t my_str_t::substr(size_t begin, size_t size) {
    if (begin > size_m) {
        throw std::out_of_range("Your pointer is out of range!");
    }
    if (begin + size > size_m) {
        return my_str_t{data_m + begin, size_m - begin};
    }
    return my_str_t{data_m + begin, size};

}

my_str_t &my_str_t::operator+=(const my_str_t &str) {
    append(str);
    return *this;
}
my_str_t &my_str_t::operator*=(size_t amount) {
    if(!amount) {
        *this = my_str_t();
        return *this;
    }
    size_t new_size = size_m * amount;
    increase_capacity(get_capacity(new_size));
    my_str_t copy{*this};
    while(amount - 1) {
        append(copy);
        --amount;
    }
    return *this;
}

my_str_t::~my_str_t() {
    delete[] data_m;
}

std::ostream &operator<<(std::ostream &ostream, const my_str_t &str) {
    return ostream << str.c_str();
}
std::istream &operator>>(std::istream &istream, my_str_t &str) {
    str.clear();
    int ch = istream.get();
    while (std::isspace(ch)) {
        ch = istream.get();
    }
    while (!std::isspace(ch) && ch != EOF) {
        str.append((char) ch);
        ch = istream.get();
    }
    return istream;
}

my_str_t operator+(const my_str_t &str1, const my_str_t &str2) {
    my_str_t temp{str1};
    temp += str2;
    return temp;
}
my_str_t operator*(const my_str_t &str, size_t amount) {
    my_str_t temp{str};
    temp *= amount;
    return temp;
}

bool operator==(const my_str_t &lhs, const my_str_t &rhs) {
    return str_cmp(lhs.c_str(), rhs.c_str()) == 0;
}
bool operator!=(const my_str_t &lhs, const my_str_t &rhs) {
    return str_cmp(lhs.c_str(), rhs.c_str()) != 0;
}
bool operator>(const my_str_t &lhs, const my_str_t &rhs) {
    return lhs.size() > rhs.size();
}
bool operator>=(const my_str_t &lhs, const my_str_t &rhs) {
    if (lhs.size() > rhs.size()) {
        return true;
    }
    return str_cmp(lhs.c_str(), rhs.c_str()) == 0;
}
bool operator<(const my_str_t &lhs, const my_str_t &rhs) {
    return lhs.size() < rhs.size();
}
bool operator<=(const my_str_t &lhs, const my_str_t &rhs) {
    if (lhs.size() < rhs.size()) {
        return true;
    }
    return str_cmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator==(const my_str_t &lhs, const char *rhs) {
    return str_cmp(lhs.c_str(), rhs) == 0;
}
bool operator!=(const my_str_t &lhs, const char *rhs) {
    return str_cmp(lhs.c_str(), rhs) != 0;
}
bool operator>(const my_str_t &lhs, const char *rhs) {
    return lhs.size() > str_len(rhs);
}
bool operator>=(const my_str_t &lhs, const char *rhs) {
    if (lhs.size() > str_len(rhs)) {
        return true;
    }
    return str_cmp(lhs.c_str(), rhs) == 0;
}
bool operator<(const my_str_t &lhs, const char *rhs) {
    return lhs.size() < str_len(rhs);
}
bool operator<=(const my_str_t &lhs, const char *rhs) {
    if (lhs.size() < str_len(rhs)) {
        return true;
    }
    return str_cmp(lhs.c_str(), rhs) == 0;
}

bool operator==(const char *rhs, const my_str_t &lhs) {
    return str_cmp(rhs, lhs.c_str()) == 0;
}
bool operator!=(const char *rhs, const my_str_t &lhs) {
    return str_cmp(rhs, lhs.c_str()) != 0;
}
bool operator>(const char *rhs, const my_str_t &lhs) {
    return str_len(rhs) > lhs.size();
}
bool operator>=(const char *rhs, const my_str_t &lhs) {
    if (str_len(rhs) > lhs.size()) {
        return true;
    }
    return str_cmp(rhs, lhs.c_str()) == 0;
}
bool operator<(const char *rhs, const my_str_t &lhs) {
    return str_len(rhs) < lhs.size();
}
bool operator<=(const char *rhs, const my_str_t &lhs) {
    if (str_len(rhs) < lhs.size()) {
        return true;
    }
    return str_cmp(rhs, lhs.c_str()) == 0;
}

std::istream &readline(std::istream &istream, my_str_t &str) {
    str.clear();
    int ch = istream.get();
    while (ch != '\n' && ch != EOF) {
        str.append((char) ch);
        ch = istream.get();
    }
    return istream;
}

void my_str_t::increase_capacity(size_t capacity) {
    if (capacity < capacity_m) {
        return;
    }
    size_t new_capacity = capacity_m + 1;
    while (new_capacity <= capacity) {
        new_capacity *= 2;
    }
    reserve(new_capacity - 1);
}
size_t str_len(const char *c_str) {
    if (!c_str) {
        throw std::logic_error("nullptr given");
    }
    size_t length = 0;
    while (*c_str != '\0') {
        c_str++;
        length++;
    }
    return length;
}
int str_cmp(const char *lhs, const char *rhs) {
    if (!lhs || !rhs) {
        throw std::logic_error("nullptr given");
    }
    while (*lhs == *rhs && *lhs != '\0' && *rhs != '0') {
        lhs++;
        rhs++;
    }
    if (*lhs == *rhs)
        return 0;
    if (*lhs > *rhs || *rhs == '\0')
        return 1;
    if (*lhs < *rhs || *lhs == '\0')
        return -1;
    return 0;
}




