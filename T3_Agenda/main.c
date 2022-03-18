#include "biblioteca.h"

int main(){
    int escolha;
    void *pBuffer = malloc(sizeof(int));

    while (1){
        //Menu
        printf("=========================================================\n");
        printf("Sua Agenda\n");
        printf("1 - Adicionar informações\n");
        printf("2 - Remover informações\n");
        printf("3 - Listar\n");
        printf("4 - Buscar\n");
        printf("5 - Sair\n");
        printf("=========================================================\n");
        scanf ("%d", &escolha);

        //Executar o menu

        switch (escolha){
            case 1:
                adicionar();
                break;
            case 2:
                printf("Remova algum nome:\n");
                remover();
                break;
            case 3:
                listar();
                break;
            case 4:
                buscar();
                break;
            case 5:
                exit(0);
                break;
        }
    }
}