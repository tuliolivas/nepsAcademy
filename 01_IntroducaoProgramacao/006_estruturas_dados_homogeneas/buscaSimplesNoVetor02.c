#include <stdio.h>

void lerVetor(int *v) {
    for (int i = 0; i < 10; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", v + i);
    }
}

int checarNumeroIndices (int *v, int x) {
    int i;
    int count = 0;
    int v_aux[10];

    for (i = 0; i < 10; i++)
        if ( *(v + i) == x) {
            *(v_aux + count) = i;
            count ++;
            
        }
            
    if (count == 0)
        return 1;
    else {
         printf("%d\n", count);
         for (i = 0; i < count; i++)
            printf("%d ", *(v_aux + i));
    }
    return 0;
}

int main () {
    int v[10], x;

    lerVetor(v);

    printf("Valor de X que sera pesquisado no Vetor: ");
    scanf("%d", &x);
            
    if (checarNumeroIndices(v, x))
        printf("Mia x");

    return 0;
}