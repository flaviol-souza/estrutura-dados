#include <stdio.h>
#include <stdlib.h>
#include "structure/stack.h"

/*
*   (Exercício 3.3) Imagine uma pilha, literal, de pratos. Se a pilha ficar muito alta, ela pode tombar. Portanto, na realidade, 
*    provavelmente iniciaríamos uma nova pilha quando a pilha anterior excedesse algum limite. Implemente uma estrutura de dados SetOfStack s que imita isso.
*    SetOfStack s deve ser composto de várias pilhas e deve criar uma pilha assim que a anterior exceder a capacidade. SetOfStack.pushSet() e SetOfStack.popSet() 
*    devem se comportar de forma idêntica a uma única pilha (ou seja, pop( ) deve retornar os mesmos valores que se houvesse apenas uma única pilha).
*
*    O exercício proposto no Livro: Cracking Coding Interview 6th Edition 
* 
*    gcc exec_4.c structure\stack.c -o exec_4.exe -ansi -Wall -pedantic -std=c99
*/

/*typedef struct _setStack 
{
    
} SET_STACK;

void pushSet(SET_STACK *set, NODE *node){

}

void popSet(SET_STACK *set){

}*/

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