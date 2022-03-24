#include "biblioteca.h"

int main(){
    int escolha;
    int npessoa = 0;
    void *Buffer = malloc(sizeof(int));
    memcpy(Buffer, &npessoa,sizeof(int));

    while (1){
        //Menu
        printf("=========================================================\n");
        printf("Adicionar uma pessoa?\n");
        printf("1- Sim\n");
        printf("2- Nao\n");
        printf("=========================================================\n");
        scanf("%d", &escolha);

        //Menu
        switch (escolha){
            case 1:
                Buffer=adicionar(Buffer);
                break;
            case 2:
                listar(Buffer);
                free(Buffer);
                exit(0);
                break;
            default:
                printf("\nOpcao invalida\n");
        }
    }
}