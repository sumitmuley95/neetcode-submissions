class Solution {
public:
    void solve(vector<vector<char>>& board) {
        //border che zeros la queue madhe tak aani 4 direction madhe ja jithe 'O' dista tela visited mark kar
        //lastly je visited nahi aani 'O' aahe tenla X mark kar
        if(board.empty() || board[0].empty()) return;
        queue<pair<int,int>>q;
        //borders madhe iterate kar
        vector<vector<bool>>vis(board.size(),vector<bool>(board[0].size(),false));
        for(int j = 0; j < board[0].size(); j++) {
            if(board[0][j] == 'O') {
                q.push({0,j});
                vis[0][j] = true;
            }
            if(board[board.size()-1][j] == 'O') {
                q.push({board.size()-1,j});
                vis[board.size()-1][j] = true;
            }
        }
        for(int i = 0; i < board.size(); i++) {
            if(board[i][0] == 'O') {
                q.push({i,0});
                vis[i][0] = true;
            }
            if(board[i][board[0].size()-1] == 'O') {
                q.push({i,board[0].size()-1});
                vis[i][board[0].size()-1] = true;
            }
        }

        while(!q.empty()) {
            auto elem = q.front();
            q.pop();

            int row = elem.first;
            int col = elem.second;

            if(row+1 >= 0 && col >= 0 && row+1 < board.size() && col < board[0].size() && board[row+1][col] == 'O' && !vis[row+1][col]) {
                vis[row+1][col] = true;
                q.push({row+1,col});
            }
            if(row-1 >= 0 && col >= 0 && row-1 < board.size() && col < board[0].size() && board[row-1][col] == 'O' && !vis[row-1][col]) {
                vis[row-1][col] = true;
                q.push({row-1,col});
            }
            if(row >= 0 && col+1 >= 0 && row < board.size() && col+1 < board[0].size() && board[row][col+1] == 'O' && !vis[row][col+1]) {
                vis[row][col+1] = true;
                q.push({row,col+1});
            }
            if(row >= 0 && col-1 >= 0 && row < board.size() && col-1 < board[0].size() && board[row][col-1] == 'O' && !vis[row][col-1]) {
                vis[row][col-1] = true;
                q.push({row,col-1});
            }
        }

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == 'O' && vis[i][j] == false) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
