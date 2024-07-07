class Solution {
public:
    vector<vector<string>> result;
    vector<string> path;

    bool isPalindrome(const string& s) {
        for (int i = 0, j = s.size() - 1; i <= j; i++, j--) {
            if (s[i] != s[j])
                return false;
        }
        
        return true;
    }

    void backtrack(string& s, int startIndex) {
        if (startIndex >= s.size()) {
            result.push_back(path);
            return;
        }

        string substr = "";
        for (int i = startIndex; i < s.size(); i++) {
            substr += s[i];
            if (isPalindrome(substr)) {
                path.push_back(substr);
                backtrack(s, i + 1);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<bool> delimiters(s.size() - 1, true);
        backtrack(s, 0);
        return result;
    }
};