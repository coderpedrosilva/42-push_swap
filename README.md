# 42-push_swap

O projeto Push swap é um projeto de algoritmo onde os dados devem ser ordenados e classificados. Existe à disposição um conjunto de valores inteiros, 2 pilhas e um conjunto de instruções para manipular ambas as pilhas.

Trata-se de um programa de ordenação de dados, com um conjunto limitado de instruções, usando o menor número possível de ações. A pilha "A" contém uma quantidade aleatória de números negativos e/ou positivos que não podem ser duplicados. A pilha "B" inicia vazia.

O objetivo é ordenar em ordem crescente os números na pilha "A". Para isso se tem à disposição as
seguintes operações:

Operação   | Descrição
--------- | ------
sa (swap a) | Troca os 2 primeiros elementos no topo da pilha "A". <br> Não faz nada se houver apenas um ou nenhum elemento.
sb (swap b) | Troca os 2 primeiros elementos no topo da pilha "B". <br> Não faz nada se houver apenas um ou nenhum elemento.
ss | sa e sb ao mesmo tempo.
pa (push a) | Pega o primeiro elemento no topo de "B" e coloca no <br> topo de "A". Não faz nada se "B" estiver vazia.
pb (push b) | Pega o primeiro elemento no topo de "A" e coloca no <br> topo de "B". Não faz nada se "A" estiver vazia.
ra (rotate a) | Desloca todos os elementos da pilha "A" por 1. <br> O primeiro elemento torna-se o último.
rb (rotate b) | Desloca todos os elementos da pilha "B" por 1. <br> O primeiro elemento torna-se o último.
rr | ra e rb ao mesmo tempo.
rra (rotate reverse a) | Desloca todos os elementos da pilha <br> "A" por 1. O último elemento se torna o primeiro.
rrb (rotate reverse b) | Desloca todos os elementos da pilha <br> "B" por 1. O último elemento se torna o primeiro.
rrr | rra e rrb ao mesmo tempo.
