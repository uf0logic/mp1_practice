#include <stdio.h>
#include <stdlib.h>
#include <math.h>



void print_char_array(char *array, int size) {
    printf("\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            printf("%c ", array[i * size + j]);
        printf("\n");
    }
}

void create_int_array(int *array, int size) {
    int i = 0;
    while (i < size*size) {
        scanf("%d ", (array + i));
        i++;}
}

void print_int_array(int *array, int size) {
    printf("\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            printf("%d ", array[i * size + j]);
        printf("\n");
    }
}

int task_1(int size) {
    if (size%2 == 0) {
        printf("\nSize of matrix should be even\n");
        return 1;
    }
    char* array = (char*) malloc(size*sizeof(char));

    for (int i=0; i<=size; i++) {
        for (int j = 0; j < size; j++) {
            array[i * size + j] = '.';
            array[size*size/2 + j-size/2] = '*';
        }
        array[i * size + size / 2] = '*';
        array[i*(size+1)] = '*';
        array[(size-1) * i] = '*';
    }

    print_char_array(array, size);
    return 0;
}

int task_2(int size) {
    int* array = (int*) malloc(size * size * sizeof(int));

    for (int i = 0; i<size; i++) {
        for (int j = 0; j<size; j++) {
            array[i*size + j] = abs(j - i);
            array[j*size + i] = abs(j - i);
        }
    }
    print_int_array(array, size);
    return 0;
}

int task_3(int size) {
    int* array = (int*) malloc(size*size * sizeof(int));

    create_int_array(array, size);

    for (int i = 0; i<size; i++) {
        for (int j = 0; j<size; j++) {
            if (array[i*size + j] != array[j*size + i]){
                printf("NO");
                free(array);
                return 0;
            }

        }
    }
    printf("YES");
    print_int_array(array,size);
    free(array);
    return 0;
}

int main() {
    int x = sin(5);
    int size;
    start:
    printf("Enter the size of Matrix: ");
    scanf("%d", &size);
    
    //if (task_1(size) == 1) goto start;
    //task_2(size);
    //task_3(size);


    return 0;
}