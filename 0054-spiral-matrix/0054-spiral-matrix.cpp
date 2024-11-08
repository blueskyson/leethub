class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int total = matrix.size() * matrix[0].size();
        int xStart = 0, xEnd = matrix[0].size(), yStart = 0, yEnd = matrix.size();
        while (result.size() < total) {
            // left to right
            for (int i = xStart; i < xEnd; i++) {
                result.push_back(matrix[yStart][i]);
            }
            xEnd -= 1;
            if (result.size() == total) {
                break;
            }

            // top to bottom
            for (int i = yStart + 1; i < yEnd; i++) {
                result.push_back(matrix[i][xEnd]);
            }
            yStart += 1;
            if (result.size() == total) {
                break;
            }

            // right to left
            for (int i = xEnd - 1; i >= xStart; i--) {
                result.push_back(matrix[yEnd - 1][i]);
            }
            yEnd -= 1;
            if (result.size() == total) {
                break;
            }

            // bottom to top
            for (int i = yEnd - 1; i >= yStart; i--) {
                result.push_back(matrix[i][xStart]);
            }
            xStart += 1;
            if (result.size() == total) {
                break;
            }
        }
        
        return result;
    }
};