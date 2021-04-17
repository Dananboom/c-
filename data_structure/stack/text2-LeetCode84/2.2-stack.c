# include <stdio.h>
# include <stdlib.h>
// 先实现栈
typedef struct _stack_list_node {
    int value;
    int key;
    struct _stack_list_node * next;
    struct _stack_list_node * pre;
} * stack_list_node ;
 
typedef struct _stack_list {
    stack_list_node head;
    stack_list_node tail;
    int length;
} * stack_list;

stack_list list_creat (void) {
    stack_list p = (stack_list) malloc (sizeof(struct _stack_list_node));
    p->head = NULL;
    p->tail = NULL;
    p->length = 0;
    return p;
}

void stack_push (stack_list p, int a, int key) {
    if (p->length == 0) {
        p->tail = (stack_list_node) malloc (sizeof(struct _stack_list_node));
        p->head = p->tail;
        p->tail->next = NULL;
    } else {
        p->tail->next = (stack_list_node) malloc (sizeof(struct _stack_list_node));
        p->tail->next->pre = p->tail;
        p->tail = p->tail->next;

    }
    p->tail->value = a;
    p->tail->key = key;
    p->tail->next = NULL;
    p->length++;
} 

void stack_pop (stack_list p) {
    if (p->length > 1) {
        stack_list_node newTail = p->tail->pre;
        free(p->tail);
        p->tail = newTail;
        p->tail->next = NULL;

    } else {
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
        printf("%d %d ", current->value, current->key);
        current = current->next;
    }
    printf("\n");
}

stack_list_node top_node (stack_list p) {
    return p->tail;
}

int largestRectangleArea(int* heights, int heightsSize) {
    heightsSize++;
    int newarr[heightsSize];
    for (int i = 0; i < heightsSize - 1; i++) {
        newarr[i] = heights[i];
    }
    newarr[heightsSize - 1] = 0;
    int max = 0;
    stack_list p = list_creat();
    for (int i = 0; i < heightsSize; i++) {
       while (p->length != 0 && newarr[i] < top_node(p)->value) {
           int temp = top_node(p)->value;
           stack_pop(p);
           if (p->length == 0) {
               (i - 0) * temp > max ? max = (i - 0) * temp : max;
           } else {    
               (i - top_node(p)->key - 1) * temp > max ?  max = (i - top_node(p)->key - 1) * temp : max;                                                          
           }
        }
        stack_push(p, newarr[i], i);
    }
    return max;
}    

/*思路：
这道题的暴力解法