#include<stdio.h>

int soma(int, int);

int main(){
    int v, w, x;
    v=3;
    w=4;
    x = soma(v, w);
    printf("%d\n", x);
    return 0;
}

int soma(int a, int b){
    int c;
    c = a + b;
    return c;
}

