#include<stdio.h>

int main(){
    int x = 19;
    int *p1, *p2;

    p1 = &x;
    p2 = p1;

    printf("%p\n", p1);
    printf("%i\n", *p1);
    printf("%p\n", p2);
    printf("%i\n", *p2);

    return 0;
}