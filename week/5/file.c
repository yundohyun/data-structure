#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct course {
  char courseid[10];
  char tname[20];
  unsigned snum;
  unsigned roomnum;
} course;

int main(int argc, char *argv[]) {
  int size = 0;
  course courses[MAX_SIZE];

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("파일을 열 수 없습니다");
    return 1;
  }

  while (
    fscanf(fp, "%s %s %u %u",
      courses[size].courseid,
      courses[size].tname,
      &courses[size].snum,
      &courses[size].roomnum
    ) == 4
  ) size++;

  printf("학생 수가 40명 이상인 강좌 리스트\n");
  for (int i = 0; i < size; i++)
    if (courses[i].snum >= 40)
      printf("아이디 : %s, 교수 이름 : %s, 학생 수 : %u, 강의실 번호 : %u\n", courses[i].courseid, courses[i].tname, courses[i].snum, courses[i].roomnum);

  printf("\n");

  char name[20];
  printf("검색할 교수 이름을 입력하시오 : ");
  scanf("%s", name);

  for (int i = 0; i < size; i++)
    if (strcmp(courses[i].tname, name) == 0)
      printf("아이디 : %s, 학생 수 : %u, 강의실 번호 : %u\n", courses[i].courseid, courses[i].snum, courses[i].roomnum);

  printf("\n");

  unsigned id;
  printf("검색할 강의실 번호를 입력하시오 : ");
  scanf("%u", &id);

  for (int i = 0; i < size; i++)
    if (courses[i].roomnum == id)
      printf("아이디 : %s, 교수 이름 : %s, 학생 수 : %u\n", courses[i].courseid, courses[i].tname, courses[i].snum);
}
