#include "biblioteca.h"

int menu(void *pBuffer){
    //Menu
    printf("=========================================================\n");
    printf("Sua Agenda\n");
    printf("1- Adicionar Pessoas\n");
    printf("2- Remover Pessoas\n");
    printf("3- Listar\n");
    printf("4- Buscar\n");
    printf("5- Sair\n");
    printf("=========================================================\n");
    scanf("%d", &pBuffer);

    return (pBuffer);
}

void adicionar(void *head){
    void *nodo = malloc((sizeof(int) * 2) + (sizeof(void*) * 2) + (sizeof(char) * 15));
        if(nodo==NULL){
            printf("\nNao tem memoria!\n");
            exit(0);
        }
    void **anterior = nodo;
    char *nome = nodo + sizeof(void*);
    int *idade = nome + (sizeof(char) * 15);
    int *telefone = idade + (sizeof(int));
    void *start = head;

    fflush(stdin);
    printf("Informe o nome:");
    scanf("%s", nome);
    fflush(stdin);
    printf("Informe a idade:");
    scanf("%d", idade);
    fflush(stdin);
    printf("Informe o telefone:");
    scanf("%d", telefone);

    if(head==NULL){
        return nodo;
    }else{
        void **proximo=head+((sizeof(int) * 2) + (sizeof(void*)) + (sizeof(char) * 15));
        void *temp;
        while(*proximo!=NULL){
            temp=*proximo;
            proximo=temp+((sizeof(int) * 2) + (sizeof(void) * 2) + (sizeof(char) * 15));
        }
        *proximo=nodo;
    }

}

void remover(){
    printf("oi2");
}

void listar(void *head){
    void **proximo=head+((sizeof(int) * 2) + (sizeof(void*)) + (sizeof(char) * 15));
    void *temp;
    char *nome = head+sizeof(void*);
    int *idade, *telefone;

    if (*proximo==NULL){
        printf("Escreve algo nessa m****");
    }
    do{
        temp=*proximo;
        proximo = temp + ((sizeof(int) * 2) + (sizeof(void) * 2) + (sizeof(char) * 15));
        nome = head + sizeof(void*);
        idade = nome + (sizeof(char) * 15);
        telefone = idade + sizeof(int);
        printf("\"\\nNome: %s\\nIdade: %d\\nTelefone: %d\\n\"", nome, *idade, *telefone);
    }while(*proximo!=NULL);

    /* if (*proximo==NULL){
        printf("Escreve algo nessa m****");
    }
    else{
        printf("\nNome: %s\nIdade: %d\nTelefone: %d\n", nome, idade, telefone);
    }while(*proximo!=NULL); */

    printf("\n");
}

void buscar(){
    printf("oi4");
}