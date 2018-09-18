#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOW_VALUE "0"
#define TAM 20

void inicializacao(char* prev1, char* prev2, FILE** lista1, FILE** lista2, int* existem_mais_nomes, FILE** saida){
    strcpy(prev1, LOW_VALUE);
    strcpy(prev2, LOW_VALUE);

    *lista1 = fopen("Lista1.txt", "r");
    *lista2 = fopen("Lista2.txt", "r");

    if(*lista1 != NULL && *lista2 != NULL)
        *existem_mais_nomes = 1;

    *saida = fopen("output.txt", "w+");
}

void input(FILE* entrada, char* nome_ant, char* nome, int* existem_mais_nomes){
    fgets(nome, TAM, entrada);
    if(feof(entrada))
        *existem_mais_nomes = 0;
    else if(strcmp(nome, nome_ant) <= 0){
        printf("Erro na checagem de sequência\n");
        exit(EXIT_FAILURE);
    }
    strcpy(nome_ant, nome);
}

int main(){ //match
    FILE *lista1, *lista2, *saida;
    int existem_mais_nomes, ret_cmp;
    char prev1[TAM], prev2[TAM], nome1[TAM], nome2[TAM];

    inicializacao(prev1, prev2, &lista1, &lista2, &existem_mais_nomes, &saida);
    input(lista1, prev1, nome1, &existem_mais_nomes);
    input(lista2, prev2, nome2, &existem_mais_nomes);

    while(existem_mais_nomes){
        ret_cmp = strcmp(nome1, nome2);
        if(ret_cmp < 0)
            input(lista1, prev1, nome1, &existem_mais_nomes);
        else if(ret_cmp > 0)
            input(lista2, prev2, nome2, &existem_mais_nomes);
        else{ //Se as chaves forem iguais
            fwrite(nome1, sizeof(char), strlen(nome1), saida);
            input(lista1, prev1, nome1, &existem_mais_nomes);
            input(lista2, prev2, nome2, &existem_mais_nomes);
        }
    }
}