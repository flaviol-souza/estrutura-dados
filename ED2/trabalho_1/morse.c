#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct word
{
    int i;
} WORD;

char *randomPalavra(int wordSize)
{
    char *word;
    word = (char*)malloc((wordSize) * sizeof(char));
    for (int i = 0; i < wordSize; i++)
    {
        word[i] = (rand() % 26) + 65;
    }

    return word;
}

char *randomMorse(int wordSize)
{
    return NULL; //* -
}

WORD *translateToMorse(WORD *palavra)
{
    return NULL;
}

WORD *translateToPortugues(WORD *morse)
{
    return NULL;
}

WORD *sort(WORD *morse)
{
    return NULL;
}

int main()
{
    int r, count = 0;
    char *morse;
    while (count < 10)
    {
        r = rand() % 10;
        morse = translateToMorse(randomPalavra(r));
        translateToPortugues(morse);
        sort(morse);
        count++;
    }
}