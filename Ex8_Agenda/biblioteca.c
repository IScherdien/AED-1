#include "biblioteca.h"

#define tamanho (sizeof(int)*2)+(sizeof(void*)*2)+(sizeof(char)*15)
#define final tamanho-sizeof(void*)

int menu(void *pBuffer) {
    int *input=pBuffer;

    //Menu
    printf("\n=========================================================\n");
    printf("Sua Agenda\n");
    printf("1- Adicionar Pessoas\n");
    printf("2- Remover Pessoas\n");
    printf("3- Listar\n");
    printf("4- Buscar\n");
    printf("5- Sair\n");
    printf("=========================================================\n");
    scanf("%d", &input[0]);

    return (int)input[0];
}

void *adicionar(void *head){

    void *nodo = malloc(tamanho);
    if(nodo==NULL){
        printf("\nNao tem memoria!\n");
        exit(1);
    }
    void **anterior=nodo;
    char *nome=nodo+sizeof(void*);
    int *idade=nome+(sizeof(char)*15);
    int *telefone=(nodo+final)-sizeof(int);
    void **proxnodo=nodo+final;
    *proxnodo = NULL;
    *anterior = NULL;

    fflush(stdin);
    printf("\nInforme o nome:");
    scanf("%s", nome);
    fflush(stdin);
    printf("\nInforme a idade:");
    scanf("%d", idade);
    fflush(stdin);
    printf("\nInforme o telefone:");
    scanf("%d", telefone);

    if(head==NULL){
        *anterior=head;
        return nodo;
    }else{
        void *temp=head;
        temp+=final;
        void **proximo=temp;
        while(*proximo!=NULL){
            temp=*proximo;
            proximo=temp+final;
        }
        *anterior=proximo;
        *proximo=nodo;
        return head;
    }
}

void remover(void *head){
    char *encontrar= malloc(sizeof(char) * 15);
    if(encontrar==NULL){
        exit(1);
    }

    printf("Insira o nome da pessoa que voce quer remover.");
    scanf("%s",encontrar);



    void **proximo=head;
    void *temp;
    char *nome=head+sizeof(void*);
    int *idade, *telefone;

    if (proximo==NULL){
        printf("Agenda vazia.");
        return;
    }
    do{
        temp=proximo;
        nome=temp+sizeof(void*);
        idade=nome+(sizeof(char) * 15);
        telefone=(temp+final)-sizeof(int);
        temp=proximo;
        proximo=temp+final;
        proximo=*proximo;
        if(strcmp(encontrar, nome) == 0){
            void **primeiro,**terceiro;
            temp=proximo;
            temp-=final;
            primeiro=temp;
            primeiro=*primeiro;
            temp=primeiro;
            temp+=final;
            primeiro=temp;
            *primeiro=*proximo;
            /**primeiro=temp;
            primeiro=*primeiro;
            temp=primeiro;
            temp+=final;
            primeiro=temp;
            //temp=proximo;
            *primeiro=temp;

            terceiro=proximo;
            temp-=final;
            *terceiro=temp;**/
        }
    }while(proximo!=NULL);
    printf("\nNao foi possivel remover esta pessoa.\n");//Caso não encontre o nome na lista
}

void listar(void *head){
    void **proximo=head;
    void *temp;
    char *nome=head+sizeof(void*);
    int *idade, *telefone;

    if (proximo==NULL){
        printf("Agenda vazia.");
        return;
    }
    do{
        temp=proximo;
        nome=temp+sizeof(void*);
        idade=nome+(sizeof(char) * 15);
        telefone=(temp+final)-sizeof(int);
        temp=proximo;
        proximo=temp+final;
        proximo=*proximo;
        printf("\nNome: %s\nIdade: %d\nTelefone: %d\n", nome, *idade, *telefone);
    }while(proximo!=NULL);
}

void buscar(void* head){
    char *encontrar= malloc(sizeof(char) * 15);
    if(encontrar==NULL){
        exit(1);
    }

    printf("\nQuem voce quer buscar? Insira o nome.\n");
    scanf("%s",encontrar);
    void **proximo=head;
    void *temp;
    char *nome=head+sizeof(void*);
    int *idade, *telefone;

    if (proximo==NULL){
        printf("Agenda vazia.");
        return;
    }
    do{
        temp=proximo;
        nome=temp+sizeof(void*);
        idade=nome+(sizeof(char) * 15);
        telefone=(temp+final)-sizeof(int);
        temp=proximo;
        proximo=temp+final;
        proximo=*proximo;
        if(strcmp(encontrar, nome) == 0){
            printf("\nNome: %s\nIdade: %d\nTelefone: %d\n", nome, *idade, *telefone);
            return;
        }
    }while(proximo!=NULL);
    printf("\nNao foi possivel buscar esta pessoa.\n");
}