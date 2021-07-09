# Data structure in C :white_check_mark:

<hr>
<h3>Implementation some exercises :bulb:</h3>

<dl>
  <dt>BubbleSort</dt>
  <dd>
    Compara os elementos sequencialmente, e troca de lugar se não estiverem ordenados.
    Melhor caso <strong>O(N)</strong> - para todos os elementos já ordenados.
    Pior caso <strong>O(N^2)</strong> - não recomendado para vetores grandes.
  </dd>

  <dt>InsertionSort</dt>
  <dd>
    Compara o elemento e insere em seu devido lugar.
    É capaz de ordenar dados em tempo real, no momento em que são inseridos.
    Melhor caso <strong>O(N)</strong> - vetor já ordenado.
    Pior caso <strong>O(N^2)</strong> - perde desempenho em grande quantidade de dados desordenados.
  </dd>
  <dt>SelectionSort</dt>
  <dd>
    Procura em todas as posições o menor valor e ordena dessa forma.
    Melhor caso <strong>O(N^2)</strong>.
    Pior Caso<strong>O(N^2)</strong>.
  </dd>
  <dt>MergeSort</dt>
  <dd>
    Divide recursivamente o conjunto pela metade, e ordena os subconjuntos.
    Melhor caso <strong>O(N log N)</strong>.
    Pior Caso<strong>O(N log N)</strong> por ser recursivo e criar um vetor auxiliar na ordenação.
  </dd>
  <dt>QuickSort</dt>
  <dd>
    Possui a ideia em dividir o vetor e selecionar um elemento como pivô, usa recursividade para ordenar valores.
    Melhor caso <strong>O(N log N)</strong> - seleciona sempre o meio para dividir, as partições tem o mesmo tamanho.
    Caso médio <strong> O()</strong> - divide por um valor qualquer no vetor.
    Pior caso <strong> O(N^2)</strong> - caso o pivô seja o maior ou menor elemento.
  </dd>
</dl>


<h3>To compile and run :electric_plug:</h3>
<dl>
<dt>Linux</dt> 
  <dd>you need to open <strong>src/</strong> and run the command to compile <strong>gcc merge.c</strong>, after that, you can run with <strong>./a.out</strong></dd>
<dt>
Windows
</dt>
<dd>you can compile and run with <strong>gcc merge.c -o a.exe</strong></dd>
