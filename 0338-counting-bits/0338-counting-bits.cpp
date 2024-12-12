class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        result.push_back(0);
        for (int i = 1; i <= n; i++) {
            int bits = result[i / 2] + (i & 1);
            result.push_back(bits);
        }
        
        return result;
    }
};