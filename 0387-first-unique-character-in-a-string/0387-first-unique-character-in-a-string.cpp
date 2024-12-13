class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map;
        for (int i = 0; i < s.size(); i++) {
            if (map.find(s[i]) != map.end()) {
                map[s[i]] = -1;
            } else {
                map[s[i]] = i;
            }
        }
        
        int result = INT32_MAX;
        for (unordered_map<char, int>::iterator it = map.begin(); it != map.end(); it++) {
            if (it->second != -1)
                result = min(result, it->second);
        }
        
        if (result ==  INT32_MAX) {
            return -1;
        }
        return result;
    }
};