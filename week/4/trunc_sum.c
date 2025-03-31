#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

float trunc_sum(float* data) {
  float sum = 0.0;
  for (int i = 0; i < 10; i++) {
    int ivalue = (int)*(data + i);
    sum += *(data + i) - ivalue;
  }
  return sum;
}

int main() {
  float xarray[10], fsum = 0.0;
  int i;
  printf("Enter 10 reals : ");
  for (i = 0; i < 10; i++) {
    scanf("%f", xarray + i);
    fsum = fsum + *(xarray + i);
  }
  printf("Sum = %.2f\n", fsum);
  printf("Truncation Value = %.2f\n", trunc_sum(xarray));
}
