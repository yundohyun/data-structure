#include <stdio.h>
#include <stdlib.h>

int main() {
  int *p, q;
  float *fp, x;
  p = &q;
  *p = 199;

  // float 변수를 선언하고 주소를 fp에 저장
  float temp;
  fp = &temp;

  scanf("%f", fp);
  x = *fp;
  printf("%d --- %.2f\n", q, x);
}