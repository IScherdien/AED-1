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
        printf("Sua Agenda\n");
        printf("1- Adicionar informações\n");
        printf("2- Remover informações\n");
        printf("3- Listar\n");
        printf("4- Buscar\n");
        printf("5- Sair\n");
        printf("=========================================================\n");
        scanf("%d", &escolha);

        //Executar o menu

        switch (escolha){
            case 1:
                pBuffer=adicionar(pBuffer);
                break;
            case 2:
                pBuffer=remover(pBuffer);
                break;
            case 3:
                listar(pBuffer);
                break;
            case 4:
                buscar(pBuffer);
                break;
            case 5:
                exit(0);
                break;
        }
    }
}