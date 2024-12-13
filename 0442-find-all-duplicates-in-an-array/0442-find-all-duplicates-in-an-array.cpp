class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> result;
        int i = 1;
        while (i < nums.size()) {
            if (nums[i] == nums[i - 1]) {
                result.push_back(nums[i]);
                while (i < nums.size() && nums[i] == nums[i - 1]) {
                    i++;
                }
            } else {
                i++;
            }
        }
        
        return result;
    }
};