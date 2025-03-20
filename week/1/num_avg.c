#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
  int pnum = 0;
  int sum = 0;
  
  int n;
  printf("입력할 데이터 수 : ");
  scanf("%d", &n);
  
  int *data = (int *)malloc(n * sizeof(int));
  
  printf("데이터 입력 : ");
  int i = 0;
  while (scanf("%d", &data[i++]) == 1)
    if (getchar() == '\n') break;
  
  for (int i = 0; i < n; i++) 
    if (data[i] > 0) {
      sum += data[i];
      pnum++;
    }
  
  double pavg = (pnum > 0) ? (double)sum / pnum : 0.0; // 평균 계산
  
  printf("pnum(%d), pavg(%.2f)\n", pnum, pavg);

  free(data);
  
  return 0;
}