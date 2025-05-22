#include <stdio.h>
#define MAX_QUEUE_SIZE 7

typedef struct {
  int job_num;
  char grade;
} element;

element queue[MAX_QUEUE_SIZE];
int rear = 0;
int front = 0;

void caddq(element item) {
  if ((rear + 1) % MAX_QUEUE_SIZE == front) {
    printf("Queue is full\n");
    return;
  }
  rear = (rear + 1) % MAX_QUEUE_SIZE;
  queue[rear] = item;
}

element cdeleteq() {
  if (front == rear) {
    printf("Queue is empty\n");
    return (element){-1, ' '};
  }
  front = (front + 1) % MAX_QUEUE_SIZE;
  return queue[front];
}

int main() {
  int i, job_num, out, cond=1;
  element temp;
  while (cond) {
    printf("완료한 작업 수는? ");
    scanf("%d", &job_num);
    
    printf("작업번호와 작업상태 입력 :\n");
    for (i=0; i < job_num; i++) {
      scanf("%d %c", &temp.job_num, &temp.grade);
      caddq(temp);
    }
    printf("몇개의 작업을 출고하실래요? ");
    scanf("%d", &out);
    for (i=0; i < out; i++) {
      temp = cdeleteq();
      printf("%d\t%c\n", temp.job_num, temp.grade);
    }
    printf("front = %d :: rear = %d\n", front, rear);
    printf("작업의 입출력을 계속하실래요(1/0)?");
    scanf("%d", &cond);
  }
}