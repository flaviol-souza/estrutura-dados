#include <stdio.h>
#include <stdlib.h>
#include "structure/queue.h"

/*
*   (Exercício 3.6) Animal Shelten é um abrigo de animais, que abriga apenas cães (type=1) e gatos (type =2), opera em uma política estritamente "primeiro a entrar, 
*    primeiro a sair". As pessoas devem adotar o "mais velho" (com base na hora de chegada, representado pelo value) de todos os animais no abrigo, ou podem escolher 
*    se preferem um cachorro ou um gato (e receberão o animal mais velho desse tipo). Eles não podem selecionar qual animal específico eles gostariam. Crie as estruturas 
*    de dados para manter este sistema e implemente operações como enqueue, dequeueAny, dequeueDog e dequeueCat. Você pode usar a estrutura de dados integrada LinkedList.
*
*    O exercício proposto no Livro: Cracking Coding Interview 6th Edition 
* 
*    gcc exec_6.c structure\queue.c -o exec_6.exe -ansi -Wall -pedantic -std=c99
*/

int main()
{
    QUEUE fila;

    initQueue(&fila);

    insertQueue(&fila, 1);
    insertQueue(&fila, -9);
    insertQueue(&fila, 21);
    printQueue(fila);

    retrive(&fila);
    printQueue(fila);

    insertQueue(&fila, 10);
    printQueue(fila);

    retrive(&fila);
    retrive(&fila);
    printQueue(fila);

    return 0;
}