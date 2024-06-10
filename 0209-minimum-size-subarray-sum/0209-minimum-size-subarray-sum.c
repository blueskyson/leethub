int minSubArrayLen(int target, int* nums, int numsSize) {
    int currentSum = 0, minLength = INT32_MAX;
    int left = 0, right = 0;
    for (; right < numsSize; right++) {
        currentSum += nums[right];
        while (currentSum >= target) {
            int currentLength = right - left + 1;
            if (currentLength < minLength) {
                minLength = currentLength;
            }
            currentSum -= nums[left];
            left++;
        }
    }
    
    return minLength == INT32_MAX ? 0 : minLength;
}