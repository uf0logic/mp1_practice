#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

void insertion_sort(int array[], int size) {
    int index, newElement;

    for (int i = 1; i < size; ++i) {
        newElement = array[i];
        index = i - 1;
        while (index >= 0 && array[index] > newElement) {
            array[index + 1] = array[index];
            index--;
        }
        array[index + 1] = newElement;
    }
}

void task_1(char *str) {
    char word1[] = "ПК"; // Слово, которое заменяется
    char word2[] = "компьютер"; // Слово, которым заменяют
    char str2[128];
    char *s = str; char *s2 = str2;

    const size_t w1len = strlen(word1), w2len = strlen(word2);

    for(; *s2 = *s; ++s, ++s2)
    {
        if(!strncmp(s, word1, w1len))
        {
            strcpy(s2, word2);
            s += w1len - 1;
            s2 += w2len - 1;
        }
    }
    puts(str2);
    getchar();
    getchar ();
}

void task_2(char *str) {
    char* str2 = (char*) malloc(sizeof(char));
    int k;

    for (int i = 0; str[i] != '\0'; i++) {
        k = i;
        if (str[i] == '.' && str[i+1] != ' ') {
            strcat(str2, ". ");
        } else strncat(str2, str + k, 1);
    }
    puts(str2);
}

void task_3(char *str) {
    char* str2 = (char*) malloc(sizeof(char));
    int k;

    for (int i = 0; str[i] != '\0'; i++) {
        k = i;
        switch (str[i]) {
            case '+':
                strcat(str2, "addition");
                break;
            case '-':
                strcat(str2, "subtraction");
                break;
            case '/':
                strcat(str2, "division");
                break;
            case '*':
                strcat(str2, "multiplication");
                break;
            default:
                strncat(str2, str + k, 1);
                break;
        }
    }
    puts(str2);
}

int task_4(char *str) {
    int *nums = (int*) malloc(sizeof (int));
    int k = 0;

    for (int i = 0; i < strlen(str); i++) {
        // Debug Time!!!
        // printf("%c - %d\n", str[i], (int)str[i]);
        if (48<=(int)str[i] && (int)str[i]<=57){
            nums[k] = str[i] - '0';
            k++;
        }
    }

    for (int i=0; i<k; i++) printf("%d", nums[i]);

    printf("\n\n");

    insertion_sort(nums,k);

    for (int i=0; i<k; i++) printf("%d", nums[i]);

    free(nums);
    return 0;
}

int main() {
    setlocale(LC_ALL, "ru_RU.utf8");
    char str[128];
    gets (str);

    //task_1(str);
    //task_2(str);
    //task_3(str);
    //task_4(str);

    //puts(str);
}