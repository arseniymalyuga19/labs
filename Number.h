#pragma once
#include <iostream>
#include <string>

class Number {
private:
    std::string value; // строка, представляющая число
    int base;          // основание системы счисления

public:
    Number(const char* value, int base); // Конструктор
    Number(int value);                   // Конструктор из int
    Number(const std::string& str);      // Конструктор из строки (та же база)
    Number(const Number& other);         // Конструктор копирования
    Number(Number&& other) noexcept;     // Конструктор перемещения
    ~Number();

    Number& operator=(const Number& other); // Оператор присваивания
    Number& operator=(Number&& other) noexcept;
    Number& operator=(int value);           // Присваивание из int
    Number& operator=(const char* str);     // Присваивание из строки

    char operator[](int index) const;       // Оператор индекса
    friend Number operator+(const Number& a, const Number& b);
    friend Number operator-(const Number& a, const Number& b);

    Number& operator+=(const Number& other);

    bool operator>(const Number& other) const;
    bool operator<(const Number& other) const;
    bool operator>=(const Number& other) const;
    bool operator<=(const Number& other) const;
    bool operator==(const Number& other) const;
    bool operator!=(const Number& other) const;

    Number& operator--();    // Префикс: удалить старший разряд
    Number operator--(int);  // Постфикс: удалить младший разряд

    void SwitchBase(int newBase); // Сменить основание
    void Print() const;           // Напечатать число
    int GetDigitsCount() const;   // Кол-во цифр
    int GetBase() const;          // Текущая база
};
