class Solution {
public:
    vector<vector<string>> result;

    vector<string> buildPuzzle(vector<vector<bool>>& board) {
        vector<string> vec;
        for (int i = 0; i < board.size(); i++) {
            string row = "";
            for (int j = 0; j < board.size(); j++) {
                row += board[i][j] == true ? 'Q' : '.';
            }
            vec.push_back(row);
        }
        return vec;
    }
    
    bool canPutQueen(vector<vector<bool>>& board, int row, int col) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j]) {
                    if (abs(i - row) == abs(j - col))
                        return false;
                    if (j == col)
                        return false;
                }
            }
        }

        return true;
    }
    
    void traverse(vector<vector<bool>>& board, int rowNum) {
        if (rowNum == board.size()) {
            result.push_back(buildPuzzle(board));
            return;
        }
        for (int i = 0; i < board.size(); i++) {
            if (canPutQueen(board, rowNum, i)) {
                board[rowNum][i] = true;
                traverse(board, rowNum + 1);
                board[rowNum][i] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<bool>> board;
        for (int i = 0; i < n; i++) {
            vector<bool> row(n, false);
            board.push_back(row);
        }
        traverse(board, 0);
        return result;
    }
};