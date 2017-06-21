#include <stdio.h>
#include <malloc.h>

typedef struct node {
    int data;
    struct node* link;
}node_t;

void insert(node_t** head, int data) {
    node_t *tmp =  (node_t*)malloc(sizeof(node_t));
    tmp->data = data;
    tmp->link = (*head);
    *head = tmp;
}

void display(node_t* head) {
    while(head) {
        printf ("%d ", head->data);
        head = head->link;
    }
    printf ("\n");
}

void reverseList(node_t** head) {
    if (*head == 0) {
        return;
    }
    node_t *p = 0;
    node_t *q = *head;
    node_t *tmp = q->link;
    while(tmp) {
        q->link = p;
        p = q;
        q = tmp;
        tmp = q->link;
    };
    q->link = p;
    *head = q;
}

int main() {
    node_t *head = 0;
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    insert(&head, 6);
    insert(&head, 7);
    insert(&head, 8);
    display(head);
    reverseList(&head);
    display(head);
    return 0;
}

