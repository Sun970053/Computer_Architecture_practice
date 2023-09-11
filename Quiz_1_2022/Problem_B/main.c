#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct list_node {
    int val;
    struct list_node *next;
};

struct list_node *reverse(struct list_node **head /*B01 Fill Your Code */)
{
    struct list_node *next = NULL, *ret;
    while (*head) {
        ret = malloc(sizeof(struct list_node));
        ret->val = (*head)->val /*B02 Fill Your Code */;
        ret->next = next /*B03 Fill Your Code */;
        next = ret /*B04 Fill Your Code */;
        *head = (*head)->next;
    }
    return ret;
}

/* Assume that NEW_LL_1234() properly malloc's a linked list
 * 1 -> 2 -> 3 -> 4, and returns a pointer that points to the first
 * list_node in the linked list. Assume that before test_reverse
 * returns, head and ret will be properly freed.
 */

void test_reverse()
{
    //struct list_node *head = NEW_LL_1234();
    struct list_node* head = malloc(sizeof(struct list_node));
    struct list_node* pt = head;
    for (int c = 1; c <= 3; ++c) {
        struct list_node* new_node = malloc(sizeof(struct list_node));
        *pt = (struct list_node){.val = c, .next = new_node};
        printf("node(%d) = %d\n", c, pt->val);
        pt = new_node;
    }
    *pt = (struct list_node){.val = 4, .next = NULL};
    printf("node(%d) = %d\n", 4, pt->val);
    printf("head->val == %d\n",head->val);
    printf("head->next->val == %d\n",head->next->val);
    assert(head->val == 1);        /* returns True */
    assert(head->next->val == 2);  /* returns True */

    struct list_node *ret = reverse(&head);
    struct list_node *pt2 = ret;
    int num = 1;
    while(pt2){
        printf("reverse node(%d) == %d\n",num++ ,pt2->val);
        pt2 = pt2->next;
    }
    printf("head = %p ret = %p\n",head ,ret);
    printf("ret->val == %d\n", ret->val);
    assert(head != ret);    /* ret is a new copy of the original list */
    assert(ret->val == 4);  /* should return True */
}

int main()
{
    printf("Problem_B\n");
    test_reverse();
    return 0;
}
