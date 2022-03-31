#include "biblioteca.h"

int main(){
    setbuf(stdout, 0);
    int *pBuffer=NULL;
    pBuffer= malloc(sizeof(int)*3);
    if(pBuffer==NULL){
        exit(1);
    }

    pBuffer[0]=0;

    while (1){
        //Menu
        printf("=========================================================\n");
        printf("Sua Agenda\n");
        printf("1- Adicionar informacoes\n");
        printf("2- Remover informacoes\n");
        printf("3- Listar\n");
        printf("4- Sair\n");
        printf("=========================================================\n");
        fflush(stdin);
        scanf("%d", &pBuffer[1]);

        //Executar o menu

        switch (pBuffer[1]){
            case 1:
                adicionar(pBuffer);
                break;
            case 2:
                remover(pBuffer);
                break;
            case 3:
                listar(pBuffer);
                break;
            case 4:
                exit(0);
                break;
        }
    }
}