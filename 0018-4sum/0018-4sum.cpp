class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > target && nums[i] >= 0) {
                break;
            }
            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }

            for (int j = i + 1; j < nums.size(); j++) {
                int halfSum = nums[i] + nums[j];
                if (halfSum > target && halfSum >= 0) {
                    break;
                }
                if (j > i + 1 && nums[j - 1] == nums[j]) {
                    continue;
                }

                int left = j + 1;
                int right = nums.size() - 1;
                while (right > left) {
                    long sum = (long)halfSum + nums[left] + nums[right];
                    if (sum > target) {
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        result.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        while (right > left && nums[right - 1] == nums[right])
                            right--;
                        while (right > left && nums[left + 1] == nums[left])
                            left++;
                        right--;
                        left++;
                    }
                }
                
            }
        }
        
        return result;
    }
};