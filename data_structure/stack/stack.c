#include <stdio.h>
#include <stdlib.h>
typedef struct _stack_list_node {
    int value;
    struct _stack_list_node *next;
    struct _stack_list_node *pre;
} * stack_list_node;

typedef struct _stack_list {
    stack_list_node head;
    stack_list_node tail;
    int length;
} * stack_list;

//函数声明区
stack_list stack_creat(void);
void stack_push(stack_list p, int value);
void stack_pop(stack_list p);
void print_list(stack_list p);
int top_node (stack_list p);
void list_free (stack_list p);

stack_list stack_creat(void) {
    stack_list p = (stack_list)malloc(sizeof(struct _stack_list_node));
    p->head = NULL;
    p->tail = NULL;
    p->length = 0;
    return p;
}
void stack_push(stack_list p, int value) {
    if (p->length == 0)
    {
        p->tail = (stack_list_node)malloc(sizeof(struct _stack_list_node));
        p->head = p->tail;
        p->tail->next = NULL;
    }
    else
    {
        p->tail->next = (stack_list_node)malloc(sizeof(struct _stack_list_node));
        p->tail->next->pre = p->tail;
        p->tail = p->tail->next;
    }
    p->tail->value = value;
    p->length++;
    p->tail->next = NULL;
}

void stack_pop(stack_list p) {
    if (p->length > 1)
    {
        stack_list_node newTail = p->tail->pre;
        free(p->tail);
        p->tail = newTail;
        p->tail->next = NULL;

    }
    else
    {
        free(p->head);
        p->head = NULL;
        p->tail = NULL;
    }
    p->length--;
}

void print_list(stack_list p) {
    
    stack_list_node current = p->head;
    while (current != NULL)
    {   
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int top_node (stack_list p) {
    int a = p->tail->value;
    return a;
}

void list_free (stack_list p) {
    stack_list_node current = p->head;
    while (current != NULL)
    {   
        stack_list_node temp = current->next;
        free(current);
        current = temp;
        
    }
}
//int main() {
//    stack_list p = stack_creat();
//    stack_push(p, 7);
//    stack_push(p, 7);
//    stack_push(p, 7);
//    stack_push(p, 7);
//    stack_push(p, 7);
//    stack_push(p, 7);
//    stack_push(p, 7);
//    stack_pop(p);
//    stack_pop(p);
//    printf("%d\n", p->length);
//    print_list(p);
//}
