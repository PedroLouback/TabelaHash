# Trabalho sobre Estrutura de Dados Hash

[![Linguagem C](https://img.shields.io/badge/Linguagem-C-green.svg)](https://github.com/PedroLouback/TrabalhoFinal-Prog.2)
[![requirement](https://img.shields.io/badge/IDE-Visual%20Studio%20Code-informational)](https://code.visualstudio.com/docs/?dv=linux64_deb)
![ISO](https://img.shields.io/badge/ISO-Linux-blueviolet)


<h1> Implementação de duas Tabelas Hash

## Conteúdos

<p align="center">
 <a href="#apresentação">Apresentação</a> •
 <a href="#representação-gráfica-das-tabelas-hash">Representação gráfica das Tabelas Hash</a> •
 <a href="#lógica">Lógica</a> • 
 <a href="#representação-gráfica">Representação gráfica</a> • 
 <a href="#resultados-e-análises">Resultados e Análises</a> • 
 <a href="#bibliotecas">Bibliotecas</a> •
 <a href="#compilação-e-execução">Compilação e Execução</a> • 
 <a href="#autor">Autor</a>
</p>

---

## Apresentação

Foi proposto pelo professor [Michel Pires da Silva](http://lattes.cnpq.br/1449902596670082) durante sua aula de `Laboratório de Algoritmos e Estruturas de Dados 1` um trabalho em que propunha a implementação de dois tipos de tabelas hash sendo elas:

- [X] Hash de Endereçamento Fechado;
- [X] Hash de Endereçamento Aberto por Hash Dupla;

Onde foi obtido exito na implementação das duas tabelas. O trabalho deve receber diretamente no seu código um vetor de no mínimo 20 valores inteiros, os quais serão utilizados como entrada para as duas estruturas que vão ser criadas como o dobro do tamanho do vetor (i.e., número primo maior que esse valor dobro).
O propósito desse trabalho é apresentar e analisar o número de colisões ocorridas para ambas as estruturas quando o mesmo vetor é armazenado, apresentando uma breve discussão dos motivos que levaram uma apresentar melhores resultados.

A estrutura `Hash de Endereçamento Fechado` ...

A estrutura `Hash de Endereçamento Aberto por Hash Dupla` ...

O algoritmo de busca `DFS` significa *Depth First Search*, sendo uma técnica que utiliza uma *Estrutura de dados Pilha* onde procura sempre explorar dando preferência a uma determinada direção a partir da posição inicial, empilhando as posições visitadas e desempilhando as posições que já foram passadas.

O algoritmo de busca `BFS` significa *Breadth First Search* e consiste em uma técnica baseada em largura onde visita um elemento e todos os seus vizinhos, depois todo os vizinhos dos vizinhos e assim por diante. Para fazer isso, o algoritimo usa uma *Estrutura de dados Fila* em que o primeiro a entrar será o primeiro a sair sendo mais lento que o `DFS`

---

## Representação gráfica das Tabelas Hash

<p align="center">
<img src="imgs/DFS.png" width="260px"/> 
</p>

A representação mostra o início em (0x0) e os números que estão dentro das células mostram os passos percorridos até chegar ao final *@* (NxN), onde é visualizado a diferença na forma de caminhar nos dois algoritmos de busca.

<p align="center">
<img src="imgs/BFS.png" width="260px"/> 
</p>

---

## Lógica

Ao se deparar com proposta do problema citado na <a href="#apresentação">Apresentação</a> a dupla decidiu em utilizar apenas um programa principal no qual iria ler o arquivo citado nas regras de desenvolvimento do programa onde após a leitura iria ser chamado o método de busca em que era desejadO utilizar, sendo esses dois métodos implementados nesse programa principal, foi feito as inserções de uma [Fila Dinâmica](https://github.com/mpiress/dynamic_queue) e uma [Pilha Dinâmica](https://github.com/mpiress/dynamic_stack) onde foram clonadas dos respectivos repositorios para obter seus métodos básicos mantendo a proposta de cada algoritmo de busca requerido. O desenvolvimento da lógica de todo o problema foi desenvolvida em 3 sub etapas para que houvesse sucesso na resolução, sendo elas,  <a href="#•-funcionamento-da-leitura-do-arquivo">Funcionamento da leitura do arquivo </a>, <a href="#•-funcionamento-do-dfs">Funcionamento do DFS</a> e <a href="#•-funcionamento-do-bfs">Funcionamento do BFS</a>:

### • Funcionamento da leitura do arquivo

Para ser feita a leitura correta do arquivo primeiramente o nome do mesmo terá que ser `matriz` do tipo  *txt*, foi preciso pensar levando em consideração as regras propostas, resumindo então em ler o tamanho N da matriz na primeira linha utilizando a função _fscanf_ lendo apenas um número por se tratar de uma matriz quadrática sendo esse número adquirido pela variavel _tam_ para ser feita a construção da matriz alocando o seu tamanho de linhas e de colunas, após a leitura da primeira linha foi utilizado dois comandos `FOR` para que fosse possível ser feita a leitura da matriz dentro do arquivo constituindo de **zeros** (caminhos possível de se locomover) e **uns** (paredes de bloqueio) direcionando-a para o programa e armazenando-a nos espaçoes alocados sendo feito então toda a criação já da matriz com suas paredes de bloqueios. Para ser feito a leitura do tipo de método utilizado para busca foi pensando em ser feita novamente a leitura com a função _fscanf_ onde se usuário quiser utilizar o método `DFS` será necessário apenas modificar a ultima linha para **0** e caso se quiser utilizar o método `BFS`irá modificar para **1**, pois com isso o programa entenderá, a partir de um tratamento com `IFs` feito pela dupla que dependendo do valor citado seria feita a leitura desejada do método.
Exemplo de entrada do arquivo `matriz.txt`: 

<p align="center">
<img src="imgs/ExplicacaoArquivo.png" width="500px"/> 
</p>


---

## Representação gráfica

Segue a representação gráfica de um exemplo ilustrado dos dois diferentes algoritmos de busca e suas respectivas legendas aplicadas ao exemplo de matriz fornecidos pelo professor:
 
 • *Os número que estão dentro de cada celula representam respectivamente a posição do **i** e a posição do **j**, para que não haja confusão, onde ache que seja um valor*

<p align="center" alt="Representação caminho percorrido.">
<img src="imgs/Caminhos_bloqueados.png" width="500px"/><br/>
<i><b>Matriz 1: </b>Representação apenas da matriz e suas parede de bloqueio</i>
</p>

<p align="center" alt="Representação caminho percorrido.">
<img src="imgs/LEGENDA_DFS.png" width="600px"/><br/>
<i><b>Matriz 2: </b>Representação matriz percorrida utilizando DFS</i>

<p align="center" alt="Representação caminho percorrido.">
<img src="imgs/LEGENDA_BFS.png" width="600px"/><br/>
<i><b>Matriz 3: </b>Representação matriz percorrida utilizando BFS</i>



---

## Resultados e Análises 

<i>1</i> - Sim, diferentes tamanhos de matrizes e posicionamentos de paredes irão influenciar diretamente em qual dos métodos terá uma reposta mais eficiente. Para matrizes onde o número de paredes é consideravelmente alto ou as paredes se encontram em posições as quais formam uma espécie de caminho sem volta, o BFS retornará o resultado com um tempo de execução menor. Caso contrário, para matrizes onde o número de paredes é baixo, o DFS possui melhor performance, uma vez que a probabilidade de ficar preso em um corredor é mais baixa quando há poucas paredes, por consequência, DFS dará menos passos e retornará mais rápido que o BFS.<br/>
<i>2</i>- O DFS busca o caminho dando preferência ao comando inicial (DESCER ou IR PARA DIREITA), isso implica que, suas decisões são tomadas apenas observando o próximo passo, não é levado em consideração que,  se o algoritmo optar por descer agora ao em vês de virar a direita, ele ficará sem mais para onde ir. Isso é uma característica de uma família de algoritmos chamados de Algorítmos gulosos. Então não, os algorítmos aqui apresentdos não possuem capacidade de encontrar o menor caminho até o seu destino.

---

## Bibliotecas

<p>Para o funcionamento do programa, é necessário incluir as seguintes bibliotecas: 
<ul>
    <li><code>#include 'stdlib.h'</code></li>
    <li><code>#include 'stdio.h'</code></li>
    <li><code>#include 'time.h'</code></li>
    <li><code>#include 'stdbool.h'</code></li>
</ul>

---

## Compilação e Execução

O programa feito de acordo com a proposta possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação             


---

## Autores

Desenvolvido por [Pedro Henrique Louback Campos](https://github.com/PedroLouback) 

Aluno do 3° periodo de `Engenharia da Computação` no [CEFET-MG](https://www.cefetmg.br)
