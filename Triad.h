//
// Created by Arsenii Goriachev on 06.05.2023.
//

#ifndef MP1_PRACTICE_TRIAD_H
#define MP1_PRACTICE_TRIAD_H

#include <iostream>

class Triad {
public:
    Triad(int a, int b, int c) : a(a), b(b), c(c) {}
    void incrementA();
    void incrementB();
    void incrementC();
    friend inline std::ostream& operator<<(std::ostream& os, const Triad& t) {     //Как лучше делать overload?
        os << "(" << t.a << ", " << t.b << ", " << t.c << ")";                     //Inline? Или в Исходнике?
        return os;
    }
private:
    int a, b, c;
};

class Time : public Triad {
public:
    Time(int hour, int minute, int second) : Triad(hour, minute, second), hour(hour), minute(minute), second(second) {}
    void incrementHour() { hour++; }
    void incrementMinute() { minute++; }
    void incrementSecond() { second++; }

    void incrementSeconds(int n);
    void incrementMinutes(int n);
    void incrementHours(int n);

    int getHour() const { return hour; }
    int getMinute() const { return minute; }
    int getSecond() const { return second; }

    friend inline std::ostream& operator<<(std::ostream& os, const Time& t) {
        os << t.hour << ":" << t.minute << ":" << t.second;
        return os;
    }
private:
    int hour, minute, second;
};

#endif //MP1_PRACTICE_TRIAD_H


