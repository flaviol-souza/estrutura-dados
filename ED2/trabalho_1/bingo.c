#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct card
{

} CARD;

typedef struct ranking
{

} RANKING;

int randomNewPlayer()
{
    return rand() & 1;
}

CARD *buildCard(int playerId)
{
    return NULL;
}

RANKING *rankingHits()
{
    return NULL;
}

int drawNumber()
{
    return 0; // 0 - sorteia; 1-fim de jogo
}

int main()
{
    CARD *c;
    int newDraw = 0, countPlayers = 0, beginPlayers = randomNewPlayer();
    while (countPlayers <= beginPlayers)
    {
        c = buildCard(countPlayers++);
    }

    while (newDraw == 0)
    {
        newDraw = drawNumber();
        if (randomNewPlayer() == 1 && countPlayers <= 30)
        {
            c = buildCard(countPlayers++);
        }
    }
}