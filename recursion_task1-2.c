#include <stdio.h>
#include <stdlib.h>

unsigned int factorial(unsigned int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

unsigned int binom(unsigned int n, unsigned k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

unsigned int *task_1(unsigned int size) {
    unsigned int *row = (unsigned int *) malloc(size * sizeof(int));
    printf("[ ");
    for (int i = 0; i <= size; i++) {
        row[i] = binom(size, i);   //В задаче просили вернуть строку. Технически - вывод можно сделать потом, но
        printf("%x ", row[i]);           //я решил сразу выводить тут (эти два пункта можно объединить)
    }
    printf("]\n");
    return 0;
}

int task_2(int start, unsigned int end, int count) {
    if (start > end) return 0;
    if (start == end) return 1;
    count++;

    return task_2(start + 1, end, count) + task_2(start + 2, end, count);
}

int main() {
    unsigned int n, k = 0;
    printf("Input: ");
    scanf("%d", &n);

    //task_1(n);
    //printf("%d", task_2(0, n, k));

    return 0;
}