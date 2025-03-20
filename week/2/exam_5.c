#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
  int count = 0;
  int max = 0;

  int data;
  scanf("%d", &data);
  while (data > 0) {
    count++;
    if (data > max) max = data;
    scanf("%d", &data);
  }

  if (count == 0) 
    printf("no data");
  else
    printf("count = %d, max = %d", count, max);
  
  return 0;
}