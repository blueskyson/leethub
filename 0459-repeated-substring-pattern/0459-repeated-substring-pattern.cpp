class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string sub = "";
        for (int i = 0; i < s.size() / 2; i++) {
            sub += s[i];
            int cur = 0, j = 0;
            for (; j < s.size(); j++) {
                if (s[j] != sub[cur]) {
                    break;
                }
                cur++;
                if (cur == sub.size()) {
                    cur = 0;
                }
            }
            
            if (j == s.size() && cur == 0) {
                return true;
            }
        }
        
        return false;
    }
};