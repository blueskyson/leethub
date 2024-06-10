int search(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize;
    while (left < right) {
        int middle = (left + right) >> 1;
        if (nums[middle] == target) {
            return middle;
        }
        
        if (nums[middle] < target) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }

    return -1;
}