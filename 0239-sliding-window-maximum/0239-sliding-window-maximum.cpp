class Solution {
public:
    class MyQueue {
    public:
        deque<int> q;
        void push(int val) {
            while (!q.empty() && val > q.back()) {
                q.pop_back();
            }
            q.push_back(val);
        }

        void pop(int val) {
            if (!q.empty() && q.front() == val) {
                q.pop_front();
            }
        }

        int front() {
            return q.front();
        }
    };

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        MyQueue q;
        for (int i = 0; i < k; i++) {
            q.push(nums[i]);
        }
        result.push_back(q.front());
        for (int i = 0; i < nums.size() - k; i++) {
            q.pop(nums[i]);
            q.push(nums[i + k]);
            result.push_back(q.front());
        }
        return result;
    }
};