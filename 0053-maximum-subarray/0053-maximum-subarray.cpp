class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum = 0, max_sum = INT32_MIN;
        for (int i = 0; i < nums.size(); i++) {
            current_sum += nums[i];
            max_sum = max(max_sum, current_sum);
            if (current_sum < 0) {
                current_sum = 0;
            }
        }
        return max_sum;
    }
};