#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int menu();
char *addnome(char *nome);
void rnome();
void listarnome(char *nome);


int main(){
    int escolha;
    char *nome = (char*)malloc(sizeof(char) *2);
    nome[0]= '\0';

    while (1){
    //Menu
    printf("=========================================================\n");
    printf("Sua Agenda\n");
    printf("1 - Adicionar nome:\n");
    printf("2 - Remover nome:\n");
    printf("3 - Listar\n");
    printf("4 - Sair\n");
    printf("=========================================================\n");
    scanf ("%d", &escolha);

    //Executar o menu
   
        switch (escolha){
            case 1: 
                nome=addnome(nome);
                break;
            case 2:
                printf("Remova algum nome:\n");
                rnome(nome);
                break;
            case 3: 
                listarnome(nome);
                break;
            case 4:
                exit(0);
                break;
        }
    }
}

char *addnome(char *nome){
    char nomeadd[15];
    printf("Adicione o nome:\n");
    scanf("%s", nomeadd);

    strcat(nomeadd, "-");

    int tamnome;
    tamnome = strlen(nomeadd)+1;

    int tamagenda;
    tamagenda = strlen(nome);

    nome = (char*) realloc(nome, (tamnome + tamagenda) * sizeof(char));
    if (nome == NULL){
        printf("Erro");
        exit(1);
    }

    strcat(nome, nomeadd);
    return nome;

}

void rnome(){
//não sei como fazer ela :(
}

void listarnome(char *nome){
    
    for (int i = 0; nome[i]!= '\0' ; i++){
        if (nome[i]!='-'){
            printf("%c", nome[i]);
        }
        else{
            printf("\n");
        }  
    }
     
}