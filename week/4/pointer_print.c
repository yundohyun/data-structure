#include <stdio.h>
#include <stdlib.h>

int main() {
  int* pi = (int *)malloc(5 * sizeof(int));
  for (int i = 0; i < 5; i++)
    *(pi + i) = (i + 1) * 10;
  
  printf("포인터 표현으로 출력 : ");
  for (int i = 0; i < 5; i++)
    printf("%4d", *(pi + i));
  printf("\n");
  
  printf("배열 표현으로 출력 : ");
  for (int i = 0; i < 5; i++)
    printf("%4d", pi[i]);
  printf("\n");
}