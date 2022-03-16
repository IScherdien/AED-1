#include "biblioteca.h"


void addnome(){
    nome = (char*)malloc(sizeof(char) *tamnome);
}

void rnome(){

}

void listarnome(){
    char *temp;
    
    printf("Listando nomes \n");
    for (i=0; i<n; i++)
    printf("%s\n", p[i])
}