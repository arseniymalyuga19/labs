#pragma once
#include <iostream>
#include <string>

class Number {
private:
    std::string value; // ������, �������������� �����
    int base;          // ��������� ������� ���������

public:
    Number(const char* value, int base); // �����������
    Number(int value);                   // ����������� �� int
    Number(const std::string& str);      // ����������� �� ������ (�� �� ����)
    Number(const Number& other);         // ����������� �����������
    Number(Number&& other) noexcept;     // ����������� �����������
    ~Number();

    Number& operator=(const Number& other); // �������� ������������
    Number& operator=(Number&& other) noexcept;
    Number& operator=(int value);           // ������������ �� int
    Number& operator=(const char* str);     // ������������ �� ������

    char operator[](int index) const;       // �������� �������
    friend Number operator+(const Number& a, const Number& b);
    friend Number operator-(const Number& a, const Number& b);

    Number& operator+=(const Number& other);

    bool operator>(const Number& other) const;
    bool operator<(const Number& other) const;
    bool operator>=(const Number& other) const;
    bool operator<=(const Number& other) const;
    bool operator==(const Number& other) const;
    bool operator!=(const Number& other) const;

    Number& operator--();    // �������: ������� ������� ������
    Number operator--(int);  // ��������: ������� ������� ������

    void SwitchBase(int newBase); // ������� ���������
    void Print() const;           // ���������� �����
    int GetDigitsCount() const;   // ���-�� ����
    int GetBase() const;          // ������� ����
};
