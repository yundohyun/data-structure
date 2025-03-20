#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
  int pos_sum = 0;
  int nega_sum = 0;
  
  int n;
  printf("입력할 데이터 수 : ");
  scanf("%d", &n);
  
  int *data = (int *)malloc(n * sizeof(int));
  
  printf("데이터 입력 : ");
  int i = 0;
  while (scanf("%d", &data[i++]) == 1)
    if (getchar() == '\n') break;
  
  for (int i = 0; i < n; i++) 
    if (data[i] > 0) pos_sum += data[i];
    else nega_sum += data[i];

  printf("양수의 합 : %d\n", pos_sum);
  printf("음수의 합 : %d", nega_sum);

  free(data);
  
  return 0;
}