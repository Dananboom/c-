#include <stdio.h>
#include <stdlib.h>
typedef struct _strack_list_node {
    int value;
    struct _strack_list_node *next;
    struct _strack_list_node *pre;
} * strack_list_node;

typedef struct _strack_list {
    strack_list_node head;
    strack_list_node tail;
    int length;
} * strack_list;

//函数声明区
strack_list strack_creat(void);
void strack_push(strack_list p, int value);
void strack_pop(strack_list p);
void print_list(strack_list p);
int top_node (strack_list p);

strack_list strack_creat(void) {
    strack_list p = (strack_list)malloc(sizeof(struct _strack_list_node));
    p->head = NULL;
    p->tail = NULL;
    p->length = 0;
}

void strack_push(strack_list p, int value) {
    if (p->length == 0)
    {
        p->tail = (strack_list_node)malloc(sizeof(struct _strack_list_node));
        p->head = p->tail;
    }
    else
    {
        p->tail->next = (strack_list_node)malloc(sizeof(struct _strack_list_node));
        p->tail->next->pre = p->tail;
        p->tail = p->tail->next;
    }
    p->tail->value = value;
    p->length++;
    p->tail->next = NULL;
}

void strack_pop(strack_list p) {
    if (p->length > 1)
    {
        strack_list_node temp = p->tail;
        p->tail->pre->next = NULL;
        free(temp);
    }
    else
    {
        free(p->head);
        p->head = NULL;
        p->tail = NULL;
    }
}

void print_list(strack_list p) {
    strack_list_node currernt = p->head;
    while (currernt != NULL)
    {
        printf("%d ", currernt->value);
        currernt = currernt->next;
    }
    printf("\n");
}

int top_node (strack_list p) {
    int a = p->tail->value;
    return a;
}
