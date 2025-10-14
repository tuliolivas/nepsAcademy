#include <stdio.h>

int main(){
    
    float n1, n2, n3;
    
    if (scanf("%f %f", &n1, &n2) != 2) {
        fprintf(stderr, "Error: Invalid input. Please enter two numeric values\n");
        return 1;
    }
    
    if (((n1 < 0.0) || (n2 < 0.0) ) || ((n1 > 10.0) || (n2 > 10.0) ))
    {
         fprintf(stderr, "Error: Values must be between 0.0 and 10.0.\n");
        return 1;
    }

    n3 = (2 * n1 + 3 * n2) / 5.0;

    if (n3 >= 7.0)
        printf("Aprovado");
    else if (n3 < 3.0)
        printf("Reprovado");
    else
        printf("Final");

    return 0;
}