class Solution {
public:
    bool result = false;
    void solve(vector<vector<char>>& board, string& word, int i, int j, int it) {
        //base case
        if(it == word.size()) {
            result = true;
            return;
        }
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return;
        if(board[i][j] == word[it] && result == false) {
            char originalElem = board[i][j];
            board[i][j] = '#';
            solve(board,word,i-1,j,it+1);
            solve(board,word,i,j+1,it+1);
            solve(board,word,i+1,j,it+1);
            solve(board,word,i,j-1,it+1);
            board[i][j] = originalElem;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                char elem = board[i][j];
                if(elem == word[0]) {
                    solve(board,word,i,j,0);
                    if(result) return true;
                }
            }
        }
        return result;
    }
};
