#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fnode *fpointer;
struct fnode {
  char animal[10];
  int item;
  fpointer next;
};

void free_all(fpointer head) {
  fpointer current = head;
  fpointer next;
  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }
}

int main() {
  fpointer head = NULL, ptr, another, before;
  int how_many = 0;

  head = (fpointer) malloc(sizeof(struct fnode));

  strcpy(head->animal, "dog");
  head->item = 10;
  head->next = NULL;

  for (int i = 0; i < 4; i++) {
    another = (fpointer) malloc(sizeof(struct fnode));
    printf("Enter the sort of animal and ost number: ");
    scanf("%s %d", (another->animal), &(another->item));
    ptr = head;
    while (ptr != NULL) {
      before = ptr;
      ptr = ptr->next;
    }
    before->next = another;
    another->next = NULL;
  }

  printf("===============\n");

  ptr = head;
  while (ptr != NULL) {
    printf("Animal: %s, Item: %d\n", ptr->animal, ptr->item);
    how_many += ptr->item;
    ptr = ptr->next;
  }
  printf("Total items: %d\n", how_many);

  free_all(head);
}