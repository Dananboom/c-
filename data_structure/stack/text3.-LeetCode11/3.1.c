#define     MAX(a, b)   ((a) > (b) ? (a) : (b))
int maxArea(int* height, int heightSize){
    int max  = 0;
    for (int i = 0; i < heightSize; i++) {
        //遍历左面
        for (int j = i - 1; j >= 0; j--) {
            if (height[j] >= height[i]) {
                max = MAX((i - j) * height[i], max); 
            }
        }
        //遍历右面
        for (int j = i + 1; j < heightSize; j++) {
            if (height[j] >= height[i]) {
                max = MAX((j - i) * height[i], max);  
            }
        }
    }
    return max;
}