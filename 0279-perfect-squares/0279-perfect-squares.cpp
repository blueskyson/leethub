class Solution {
public:
    int numSquares(int n) {
        vector<int> nums;
        for (int i = 1; i <= 100; i++) {
            int square = i * i;
            if (square > n) {
                break;
            }
            nums.push_back(square);
        }
        
        vector<int> dp(n + 1, INT32_MAX);
        dp[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = nums[i]; j <= n; j++) {
                dp[j] = min(dp[j], dp[j - nums[i]] + 1);
            }
        }
        
        return dp[n];
    }
};