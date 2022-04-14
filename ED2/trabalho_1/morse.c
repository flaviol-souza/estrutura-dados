#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct word
{

} WORD;

int randomSize()
{
    return rand() % 10;
}

char *randomPalavra()
{
    int wordSize = rand() % 10;
    char word[wordSize];
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
    int count = 0;
    char *morse;
    while (count < 10)
    {
        morse = translateToMorse(randomPalavra(randomSize()));
        translateToPortugues(morse);
        sort(morse);
        count++;
    }
}