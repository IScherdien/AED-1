#include "biblioteca.h"

int main(){
int escolha;
char *nome = (char*)malloc(sizeof(char) *tamnome);

//Menu
printf("=========================================================");
printf("Sua Agenda");
printf("1 - Adicionar nome:\n");
printf("2 - Remover nome:\n");
printf("3 - Listar\n");
printf("4 - Sair\n");
printf("=========================================================");
scanf ("%d", &escolha);

//Executar o menu
while (1){
    switch (escolha){
        case 1: 
            printf("Adicione o nome:\n");
            addnome(&nome, &tam);
            break;
        case 2:
            printf("Remova algum nome:\n");
            rnome(&nome, &tam);
            break;
        case 3: 
            printf("Listar" );
            listarnome(&nome, &tam);
            break;
        case 4:
            exit(0);
            break;
        }
    }


}