class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    
    void backtrack(vector<int>& candidates, int target, int startIndex, int sum) {
        if (sum == target) {
            result.push_back(path);
            return;
        }
        
        if (sum > target) {
            return;
        }

        for (int i = startIndex; sum < target && i < candidates.size(); i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtrack(candidates, target, i, sum);
            path.pop_back();
            sum -= candidates[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        path.clear();
        backtrack(candidates, target, 0, 0);
        return result;
    }
};