#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>

#define TAM 20

typedef struct data{
	char last_name[TAM], first_name[TAM], addres[TAM], city[TAM], state[TAM], zip[TAM];
	int REC_LENGTH;
}DATA;

/* Não é necessário o uso de uma struct, os dados podem ser lidos
   direto na main, usei por opção.
*/

void corta_string(char *str){
	str[strlen(str)-1] = '\0';
}

void concatenate_and_add_pipe(char* str, char* BUFFER){
	strcat(str, "|");
	strcat(BUFFER, str);
}

int main(){
	char nome_arquivo[TAM], last_name[TAM], BUFFER[10*TAM];
	FILE *arq;
	DATA data;
	char tamanho_buffer[3];
 
	printf("Escreva o nome do arquivo: ");
	fgets(nome_arquivo, TAM, stdin);
	corta_string(nome_arquivo);

	arq = fopen(nome_arquivo, "w");

	printf("Escreva o sobrenome: ");
	fgets(data.last_name, TAM, stdin);
	corta_string(data.last_name);

	while(strlen(data.last_name) > 0){
		BUFFER[0] = '\0';
		concatenate_and_add_pipe(data.last_name, BUFFER);
		
		printf("Escreva o nome: ");
		fgets(data.first_name, TAM, stdin);
		corta_string(data.first_name);
		concatenate_and_add_pipe(data.first_name, BUFFER);

		printf("Escreva o endereço: ");
		fgets(data.addres, TAM, stdin);
		corta_string(data.addres);
		concatenate_and_add_pipe(data.addres, BUFFER);
		__fpurge(stdin);

		printf("Escreva a cidade: ");
		fgets(data.city, TAM, stdin);
		corta_string(data.city);
		concatenate_and_add_pipe(data.city, BUFFER);

		printf("Escreva o estado: ");
		fgets(data.state, TAM, stdin);
		corta_string(data.state);
		concatenate_and_add_pipe(data.state, BUFFER);

		printf("Escreva o cep: ");
		fgets(data.zip, TAM, stdin);
		corta_string(data.zip);
		concatenate_and_add_pipe(data.zip, BUFFER);

		data.REC_LENGTH = strlen(BUFFER);
		printf("%d\n", data.REC_LENGTH);

		
		//fprintf(arq, "%d", data.REC_LENGTH); //Método usado para imprimir um inteiro 
											//que pode ser lido no arquivo de texto
		
		fwrite(&(data.REC_LENGTH), sizeof(int), 1, arq);
		fwrite(BUFFER, sizeof(char), strlen(BUFFER), arq);

		printf("Escreva o sobrenome: ");
		fgets(data.last_name, TAM, stdin);
		corta_string(data.last_name);
	}

	fclose(arq);
}