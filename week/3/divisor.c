#include <stdio.h>

int main() {
	int num, n, p, count = 0;	
	printf("양의정수 입력  : ");
	scanf("%d", &n);
	
	num = n;
	while ((num % 2) == 0) {
		printf("%4d", 2); // ①
		num = num / 2; 
    count++;
	}
  p = 3; 
	while (num != 1) {
		if ((num % p) == 0) {
		  printf("%4d", p); // ②
		  num = num / p; 
      count++;	
		}
		else
      p = p + 2;
	}
	printf("\ncount = %d\n", count); //③	
}