#include "biblioteca.h"

typedef struct Pessoa{
    char nome[10];
    int idade;
    int telefone;
}Pessoas;

void *adicionar(char *pBuffer){
    int npessoa;
    memcpy(&npessoa, pBuffer, sizeof(int));

    Pessoas *ppessoa;
    pBuffer = (Pessoas *)realloc(pBuffer, (sizeof(Pessoas) * (npessoa + 1)));
    if (pBuffer == NULL){
        printf("\nErro, falta de memoria\n");
        exit(1);
    }

    ppessoa = pBuffer + (sizeof(Pessoas) * (npessoa))+sizeof(int);

    fflush(stdin);
    printf("Informe o nome: ");
    scanf("%s", ppessoa->nome);
    fflush(stdin);
    printf("Informe a idade: ");
    scanf("%d",&ppessoa->idade);
    fflush(stdin);
    printf("Informe o telefone: ");
    scanf("%d", &ppessoa->telefone);
    npessoa++;
    memcpy(pBuffer,&npessoa, sizeof(int));
    return pBuffer;
}

void *remover(char *pBuffer){
    int npessoa,apagar;
    memcpy(&npessoa, pBuffer, sizeof(int));
    Pessoas *ppessoa,*ppessoab;

    printf("\nQual pessoa voce deseja apagar: ");
    scanf("%d", &apagar);

    if (apagar > npessoa){
        printf("\n---Nenhuma pessoa cadastrada---\n");
        return pBuffer;
    }

    if (apagar == npessoa){
        pBuffer = (Pessoas *)realloc(pBuffer, (sizeof(Pessoas) * (npessoa)));
        npessoa--;
        memcpy(pBuffer, &npessoa, sizeof(int));
    }
    ppessoa = pBuffer + (sizeof(Pessoas) * (apagar - 1));
    ppessoab = pBuffer + (sizeof(Pessoas) * (apagar));
    memcpy(ppessoa, ppessoab, (sizeof(Pessoas) * (npessoa)) - (sizeof(Pessoas) * apagar));
    npessoa--;
    memcpy(pBuffer, &npessoa, sizeof(int));
    return pBuffer;
}

void listar(char *pBuffer){
    int npessoa;
    memcpy(&npessoa, pBuffer, sizeof(int));
    Pessoas *ppessoa= pBuffer+sizeof(int);
    for (int i = 0; i < npessoa; i++){
        printf("\nPessoa: %d", i + 1);
        printf("\tNome: %s", ppessoa->nome);
        printf("\tIdade: %d", ppessoa->idade);
        printf("\tTelefone: %d", ppessoa->telefone);
        ppessoa++;
    }
    printf("\n");
    return;

}

void buscar(char *pBuffer){
    int npessoa;
    memcpy(&npessoa, pBuffer, sizeof(int));
    char nome_buscado[10];
    Pessoas *ppessoa;
    ppessoa = pBuffer;
    printf("\nQual pessoa quer buscar: ");
    scanf("%s", nome_buscado);

    for (int c = 0; c < npessoa; c++){
        if (strcmp(nome_buscado, ppessoa->nome) == 0){
            printf("\nNome: %s", ppessoa->nome);
            printf("\nIdade: %d", ppessoa->idade);
            printf("\nTelefone: %d", ppessoa->telefone);
            return;
        }
        ppessoa++;
    }
    printf("\nPessoa nao cadastrada\n");
}