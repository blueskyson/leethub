class Solution {
public:
    vector<string> result;
    char startChars[8] = {'a', 'd', 'g', 'j', 'm', 'p', 't', 'w'};

    void backtrack(string& path, int index, string& digits) {
        if (path.size() == digits.size()) {
            result.push_back(path);
            return;
        }

        int num = digits[index] - '0';
        char startChar = startChars[num - 2];
        int endCount = num == 7 || num == 9 ? 4 : 3;
        for (int i = 0; i < endCount; i++) {
            path += startChar + i;
            backtrack(path, index + 1, digits);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        result.clear();
        if (digits == "") {
            return result;
        }
        
        string path = "";
        backtrack(path, 0, digits);
        return result;
    }
};