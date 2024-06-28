class Solution {
public:
    class cmp {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pri;
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            pri.push(*it);
            if (pri.size() > k) {
                pri.pop();
            }
        }
        
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri.top().first;
            pri.pop();
        }
        
        return result;
    }
};