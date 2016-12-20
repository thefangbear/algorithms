#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;

void push(node_t * head, int val) {
    node_t * current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}

void print_list(node_t * head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

node_t init() {

  node_t * head = NULL;
  head = malloc(sizeof(node_t));
  if (head == NULL) {
     return 1;
  }

  head->val = 1;
  head->next = NULL;
  return head;
}

void add(node_t *head) {
  head = malloc(sizeof(node_t));
  head->val = 1;
  head->next = malloc(sizeof(node_t));
  head->next->val = 2;
  head->next->next = NULL;
}
