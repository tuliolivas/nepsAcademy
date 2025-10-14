Neste projeto, você vai criar um programa de calculadora baseado em texto que funciona inteiramente no terminal.
A ideia é simples: ao rodar o programa, ele exibirá um menu de opções para o usuário, permitindo que escolha uma operação matemática como adição, subtração, multiplicação ou divisão.
Depois, o usuário insere os números e recebe o resultado imediatamente.
É prático, funcional e, acima de tudo, um ótimo exercício para consolidar os fundamentos da programação em C!

Quando o programa for executado, ele deverá exibir um menu inicial com as seguintes opções:

===============================
   Calculadora Simples
===============================
Selecione uma operação:
1. Adição
2. Subtração
3. Multiplicação
4. Divisão
5. Sair

Opção:
Se o usuário escolher uma operação (por exemplo, "1" para adição), o programa deverá solicitar dois números:

Digite o primeiro número: 5
Digite o segundo número: 3
Resultado: 5 + 3 = 8

Após exibir o resultado, o programa perguntará se o usuário deseja realizar outra operação:

Deseja realizar outra operação? (s/n):

Se o usuário digitar "s", o programa volta ao menu inicial. Caso contrário, ele exibe uma mensagem de despedida e encerra:

Obrigado por usar a calculadora! Até a próxima.

Arquivos Obrigatórios
Seu projeto precisa ter os seguintes arquivos:
main.c: Contém o código-fonte principal do programa com todas as funcionalidades implementadas.

Requisitos
Para ser considerado correto seu projeto precisa implementar corretamente os seguintes requisitos.

Pontos: 40
Seu programa deve implementar o menu inicial e seleção de ppções
Exibição do menu: Ao executar o programa, ele deve exibir o menu inicial de forma correta e clara;
Entrada e validação da opção:
O programa deve ler a entrada do usuário para a opção selecionada.
Deve validar se a opção é um número inteiro entre 1 e 5.
Se o usuário inserir uma opção inválida (número fora do intervalo ou entrada não numérica), o programa deve exibir uma mensagem de erro apropriada e solicitar que o usuário insira uma opção válida novamente.
Opção de sair:
Se o usuário selecionar a opção 5 (Sair), o programa deve exibir a mensagem de despedida
Após exibir a mensagem, o programa deve encerrar a execução.

Pontos: 40
Você precisa implementar as operações matemáticas
Solicitação dos números:
Para as opções 1 a 4, o programa deve solicitar que o usuário insira dois números;
Deve ler os dois números inseridos pelo usuário, permitindo números inteiros e decimais.
Cálculo e exibição do resultado:
O programa deve realizar a operação matemática correspondente à opção selecionada:
1. Adição: somar os dois números.
2. Subtração: subtrair o segundo número do primeiro.
3. Multiplicação: multiplicar os dois números.
4. Divisão: dividir o primeiro número pelo segundo.
Deve exibir o resultado no formato especificado, incluindo o operador matemático correto:
Resultado: [número1] [operador] [número2] = [resultado]
Exemplo:
Resultado: 5 + 3 = 8
Tratamento de erros na divisão:
Se o usuário tentar dividir por zero, o programa deve detectar essa situação e exibir uma mensagem de erro apropriada, como:
Erro: Divisão por zero não é permitida.
Após o erro, deve solicitar ao usuário se deseja realizar outra operação.

Pontos: 20
Seu programa precisa implementar loop para múltiplas operações
Perguntar sobre nova operação:
Após exibir o resultado (ou uma mensagem de erro), o programa deve perguntar ao usuário se ele deseja realizar outra operação.
Deve ler a resposta do usuário, aceitando 's' ou 'n' (maiúsculo ou minúsculo).
Controle de fluxo com base na resposta:
Se o usuário digitar 's':
O programa deve limpar a tela (opcional) e retornar ao menu inicial para que o usuário possa selecionar uma nova operação.
Se o usuário digitar 'n':
O programa deve exibir a mensagem de despedida.
Em seguida, encerrar a execução.
Se o usuário digitar uma resposta inválida:
O programa deve exibir uma mensagem de erro, como:
Resposta inválida. Por favor, digite 's' para sim ou 'n' para não.
Deve repetir a pergunta até que o usuário insira uma resposta válida.
Manutenção do loop principal:
O programa deve continuar este ciclo de operações até que o usuário escolha não realizar outra operação após um cálculo ou selecione a opção de sair no menu inicial.