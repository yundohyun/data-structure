#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
  int ssum = 0;
  int psum = 0;
  int temp_ssum = 0;
  int temp_psum = 1;
  
  int n;
  printf("입력할 데이터 수 : ");
  scanf("%d", &n);
  
  for (int i = 1; i < n + 1; i++) {
    temp_ssum += i;
    temp_psum *= i;
    ssum += temp_ssum;
    psum += temp_psum;
  }

  printf("ssum = %d, psum = %d\n", ssum, psum);
  
  return 0;
}