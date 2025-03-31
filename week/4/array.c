#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void insert_data(int arr[], int n, int k, int data) {
  for (int i = n; i > k; i--)
    arr[i] = arr[i - 1];
  arr[k] = data;
}

int is_search(int arr[], int n, int data) {
  for (int i = 0; i < n; i++)
    if (arr[i] == data) return i;
  return -1;
}

int delete_data(int arr[], int n, int k) {
  int ddata = arr[k];
  for (int i = k; i < n - 1; i++)
    arr[i] = arr[i + 1];
  return ddata;
}

int main() {
  int n;
  printf("입력할 데이터 수 : ");
  scanf("%d", &n);
  
  int data[100];
  
  printf("데이터 입력 : ");
  int i = 0;
  while (scanf("%d", &data[i++]) == 1)
    if (getchar() == '\n') break;

  printf("인덱스 위치와 삽입할 값 : ");
  int idx, value;
  scanf("%d %d", &idx, &value);

  insert_data(data, n + 1, idx, value);
  
  printf("\n\n삽입 후 값 : ");
  for (int i = 0; i < n + 1; i++)
    printf("%d ", data[i]);

  printf("\n\nSearch Test\n");   
  int k = is_search(data, n + 1, value);
  if (k != -1) printf("%d is in this list at %d", value, k);
  else printf("%d : Not found in this list", value);

  printf("\n\nDeleted Data : %d\n", delete_data(data, n + 1, k));
  printf("삭제 후 값 : ");
  for (int i = 0; i < n; i++)
    printf("%d ", data[i]);
  printf("\n");
}