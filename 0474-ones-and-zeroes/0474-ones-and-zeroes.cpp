class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp;
        for (int i = 0; i <= m; i++) {
            dp.push_back(vector<int>(n + 1, 0));
        }
        
        for (string s : strs) {
            int zeroNum = 0, oneNum = 0;
            for (char c : s) {
                if (c == '0') {
                    zeroNum++;
                } else {
                    oneNum++;
                }
            }

            for (int i = m; i >= zeroNum; i--) {
                for (int j = n; j >= oneNum; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
                }       
            }
        }
        
        return dp[m][n];
    }
};