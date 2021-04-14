#include <stdio.h>
# include "../stack.c"
//原始版本，灵活性很差
int main(){
    int a [7] = {3, 7, 5, 8, 6, 5, 9};
    stack_list p = stack_creat();
    stack_push(p, a[0]);
    for (int i = 0; i < 7 - 1; i++) {
        if (p->length == 1) {
            if (a[i + 1] > top_node(p)) { //如果只有一个元素，并且后面的数比前面的数大的时候，先弹后压
                stack_pop(p);
                stack_push(p, a[i + 1]);
            } else {
                stack_push(p, a[i + 1]);
            } 
        } else if (p->length == 2) {
            if (a[i + 1] > top_node(p)){
                stack_pop(p);
                if (a[i + 1] > top_node(p)){
                    stack_pop(p);
                    stack_push(p, a[i + 1]);
                } else {
                    stack_push(p, a[i + 1]);
                }
            } else if (a[i + 1] < top_node(p)) {
                stack_push(p, a[i + 1]);
            }
        } else if (p->length == 3) {
            if(a[i + 1]  > top_node(p)){//最外面的
                stack_pop(p);
                stack_push(p, a[i + 1]); 
            }
        }
    }
    print_list(p);
}

