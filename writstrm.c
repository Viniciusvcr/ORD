#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

#define TAM 20

void corta_string(char* frase){
	frase[strlen(frase)-1] = '\0';
}

int main(){
	char nome_arquivo[TAM], sobrenome[TAM], nome[TAM];
	char endereco[TAM+TAM], cidade[TAM], estado[TAM], cep[TAM]; 
	FILE *arq;

	printf("Escreva o nome do arquivo a ser criado: ");
	fgets(nome_arquivo, TAM, stdin);
	arq = fopen(nome_arquivo, "w");

	printf("\nEscreva o sobrenome: ");
	fgets(sobrenome, TAM, stdin);
	corta_string(sobrenome);
	while(strlen(sobrenome) > 0){
		//__fpurge(stdin);

		printf("\nEscreva o nome: ");
		fgets(nome, TAM, stdin);
		corta_string(nome);

		printf("\nEscreva o endereco: ");
		fgets(endereco, TAM, stdin);
		corta_string(endereco);
		__fpurge(stdin);

		printf("\nEscreva o cidade: ");
		fgets(cidade, TAM, stdin);
		corta_string(cidade);

		__fpurge(stdin);

		printf("\nEscreva o estado: ");
		fgets(estado, TAM, stdin);
		corta_string(estado);

		__fpurge(stdin);

		printf("\nEscreva o cep: ");
		fgets(cep, TAM, stdin);
		corta_string(cep);

		__fpurge(stdin);

		fputs(sobrenome, arq);
		fputs("|", arq);
		fputs(nome, arq);
		fputs("|", arq);
		fputs(endereco, arq);
		fputs("|", arq);
		fputs(cidade, arq);
		fputs("|", arq);
		fputs(estado, arq);
		fputs("|", arq);
		fputs(cep, arq);
		fputs("|", arq);

		printf("\nEscreva o sobrenome: ");
		fgets(sobrenome, TAM, stdin);
		corta_string(sobrenome);
	}

	fclose(stdin);

}