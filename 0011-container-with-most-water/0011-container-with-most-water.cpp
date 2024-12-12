class Solution {
public:
    int maxArea(vector<int>& height) {
        int leftTall = 0, rightTall = height.size() - 1;
        int result = min(height[0], height[height.size() - 1]) * (height.size() - 1);
        for (int i = 0; i < height.size(); i++) {
            if (height[i] < leftTall) {
                continue;
            }
            
            leftTall = height[i];
            int rightTall = height[height.size() - 1];
            for (int j = height.size() - 1; j > i; j--) {
                if (height[j] < rightTall) {
                    continue;
                }
                int h = min(height[i], height[j]);
                int v = h * (j - i);
                result = max(v, result);
            }
        }
        return result;
    }
};