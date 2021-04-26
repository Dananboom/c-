#include <stdio.h>

int findShortestSubArray(int* nums, int numsSize){
    int max = 0, min, length = 0, index = 0, l = 0, r = 0; 
    int hashTable_fre[50005] = {0}, hashTable_left[50005] = {0}, hashTable_right[50005] = {0}, arr[numsSize];
    for (int i = 0; i < numsSize; i++) {
        arr[i] = -1;
    }
    //找到度。
    for (int i = 0; i < numsSize; i++) {
        hashTable_fre[nums[i]]++;
        int temp = max;//temp保存之前的度
        max = max > hashTable_fre[nums[i]] ? max : hashTable_fre[nums[i]];//度更新了
        if(hashTable_fre[nums[i]] == 1) {//频率是1的时候，说明这个数只出现了一次
            hashTable_left[nums[i]] = i;
            hashTable_right[nums[i]] = i;
        } else if(hashTable_fre[nums[i]] == max) {
            hashTable_right[nums[i]] = i;
        }
        if (temp != max) {//如果度变了
            l = r;
        }
        
        if(hashTable_fre[nums[i]] == max) {  
            arr[index] = nums[i]; 
            index++;
            r++;
        }   
    }
    for (int i = l; i <= r; i++) {
            if(arr[i] != -1) {
                length = hashTable_right[arr[i]] - hashTable_left[arr[i]] + 1;
                if (min == 0){
                    min = length;
                }
            }
            min = min < length ? min : length;
        }
    return min;
}
int main() {
    int arr[7] = {1,2,2,3,1,4,2};
    printf("%d", findShortestSubArray(arr,7));
}