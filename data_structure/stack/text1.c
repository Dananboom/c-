#include <stdio.h>
# include "./strack.c"

int main(){
    int a [7] = {3, 7, 5, 8, 6, 5, 6};
    strack_list p = strack_creat();
    strack_push(p,a[0]);
    for (int i = 0; i < 7; i++) {
        if (p->length == 3) {
            if(a[i + 1] > top_node(p)) {
                strack_pop(p);//最后一位
                if(a[i + 1] > top_node(p)) {
                    strack_pop(p);//第二位
                    if(a[i + 1] > top_node(p)) {
                        strack_pop(p);//最后一位
                        strack_push(p, a[i + 1]);
                    } else {
                        strack_push(p, a[i + 1]);
                    } 
                } else {
                    strack_push(p, a[i + 1]);
                } 
            }
        } else if(p->length == 2) { //如果栈里有两个元素
            if(a[i + 1] > top_node(p)) {//如果新的比栈顶大，就先弹
                strack_pop(p);
                if (a[i + 1] > top_node(p)) {//再比较
                    strack_pop(p);
                    strack_push(p, a[i + 1]);
                } else {
                    strack_push(p, a[i + 1]);
                }
            } else {
                strack_push(p, a[i + 1]);//如果不大，就压
            }

        } else if (p->length == 1) {
            if (a[i + 1] > top_node(p)) { //如果只有一个元素，并且后面的数比前面的数大的时候，先弹后压
                strack_pop(p);
                strack_push(p, a[i + 1]);
            } else {
                strack_push(p, a[i + 1]);
            }
        }
    }
    print_list(p);
}

