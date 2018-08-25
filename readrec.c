#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>

#define TAM 20

void corta_string(char *str){
	str[strlen(str)-1] = '\0';
}

int get_rec(FILE* arq, char* buffer){
	int lenght;

	fread(&lenght, sizeof(int), 1, arq);
	if(feof(arq)) 
		return 0;
	fread(buffer, sizeof(char), lenght, arq);
	return lenght;
}

int main(){
	FILE *input;
	char nome_arquivo[TAM], buffer[TAM], *field;
	int scan_pos = 0, rec_lenght;

	printf("Escreva o nome do arquivo: ");
	fgets(nome_arquivo, TAM, stdin);
	corta_string(nome_arquivo);
	input = fopen(nome_arquivo, "r");

	rec_lenght = get_rec(input, buffer);
	printf("REC_LENGHT: %d\n", rec_lenght);
	while(rec_lenght > 0){
		field = strtok(buffer, "|");
		while(field != NULL){
			printf("\t%s\n", field);
			field = strtok(NULL, "|");
		}
		rec_lenght = get_rec(input, buffer);
	}
	fclose(input);
}