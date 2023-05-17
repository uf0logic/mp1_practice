#ifndef MP1_PRACTICE_MYSTRING_H
#define MP1_PRACTICE_MYSTRING_H

#include <iostream>

using namespace std;

class MyString {
private:
    char *str;  // строка
    int size;   // размер (max)
    int leng;   // длина реальная
public:
    // Конструкторы ---------------------------------
    MyString();                  // По умолчанию
    MyString(int _leng, char fill = ' ');  // Инициализатор
    MyString(const MyString &cms);  // Копирования
    MyString(const char *cstr);      // Преобразования типа
    // Деструктор -----------------------------------
    ~MyString();

    int Size() const { return size; }

    int Leng() const { return leng; }

    MyString &operator=(const MyString &_str);

    MyString &operator=(const char *cstr);

    MyString &operator+=(const MyString &_str);    // операция присваивания
    MyString &operator+=(const char *cstr);    // операция присваивания

    MyString operator+(const MyString &_str);    // объединение строк в стеке с возвратом объекта
    MyString operator+(const char *cstr);    // операция объединения строк
    char &operator[](int index);        // операция индексации
    char operator[](int index) const;    // операция индексации

    bool operator==(const MyString &_str) const;    // операция сравнения
    bool operator!=(const MyString &_str) const;    // операция сравнения
    bool operator>(const MyString &_str) const;    // операция сравнения
    bool operator<(const MyString &_str) const;    // операция сравнения
    bool operator<=(const MyString &_str) const;    // операция сравнения
    bool operator>=(const MyString &_str) const;    // операция сравнения

    void DelSymbol(const char symbol = ' ');// удаление символа в строке
    MyString SubStr(int p, int len) const;        // выделение подстроки
    int Pos(const MyString &_str, int p) const;    // поиск подстроки

    friend ostream &operator<<(ostream &stream, const MyString &_str);

    friend istream &operator>>(istream &stream, MyString &_str);


private:
    int _copy(const char *cstr); // копирование строки
};


#endif //MP1_PRACTICE_MYSTRING_H
