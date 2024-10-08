class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        } else if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        
        // Select the 1st
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = nums[0];
        for (int i = 2; i < nums.size() - 1; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        
        int result1 = dp[nums.size() - 2];
        
        // Unselect the 1st
        fill(dp.begin(), dp.end(), 0);
        dp[1] = nums[1];
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        
        int result2 = dp[nums.size() - 1];
        return max(result1, result2);
    }
};