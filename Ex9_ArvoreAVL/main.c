#include "biblioteca.h"

int main(){
    int numero;
    srand(time(NULL));
    printf("Bem vinde ao programa Arveres\n");
    printf("O jardineiro eh Jesus e as Arveres somos Nozes\n");
    printf("Quantos nodos voce quer adicionar a Arvere?\n");
    scanf("%d", &numero);
    Nodo *nod =NULL;
    nod=gerar(numero,nod);
    print(nod);

    printf("Visualização da Arvore\nEla ocorre da esquerda para a direita");
    print(nod);
}


