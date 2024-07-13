class Solution {
public:    
    int jump(vector<int>& nums) {
        int curDistance = 0;
        int ans = 0;
        int nextDistance = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            nextDistance = max(nums[i] + i, nextDistance);
            if (i == curDistance) {
                curDistance = nextDistance;
                ans++;
            }
        }
        return ans;
    }
};