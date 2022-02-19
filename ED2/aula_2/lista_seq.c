#include <stdio.h>
#include <stdlib.h>
/* LISTA SEQUENCIAL --- Created on Feb 12 2022
*  AUTHOR : Flavio Souza
*  DESCRIPTION :
*       Implementação de uma lista sequencial com as operações básicas.  
*/
#define INICIO   1
#define MAXTAM   1000

typedef int APONTADOR;

typedef struct {
    int itens[MAXTAM];
    APONTADOR primeiro, ultimo;
} LISTA;

void listaVazia(LISTA *lista) { 
    lista->primeiro = INICIO;
    lista->ultimo = lista->primeiro;
}  

int estaVazia(LISTA lista) { 
    return (lista.primeiro == lista.ultimo);
}  

void insere(int x, LISTA *lista) { 
    if (lista->ultimo > MAXTAM) {
        printf("\nLISTA esta cheia");
    } else { 
        lista->itens[lista->ultimo - 1] = x;
        lista->ultimo++;
    }
}  

void retira(LISTA *lista, int x_i) { 
    int aux;
    if (estaVazia(*lista)) { 
        printf("\nA lista da Vazia");
        return;
    }

     if(x_i > lista->ultimo){
        printf("\nA posicao %i nao existe na lista", x_i);
        return;
    }

    lista->ultimo--;
    for (aux = x_i; aux < lista->ultimo; aux++){
        lista->itens[aux - 1] = lista->itens[aux];
    }
    lista->itens[lista->ultimo] = 0;
    printf("\nItem da posicao %i removido.", x_i);
}  

void imprime(LISTA lista) { 
    int aux;

    if (estaVazia(lista)) { 
        printf("\nLista esta VAZIA");
        return;
    }

    printf("\n|");
    for (aux = lista.primeiro - 1; aux <= (lista.ultimo - 2); aux++){
        printf("%d|", lista.itens[aux]);
    }    
} 

int localizar(LISTA *lista, int valor){
    /*Crie uma funcao capaz de localizar um item de valor na lista*/
    return 0;
}

int main(int argc, char *argv[]) {   
    LISTA lista;
    
    listaVazia(&lista);

    insere(10, &lista);
    insere(109, &lista);
    insere(7, &lista);
    insere(21, &lista);
    
    imprime(lista);

    retira(&lista, 2);
    retira(&lista, 109);
    imprime(lista);

    return 0;
}