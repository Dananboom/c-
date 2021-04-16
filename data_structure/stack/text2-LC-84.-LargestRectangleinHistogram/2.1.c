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