#include <stdio.h>

int recursive(int *count, char *stringS, char c) {
    char *found = strchr(stringS, c);

    if (found == NULL)
        return 1;
    else
    {
        (*count)++;
        return recursive(count, found + 1, c);
    }
}

int main () {
    char stringS[21];
    char c;
    int count = 0;

    scanf("%s", stringS);
    scanf(" %c", &c);

    recursive(&count, stringS, c);

    printf("String: %s Caractere: %c Casos: %d", stringS, c, count);

    //Manual
    /*
    char stringS[21];
    char c;
    int count = 0;

    scanf("%s", stringS);
    scanf(" %c", &c);

    for (int i = 0; stringS[i] != '\0'; i++) {
        if (stringS[i] == c)
            count++;
    }

    printf("String: %s Caractere: %c Casos: %d", stringS, c, count);

    return 0;
    */

    return 0;
}