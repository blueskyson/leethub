class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<unsigned> dp(amount + 1, INT32_MAX);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        
        if (dp[amount] == INT32_MAX) {
            return -1;
        }
        
        return dp[amount];
    }
};