#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int val;
    struct _node *next;
} node_t;

node_t *partition(node_t *head, int x)
{
    node_t *L = NULL, **p1 = &head, **p2 = &L;

    for (node_t *node = head; node; node = node->next) {
        node_t ***indir = node->val >= x ?
            (&p2 /* fill your code */) : (&p1 /* fill your code */);
        **indir = node;
        *indir = &(**indir)->next /* fill your code */;
    }

    *p1 = L, *p2 = NULL;
    return head;
}

int main()
{
    node_t last = {.val = 2, .next = NULL};
    node_t fifth = {.val = 5, .next = &last};
    node_t forth = {.val = 2, .next = &fifth};
    node_t third = {.val = 3, .next = &forth};
    node_t second = {.val = 4, .next = &third};
    node_t head = {.val = 1, .next = &second};
    printf("List: \n");
    for(node_t* node_t = &head; node_t; node_t = node_t->next){
        printf("%d -> ", node_t->val);
    }
    printf("\n");
    node_t* change;
    change = partition(&head, 3);
    printf("List: \n");
    for(node_t* node_t = change; node_t; node_t = node_t->next){
        printf("%d -> ", node_t->val);
    }
    printf("\n");
    return 0;
}
