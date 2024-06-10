/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int left = 0, right = numsSize - 1, writer = right;
    int *resultNums = (int*)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        nums[i] = nums[i] * nums[i];
    }

    while (writer >= 0) {
        if (nums[left] > nums[right]) {
            resultNums[writer] = nums[left];
            left++;
        } else {
            resultNums[writer] = nums[right];
            right--;
        }
        
        writer--;
    }
    
    *returnSize = numsSize;
    return resultNums;
}