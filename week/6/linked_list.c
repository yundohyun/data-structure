#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct simple_list *simple_pointer;
struct simple_list {
  char state[3];
  int count;
  simple_pointer next;
};

simple_pointer state_list() {
  simple_pointer head = malloc(sizeof(struct simple_list));
  simple_pointer current = head;
  char states[3][3] = {"CA", "NY", "TX"};
  int counts[3] = {1, 2, 3};

  for (int i = 0; i < 3; i++) {
    strcpy(current->state, states[i]);
    current->count = counts[i];
    if (i < 2) {
      current->next = malloc(sizeof(struct simple_list));
      current = current->next;
    } else
      current->next = NULL;
  }
  return head;
}

void append(simple_pointer head, char *state, int count) {
  simple_pointer current = head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = malloc(sizeof(struct simple_list));
  strcpy(current->next->state, state);
  current->next->count = count;
  current->next->next = NULL;
}

void print_list(simple_pointer head) {
  simple_pointer current = head;
  while (current != NULL) {
    printf("State: %s, Count: %d\n", current->state, current->count);
    current = current->next;
  }
}

void free_list(simple_pointer head) {
  simple_pointer current = head;
  simple_pointer next;
  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }
}

int main() {
  simple_pointer head = state_list();
  append(head, "FL", 4);
  append(head, "WA", 5);
  print_list(head);
  free_list(head);
  return 0;
}
