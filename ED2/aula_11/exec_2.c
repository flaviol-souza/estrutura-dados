#include <stdio.h>
#include <stdlib.h>
#include "structure/list.h"

/*
*   (Exercício 2.2) Implemente um algoritmo para encontrar o n últimos elemento de uma lista encadeada.
*    O exercício proposto no Livro: Cracking Coding Interview 6th Edition 
* 
*    gcc exec_2.c structure\list.c -o exec_2.exe -ansi -Wall -pedantic -std=c99 
*/

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