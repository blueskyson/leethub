class Solution {
public:
    void reverse(string& s, int start, int end) {
        for (int i = start, j = end; j > i; i++, j--) {
            s[i] ^= s[j];
            s[j] ^= s[i];
            s[i] ^= s[j];
        }        
    }

    string reverseWords(string s) {
        // Remove repeating spaces
        int slow = 0, fast = 0;
        while (s[fast] == ' ')
            fast++;
        while (fast < s.size()) {
            if (fast > 0 && s[fast] == ' ' && s[fast - 1] == ' ') {
                fast++;
                continue;
            }
            s[slow] = s[fast];
            slow++;
            fast++;
        }
        
        if (slow > 0 && s[slow - 1] == ' ') {
            s.resize(slow - 1);
        } else {
            s.resize(slow);
        }
        
        // Reverse whole string
        reverse(s, 0, s.size() - 1);
        
        // Reverse back each word
        int start = 0;
        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                reverse(s, start, i - 1);
                start = i + 1;
            }
        }

        return s;
    }
};