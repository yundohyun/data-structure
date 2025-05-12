#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MTSIZE 50

typedef struct anode* aList;
struct anode {
    char aid[10];
    int apart;
    int wn;
    aList next;
};

int num_agent(aList ptr) {
    int anum = 0;
    for (ptr = ptr->next; ptr != NULL; ptr = ptr->next) {
        anum++;
    }
    anum++; // for the first node
    return anum;
}

int waiting_sum(aList ptr) {
    int wsum = 0;
    while (ptr != NULL) {
        wsum += ptr->wn;
        ptr = ptr->next;
    }
    return wsum;
}

void main(int argc, char* argv[]) {
    aList inode, first = NULL;
    FILE* afilep;

    if ((afilep = fopen(argv[1], "r")) == NULL) {
        printf("데이터 파일을 열 수 없습니다 \n");
        exit(1);
    }

    inode = (aList)malloc(sizeof(struct anode));
    while (fscanf(afilep, "%s %d %d", inode->aid, &(inode->apart), &(inode->wn)) != EOF) {
        if (first != NULL)
            inode->next = first;
        else
            inode->next = NULL;
        first = inode;
        inode = (aList)malloc(sizeof(struct anode));
    }
    printf("연결리스트안의 노드의 수 즉 상담원의 수는 %d명입니다. \n", num_agent(first));
    printf("전체 %d명이 대기 중입니다\n", waiting_sum(first));
}