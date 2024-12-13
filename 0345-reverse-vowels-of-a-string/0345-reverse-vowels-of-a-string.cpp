class Solution {
public:
    string reverseVowels(string s) {
        vector<int> vowelIndex;
        unordered_set<char> set({'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'});
        for (int i = 0; i < s.size(); i++) {
            if (set.count(s[i])) {
                vowelIndex.push_back(i);
            }
        }
        
        int left = 0, right = vowelIndex.size() - 1;
        while (right >= left) {
            char tmp = s[vowelIndex[right]];
            s[vowelIndex[right]] = s[vowelIndex[left]];
            s[vowelIndex[left]] = tmp;
            left++;
            right--;
        }
        
        return s;
    }
};