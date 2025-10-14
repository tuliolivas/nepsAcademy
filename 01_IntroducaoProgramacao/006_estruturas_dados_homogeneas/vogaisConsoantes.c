#include <stdio.h>

int main () {
    char string[51],vogais[51],consoantes[51];
    int len = 0;
    int v = 0;
    int c = 0;

    scanf("%s", string);

    while (*(string + len) != '\0')    
    {
        if (*(string + len) == 'a' || *(string + len) == 'e' || *(string + len) == 'i' || *(string + len) == 'o' || *(string + len) == 'u') {
            vogais[v] = *(string + len);
            v ++;
        }
        else {
            consoantes[c] = *(string + len);
            c ++;
        }

        len ++;
    }

    vogais[v] = '\0';
    consoantes[c] = '\0';
    
    printf("Vogais: %s\n", vogais);
    printf("Consoantes: %s\n", consoantes);
}