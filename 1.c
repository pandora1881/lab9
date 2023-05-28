#include <stdio.h>
#include <string.h>
#include <ctype.h>

void замінитиВерхнійРегістр(char *str)
{
    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        if (isupper(str[i]))
        {
            str[i] = tolower(str[i]);
        }
    }
}

void друкуватиНайдовшеСлово(char *str)
{
    char найдовшеСлово[100];
    char слово[100];
    int maxLen = 0;
    int len = strlen(str);
    int i = 0;

    while (i < len)
    {
        int j = 0;
        while (i < len && !isspace(str[i]))
        {
            слово[j] = str[i];
            i++;
            j++;
        }
        слово[j] = '\0';

        if (j > maxLen)
        {
            maxLen = j;
            strcpy(найдовшеСлово, слово);
        }

        while (i < len && isspace(str[i]))
        {
            i++;
        }
    }

    printf("Найдовше слово: %s\n", найдовшеСлово);
}

int main()
{
    char ввід[100];

    printf("Введіть рядок: ");
    fgets(ввід, sizeof(ввід), stdin);

    // Видалення крапки перенесення рядка в кінці
    ввід[strcspn(ввід, "\n")] = '\0';

    // Заміна великих літер на малі
    замінитиВерхнійРегістр(ввід);

    // Друкувати найдовше слово
    друкуватиНайдовшеСлово(ввід);

    return 0;
}
