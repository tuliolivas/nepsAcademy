# Função Realloc
A função realloc irá alterar o tamanho de um bloco de memória previamente alocado.
Ou seja, ela irá receber um ponteiro que aponta para a primeira posição de um bloco de memória que já foi alocado e irá alterar a quantidade de bytes dele, retornando um ponteiro para a primeira posição do bloco com seu novo tamanho.
Caso o novo tamanho seja maior que o anterior, então todas as posições anteriores manterão seus valores e as novas terão valores indeterminados.
Caso contrário, as primeiras posições do bloco irão manter seus valores, e a exclusão será feita nas posições ao final do bloco.

O protótipo da função (tipo de retorno, nome e parâmetros) é o seguinte:

`void* realloc (void* ptr, size_t size);`

Para a utilização da função, são necessários dois parâmetros:
1. o ponteiro que aponta para o bloco de memória previamente alocado, 
2. o novo número de bytes que esse bloco irá assumir.

### Exemplos:
```c
int *p1 = malloc(64);
p1 = realloc(p1, 512);
double *p2 = calloc(4, sizeof(double));
p2 = realloc(p2, 8*sizeof(double));
```

###Observações:

O ponteiro passado para a função também pode ter um valor nulo e, nesse caso, a função atuará da mesma forma que a função malloc. Observe:

```c
int *p = NULL;
p = realloc(p, 64);
```

É possível, mas não obrigatório, que a função mova o bloco para outro endereço, para que a realocação seja possível, visto que a região anterior pode não ter espaço suficiente.

Caso a realocação não seja possível, então a função irá retornar um ponteiro nulo, porém não irá desalocar o bloco.
Por isso, uma boa prática é utilizar um ponteiro auxiliar para receber o endereço proveniente da realocação, e só atribuir este endereço ao ponteiro original caso ele não seja nulo.

Observe:
```c
int *p = malloc(24);
int *aux = realloc(p, 2147483647); // retorna um ponteiro nulo
if(aux != NULL){ // NULL representa um valor nulo
    p = aux; // nao eh executado, pois aux armazena um ponteiro nulo
}
```

Tendo em vista que a função realloc retorna um ponteiro do tipo void, pode ser necessário utilizar um casting de dados ao atribuir o endereço retornado pela função a um ponteiro, assim como nas funções malloc e calloc:

```c
int *p = (int*)malloc(8);
p = (int*)realloc(p, 64);
char *ptr = (char*)calloc(7, sizeof(char));
```

A função free também pode ser utilizada para liberar a memória realocada pela função realloc:

```c
double *ptr = (double*)malloc(7*sizeof(double));
ptr = (double*)realloc(ptr, 9*sizeof(double));
free(ptr);
```

### Exemplos de funcionamento

Utilizando a função malloc, podemos alocar um bloco de 2 bytes de memória:

```c
char *p = (char*)malloc(2);

//agora podemos utilizar esse bloco como um vetor de caracteres

p[0] = 'A';
p[1] = 'B';
```

Suponha, agora, que precisamos de outros 3 caracteres. Para obter isso, podemos utilizar a função realloc para expandir nosso vetor:

```c
p = (char*)realloc(p, 5); // 2 + 3 = 5

p[2] = 'C';
p[3] = 'D';
p[4] = 'E';
```

Da mesma forma que foi possível aumentar o tamanho do vetor, também podemos diminuí-lo:

```c
p = (char*)realloc(p, 3); // desaloca os ultimos 2 bytes
```

Tendo entendido o funcionamento básico da função realloc, vamos ver como funcionaria a realocação a partir de um ponteiro nulo e o deslocamento do bloco para que a realocação seja possível.

Partindo de um ponteiro de valor nulo, podemos utilizar a função realloc para alocar 2 bytes de memória:

```c
char *ptr = NULL;

ptr = (char*)realloc(p, 2);

// agora podemos utilizar esse bloco como um vetor de caracteres

ptr[0] = 'A';
ptr[1] = 'B';
```

Suponhaa que, na região onde nosso bloco de memória foi alocado, só há mais uma posição disponível(pois o bloco deve ser contínuo).
Logo, caso queiramos expandir nosso vetor para 4 bytes, então ele deverá ser deslocado:

```c
ptr = (char*)realloc(p, 4);

ptr[2] = 'C';
ptr[3] = 'D';
```

No entanto, para diminuir o vetor não será necessário voltar para antiga posição, pois a região onde o bloco está armazenado tem espaço suficiente.
Ou seja, o deslocamento do bloco de memória só ocorre quando não é possível realizar a realocação na região onde ele se encontra. Observe:
````c
p = (char*)realloc(p, 2);
```

Agora que você aprendeu a utilizar as funções malloc, calloc, realloc e free, tente usar seus conhecimentos para fazer um programa que crie um vetor dinâmico e vá alterando seu tamanho conforme a entrada indicada pleo usuário.