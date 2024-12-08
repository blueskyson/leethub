class Solution {
public:
    bool recurse(vector<vector<char>>& board, string word, int index, int col, int row, vector<vector<bool>>& visited) {
        if (index == word.size() - 1) {
            return true;
        }
        
        int width = board[0].size(), height = board.size();
        if (row > 0 &&
            board[row - 1][col] == word[index + 1] &&
            !visited[row - 1][col]) {
            visited[row - 1][col] = true;
            if (recurse(board, word, index + 1, col, row - 1, visited))
                return true;
            visited[row - 1][col] = false;
        }
        
        if (col < width - 1 &&
            board[row][col + 1] == word[index + 1] &&
            !visited[row][col + 1]) {
            visited[row][col + 1] = true;
            if (recurse(board, word, index + 1, col + 1, row, visited))
                return true;
            visited[row][col + 1] = false;
        }
        
        if (row < height - 1 &&
            board[row + 1][col] == word[index + 1] &&
            !visited[row + 1][col]) {
            visited[row + 1][col] = true;
            if (recurse(board, word, index + 1, col, row + 1, visited))
                return true;
            visited[row + 1][col] = false;
        }
        
        if (col > 0 &&
            board[row][col - 1] == word[index + 1] &&
            !visited[row][col - 1]) {
            visited[row][col - 1] = true;
            if (recurse(board, word, index + 1, col - 1, row, visited))
                return true;
            visited[row][col - 1] = false;
        }
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int width = board[0].size(), height = board.size();
        vector<vector<bool>> visited(height, vector<bool>(width, false));
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (board[i][j] != word[0]) {
                    continue;
                }
                
                visited[i][j] = true;
                bool result = recurse(board, word, 0, j, i, visited);
                if (result == true) {
                    return true;
                }
                visited[i][j] = false;
            }
        }
        
        return false;
    }
};