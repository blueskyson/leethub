class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT32_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > result) {
                result = sum;
            }
            if (sum < 0) {
                sum = 0; // reset
            }
        }
        return result;
    }
};