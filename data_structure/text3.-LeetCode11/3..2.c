#define     MAX(a, b)   ((a) > (b) ? (a) : (b))
int maxArea(int* height, int heightSize){
    int max  = 0;
    int r = heightSize - 1, l = 0;
    while (l < r) {
        if (height[r] < height[l]) {
            max = MAX((r - l) * height[r], max);
            r--;
        } else {
            max = MAX((r - l) * height[l], max);
            l++;
        }
    }
    return max;
}