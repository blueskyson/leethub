class Solution {
public:    
    int jump(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }

        vector<int> minSteps(nums.size(), INT32_MAX);
        int distanceToEnd = 0;
        for (int i = nums.size() - 2; i >= 0; i--) {
            distanceToEnd++;
            if (nums[i] == 0) {
                continue;
            }

            if (nums[i] >= distanceToEnd) {
                minSteps[i] = 1;
                continue;
            }
            
            int jumpSize = i + nums[i] + 1 < minSteps.size() ? i + nums[i] + 1 : minSteps.size();
            int min = INT32_MAX;
            int minIndex = i + 1;
            for (int j = i + 1; j < jumpSize; j++) {
                if (minSteps[j] < min) {
                    min = minSteps[j];
                    minIndex = j;
                }
            }
            if (min < INT32_MAX) {
                minSteps[i] = minSteps[minIndex] + 1;
            }
        }
        
        return minSteps[0];
    }
};