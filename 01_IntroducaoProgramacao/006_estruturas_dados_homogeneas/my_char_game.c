#include <stdio.h>

int main () {
    char player_move;
    
    int scene[9] = {
        0, 0, 0,
        0, 8, 0,
        0, 0, 0 
    };

    //Game Loop
    int draw = 1;

    while (draw) {
        //Desenhar a cena
        for( int i = 0; i < 9; i++)
        {
            printf("%d ", *(scene + i));
           if ((i + 1) % 3 == 0)
                printf("\n");
        }
        
        //Ler entrada de dados
        printf("Move (a=left, d=right, w=up, s=down, other=exit): ");
        // Limpa o buffer antes de ler
        fflush(stdin);
        player_move = getchar();
        getchar(); // Consome o '\n'

        //Achar a posição do player
        int pos = -1;
        for (int i = 0; i < 9; i++)
        
            if (*(scene + i) == 8)
            {
                pos = i;
                break;
            }
        

        //Movimentar o player
        switch (player_move)
        {
        case 'a':
            if (pos % 3 != 0)
            {
                *(scene  + pos - 1) = 8;
                *(scene  + pos) = 0;
            }
            break;

        case 'd':
            if ((pos + 1) % 3 != 0)
            {
                *(scene  + pos + 1) = 8;
                *(scene  + pos) = 0;
            }
            break;

        case 'w':
            if (pos > 2)
            {
                *(scene  + pos - 3) = 8;
                *(scene  + pos) = 0;
            }
            break;

        case 's':
            if (pos < 6)
            {
                *(scene  + pos + 3) = 8;
                *(scene  + pos) = 0;
            }
            break;
            
        default:
            draw = 0;
            break;
        }

    }  

}