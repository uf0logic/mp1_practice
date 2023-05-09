//
// Created by Arsenii Goriachev on 06.05.2023.
//

#include "Triad.h"

void Triad::incrementA() {
    a++;
}

void Triad::incrementB() {
    b++;
}

void Triad::incrementC() {
    c++;
}

void Time::incrementSeconds(int n) {
    second += n;
    if (second >= 60) {
        minute += second / 60;
        second %= 60;
    }
    if (minute >= 60) {
        hour += minute / 60;
        minute %= 60;
    }
    if (hour >= 24) {
        hour %= 24;
    }
}

void Time::incrementMinutes(int n) {
    minute += n;
    if (minute >= 60) {
        hour += minute / 60;
        minute %= 60;
    }
    if (hour >= 24) {
        hour %= 24;
    }
}

void Time::incrementHours(int n) {
    hour += n;
    if (hour >= 24) {
        hour %= 24;
    }
}
