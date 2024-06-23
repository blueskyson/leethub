class Solution {
public:
    int strStr(string haystack, string needle) {
        int endpoint = haystack.size() - needle.size();
        for (int i = 0; i <= endpoint; i++) {
            int j = i;
            int cursor = 0;
            while (cursor < needle.size()) {
                if (haystack[j] != needle[cursor]) {
                    break;
                }
                
                j++;
                cursor++;
            }
            
            if (cursor == needle.size()) {
                return i;
            }
        }
        
        return -1;
    }
};