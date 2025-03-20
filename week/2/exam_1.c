#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
  int even = 0;
  int odd = 0;
  
  int n;
  printf("입력할 데이터 수 : ");
  scanf("%d", &n);
  
  int *data = (int *)malloc(n * sizeof(int));
  
  printf("데이터 입력 : ");
  int i = 0;
  while (scanf("%d", &data[i++]) == 1)
    if (getchar() == '\n') break;
  
  for (int i = 0; i < n; i++) 
    if (data[i] % 2 == 0) even += data[i];
    else odd += data[i];

  printf("짝수의 합 : %d\n", even);
  printf("홀수의 합 : %d", odd);

  free(data);
  
  return 0;
}