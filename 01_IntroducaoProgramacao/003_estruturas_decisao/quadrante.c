#include <stdio.h>

int main(){    	
    // Seu código vai aqui
    
    int X, Y, flagX, flagY;
    
    if (scanf("%d %d", &X, &Y) != 2) {
        fprintf(stderr, "Error: Invalid input. Please enter two integer values\n");
        return 1;
    }

    if (((X < -100) || (Y < -100) ) || ((X > 100) || (Y > 100) ))
    {
         fprintf(stderr, "Error: Values must be between -100 and 100.\n");
        return 1;
    }
    
    if (X > 0) flagX = 1;
    else  if (X < 0) flagX = -1;
    else flagX = 0;
    
    if (Y > 0) flagY = 1;
    else  if (Y < 0) flagY = -1;
    else flagY = 0;

    switch (flagX * flagY)
    {
    case 0:
        printf("Eixos");
        break;
    case 1:
        if (flagX > 0 && flagY > 0)
            printf("Q1\n");
        else
            printf("Q3\n");
        break;
    case -1:
        if (flagX > 0 && flagY < 0)
            printf("Q4\n");
        else
            printf("Q2\n");
        break;
    default:
        break;
    }

    return 0;
}