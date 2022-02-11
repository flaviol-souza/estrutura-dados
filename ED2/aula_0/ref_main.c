#include <stdio.h>
#include <conio.h>

void troca_valores(int *ptrx, int *ptry);

int main(void) {
  int a, b;
  printf("Digite o primeiro valor: ");
  scanf("%d", &a);
  
  printf("Digite o segundo valor: ");
  scanf("%d", &b);
  
  printf("Voce digitou os valores na seguinte ordem: %d e %d\n", a, b);
  
  troca_valores(&a, &b);
  
  printf("Os valores trocados sao: %d e %d\n", a, b);
  
  getch();
  return 0;
}

void troca_valores(int *ptrx, int *ptry) {
  int auxiliar;
  
  auxiliar = *ptrx;
  
  *ptrx = *ptry;
  
  *ptry = auxiliar;
  
  return;
}