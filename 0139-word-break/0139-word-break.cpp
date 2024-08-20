class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 0; i <= s.size(); i++) {
            if (dp[i] == false) {
                continue;
            }

            for (string w : wordDict) {
                if (w.size() <= s.size() - i) {
                    bool sameStr = true;
                    for (int j = 0; j < w.size(); j++) {
                        if (w[j] != s[i + j]) {
                            sameStr = false;
                            break;
                        }
                    }
                    
                    if (dp[i + w.size()] == false && sameStr == true) {
                        dp[i + w.size()] = true;
                    }
                }
            }
        }
        
        return dp[s.size()];
    }
};