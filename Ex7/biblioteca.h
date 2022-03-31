#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[30];
    int idade;
    int altura;
} Pessoa;

void adicionar(int *pBuffer);
void remover(int *pBuffer);
void listar(int *pBuffer);
