class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    
    void backtrack(vector<int>& candidates, int target, int startIndex, int sum, vector<bool>& used) {
        if (sum == target) {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false)
                continue;

            sum += candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;
            backtrack(candidates, target, i + 1, sum, used);
            used[i] = false;
            path.pop_back();
            sum -= candidates[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        result.clear();
        path.clear();
        backtrack(candidates, target, 0, 0, used);
        return result;
    }
};