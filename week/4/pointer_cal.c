#include <stdio.h>

int cal(int *a, float b) {
  int c;
  c = (*a) * b;
  *a = (*a) * 2;
  return c;
}

int main() {
  int num1 = 100, num2;
  float ratio = 0.5;
  num2 = cal(&num1, ratio);
  printf("num1 = %d, num2 = %d\n", num1, num2);
}
