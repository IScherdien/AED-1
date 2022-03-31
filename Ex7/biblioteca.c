#include "biblioteca.h"

Pessoa pessoas[10];

void adicionar(int *pBuffer){


    Pessoa *ppessoa;
    ppessoa = pessoas + (sizeof(Pessoa) *pBuffer[0]);

    fflush(stdin);
    printf("Informe o nome:");
    scanf("%s", ppessoa->nome);
    fflush(stdin);
    printf("Informe a idade:");
    scanf("%d",&ppessoa->idade);
    fflush(stdin);
    printf("Informe altura:");
    scanf("%d", &ppessoa->altura);
    pBuffer[0]++;
}

void remover(int *pBuffer){
    printf("\nQual pessoa voce deseja apagar:");
    fflush(stdin);
    scanf("%d", &pBuffer[1]);

    Pessoa *ppessoa,*ppessoab;

    ppessoa = pessoas + sizeof(Pessoa) * (pBuffer[1]-1);
    ppessoab = pessoas + sizeof(Pessoa) * (pBuffer[1]);
    memcpy(ppessoa, ppessoab,(pBuffer[0]-pBuffer[1])*sizeof(Pessoa));
    pBuffer[0]--;
}

void listar(int *pBuffer){
    Pessoa *ppessoa;
    for (pBuffer[1] = 0; pBuffer[1] < pBuffer[0]; pBuffer[1]++){
        ppessoa = pessoas + (sizeof(Pessoa) *pBuffer[1]);
        printf("\nPessoa: %d", pBuffer[1] + 1);
        printf("\nNome: %s", ppessoa->nome);
        printf("\nIdade: %d", ppessoa->idade);
        printf("\nAltura: %d", ppessoa->altura);
    }
    printf("\n");
    return;

}