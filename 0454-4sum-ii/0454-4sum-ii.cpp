class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> map;
        for (int num1 : nums1) {
            for (int num2 : nums2) {
                map[num1 + num2] += 1;
            }
        }

        int count = 0;
        for (int num3 : nums3) {
            for (int num4 : nums4) {
                int offset = 0 - (num3 + num4);
                if (map.find(offset) != map.end()) {
                    count += map[offset];
                }
            }
        }
        
        return count;
    }
};