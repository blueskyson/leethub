class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> a(nums.size(), 1);
        vector<int> b(nums.size(), 1);
        vector<int> result;
        a[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            a[i] = nums[i] * a[i - 1];
        }
        
        b[nums.size() - 1] = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--) {
            b[i] = nums[i] * b[i + 1];
        }
        
        result.push_back(b[1]);
        for (int i = 1; i < nums.size() - 1; i++) {
            result.push_back(a[i - 1] * b[i + 1]);
        }
        result.push_back(a[nums.size() - 2]);
        return result;
    }
};