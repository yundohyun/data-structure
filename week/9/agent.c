#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MTSIZE 50

typedef struct agent {
  char aid[4];
  int apart;
  int wn;
} agentType;

agentType max_waiting(agentType a[], int n);  

void main(int argc, char* argv[]) {
  agentType atable[MTSIZE], maxa;
  int k = 0, n;
  FILE* afile;

  if ((afile = fopen(argv[1], "r")) == NULL) {
    printf("입력파일을 사용할 수 없습니다\n");
    exit(1);
  }

  while (fscanf(afile, "%s %d %d", atable[k].aid, &atable[k].apart, &atable[k].wn) != EOF) k++;
  n = k;
  printf("이 콜센터의 상담원의 수 %d명입니다\n", n);

  maxa = max_waiting(atable, n);
  printf("최대 대기상담원 : %s %d %d\n", maxa.aid, maxa.apart, maxa.wn);
}

agentType max_waiting(agentType a[], int n) {
  int k, maxk = 0;
  for (k = 1; k < n; k++)
    if (a[k].wn > a[maxk].wn) maxk = k;
  return a[maxk];              
}


