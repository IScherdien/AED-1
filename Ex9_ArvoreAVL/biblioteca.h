#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COUNT 10 //para o print

typedef struct nod{
    int valor, altura;
    struct nod *esq;
    struct nod *dir;
}Nodo;

Nodo *gerar(int numero, Nodo *nod);
Nodo *criar(int valor);
Nodo *rotdireita(Nodo *origem);
Nodo *rotesquerda(Nodo *origem);
int fb(Nodo *nodofb);
Nodo *inserir(int valor, Nodo *nod);
int valorzero(Nodo *nod);

void printavl(Nodo *nod, int space);
void print(Nodo *nod);