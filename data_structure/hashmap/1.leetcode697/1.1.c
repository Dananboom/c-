/*这题要考虑三件事

数组的度
符合度的数
符合度的数的下标
因此三个hash表，或者是个结构体数组，key存数，value存每个数出现的频率（后面找到最大的），符合度的数（他们下标之差是最小的，
其实找到每个数第一次出现和最后一次出现的下标就好），后面就是拿符合度的数的下标来运算了。*/
 //原始版本
 int findShortestSubArray(int* nums, int numsSize){
    int max = 0, min = 0, length = 0, l = 0, r = 0; 
    int hashTable_fre[50005] = {0}, hashTable_left[50005] = {0}, hashTable_right[50005] = {0}, arr[numsSize];
    //找到度。
    for (int i = 0; i < numsSize; i++) {
        hashTable_fre[nums[i]]++;
        int temp = max;//temp保存之前的度
        max = max > hashTable_fre[nums[i]] ? max : hashTable_fre[nums[i]];//度更新了
        if(hashTable_fre[nums[i]] == 1) {//频率是1的时候，说明这个数只出现了一次
            //第一次出现的下标
            hashTable_left[nums[i]] = i;
            hashTable_right[nums[i]] = i;
        } else if(hashTable_fre[nums[i]] == max) {
            //最后一次出现的下标
            hashTable_right[nums[i]] = i;
        }
        if (temp != max) {//如果度变了，相当于前面都没用了，这时候双指针前移
            l = r;
        }
        //把符合当前度的数放入辅助数组中
        if(hashTable_fre[nums[i]] == max) {  
            arr[r] = nums[i]; 
            r++;
        }   
    }
    //计算辅助数组中有效值的下标
    for (int i = l; i < r; i++) {
        length = hashTable_right[arr[i]] - hashTable_left[arr[i]] + 1;
        if (min == 0){
            min = length;
        }
        min = min < length ? min : length;
    }
    return min;
}
