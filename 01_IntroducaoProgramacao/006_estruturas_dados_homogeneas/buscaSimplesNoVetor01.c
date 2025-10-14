#include <stdio.h>

void lerVetor(int *v) {
    for (int i = 0; i < 10; i++)
        scanf("%d", v + i);
}

int checarNumero (int *v, int x) {
    for (int i = 0; i < 10; i++)
        if ( *(v + i) == x)
            return 0;
    return 1;
}

int main () {
    int v[10], x;

    lerVetor(v);

    scanf("%d", &x);
    
    if (checarNumero(v, x))
        printf("NAO");
    else
        printf("SIM");
        
    return 0;
}