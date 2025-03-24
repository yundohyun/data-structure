#include <stdio.h>

int main() {
  int answer, score = 0, num, correct;

  for (int i = 0; i < 5; i++) {
	  correct = 0;
	  num = 0;
	  while (num < 3 && !correct) {
	    printf("%d + %d = ", i*i, i*10);
	    scanf("%d", &answer);

      if (answer == (i*i)+(i*10)) {
		    printf("Correct!!\n");
		    correct = 1;
		    score += (20-num*3);
	    } else
		    printf("Try Again!!\n");

      num++;
	  }    
  }
  printf("당신의 덧셈성적은 ? %d\n", score);
}