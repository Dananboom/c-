//这个版本和上面的差不多，区别是不用辅助数组，而是把每个数的下标之差算出来，找到最小的，当度发生变化时，把最小的更新，再继续算
int findShortestSubArray(int* nums, int numsSize){
    int max = 0, min = 52000, length = 0, flag = 0, hashTable_fre[50000] = {0}, hashTable_left[50000], hashTable_right[50000];//这三个hash表，只有要做判断的那个初始化就行
    for (int i = 0; i < numsSize; i++) {
        hashTable_fre[nums[i]]++;
        if(hashTable_fre[nums[i]] == 1) {//频率是1的时候，说明这个数只出现了一次
            hashTable_left[nums[i]] = i;
            hashTable_right[nums[i]] = i;
        } else if(hashTable_fre[nums[i]] >= max) {
            flag++;
            hashTable_right[nums[i]] = i;
            length = hashTable_right[nums[i]] - hashTable_left[nums[i]] + 1;
            if (hashTable_fre[nums[i]] > max ) { //度应该要更新
                min = 52000;
            }
            max = hashTable_fre[nums[i]];//度更新了
            min = min < length ? min : length;
        } 
    }
    return min = flag == 0 ? 1 : min;
}
