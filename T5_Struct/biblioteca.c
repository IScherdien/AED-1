#include "biblioteca.h"

typedef struct Pessoa{
    char nome[10];
    int idade;
    float altura;
}Pessoas;

void *adicionar(char *Buffer){
    int npessoa;
    Pessoas *ppessoa;
    Buffer = (Pessoas *)realloc(Buffer, (sizeof(Pessoas) * (npessoa + 1)));
    if (Buffer == NULL){
        printf("\nErro, falta de memoria\n");
        exit(1);
    }

    ppessoa = Buffer + (sizeof(Pessoas) * (npessoa))+sizeof(int);

    fflush(stdin);
    printf("Informe o nome: ");
    scanf("%s", ppessoa->nome);
    fflush(stdin);
    printf("Informe a idade: ");
    scanf("%d",&ppessoa->idade);
    fflush(stdin);
    printf("Informe a altura: ");
    scanf("%f", &ppessoa->altura);
    npessoa++;
    memcpy(Buffer,&npessoa, sizeof(int));
    return Buffer;
}

void listar(char *pBuffer){
    int npessoa;
    memcpy(&npessoa, pBuffer, sizeof(int));
    Pessoas *ppessoa= pBuffer+sizeof(int);
    for (int i = 0; i < npessoa; i++){
        printf("\nPessoa: %d", i + 1);
        printf("\nNome: %s", ppessoa->nome);
        printf("\nIdade: %d", ppessoa->idade);
        printf("\nAltura: %.2f", ppessoa->altura);
        ppessoa++;
    }
    printf("\n");
    return;

}