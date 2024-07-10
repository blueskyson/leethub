class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtrack(vector<int>& nums, int startIndex) {
        result.push_back(path);
        for (int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtrack(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        result.clear();
        path.clear();
        backtrack(nums, 0);
        return result;
    }
};