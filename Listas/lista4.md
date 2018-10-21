# Resolução de exercícios - Lista 4

1) O número de comparações não é uma medida adequada para avaliar o desempenho de métodos de ordenação de grandes arquivos que não cabem na memória pois o tempo de seek nestes arquivos é muito maior que o tempo de ordenação, ou seja, o tempo de seek é o grande gargalo de desempenho da operação.

2) ~Algoritmo~

3) 
        - Arquivo com 6000 registros
        - Máx na memória interna: 600 registros (buffer de entrada)
        - Buffer de saída: 200 registros

    a) Temos 6000 registros e podemos armazenar em memória apenas 600 por vez. Isso quer dizer que teremos **100 *runs***. <br>
    É preciso ler as 100 *runs* simultâneamente, portanto, serão lidos **600/100 registros de cada run**, ou seja, **60 registros de cada run**.

    b) Cada run terá que ser acessada 60 vezes durante a etapa de merging. Considerando 1 seek por acesso, teremos 60 seeks. <br>
    Ou seja, 60*60 = 3600 seeks.

    c) Para escrever o arquivo ordenado no disco, a quantidade de seeks depende do tamanho do buffer de saída. Temos que esse buffer tem tamanho suficiente para armazenar 200 registros.<br>
    Temos então 6000/200 = 300 seeks para escrever o arquivo ordenado no disco.

4) 

5) 
        - Arquivo de 800MB
        - Buffer de entrada de 4MB
        - Buffer de saída de 200KB

    800 MB / 4 MB = **200 runs**

    P1: 1 seek por run = 200 seeks => 200 seeks + transmissão de 800MB
    P2: 1 seek por run = 200 seeks => 200 seeks + transmissão de 800MB
    P3: 
