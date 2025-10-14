#include <stdio.h>

void lerVetor(int *v) {
    for (int i = 0; i < 10; i++)
        scanf("%d", v + i);
}

void inverso (int *v, int *iv) {
    for (int i = 10; i > 0 ; i--) {
        *(iv + i - 10) = *(v + i - 1);
        printf("%d\n", *(iv + i - 10));
    }
}

int main () {
    int v[10], iv[10];

    lerVetor(v);

    inverso(v, iv);
        
    return 0;
}