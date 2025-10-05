#include <stdio.h>

typedef struct Node node;

typedef struct Node {
    int value;
    node *next;
} node;

int main() {
    node node1;
    node node2;
    node1.value = 1;
    node1.next = &node2;
    node2.value = 2;
    node2.next = NULL;

    node *head = &node1;
    while(head) {
        printf("%d\n", head->value);
        head = head->next;
    }
}
