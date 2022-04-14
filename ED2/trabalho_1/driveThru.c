#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LIMITEKITCHEN 7
#define DRIVETHRU 1
#define COUNTER 2
#define DELIVERY 3

const int orderType[] = {DRIVETHRU, COUNTER, DELIVERY};

typedef struct order
{

} ORDER;

int randomOrderType()
{
    int size = sizeof((orderType)) / sizeof((orderType[0]));
    return orderType[rand() % size];
}

int requestOrder(int order)
{
    return 0; // return key of order
}

int randomStep()
{
    int r = rand() % 100 + 1;
    if (r <= 35)
        return 1;
    if (r <= 60)
        return 2;
    else
        return 3;
}

ORDER *makeOrder()
{
    return NULL;
}

ORDER *deliveryOrder()
{
    return NULL;
}

int main()
{
    ORDER *o;
    int step = 1, orderType, key, countOrder = 0;
    while (countOrder < 100)
    {
        if (step == 1)
        {
            orderType = randomOrderType();
            key = requestOrder(orderType);
            printf("\nOrder Type: %i -> Key: %i", orderType, key);
        }
        else if (step == 2)
        {
            o = makeOrder();
        }
        else
        {
            o = deliveryOrder();
        }
        step = randomStep();
    }
}