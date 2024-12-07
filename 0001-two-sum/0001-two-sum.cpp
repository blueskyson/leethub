class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            auto tmp = map.find(target - nums[i]);
            if (tmp != map.end()) {
                vector<int> result;
                result.push_back(tmp->second);
                result.push_back(i);
                return result;
            }
            map[nums[i]] = i;
        }
        
        vector<int> empty;
        return empty;
    }
};