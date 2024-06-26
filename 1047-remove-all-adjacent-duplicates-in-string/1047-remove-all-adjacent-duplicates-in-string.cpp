class Solution {
public:
    string removeDuplicates(string s) {
        deque<char> q;
        for (int i = 0; i < s.size(); i++) {
            if (!q.empty() && q.back() == s[i]) {
                q.pop_back();
            } else {
                q.push_back(s[i]);
            }
        }
        
        string result(q.begin(), q.end());
        return result;
    }
};