class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int A = 0;
        for (int i = 0; i <= nums.size(); i++) {
            A ^= i;
        }
        
        int B = 0;
        for (int i = 0; i < nums.size(); i++) {
            B ^= nums[i];
        }
        
        return A ^ B;
    }
};