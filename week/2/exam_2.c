#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  printf("입력할 데이터 수 : ");
  scanf("%d", &n);
  
  int *data = (int *)malloc(n * sizeof(int));
  
  printf("데이터 입력 : ");
  int i = 0;
  while (scanf("%d", &data[i++]) == 1)
    if (getchar() == '\n') break;

  printf("반대로 정렬된 값 : \n");
  for (int i = 0; i < n; i++)
      printf("%d ", data[n - 1 - i]);

  free(data);
  
  return 0;
}