class Solution {
public:
    bool isValid(vector<vector<char>>& board, int& row, int& col, char& num) {
        // row and col
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num) {
                return false;
            }
            
            if (board[i][col] == num) {
                return false;
            }
        }

        int boxRow = (row / 3) * 3;
        int boxCol = (col / 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[boxRow + i][boxCol + j] == num) {
                    return false;
                }
            }
        }
        
        return true;
    }

    bool backtrack(vector<vector<char>>& board, int n) {
        int row = n / 9, col = n % 9;
        while (n < 81 && board[row][col] != '.') {
            n++;
            row = n / 9;
            col = n % 9;
        }

        if (n == 81) {
            return true;
        }

        for (char a = '1'; a <= '9'; a += 1) {
            if (!isValid(board, row, col, a))
                continue;
            
            board[row][col] = a;
            if (backtrack(board, n + 1)) {
                return true;
            }
            board[row][col] = '.';
        }
                                
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0);
    }
};