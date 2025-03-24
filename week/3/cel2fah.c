#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
  float cel, fah;
  int n = 0;
  printf("섭씨온도 : ");
  scanf("%f", &cel);
  while (cel > -50) {
    fah = cel * (9.0 / 5.0) + 32;
    printf("화씨온도 : %.2f\n", fah);

    printf("섭씨온도 : ");
    scanf("%f", &cel);
  }
}
