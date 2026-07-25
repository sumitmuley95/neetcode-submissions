class Solution {
public:
    int solve(vector<vector<int>>& matrix, int i, int j, int prev, vector<vector<int>>& dp) {
        //base case
        if(i < 0 || j < 0 || i == matrix.size() || j == matrix[0].size() || prev >= matrix[i][j]) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        //recursion
        prev = matrix[i][j];
        return dp[i][j] = 1 + max(solve(matrix,i,j+1,prev,dp), max(solve(matrix,i-1,j,prev,dp), max(solve(matrix,i,j-1,prev,dp),solve(matrix,i+1,j,prev,dp))));
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size()+1,vector<int>(matrix[0].size()+1,-1));
        int result = 0;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                result = max(result,solve(matrix,i,j,INT_MIN,dp));
            }
        }
        return result;
    }
};
