#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

int main() {
    char abc[27] = "abcdefghijklmnopqrstuvwxyz";
    int nums[26] = {0};
    char* buffer = (char*) malloc(sizeof(char));
    FILE* input = fopen("/Users/uf0logic/Documents/Coding/C:C++/UNN/mp1_practice/task_file.txt", "r");
    FILE* output = fopen("/Users/uf0logic/Documents/Coding/C:C++/UNN/mp1_practice/output.txt", "w");
    if (input == NULL || output == NULL) perror("Ошибка открытия файла");
    else {
        while (fgets(buffer, 32, input) != NULL) {
            //puts(buffer);
            //for (int i = 0; i < 32; i++) printf("%c", buffer[i]);
            //printf("%d\n", strlen(""));
            if (strlen(buffer) - 2 > 3) {
                for (int i = 0; i < 26; i++) {
                    if (buffer[0]==abc[i]) {
                        nums[i]++; break;
                    }
                }
            }
        }
    }

    for (int i=0; i<26; i++) {
        sprintf(buffer, "%c = %i\n", abc[i], nums[i]);
        fputs(buffer,output);
    }

    fclose(input);
    fclose(output);

    return 0;
}