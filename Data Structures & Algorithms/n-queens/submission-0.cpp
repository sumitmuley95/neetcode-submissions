class Solution {
public:
    unordered_map<int,bool> rowCheck;
    unordered_map<int,bool> lowerDiagonal;
    unordered_map<int,bool> upperDiagonal;
    void addToResult(vector<vector<char>>& board, vector<vector<string>>& result, int n) {
        vector<string>tempAns;
        for(int row = 0; row < n; row++) {
            string output = "";
            for(int col = 0; col < n; col++) {
                output += board[row][col];
            }
            tempAns.push_back(output);
        }
        result.push_back(tempAns);
    }
    bool isSafe(int row, int col, vector<vector<char>>& board) {
        if(rowCheck[row]) return false;
        if(lowerDiagonal[row+col]) return false;
        if(upperDiagonal[row-col]) return false;
        return true;
    }
    void solve(vector<vector<char>>& board, vector<vector<string>>& result, int col, int n) {
        //base case 
        if(col >= n) {
            addToResult(board,result,n);
        }

        for(int row = 0; row < n; row++) {
            if(isSafe(row,col,board)) {
                board[row][col] = 'Q';
                rowCheck[row] = true;
                lowerDiagonal[row+col] = true;
                upperDiagonal[row-col] = true;

                solve(board,result,col+1,n);

                //backtrack
                board[row][col] = '.';
                rowCheck[row] = false;
                lowerDiagonal[row+col] = false;
                upperDiagonal[row-col] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>result;
        vector<vector<char>>board(n,vector<char>(n,'.'));
        solve(board,result,0,n);
        return result;
    }
};
