# Leitura de dados
A leitura de dados possibilita que o programa armazene informações digitadas pelo usuário.
Sem a leitura de dados, um programa seria apenas algo estático, ou seja sempre faria a mesma coisa com os mesmos dados.
É através da leitura de dados que conseguimos coletar informações digitadas pelo usuário e fazer o programa trabalhar com base nesses dados.
Um exemplo da importância da leitura de dados, e você imaginar uma calculadora sem leitura de dados.
Seria uma calculadora onde você não poderia colocar as suas formulas, sempre calcularia a mesma formula.

# Comando scanf.
Para realização da leitura de dados em C utilizamos o comando scanf (scan + f = ler + função), ele possibilita que o programa solicite valores para o usuário e atribua esses valores para variáveis.
No comando scanf, devemos informar a formatação que queremos ler e as posições de memória que vamos guardar os valores.

`scanf(<formatação>,<posições de memória>);`

# Operador &
No scanf, devemos informar as posições de memória que queremos guardar as informações.
Quando escrevemos & antes de uma variável, o C entende que queremos a posição de memória da variável. 
Então sempre que colocarmos uma variável no scanf, temos que colocar o & antes dela, para especificar que queremos que o computador armazene informação na mesma posição de memoria que ela está ocupando.

# Formatação
A formatação utilizada e semelhante ao printf, utilizando `%<tipo>` para especificar que queremos ler um valor de um determinado tipo:

Especificador|Tipo
:-:|:-:
%d ou %i  |int
%f|float
%c|char

### Exemplos:

```c
#include <stdio.h>

int main(){
    int a, b;
    scanf("%d", &a);
    printf("Valor da variavel a = %d\n", a);
    return 0;
}
```

Na linha 4 é realizado a declaração das variáveis, como foi visto anteriormente essa declaração pode ser feita com varias variáveis em uma unica linha caso elas sejam do mesmo tipo ou cada uma em uma linha separada.
Na linha 5 o comando scanf está realizando a leitura de um valores e o atribuindo à variável a, note que foi colocado apenas um especificador entre as aspas duplas e apenas a variável a após a virgula, ou seja pra cada especificador entre as aspas duplas eu preciso colocar uma variável apos a virgula, note também que antes da variável a esta presente um &.
Na linha 6 esta sendo realizado a impressão do valor digitado pelo usuário presente na variável a.
Ao compilar e executar esse código, note que vai aparecer apenas uma linha vazia com um traço piscando, isso significa que ele esta esperando que você digite um valor, ao digitar o valor pressione a tecla "Enter".

```c
#include <stdio.h>

int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    printf("Valor de A = %d\nValor de B = %d\n", a, b);
}
```

Neste exemplo e possível ver que e possível realizar a leitura de mais um valor no scanf e atribuir esses valores a mais de uma variável.
Desta vez no printf esta sendo imprimido o valor das duas variáveis, em vez de apenas o valor da variável a como no primeiro exemplo.
Ao compilar e executar o código desta vez, note que quando você digitar um valor e pressionar a tecla "Enter", ele ira pedir outro valor, pois desta vez são duas entradas e não apenas uma.
O primeiro valor digitado sera atribuído a posição de memoria da variável a e o segundo a posição de memoria da variável b, a ordem dos valores esta diretamente relacionada a ordem das variáveis após a virgula.

```c
#include <stdio.h>

int main(){
    int a, b;
    scanf("%d",&a);
    scanf("%d",&b)
    printf("Valor de A = %d\nValor de B = %d\n",a,b);
}
```

Neste exemplo ao invés de ler dois valores para duas variáveis em um único scanf, realizamos a leitura em dois scanfs diferentes.

```c
#include <stdio.h>

int main(){
    int a, b;
    scanf("%d%d",&a,&b);
    printf("Soma de a+b = %d\n",a+b);
}
```

Neste exemplo invés de fazermos a impressão do valor de a e de b, imprimimos a soma destes valores.
Também pode-se observar que ao invés de 2 especificadores temos apenas 1, pois em vez de imprimir dois valores distintos estamos imprimindo um único valor ,ou seja, a soma de a com b, a+b.

```c
#include <stdio.h>

int main(){
    float a, b;
    scanf("%f%f",&a,&b);
    printf("Soma de a+b = %f\n",a+b);
}
```

No exemplo a cima, estamos fazendo a mesma soma do exemplo anterior, só que desta vez estamos utilizando variáveis do tipo float, note que no especificador em vez de %d estamos utilizando %f.
Com entradas de tipo float precisamos ter um cuidado especial, ao invés de utilizar virgula utilizamos ponto, ex: "3.14".