#include "biblioteca.h"

int menu(){
    int tamanho;

    printf("Programa master de ''organizar'' vetores \n");
    printf("Ele vai organizar melhor do que uma mãe organizaria o seu roupeiro\n");
    printf("Informe tamanho do vetor: ");
    //scanf("%d", &tamanho);

}

void imprimir(int *vetor, int tamanho){
    printf("\n==============================================================\n");
    printf("Vetor:\n");
    for (int i = 0; i < tamanho; ++i){
        printf("%d\t", vetor[i]);
    }
    printf("\n");
}

 int *gerar(int tamanho){
     int *vetor= malloc(sizeof(int)*tamanho);
     if(vetor==NULL){
         printf("\nNao tem memoria!\n");
         exit(0);
     }
     for (int i = 0; i < tamanho; i++){
         vetor[i]=rand()% TAM;
     }
     return vetor;
}

int *insertion(int vetor[], int tamanho){
    int temp, i, j;
    for (i = 1; i < tamanho; i++){ //i=1 Porque é preciso comparar o segundo elemento do vetor
        temp=vetor[i];
        j=i-1;
        while (j>=0 && vetor[j]>temp){
            vetor[j+1]=vetor[j]; //Se o numero que está sendo comparado for menor, então o numero atual ira assumir a posição acima do j
            j=j-1;
        }
        vetor[j+1]=temp;
    }
    return vetor;
}

int *selection(int vetor[], int tamanho){
    int troca, temp, menor, i;
    for (i = 0; i < tamanho; i++){
        menor=i;
        for (temp=i; temp<tamanho; temp++){
            if(vetor[temp]<vetor[menor]){
                menor=temp;
            }
        }
        if(menor!=i){
            troca=vetor[i];
            vetor[i]=vetor[menor];
            vetor[menor]=troca;
        }
    }
    return vetor;
}

int *quick(int vetor[],int esq, int dir){
    int pivo, temp;
    pivo=vetor[(dir+esq)/2];
    while (esq<dir){
        while(vetor[esq]<=pivo)
            esq++;
        while(vetor[dir>pivo])
            dir--;
        if(esq<dir){
            temp=vetor[esq];
            vetor[esq]=vetor[dir];
            vetor[dir]=temp;
        }
    }
    
}

//TEMPORARIO (Peguei emprestado para ver como os algoritimos se comportam com um vetor "controlado"
int *embaralhar(int *vetor, int tamanho) {
    //embaralha o vetor;
    for (int i = 0; i < tamanho; ++i) {
        troca(&vetor[i], &vetor[rand() % tamanho]);
    }
    return vetor;
}
int *PopularSqc(int *vetor, int tamanho) {
    //Popula o vetor com valores crescentes
    for (int i = 0; i < tamanho; ++i) {
        vetor[i] = i + 1;
    }
    return vetor;
}
void troca(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
//FIM TEMPORARIO
