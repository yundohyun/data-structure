#include <stdio.h>
#include <stdlib.h>

typedef struct ctype *carlistp;
  struct ctype {
  char rcode[10];
  unsigned cc;
  carlistp next;
};

int over3000(carlistp ptr) {
  int over = 0;
  for (; ptr != NULL; ptr = ptr->next)
    if (ptr->cc >= 3000) {
      printf("%s\n", ptr->rcode);
      over++;
    }
  return over;
}

int main(int argc, char* argv[]) {
  carlistp first = NULL, inode;
  FILE* cardata = fopen(argv[1], "r");
  if (cardata == NULL) {
    printf("데이터 파일을 열 수 없습니다 \n");
    exit(1);
  };

  // 순서대로 삽입
  inode = (carlistp)malloc(sizeof(struct ctype));
  while (fscanf(cardata, "%s %u", inode->rcode, &(inode->cc)) != EOF) {
    inode = (carlistp)malloc(sizeof(struct ctype));
    if (first != NULL)
      inode->next = first;
    else
      inode->next = NULL;
    first = inode;
  }

  // // 반대로 삽입
  // inode = (carlistp)malloc(sizeof(struct ctype));
  // while (fscanf(cardata, "%s %u", inode->rcode, &(inode->cc)) != EOF) {
  //   inode = (carlistp)malloc(sizeof(struct ctype));
  //   inode->next = NULL;
  //   if (first) {
  //     carlistp temp = first;
  //     while (temp->next != NULL)
  //     temp = temp->next;
  //     temp->next = inode;
  //   } else {
  //     first = inode;
  //   }
  // }

  fclose(cardata);
  printf("배기량이 3000cc이상인 차량의 등록코드를 출력하고, \n");
  printf("3000cc이상인 차량수를함수 over3000()에서 리턴받아출력하시오\n");
  printf("3000cc이상인 차량수%d대입니다\n", over3000(first));
}
