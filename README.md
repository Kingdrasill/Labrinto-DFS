# Resolver um labrinto pelo método de Busca em Profundidade(DFS)

<div style="display: inline-block;">
<img align="center" height="20px" width="60px" src="https://img.shields.io/badge/Language-C-blue"/> 
<img align="center" height="20px" width="80px" src="https://img.shields.io/badge/Made%20in-VSCode-red"/> 
</div>
<p align="justify">
Busca em Profundidade é um algoritmo normalmente ultilizado para realizar busca ou travsseia em árvores, mas pode ser aplicado em outros casos também. Um desses casos é em matrizes, que podem ser labirintos, para chegar de uma determinada posição inicial até uma determindada posição final, em labirintos essas seriam a entrada e saída dele. Para este algoritmo há duas estruturas importantes a matriz que é o labirinto e a pilha dinâmica que guarda o caminho percorrido.
</p>

<p align="justify">
  A estrutua da matriz é possui um tamanho, uma largura e qual o dado de cada posição da matriz. Está irá representar um labirinto de tamanho n e largura m em que cada posição pode ter um dos tipos de dado a seguir:
  <ul>
    <li>"E" - Simboliza a entrada do labirinto, só há uma por labirinto</li>
    <li>"S" - Simboliza a saída do labirinto, só há uma por labirinto</li>
    <li>"." - Simboliza um caminho passável no labirinto, só há uma por labirinto</li>
    <li>"#" - Simboliza uma parede no labirinto, só há uma por labirinto</li>
  </ul>
  E para um labirinto ser válido tem que exister pelo menos um caminho da entrada para o final. O labirinto a seguir é um labirinto 8x8 válido de exemplo, o caminho vermelho representa uma das formas de passar por ele:
</p>
<p align="center">
  <img src="imgs/labirinto.png" width="400px">
</p>

<p align="justify">
  A estrutura pilha dinâmica será utilizada para guardar o caminho tomado da entrada para chegar na saída. A pilha dinâmica é uma variante do modelo de pilha estática, na pilha dinâmica a um ponteiro que a ponta para o topo da pilha e um ponteiro que aponta para o fundo da pilha e os dados possuem um valor e quem é o dado passado para chegar nele. A estrutura pode ser vista pela visualização gráfica abaixo:  
</p>
<p align="center">
  <img src="imgs/pilha.png">
</p>

# Compilação e Execução

A lista dinâmica disponibilizada possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |
