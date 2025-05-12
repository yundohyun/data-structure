#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 50

typedef struct {
    int key;
    char grade;
} element;

int top = -1;
element stack[MAX_STACK_SIZE];
void push(element data) {
    if (top >= (MAX_STACK_SIZE - 1)) {
        printf("스택이 가득 찼습니다.\n");
        return;
    }
    stack[++top] = data;
};
element pop() {
    if (top < 0) {
        printf("스택이 비었습니다.\n");
        exit(1);
    }
    return stack[top--];
};

int main() {
    element data;
    int i, n, cond = 1;
    i = 0;
    while (cond) {
        printf("Input data : ");
        scanf("%d %c", &data.key, &data.grade);
        if (data.key != 0) {
            push(data);
            i++;
        }
        printf("Continue...(1/0)");
        scanf("%d", &cond);
    }
    printf("입력한 데이터의 개수 : %d \n", i);

    printf("스택에서 몇개의 데이터가 필요하세요 ? ");
    scanf("%d", &n);
    printf("스택에서 삭제한 데이터 : \n");
    for (i=0; i < n; i++) {
        data = pop();
        printf("%d \t%c\n", data.key, data.grade);
    }
}