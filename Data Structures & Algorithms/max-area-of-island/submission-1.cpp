class Solution {
public:
    int solve(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j) {
        //base case
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] == 0 || vis[i][j]) return 0;
        //ek case main baki recursion
        if(grid[i][j] == 1 && !vis[i][j]) {
            vis[i][j] = true;
            return 1+solve(grid,vis,i+1,j)+solve(grid,vis,i-1,j)+solve(grid,vis,i,j+1)+solve(grid,vis,i,j-1);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
        int result = INT_MIN;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                result = max(result,solve(grid,vis,i,j));
            }
        }
        return result;
    }
};
