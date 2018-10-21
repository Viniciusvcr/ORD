# Resolução de exercícios - Lista 5

1) Ao usar índices simples podemos **deixar o arquivo de dados desordenado e ordenar apenas o arquivo de índice simples em memória RAM**, o que é muito rápido (o arquivo todo deve caber em memória). Além disso, podemos **criar várias visões para o mesmo arquivo de dados**, proporcionando diferentes tipos de busca. Com índices podemos também **fazer acesso direto por chave** a registros do arquivo de dados, reduzindo drásticamente o número de seeks necessários.

2) Uma chave primária deve ser única para garantir que cada elemento diferente tenha uma única "representação". A mesma restrição não se aplica a uma chave secundária pois podem existir elementos com um mesmo atributo que são diferentes logicamente. Um exemplo disso seria com nomes de pessoas. Pode existir duas pessoas com o mesmo nome (chave secundária), porém não é possível que seus CPFs (chave primária) sejam iguais.

3) O uso de índices simples deixa de ser recomendado quando não é possível carregar o arquivo completo para a memória RAM. Isso se dá pois é necessário manter o os índices ordenados por chave, o que é rápido de se fazer em memória RAM, mas pode ser demorado de se fazer em disco (temos um arquivo de índices justamente para não ordenarmos nada em disco).

4) Quando associamos índices secundários com índices primários teremos apenas que alterar o arquivo de índices primários caso uma alteração seja feita no arquivo de dados, o que não ocorre se fizermos uma associação direta. Em contrapartida, organizando de forma indireta teremos uma queda de desempenho na busca já que precisamos de um passo a mais, o que não ocorre na forma direta.

5) 
    - ***Registro de tamanho fixo***:
        - **Atualizar registro**: Nesse caso, índices primários só terão de ser atualizados caso haja alteração na chave primária, o que acarreta a necessidade de alteração do índice secundário. 
        - **Remover registro**: Nesse caso, apenas o índice primário sofrerá alteração visto que, durante uma busca pro índice secundário, nada será encontrado como referência para índice primário (no caso de estarmos usando uma organização indireta). Caso estejamos usando uma organização direta, ambos índices (primário e secundário) devem ser revisados.
        - **Inserir registro**: Na inserção de um registro claramente devemos atualizar ambos os índices visto que há agora uma nova chave primária que poderá ser buscada por um programa.
    - ***Registro de tamanho variável***:
        - **Atualizar registro**: Para índices primários é necessário fazer uma verificação nos índices pois pode haver alterações devido ao tamanho dos dados. Para os índices secundários, caso sejam feitos de forma indireta, nada irá mudar. Já, caso sejam feitos de forma direta, a verificação também é necessária.
        - **Remover registro**: Mesmo caso que em "Registro de tamanho fixo"
        - **Inserir registro**: Mesmo caso que em "Registro de tamanho fixo"

6) Porque, caso os índices secundários façam referência direta ao byte-offset do arquivo de dados, a escolha da abordagem *delete-all-references* é obrigatória. Diferentemente, caso os índices secundários façam referência aos índices primários, podemos excluir somente a referência do índice primário, ou seja, a abordagem *delete-some-references*, e ainda termos a busca por chave secundária funcionando, visto que, durante esse tipo de busca, nada será encontrado no arquivo de chaves primárias (tempo muito menor de busca). 

7) ~Algoritmo~

8) A finalidade do uso da lista invertida é a implementação de buscas por palavras-chave em conjuntos de documentos. Com esse tipo de lista, não precisamos buscar em todos os documentos por uma ocorrência já que temos cada palavra-chave ligada a uma lista de documentos nos quais ela aparece.

9) Índice secundário:

    |   Chave   	| Ref 	|
    |:---------:	|:---:	|
    | Beethoven 	|  2  	|
    |   Corea   	|  7  	|
    |   Dvorak  	|  1  	|
    | Prokofiev 	|  4  	|

    Lista invertida:

    |   Chave  	| Prox 	|
    |:--------:	|:----:	|
    | COL31809 	|  -1  	|
    |  DG18807 	|   3  	|
    |  RCA2626 	|   5  	|
    |  LON2312 	|  -1  	|
    | DG139201 	|   6  	|
    |  ANG3795 	|  -1  	|
    | WAR23699 	|  -1  	|

10) ?

11) ~Algoritmo~

12) 
    **Índice secundário profissão**:

    |    Chave    	| Ref 	|
    |:-----------:	|:---:	|
    |   Analista  	|  11 	|
    |  Digitador  	|  15 	|
    |   Operador  	|  8  	|
    | Programador 	|  2  	|

    **Índice secundário nacionalidade**:

    |    Chave   	| Ref 	|
    |:----------:	|:---:	|
    |  Argentina 	|  3  	|
    | Brasileira 	|  2  	|
    |   Chilena  	|  8  	|
    |  Paraguaia 	|  5  	|

    **Lista Invertida**:

    | Chave 	| Prox.Profissão 	| ProxNacionalidade 	|
    |:-----:	|:--------------:	|:-----------------:	|
    |  2050 	|       -1       	|         -1        	|
    |  430  	|        9       	|         9         	|
    |  980  	|       16       	|         16        	|
    |  1010 	|       13       	|         14        	|
    |  2000 	|       -1       	|         -1        	|
    |  1900 	|       12       	|         13        	|
    |  1550 	|        5       	|         12        	|
    |  690  	|        4       	|         15        	|
    |  730  	|       14       	|         4         	|
    |  1100 	|        5       	|         11        	|
    |  1790 	|        6       	|         -1        	|
    |  1990 	|        1       	|         1         	|
    |  2200 	|       -1       	|         -1        	|
    |  1620 	|       -1       	|         6         	|
    |  790  	|        3       	|         7         	|
    |  1040 	|        7       	|         10        	|
