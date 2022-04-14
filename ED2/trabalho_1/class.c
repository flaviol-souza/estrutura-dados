#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define APPROVED 1
#define FAILED 2

typedef struct student
{

} STUDENT;

typedef struct class
{

} CLASS;

typedef struct report
{

} REPORT;

int randomGradeSchool()
{
    return rand() % 3;
}

int randomGrade()
{
    return rand() % 10;
}

char *randomName()
{
    int sizeName = rand() % 10;
    char name[sizeName];
    for (int i = 0; i < sizeName; i++)
    {
        name[i] = (rand() % 26) + 65;
        printf("%c", name[i]);
    }

    return name;
}

STUDENT *schoolEnrollment(char *name, int gradeSchool)
{
    return NULL;
}

CLASS *buildDiary(int gradeSchool)
{
    return NULL;
}

void launchGradeSchool(int ra, double grade)
{
}

REPORT *approvedFailed(int gradeSchool)
{
    return NULL;
}

void launchGradeClass(CLASS *class)
{
    STUDENT s = class->student;
    while (s != NULL)
    { // loop na lista de aluno da TURMA
        launchGradeSchool(s->ra, randomGrade());
        s = s->next;
    }
}

int main()
{
    CLASS *c1, *c2, *c3;
    REPORT *r1, *r2, *r3;
    STUDENT *s;
    int countStudent = 0;
    while (countStudent <= 90)
    {
        s = schoolEnrollment(randomName(), randomGradeSchool());
    }

    c1 = buildDiary(1);
    c2 = buildDiary(2);
    c3 = buildDiary(3);

    launchGradeClass(c1);
    launchGradeClass(c2);
    launchGradeClass(c3);

    r1 = approvedFailed(1);
    r2 = approvedFailed(2);
    r3 = approvedFailed(3);
}