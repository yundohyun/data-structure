#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, ans, count = 0;
  printf("몇개의 덧셈 문제를 낼까요? : ");
  scanf("%d", &n);

  int* p = (int *)malloc(n * sizeof(int));
  int* q = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    *(p + i) = i + 20;
    *(q + i) = (i + 1) * 20 - 15;
    printf("%d + %d = ", *(p + i), *(q + i));
		scanf("%d", &ans);

    if (ans == *(p + i) + *(q + i)) {
      printf("정답입니다.\n");
      count++;
    } else
      printf("틀렸습니다. 답은 %d입니다.\n", *(p + i) + *(q + i));
  }

  printf("정답 개수는 %d개입니다.\n", count);
}
