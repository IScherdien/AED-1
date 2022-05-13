#include "biblioteca.h"

int main(){
    int teste[] = {20, 4, 3, 9, 26, 15};

    int numero=6;
    srand(time(NULL));
    printf("Bem vinde ao programa Arveres\n");
    printf("O jardineiro eh Jesus e as Arveres somos Nozes\n");
    printf("Quantos nodos voce quer adicionar a Arvere?\n");
    scanf("%d", &numero);
    Nodo *nod =NULL;
    nod=gerar(numero,nod);
    //nod= Teste(NULL, teste, 6);

    printf("Visualização da Arvore\nEla ocorre da esquerda para a direita");
    print(nod);
    printf("\nE avl? %s", (ArvoreArvl(nod)) ? "Sim" : "Não");
}


