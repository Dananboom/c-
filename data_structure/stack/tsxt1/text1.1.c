#include <stdio.h>
# include "../stack.c"
//第二个版本
//虽然用了两个循环，但是由于后面的那个栈的循环和数据多少不是线性关系，后面的那个循环最多循环栈的深度那么多次，而且几率很小
int main() {
    int a[10000];
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    stack_list p = stack_creat();
    stack_push(p, a[0]);
    for (int i = 0; i < n - 2; i++){ //因为最后i + 1 会越界，所以循环少循环一次。
        for (int j = 0; j < m; j++) {//循环最多比m次，
            if(a [i + 1] > top_node(p)) {//如果后面的大于前面的
                stack_pop(p);
                if(p->length != 0){
                    continue;
                } else {
                    stack_push(p, a[i + 1]);
                    break;
                }
            } else {
                stack_push(p, a[i + 1]);
                break;
            }
        }
    }
    if(a[n - 1] > top_node(p)) {
        if (p->length < m){//考虑栈的深度，如果栈里面深度不够，就不pop了
            stack_push(p, a[n - 1]);
        } else { 
            stack_pop(p);
            stack_push(p, a[n - 1]);
        }
    }
    print_list(p);
}