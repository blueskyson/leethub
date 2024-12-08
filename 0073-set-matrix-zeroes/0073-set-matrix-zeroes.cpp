class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int width = matrix[0].size(), height = matrix.size();
        vector<pair<int, int>> zeros;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (matrix[i][j] == 0) {
                    zeros.push_back(pair<int, int>(i, j));
                }
            }
        }
        
        for (auto zero : zeros) {
            // column
            for (int i = 0; i < height; i++) {
                matrix[i][zero.second] = 0;
            }
            
            // row
            for (int i = 0; i < width; i++) {
                matrix[zero.first][i] = 0;
            }
        }
        
        // for (int i = 0; i < height; i++) {
        //     for (int j = 0; j < width; j++) {
        //         cout << matrix[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }
};