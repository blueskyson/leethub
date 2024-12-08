class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i >= nums[j]) {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        
        // for (int i = 0; i < dp.size(); i++) {
        //     cout << dp[i] << " ";
        // }
        // cout << endl;
        return dp[target];
    }
};