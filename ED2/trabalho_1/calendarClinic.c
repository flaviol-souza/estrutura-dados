#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MEDICAL 1
#define SURGERY 2

const int appointmentType[] = {MEDICAL, SURGERY};

typedef struct appointment
{

} APPOINTMENT;

typedef struct calendar
{

} CALENDAR;

int randomAppointmentType()
{
    int size = sizeof((appointmentType)) / sizeof((appointmentType[0]));
    return appointmentType[rand() % size];
}

int randomCrm(){
    return rand() % 3;
}

int randomNumber(int minNumber, int maxNumber){
    return rand() % (maxNumber + 1 - minNumber) + minNumber;
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

APPOINTMENT *scheduleAppointment(int appointmentType, int crm)
{
    return NULL;
}

void *cancelAppointment(int day, int appointmentNumber)
{
    return NULL;
}

CALENDAR *optimizeCalendar()
{
    return NULL;
}

int main()
{
    int step = 1, count = 0;
    APPOINTMENT *a;
    CALENDAR *c;
    while (count < 100)
    {
        if (step == 1)
        {
            a = scheduleAppointment(randomAppointmentType(),  randomCrm());
        }
        else if (step == 2)
        {
            cancelAppointment(randomNumber(1, 5), randomNumber(1, 5));
        }
        else if (step == 3)
        {
            c = optimizeCalendar();
        }
        step = randomStep();
    }
}