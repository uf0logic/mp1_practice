#include <iostream>
#include "MyString.h"

using namespace std;

int main() {
    // Конструктор По-умолчанию
    MyString str1;
    cout << "str1: " << str1 << endl;

    // Конструктор Инициализатор
    MyString str2(10, 'X');
    cout << "str2: " << str2 << endl;

    // Конструктор Копирования
    MyString str3 = str2;
    cout << "str3: " << str3 << endl;

    // Оператор Присваивания
    str1 = "Hello";
    cout << "str1: " << str1 << endl;

    // Оператор Присоединения
    str1 += str2;
    cout << "str1: " << str1 << endl;

    // Операторы сравнения
    cout << "str1 == str2: " << (str1 == str2) << endl;
    cout << "str1 != str2: " << (str1 != str2) << endl;
    cout << "str1 > str2: " << (str1 > str2) << endl;
    cout << "str1 < str2: " << (str1 < str2) << endl;
    cout << "str1 >= str2: " << (str1 >= str2) << endl;
    cout << "str1 <= str2: " << (str1 <= str2) << endl;

    // Оператор Индексации
    cout << "str1[1]: " << str1[1] << endl;

    // Выделение подстроки
    MyString str4 = str1.SubStr(2, 5);
    cout << "str4: " << str4 << endl;

    // Расположение подстроки
    int pos = str1.Pos(str2, 0);
    cout << "pos: " << pos << endl;

    // Удаление символа
    str1.DelSymbol('l');
    cout << "str1 after deletion: " << str1 << endl;

    return 0;
}
