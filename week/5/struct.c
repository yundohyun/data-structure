#include <stdio.h>
#include <stdlib.h>

typedef struct member {
  int id;
  char name[20];
  float score;
} member;

void over_4(member members[], int n) {
  printf("학점이 4점 이상인 학생의 리스트\n");
  for (int i = 0; i < n; i++)
    if (members[i].score >= 4)
      printf("아이디 : %d, 이름 : %s, 학점 : %.2f\n", members[i].id, members[i].name, members[i].score);
}

member max_score(member members[], int n) {
  int idx = 0;
  for (int i = 1; i < n; i++)
    if (members[i].score > members[idx].score)
      idx = i;
  return members[idx];
}

int main() {
  printf("몇 명의 학생을 입력하시겠습니까? : ");
  int n;
  scanf("%d", &n);

  member* members = (member*)malloc(sizeof(member) * n);

  for (int i = 0; i < n; i++) {
    printf("학생 %d의 아이디, 이름, 점수를 입력하세요 : ", i + 1);
    scanf("%d %s %f", &members[i].id, members[i].name, &members[i].score);
  }

  over_4(members, n);
  member max = max_score(members, n);
  printf("최고 점수 학생\n아이디 : %d, 이름 : %s, 학점 : %.2f\n", max.id, max.name, max.score);
}