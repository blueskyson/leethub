class Solution {
public:
    string reverseStr(string s, int k) {
        int left = 0, right = k;
        while (1) {
            if (s.size() < right) {
                int l = left, r = s.size() - 1;
                while (l < r) {
                    int tmp = s[l];
                    s[l] = s[r];
                    s[r] = tmp;
                    l++;
                    r--;
                }
                
                break;
            }

            int l = left, r = right - 1;
            while (l < r) {
                int tmp = s[l];
                s[l] = s[r];
                s[r] = tmp;
                l++;
                r--;
            }
            left += 2 * k;
            right += 2 * k;
        }
        
        return s;
    }
};