class Solution {
public:
    int solve(vector<int>& cost, int i, vector<int>& dp) {
        //base case
        if(i == cost.size()) return 0;
        if(i > cost.size()) return 0;
        if(dp[i] != -1) return dp[i];
        //ek case mera baki recursion
        return dp[i] = cost[i] + min(solve(cost,i+1,dp),solve(cost,i+2,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+1,-1);
        return min(solve(cost,0,dp),solve(cost,1,dp));
    }
};
