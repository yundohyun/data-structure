#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
  int total_price = 0;
  
  int n;
  printf("입력할 데이터 수 : ");
  scanf("%d", &n);
  
  int *price = (int *)malloc(n * sizeof(int));
  double *rate = (double*)malloc(n * sizeof(double));
  
  printf("가격 입력 : ");
  int i = 0;
  while (scanf("%d", &price[i++]) == 1)
    if (getchar() == '\n') break;
  
  printf("할인률 입력 : ");
  i = 0;
  while (scanf("%lf", &rate[i++]) == 1)
    if (getchar() == '\n') break;

  for (int i = 0; i < n; i++) 
    total_price += (int)((double) price[i] * (1 - rate[i]));
      
  printf("total_price(%d)", total_price);
  
  free(price);
  free(rate);
  
  return 0;
}