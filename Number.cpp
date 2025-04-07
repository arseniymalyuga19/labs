#include "Number.h"
#include <cmath>
#include <sstream>
#include <algorithm>

// Преобразует символ в значение цифры
int CharToDigit(char c) {
    if (isdigit(c)) return c - '0';
    return toupper(c) - 'A' + 10;
}

// Преобразует цифру в символ
char DigitToChar(int digit) {
    if (digit < 10) return '0' + digit;
    return 'A' + (digit - 10);
}

// Перевод из произвольной системы счисления в 10
int ToDecimal(const std::string& value, int base) {
    int result = 0;
    for (char c : value) {
        result = result * base + CharToDigit(c);
    }
    return result;
}

// Перевод из 10 в произвольную систему счисления
std::string FromDecimal(int number, int base) {
    if (number == 0) return "0";
    std::string result;
    while (number > 0) {
        result = DigitToChar(number % base) + result;
        number /= base;
    }
    return result;
}

Number::Number(const char* val, int base) : value(val), base(base) {}

Number::Number(int val) : base(10) {
    value = FromDecimal(val, base);
}

Number::Number(const std::string& str) : value(str), base(10) {}

Number::Number(const Number& other) : value(other.value), base(other.base) {}

Number::Number(Number&& other) noexcept : value(std::move(other.value)), base(other.base) {}

Number::~Number() {}

Number& Number::operator=(const Number& other) {
    if (this != &other) {
        value = other.value;
        base = other.base;
    }
    return *this;
}

Number& Number::operator=(Number&& other) noexcept {
    if (this != &other) {
        value = std::move(other.value);
        base = other.base;
    }
    return *this;
}

Number& Number::operator=(int val) {
    base = 10;
    value = FromDecimal(val, base);
    return *this;
}

Number& Number::operator=(const char* str) {
    value = str;
    return *this;
}

char Number::operator[](int index) const {
    return value[index];
}

Number operator+(const Number& a, const Number& b) {
    int maxBase = std::max(a.base, b.base);
    int sum = ToDecimal(a.value, a.base) + ToDecimal(b.value, b.base);
    return Number(FromDecimal(sum, maxBase).c_str(), maxBase);
}

Number operator-(const Number& a, const Number& b) {
    int maxBase = std::max(a.base, b.base);
    int diff = ToDecimal(a.value, a.base) - ToDecimal(b.value, b.base);
    return Number(FromDecimal(diff, maxBase).c_str(), maxBase);
}

Number& Number::operator+=(const Number& other) {
    *this = *this + other;
    return *this;
}

bool Number::operator>(const Number& other) const {
    return ToDecimal(value, base) > ToDecimal(other.value, other.base);
}
bool Number::operator<(const Number& other) const {
    return ToDecimal(value, base) < ToDecimal(other.value, other.base);
}
bool Number::operator>=(const Number& other) const {
    return !(*this < other);
}
bool Number::operator<=(const Number& other) const {
    return !(*this > other);
}
bool Number::operator==(const Number& other) const {
    return ToDecimal(value, base) == ToDecimal(other.value, other.base);
}
bool Number::operator!=(const Number& other) const {
    return !(*this == other);
}

Number& Number::operator--() {
    if (!value.empty()) value.erase(0, 1); // Удалить старший разряд
    return *this;
}

Number Number::operator--(int) {
    Number temp = *this;
    if (!value.empty()) value.pop_back(); // Удалить младший разряд
    return temp;
}

void Number::SwitchBase(int newBase) {
    int decimal = ToDecimal(value, base);
    value = FromDecimal(decimal, newBase);
    base = newBase;
}

void Number::Print() const {
    std::cout << value << " (base " << base << ")\n";
}

int Number::GetDigitsCount() const {
    return static_cast<int>(value.size());
}

int Number::GetBase() const {
    return base;
}
