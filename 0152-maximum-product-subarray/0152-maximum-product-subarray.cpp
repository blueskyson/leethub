class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        int current_max = nums[0], current_min = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) {
                int tmp = current_max;
                current_max = current_min;
                current_min = tmp;
            }
            
            current_max = max(nums[i], current_max * nums[i]);
            current_min = min(nums[i], current_min * nums[i]);
            result = max(result, current_max);
        }
        
        return result;
    }
};