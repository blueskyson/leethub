class Solution {
public:
    void backtrack(vector<vector<int>>& result, vector<int>& path, const int& k, const int& n, int startIndex) {
        int sum = 0;
        for (int i = 0; i < path.size(); i++) {
            sum += path[i];
        }

        if (sum > n) {
            return;
        }

        if (path.size() == k && sum == n) {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i <= 9; i++) {
            path.push_back(i);
            backtrack(result, path, k, n, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> path;
        backtrack(result, path, k, n, 1);
        return result;
    }
};