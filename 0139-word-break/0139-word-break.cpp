class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size(), false);
        for (int i = 0; i < s.size(); i++) {
            if (i > 0 && dp[i - 1] != true) {
                continue;
            }
            
            for (string word : wordDict) {
                if (i + word.size() > s.size()) {
                    continue;
                }

                bool isSame = true;
                for (int j = 0; j < word.size(); j++) {
                    if (s[i + j] != word[j]) {
                        isSame = false;
                        break;
                    }
                }
                
                if (isSame) {
                    dp[i + word.size() - 1] = true;
                }
            }
        }
        
        // for (int i = 0; i < dp.size(); i++) {
        //     cout << dp[i] << " ";
        // }
        // cout << endl;
        
        return dp[s.size() - 1];
    }
};