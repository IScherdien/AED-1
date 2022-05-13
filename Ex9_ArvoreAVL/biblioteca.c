#include "biblioteca.h"

Nodo *Teste(Nodo *head, int *V, int nNodos) {
    for (int i = 0; i < nNodos; ++i) {
        head = inserir(V[i], head);
    }
    return head;
}

Nodo *gerar(int numero, Nodo *nod) {
    for (int i = 0; i < numero; ++i) {
        nod = inserir(rand() % 100, nod);
    }
    return nod;
}

Nodo *criar(int valor) {
    Nodo *folha;
    folha = malloc(sizeof(Nodo));
    if (folha == NULL) {
        printf("\nNao tem memoria!\n");
        exit(0);
    }
    folha->valor = valor;
    folha->altura = 1;
    folha->esq = NULL;
    folha->dir = NULL;
    return folha;
}

int fb(Nodo *nodofb) {
    int dir = 0, esq = 0;
    if (nodofb->esq != NULL) {
        esq = nodofb->esq->altura;
    }
    if (nodofb->dir != NULL) {
        dir = nodofb->dir->altura;
    }
    return esq - dir;
}

Nodo *rotdireita(Nodo *origem) {
    if (origem == NULL) {
        return origem;
        exit(18);
    }
    Nodo *temp = origem->esq;

    origem->esq = temp->dir;
    temp->dir = origem;

    origem->altura= altura(origem);
    temp->altura= altura(temp);

    return temp;
}

Nodo *rotesquerda(Nodo *origem) {
    if (origem == NULL) {
        return origem;
        exit(18);
    }

    Nodo *temp = origem->dir;

    origem->dir = temp->esq;
    temp->esq = origem;

    origem->altura= altura(origem);
    temp->altura= altura(temp);

    return temp;
}

Nodo *inserir(int valor, Nodo *nod) {

    if (nod == NULL) {
        return criar(valor);
    }

    if (valor == nod->valor) {
        printf("Este numero já foi incluso");
        return nod;
    }

    if (valor > nod->valor) {
        nod->dir = inserir(valor, nod->dir);
        nod->altura = nod->dir->altura + 1;
    } else if (valor < nod->valor) {
        nod->esq = inserir(valor, nod->esq);
        nod->altura = nod->esq->altura + 1;
    }

    int fbi = fb(nod);
    if (fbi > 1) {
        if (valorzero(nod) < valorzero(nod->dir)) { //Esquerda direita
            nod->esq = rotesquerda(nod->esq);
            return rotdireita(nod);
        } else {
            return rotdireita(nod); //Simples direita
        }
    } else if (fbi < -1) {
        if (valorzero(nod) > valorzero(nod->esq)) { //Direita esquerda
            nod->dir = rotdireita(nod->dir);
            return rotesquerda(nod);
        } else {
            return rotesquerda(nod); //Simples esquerda
        }
    }
    return nod;
}

int valorzero(Nodo *nod) {
    return (nod != NULL) ? nod->valor : 0;
}

/*Função do slide da aula 8*/
int ArvoreArvl(Nodo *nod) {
    int fbi;
    if (nod == NULL)
        return 1;
    if (!ArvoreArvl(nod->esq))
        return 0;
    if (!ArvoreArvl(nod->dir))
        return 0;
    fbi = fb(nod);
    if ((fbi > 1) || (fbi < -1))
        return 0;
    else
        return 1;
}

/* Utilizei a função "imprimir" deste site:
  https://www.geeksforgeeks.org/avl-tree-set-1-insertion/*/
void printavl(Nodo *nod, int space) {
    // Base case
    if (nod == NULL)
        return;
    // Increase distance between levels
    space += COUNT;
    // Process dir child first
    printavl(nod->dir, space);
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d-(%d)\n", nod->valor, nod->altura);
    // Process esq child
    printavl(nod->esq, space);
}

void print(Nodo *nod) {
    // Pass initial space count as 0
    printavl(nod, 0);
}


//Arthur
int altura(Nodo *head) {

    if (head == NULL) {
        return 0;
    }

    return 1 + maior(altura(head->esq), altura(head->dir));
}

int maior(int a, int b) {
    return (a > b) ? a : b;
}
