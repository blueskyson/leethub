class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtrack(vector<int>& nums, vector<bool> used) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i])
                continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtrack(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        backtrack(nums, used);
        return result;
    }
};