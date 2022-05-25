#include "biblioteca.h"

int menu(){
    int escolha, tamanho;

    printf("Programa master de ''organizar'' vetores \n");
    printf("Ele vai organizar melhor do que uma mãe organizaria o seu roupeiro\n");
    printf("Informe tamanho do vetor: ");
    //scanf("%d", &tamanho);
    tamanho=4;

    srand(time(NULL));
    gerar(tamanho);

    printf("\n======================================\n");
    printf("Argoritmos de ordenacao:\n");
    printf("1- Insertion Sort\n");
    printf("2- Selection Sort\n");
    printf("3- Quick Sort\n");
    printf("4- Merge Sort\n");
    printf("5- Sair\n");
    printf("======================================\n");
    printf("Escolha qual será a ordenacao: ");
    scanf("%d", &escolha);
    return escolha;

}

 int gerar(int tamanho){
     int vetor[tamanho];
     printf("\n======================================\n");
     printf("Vetor que será ordenado:\n");
     for (int i = 0; i < tamanho; i++){
         vetor[i]=rand()%15;
         printf("%d  ", vetor[i]);
     }
}

int insertion(int vetor[], int tamanho){
    int vis, j;
    for (int i = 1; i < tamanho; i++){
        vis=vetor[i];
        j=i-1;
        while (j>=0 && vis<vetor[j]){
            vetor[j+1]=vetor[j];
            j=j-1;
        }
    } printf("%d  ", vetor[j]);
    return vetor[j];
}



