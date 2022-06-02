#include <stdio.h>
#include <stdlib.h>
#include "structure/stack.h"

/*
*   (Exercício 3.5) Escreva um programa para ordenar uma pilha de forma que os menores itens fiquem no topo. Você pode usar uma pilha temporária adicional, 
*    mas não pode copiar os elementos em nenhuma outra estrutura de dados. A pilha suporta as seguintes operações: push, pop, peek e isEmpty.
*
*    O exercício proposto no Livro: Cracking Coding Interview 6th Edition 
* 
*    gcc exec_5.c structure\stack.c -o exec_5.exe -ansi -Wall -pedantic -std=c99
*/

int main()
{
    STACK myStack;

    initStack(&myStack);

    push(&myStack, 'S');
    push(&myStack, 'T');
    push(&myStack, 'A');
    push(&myStack, 'C');
    push(&myStack, 'K');

    printStack(&myStack);
    return 1;
}