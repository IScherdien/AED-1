#include "biblioteca.h"
/*Exercício:
1- Implementar os algoritmos de ordenação Insertion Sort, Selection Sort, Quick Sort e Merge Sort.
2- O programa deve solicitar o tamanho do vetor de números (n) que será ordenado
3- O programa deve preencher um vetor de tamanho n com números aleatórios. Usar srand(time(NULL)); no inicio do programa.*/


int main(){
    srand(time(NULL));
    int tamanho=14;
    int *vetor = (int *) malloc(tamanho * sizeof(int));
    if (vetor == NULL) {
        exit(0);
    }

    //vetor=embaralhar(gerar(tamanho), tamanho);
    vetor=embaralhar(PopularSqc(vetor, tamanho), tamanho);
    imprimir(vetor,tamanho);

    //vetor=insertion(vetor,tamanho);
    //vetor=selection(vetor,tamanho);
    vetor=quick(vetor, 0, tamanho-1);
    imprimir(vetor,tamanho);

    /*while(1){
        switch(menu()){
            case 1:
                insertion(vetor, tamanho);
                break;
            case 2:
                printf("Selection Sort\n");
                break;
            case 3:
                printf("Quick Sort\n");
                break;
            case 4:
                printf("Merge Sort\n");
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Escolha invalida\n");
                break;
        }
    }*/
}