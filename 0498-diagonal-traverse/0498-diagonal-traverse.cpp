class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int width = mat[0].size();
        int height = mat.size();
        int total = mat.size() * mat[0].size();
        vector<int> result;
        int i = 0, xStart = 0, yStart = 0;
        while (result.size() < total) {
            if (i % 2 == 0) { // left bottom to right top
                int x = xStart, y = yStart;
                while (1) {
                    result.push_back(mat[y][x]);
                    cout << mat[y][x] << " ";
                    if (y == 0 && x < width - 1) {
                        xStart = x + 1;
                        yStart = y;
                        break;
                    }
                    
                    if (x == width - 1) {
                        xStart = x;
                        yStart = y + 1;
                        break;
                    }
                    
                    x++;
                    y--;
                }
            } else { // right top to left bottom
                int x = xStart, y = yStart;
                while (1) {
                    result.push_back(mat[y][x]);
                    cout << mat[y][x] << " ";
                    if (x == 0 && y < height - 1) {
                        xStart = x;
                        yStart = y + 1;
                        break;
                    }
                    
                    if (y == height - 1) {
                        xStart = x + 1;
                        yStart = y;
                        break;
                    }
                    
                    x--;
                    y++;
                }
            }
            
            cout << endl;
            i++;
        }
        
        return result;
    }
};