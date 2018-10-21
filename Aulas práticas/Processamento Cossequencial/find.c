#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>

#define TAM 20

void corta_string(char* str){
	str[strlen(str)-1] = '\0';
}

int get_rec(FILE* arq, char* buffer){
	int lenght;

	if (fread(&lenght, sizeof(int), 1, arq) == 0)
		return 0;
	fread(buffer, sizeof(char), lenght, arq);
	buffer[lenght] = '\0';
	return lenght;
}

int main(){
	FILE *input;
	char nome_arquivo[TAM], search_key[TAM], buffer[3*TAM], *last, *field;
	int matched = 0;
	int rec_lenght;

	printf("Escreva o nome do arquivo: ");
	fgets(nome_arquivo, TAM, stdin);
	corta_string(nome_arquivo);
	input = fopen(nome_arquivo, "r");

	printf("Escreva o sobrenome para procura: ");
	fgets(search_key, TAM, stdin);
	corta_string(search_key);
	while(!matched && (rec_lenght = get_rec(input, buffer)) > 0){
		last = strtok(buffer, "|");
		if(strcmp(last, search_key) == 0)
			matched = 1;
	}

	if(matched){
		printf("CAMPO:\n \t%s\n", last);
		field = strtok(NULL, "|");
		while(field != NULL){
			printf("\t%s\n", field);
			field = strtok(NULL, "|");
		}
	}

	fclose(input);
}