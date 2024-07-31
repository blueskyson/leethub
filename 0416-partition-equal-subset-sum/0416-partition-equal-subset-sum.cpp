class Solution {
public:
    bool canPartition(vector<int>& nums) {
        vector<int> dp(10001, 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        if (sum % 2 == 1)
            return false;

        int half = sum / 2;        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = half; j >= nums[i]; j--) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        
        return dp[half] == half;
    }
};