#include "MyString.h"
#include <string>

// Конструктор По-умолчанию
MyString::MyString() {
    size = 10;
    leng = 0;
    str = new char[size];
    str[0] = '\0';
}

// Конструктор Инициализатор
MyString::MyString(int _leng, char fill) {
    size = _leng + 1;
    leng = _leng;
    str = new char[size];
    for (int i = 0; i < leng; i++)
        str[i] = fill;
    str[leng] = '\0';
}

// Конструктор Копирования
MyString::MyString(const MyString &cms) {
    size = cms.size;
    leng = cms.leng;
    str = new char[size];
    for (int i = 0; i < leng; i++)
        str[i] = cms.str[i];
}

// Конструктор преобразования типа
MyString::MyString(const char *cstr) {
    strcpy(str, cstr);
    leng = strlen(cstr);
    size = leng + 1;

}

// Деструктор
MyString::~MyString() {
    delete[] str;
}


MyString &MyString::operator=(const MyString &_str) {
    if (this != &_str) {
        delete[] str;
        size = _str.size;
        leng = _str.leng;
        str = new char[size];
        strcpy(str, _str.str);
    }
    return *this;
}

MyString &MyString::operator=(const char *cstr) {
    delete[] str; // free up existing memory
    leng = strlen(cstr);
    size = leng + 1;
    str = new char[size];
    strcpy(str, cstr);
    return *this;
}

MyString &MyString::operator+=(const MyString &_str) {
    int newLeng = leng + _str.leng;
    if (newLeng >= size) {
        char *newStr = new char[newLeng + 1];
        strcpy(newStr, str);
        strcat(newStr, _str.str);
        delete[] str;
        str = newStr;
        size = newLeng + 1;
        leng = newLeng;
    } else {
        strcat(str, _str.str);
        leng = newLeng;
    }
    return *this;
}


MyString &MyString::operator+=(const char *cstr) {
    int newLength = leng + strlen(cstr);
    char *newStr = new char[newLength + 1];
    strcpy(newStr, str);
    strcat(newStr, cstr);
    delete[] str;
    str = newStr;
    leng = newLength;
    size = newLength + 1;
    return *this;
}

MyString MyString::operator+(const MyString &_str) {
    MyString result(leng + _str.leng, ' ');
    strcpy(result.str, str);
    strcat(result.str, _str.str);
    return result;
}

MyString MyString::operator+(const char *cstr) {
    MyString result(leng + strlen(cstr), ' ');
    strcpy(result.str, str);
    strcat(result.str, cstr);
    return result;
}

char &MyString::operator[](int index) {
    if (index < 0 || index >= leng)
        throw std::out_of_range("Index out of range");
    return str[index];
}

char MyString::operator[](int index) const {
    if (index < 0 || index >= leng)
        throw std::out_of_range("Index out of range");
    return str[index];
}

bool MyString::operator==(const MyString &_str) const {
    return strcmp(str, _str.str) == 0;
}

bool MyString::operator!=(const MyString &_str) const {
    return strcmp(str, _str.str) != 0;
}

bool MyString::operator>(const MyString &_str) const {
    return strcmp(str, _str.str) < 0;
}

bool MyString::operator<(const MyString &_str) const {
    return strcmp(str, _str.str) > 0;
}

bool MyString::operator<=(const MyString &_str) const {
    return strcmp(str, _str.str) >= 0;
}

bool MyString::operator>=(const MyString &_str) const {
    return strcmp(str, _str.str) <= 0;
}

int MyString::_copy(const char *cstr) {
    int len = strlen(cstr);
    if (len >= size) {
        delete[] str;
        size = len + 1;
        str = new char[size];
    }
    strcpy(str, cstr);
    leng = len;
    return leng;
}

// output stream operator
ostream &operator<<(ostream &stream, const MyString &_str) {
    stream << _str.str;
    return stream;
}

// input stream operator
istream &operator>>(istream &stream, MyString &_str) {
    char buffer[1024];
    stream.getline(buffer, 1024);
    _str = buffer;
    return stream;
}

void MyString::DelSymbol(const char symbol) {
    int j = 0;
    for (int i = 0; i < leng; i++) {
        if (str[i] != symbol) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
    leng = j;
}

MyString MyString::SubStr(int p, int len) const {
    if (p < 0 || p >= leng || len <= 0 || p + len > leng) {
        return MyString(0, '\0');
    }
    MyString result(len, ' ');
    strncpy(result.str, &str[p], len);
    result.leng = len;
    return result;
}

int MyString::Pos(const MyString &_str, int p) const {
    if (p < 0 || p >= leng) {
        return -1;
    }
    char *ptr = strstr(&str[p], _str.str);
    if (ptr == nullptr) {
        return -1;
    }
    return ptr - str;
}




 