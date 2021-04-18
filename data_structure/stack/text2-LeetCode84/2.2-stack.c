# include <stdio.h>
# include <stdlib.h>
#define     MAX(a, b)   ((a) > (b) ? (a) : (b))
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

int largestRectangleArea(int* heights, int heightsSize) {
    int max = 0;
    stack_list p = list_creat();
    for (int i = 0; i <= heightsSize; i++) {
        int target = i == heightsSize ? 0 : heights[i];
        while (p->length != 0 && target < top_node(p)->value) {
           int temp = top_node(p)->value;
           stack_pop(p);
           int width = i - ( p->length == 0 ? 0 : top_node(p)->key + 1);
           max = MAX(width * temp, max);
        }
        stack_push(p, target, i);
    }
    free(p);
    return max;
}    

/*思路：
用单调栈做
注意栈这个结构是后进先出，所以基本上所有数据进来都要先弹后压，所以可以把弹写在前面，压写在后面，一开始没有数据的时候，前面那个弹得判断肯定不成立，
所以就直接被压了。

这个的思路也大概是遍历数组。算出每一个矩形的宽度，和这个矩形的值（长度）相乘，
首先，什么时候压栈，在这题里面，数组里面的每个数肯定都是要计算的，所以都要压栈。

有个新栈顶和旧栈顶，当遍历到的数比旧站顶小的时候，旧栈顶就被弹出去了，我们的目标数就是这个旧栈顶，我们求的是以旧栈顶为高的矩形的面积

什么时候弹栈，当遍历到的数比当前的栈顶小的时候（旧栈顶），新栈顶肯定是左边第一个比旧栈顶小的数，因为比旧栈顶大的都被弹出了，（比如1，5，6，3，求以三为高的矩形面积，左边比三大的5和6都被弹出了。）。（执行了pop）
旧站顶到左边第一个比他小的数的距离就是旧栈顶下标-新栈顶下标，旧栈顶到右边第一个比他小的数的距离是旧栈顶的下标-把旧站顶弹出去的下标（当前遍历到的i）-1，就是当前遍历到的i。减去新站顶的下标-1.

两个细节，第一个，栈如果pop以后被弹空了，就说明左面没有比目标的数更小的数了，此时的宽度是i-1.
         第二个，如果遇到两个一样的数，比如2，2.后一个2计算的面积是1，但是前一个的面积，因为这时候栈被弹空，所以计算的面积是4，这个无伤大雅。
         第三个，在栈最右面补上一个0，保证栈里面的数会被计算（除了0）小细节，不用真的遍历一遍数组再补个0.


每次做栈的题要注意 

一、什么时候压栈，什么时候弹栈，压栈就说明这个数据有用，弹栈了说明这个数据没用

数据没用有两种情况： 1. 找到了比他更优的解了，它不再被需要了
                    2.需要用他的值已经被计算出来了，不再需要他了。

二、计算的时候想一下栈顶和压栈的元素的关联，栈在遍历的时候，无非就是三个动态元素：弹出去的数（旧栈顶）；把他弹出去的数，弹出后的栈顶(新栈顶)

代码风格：不要把一大堆逻辑写在一起，能拆解的要拆解。

*/






