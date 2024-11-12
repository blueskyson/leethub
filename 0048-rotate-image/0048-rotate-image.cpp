class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int radius = matrix.size() / 2;        
        for (int i = 0; i < radius; i++) {
            int length = matrix.size() - (2 * i);
            int xStart = i, yStart = i;
            int xEnd = matrix.size() - i, yEnd = matrix.size() - i;
            for (int j = 0; j < length - 1; j++) {
                int a = matrix[yStart][xStart + j];
                int b = matrix[yStart + j][xEnd - 1];
                int c = matrix[yEnd - 1][xEnd - 1 - j];
                int d = matrix[yEnd - 1 - j][xStart];
                // cout << a << " " << b << " " << c << " " << d << endl;
                matrix[yStart][xStart + j] = d;
                matrix[yStart + j][xEnd - 1] = a;
                matrix[yEnd - 1][xEnd - 1 - j] = b;
                matrix[yEnd - 1 - j][xStart] = c;
            }
        }
    }
};