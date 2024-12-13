class Solution {
public:
    void discover(vector<vector<char>>& grid, vector<vector<bool>>& discovered, int row, int col) {
        if (grid[row][col] == '0' || discovered[row][col] == true)
            return;
        discovered[row][col] = true;
        int width = grid[0].size(), height = grid.size();
        if (row > 0) {
            discover(grid, discovered, row - 1, col);
        }
        
        if (row < height - 1) {
            discover(grid, discovered, row + 1, col);
        }
        
        if (col > 0) {
            discover(grid, discovered, row, col - 1);
        }
        
        if (col < width - 1) {
            discover(grid, discovered, row, col + 1);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int width = grid[0].size(), height = grid.size();
        int result = 0;
        vector<vector<bool>> discovered(height, vector<bool>(width, false));
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (grid[i][j] == '1' && discovered[i][j] == false) {
                    discover(grid, discovered, i, j);
                    result++;
                }
            }
        }
        
        return result;
    }
};