class Solution {
public:
    vector<string> result;
    vector<string> path;

    void backtrack(const string& s, int index) {
        if (path.size() == 4 && index == s.size()) {
            return result.push_back(path[0] + '.' + path[1] + '.' + path[2] + '.' + path[3]);
        }

        string segment = "";
        for (int i = 0; i < 3 && index + i < s.size(); i++) {
            segment += s[index + i];
            if (i > 0 && s[index] == '0') {
                return;
            }
            
            if (i == 2 && stoi(segment) > 255) {
                return;
            }
            
            path.push_back(segment);
            backtrack(s, index + i + 1);
            path.pop_back();
        }
    }
    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0);
        return result;
    }
};