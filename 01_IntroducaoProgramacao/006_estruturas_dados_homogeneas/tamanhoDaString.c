#include <stdio.h>

int main () {
    char stringS[127];
    scanf("%s", stringS);
    printf("String:%s Tamanho:%d", stringS, strlen(stringS));
    return 0;

    //Manual
    /*
    char stringS[127];
    int len = 0;
    scanf("%s", stringS);
    while (1)
    {
        if (*(stringS + len) == '\0')
            break;
        else
            len ++;
    }
    printf("String:%s Tamanho:%d", stringS, len);
    return 0;
    */
}