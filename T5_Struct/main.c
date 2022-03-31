#include "biblioteca.h"

int main(){
    setbuf(stdout, 0);
    int escolha;
    int npessoa = 0;
    void *pBuffer = malloc(sizeof(int));
    memcpy(pBuffer, &npessoa,sizeof(int));

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
                pBuffer=adicionar(pBuffer);
                break;
            case 2:
                listar(pBuffer);
                free(pBuffer);
                exit(0);
                break;
            default:
                printf("\nOpcao invalida\n");
        }
    }
}