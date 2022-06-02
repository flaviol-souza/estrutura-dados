#include <stdio.h>
#include <stdlib.h>
#include "structure/list.h"

/*
*   (Exercício 2.3) Implemente um algoritmo para excluir um nó no meio de uma lista encadeada (ou seja, qualquer nó, exceto o primeiro e o último nó, não necessariamente o meio exato), com acesso apenas a esse nó. EXEMPLO 
*   Entrada: o nó c da lista encadeada a - >b- >c - >d - >e- >f 
*   Resultado: nada é retornado, mas a nova lista encadeada se parece com a->b->d->e- > f
*
*    O exercício proposto no Livro: Cracking Coding Interview 6th Edition 
* 
*    gcc exec_3.c structure\list.c -o exec_3.exe -ansi -Wall -pedantic -std=c99 
*/

void deleteMiddle(LIST *list, NODE *node){

}

int main()
{
    NODE *no;
    LIST minhaLista;
    
    initList(&minhaLista);
    printf("Fila criada");

    insert(&minhaLista, 17);
    printList(&minhaLista);

    insert(&minhaLista, 21);
    printList(&minhaLista);

    insert(&minhaLista, 19);
    printList(&minhaLista);

    insert(&minhaLista, 11);
    printList(&minhaLista);
    
    no = searchList(&minhaLista, 21);
    printNode(no);
    no = searchList(&minhaLista, 19);
    printNode(no);

    delete(&minhaLista, no);
    printList(&minhaLista);

    return 0;
}