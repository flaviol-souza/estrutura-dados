#include<stdio.h>

void swap(int *, int *);

int main(){
    int v, w;
    v=3;
    w=4;
    swap(&v, &w);
    printf("%d %d\n", v, w);
    return 0;
}

void swap(int *a, int *b){
    int c;
    c = *a;
    *a = *b;
    *b = c;
}