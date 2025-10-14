Biblioteca string.h

Nesta lição, aprenderemos as principais funções da biblioteca <string.h>,que podemos usar para trabalhar melhor com strings.
Seguiremos os tópicos:

O que é a biblioteca string.h?
Função Strlen.
Função Strcpy.
Função Strcmp.
Função Strcat.
Função Strstr.

Codificação: Usando a Biblioteca.

O que é a biblioteca string.h?

Uma biblioteca é um arquivo que contém diversas funções.
Cada biblioteca contém funções específicas para algum propósito. Por exemplo:

- stdio.h: Funções de entrada e saída de dados.
- string.h: Funções de manipulação de strings.

Para usar as funções que estão na biblioteca, devemos incluir a biblioteca no início do código digitando "#include <string.h>".

#include <string.h>

função strlen

Uma função que espera receber um local de memória que contém uma string e retornará quantos caracteres existem entre o local recebido e o próximo '\0'.

Exemplo:

char s[10] = "abcd";
printf("%d", strlen(s) ); // Prints 4

função strcpy

Uma função que espera receber duas posições de memória contendo strings e atribuirá a segunda string à primeira.

Exemplo:

char a[10] = "abcd";
char b[10];
strcpy(b, a); //b receives a
printf("%s\n", b); // Prints "abcd"

É importante observar que, como segundo parâmetro, podemos fornecer um ponteiro ou uma string.
Se substituirmos a variável a no código strcpy acima por "neps", ele imprimirá "neps", mesmo que essa string não esteja alocada em um espaço de memória.

função strcmp

Uma função que espera receber duas posições de memória contendo strings e comparará as strings lexicograficamente.

If str1 == str2, returns 0
If str1 < str2, returns -1
If str1 > str2, returns 1

Um exemplo do uso da função seria:

int main(){
    char n1[20];
    char n2[20];

    scanf("%s %s", n1, n2);

    if(strcmp(n1, n2) == 0){
        printf("equal strings");
    }
    if(strcmp(n1, n2) == -1){
        printf ("first is smaller");
    }
    if(strcmp(n1, n2) == 1){
        printf ("second is smaller");
    }
}

O código acima compara as duas strings e pode dizer se elas são iguais, se a primeira é menor ou se a segunda é menor por meio da função strcmp.

Observe que o valor lexicográfico * das strings é comparado, então se inserirmos as strings "aaaa" e "abcde", que têm o mesmo número de caracteres, nosso código imprime "first is smaller", porque lexicograficamente a primeira string é menor, ou seja, se ordenarmos as duas considerando a ordem alfabética, "aaaa" viria primeiro.

Se inserirmos as strings "zz" e "abcde", o código imprime "o segundo é menor", porque na ordem lexicográfica,
ou seja, se classificarmos as strings em ordem alfabética, o segundo viria primeiro.

função strcat

Uma função que espera receber duas posições de memória contendo strings e concatenará a segunda string na primeira.

Exemplo:

char name[50] = "neps";
strcat(name, " academy"); //name = "neps academy"
printf("%s\n", name); // Prints "neps academy"

Função strstr

Uma função que espera receber duas posições de memória contendo strings e retorna a primeira posição de memória da primeira que contém a segunda.

char name[50] = "academy";
printf("%s", strstr(name, "de") ); //Prints "demy

No código acima, a função strstr procurará a string "de" na string "academy" e retornará a primeira posição da memória onde ela for encontrada e,
como a estamos imprimindo a partir dessa posição, acabamos imprimindo "demy".

Se alterarmos o segundo parâmetro para "c", o programa imprimirá "cademy".

Se a string não for encontrada, um ponteiro nulo será retornado.
Abaixo está um exemplo de como podemos usar a função para descobrir se uma string está contida em outra.

int main(){
    char n1[20] = "academy";
    if(strstr(n1, "xx") == NULL){
        printf ("Not contained");
    }else{
        printf("Contained\n");
    }
}

Agora você sabe como usar as principais funções de string.h para fazer operações como encontrar o tamanho de uma string, copiar uma string,
comparar duas strings, concatenar duas strings e verificar a ocorrência de uma string em outra.