class Solution {
public:
    int solve(int n, int target, vector<int>& dp) {
        //base case
        if(target == n) {
            return 1;
        }
        if(target > n) return 0;
        if(dp[target] != -1) return dp[target];
        dp[target] = solve(n,target+1,dp) + solve(n,target+2,dp);
        return dp[target];
    }
    int climbStairs(int n) {
        int target = 0;
        vector<int>dp(n+1,-1);
        return solve(n,target,dp);
    }
};
