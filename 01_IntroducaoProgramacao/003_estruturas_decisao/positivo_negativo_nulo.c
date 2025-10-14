#include <stdio.h>

int main(){
    // Lendo a entrada do exercício
	int X;
	scanf("%d",&X);

    // Seu código vai aqui
    
    if (X > 0)
    {
        printf("POSITIVO\n");
    }
    
    else if (X == 0)
    {
            printf("NULO\n");
    }
    
    else
    {
        printf("NEGATIVO\n");
    }

    return 0;
}