#define DNUM 100
#include <stdio.h>

int range(int a[], int n) {
  int max = a[0], min = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] > max) max = a[i];
    if (a[i] < min) min = a[i];
  }
  return max - min;
}

void main() {
  int data[DNUM], k, n;
  
  printf("The number of data : ");
  scanf("%d", &n);

  printf("Enter %d data\n", n);
  for (k=0; k < n; k++)
      scanf("%d", &data[k]);
  
  printf("The difference between the largest and the smallest value = %d\n", range(data, n));
}