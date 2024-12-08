class Solution {
public:
    bool isValid(string s) {
        if (s[0] == '0')
            return false;
        int value = stoi(s);
        return value >= 1 && value <= 26;
    }
    
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }
        if (s.size() == 1) {
            return 1;
        }
        
        vector<int> dp(s.size(), 0);
        dp[0] = 1;
        if (s[1] == '0') {
            if (isValid(s.substr(0, 2))) {
                dp[1] = 1;
            } else {
                return 0;
            }
        } else {
            if (isValid(s.substr(0, 2))) {
                dp[1] = 2;
            } else {
                dp[1] = 1;
            }
        }
        
        for (int i = 2; i < s.size(); i++) {
            if (s[i] == '0') {
                if (isValid(s.substr(i - 1, 2))) {
                    dp[i] = dp[i - 2];
                } else {
                    return 0;
                }
            } else {
                if (isValid(s.substr(i - 1, 2))) {
                    dp[i] = dp[i - 1] + dp[i - 2];
                } else {
                    dp[i] = dp[i - 1];
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