class Solution {
public:
    bool matrix(vector<vector<char>>& board, int row, int col) {
        int startRow = row - (row%3);
        int startCol = col - (col%3);

        for(int a = startRow; a < startRow+3; a++) {
            for(int b = startCol; b < startCol+3; b++) {
                if(a == row && b == col) continue;
                if(board[a][b] == board[row][col]) return false;
            }
        }

        return true;
    }

    bool verticalCheck(vector<vector<char>>& board, int row, int col) {
        for(int i = 0; i < 9; i++) {
            if(row != i && board[i][col] == board[row][col]) return false;
        }

        return true;
    }

    bool horizontalCheck(vector<vector<char>>& board, int row, int col) {
        for(int j = 0; j < 9; j++) {
            if(col != j && board[row][j] == board[row][col]) return false;
        }

        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == '.') continue;
                if(!matrix(board,i,j) || !verticalCheck(board,i,j) || !horizontalCheck(board,i,j)) return false;
            }
        }

        return true;
    }
};
