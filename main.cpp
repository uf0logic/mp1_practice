/*Задача Triad/Time_1
Создать класс Triad (тройка чисел);
определить методы увеличения полей на 1.
Определить класс-наследник Time с полями: час, минута, секунда.
Переопределить методы увеличения полей на 1 и определить методы увеличения на n секунд m минут.
*/

#include "Triad.h"
#include <iostream>

int main() {
    Triad t(0,0,0);

    t.incrementA();
    std::cout << t << std::endl;

    Time clock(0, 0, 0);
    clock.incrementSeconds(90);
    clock.incrementMinutes(70);
    std::cout << clock << std::endl;

    return 0;
}