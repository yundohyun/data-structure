#define DNUM 100
#include <stdio.h>

int pcount(int data[], int n) {
  int count = 0;
  for (int i = 0; i < n; i++)
    if (data[i] > 0) count++;
  return count;
}

double avg(int data[], int n) {
  double sum = 0;
  for (int i = 0; i < n; i++)
    sum += data[i];
  return sum / n;
}

int large(int data[], int n) {
  int max = data[0];
  for (int i = 1; i < n; i++)
    if (data[i] > max)
      max = data[i];
  return max;
}

int small(int data[], int n) {
  int min = data[0];
  for (int i = 1; i < n; i++)
    if (data[i] < min)
      min = data[i];
  return min;
}

int main() {
  int data[DNUM], n;

  printf("Enter the number of data : ");
  scanf("%d", &n);

  printf("Enter %d data : ", n);
  for (int i = 0; i < n; i++)
    scanf("%d", &data[i]);

  printf("The number of positive data : %d\n", pcount(data, n));
  printf("The average of data : %.2f\n", avg(data, n));
  printf("The largest data : %d\n", large(data, n));
  printf("The smallest data : %d\n", small(data, n));
}