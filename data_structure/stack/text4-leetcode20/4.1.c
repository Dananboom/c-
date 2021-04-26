# include <stdio.h>
# include <stdlib.h>
#include <string.h>
// 先实现栈
typedef struct _stack_list_node {
    int value;
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

void stack_push (stack_list p, int a) {
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

void list_free (stack_list p) {
    stack_list_node current = p->head;
    while (current != NULL) {   
        stack_list_node temp = current->next;
        free(current);
        current = temp;
    }
}

stack_list_node top_node (stack_list p) {
    return p->tail;
}

bool isValid(char * s){
    if (strlen(s) % 2 == 1) {
        return false;
    }
    stack_list p = list_creat();
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
            stack_push(p, s[i]);
        }
        if (p->length == 0) {
            return 0;
        }
        if (s[i] == '}' || s[i] == ']' || s[i] == ')') {
            if (top_node(p)->value - s[i] == -2 || top_node(p)->value - s[i] == -1) {
                stack_pop(p);
            } else {
                if (s[i - 1] == s[i] || s[i + 1] == s[i]) {
                    return 0;
                }
            }
        }   
    }
    return p->length == 0 ? 1 : 0;
}