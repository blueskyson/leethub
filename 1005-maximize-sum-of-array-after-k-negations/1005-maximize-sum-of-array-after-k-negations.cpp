class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int index = 0, count = 0;
        while (index < nums.size() && nums[index] < 0 && k > 0) {
            nums[index] = -nums[index];
            index++;
            k--;
        }
        
        if (k % 2) {
            if (index == nums.size() || (index > 0 && nums[index - 1] < nums[index])) {
                nums[index - 1] = -nums[index - 1];
            } else {
                nums[index] = -nums[index];
            }
        }
        
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans += nums[i];
        }
        return ans;
    }
};