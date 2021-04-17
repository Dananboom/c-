# include <stdio.h>
int largestRectangleArea(int* heights, int heightsSize){
    int num;//num是宽度
    int max = 0;
    int result;
    for (int i = 0; i < heightsSize; i++) {
        for (int j = i - 1; j >= 0; j--) { //先遍历左边的 //等于号：如果两个数一样的话（都是最小）可以直接跳出去，左面和右面只要判断一次就可
            if(heights[j] < heights[i]) {
                break;
            } else {
                num++;
            }
        }
        for (int j = i + 1; j <= heightsSize - 1; j++) { //右边的  这里控制数组不要越界，虽然有这个意识但是忘记数组是从0开始的了，最后还是越界了。
            if (heights[j] <= heights[i]) {
                break;
            } else {
                num++;
            }
        }
        result = num * heights[i];

        if (result > max) {
            max = result;
        }
        num = 1;//num不要忘记算自身也有宽度，宽度是1.而且不要忘记恢复初始状态。
    }
    return max;
}
int main() {
    int arr[3] = {2, 1, 2};
    printf("%d",largestRectangleArea(arr, 3));
}

//思路：
/*  
要算面积，面积首先是宽高，在这道题中，高度显然好控制一些，宽度是不好找的
基本思路就是遍历数组中的每个数，以数组中的第i个为高，往左往右算他的宽度，
怎么找宽度？这是最主要的
以当前的为高，向左向右找到第一个比当前的i小的数，算出面积再逐个比较，
遇到比当前的i小数的话意味这什么？如果这个小的数也被放在矩形里面计算，那这个矩形的高就不再是i了，因为显然在底确定的情况下，面积是由所有矩形中最小的矩形决定的
把i当成矩形的高，实际上默认了i是所有矩形中最小的一个，它把比他大的矩形都“削去了”，只剩下和他一样高的。
*/