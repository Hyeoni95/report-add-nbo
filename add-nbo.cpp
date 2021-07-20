#pragma once

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <netinet/in.h>

uint32_t ReadFile(FILE*);

uint32_t ReadFile(FILE *fp){

	uint32_t *buffer = NULL;

	buffer = (uint32_t *)malloc(sizeof(uint32_t));

	fread(buffer, 1, 4, fp);

	uint32_t num = ntohl(*buffer);

	free(buffer);
	fclose(fp);

	return num;
}

int main(int argc, char *argv[]){
	
	FILE *fp1, *fp2;

	if(argc < 3){
		fprintf(stderr, "SYNTAX: add-nbo file1 file2\n");
		exit(1);
	}
	if(!(fp1 = fopen(argv[1], "r"))){
		fprintf(stderr, " open error : file1\n");
		exit(1);
	}
	if(!(fp2 = fopen(argv[2], "r"))){
		fprintf(stderr, "open error : file2\n");
	}

	uint32_t num1 = ReadFile(fp1);
	uint32_t num2 = ReadFile(fp2);

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1, num1, num2, num2, (num1+num2), (num1+num2));

	return 0;
}

