class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int freshCount = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 2) q.push({i,j});
                else if(grid[i][j] == 1) freshCount++;
            }
        }

        if(freshCount == 0) return 0;
        if(q.empty()) return -1;

        while(!q.empty()) {
            auto rotten = q.front();
            int r = rotten.first;
            int c = rotten.second;

            q.pop();

            if(r+1 >= 0 && c >= 0 && r+1 < grid.size() && c < grid[0].size() && grid[r+1][c] == 1) {
                grid[r+1][c] = 1 + grid[r][c];
                q.push({r+1,c});
                freshCount--;
            }
            if(r-1 >= 0 && c >= 0 && r-1 < grid.size() && c < grid[0].size() && grid[r-1][c] == 1) {
                grid[r-1][c] = 1 + grid[r][c];
                q.push({r-1,c});
                freshCount--;
            }
            if(r >= 0 && c+1 >= 0 && r < grid.size() && c+1 < grid[0].size() && grid[r][c+1] == 1) {
                grid[r][c+1] = 1 + grid[r][c];
                q.push({r,c+1});
                freshCount--;
            }
            if(r >= 0 && c-1 >= 0 && r < grid.size() && c-1 < grid[0].size() && grid[r][c-1] == 1) {
                grid[r][c-1] = 1 + grid[r][c];
                q.push({r,c-1});
                freshCount--;
            }
        }

        if(freshCount > 0) return -1;
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) return -1;
            }
        }
        
        int result = INT_MIN;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                result = max(result,grid[i][j]);
            }
        }
        return result-2;
    }
};
