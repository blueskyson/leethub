class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        unordered_set<string> set = unordered_set<string>(forbidden.begin(), forbidden.end());
        int result = 0;
        int right = word.size() - 1;
        for (int left = word.size() - 1; left >= 0; left--) {
            for (int k = left; k < min(left + 10, right + 1); k++) {
                if (set.count(word.substr(left, k - left + 1))) {
                    right = k - 1;
                    break;
                }
            }
            result = max(result, right - left + 1);
        }
        
        return result;
    }
};