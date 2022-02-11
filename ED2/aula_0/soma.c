#include<stdio.h>
int soma(int, int);

int main(){
    int a = soma(2, 3);
    int *p;
    return 0;
}

int soma(int *a, int *b){
    return a + b;
}