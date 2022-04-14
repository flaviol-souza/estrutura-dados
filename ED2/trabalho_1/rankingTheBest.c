#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TECHNICIAN 1
#define CAPTAIN 2
#define JOURNALIST 3
#define PUBLIC 4

const int voters[] = {TECHNICIAN, CAPTAIN, JOURNALIST, PUBLIC};

typedef struct athlete
{

} ATHELETA;

typedef struct ranking
{

} RANKING;

int randomVoter()
{
    int size = sizeof((voters)) / sizeof((voters[0]));
    return voters[rand() % size];
}

int randomAthlete()
{
    return rand() % 10;
}

void vote(int group, int athleteId)
{
    printf("\nGroup: %i -> Athlete: %i", group, athleteId);
}

RANKING *sortByGroup()
{
    return NULL;
}

RANKING *theBest()
{
    return NULL;
}

int main()
{
    RANKING *byGroups, *best;
    int countVote = 0;

    while (countVote < 100)
    {
        countVote++;
        vote(randomVoter(), randomAthlete());
    }

    byGroups = sortByGroup();

    best = theBest();
}