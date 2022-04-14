#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct container
{

} CONTAINER;

typedef struct cargo_ship
{

} CARGO_SHIP;

int randomLandingPoint()
{
    return rand() % 3;
}

CONTAINER *boarding(int landing)
{
    return NULL;
}

void loading()
{
}

CONTAINER *discharging()
{
    return NULL;
}

int main()
{
    CONTAINER *container;
    int countContainer = 0;
    while (countContainer < 18)
    {
        countContainer++;
        container = boarding(randomLandingPoint());
        // print da codigo do container
    }

    printf("\nCarregando embarcao"); 
    loading();

    // Ponto de Desembarque 1
    while (container != NULL)
    {
        container = discharging();
    }
    printf("\nFim da primeira entrega!");

    // Ponto de Desembarque 2
    while (container != NULL)
    {
        container = discharging();
    }
    printf("\nFim da segunda entrega!");

    // Ponto de Desembarque 3
    while (container != NULL)
    {
        container = discharging();
    }
    printf("\nFim da terceira entrega!");
}