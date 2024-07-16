class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b) {
        return a[0] < b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 1) {
            return 1;
        }

        sort(points.begin(), points.end());
        int arrow = 0;
        long long curEnd = INT64_MIN;
        for (int i = 0; i < points.size(); i++) {
            curEnd = min((long long)points[i][1], curEnd);
            if (points[i][0] > curEnd) {
                arrow++;
                curEnd = points[i][1];
            }
        }
        
        return arrow;
    }
};