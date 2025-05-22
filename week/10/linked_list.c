#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int job_num;
  char grade;
} element;

typedef struct Node {
  element data;
  struct Node* next;
} QueueNode;

QueueNode *rear = NULL, *front = NULL;

void addqlist(element item) {
  QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
  newNode->data = item;
  newNode->next = NULL;

  if (rear == NULL)
    front = rear = newNode;
  else {
    rear->next = newNode;
    rear = newNode;
  }
}

element deleteqlist() {
  if (front == NULL) {
    printf("Queue is empty\n");
    return (element){-1, ' '};
  }

  QueueNode* temp = front;
  element item = front->data;
  front = front->next;

  if (front == NULL) rear = NULL;

  free(temp);
  return item;
}

void printlist() {
  QueueNode* current = front;
  while (current != NULL) {
    printf("%d %c -> ", current->data.job_num, current->data.grade);
    current = current->next;
  }
  printf("NULL\n");
}

int main() {
  int i, job_num, gradeA=0;
  element temp;

  printf("오늘 작업한 작업 수는? ");  
  scanf("%d", &job_num);

  printf("작업번호와 작업상태 입력 :\n");
  for (i=0; i < job_num; i++) {
    scanf("%d %c", &temp.job_num, &temp.grade);
    addqlist(temp);
  }
  
  printf("\n 연결 큐 안의 데이터 = \n");
  printlist();
  
  printf("\n 1개 삭제 후 삽입 연산 테스트\n");
  temp=deleteqlist(); 
  addqlist(temp);
  printlist();
  
  printf("A등급인 제품번호 = ");
  for (i=0; i < job_num; i++) {
  	temp = deleteqlist();
    if (temp.grade == 'A') {
        printf("%d\t", temp.job_num);
        gradeA++;
    } else
      addqlist(temp);
  }
  printf("\nA 등급인 제품은 %d개입니다. \n", gradeA);
  printf("%d 개의 등급 A 삭제 후 큐 안의 데이터 = \n", gradeA);
  printlist();
}