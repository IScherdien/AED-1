#include "biblioteca.h"

int main(){
    setbuf(stdout, 0);
    void *pBuffer = malloc(sizeof(int) * 2);
        if(pBuffer==NULL){
            printf("\nNao tem memoria!\n");
            exit(0);
        }
    void *head = malloc(sizeof(void*));
        if(head==NULL){
            printf("\nNao tem memoria!\n");
            exit(0);
        }
        head=NULL;
    //Executar o menu
    while(1){
        switch (menu(pBuffer)){
            case 1:
                adicionar(head);
                break;
            case 2:
                remover();
                break;
            case 3:
                listar(head);
                break;
            case 4:
                buscar();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Escolha invalida\n");
                break;
        }
    }
}
