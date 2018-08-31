#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>

#define TAM_REG 64

typedef struct data{
	char last_name[TAM_REG], first_name[TAM_REG], addres[TAM_REG], city[TAM_REG], state[TAM_REG], zip[TAM_REG];
	int REC_LENGTH;
}DATA;

int get_offset(int rrn){
	return rrn*TAM_REG+4;
}

void corta_string(char* str){
	str[strlen(str)-1] = '\0';
}

void concatenate_and_add_pipe(char* str, char* BUFFER){
	strcat(str, "|");
	strcat(BUFFER, str);
}

void ler_dados(DATA* reg, char* BUFFER){
	BUFFER[0] = '\0';
	printf("Escreva o sobrenome: ");
	fgets(reg->last_name, TAM_REG, stdin);
	corta_string(reg->last_name);
	concatenate_and_add_pipe(reg->last_name, BUFFER);
	
	printf("Escreva o nome: ");
	fgets(reg->first_name, TAM_REG, stdin);
	corta_string(reg->first_name);
	concatenate_and_add_pipe(reg->first_name, BUFFER);

	printf("Escreva o endereço: ");
	fgets(reg->addres, TAM_REG, stdin);
	corta_string(reg->addres);
	concatenate_and_add_pipe(reg->addres, BUFFER);
	__fpurge(stdin);

	printf("Escreva a cidade: ");
	fgets(reg->city, TAM_REG, stdin);
	corta_string(reg->city);
	concatenate_and_add_pipe(reg->city, BUFFER);

	printf("Escreva o estado: ");
	fgets(reg->state, TAM_REG, stdin);
	corta_string(reg->state);
	concatenate_and_add_pipe(reg->state, BUFFER);

	printf("Escreva o cep: ");
	fgets(reg->zip, TAM_REG, stdin);
	corta_string(reg->zip);
	concatenate_and_add_pipe(reg->zip, BUFFER);

	for(int i=strlen(BUFFER); i<TAM_REG+1; i++)
		BUFFER[i] = '\0';
}

void get_rec(FILE* arq, char* buffer){
	int lenght;

	fread(buffer, sizeof(char), TAM_REG, arq);
}

void print_buffer(char* buffer){
	char *field = strtok(buffer, "|");

	printf("Campo: \n");
	while(field != NULL){
		printf("\t%s\n", field);
		field = strtok(NULL, "|");
	}
}

int main(){
	FILE *filename;
	char nome_arquivo[TAM_REG], buffer[TAM_REG+1], modificar;
	int header, opt, pos_grav, rrn;
	DATA dados;

	printf("Escreva o nome do arquivo: ");
	fgets(nome_arquivo, TAM_REG, stdin);
	corta_string(nome_arquivo);

	filename = fopen(nome_arquivo, "r+");
	if(filename == NULL){
		filename = fopen(nome_arquivo, "w+");
		header = 0;
		fwrite(&header, sizeof(int), 1, filename);
	}else{
		fread(&header, sizeof(int), 1, filename);
	}

	printf("Header: %d\n\n", header);
	do{
		printf("\nOpções:\n\n");
		printf("\t[1] Adicionar um registro ao final do arquivo\n");
		printf("\t[2] Recuperar um registro por RRN para alterações\n");
		printf("\t[0] Terminar programa\n\n");
		printf("Digite o número de sua escolha: ");
		scanf("%d", &opt);
		__fpurge(stdin);

		switch(opt){
			case 1:
				ler_dados(&dados, buffer);
				pos_grav = get_offset(header);
				fseek(filename, pos_grav, SEEK_SET);
				fwrite(buffer, sizeof(char), TAM_REG, filename);
				header++;
				fseek(filename, 0, SEEK_SET);
				fwrite(&header, sizeof(int), 1, filename);
			break;

			case 2:
				printf("Insira o RRN: ");
				scanf("%d", &rrn);
				__fpurge(stdin);
				if(rrn <= header){
					fseek(filename, get_offset(rrn), SEEK_SET);
					get_rec(filename, buffer);
					print_buffer(buffer);
					printf("\nDeseja modificar esse registro? [s]/[n]");
					scanf("%c", &modificar);
					__fpurge(stdin);
					if(modificar == 'S' || modificar == 's'){
						ler_dados(&dados, buffer);
						fseek(filename, get_offset(rrn), SEEK_SET);
						fwrite(buffer, sizeof(char), 64, filename);
					}
				}else printf("Não há esse RRN no arquivo\n");
		}
	}while(opt != 0);
}

