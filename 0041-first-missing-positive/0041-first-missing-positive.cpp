class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, target = 1;
        while (i < nums.size() && nums[i] <= 0) {
            i++;
        }
        
        while (i < nums.size()) {
            if (nums[i] == target) {
                i++;
                while (i < nums.size() && nums[i] == target) {
                    i++;
                }
                target++;
            } else {
                return target;
            }
        }
        
        return target;
    }
};