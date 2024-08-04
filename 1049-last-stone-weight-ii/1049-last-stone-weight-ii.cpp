class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (int i = 0; i < stones.size(); i++) {
            sum += stones[i];
        }

        int half = sum / 2;
        vector<int> dp(half + 1, 0);
        for (int i = 0; i < stones.size(); i++) {
            for (int j = half; j >= stones[i]; j--) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        
        return (sum - dp[half]) - dp[half];
    }
};