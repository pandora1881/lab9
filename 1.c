#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

void replaceUpperCase(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;  // переводимо велику літеру у відповідну малу
        }
        i++;
    }
}

void printLongestWord(char *str) {
    char longestWord[MAX_LENGTH] = "";
    char currentWord[MAX_LENGTH] = "";
    int i = 0, j = 0;

    while (str[i] != '\0') {
        if (str[i] != ' ') {
            currentWord[j] = str[i];
            j++;
        } else {
            currentWord[j] = '\0';
            if (strlen(currentWord) > strlen(longestWord)) {
                strcpy(longestWord, currentWord);
            }
            j = 0;
        }
        i++;
    }

    printf("Найдовше слово: %s\n", longestWord);
}

int main() {
    char input[MAX_LENGTH];

    printf("Введіть текстовий рядок: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';  // видаляємо символ нового рядка з кінця рядка

    replaceUpperCase(input);
    printf("Текстовий рядок після заміни великих літер: %s\n", input);

    printLongestWord(input);

    return 0;
}
