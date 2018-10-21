#include <stdio.h>
#include <string.h>
#define TAM 20

void corta_string(char* frase){
	frase[strlen(frase)-1] = '\0';
}

int readfield(FILE* input, char* str){
	int i = 0;
	char ch = fgetc(input);
	while(ch != EOF && ch != '|'){
		str[i] = ch;
		i++;
		ch = fgetc(input);
	}
	str[i] = '\0';
	return i;
}

int main(){

	char nome_arquivo[TAM], retorno[TAM];
	FILE *input;
	int field_length, i = 0;

	printf("Escreva o nome do arquivo a ser lido: ");
	fgets(nome_arquivo, TAM, stdin);
	input = fopen(nome_arquivo, "r");

	field_length = readfield(input, retorno);
	while(field_length > 0){
		printf("Campo #%d: %s\n", i+1, retorno);
		field_length = readfield(input, retorno);
		i++;
	}
	fclose(input);
}